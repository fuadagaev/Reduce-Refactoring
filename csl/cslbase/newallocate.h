// newallocate.h                          Copyright (C) Codemist, 2018-2022


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$

#ifndef header_newallocate_h
#define header_newallocate_h 1

#include "log.h"
#include <cstring>
#include <csetjmp>


using std::hex;
using std::dec;

static const size_t pageSize = 8*1024*1024u;     // Use 8 Mbyte pages
static const size_t chunkSize = 16*1024u;        // 16 Kbyte chunks
static const size_t chunkMask = chunkSize-1;

extern bool allocateSegment(size_t);

enum PageType
{   emptyPageType,
    consPinPageType,
    vecPinPageType,
    consFullPageType,
    vecFullPageType,
    borrowPageType
};

class Page;

extern Page* emptyPages;
extern Page* consPinPages;
extern Page* vecPinPages;
extern Page* oldConsPinPages;
extern Page* oldVecPinPages;
extern Page* consFullPages;
extern Page* vecFullPages;
extern Page* consOldPages;
extern Page* vecOldPages;
extern Page* consCurrent;
extern Page* vecCurrent;
extern Page* borrowPages;
extern Page* borrowCurrent;
extern Page* potentiallyPinned;
extern Page* pinnedPages;

extern Page* emptyPagesTail;
extern Page* consPinPagesTail;
extern Page* vecPinPagesTail;
extern Page* consFullPagesTail;
extern Page* vecFullPagesTail;
extern Page* borrowPagesTail;

extern size_t emptyPagesCount;
extern size_t consPinPagesCount;
extern size_t vecPinPagesCount;
extern size_t consFullPagesCount;
extern size_t vecFullPagesCount;
extern size_t borrowPagesCount;


class alignas(pageSize) Page
{
public:
// Define two structs used when setting out the rest of the
// layout. In many respects the most important thing about these is
// the alignment that they impose.
    struct alignas(2*sizeof(LispObject)) ConsCell
    {   LispObject car;
        LispObject cdr;
    };
    struct alignas(chunkSize) Chunk
    {   uintptr_t data[chunkSize/sizeof(uintptr_t)];
    };
    union
    {
// The sole purpose of the forceSize[] array is to ensure that the
// Page class ends up the size I want it to. The other entries in the
// union end up with arrays that are declared as having size 1 but which
// are in fact intended to span all the way up to pageSize
        char forceSize[pageSize];
        struct
        {
// There are some fields that every Page will have...
            PageType type;
            Page* chain;
            Page* oldPinnedPages;
            Page* pinnedPages;
            LispObject pinnedObjects;
            uintptr_t scanPoint;
            uintptr_t dataEnd;
            uintptr_t initialLimit;
// Now based on the "type" field I will have either a CONS page or
// a VEC page, and the union here defines how each is to be laid out. Note
// that the arrays consData[] and chunks[] are in fact expected to run
// out up to pageSize rather than being of length 1 as declared here...
// I can not see a tidy C++ way to make the length of each array what I
// want. Well I can do it using something like
//   consData[(pagesize - sizeof(PageType) - sizeof(Page*) - ...)/
//            sizeof(ConsCell)]
// but that becomes hideous to maintain and delicate as regards alignment.
// I might clean it up a bit by embedding the whole header in a further
// struct so I could use the size of that in my arithmetic, but it still
// feels uncomfortable!
            union
            {   struct
                {   uint64_t previousConsPins[pageSize/
                                              (2*sizeof(LispObject))/
                                              (8*sizeof(uint64_t))];
                    uint64_t currentConsPins[pageSize/
                                             (2*sizeof(LispObject))/
                                             (8*sizeof(uint64_t))];
                    ConsCell consData[1];
                };
                struct
                {   bool potentiallyPinnedFlag;
                    Page* potentiallyPinnedChain;
// I make chunkStatus an array of uint8_t values so that I understand
// its layout very clearly. The values stored are explained elsewhere.
                    uint8_t  chunkStatus[pageSize/chunkSize];
                    uint64_t potentiallyPinnedChunks[pageSize/
                                                     chunkSize/(8*sizeof(uint64_t))];
                    uint64_t previousVecPins[pageSize/8/(8*sizeof(uint64_t))];
                    uint64_t currentVecPins[pageSize/8/(8*sizeof(uint64_t))];
                    Chunk chunks[1];
                };
            };
        };
    };
};

inline bool isPotentiallyPinned(Page* p, uintptr_t a)
{   size_t chunkNo = (a - reinterpret_cast<uintptr_t>(p))/chunkSize;
    return ((p->potentiallyPinnedChunks[chunkNo/64] >>
             (chunkNo & 63)) & 1) != 0;
}

inline void setPotentiallyPinned(Page* p, uintptr_t a)
{   size_t chunkNo = (a - reinterpret_cast<uintptr_t>(p))/chunkSize;
    p->potentiallyPinnedChunks[chunkNo/64] |=
        static_cast<uint64_t>(1) << (chunkNo & 63);
}

inline bool isPotentiallyPinnedChunk(Page* p, size_t chunkNo)
{   return ((p->potentiallyPinnedChunks[chunkNo/64] >>
             (chunkNo & 63)) & 1) != 0;
}

