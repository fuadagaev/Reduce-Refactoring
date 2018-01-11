/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         bpsheap.c
% Description:  Code to dynamically set up bps and heap structures
% Author:       RAM, HP/FSD
% Created:      9-Mar-84
% Modified:
% Mode:         Text
% Package:
%
% (c) Copyright 1982, University of Utah
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
% 2018 (Arthur Norman)
%  Bring the C code up to date.
% 11-Aug-88 (Julian Padget)
%  Added initialization of bpslowerbound in setupbps().
% 07-Apr-87 (Harold Carr & Leigh Stoller)
%  Put in error checking to ensure that the memory pointers will fit in
%   info field of the lisp item.
% 21-Dec-86 (Leigh Stoller)
%  Added allocatemorebps function, called from try-other-bps-spaces in
%   allocators.sl.
% 18-Dec-86 (Leigh Stoller)
%  Changed to newer model. Bps is now defined in bps.c so that unexec can
%  alter the text/data boundry. Took out code that allowed command line
%  modification of bpssize. (Now set in the Makefile). Added setupbps()
%  that initialzes nextbps and lastbps.
% 20-Sep-86 (Leigh Stoller)
%  Removed assembler alias statements because they are not portable. Instead,
%  a sed script will be used to convert the _variables of C to VARIABLES of
%  PSL.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

long unexec();

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>    // for PAGESIZE
#include <inttypes.h>  // Make newer integer types  of known width available
#include <unistd.h>

#ifndef PAGESIZE
#define PAGESIZE 4096
#endif

/* Use 1 if using compacting collector ($pxnk/compact-gc.sl).
   Use 2 if using copying collector ($pnk/copying-gc.sl).
   Be sure to update $pxnk/load-psl.sl to include correct collector. */

#define NUMBEROFHEAPS 2

#define MINSIZE        1000 * 1024 * 1024  /* Default total in number of bytes. */
#define MALLOCSIZE     500000              /* Default size for OS support functions. */
#define EXTRABPSSIZE   300000              /* Minimum amount to increase bps by. */
#define MINIMUMHEAPADD 20000               /* Minimum amount to increase heap by */


#ifndef BPSSIZE
#define BPSSIZE         1600000    /* Default bps size in number of bytes */
#endif

char *  imagefile;
char *  abs_imagefile = NULL; /* like imagefile, but as an absolute path */
size_t   max_image_size;
uintptr_t   oldbreakvalue;

uintptr_t bpscontrol[2];

extern uintptr_t  alreadysetupbpsandheap;
extern uintptr_t  hashtable;
extern char bps[];
extern uintptr_t  symval;
extern uintptr_t  lastbps;
extern uintptr_t  nextbps;
extern uintptr_t  bpslowerbound;
extern size_t     _infbitlength_;

extern uintptr_t  heaplowerbound;
extern uintptr_t  heapupperbound;
extern uintptr_t  heaplast;
extern uintptr_t  heaptrapbound;

extern uintptr_t  oldheaplowerbound;
extern uintptr_t  oldheapupperbound;
extern uintptr_t  oldheaplast;
extern uintptr_t  oldheaptrapbound;

extern int creloc(uintptr_t array, size_t len, intptr_t diff, uintptr_t lowb);

size_t sizeofsymvectors = 0;

extern void setupbps();
extern void getheap(intptr_t heapsize);
extern void read_error(char * what, intptr_t bytesread, intptr_t byteswanted);