inline void setPotentiallyPinnedChunk(Page* p, size_t chunkNo)
{   p->potentiallyPinnedChunks[chunkNo/64] |=
        static_cast<uint64_t>(1) << (chunkNo & 63);
}

// Here p must be a CONS page and a a pointer within it.

inline bool consIsPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/(2*sizeof(LispObject));
    return (p->currentConsPins[o/64] >> (o&63)) != 0;
}

inline bool consIsPreviousPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/(2*sizeof(LispObject));
    return (p->previousConsPins[o/64] >> (o&63)) != 0;
}

inline void consSetPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/(2*sizeof(LispObject));
    p->currentConsPins[o/64] |= static_cast<uint64_t>(1) << (o&63);
}

inline void consClearPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/(2*sizeof(LispObject));
    p->currentConsPins[o/64] &= ~(static_cast<uint64_t>(1) << (o&63));
}

// And versions for VEC pages, which pin with granularity a single
// LispObject, so the bitmaps are twice as large as the ones for CONS pages
// where granularity only needs to be the size of a pair of adjacent
// objects.

inline bool vecIsPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/sizeof(LispObject);
    return (p->currentVecPins[o/64] >> (o&63)) != 0;
}

inline bool vecIsPreviousPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/sizeof(LispObject);
    return (p->previousVecPins[o/64] >> (o&63)) != 0;
}

inline void vecSetPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/sizeof(LispObject);
    p->currentVecPins[o/64] |= static_cast<uint64_t>(1) << (o&63);
}

inline void vecClearPinned(uintptr_t a, Page* p)
{   uintptr_t o = (a - reinterpret_cast<uintptr_t>(p))/sizeof(LispObject);
    p->currentVecPins[o/64] &= ~(static_cast<uint64_t>(1) << (o&63));
}


// Set up the given Page as one for use with CONS supposing it is
// totally free to start with. This sets up global fringe and limit pointers.

// Note that a page that has any pinned items in it will hold the relevant
// values for those in scanPoint and initialLimit fields.

extern uintptr_t consFringe, consLimit, consEnd;

inline void initConsPage(Page* p, bool empty)
{   p->type = consFullPageType;
    consCurrent = p;
    consEnd = reinterpret_cast<uintptr_t>(p) + pageSize;
    if (empty)
    {   p->pinnedObjects = TAG_FIXNUM;
        std::memset(p->previousConsPins, 0, sizeof(p->previousConsPins));
        std::memset(p->currentConsPins, 0, sizeof(p->currentConsPins));
        consFringe = p->scanPoint = reinterpret_cast<uintptr_t>(&p->consData);
        consLimit = consEnd;
    }
    else
    {   consFringe = p->scanPoint;
        consLimit = p->initialLimit;
    }
}

inline void pageAppend(Page* p, Page*& list, Page*& tail, size_t& count)
{   p->chain = nullptr;
    if (count == 0)
    {   list = tail = p;
        count = 1;
    }
    else
    {   tail->chain = p;
        tail = p;
        count++;
    }
}

extern uintptr_t consEndOfPage();
extern void garbage_collect();

// A totally unused page must still have its type field filled in as
// emptyPageType so that ambiguous pointers that refer within it can
// be disregarded.
// 

// I should document the layout of a Cons Page, and the structure depends
// on the status of the page:
//
// Empty:      value in consData[0].car = consEnd
//             Well actually that will get set as the page is allocated to
//             be one containing Cons style data. Also a fully empty page
//             will have the bitmaps relating to pinning all clear.
//             dataEnd points at the start of the page.
//
// Empty+Pins: first unpinned word points to either consEnd or the next
//             pinned location, and similarly beyond that. dataEnd refers
//             to the start of the page. So a fully empty page is just a
//             special case of that.
//
// Full:       Valid data is present from consData[0] to dataEnd
//             but skipping items marked as pinned in the bitmap and the
//             pinning bitmap will identify any pinned data. Ah well
//             in fact all of these have the same structure. I just show
//             them separately here because allocating an unused page as
//             a cons page makes an empty one, the GC can release pages
//             as either unused or empty+pins and both GC and general
//             computation can allocate memory as full pages.
// 
//
// Current:    data runs from consData[0] to scanPoint and then scanPoint
//             up to consFringe, but any cells marked as pinned will be
//             ignored on scanning.
//             During allocation new data is placed from consFringe to
//             consLimit.
//             There are two possibilities there. One is that consLimit is
//             at consEnd in which case the Page has become full. The other
//             is that the cell at consLimit is pinned. In such a case one
//             can perform a linear scan upwards looking for either no
//             pinning or consEnd. If an unpinned item is found its
//             contents show where the next setting of consLimit should
//             be, and that will either be the next pinned item or consEnd.
//
// Note that some of the words there refer to global variables (eg consFringe)
// while others are fields stored within the Page (eg scanPoint).
//
// When allocation fills up a page or when GC is about to start (which
// may happen when the current cons page is only partly filled) the
// current Page has its dataEnd field set to consFringe.
// Whenever a new current (cons) page is established it has its scanPoint
// and dataEnd fields set to the first address after &consData[0]
// that is not pinned, and consFringe also points there. consLimit is set
// based on the initial value set there. This means that a Page that contains
// any pinned cons cells may not be re-allocated to hold vectors, because it
// has to have the internal structure as per here,
// "Current:" above. So that defines the state that the GC must leave
// a cons Page in. So for clarity, if the page is utterly empty and without
// any pinned items it starts off with its first word containing the
// address one beyond its last.

// Well I will also explain a Vector Page.
//
// Each vector Page is viewed as made up of a sequence of chunks each of
// 16KB and a 512 byte array provides a small amount of information about
// each. The values are used as follows:
// 0          A basic chunk, ie everything fits within 16KB.
// 1          The first segment of an extended chunk.
// 2,3,..253  Subsequent segments of an extended chunk.
// 254        Initial segment of an extended chunk containing some pins.
// 255        A basic chunk that contains some pinned data.
// In CSL I arrange that the largest basic vector I allocate is of size
// around 2MB and a consequence of that is that I will never need an
// extended chunk much larger than that, and so I will never overflow
// the limit (253) of segments in an extended chunk. Phew. Note that setting
// the array so it just contains zero leaves it is a "safe" state, and when
// an unused Page is made into a Vector one this must happen.
//
enum ChunkStatus
{
    BasicChunk          = 0u,
    ExtendedChunkStart  = 1u,
    ExtendedChunkMax    = 253u,
    ExtendedPinnedChunk = 254u,
    BasicPinnedChunk    = 255u
};
// The purpose of all this is that if I have an ambiguous pointer that
// refers within a vector page I can first easily identify the chunk
// it is within. Then I probe the byte array. If the value I find is
// 0, 1, 254 or 255 I have the first or only 16KB part of the chunk.
// Otherwise I can subtract the number I find from the address to identify
// the first part, and then if I need to re-probe to see if an extended
// chunk contains any pinned objects.
//
// A full vector page will contain its sequence of chunks. some will be
// flagged as containing pinned material by the entry on their first
// (or only) segment. A bitmap will identify the headers of the pinned
// objects within them.
// Chunks up to dataEnd will will contain a sequence of Lisp items,
// with a padder object at the end so that the chunk is totally full,
// ir if it is a current Page live date runs up to vecFringe.
// Only chunks containing pinned material beyond that are at all
// useful.
//
// A current vector page will have a scanPoint that refers just beyond
// some object and has vecFringe and vecLimit set properly.
// Each chunk apart from the one that vecFringe points within
// and any that contain pinned data are totally full (with a padder at
// the end). So to scan, one identifies the chunk concerned (by dividing
// by 16K) and checks its sequence number in the byte-array. That makes
// it possible to identify the end of the chunk or extended chunk, and
// the data can then be parsed until that is reached. Then the next
// non-pinned chunk is found (by skipping over pinned chunks) and scanning
// continues until either vecFringe or the end of the Page is reached.
//
// Allocation will test currentChunkIsEmpty. If it is empty then it is
// OK to allocate a block up as far as vecHardLimit, which is either the
// start of the next pinned chunk is is vecEnd. In that case the allocated
// space is set up as an extended chunk if needbe and vecLimit set so that
// subsequent small requests can potentially fill up spare space at the
// end. Of course that clears currentChunkIsEmpty. The next allocation(s)
// can fit in blocks of memory up as far as vecLimit. A common case may be
// when multiple smallish vectors build up within a basic chunk.
// When the next request will not fit a padder has to be put in and
// a new empty chunk started.
// When there is an attempt to allocate a rather large vector a big padder
// may be needed. Well most padders will just be from vecFringe to the
// end of the current chunk, so inserting then will not adjust
// chunkStatus[], but it will be possible to need to insert a padder
// when currentChunkIsEmpty and that may cvall for an extended chunk to
// hold it.
//
// A vector page that is empty apart from some pinned stuff needs to have
// the chunkStatus array filled in to identify each chunk that contains
// pinned material. When a totally fresh page is made into a vector page
// the chunkStatus[] array can be set to zero as if every chunk is basic
// and not pinned.

// Allocation while programs are running normally and when garbage
// collection is in progress are identical until a Page becomes full.
// In normal cases filling a page leads to a check as to whether 2/3 of
// all available pages are in use, and if now a further page is just
// grabbed, and otherwise GC is triggered. Well "available" needs to include
// available via requesting more from the operating system.
// During GC fresh pages are always grabbed save that if none are available
// at all then a "run out of memory" event must be reported. This is a
// horrible situation because memory is in a messed up state with some
// stuff copied to the "new half space" and some not, so recovery is
// not possible but I suspect that by making print routines able to
// traverse forwarding pointers transparently it may still be possible to
// generate a backtrace. If I want to be able to recover from memory-full
// disasters I would need to trigger GC when memory became just 1/2 full
// (and still worry about fragmentation!) and then complain at the end
// of GC unless there was not say 1/6 of memory still unused, ie that
// half memory load had compressed into 1/3 of memory, which is the
// same stopping point that I am at present envisaging. But my proposed
// scheme garbage collects less frequently so improves performance at the
// cost of recovery in circumstances that I tend to view as unrecoverable!