int setupbpsandheap(int argc, char *argv[])
{   uintptr_t ohl,ohtb,ohub,htb,hlb,hub;
    intptr_t diff;
    int memset = 0;
    FILE * imago;
    uintptr_t headerword [8];
    uintptr_t total, bpssize, heapsize, mallocsize;
    uintptr_t current_size_in_bytes, heapsize_in_bytes;
    char   *argp, *scanptr, *scanformat;
    long hugo;

    total        = MINSIZE;
    mallocsize    = MALLOCSIZE;

    for (int i=1; i<argc-1; i++)
    {   argp = argv[i];
        if (*argp++ == '-')
        {   scanformat = "";
            switch (*argp++)
            {   case 't': scanptr = (char *)&total;
                    memset = 1;
                    switch (*argp)
                    {   case 'x': scanformat = "%x";
                            break;
                        case 'd': scanformat = "%d";
                            break;
                    }
                    break;
                case 'm': scanptr = (char *)&mallocsize;
                    switch (*argp)
                    {   case 'x': scanformat = "%lx";
                            break;
                        case 'd': scanformat = "%ld";
                            break;
                    }
                    break;
                case 'f': imagefile = argv[i+1]; break;
            }
            if (*scanformat != 0)
                sscanf(argv[i+1],scanformat,scanptr);
        }
    }   /* end of for loop -- arg vector searched */

    /* insure valid values */

    if (total < 1000000)  total = total * 1000000;

    if (total == 0)
        total = MINSIZE;

    if (mallocsize <= 0)
        mallocsize = MALLOCSIZE;

    /* Reserve some space for C's usr of io buffers, etc. By mallocing then
       freeing, the memory is sbrk'ed onto the image, but available for future
       calls to malloc, which will not need to call sbrk again. */

    bpssize = BPSSIZE;

    heapsize_in_bytes = total - bpssize;

    /* On systems in which the image does not start at address 0, this won't
       really allocate the full maximum, but close enough. */
    current_size_in_bytes = (((intptr_t) sbrk(0))<<5)>>5;
    max_image_size = 0x1000000000000; /* 1 more than allowable size */

    if ((heapsize_in_bytes + current_size_in_bytes) >= max_image_size)
    {   heapsize_in_bytes = max_image_size - current_size_in_bytes;
        total = heapsize_in_bytes + bpssize;
        printf("total %" PRIxPTR " %" PRIxPTR " %" PRIxPTR "\n",
               heapsize_in_bytes, current_size_in_bytes,total);
        printf("Size requested will result in pointer values larger than\n");
        printf(" PSL items can handle. Will allocate maximum size instead.\n\n");
    }

#if (NUMBEROFHEAPS == 2)
    heapsize =(heapsize_in_bytes / 8) * 4;  /* insure full words */
#else
    heapsize =(heapsize_in_bytes / 8) * 8;  /* insure full words */
#endif

    if (imagefile == NULL)
    {   printf("Setting heap limit as follows:\n");
    }

    setupbps();
    if (imagefile != NULL) imago = fopen(imagefile,"r");
    /* before getheap */

    getheap(heapsize);

    if (imagefile == NULL)
        printf("bpssize = % " PRIdPTR "(%" PRIXPTR "), "
                  "heapsize = %" PRIdPTR " (%" PRIXPTR ")\n"
                  "Total image size = %" PRIdPTR " (%" PRIXPTR ")\n",
               bpssize, bpssize,
               heapsize, heapsize,
               (intptr_t)sbrk(0), (intptr_t)sbrk(0));

    if (imagefile != NULL)
    {   ohl = oldheaplowerbound; ohub = oldheapupperbound;
        ohl =  oldheaplast; ohtb = oldheaptrapbound;
        hlb = heaplowerbound; hub = heapupperbound;
        htb = heaptrapbound;
        /* save the new values around restore of the old ones */

        printf("Loading image file: %s \n",imagefile);
        if (imago == NULL)
        {   perror("error");
            exit(-1);
        }
        fread(headerword, 8, 2, imago);
        unexec();      /* set control vector */
        if ((int) bpscontrol[0] != headerword[0]
            || bpscontrol[1] != headerword[1])
        {   printf(" Cannot start the image with this bpsl \n");
            printf(" %" PRIxPTR " != %" PRIxPTR ", %" PRIxPTR " != %" PRIxPTR "\n",
                bpscontrol[0], headerword [0],
                bpscontrol[1], headerword[1]);
            exit(-19);
        }
        fread(headerword,8,4,imago);
#ifdef DEBUG
        printf("symbol table: %" PRIxPTR " (%" PRIxPTR ") bytes\n",headerword[0],headerword[0]);
#endif
        hugo = fread(&symval,1,headerword[0],imago);
        diff = hlb-heaplowerbound;
        if (hlb < heaplowerbound)
        {   creloc((intptr_t)&symval,headerword[0]/8,diff,hlb -1);
        }
        else
        {   creloc((intptr_t)&symval,headerword[0]/8,diff, heaplowerbound -1);
        }

        sizeofsymvectors = headerword[0]/8;

        if (hugo != headerword[0]) read_error("symbol table",hugo,headerword[0]);

#ifdef DEBUG
        printf("heap: %" PRIdPTR " (%" PRIxPTR ") bytes\n",headerword[1],headerword[1]);
#endif
        hugo = fread((char*)hlb,1,headerword[1],imago);
        if (hlb < heaplowerbound)
        {   creloc(hlb,headerword[1]/8,diff,hlb -1);
        }
        else
        {   creloc(hlb,headerword[1]/8,diff, heaplowerbound -1);
        }
        heaplast += diff;

        if (hugo != headerword[1]) read_error("heap",hugo,headerword[1]);
#ifdef DEBUG
        printf("hash table: %" PRIdPTR " (%" PRIxPTR ") bytes\n",headerword[2],headerword[2]);
#endif
        hugo = fread(&hashtable,1,headerword[2],imago);
        if (hugo != headerword[2]) read_error("hash table",hugo,headerword[2]);
#ifdef DEBUG
        printf("BPS: %ld (%lx) bytes\n",headerword[3],headerword[3]);
#endif
        hugo = fread((char*)bpslowerbound,1,headerword[3],imago);
        if (hugo != headerword[3]) read_error("BPS",hugo,headerword[3]);
        fclose(imago);
        if (memset)
        {   oldheaplowerbound = ohl; oldheapupperbound = ohub;
            oldheaplast = ohl; oldheaptrapbound = ohtb;
            heaplowerbound = hlb; heapupperbound = hub;
            heaptrapbound = htb;
        }
        abs_imagefile = realpath(imagefile,NULL);
// 4711 is being returned as a return code here. This seems WEIRD to me!
        return 4711;
    }
    return 0;

}