// With at least some compilers if I have an "inline" function definition
// but there are no calls to it then no space is wasted. Well compile time
// may be impacted. So I put some functions that can display or validate
// Pages here for use while debugging.

inline void displayVectorPage(Page* p)
{   unsigned int n = 0;
    for (unsigned int i=0; i<sizeof(p->chunkStatus); i++)
    {   unsigned int k = p->chunkStatus[i];
        if (k == BasicChunk)
        {   n++;
            continue;
        }
        if (n != 0)
        {   zprintf("%dB ", n);
            n = 0;
        }
        zprintf("^%u ", k);
    }
    if (n != 0) zprintf("%dB ", n);
}


extern bool withinGarbageCollector;

// The class here is to ensure that the flag gets reset when GC terminates.

class WithinGarbageCollector
{
public:
    WithinGarbageCollector()
    {   withinGarbageCollector = true;
    }
    ~WithinGarbageCollector()
    {   withinGarbageCollector = false;
    }
};

inline uintptr_t harderGet2Words()
{
// Here consFringe == consLimit. One possibility is tha this is because
// consLimit points at a pinned item, and there could of course be
// several consecutive pinned things. And in a bad case that could
// extend so that the very last location in the Page was pinned. Another
// possibility is that consLimit==consEnd so the Page is already all used up.
// The loop here skips over pinned stuff.
    while (consFringe < consEnd &&
           consIsPinned(consFringe, consCurrent))
        consFringe += 2*sizeof(LispObject);
// Now if the Page is full I need to try to allocate another, and if that
// does not make sense I will have to garbage collect.
    if (consFringe == consEnd) return consEndOfPage();
// When I skip pinned data and if there is space beyond same then the first
// word of that region holds a pointer showing where the next usable
// section of memory ends.
    consLimit = *reinterpret_cast<uintptr_t*>(consFringe);
// Now I can allocate.
    uintptr_t r = consFringe;
    consFringe += 2*sizeof(LispObject);
    return r;
}

// This is the main function for allocating CONS cells and any
// other item that only use up 2 cells. I hope it will often have
// calls to it expanded inline.

inline uintptr_t get2Words()
{   uintptr_t r = consFringe;
    if (r != consLimit)
    {   consFringe += 2*sizeof(LispObject);
        return r;
    }
    return harderGet2Words();
}

inline Header makeHeader(size_t n, int type)   // size is in bytes
{   return TAG_HDR_IMMED + (n << (Tw+5)) + type;
}

// At times I want to put a vector header at the start of a block of
// memory. This does the job. Note that a is an untagged pointer here.

inline void setHeaderWord(uintptr_t a, size_t n, int type=TYPE_PADDER)
{   *reinterpret_cast<uintptr_t*>(a) = makeHeader(n, type);
}

extern uintptr_t vecFringe, vecLimit, vecEnd;

// Again pages that have any pinned data in them specify their initial
// fringe and limit in scanPoint and initialLimit.

inline void initVecPage(Page* p, bool empty)
{   p->type = vecFullPageType;
    vecCurrent = p;
    vecEnd = reinterpret_cast<uintptr_t>(p) + pageSize;
    if (empty)
    {   p->potentiallyPinnedFlag = false;
        p->potentiallyPinnedChain = nullptr;
        std::memset(p->previousVecPins, 0, sizeof(p->previousVecPins));
        std::memset(p->currentVecPins, 0, sizeof(p->currentVecPins));
        std::memset(p->chunkStatus, BasicChunk, sizeof(p->chunkStatus));
        std::memset(p->potentiallyPinnedChunks, 0,
                    sizeof(p->potentiallyPinnedChunks));
        vecFringe = p->scanPoint = reinterpret_cast<uintptr_t>(&p->chunks);
        vecLimit = vecEnd;
    }
    else
    {   vecFringe = p->scanPoint;
        vecLimit = p->initialLimit;
    }
    displayVectorPage(p);
}

extern Page* grabFreshPage(PageType type);

inline uintptr_t getNBytes(size_t n)
{
// If I am just getting 2 words I can use the cons heap where allocation
// is simpler. This will cover some rather small bignums and some short
// strings. It is a rather minor special case!
    if (n == 2*sizeof(LispObject)) return get2Words();
    for (;;)
    {   uintptr_t r = vecFringe;
// Now I will see if the new item will fit within the current chunk. Note
// that this test applies whether I am in a basic chunk or at the end of
// an extended one. The chunkStatus[] entry must already be set up and
// at the start that will always indicate basic chunks, so when this fills
// one chunk perfectly and moves on to the next that next one will be
// ready to be a basic chunk. The test against vecLimit is needed because
// a previous allocation may have totally filled eg the last chunk on
// the page.
        if ((r&chunkMask) + n <= chunkSize && r!=vecLimit)
        {   vecFringe += n;
            return r;
        }
// Here either the request will not fit in the current chunk or really there
// is no current chunk. Insert a padder in the former case.
        if (r!=vecLimit)
        {   setHeaderWord(r, (-r)&chunkMask);
            vecFringe = r + ((-r)&chunkMask);
        }
// Now vecFringe points at the start of a chunk. In some cases that will
// mean I can just move on and use that chunk easily. Note that this
// requires chunkStatus[] to have been initialised to BasicChunk
        if (n <= chunkSize && vecFringe != vecLimit)
        {   r = vecFringe;
            vecFringe += n;
            return r;
        }
// Here is the messy case. It could be that the request is small and
// I have just filled memory up as far as vecLimit, or it could be that
// there is space before vecLimit but I need to confirm that there are
// enough consecutive free unpinned chunks to accommodate a large
// vector request.
        size_t chunkNo =
            (vecFringe - reinterpret_cast<uintptr_t>(vecCurrent))/chunkSize;
// chunkNo is now the number of the chunk that blocked me at vecLimit. I
// will skip over pinned chunks.
        while (chunkNo<sizeof(vecCurrent->chunkStatus) &&
               vecCurrent->chunkStatus[chunkNo] != BasicChunk) chunkNo++;
// Now I know where the next available region is. Scan to find its end.
// That will let me set fresh values for vecFringe and vecLimit.
        size_t stopPoint=chunkNo;
        while (stopPoint<sizeof(vecCurrent->chunkStatus) &&
               vecCurrent->chunkStatus[stopPoint] == BasicChunk) stopPoint++;
        vecFringe =
            reinterpret_cast<uintptr_t>(vecCurrent) + chunkNo*chunkSize;
        vecLimit =
            reinterpret_cast<uintptr_t>(vecCurrent) + stopPoint*chunkSize;
        if (n <= vecLimit - vecFringe)
        {
// Now it will fit
            uintptr_t r = vecFringe;
            vecFringe += n;
// Set vecLimit the the chunk boundary just above the newly allocated
// region of memory
            vecLimit = vecFringe + ((-vecFringe) & chunkMask);
// Mark up an extended block if needbe.
            if (n > chunkSize)  // leave as Basic if possible.
            {   size_t chunksNeeded = (n + chunkSize - 1)/chunkSize;
                for (size_t i=0; i<chunksNeeded; i++)
                    vecCurrent->chunkStatus[chunkNo+i] = ExtendedChunkStart+i;
            }
            return r;
        }
// Ugh - the request will not fit in this block. I need to fill this block
// with a padder and scan on looking for another. Make the space into
// and extended block (if necessary)
        if (vecLimit != vecFringe+chunkSize)
            for (size_t i=chunkNo; i<stopPoint; i++)
                vecCurrent->chunkStatus[i] = ExtendedChunkStart+(i-chunkNo);
        setHeaderWord(vecFringe, vecLimit-vecFringe);
        vecFringe = vecLimit;
// If I have reached the end of a Page then I must gram a new one.
        if (vecLimit == vecEnd)
        {   vecCurrent->dataEnd = vecFringe;
            pageAppend(vecCurrent, vecFullPages,
                       vecFullPagesTail, vecFullPagesCount);
            vecCurrent = grabFreshPage(vecFullPageType);
        }
        continue;    
    }
}


// "Borrowing" is a concept I introduce here. Its key use is when a hash
// table needs to be re-hashed. A requirement here is that garbage
// collection can not be triggered while borrowing is active.
// The idea is that apart from when garbage collection is happening
// around half of all memory is unused - when a GC starts it will be
// treated as the "new space" into which live data will be copied.
// Between garbage collections I allow myself to allocate from it
// on a strictly temporary basis. I only ever need to store vectors
// in it, so the logic here closely follow that for the normal
// allocation of vectors. Its use for hash tables is that a copy
// of all the data in a table can be made in "borrowed" space. The
// original table can then be cleared and everything re-hashed back
// into it. When that has been done the borrowed memory can be
// released.

extern Page* pageFringe;

extern unsigned int borrowingDepth;
extern uintptr_t borrowFringe, borrowLimit, borrowEnd;

class Borrowing
{
    Page* save;
public:
    Borrowing()
    {   if (borrowingDepth++ == 0)
        {   save = pageFringe;
        }
    }
    ~Borrowing()
    {   if (--borrowingDepth == 0)
        {   while (borrowPages != nullptr)
            {   Page* p = borrowPages;
                borrowPages = p->chain;
                p->chain = emptyPages;
                emptyPages = p;
            }
            borrowCurrent = nullptr;
            borrowFringe = borrowEnd = 0;
            pageFringe = save;
        }
    }
};

inline void initBorrowPage(Page* p, bool empty)
{
// borrowed pages do not need anything like as much initialisation since
// they will never participate in GC. However they must have chunkStatus
// set up since that is inspected in case there might have been pinned
// items within them.
    borrowCurrent = p;
    borrowEnd = reinterpret_cast<uintptr_t>(p) + pageSize;
    if (empty)
    {
// I do not need to do anything with pinning bitmaps here, but I must
// initialise chunkStatus since that is used during allocation.
        std::memset(p->chunkStatus, BasicChunk, sizeof(p->chunkStatus));
        borrowFringe = p->scanPoint = reinterpret_cast<uintptr_t>(&p->chunks);
        borrowLimit = borrowEnd;
    }
    else
    {   borrowFringe = p->scanPoint;
        borrowLimit = p->initialLimit;
    }
    displayVectorPage(p);
}