void read_error(char * what,intptr_t bytesread,intptr_t byteswanted)
{   printf("File too short while reading %s: bytes read = %ld (%lx), bytes expected = %ld (%lx)\n",
           what,bytesread,bytesread,byteswanted,byteswanted);
    exit(-1);
}


/* The current procedure is to convert the starting address of the char
   array defined in bps.c to an address and store it in nextbps. A check
   is made to make sure that nextbps falls on an even word boundry.
 */

#include <sys/mman.h>

void setupbps()
{   char *p = (char *)bps;
    size_t bpssize;
    nextbps = ((intptr_t)bps + 7) & ~7;        /* Up to a multiple of 8. */
    bpslowerbound = nextbps;
    lastbps = ((intptr_t)bps + BPSSIZE) & ~7;    /* Down to a multiple of 8. */
    p = (char *)(((intptr_t) bpslowerbound  -1) & ~(PAGESIZE-1));
    bpssize = ((BPSSIZE + PAGESIZE-1) & ~(PAGESIZE-1));
    if (mprotect(p, bpssize, PROT_READ | PROT_WRITE | PROT_EXEC))
    {   perror("Couldn't mprotect");
        exit(errno);
    }
}


/* Allocate alternate bps space. Note: The use of sbrk(), and the fact that
   nextbps is now greater than heaplast means that unexec should be not be
   tried after this routine is called. The image would be huge.
 */
size_t allocatemorebps()
{   intptr_t old_nextbps = nextbps;

    intptr_t current_size_in_bytes = (intptr_t)sbrk(0);

    if ((current_size_in_bytes + EXTRABPSSIZE) >= max_image_size)
        return 0;

    if (((intptr_t)sbrk(0)) % 2)      /* force to even word boundary*/
        nextbps = (intptr_t)sbrk(1);

    nextbps = (intptr_t)sbrk(EXTRABPSSIZE);   /* allocate extra BPS */
    if (nextbps == -1)
    {   nextbps = old_nextbps;
        return 0;
    }
    lastbps = nextbps + EXTRABPSSIZE;

    return EXTRABPSSIZE;   /* This will be a paramter later */
}


void getheap(intptr_t heapsize)
{

#if (NUMBEROFHEAPS == 1)
    heaplowerbound        = (intptr_t)sbrk(heapsize);  /* allocate first heap */;
    oldheaplowerbound     = -1;
#else

    heaplowerbound        = (intptr_t )malloc(2 * heapsize);  /* allocate first heap */;
#endif
    if (heaplowerbound  == (intptr_t) NULL )
    {   perror("GETHEAP");
        exit(-1);
    }
    heapupperbound        = heaplowerbound + heapsize;
    heaplast              = heaplowerbound;
    heaptrapbound         = heapupperbound -120;

#if (NUMBEROFHEAPS == 2)
    oldheaplowerbound     = heapupperbound;
    oldheapupperbound     = oldheaplowerbound + heapsize;
    oldheaplast           = oldheaplowerbound;
    oldheaptrapbound      = oldheapupperbound -120;
#endif
    oldbreakvalue = (intptr_t )sbrk(0);
}