// The code for borrowing is very much the same as the for allocating
// vector space, save that it uses borrowFringe etc. Also it does not
// change chunkStatus[] information, so that when the borrowed page is
// finally abandoned it is left in just the state it was at the start.
// Furthermore it does not need to insert padder objects since new data
// in the page is not visible to the garbage collector.
// This code has the comments that are present in getNBytes() stripped out
// so that the bulk is a little less daunting.

inline uintptr_t borrowNBytes(size_t n)
{
    for (;;)
    {   uintptr_t r = borrowFringe;
        if ((r&chunkMask) + n <= chunkSize && r!=borrowLimit)
        {   borrowFringe += n;
            return r;
        }
        if (r!=borrowLimit)
            borrowFringe = r + ((-r)&chunkMask);
        if (n <= chunkSize && borrowFringe != borrowLimit)
        {   r = borrowFringe;
            borrowFringe += n;
            return r;
        }
        size_t chunkNo =
            (borrowFringe - reinterpret_cast<uintptr_t>(borrowCurrent))/chunkSize;
        while (chunkNo<sizeof(borrowCurrent->chunkStatus) &&
               borrowCurrent->chunkStatus[chunkNo] != BasicChunk) chunkNo++;
        size_t stopPoint=chunkNo;
        while (stopPoint<sizeof(borrowCurrent->chunkStatus) &&
               borrowCurrent->chunkStatus[stopPoint] == BasicChunk) stopPoint++;
        borrowFringe =
            reinterpret_cast<uintptr_t>(borrowCurrent) + chunkNo*chunkSize;
        borrowLimit =
            reinterpret_cast<uintptr_t>(borrowCurrent) + stopPoint*chunkSize;
        if (n <= borrowLimit - borrowFringe)
        {   uintptr_t r = borrowFringe;
            borrowFringe += n;
            borrowLimit = borrowFringe + ((-r) & chunkMask);
            return r;
        }
        borrowFringe = borrowLimit;
        if (borrowLimit == borrowEnd)
        {   borrowCurrent->dataEnd = borrowFringe;
            pageAppend(borrowCurrent, borrowPages,
                       borrowPagesTail, borrowPagesCount);
            borrowCurrent = grabFreshPage(borrowPageType);
        }
        continue;    
    }
}


inline void poll()
{
}

// Now for higher level code that performs Lisp-specific allocation.

inline LispObject cons(LispObject a, LispObject b)
{   LispObject r = get2Words() + TAG_CONS;
    setcar(r, a);
    setcdr(r, b);
    return r;
}

// With the conservative collector I maybe do not need to avoid garbage
// collection on any particular individual uses of cons().

inline LispObject cons_no_gc(LispObject a, LispObject b)
{   return cons(a, b);
}

inline LispObject cons_gc_test(LispObject p)
{   return p;
}

inline LispObject ncons(LispObject a)
{   LispObject r = get2Words() + TAG_CONS;
    setcar(r,  a);
    setcdr(r,  nil);
    return r;
}


inline LispObject list2(LispObject a, LispObject b)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcar(r2, b);
    setcdr(r1, r2);
    setcdr(r2, nil);
    return r1;
}

inline LispObject list2star(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcar(r2, b);
    setcdr(r1, r2);
    setcdr(r2, c);
    return r1;
}

inline LispObject list2starrev(LispObject c, LispObject b,
                               LispObject a)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcar(r2, b);
    setcdr(r1, r2);
    setcdr(r2, c);
    return r1;
}

inline LispObject list3star(LispObject a, LispObject b, LispObject c,
                            LispObject d)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    LispObject r3 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcar(r2, b);
    setcar(r3, c);
    setcdr(r1, r2);
    setcdr(r2, r3);
    setcdr(r3, d);
    return r1;
}

inline LispObject list4(LispObject a, LispObject b, LispObject c,
                        LispObject d)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    LispObject r3 = get2Words() + TAG_CONS;
    LispObject r4 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcar(r2, b);
    setcar(r3, c);
    setcar(r4, d);
    setcdr(r1, r2);
    setcdr(r2, r3);
    setcdr(r3, r4);
    setcdr(r4, nil);
    return r1;
}

inline LispObject acons(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    setcar(r1, r2);
    setcar(r2, a);
    setcdr(r1, c);
    setcdr(r2, b);
    return r1;
}

inline LispObject acons_no_gc(LispObject a, LispObject b,
                              LispObject c)
{   return acons(a, b, c);
}

inline LispObject list3(LispObject a, LispObject b, LispObject c)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    LispObject r3 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcar(r2, b);
    setcar(r3, c);
    setcdr(r1, r2);
    setcdr(r2, r3);
    setcdr(r3, nil);
    return r1;
}

inline LispObject list3rev(LispObject c, LispObject b, LispObject a)
{   LispObject r1 = get2Words() + TAG_CONS;
    LispObject r2 = get2Words() + TAG_CONS;
    LispObject r3 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcar(r2, b);
    setcar(r3, c);
    setcdr(r1, r2);
    setcdr(r2, r3);
    setcdr(r3, nil);
    return r1;
}

inline LispObject Lcons(LispObject, LispObject a, LispObject b)
{   LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcdr(r1, b);
    return onevalue(r1);
}

inline LispObject Lxcons(LispObject, LispObject a, LispObject b)
{   LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, b);
    setcdr(r1, a);
    return onevalue(r1);
}

inline LispObject Lnilfn(LispObject)
{   return onevalue(nil);
}

inline LispObject Lncons(LispObject env, LispObject a)
{   LispObject r1 = get2Words() + TAG_CONS;
    setcar(r1, a);
    setcdr(r1, nil);
    return onevalue(r1);
}

extern LispObject Lgctest_0(LispObject);
extern LispObject Lgctest_1(LispObject, LispObject);
extern LispObject Lgctest_2(LispObject, LispObject, LispObject);
extern void gcTestCode(); // temporary and for debugging.

// For up to 16 segments I have...
//   heapSegmentCount   number of allocated segments
//   heapSegment[i]      base address of a segment of memory
//   heapSegmentSize[i] size of useful part of that segment, in bytes
//   heapSegmentTotalSize[i] total size
// I will keep the segments in my table sorted so that a binary search
// can identify which one is relevant rather easily.

extern void* heapSegment[16];
extern char* heapSegmentBase[16];
extern size_t heapSegmentSize[16];
extern size_t heapSegmentCount;

void initHeapSegments(double n);

// findHeapSegment() can be given an arbitrary bit-pattern and
// if that could represent a pointer into one of the segments it returns
// the index into the table of segments associated with it, or -1 if the
// bit-pattern could not be interpreted as a pointer to within the
// memory I have allocated.

// Given a value I want to see if it could be a pointer into one of the
// allocated segments. Because there are only 16 of them and if I keep my
// table of segments such that they are sorted on their start address
// I can use a binary search which should be pretty fast, with the inline
// functions here expected to expand into a direct search tree in the
// generated code.

inline int findSegment2(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+1])) return n;
    else return n+1;
}

inline int findSegment4(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+2]))
        return findSegment2(p, n);
    else return findSegment2(p, n+2);
}

inline int findSegment8(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+4]))
        return findSegment4(p, n);
    else return findSegment4(p, n+4);
}

inline int findSegment16(uintptr_t p, int n)
{   if (p < reinterpret_cast<uintptr_t>(heapSegment[n+8]))
        return findSegment8(p, n);
    else return findSegment8(p, n+8);
}

inline int findHeapSegment(uintptr_t p)
{   int n = findSegment16(p, 0);
    if (p < reinterpret_cast<uintptr_t>(heapSegment[n]) ||
        p >= reinterpret_cast<uintptr_t>(heapSegment[n]) +
        heapSegmentSize[n]) return -1;
    return n;
}

// If I print addresses "naturally" I tend to get huge numbers with lots of
// leading digits - especially on a 64-bit system. This little function
// maps addresses to offsets within their heap segment. It is not really going
// to help a huge amount of you have multiple segments each full with
// gigabytes of data, but may ease early debugging on small cases quite
// a lot!
// If a value p is an address within the data region of a Page then
// the display will be of the form "#pagenumber:offset" if in the first
// heapsegment and "#segment:pagenumber:offset" otherwise. An offset
// of zero should correspond to the start of the first Chunk within the Page,
// and so the first bit of allocated user data lies (on a 64-bit machine)
// at address #0:30 because of the size of the Chunk header.

extern LispObject nil;

inline const char* Addr(uintptr_t p)
{
// This function may be called several times in a single expression. I
// do not want it to have to allocate fresh memory, so I set it up with
// four (4) buffers and use those in turn. 
    static char rr[4*40];
    static int seq=0;
    char* r = &rr[40*(seq++ & 0x3)];
    if (p == static_cast<uintptr_t>(nil))
    {   std::strcpy(r, "nil");
        return r;
    }
    else if (p == 0U)
    {   std::strcpy(r, "zero");
        return r;
    }
    int hs = findHeapSegment(p);
    if (hs != -1)
    {   uintptr_t segBase = reinterpret_cast<uintptr_t>(heapSegment[hs]);
        uintptr_t o = p - segBase;
        uintptr_t pNum = o/pageSize;
        Page* pp = reinterpret_cast<Page*>(segBase + pNum*pageSize); 
        uintptr_t pOff = o%pageSize;
        if ((pp->type==consPinPageType || pp->type==consFullPageType) &&
            pOff >= offsetof(Page, consData))
        {   pOff -= offsetof(Page, consData);
            if (hs == 0) std::snprintf(r, 40,
                "#%" PRIxPTR ":%" PRIxPTR, pNum, pOff);
            else std::snprintf(r, 40,
                "#[%d]: %" PRIxPTR ":%" PRIxPTR, hs, pNum, pOff);
            return r;
        }
        else if ((pp->type==vecPinPageType || pp->type==vecFullPageType) &&
                 pOff >= offsetof(Page, chunks))
        {   pOff -= offsetof(Page, chunks);
            if (hs == 0) std::snprintf(r, 40,
                "#%" PRIxPTR "::%" PRIxPTR, pNum, pOff);
            else std::snprintf(r, 40,
                "#[%d]: %" PRIxPTR "::%" PRIxPTR, hs, pNum, pOff);
            return r;
        }
        else if (pOff == 0)
        {   if (hs == 0) std::snprintf(r, 40, "#%" PRIxPTR ":", pNum);
            else std::snprintf(r, 40, "#[%d]: %" PRIxPTR ":", hs, pNum);
            return r;
        }
    }
    bool maybeChars = true;
    for (uintptr_t w=p; w!=0; w=w>>8)
    {   int c = w & 0xff;
        if (c < ' ' || c >= 0x7f) maybeChars = false;
    }
    if (maybeChars && p!=0)
    {   std::snprintf(r, 40, "%#" PRIxPTR "/%" PRIdPTR, p, p);
        size_t q = strlen(r);
        r[q++] = '/';
        r[q++] = '"';
        while (p != 0)
        {   r[q++] = p & 0xff;
            p = p>>8;
        }
        r[q++] = '"';
        r[q] = 0;
    }
    else std::snprintf(r, 40, "%#" PRIxPTR "/%" PRIdPTR, p, p);
    return r;
}