/* Tag( alterheapsize )
 */
intptr_t alterheapsize(intptr_t increment)
{   /*
      alters the size of the heap by the specified increment.  Returns
      the increment if successful, otherwise returns 0.  May fail if
      the sbrk is unsuccessful or if the user tries to cut the heap back
      to nothing or the current break value does not match the old value.
      The latter case occurs when a malloc or sbrk has allocated space for
      some other software, in which case we cannot allocate any more space
      contiguously.

      Modifies both the heap and gcarray size.
      NOTE: a garbage collection should probably be performed before this
        routine is called.
      NOTE: only implemented for the one heap version on the 68000.
    */

    size_t current_size_in_bytes;
    intptr_t diff;

#if (NUMBEROFHEAPS == 1)
    int gcarraysize, newbreakvalue;

    printf("***** cannot extend heap on this machine\n");
    return 0;

    if ((uintptr_t)sbrk(0) != oldbreakvalue)  /* Non contiguous memory */
        return 0;

    newbreakvalue = oldbreakvalue + increment;

    /* don't let the user cut his heap back to nothing, taking into account
       space for the gcarray. */
    if ((increment < 0) &&
        ((newbreakvalue - heaplowerbound) <
         (((heaplast + MINIMUMHEAPADD - heaplowerbound) * 9) / 8)))
        return 0;

    current_size_in_bytes = sbrk(0);

    if ((current_size_in_bytes +  increment) >= max_image_size)
        return 0;

    if ((intptr_t)sbrk(increment) == -1)     /* the sbrk failed. */
        return 0;

    newbreakvalue = (intptr_t) sbrk(0);
    heapsize = ((newbreakvalue - heaplowerbound) / 4) * 4;

    gcarraysize = ((heapsize / 9) / 4) * 4;
    heapsize = heapsize - gcarraysize;

    heapupperbound = heaplowerbound + heapsize;
    heaptrapbound     = heapupperbound;

    oldbreakvalue    = newbreakvalue;
    return increment;
#else
    /* assumes the current heap is the 'lower' one */
    int newbreakvalue;
    void *realo;

    if ((intptr_t)sbrk(0) != oldbreakvalue)  /* Non contiguous memory */
    {   printf(" unable to allocate %" PRIxPTR " %" PRIxPTR "\n",
            (uintptr_t)sbrk(0), oldbreakvalue);
        return 0;
    }

    current_size_in_bytes = ((intptr_t) sbrk(0) <<5) >>5;

    if ((current_size_in_bytes + 2* increment) >= max_image_size)
        return (-1);

    realo = realloc((void *)heaplowerbound,
                    oldheapupperbound - heaplowerbound + 2*increment);
    if (realo == (void *)NULL) return (-2);
    diff =  (uintptr_t)realo - heaplowerbound;
// The original code performed a "less than" test involving a value of type
// void *. I am changing that to cast to uintptr_t because the status of
// comparisons in C between void* pointers which might not point into a single
// object is questionable.
    if ((uintptr_t)realo < heaplowerbound)
    {   creloc((intptr_t)&symval,sizeofsymvectors,diff,(uintptr_t)(realo-1));
    }
    else
    {   creloc((intptr_t)&symval,sizeofsymvectors,diff, heaplowerbound -1);
    }
    if ((uintptr_t)realo < heaplowerbound)
    {   creloc((intptr_t)realo,(heapupperbound - heaplowerbound)/8,diff,(uintptr_t)(realo -1));
    }
    else
    {   creloc((intptr_t)realo,(heapupperbound - heaplowerbound)/8,diff,
               heaplowerbound -1);
    }

    newbreakvalue = (intptr_t)sbrk(0);

    heaplowerbound        = (uintptr_t)realo;
    heaplast              = heaplast + diff ;
    heapupperbound        = heapupperbound  + diff + increment ;
    heaptrapbound         = heapupperbound - 120;
    oldheaplowerbound     = oldheaplowerbound + diff + increment;
    oldheapupperbound     = oldheapupperbound + diff + 2* increment ;
    oldheaplast           = oldheaplowerbound + diff ;
    oldheaptrapbound      = oldheapupperbound -120;
    oldbreakvalue         = newbreakvalue;
    return increment;
#endif

}

long unexec()
{   bpscontrol[0] = bpslowerbound;
    bpscontrol[1] = BPSSIZE;
    return (long)bpscontrol;
}

char *get_imagefilepath()
{   return abs_imagefile;
}

// end of bpsheap.c