template <typename T>
inline const char* Addr(T p)
{   return Addr((uintptr_t)p);
}

// If Addr(n) yields #p:o then unAddr(p,o) should return n, however the code
// here does not achieve this because Addr subtracts the start address of
// data within a Page!

inline uintptr_t unAddr(uintptr_t p, uintptr_t o)
{    return reinterpret_cast<uintptr_t>(heapSegment[0]) + pageSize*p + o;
}

// .. and extra for the case of addresses in segments 1 and beyond.

inline uintptr_t unAddr(unsigned int s, uintptr_t p, uintptr_t o)
{    return reinterpret_cast<uintptr_t>(heapSegment[s]) + pageSize*p + o;
}

// This finds a page that a potential pointer p is within, or returns nullptr
// if there is not one

inline Page* findPage(uintptr_t p)
{   int n = findHeapSegment(p);
    if (n < 0) return nullptr;
    return reinterpret_cast<Page*>(p & -pageSize);
}

#ifdef __GNUC__

// Note that __GNUC__ also gets defined by clang on the Macintosh, so
// this code is probably optimized there too. This must NEVER be called
// with a zero argument. Also note that this function is also defined
// in arithlib.hpp, but since it is "inline" there is not need to worry
// about having multiple definitions, although it will be best if they
// all match.

// Count the leading zeros in a 64-bit word.

inline int nlz(uint64_t x)
{   return __builtin_clzll(x);  // Must use the 64-bit version of clz.
}

// Count the trailing zeros in a 64-bit word.

inline int ntz(uint64_t x)
{   return __builtin_ctzll(x);  // Must use the 64-bit version.
}

#else // __GNUC__

inline int nlz(uint64_t x)
{   int n = 0;
    if (x <= 0x00000000FFFFFFFFU)
    {   n = n + 32;
        x = x << 32;
    }
    if (x <= 0x0000FFFFFFFFFFFFU)
    {   n = n + 16;
        x = x << 16;
    }
    if (x <= 0x00FFFFFFFFFFFFFFU)
    {   n = n + 8;
        x = x << 8;
    }
    if (x <= 0x0FFFFFFFFFFFFFFFU)
    {   n = n + 4;
        x = x << 4;
    }
    if (x <= 0x3FFFFFFFFFFFFFFFU)
    {   n = n + 2;
        x = x << 2;
    }
    if (x <= 0x7FFFFFFFFFFFFFFFU)
    {   n = n + 1;
    }
    return n;
}

// This code is to identify the least significant bit in a 64-bit
// value. The function leastBit() just removes all other bits. It is probably
// not going to be used a lot.

uint64_t leastBit(uint64_t n)
{   return n & (-n);
}

// ntz find the bit-number of the least significant bit, So here are some
// values it will return:
//    1      0
//    2      1
//    4      2
//    8      3
//   16      4
// etc. The name is for "Number of Trailing Zeros".
// If the input value is zero it returns -1, but the GNU builting does not
// guarantee any such behaviour, so zero input should be considered illegal.

int ntz(uint64_t n)
{   static int8_t lsbTable[67] =
    {  -1,   0,   1,  39,   2,  15,  40,  23,   3,  12,
       16,  59,  41,  19,  24,  54,   4,  -1,  13,  10,
       17,  62,  60,  28,  42,  30,  20,  51,  25,  44,
       55,  47,   5,  32,  -1,  38,  14,  22,  11,  58,
       18,  53,  63,   9,  61,  27,  29,  50,  43,  46,
       31,  37,  21,  57,  52,   8,  26,  49,  45,  36,
       56,   7,  48,  35,   6,  34,  33,  -1
    };
    else return lsbTable[leastBit(n) % 67];
}

#endif // __GNUC__
#define NLZ_DEFINED 1
#define NTZ_DEFINED 1

#endif // header_newallocate_h

// end of newallocate.h
