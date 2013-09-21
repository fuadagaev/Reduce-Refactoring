
/* $destdir/u16.c        Machine generated C code */

/* Signature: 00000000 21-Sep-2013 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#ifndef _cplusplus
#include <setjmp.h>
#endif

#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
#if !defined UNDER_CE && !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
#endif
#ifndef MS_CDECL
#ifdef _MSC_VER
#  define MS_CDECL __cdecl
#else
#  define MS_CDECL
#endif
#endif
#ifdef WIN32
#  if defined WIN64 || defined __WIN64__
#     define OPSYS           "win64"
#     define IMPNAME         "win64"
#  else
#     define OPSYS           "win32"
#     define IMPNAME         "win32"
#  endif
#else
#  ifdef HOST_OS
#     define OPSYS           HOST_OS
#     ifdef HOST_CPU
#        define IMPNAME      HOST_OS ":" HOST_CPU
#     else
#        define IMPNAME      HOST_OS
#     endif
#  else
#     define OPSYS           "Unknown"
#     define IMPNAME         "Generic"
#  endif
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef  HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef  HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef  HAVE_U_INTPTR_T
typedef u_intptr_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef unsigned int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef short int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef unsigned short int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef unsigned long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef long long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef unsigned long long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_INT32_T
typedef int32_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_INT64_T
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_UINT32_T
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_UINT64_T
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#if !defined HAVE_STDINT_H || !defined HAVE_INT32_T
#error This system needs a 32-bit integer type.
#endif
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
typedef int                 CSLbool;
#define YES                 1
#define NO                  0
#ifndef PAGE_BITS
#  define PAGE_BITS             22
#endif 
#define PAGE_POWER_OF_TWO       (((uint32_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256U)
#ifndef MAX_HEAPSIZE
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#ifndef MAX_BPSSIZE
#  define MAX_BPSSIZE           64
#endif 
#define MEGABYTE                ((uint32_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES               (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES           (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES               (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES           (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES        MAX_BPS_PAGES
#define CSL_IGNORE(x)           (x = x)
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK       0xff
typedef intptr_t Lisp_Object;
#define CELL sizeof(Lisp_Object)
#define TAG_BITS        7
#define TAG_CONS        0   
                            
#define TAG_FIXNUM      1   
#define TAG_ODDS        2   
#ifdef COMMON
#define TAG_SFLOAT      3   
#endif 
#define TAG_SYMBOL      4   
#define TAG_NUMBERS     5   
#define TAG_VECTOR      6   
#define TAG_BOXFLOAT    7   
#define fixnum_of_int(x)    ((Lisp_Object)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) < 0 ?           \
                             (((int32_t)(x))>>4) | (-0x10000000) :  \
                             (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I        8               
#define GC_BIT_H        8               
#define GC_BIT_P        ((intptr_t)~((~(uintptr_t)0) >> 1))
#define is_marked_i(w)      (((int)(w) & GC_BIT_I) != 0)
extern Lisp_Object address_sign;  
#define is_marked_p(w)      (((Lisp_Object)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((Lisp_Object)(w) & ~GC_BIT_P) + \
                              address_sign)
#define flip_mark_bit_i(w)  ((Lisp_Object)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w)  ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w)  ((Lisp_Object)(w) ^ GC_BIT_P)
#define is_marked_h(w)      (((int)(w) & GC_BIT_H) != 0)
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception()    (nil = C_nil = (nil ^ 1))
#define ignore_exception() \
   do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)
#define set_mark_bit_h(h)   ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h)   ((Lisp_Object)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((Lisp_Object)(h) & ~GC_BIT_I)
#define is_cons(p)   ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p)   ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#ifdef COMMON
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#endif 
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p)     (is_cons(p) && (p) != nil)
#define symbolp(p)   (is_symbol(p) || (p) == nil)
#else 
#define consp(p)     is_cons(p)
#define symbolp(p)   is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p)  ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{
    Lisp_Object car;
    Lisp_Object cdr;
} Cons_Cell;
#ifdef MEMORY_TRACE
extern Cons_Cell *memory_reference(intptr_t p);
extern char *cmemory_reference(intptr_t p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;
#define qcar(p) (memory_reference((intptr_t)p)->car)
#define qcdr(p) (memory_reference((intptr_t)p)->cdr)
#else 
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#endif 
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef Lisp_Object Special_Form(Lisp_Object, Lisp_Object);
typedef Lisp_Object one_args(Lisp_Object, Lisp_Object);
typedef Lisp_Object two_args(Lisp_Object, Lisp_Object, Lisp_Object);
typedef Lisp_Object MS_CDECL n_args(Lisp_Object, int, ...);
typedef uintptr_t Header;
#define header_mask          0x3f0
#define type_of_header(h)    (((unsigned int)(h)) & header_mask)
#define length_of_header(h)  (((uint32_t)(h)) >> 10)
#define TYPE_SYMBOL         0x00000010
#define  SYM_SPECIAL_VAR    0x00000040  
#define  SYM_GLOBAL_VAR     0x00000080  
#define  SYM_SPECIAL_FORM   0x00000100  
#define  SYM_MACRO          0x00000200  
#define  SYM_C_DEF          0x00000400  
#define  SYM_CODEPTR        0x00000800  
#define  SYM_ANY_GENSYM     0x00001000  
#define  SYM_TRACED         0x00002000
#define  SYM_FASTGET_MASK   0x000fc000  
#define  SYM_FASTGET_SHIFT  14
#ifdef COMMON
#define  SYM_EXTERN_IN_HOME 0x00100000  
#define  SYM_IN_PACKAGE     0xffe00000  
#define  SYM_IN_PKG_SHIFT   23
#define  SYM_IN_PKG_COUNT   11
#else 
#define  SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length       ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h)   (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM         0x020   
#ifdef COMMON
#define TYPE_RATNUM         0x060
#define TYPE_COMPLEX_NUM    0x0a0
#define TYPE_SINGLE_FLOAT   0x120
#endif 
#define TYPE_DOUBLE_FLOAT   0x160
#ifdef COMMON
#define TYPE_LONG_FLOAT     0x1a0
#endif 
#ifdef MEMORY_TRACE
#define numhdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_NUMBERS)))
#define flthdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_BOXFLOAT)))
#else
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#endif
#define is_numbers_header(h) (((int)(h) & 0x330) == 0x020)
#define is_boxfloat_header(h)(((int)(h) & 0x330) == 0x120)
#ifdef COMMON
#define is_ratio(n) \
    (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
    (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#endif 
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)
#ifdef MEMORY_TRACE
#define vechdr(v)  (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                               TAG_VECTOR)))
#define elt(v, n)  (*(Lisp_Object *)memory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT))))
#define celt(v, n) (*cmemory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define ucelt(v, n) (*(unsigned char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define scelt(v, n) (*(signed char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#else 
#define vechdr(v)  (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT)))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#endif 
#define helt(v, n) \
   ((*(unsigned char *)((v) + (CELL-TAG_VECTOR) + (2*(intptr_t)(n))) | \
    (*(signed char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n)))) << 8))
#define sethelt(v, n, x) \
   do { \
      *(char *)((v) + (CELL-TAG_VECTOR+0) + (2*(intptr_t)(n))) = (x); \
      *(char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n))) = (x)>>8; \
      } while (0)
#define ielt(v, n)  (*(intptr_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n)  (*(int32_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n)  (*(float *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n)  (*(double *)((char *)(v) + \
                           (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
#ifdef COMMON
#define TYPE_BITVEC1        0x030   
#define TYPE_BITVEC2        0x0b0   
#define TYPE_BITVEC3        0x130
#define TYPE_BITVEC4        0x1b0   
#define TYPE_BITVEC5        0x230   
#define TYPE_BITVEC6        0x2b0   
#define TYPE_BITVEC7        0x330   
#define TYPE_BITVEC8        0x3b0   
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#endif 
#define TYPE_STRING         0x070   
#define TYPE_BPS            0x170   
#define TYPE_SPARE          0x270   
#define TYPE_MAPLEREF       TYPE_SPARE 
#define TYPE_FOREIGN        TYPE_SPARE 
#define TYPE_SP             0x370   
#ifdef COMMON
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#else
#define vector_holds_binary(h) (((h) & 0x80) == 0)
#endif
#define TYPE_SIMPLE_VEC     0x0f0   
#define TYPE_HASH           0x1f0   
#define TYPE_ARRAY          0x2f0   
#define TYPE_STRUCTURE      0x3f0   
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8           TYPE_BPS
#define TYPE_VEC16          0x220   
#define TYPE_VEC32          0x260   
#define TYPE_MIXED1         0x2a0   
#define TYPE_MIXED2         0x2e0   
#define TYPE_FLOAT32        0x320   
#define TYPE_FLOAT64        0x360   
#define TYPE_MIXED3         0x3a0   
#define TYPE_STREAM         0x3e0   
#define ODDS_MASK           0xff
#define TAG_CHAR            0x02    
#define TAG_BPS             0x42
#define TAG_SPID            0xc2    
#define SPID_NIL            (TAG_SPID+0x0000)  
#define SPID_FBIND          (TAG_SPID+0x0100)  
#define SPID_CATCH          (TAG_SPID+0x0200)  
#define SPID_PROTECT        (TAG_SPID+0x0300)  
#define SPID_HASH0          (TAG_SPID+0x0400)  
#define SPID_HASH1          (TAG_SPID+0x0500)  
#define SPID_GCMARK         (TAG_SPID+0x0600)  
#define SPID_NOINPUT        (TAG_SPID+0x0700)  
#define SPID_ERROR          (TAG_SPID+0x0800)  
#define SPID_PVBIND         (TAG_SPID+0x0900)  
#define SPID_NOARG          (TAG_SPID+0x0a00)  
#define SPID_NOPROP         (TAG_SPID+0x0b00)  
#define SPID_LIBRARY        (TAG_SPID+0x0c00)  
#define is_header(x) (((int)(x) & 0x30) != 0)     
#define is_char(x)   (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x)    (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_spid(x)   (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff)    == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#ifdef OLD_VERSION
#define font_of_char(n)  (((int32_t)(n) >> 24) & 0xff)
#define bits_of_char(n)  (((int32_t)(n) >> 16) & 0xff)
#ifdef Kanji
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0xffff)
#else
#define code_of_char(n)  ((char)(((int32_t)(n) >>  8) & 0xff))
#endif
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 24) |                  \
    (((uint32_t)(bits)) << 16) | (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0xff, 4)
#else 
#define font_of_char(n)  (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n)  (0)
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0x001fffff)
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 29) |                    \
                   (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF ((Lisp_Object)(int32_t)0xff000402)
#endif  
#define data_of_bps(v)                                        \
  ((char *)(doubleword_align_up((intptr_t)                    \
               bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) +   \
            (SIXTY_FOUR_BIT ?                                 \
               (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
                          PAGE_POWER_OF_TWO) :                \
               0) +                                           \
            (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk;      
typedef intptr_t junkxx;   
typedef struct Symbol_Head
{
    Header header;      
    Lisp_Object value;   
    Lisp_Object env;     
    intptr_t function1;  
    intptr_t function2;  
    intptr_t functionn;  
    Lisp_Object pname;   
    Lisp_Object plist;   
    Lisp_Object fastgets;
    uintptr_t count;     
#ifdef COMMON
    Lisp_Object package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE  63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
     ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
     (n)
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p)     (*(Header *)     symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p)      (*(Lisp_Object *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p)        (*(Lisp_Object *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p)        ((one_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (3*CELL - TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (4*CELL - TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *((intptr_t *)symalign((char *)(p) + \
                                         (5*CELL - TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p)        (*(intptr_t *)      symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p)        (*(intptr_t *)      symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p)      (*(Lisp_Object *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p)      (*(Lisp_Object *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p)   (*(Lisp_Object *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p)      (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p)     (*(Header *)     memory_reference((intptr_t) \
                                         symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p)        (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p)        ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p)   (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p)      (*(uintptr_t *) memory_reference((intptr_t) \
                                         symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
#ifdef COMMON
typedef union Float_union
{
    float f;
    int32_t i;
} Float_union;
#endif
typedef struct Big_Number
{
    Header h;
    uint32_t d[1];  
} Big_Number;
#define bignum_length(b)  length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b)  ((uint32_t *)memory_reference((intptr_t)((char *)b + \
                                         (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b)  ((uint32_t *)((char *)b  + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n)    (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)
#ifdef COMMON
typedef struct Rational_Number
{
    Header header;
    Lisp_Object num;
    Lisp_Object den;
} Rational_Number;
#define numerator(r)    (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r)  (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{
    Header header;
    Lisp_Object real;
    Lisp_Object imag;
} Complex_Number;
#define real_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{
    Header header;
    union float_or_int {
       float f;
       int32_t i;
    } f;
} Single_Float;
#define single_float_val(v) \
    (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#endif 
#define SIZEOF_DOUBLE_FLOAT     16
#define double_float_addr(v)    ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define double_float_val(v)     (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#ifdef COMMON
#define SIZEOF_LONG_FLOAT       16
#define long_float_addr(v)      ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define long_float_val(v)       (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#endif
#define word_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((Lisp_Object)(((intptr_t)(n) + \
                            sizeof(Lisp_Object) - 1) & (-sizeof(Lisp_Object))))
#define quadword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-16)))
#define UNWIND_NULL       0x0         
#define UNWIND_GO         0x1         
#define UNWIND_RETURN     0x2         
#define UNWIND_THROW      0x3         
#define UNWIND_RESTART    0x4         
#define UNWIND_RESOURCE   0x5         
#define UNWIND_FNAME      0x100       
#define UNWIND_ARGS       0x200       
#define UNWIND_ERROR      (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND     0x400       
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern Lisp_Object interrupted(Lisp_Object p);
extern Lisp_Object MS_CDECL error(int nargs, int code, ...);
extern Lisp_Object MS_CDECL cerror(int nargs, int code1, int code2, ...);
extern Lisp_Object too_few_2(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object too_many_1(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_0a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_0b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_3a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_3b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_na(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_nb(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL wrong_no_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL wrong_no_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object bad_special2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL bad_specialn(Lisp_Object env, int nargs, ...);
extern Lisp_Object aerror(char *s);         
extern Lisp_Object aerror0(char *s);
extern Lisp_Object aerror1(char *s, Lisp_Object a);
extern Lisp_Object aerror2(char *s, Lisp_Object a, Lisp_Object b);
extern void MS_CDECL fatal_error(int code, ...);
#define GC_MESSAGES   0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS  0x04
#define GC_MSG_BITS   0x07
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG    0x10
#define ARGS_FLAG     0x20
#define BACKTRACE_MSG_BITS 0x38
 
#define err_bad_car               0      
#define err_bad_cdr               1      
#define err_no_store              2      
#define err_undefined_function_1  3      
#define err_undefined_function_2  4      
#define err_undefined_function_n  5      
#define err_wrong_no_args         6      
#define err_unbound_lexical       7      
#define err_bad_rplac             8      
#define err_bad_arith             9      
#define err_redef_special        10      
#define err_bad_arg              11      
#define err_bad_declare          12      
#define err_bad_fn               13      
#define err_unset_var            14      
#define err_too_many_args1       15      
#define err_too_many_args2       16      
#define err_bad_apply            17      
#define err_macroex_hook         18      
#define err_block_tag            19      
#define err_go_tag               20      
#define err_excess_args          21
#define err_insufficient_args    22
#define err_bad_bvl              23      
#define err_bad_keyargs          24
#define err_write_err            25
#define err_bad_endp             26      
#define err_no_fasldir           27
#define err_no_fasl              28      
#define err_open_failed          29      
#define err_pipe_failed          30      
#define err_stack_overflow       31
#define err_top_bit              32
#define err_mem_spans_zero       33
#define err_no_longer_used       34      
#define err_no_tempdir           35
    
#ifdef INCLUDE_ERROR_STRING_TABLE
static char *error_message_table[] =
{
    "attempt to take car of an atom",
    "attempt to take cdr of an atom",
    "insufficient freestore to run this package",
    "undefined function (1 arg)",
    "undefined function (2 args)",
    "undefined function",
    "wrong number of arguments",
    "unbound lexical variable",
    "bad rplaca/rplacd",
    "bad argument for an arithmetic function",
    "attempt to redefine a special form",
    "not a variable",
    "bad use of declare",
    "attempt to apply non-function",
    "unset variable",
    "too many arguments",
    "too many arguments",
    "object not valid as a function (apply,",
    "macroexpand-hook failure",
    "block tag not found",
    "go tag not found",
    "too many arguments provided",
    "not enough arguments provided",
    "bad item in bound variable list",
    "bad keyword arguments",
    "write-error on file",
    "endp used on badly terminated list",
    "environment parameter 'fasldir' not set",
    "loadable module not found for loading",
    "file could not be opened",
    "unable to establish pipe",
    "stack overflow",
    "top bit of address has unexpected value",
    "memory block spans the zero address",
    "this error code available for re-use",
    "unable to find a directory for temporary files",
    "dummy final error message"
};
#endif
#endif 
#ifndef header_externs_h
#define header_externs_h 1
#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
          fflush(stderr); \
          } while (0)
#define DS(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
          fflush(stderr); \
          } while (0)
#define DX(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
                          (long long unsigned)(s)); \
          fflush(stderr); \
          } while (0)
extern void **pages,
            **heap_pages, **vheap_pages,
            **bps_pages, **native_pages;
extern void **new_heap_pages, **new_vheap_pages,
            **new_bps_pages, **new_native_pages;
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS   0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS    2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{
    void *start;
    void *end;
    int type;
} page_map_t;
#endif
extern int32_t pages_count,
               heap_pages_count, vheap_pages_count,
               bps_pages_count, native_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count,
               new_bps_pages_count, new_native_pages_count;
extern int32_t native_pages_changed;
extern int32_t native_fringe;
extern Lisp_Object *nilsegment, *stacksegment;
extern Lisp_Object *stackbase;
extern int32_t stack_segsize;  
extern Lisp_Object *C_stack;
#define stack C_stack
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern CSLbool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
#ifdef MEMORY_TRACE
#define push(a)         do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); } while (0)
#define push2(a,b)      do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c)    do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d)  do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); } while (0)
#define push5(a,b,c,d,e)do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (e); \
                          memory_reference((intptr_t)stack); } while (0)
#define push6(a,b,c,d,e,f) do {push3(a,b,c); push3(d,e,f); } while (0)
#define my_pop()        (memory_reference((int32_t)stack), (*stack--))
#define pop(a)          { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b)       { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c)     { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d)   { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n)           stack -= (n)
#else 
#define push(a)         { *++stack = (a); }
#define push2(a,b)      { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c)    { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack += 3; }
#define push4(a,b,c,d)  { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) {                                              \
                          stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack[6] = (f); \
                          stack += 6; }
#define pop(a)          { (a) = *stack--; }
#define pop2(a,b)       { stack -= 2;     (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c)     { stack -= 3;     (a) = stack[3]; (b) = stack[2]; \
                          (c) = stack[1]; }
#define pop4(a,b,c,d)   { stack -= 4;     (a) = stack[4]; (b) = stack[3]; \
                          (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5;     (a) = stack[5]; (b) = stack[4]; \
                          (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6;                                  \
                          (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
                          (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n)           stack -= (n)
#endif 
#define errexit()    { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n)  { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return nil; } }
#define errexitv()   { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK     2
#define GC_CONS      3
#define GC_VEC       4
#define GC_BPS       5
#define GC_PRESERVE  6
#define GC_NATIVE    7
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
extern void show_stack();
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) \
   {   show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
   {   char *p = (char *)&p; \
       if (p < C_stack_limit) return aerror("stack overflow"); \
   }
#endif
extern int32_t software_ticks, countdown;
#define stackcheck0(k)                                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck1(k, a1)                                  \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck2(k, a1, a2)                              \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck3(k, a1, a2, a3)                          \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck4(k, a1, a2, a3, a4)                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
extern Lisp_Object C_nil;
#define first_nil_offset         50     
#define work_0_offset           200
#define last_nil_offset         251
#define NIL_SEGMENT_SIZE    (last_nil_offset*sizeof(Lisp_Object) + 32)
#define SPARE                   512
#ifdef COMMON
#define BASE ((Lisp_Object *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((Lisp_Object *)(nil+4)): ((Lisp_Object *)nil))
#endif
#ifdef NILSEG_EXTERNS
#define nil_as_base
extern intptr_t byteflip;
extern Lisp_Object codefringe;
extern Lisp_Object volatile codelimit;
extern Lisp_Object * volatile stacklimit;
extern Lisp_Object fringe;
extern Lisp_Object volatile heaplimit;
extern Lisp_Object volatile vheaplimit;
extern Lisp_Object vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
extern Lisp_Object lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern Lisp_Object quote_symbol, function_symbol, comma_symbol;
extern Lisp_Object comma_at_symbol, cons_symbol, eval_symbol;
extern Lisp_Object work_symbol, evalhook, applyhook, macroexpand_hook;
extern Lisp_Object append_symbol, exit_tag, exit_value, catch_tags;
extern Lisp_Object current_package, startfn;
extern Lisp_Object gensym_base, string_char_sym, boffo;
extern Lisp_Object err_table;
extern Lisp_Object progn_symbol;
extern Lisp_Object lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern Lisp_Object echo_symbol, codevec, litvec, supervisor, B_reg;
extern Lisp_Object savedef, comp_symbol, compiler_symbol, faslvec;
extern Lisp_Object tracedfn, lisp_terminal_io;
extern Lisp_Object lisp_standard_output, lisp_standard_input, lisp_error_output;
extern Lisp_Object lisp_trace_output, lisp_debug_io, lisp_query_io;
extern Lisp_Object prompt_thing, faslgensyms;
extern Lisp_Object prinl_symbol, emsg_star, redef_msg;
extern Lisp_Object expr_symbol, fexpr_symbol, macro_symbol;
extern Lisp_Object cl_symbols, active_stream, current_module;
extern Lisp_Object native_defs, features_symbol, lisp_package;
extern Lisp_Object sys_hash_table, help_index, cfunarg, lex_words;
extern Lisp_Object get_counts, fastget_names, input_libraries;
extern Lisp_Object output_library, current_file, break_function;
extern Lisp_Object standard_output, standard_input, debug_io;
extern Lisp_Object error_output, query_io, terminal_io;
extern Lisp_Object trace_output, fasl_stream;
extern Lisp_Object native_code, native_symbol, traceprint_symbol;
extern Lisp_Object loadsource_symbol;
extern Lisp_Object hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
extern Lisp_Object gchook, resources, callstack, procstack, procmem, trap_time;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol, large_modulus;
extern Lisp_Object used_space, avail_space;
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
extern Lisp_Object workbase[51];
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0              workbase[0]
#define work_1              workbase[1]
#define mv_1                workbase[1]
#define mv_2                workbase[2]
#define mv_3                workbase[3]
#define work_50             workbase[50]
#else 
#define nil_as_base  Lisp_Object nil = C_nil;
#define byteflip              BASE[12]
#define codefringe            BASE[13]
#define codelimit             (*(Lisp_Object volatile *)&BASE[14])
extern Lisp_Object * volatile stacklimit;
#define fringe                BASE[18]
#define heaplimit             (*(Lisp_Object volatile *)&BASE[19])
#define vheaplimit            (*(Lisp_Object volatile *)&BASE[20])
#define vfringe               BASE[21]
#define miscflags             BASE[22]
#define nwork                 BASE[24]
#define exit_count            BASE[26]
#define gensym_ser            BASE[27]
#define print_precision       BASE[28]
#define current_modulus       BASE[29]
#define fastget_size          BASE[30]
#define package_bits          BASE[31]
#define modulus_is_large      BASE[32]
#define current_package       BASE[52]
#define B_reg                 BASE[53]
#define codevec               BASE[54]
#define litvec                BASE[55]
#define exit_tag              BASE[56]
#define exit_value            BASE[57]
#define catch_tags            BASE[58]
#define lisp_package          BASE[59]
#define boffo                 BASE[60]
#define charvec               BASE[61]
#define sys_hash_table        BASE[62]
#define help_index            BASE[63]
#define gensym_base           BASE[64]
#define err_table             BASE[65]
#define supervisor            BASE[66]
#define startfn               BASE[67]
#define faslvec               BASE[68]
#define tracedfn              BASE[69]
#define prompt_thing          BASE[70]
#define faslgensyms           BASE[71]
#define cl_symbols            BASE[72]
#define active_stream         BASE[73]
#define current_module        BASE[74]
#define native_defs           BASE[75]
#define append_symbol         BASE[90]
#define applyhook             BASE[91]
#define cfunarg               BASE[92]
#define comma_at_symbol       BASE[93]
#define comma_symbol          BASE[94]
#define compiler_symbol       BASE[95]
#define comp_symbol           BASE[96]
#define cons_symbol           BASE[97]
#define echo_symbol           BASE[98]
#define emsg_star             BASE[99]
#define evalhook              BASE[100]
#define eval_symbol           BASE[101]
#define expr_symbol           BASE[102]
#define features_symbol       BASE[103]
#define fexpr_symbol          BASE[104]
#define funarg                BASE[105]
#define function_symbol       BASE[106]
#define lambda                BASE[107]
#define lisp_true             BASE[108]
#define lower_symbol          BASE[109]
#define macroexpand_hook      BASE[110]
#define macro_symbol          BASE[111]
#define opt_key               BASE[112]
#define prinl_symbol          BASE[113]
#define progn_symbol          BASE[114]
#define quote_symbol          BASE[115]
#define raise_symbol          BASE[116]
#define redef_msg             BASE[117]
#define rest_key              BASE[118]
#define savedef               BASE[119]
#define string_char_sym       BASE[120]
#define unset_var             BASE[121]
#define work_symbol           BASE[122]
#define lex_words             BASE[123]
#define get_counts            BASE[124]
#define fastget_names         BASE[125]
#define input_libraries       BASE[126]
#define output_library        BASE[127]
#define current_file          BASE[128]
#define break_function        BASE[129]
#define lisp_work_stream      BASE[130]
#define lisp_standard_output  BASE[131]
#define lisp_standard_input   BASE[132]
#define lisp_debug_io         BASE[133]
#define lisp_error_output     BASE[134]
#define lisp_query_io         BASE[135]
#define lisp_terminal_io      BASE[136]
#define lisp_trace_output     BASE[137]
#define standard_output       BASE[138]
#define standard_input        BASE[139]
#define debug_io              BASE[140]
#define error_output          BASE[141]
#define query_io              BASE[142]
#define terminal_io           BASE[143]
#define trace_output          BASE[144]
#define fasl_stream           BASE[145]
#define native_code           BASE[146]
#define native_symbol         BASE[147]
#define traceprint_symbol     BASE[148]
#define loadsource_symbol     BASE[149]
#define hankaku_symbol        BASE[150]
#define bytecoded_symbol      BASE[151]
#define nativecoded_symbol    BASE[152]
#define gchook                BASE[153]
#define resources             BASE[154]
#define callstack             BASE[155]
#define procstack             BASE[156]
#define procmem               BASE[157]
#define trap_time             BASE[158]
#ifdef COMMON
#define keyword_package       BASE[170]
#define all_packages          BASE[171]
#define package_symbol        BASE[172]
#define internal_symbol       BASE[173]
#define external_symbol       BASE[174]
#define inherited_symbol      BASE[175]
#define key_key               BASE[176]
#define allow_other_keys      BASE[177]
#define aux_key               BASE[178]
#define format_symbol         BASE[179]
#define expand_def_symbol     BASE[180]
#define allow_key_key         BASE[181]
#endif
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
#define large_modulus         BASE[184]
#define used_space            BASE[185]
#define avail_space           BASE[186]
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0                BASE[200]
#define work_1                BASE[201]
#define mv_1                  work_1
#define mv_2                  BASE[202]
#define mv_3                  BASE[203]
#define work_50               BASE[250]
#endif 
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list     BASE[50] 
#define equal_hash_table_list  BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(Lisp_Object v);
extern Lisp_Object eq_hash_tables, equal_hash_tables;
extern Lisp_Object volatile savecodelimit;
extern Lisp_Object * volatile savestacklimit;
extern Lisp_Object volatile saveheaplimit;
extern Lisp_Object volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
#ifdef DEBUG
extern int trace_all;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern char **csl_argv;
extern int fasl_output_file, output_directory;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
extern int boffop;
extern void packbyte(int c);
#ifndef COMMON
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#endif
#endif
#ifdef SOCKETS
extern int sockets_ready;
extern void flush_socket(void);
#endif
extern void report_file(const char *s);
extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern int errorset_min, errorset_max;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count;
#define INIT_QUIET      1
#define INIT_VERBOSE    2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p)  ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{
    FILE *f;        
    long int o;     
    long int n;     
    uint32_t chk;   
    int status;     
    int nativedir;  
} Ihandle;
extern int32_t compression_worth_while;
#define CODESIZE                0x1000
typedef struct entry_point1
{
    one_args *p;
    char *s;
} entry_point1;
typedef struct entry_point2
{
    two_args *p;
    char *s;
} entry_point2;
typedef struct entry_pointn
{
    n_args *p;
    char *s;
} entry_pointn;
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_table_io[];
extern void set_up_entry_lookup(void);
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);
extern int doubled_execution;
extern char *linker_type;
extern char *compiler_command[], *import_data[],
            *config_header[], *csl_headers[];
extern Lisp_Object encapsulate_pointer(void *);
extern void *extract_pointer(Lisp_Object a);
extern Lisp_Object Lencapsulatedp(Lisp_Object nil, Lisp_Object a);
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
#ifdef MEMORY_TRACE
extern intptr_t memory_base, memory_size;
extern unsigned char *memory_map;
extern FILE *memory_file;
extern void memory_comment(int n);
#endif
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit(void);
extern void IreInit(void);
extern void Icontext(Ihandle *);
extern void Irestore_context(Ihandle);
extern void Ilist(void);
extern CSLbool open_output(char *s, int len);
#define IOPEN_OUT       0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED   2
extern CSLbool Iopen(char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(char *name, int len, char *datestamp, int32_t *size,
                                 char *expanded_name);
extern CSLbool Icopy(char *name, int len);
extern CSLbool Idelete(char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int  Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(void *buff, int32_t size);
extern long int Ioutsize(void);
extern char *CSLtmpnam(char *suffix, int32_t suffixlen);
extern int Cmkdir(char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(Lisp_Object a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen(void);
extern int window_heading;
extern void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock(void);
extern double pop_clock(void);
extern double consolidated_time[10], gc_time;
extern CSLbool volatile already_in_gc, tick_on_gc_exit;
extern CSLbool volatile interrupt_pending, tick_pending;
extern int deal_with_tick(void);
extern int current_fp_rep;
#ifndef __cplusplus
#ifdef USE_SIGALTSTACK
extern sigjmp_buf *errorset_buffer;
extern sigjmp_buf my_exit_buffer;
#else
extern jmp_buf *errorset_buffer;
extern jmp_buf my_exit_buffer;
#endif
#endif
extern char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(Lisp_Object *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void MS_CDECL low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern void MS_CDECL sigint_handler(int code);
extern void record_get(Lisp_Object tag, CSLbool found);
extern int         primep(int32_t);
extern void        adjust_all(void);
extern void        set_up_functions(CSLbool restartp);
extern void        get_user_files_checksum(unsigned char *);
extern Lisp_Object acons(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object bytestream_interpret(Lisp_Object code, Lisp_Object lit,
                                        Lisp_Object *entry_stack);
extern CSLbool        complex_stringp(Lisp_Object a);
extern void        freshline_trace(void);
extern void        freshline_debug(void);
extern Lisp_Object cons(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_no_gc(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_gc_test(Lisp_Object a);
extern void        convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern Lisp_Object Ceval(Lisp_Object u, Lisp_Object env);
extern uint32_t  Crand(void);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern void        Csrand(uint32_t a, uint32_t b);
extern void        discard(Lisp_Object a);
extern CSLbool eql_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool cl_equal_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool equal_fn(Lisp_Object a, Lisp_Object b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(Lisp_Object a, Lisp_Object b,
                                      char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern CSLbool equalp(Lisp_Object a, Lisp_Object b);
extern Lisp_Object apply(Lisp_Object fn, int nargs,
                         Lisp_Object env, Lisp_Object fname);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name);
extern void        deallocate_pages(void);
extern void        drop_heap_segments(void);
extern Lisp_Object gcd(Lisp_Object a, Lisp_Object b);
extern Lisp_Object get_pname(Lisp_Object a);
#ifdef COMMON
extern Lisp_Object get(Lisp_Object a, Lisp_Object b, Lisp_Object c);
#else
extern Lisp_Object get(Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object getvector(int tag, int type, int32_t length);
extern Lisp_Object getvector_init(int32_t n, Lisp_Object v);
extern Lisp_Object getcodevector(int type, int32_t size);
extern uint32_t  hash_lisp_string(Lisp_Object s);
extern void lose_C_def(Lisp_Object a);
extern CSLbool        geq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        greaterp2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lesseq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lessp2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2star(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3star(Lisp_Object a, Lisp_Object b,
                             Lisp_Object c, Lisp_Object d);
extern Lisp_Object list4(Lisp_Object a, Lisp_Object b,
                         Lisp_Object c, Lisp_Object d);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object macroexpand(Lisp_Object form, Lisp_Object env);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_package(Lisp_Object name);
extern Lisp_Object make_string(const char *b);
extern Lisp_Object make_nstring(char *b, int32_t n);
extern Lisp_Object make_undefined_symbol(char const *s);
extern Lisp_Object make_symbol(char const *s, int restartp,
                               one_args *f1, two_args *f2, n_args *fn);
extern void MS_CDECL  stdout_printf(char *fmt, ...);
extern void MS_CDECL  term_printf(char *fmt, ...);
extern void MS_CDECL  err_printf(char *fmt, ...);
extern void MS_CDECL  debug_printf(char *fmt, ...);
extern void MS_CDECL  trace_printf(char *fmt, ...);
extern char        *my_getenv(char *name);
extern Lisp_Object ncons(Lisp_Object a);
extern Lisp_Object ndelete(Lisp_Object a, Lisp_Object b);
extern Lisp_Object negate(Lisp_Object a);
extern Lisp_Object nreverse(Lisp_Object a);
extern FILE        *open_file(char *filename, char *original_name,
                              size_t n, char *dirn, FILE *old_file);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern void        preserve(char *msg, int len);
extern void        preserve_native_code(void);
extern void        relocate_native_function(unsigned char *bps);
extern Lisp_Object prin(Lisp_Object u);
extern char *get_string_data(Lisp_Object a, char *why, int32_t *len);
extern void prin_to_stdout(Lisp_Object u);
extern void prin_to_terminal(Lisp_Object u);
extern void prin_to_debug(Lisp_Object u);
extern void prin_to_query(Lisp_Object u);
extern void prin_to_trace(Lisp_Object u);
extern void prin_to_error(Lisp_Object u);
extern void loop_print_stdout(Lisp_Object o);
extern void loop_print_terminal(Lisp_Object o);
extern void loop_print_debug(Lisp_Object o);
extern void loop_print_query(Lisp_Object o);
extern void loop_print_trace(Lisp_Object o);
extern void loop_print_error(Lisp_Object o);
extern void internal_prin(Lisp_Object u, int prefix);
extern Lisp_Object princ(Lisp_Object u);
extern Lisp_Object print(Lisp_Object u);
extern Lisp_Object printc(Lisp_Object u);
extern void        print_bignum(Lisp_Object u, CSLbool blankp, int nobreak);
extern void        print_bighexoctbin(Lisp_Object u,
                       int radix, int width, CSLbool blankp, int nobreak);
extern Lisp_Object putprop(Lisp_Object a, Lisp_Object b,
                       Lisp_Object c);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern void        read_eval_print(int noisy);
extern Lisp_Object reclaim(Lisp_Object value_to_return, char *why,
                           int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(char *why, int line, char *file);
extern int check_env(Lisp_Object env);
#endif
extern CSLbool do_not_kill_native_code;
extern void        set_fns(Lisp_Object sym, one_args *f1,
                                            two_args *f2, n_args *fn);
extern void        setup(int restartp, double storesize);
extern Lisp_Object simplify_string(Lisp_Object s);
extern CSLbool        stringp(Lisp_Object a);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern int32_t       thirty_two_bits(Lisp_Object a);
#ifdef HAVE_INT64_T
extern int64_t       sixty_four_bits(Lisp_Object a);
#endif
#ifdef DEBUG
extern void validate_string_fn(Lisp_Object a, char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
#ifdef COMMON
#define onevalue(r)   (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r)   (r)
#define nvalues(r, n) (r)
#endif
#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
#endif
#define equal(a, b)                                \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      equal_fn(a, b)))
#define cl_equal(a, b)                             \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      cl_equal_fn(a, b)))
#define eql(a, b)                                  \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      eql_fn(a, b)))
#ifndef IMULTIPLY
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
                            uint32_t b, uint32_t c);
#endif
#ifndef IDIVIDE
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
                          uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#endif
#define argcheck(var, n, msg) if ((var)!=(n)) return aerror(msg);
extern n_args   *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args   *three_arg_functions[];
extern void     *useful_functions[];
extern char     *address_of_var(int n);
typedef struct setup_type
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
} setup_type;
typedef struct setup_type_1
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
    uint32_t c1;
    uint32_t c2;
} setup_type_1;
extern setup_type const
       arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
       char_setup[], eval1_setup[], eval2_setup[], eval3_setup[],
       funcs1_setup[], funcs2_setup[], funcs3_setup[], print_setup[],
       read_setup[], mpi_setup[];
extern setup_type const
                    u01_setup[], u02_setup[], u03_setup[], u04_setup[],
       u05_setup[], u06_setup[], u07_setup[], u08_setup[], u09_setup[],
       u10_setup[], u11_setup[], u12_setup[], u13_setup[], u14_setup[],
       u15_setup[], u16_setup[], u17_setup[], u18_setup[], u19_setup[],
       u20_setup[], u21_setup[], u22_setup[], u23_setup[], u24_setup[],
       u25_setup[], u26_setup[], u27_setup[], u28_setup[], u29_setup[],
       u30_setup[], u31_setup[], u32_setup[], u33_setup[], u34_setup[],
       u35_setup[], u36_setup[], u37_setup[], u38_setup[], u39_setup[],
       u40_setup[], u41_setup[], u42_setup[], u43_setup[], u44_setup[],
       u45_setup[], u46_setup[], u47_setup[], u48_setup[], u49_setup[],
       u50_setup[], u51_setup[], u52_setup[], u53_setup[], u54_setup[],
       u55_setup[], u56_setup[], u57_setup[], u58_setup[], u59_setup[],
       u60_setup[];
extern setup_type const *setup_tables[];
#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif
#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif
extern char *find_image_directory(int argc, char *argv[]);
extern char program_name[64];
extern Lisp_Object declare_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object function_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object let_fn_1(Lisp_Object bvl, Lisp_Object body,
                            Lisp_Object env, int compilerp);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object resource_exceeded();
extern int64_t time_base,  space_base,  io_base,  errors_base;
extern int64_t time_now,   space_now,   io_now,   errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(Lisp_Object def, Lisp_Object env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#ifdef __cplusplus
}
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32    4294967296.0      
#define TWO_31    2147483648.0      
#define TWO_24    16777216.0        
#define TWO_22    4194304.0         
#define TWO_21    2097152.0         
#define TWO_20    1048576.0         
#define M2_31_1   -2147483649.0     
#define _pi       ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi  ((12868.0 - 0.036490896206895257)/8192.0)
#define boole_clr   0
#define boole_and   1
#define boole_andc2 2
#define boole_1     3
#define boole_andc1 4
#define boole_2     5
#define boole_xor   6
#define boole_ior   7
#define boole_nor   8
#define boole_eqv   9
#define boole_c2    10
#define boole_orc2  11
#define boole_c1    12
#define boole_orc1  13
#define boole_nand  14
#define boole_set   15
#define top_bit_set(n)     (((int32_t)(n)) < 0)
#define top_bit(n)         (((uint32_t)(n)) >> 31)
#define set_top_bit(n)     ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n)   ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1      
#define Dmultiply(hi, lo, a, b, c)                          \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) +  \
                     (uint32_t)(c);                       \
      (lo) = 0x7fffffffu & (uint32_t)r64;                 \
      (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE   1
#define Ddivide(r, q, a, b, c)                                      \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
      uint64_t c64 = (uint64_t)(uint32_t)(c);                 \
      q = (uint32_t)(r64 / c64);                                  \
      r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b)   ((r) = Idiv10_9(&(q), (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
    ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern Lisp_Object negateb(Lisp_Object);
extern Lisp_Object copyb(Lisp_Object);
extern Lisp_Object negate(Lisp_Object);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object difference2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object CLquot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quotbn(Lisp_Object a, int32_t n);
extern Lisp_Object quotbn1(Lisp_Object a, int32_t n);
extern Lisp_Object quotbb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembi(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object shrink_bignum(Lisp_Object a, int32_t lena);
extern Lisp_Object modulus(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern Lisp_Object rationalize(Lisp_Object a);
extern Lisp_Object lcm(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lengthen_by_one_bit(Lisp_Object a, int32_t msd);
extern CSLbool numeq2(Lisp_Object a, Lisp_Object b);
extern CSLbool zerop(Lisp_Object a);
extern CSLbool onep(Lisp_Object a);
extern CSLbool minusp(Lisp_Object a);
extern CSLbool plusp(Lisp_Object a);
extern CSLbool lesspbd(Lisp_Object a, double b);
extern CSLbool lessprd(Lisp_Object a, double b);
extern CSLbool lesspdb(double a, Lisp_Object b);
extern CSLbool lesspdr(double a, Lisp_Object b);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_two_word_bignum(int32_t a, uint32_t b);
extern Lisp_Object make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_lisp_integer32(int32_t n);
extern Lisp_Object make_lisp_integer64(int64_t n);
extern Lisp_Object make_sfloat(double d);
extern double float_of_integer(Lisp_Object a);
extern Lisp_Object add1(Lisp_Object p);
extern Lisp_Object sub1(Lisp_Object p);
extern Lisp_Object integerp(Lisp_Object p);
extern double float_of_number(Lisp_Object a);
extern Lisp_Object make_boxfloat(double a, int32_t type);
extern Lisp_Object make_complex(Lisp_Object r, Lisp_Object i);
extern Lisp_Object make_ratio(Lisp_Object p, Lisp_Object q);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object logior2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logxor2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logand2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logeqv2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rationalf(double d);
extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(Lisp_Object a, Lisp_Object b);
extern CSLbool lesspib(Lisp_Object a, Lisp_Object b);
#ifdef COMMON
typedef struct Complex
{
    double real;
    double imag;
} Complex;
extern Complex MS_CDECL Cln(Complex a);
extern Complex MS_CDECL Ccos(Complex a);
extern Complex MS_CDECL Cexp(Complex a);
extern Complex MS_CDECL Cpow(Complex a, Complex b);
extern double MS_CDECL Cabs(Complex a);
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
#ifdef __cplusplus
extern "C" {
#endif
extern Lisp_Object MS_CDECL Lbatchp(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecounts(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ldate(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ldatestamp(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Leject(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lflush(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgc0(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgctime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgensym(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist_modules(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llibrary_members0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmapstore0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lnext_random(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lread(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lreadch(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lrtell(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lterpri(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltmpnam(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ltyi(Lisp_Object env, int nargs, ...);
extern Lisp_Object autoload1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object bytecounts1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object double_byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object double_hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracefunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object undefined1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object f1_as_0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object f1_as_1(Lisp_Object env, Lisp_Object a);
#ifdef CJAVA
extern Lisp_Object java1(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object Labsval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ladd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lalpha_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply_1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Latan(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Latom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbanner(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lboundp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbpsp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lbpsupbv(Lisp_Object nil, Lisp_Object v);
extern Lisp_Object Lcaaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lchar_code(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lclose(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcodep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcompress(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconsp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconstantp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcopy_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldefine_in_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldelete_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldigitp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lendp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lerror1(Lisp_Object nil, Lisp_Object a1);
extern Lisp_Object Lerrorset1(Lisp_Object nil, Lisp_Object form);
extern Lisp_Object Leval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levenp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levlis(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lcn(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexplode2n(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodec(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodecn(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodehex(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexploden(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodeoctal(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfixp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloat(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloatp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfrexp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfuncall1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Lgc(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lgensym1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgensym2(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetenv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lget_bps(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lhelp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Liadd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lidentity(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lindirect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintegerp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lionep(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lisub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lizerop(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llengthc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llibrary_members(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llinelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_string(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_vector(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_source(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llognot(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llog_1(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand_1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacro_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmapstore(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmd5(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lmd60(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkevect(Lisp_Object nil, Lisp_Object n);
extern Lisp_Object Lmkquote(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_minus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_number(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_reciprocal(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodule_exists(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmv_list(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lncons(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnull(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnumberp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Loddp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lonep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lpagelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplist(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin2a(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprint(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprintc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrandom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrational(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrdf1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrds(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lremd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsetpchar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lset_small_modulus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_char(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_form_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspool(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstart_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstop(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstringp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbolp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcount(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_env(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_globalp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_name(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_restore_fns(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_specialp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_value(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsystem(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lthreevectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lthrow_nil(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltruncate(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lttab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltyo(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Luntrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lupbv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsimple_vectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lvectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lverbos(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwhitespace_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwritable_libraryp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrite_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrs(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lzerop(Lisp_Object env, Lisp_Object a);
#ifdef COMMON
extern Lisp_Object Lfind_symbol_1(Lisp_Object nil, Lisp_Object str);
extern Lisp_Object Llistp(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object autoload2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object double_hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracefunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object undefined2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object f2_as_0(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef CJAVA
extern Lisp_Object java2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object Lappend(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lapply_2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lapply1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lassoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2d(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latsoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lbpsgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n);
extern Lisp_Object Lcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcopy_native(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldeleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldelete(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldifference2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldivide(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequalcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leql(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqn(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcl_equal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lerror2(Lisp_Object nil, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object Lerrorset2(Lisp_Object nil, Lisp_Object form, Lisp_Object ffg1);
extern Lisp_Object Lexpt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagpcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfuncall2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lgcd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgeq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget_hash_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lhelp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lidifference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligeq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lileq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lilessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limax(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limin(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Linorm(Lisp_Object nil, Lisp_Object a, Lisp_Object k);
extern Lisp_Object Linstate_c_code(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintersect(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liremainder(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lirightshift(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Litimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llcm(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llist2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmax2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmember(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmin2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmod(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_difference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_expt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_plus(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_quotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_times(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnconc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lneq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnreverse2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lorderp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lpair(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrem(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremprop(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lresource_limit2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplaca(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplacd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrseek(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lset(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lset_help_file(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsubla(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsublis(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_protect(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_definition(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_env(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lthrow_one_value(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunion(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lwrite_help_module(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lxcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef COMMON
extern Lisp_Object Laref2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfloat_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_1_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrandom_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltruncate_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object MS_CDECL autoloadn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracefunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL undefinedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f0_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_3(Lisp_Object env, int nargs, ...);
#ifdef CJAVA
extern Lisp_Object MS_CDECL java0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL java3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL javan(Lisp_Object env, int nargs, ...);
#endif
extern Lisp_Object MS_CDECL Lacons(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lbpsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorset3(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorsetn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lfuncalln(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lhelp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llist(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist2star(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogand(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogeqv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogxor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmax(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmin(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmkhash(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lput_hash(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputprop(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lresource_limitn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsubst(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lvalues(Lisp_Object env, int nargs, ...);
#ifdef COMMON
extern Lisp_Object MS_CDECL Lappend_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Laref(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Laset(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Leqn_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgcd_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgeq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lget_3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgreaterp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llcm_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lleq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llessp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lquotient_n(Lisp_Object nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
#ifdef __cplusplus
}
#endif
#endif 


/* Code for rread1 */

static Lisp_Object MS_CDECL CC_rread1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0030, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rread1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rread1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* end of prologue */
    fn = elt(env, 15); /* ptoken */
    v0029 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    stack[-1] = v0029;
    v0030 = qvalue(elt(env, 1)); /* ttype!* */
    v0029 = (Lisp_Object)49; /* 3 */
    if (v0030 == v0029) goto v0033;
    v0029 = stack[-1];
    if (symbolp(v0029)) goto v0034;
    v0030 = stack[-1];
    v0029 = elt(env, 4); /* !:dn!: */
    if (!consp(v0030)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0030 = qcar(v0030);
    if (!(v0030 == v0029)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0031 = stack[-1];
    v0030 = qvalue(elt(env, 5)); /* nil */
    v0029 = elt(env, 6); /* symbolic */
    {
        popv(3);
        fn = elt(env, 16); /* dnform */
        return (*qfnn(fn))(qenv(fn), 3, v0031, v0030, v0029);
    }

v0034:
    v0029 = qvalue(elt(env, 2)); /* !*quotenewnam */
    if (v0029 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0030 = stack[-1];
    v0029 = elt(env, 3); /* quotenewnam */
    v0029 = get(v0030, v0029);
    stack[0] = v0029;
    if (v0029 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0033:
    v0030 = stack[-1];
    v0029 = elt(env, 7); /* !( */
    if (v0030 == v0029) goto v0035;
    v0030 = stack[-1];
    v0029 = elt(env, 8); /* !+ */
    if (v0030 == v0029) goto v0036;
    v0030 = stack[-1];
    v0029 = elt(env, 10); /* !- */
    v0029 = (v0030 == v0029 ? lisp_true : nil);
    goto v0037;

v0037:
    if (v0029 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    fn = elt(env, 15); /* ptoken */
    v0029 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    stack[0] = v0029;
    v0030 = stack[0];
    v0029 = elt(env, 4); /* !:dn!: */
    if (!consp(v0030)) goto v0038;
    v0030 = qcar(v0030);
    if (!(v0030 == v0029)) goto v0038;
    v0031 = stack[0];
    v0030 = qvalue(elt(env, 5)); /* nil */
    v0029 = elt(env, 6); /* symbolic */
    fn = elt(env, 16); /* dnform */
    v0029 = (*qfnn(fn))(qenv(fn), 3, v0031, v0030, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-2];
    stack[0] = v0029;
    goto v0038;

v0038:
    v0029 = stack[0];
    if (is_number(v0029)) goto v0039;
    v0029 = elt(env, 11); /* " " */
    qvalue(elt(env, 12)) = v0029; /* nxtsym!* */
    v0030 = elt(env, 13); /* "Syntax error: improper number" */
    v0029 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 17); /* symerr */
    v0029 = (*qfn2(fn))(qenv(fn), v0030, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0039:
    v0030 = stack[-1];
    v0029 = elt(env, 10); /* !- */
    if (!(v0030 == v0029)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0030 = elt(env, 14); /* minus */
    v0029 = stack[0];
    v0029 = Lapply1(nil, v0030, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    stack[0] = v0029;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v0036:
    v0029 = qvalue(elt(env, 9)); /* t */
    goto v0037;

v0035:
    {
        popv(3);
        fn = elt(env, 18); /* rrdls */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v0032:
    popv(3);
    return nil;
}



/* Code for rnprep!: */

static Lisp_Object CC_rnprepT(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0047, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnprep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0040;
/* end of prologue */
    v0046 = stack[-1];
    v0046 = qcdr(v0046);
    v0046 = qcar(v0046);
    fn = elt(env, 2); /* prepf */
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-3];
    v0048 = v0046;
    v0046 = stack[-1];
    v0046 = qcdr(v0046);
    v0047 = qcdr(v0046);
    v0046 = (Lisp_Object)17; /* 1 */
    if (v0047 == v0046) { popv(4); return onevalue(v0048); }
    stack[-2] = elt(env, 1); /* quotient */
    stack[0] = v0048;
    v0046 = stack[-1];
    v0046 = qcdr(v0046);
    v0046 = qcdr(v0046);
    fn = elt(env, 2); /* prepf */
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    {
        Lisp_Object v0050 = stack[-2];
        Lisp_Object v0051 = stack[0];
        popv(4);
        return list3(v0050, v0051, v0046);
    }
/* error exit handlers */
v0049:
    popv(4);
    return nil;
}



/* Code for prepsq!* */

static Lisp_Object CC_prepsqH(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0094, v0095, v0096;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepsq*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0040;
/* end of prologue */
    stack[-8] = qvalue(elt(env, 1)); /* !*combinelogs */
    qvalue(elt(env, 1)) = nil; /* !*combinelogs */
    v0094 = stack[-9];
    v0094 = qcar(v0094);
    if (v0094 == nil) goto v0097;
    v0094 = qvalue(elt(env, 2)); /* ordl!* */
    fn = elt(env, 15); /* setkorder */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    stack[-10] = v0094;
    v0094 = qvalue(elt(env, 3)); /* factors!* */
    stack[-7] = v0094;
    goto v0099;

v0099:
    v0094 = stack[-7];
    if (v0094 == nil) goto v0048;
    v0094 = stack[-7];
    v0094 = qcar(v0094);
    v0095 = v0094;
    v0094 = v0095;
    if (symbolp(v0094)) goto v0100;
    v0094 = qvalue(elt(env, 4)); /* nil */
    goto v0101;

v0101:
    stack[-6] = v0094;
    v0094 = stack[-6];
    fn = elt(env, 16); /* lastpair */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    stack[-5] = v0094;
    v0094 = stack[-7];
    v0094 = qcdr(v0094);
    stack[-7] = v0094;
    v0094 = stack[-5];
    if (!consp(v0094)) goto v0099;
    else goto v0025;

v0025:
    v0094 = stack[-7];
    if (v0094 == nil) goto v0102;
    stack[-4] = stack[-5];
    v0094 = stack[-7];
    v0094 = qcar(v0094);
    v0095 = v0094;
    if (symbolp(v0095)) goto v0103;
    v0094 = qvalue(elt(env, 4)); /* nil */
    goto v0007;

v0007:
    v0094 = Lrplacd(nil, stack[-4], v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    v0094 = stack[-5];
    fn = elt(env, 16); /* lastpair */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    stack[-5] = v0094;
    v0094 = stack[-7];
    v0094 = qcdr(v0094);
    stack[-7] = v0094;
    goto v0025;

v0103:
    v0096 = v0094;
    v0095 = elt(env, 5); /* prepsq!*fn */
    v0095 = get(v0096, v0095);
    env = stack[-11];
    v0096 = v0095;
    if (v0095 == nil) goto v0104;
    v0095 = stack[-9];
    v0094 = Lapply2(nil, 3, v0096, v0095, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    goto v0007;

v0104:
    if (!symbolp(v0094)) v0094 = nil;
    else { v0094 = qfastgets(v0094);
           if (v0094 != nil) { v0094 = elt(v0094, 24); /* klist */
#ifdef RECORD_GET
             if (v0094 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v0094 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v0094 == SPID_NOPROP) v0094 = nil; }}
#endif
    stack[-3] = v0094;
    v0094 = stack[-3];
    if (v0094 == nil) goto v0105;
    v0094 = stack[-3];
    v0094 = qcar(v0094);
    v0094 = qcar(v0094);
    v0094 = ncons(v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    stack[-1] = v0094;
    stack[-2] = v0094;
    goto v0106;

v0106:
    v0094 = stack[-3];
    v0094 = qcdr(v0094);
    stack[-3] = v0094;
    v0094 = stack[-3];
    if (v0094 == nil) goto v0107;
    stack[0] = stack[-1];
    v0094 = stack[-3];
    v0094 = qcar(v0094);
    v0094 = qcar(v0094);
    v0094 = ncons(v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    v0094 = Lrplacd(nil, stack[0], v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    v0094 = stack[-1];
    v0094 = qcdr(v0094);
    stack[-1] = v0094;
    goto v0106;

v0107:
    v0094 = stack[-2];
    goto v0007;

v0105:
    v0094 = qvalue(elt(env, 4)); /* nil */
    goto v0007;

v0102:
    v0094 = stack[-6];
    v0095 = v0094;
    goto v0108;

v0108:
    v0094 = elt(env, 6); /* ordop */
    fn = elt(env, 17); /* sort */
    stack[0] = (*qfn2(fn))(qenv(fn), v0095, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    v0095 = qvalue(elt(env, 3)); /* factors!* */
    v0094 = elt(env, 6); /* ordop */
    fn = elt(env, 17); /* sort */
    v0095 = (*qfn2(fn))(qenv(fn), v0095, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    v0094 = qvalue(elt(env, 2)); /* ordl!* */
    v0094 = Lappend(nil, v0095, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    v0094 = Lappend(nil, stack[0], v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    fn = elt(env, 15); /* setkorder */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    v0095 = qvalue(elt(env, 7)); /* kord!* */
    v0094 = stack[-10];
    if (equal(v0095, v0094)) goto v0109;
    v0094 = qvalue(elt(env, 8)); /* t */
    goto v0110;

v0110:
    if (v0094 == nil) goto v0111;
    v0094 = stack[-9];
    v0094 = qcar(v0094);
    fn = elt(env, 18); /* formop */
    stack[0] = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    v0094 = stack[-9];
    v0094 = qcdr(v0094);
    fn = elt(env, 18); /* formop */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    v0094 = cons(stack[0], v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    stack[-9] = v0094;
    goto v0111;

v0111:
    v0094 = qvalue(elt(env, 10)); /* !*rat */
    if (!(v0094 == nil)) goto v0112;
    v0094 = qvalue(elt(env, 11)); /* !*div */
    if (!(v0094 == nil)) goto v0112;
    v0094 = qvalue(elt(env, 12)); /* upl!* */
    if (!(v0094 == nil)) goto v0112;
    v0094 = qvalue(elt(env, 13)); /* dnl!* */
    if (!(v0094 == nil)) goto v0112;
    v0095 = stack[-9];
    v0094 = elt(env, 14); /* prepsq!*2 */
    fn = elt(env, 19); /* sqform */
    v0094 = (*qfn2(fn))(qenv(fn), v0095, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    goto v0113;

v0113:
    stack[-9] = v0094;
    v0094 = stack[-10];
    fn = elt(env, 15); /* setkorder */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    v0094 = stack[-9];
    goto v0044;

v0044:
    qvalue(elt(env, 1)) = stack[-8]; /* !*combinelogs */
    { popv(12); return onevalue(v0094); }

v0112:
    v0094 = stack[-9];
    v0096 = qcar(v0094);
    v0094 = stack[-9];
    v0095 = qcdr(v0094);
    v0094 = qvalue(elt(env, 4)); /* nil */
    fn = elt(env, 20); /* prepsq!*1 */
    v0094 = (*qfnn(fn))(qenv(fn), 3, v0096, v0095, v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    fn = elt(env, 21); /* replus */
    v0094 = (*qfn1(fn))(qenv(fn), v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    goto v0113;

v0109:
    v0094 = qvalue(elt(env, 9)); /* wtl!* */
    goto v0110;

v0100:
    v0096 = v0095;
    v0094 = elt(env, 5); /* prepsq!*fn */
    v0094 = get(v0096, v0094);
    env = stack[-11];
    v0096 = v0094;
    if (v0094 == nil) goto v0018;
    v0094 = stack[-9];
    v0094 = Lapply2(nil, 3, v0096, v0094, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    goto v0101;

v0018:
    v0094 = v0095;
    if (!symbolp(v0094)) v0094 = nil;
    else { v0094 = qfastgets(v0094);
           if (v0094 != nil) { v0094 = elt(v0094, 24); /* klist */
#ifdef RECORD_GET
             if (v0094 != SPID_NOPROP)
                record_get(elt(fastget_names, 24), 1);
             else record_get(elt(fastget_names, 24), 0),
                v0094 = nil; }
           else record_get(elt(fastget_names, 24), 0); }
#else
             if (v0094 == SPID_NOPROP) v0094 = nil; }}
#endif
    stack[-3] = v0094;
    v0094 = stack[-3];
    if (v0094 == nil) goto v0114;
    v0094 = stack[-3];
    v0094 = qcar(v0094);
    v0094 = qcar(v0094);
    v0094 = ncons(v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    stack[-1] = v0094;
    stack[-2] = v0094;
    goto v0115;

v0115:
    v0094 = stack[-3];
    v0094 = qcdr(v0094);
    stack[-3] = v0094;
    v0094 = stack[-3];
    if (v0094 == nil) goto v0116;
    stack[0] = stack[-1];
    v0094 = stack[-3];
    v0094 = qcar(v0094);
    v0094 = qcar(v0094);
    v0094 = ncons(v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    v0094 = Lrplacd(nil, stack[0], v0094);
    nil = C_nil;
    if (exception_pending()) goto v0098;
    env = stack[-11];
    v0094 = stack[-1];
    v0094 = qcdr(v0094);
    stack[-1] = v0094;
    goto v0115;

v0116:
    v0094 = stack[-2];
    goto v0101;

v0114:
    v0094 = qvalue(elt(env, 4)); /* nil */
    goto v0101;

v0048:
    v0094 = qvalue(elt(env, 4)); /* nil */
    v0095 = v0094;
    goto v0108;

v0097:
    v0094 = (Lisp_Object)1; /* 0 */
    goto v0044;
/* error exit handlers */
v0098:
    env = stack[-11];
    qvalue(elt(env, 1)) = stack[-8]; /* !*combinelogs */
    popv(12);
    return nil;
}



/* Code for sfto_ucontentf */

static Lisp_Object CC_sfto_ucontentf(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfto_ucontentf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0042 = v0040;
/* end of prologue */
    v0041 = v0042;
    if (!consp(v0041)) goto v0117;
    v0041 = v0042;
    v0041 = qcar(v0041);
    v0041 = (consp(v0041) ? nil : lisp_true);
    goto v0118;

v0118:
    if (!(v0041 == nil)) return onevalue(v0042);
    v0041 = v0042;
    v0042 = qcar(v0042);
    v0042 = qcar(v0042);
    v0042 = qcar(v0042);
    {
        fn = elt(env, 2); /* sfto_ucontentf1 */
        return (*qfn2(fn))(qenv(fn), v0041, v0042);
    }

v0117:
    v0041 = qvalue(elt(env, 1)); /* t */
    goto v0118;
}



/* Code for cl_fvarl */

static Lisp_Object CC_cl_fvarl(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_fvarl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0120 = v0040;
/* end of prologue */
    fn = elt(env, 2); /* cl_fvarl1 */
    v0121 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0122;
    env = stack[0];
    v0120 = elt(env, 1); /* ordp */
    {
        popv(1);
        fn = elt(env, 3); /* sort */
        return (*qfn2(fn))(qenv(fn), v0121, v0120);
    }
/* error exit handlers */
v0122:
    popv(1);
    return nil;
}



/* Code for ibalp_tvb */

static Lisp_Object CC_ibalp_tvb(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0125;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_tvb");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0005;
    v0124 = v0040;
/* end of prologue */
    stack[-2] = v0124;
    goto v0044;

v0044:
    v0124 = stack[-2];
    if (v0124 == nil) goto v0119;
    v0124 = stack[-2];
    v0124 = qcar(v0124);
    stack[0] = v0124;
    v0124 = stack[0];
    v0124 = qcdr(v0124);
    v0124 = qcdr(v0124);
    v0124 = qcdr(v0124);
    v0124 = qcdr(v0124);
    v0124 = qcdr(v0124);
    v0124 = qcdr(v0124);
    v0124 = qcdr(v0124);
    v0125 = qcar(v0124);
    v0124 = stack[-1];
    v0124 = (Lisp_Object)geq2(v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    v0124 = v0124 ? lisp_true : nil;
    env = stack[-3];
    if (v0124 == nil) goto v0045;
    v0124 = stack[0];
    v0125 = qcdr(v0124);
    v0124 = stack[0];
    v0124 = qcdr(v0124);
    v0124 = qcdr(v0124);
    v0124 = qcar(v0124);
    fn = elt(env, 2); /* ibalp_var!-unset */
    v0124 = (*qfn2(fn))(qenv(fn), v0125, v0124);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-3];
    goto v0045;

v0045:
    v0124 = stack[-2];
    v0124 = qcdr(v0124);
    stack[-2] = v0124;
    goto v0044;

v0119:
    v0124 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0124); }
/* error exit handlers */
v0126:
    popv(4);
    return nil;
}



/* Code for ratpoly_tad */

static Lisp_Object CC_ratpoly_tad(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0121;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratpoly_tad");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0120 = v0040;
/* end of prologue */
    v0121 = qcar(v0120);
    v0120 = (Lisp_Object)17; /* 1 */
    return cons(v0121, v0120);
}



/* Code for ofsf_clnegrel */

static Lisp_Object CC_ofsf_clnegrel(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_clnegrel");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0122 = v0005;
    v0127 = v0040;
/* end of prologue */
    if (!(v0122 == nil)) return onevalue(v0127);
    v0122 = v0127;
    {
        fn = elt(env, 1); /* ofsf_lnegrel */
        return (*qfn1(fn))(qenv(fn), v0122);
    }
}



/* Code for applyrd */

static Lisp_Object MS_CDECL CC_applyrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "applyrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for applyrd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    fn = elt(env, 7); /* lex */
    v0033 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    v0131 = qvalue(elt(env, 1)); /* atts */
    v0033 = elt(env, 2); /* (type definitionurl encoding) */
    fn = elt(env, 8); /* retattributes */
    v0033 = (*qfn2(fn))(qenv(fn), v0131, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    qvalue(elt(env, 3)) = v0033; /* mmlatts */
    v0033 = qvalue(elt(env, 4)); /* char */
    fn = elt(env, 9); /* compress!* */
    v0131 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    v0033 = qvalue(elt(env, 5)); /* functions!* */
    v0033 = Lassoc(nil, v0131, v0033);
    stack[0] = v0033;
    if (v0033 == nil) goto v0020;
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    v0131 = qcar(v0033);
    v0033 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 10); /* apply */
    v0033 = (*qfn2(fn))(qenv(fn), v0131, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    v0131 = v0033;
    v0033 = qvalue(elt(env, 3)); /* mmlatts */
    v0033 = cons(v0033, v0131);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    v0131 = v0033;
    v0033 = qvalue(elt(env, 6)); /* nil */
    qvalue(elt(env, 3)) = v0033; /* mmlatts */
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    v0033 = qcdr(v0033);
    v0033 = qcar(v0033);
    popv(2);
    return cons(v0033, v0131);

v0020:
    v0033 = qvalue(elt(env, 4)); /* char */
    v0131 = Lcompress(nil, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    env = stack[-1];
    v0033 = (Lisp_Object)273; /* 17 */
    fn = elt(env, 11); /* errorml */
    v0033 = (*qfn2(fn))(qenv(fn), v0131, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0093;
    v0033 = nil;
    { popv(2); return onevalue(v0033); }
/* error exit handlers */
v0093:
    popv(2);
    return nil;
}



/* Code for rd!:zerop!: */

static Lisp_Object CC_rdTzeropT(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rd:zerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0132 = v0040;
/* end of prologue */
    v0027 = v0132;
    v0027 = qcdr(v0027);
    if (!consp(v0027)) goto v0053;
    v0027 = v0132;
    fn = elt(env, 1); /* round!* */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* bfzerop!: */
        return (*qfn1(fn))(qenv(fn), v0027);
    }

v0053:
    v0027 = v0132;
    v0027 = qcdr(v0027);
    {
        popv(1);
        fn = elt(env, 3); /* ft!:zerop */
        return (*qfn1(fn))(qenv(fn), v0027);
    }
/* error exit handlers */
v0045:
    popv(1);
    return nil;
}



/* Code for freeoff */

static Lisp_Object CC_freeoff(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0138, v0139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeoff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
    stack[-1] = v0040;
/* end of prologue */

v0052:
    v0138 = stack[-1];
    if (!consp(v0138)) goto v0121;
    v0138 = stack[-1];
    v0138 = qcar(v0138);
    v0138 = (consp(v0138) ? nil : lisp_true);
    goto v0120;

v0120:
    if (v0138 == nil) goto v0097;
    v0138 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0138); }

v0097:
    v0138 = stack[-1];
    v0138 = qcar(v0138);
    v0138 = qcar(v0138);
    v0138 = qcar(v0138);
    fn = elt(env, 3); /* sfp */
    v0138 = (*qfn1(fn))(qenv(fn), v0138);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    if (v0138 == nil) goto v0018;
    v0138 = stack[-1];
    v0138 = qcar(v0138);
    v0138 = qcar(v0138);
    v0139 = qcar(v0138);
    v0138 = stack[0];
    v0138 = CC_freeoff(env, v0139, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    if (v0138 == nil) goto v0140;
    v0138 = stack[-1];
    v0138 = qcar(v0138);
    v0139 = qcdr(v0138);
    v0138 = stack[0];
    v0138 = CC_freeoff(env, v0139, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    if (v0138 == nil) goto v0021;
    v0138 = stack[-1];
    v0138 = qcdr(v0138);
    stack[-1] = v0138;
    goto v0052;

v0021:
    v0138 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0138); }

v0140:
    v0138 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0138); }

v0018:
    v0138 = stack[-1];
    v0138 = qcar(v0138);
    v0138 = qcar(v0138);
    v0139 = qcar(v0138);
    v0138 = stack[0];
    fn = elt(env, 4); /* ndepends */
    v0138 = (*qfn2(fn))(qenv(fn), v0139, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    if (v0138 == nil) goto v0141;
    v0138 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0138); }

v0141:
    v0138 = stack[-1];
    v0138 = qcar(v0138);
    v0139 = qcdr(v0138);
    v0138 = stack[0];
    v0138 = CC_freeoff(env, v0139, v0138);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-2];
    if (v0138 == nil) goto v0116;
    v0138 = stack[-1];
    v0138 = qcdr(v0138);
    stack[-1] = v0138;
    goto v0052;

v0116:
    v0138 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0138); }

v0121:
    v0138 = qvalue(elt(env, 1)); /* t */
    goto v0120;
/* error exit handlers */
v0088:
    popv(3);
    return nil;
}



/* Code for wedgek2 */

static Lisp_Object MS_CDECL CC_wedgek2(Lisp_Object env, int nargs,
                         Lisp_Object v0040, Lisp_Object v0005,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0165, v0069, v0070;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "wedgek2");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedgek2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0002,v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0040,v0005,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = v0002;
    stack[-3] = v0005;
    stack[-4] = v0040;
/* end of prologue */

v0028:
    v0069 = stack[-4];
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    if (v0069 == v0165) goto v0166;
    v0165 = qvalue(elt(env, 2)); /* nil */
    goto v0121;

v0121:
    if (v0165 == nil) goto v0091;
    v0165 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    v0069 = v0165;
    v0165 = v0069;
    v0165 = integerp(v0165);
    if (v0165 == nil) goto v0050;
    v0165 = v0069;
    v0165 = Loddp(nil, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    goto v0049;

v0049:
    if (v0165 == nil) goto v0128;
    v0165 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0165); }

v0128:
    v0069 = stack[-4];
    v0165 = stack[-3];
    v0165 = cons(v0069, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    v0165 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    {
        Lisp_Object v0167 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0167, v0165);
    }

v0050:
    v0165 = qvalue(elt(env, 2)); /* nil */
    goto v0049;

v0091:
    v0165 = stack[-3];
    v0069 = qcar(v0165);
    v0165 = elt(env, 1); /* wedge */
    if (!consp(v0069)) goto v0168;
    v0069 = qcar(v0069);
    if (!(v0069 == v0165)) goto v0168;
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    v0165 = qcdr(v0165);
    stack[-3] = v0165;
    goto v0028;

v0168:
    v0069 = stack[-4];
    v0165 = elt(env, 1); /* wedge */
    if (!consp(v0069)) goto v0169;
    v0069 = qcar(v0069);
    if (!(v0069 == v0165)) goto v0169;
    v0165 = stack[-4];
    v0069 = qcdr(v0165);
    v0165 = stack[-3];
    fn = elt(env, 7); /* wedgewedge */
    stack[0] = (*qfn2(fn))(qenv(fn), v0069, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    v0165 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    {
        Lisp_Object v0170 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0170, v0165);
    }

v0169:
    v0069 = stack[-4];
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    fn = elt(env, 8); /* worderp */
    v0165 = (*qfn2(fn))(qenv(fn), v0069, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    if (v0165 == nil) goto v0171;
    v0069 = stack[-4];
    v0165 = stack[-3];
    v0165 = cons(v0069, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    v0165 = stack[-2];
    fn = elt(env, 5); /* mksgnsq */
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    {
        Lisp_Object v0172 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0172, v0165);
    }

v0171:
    v0165 = stack[-3];
    v0165 = qcdr(v0165);
    if (v0165 == nil) goto v0173;
    v0165 = stack[-3];
    v0070 = qcar(v0165);
    v0069 = (Lisp_Object)17; /* 1 */
    v0165 = (Lisp_Object)17; /* 1 */
    v0165 = list2star(v0070, v0069, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    stack[-5] = ncons(v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    stack[-1] = stack[-4];
    v0165 = stack[-3];
    stack[0] = qcdr(v0165);
    v0165 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    stack[-4] = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    fn = elt(env, 3); /* deg!*form */
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    fn = elt(env, 9); /* multf */
    v0165 = (*qfn2(fn))(qenv(fn), stack[-4], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    fn = elt(env, 10); /* addf */
    v0165 = (*qfn2(fn))(qenv(fn), stack[-2], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    v0165 = CC_wedgek2(env, 3, stack[-1], stack[0], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    {
        Lisp_Object v0174 = stack[-5];
        popv(7);
        fn = elt(env, 11); /* wedgepf2 */
        return (*qfn2(fn))(qenv(fn), v0174, v0165);
    }

v0173:
    v0165 = stack[-3];
    v0069 = qcar(v0165);
    v0165 = stack[-4];
    v0165 = list2(v0069, v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    fn = elt(env, 4); /* wedgef */
    stack[0] = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    stack[-1] = stack[-2];
    v0165 = stack[-4];
    fn = elt(env, 3); /* deg!*form */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    v0165 = stack[-3];
    v0165 = qcar(v0165);
    fn = elt(env, 3); /* deg!*form */
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    fn = elt(env, 9); /* multf */
    v0165 = (*qfn2(fn))(qenv(fn), stack[-2], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    fn = elt(env, 10); /* addf */
    v0165 = (*qfn2(fn))(qenv(fn), stack[-1], v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    fn = elt(env, 5); /* mksgnsq */
    v0165 = (*qfn1(fn))(qenv(fn), v0165);
    nil = C_nil;
    if (exception_pending()) goto v0110;
    env = stack[-6];
    {
        Lisp_Object v0175 = stack[0];
        popv(7);
        fn = elt(env, 6); /* multpfsq */
        return (*qfn2(fn))(qenv(fn), v0175, v0165);
    }

v0166:
    v0069 = stack[-4];
    v0165 = elt(env, 1); /* wedge */
    v0165 = Leqcar(nil, v0069, v0165);
    env = stack[-6];
    v0165 = (v0165 == nil ? lisp_true : nil);
    goto v0121;
/* error exit handlers */
v0110:
    popv(7);
    return nil;
}



/* Code for indordp */

static Lisp_Object CC_indordp(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0021, v0022, v0160, v0140, v0128;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for indordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0140 = v0005;
    v0128 = v0040;
/* end of prologue */
    v0021 = qvalue(elt(env, 1)); /* indxl!* */
    v0160 = v0021;
    v0022 = v0128;
    v0021 = v0160;
    v0021 = Lmemq(nil, v0022, v0021);
    if (!(v0021 == nil)) goto v0044;
    v0021 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0021);

v0044:
    v0021 = v0160;
    if (v0021 == nil) goto v0177;
    v0022 = v0128;
    v0021 = v0160;
    v0021 = qcar(v0021);
    if (v0022 == v0021) goto v0026;
    v0022 = v0140;
    v0021 = v0160;
    v0021 = qcar(v0021);
    if (v0022 == v0021) goto v0101;
    v0021 = v0160;
    v0021 = qcdr(v0021);
    v0160 = v0021;
    goto v0044;

v0101:
    v0021 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0021);

v0026:
    v0021 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0021);

v0177:
    v0021 = v0128;
    v0022 = v0140;
        return Lorderp(nil, v0021, v0022);
}



/* Code for sfpx1 */

static Lisp_Object MS_CDECL CC_sfpx1(Lisp_Object env, int nargs,
                         Lisp_Object v0040, Lisp_Object v0005,
                         Lisp_Object v0002, Lisp_Object v0084,
                         Lisp_Object v0053, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0110, v0167, v0170, v0172, v0174;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "sfpx1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sfpx1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v0053,v0084,v0002,v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0040,v0005,v0002,v0084,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0053;
    stack[-4] = v0084;
    stack[-5] = v0002;
    stack[-6] = v0005;
    v0172 = v0040;
/* end of prologue */

v0197:
    v0110 = v0172;
    if (!consp(v0110)) goto v0198;
    v0110 = v0172;
    v0110 = qcar(v0110);
    v0110 = (consp(v0110) ? nil : lisp_true);
    goto v0163;

v0163:
    if (v0110 == nil) goto v0027;
    v0110 = qvalue(elt(env, 1)); /* t */
    { popv(9); return onevalue(v0110); }

v0027:
    v0110 = v0172;
    v0110 = Lconsp(nil, v0110);
    env = stack[-8];
    if (v0110 == nil) goto v0043;
    v0110 = v0172;
    v0110 = qcar(v0110);
    v0167 = v0172;
    v0167 = qcdr(v0167);
    stack[-2] = v0167;
    v0167 = v0110;
    v0167 = Lconsp(nil, v0167);
    env = stack[-8];
    if (v0167 == nil) goto v0050;
    v0167 = v0110;
    v0167 = qcdr(v0167);
    stack[-7] = v0167;
    v0110 = qcar(v0110);
    stack[0] = v0110;
    v0110 = stack[0];
    v0110 = Lconsp(nil, v0110);
    env = stack[-8];
    if (v0110 == nil) goto v0100;
    v0110 = stack[0];
    v0110 = qcar(v0110);
    stack[-1] = v0110;
    v0110 = stack[-1];
    fn = elt(env, 3); /* assert_kernelp */
    v0110 = (*qfn1(fn))(qenv(fn), v0110);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-8];
    if (v0110 == nil) goto v0128;
    v0110 = stack[0];
    v0110 = qcdr(v0110);
    stack[0] = v0110;
    v0167 = stack[-1];
    v0110 = stack[-5];
    if (v0167 == v0110) goto v0016;
    v0110 = stack[-5];
    if (v0110 == nil) goto v0003;
    v0167 = stack[-5];
    v0110 = stack[-6];
    v0110 = cons(v0167, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-8];
    stack[-6] = v0110;
    goto v0003;

v0003:
    v0110 = stack[-3];
    if (v0110 == nil) goto v0200;
    v0110 = stack[-6];
    if (v0110 == nil) goto v0200;
    v0167 = stack[-1];
    v0110 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* to */
    stack[-4] = (*qfn2(fn))(qenv(fn), v0167, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-8];
    v0110 = stack[-6];
    v0167 = qcar(v0110);
    v0110 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 4); /* to */
    v0110 = (*qfn2(fn))(qenv(fn), v0167, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-8];
    fn = elt(env, 5); /* ordpp */
    v0110 = (*qfn2(fn))(qenv(fn), stack[-4], v0110);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-8];
    if (v0110 == nil) goto v0200;
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0110); }

v0200:
    stack[-4] = stack[-7];
    v0167 = stack[-1];
    v0110 = stack[-6];
    v0172 = cons(v0167, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-8];
    v0170 = qvalue(elt(env, 2)); /* nil */
    v0167 = (Lisp_Object)1; /* 0 */
    v0110 = stack[-3];
    v0110 = CC_sfpx1(env, 5, stack[-4], v0172, v0170, v0167, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-8];
    if (v0110 == nil) goto v0201;
    v0172 = stack[-2];
    v0174 = stack[-6];
    v0170 = stack[-1];
    v0167 = stack[0];
    v0110 = stack[-3];
    stack[-6] = v0174;
    stack[-5] = v0170;
    stack[-4] = v0167;
    stack[-3] = v0110;
    goto v0197;

v0201:
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0110); }

v0016:
    v0167 = stack[0];
    v0110 = stack[-4];
    v0110 = (Lisp_Object)lessp2(v0167, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    v0110 = v0110 ? lisp_true : nil;
    env = stack[-8];
    if (v0110 == nil) goto v0202;
    stack[-1] = stack[-7];
    v0167 = stack[-5];
    v0110 = stack[-6];
    v0172 = cons(v0167, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-8];
    v0170 = qvalue(elt(env, 2)); /* nil */
    v0167 = (Lisp_Object)1; /* 0 */
    v0110 = stack[-3];
    v0110 = CC_sfpx1(env, 5, stack[-1], v0172, v0170, v0167, v0110);
    nil = C_nil;
    if (exception_pending()) goto v0199;
    env = stack[-8];
    if (v0110 == nil) goto v0116;
    v0172 = stack[-2];
    v0174 = stack[-6];
    v0170 = stack[-5];
    v0167 = stack[0];
    v0110 = stack[-3];
    stack[-6] = v0174;
    stack[-5] = v0170;
    stack[-4] = v0167;
    stack[-3] = v0110;
    goto v0197;

v0116:
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0110); }

v0202:
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0110); }

v0128:
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0110); }

v0100:
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0110); }

v0050:
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0110); }

v0043:
    v0110 = qvalue(elt(env, 2)); /* nil */
    { popv(9); return onevalue(v0110); }

v0198:
    v0110 = qvalue(elt(env, 1)); /* t */
    goto v0163;
/* error exit handlers */
v0199:
    popv(9);
    return nil;
}



/* Code for fs!:times */

static Lisp_Object CC_fsTtimes(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0123, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fs:times");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
    stack[-1] = v0040;
/* end of prologue */
    v0123 = stack[-1];
    if (v0123 == nil) goto v0052;
    v0123 = stack[0];
    if (v0123 == nil) goto v0097;
    v0024 = stack[-1];
    v0123 = stack[0];
    fn = elt(env, 2); /* fs!:timesterm */
    v0123 = (*qfn2(fn))(qenv(fn), v0024, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    stack[-2] = v0123;
    v0024 = stack[-1];
    v0123 = (Lisp_Object)49; /* 3 */
    v0024 = *(Lisp_Object *)((char *)v0024 + (CELL-TAG_VECTOR) + ((int32_t)v0123/(16/CELL)));
    v0123 = stack[0];
    v0123 = CC_fsTtimes(env, v0024, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0203;
    env = stack[-3];
    {
        Lisp_Object v0176 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* fs!:plus */
        return (*qfn2(fn))(qenv(fn), v0176, v0123);
    }

v0097:
    v0123 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0123); }

v0052:
    v0123 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0123); }
/* error exit handlers */
v0203:
    popv(4);
    return nil;
}



/* Code for evaluatecoeffts */

static Lisp_Object CC_evaluatecoeffts(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0008, v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evaluatecoeffts");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
    stack[-1] = v0040;
/* end of prologue */
    v0010 = stack[-1];
    if (v0010 == nil) goto v0097;
    v0010 = stack[-1];
    if (!consp(v0010)) goto v0132;
    v0010 = stack[-1];
    v0010 = qcar(v0010);
    v0010 = (consp(v0010) ? nil : lisp_true);
    goto v0117;

v0117:
    if (v0010 == nil) goto v0023;
    v0008 = stack[-1];
    v0010 = (Lisp_Object)1; /* 0 */
    if (!(v0008 == v0010)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0010 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0010); }

v0023:
    v0010 = stack[-1];
    v0010 = qcar(v0010);
    v0010 = qcar(v0010);
    v0008 = qcar(v0010);
    v0010 = qvalue(elt(env, 3)); /* indexlist */
    v0010 = Lmember(nil, v0008, v0010);
    if (v0010 == nil) goto v0036;
    v0010 = stack[-1];
    v0010 = qcar(v0010);
    v0010 = qcar(v0010);
    v0009 = qcar(v0010);
    v0008 = stack[0];
    v0010 = qvalue(elt(env, 3)); /* indexlist */
    fn = elt(env, 4); /* valuecoefft */
    v0010 = (*qfnn(fn))(qenv(fn), 3, v0009, v0008, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    goto v0210;

v0210:
    stack[-2] = v0010;
    v0010 = stack[-1];
    v0010 = qcar(v0010);
    v0008 = qcdr(v0010);
    v0010 = stack[0];
    v0010 = CC_evaluatecoeffts(env, v0008, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    fn = elt(env, 5); /* !*multf */
    v0010 = (*qfn2(fn))(qenv(fn), stack[-2], v0010);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    stack[-2] = v0010;
    v0010 = stack[-1];
    v0008 = qcdr(v0010);
    v0010 = stack[0];
    v0010 = CC_evaluatecoeffts(env, v0008, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    {
        Lisp_Object v0211 = stack[-2];
        popv(4);
        fn = elt(env, 6); /* addf */
        return (*qfn2(fn))(qenv(fn), v0211, v0010);
    }

v0036:
    v0010 = stack[-1];
    v0010 = qcar(v0010);
    v0008 = qcar(v0010);
    v0010 = (Lisp_Object)17; /* 1 */
    v0010 = cons(v0008, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    v0010 = ncons(v0010);
    nil = C_nil;
    if (exception_pending()) goto v0209;
    env = stack[-3];
    goto v0210;

v0132:
    v0010 = qvalue(elt(env, 1)); /* t */
    goto v0117;

v0097:
    v0010 = qvalue(elt(env, 1)); /* t */
    goto v0117;
/* error exit handlers */
v0209:
    popv(4);
    return nil;
}



/* Code for qqe_arg!-check */

static Lisp_Object CC_qqe_argKcheck(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0210;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_arg-check");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0040;
/* end of prologue */
    v0141 = stack[0];
    v0141 = qcar(v0141);
    stack[-1] = v0141;
    v0141 = stack[-1];
    fn = elt(env, 4); /* qqe_rqopp */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    if (v0141 == nil) goto v0117;
    v0141 = stack[0];
    fn = elt(env, 5); /* qqe_arg!-check!-lq!-rq */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    goto v0044;

v0044:
    v0141 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0141); }

v0117:
    v0141 = stack[-1];
    fn = elt(env, 6); /* qqe_rbopp */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    if (v0141 == nil) goto v0127;
    v0141 = stack[0];
    fn = elt(env, 7); /* qqe_arg!-check!-lb!-rb */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    goto v0044;

v0127:
    v0141 = stack[-1];
    fn = elt(env, 8); /* qqe_qopheadp */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    if (!(v0141 == nil)) goto v0034;
    v0141 = stack[-1];
    fn = elt(env, 9); /* qqe_qoptailp */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    if (!(v0141 == nil)) goto v0034;
    v0141 = stack[-1];
    fn = elt(env, 10); /* qqe_qopaddp */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    if (v0141 == nil) goto v0125;
    v0141 = stack[0];
    fn = elt(env, 11); /* qqe_arg!-check!-lb!-rq */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    goto v0044;

v0125:
    v0141 = stack[0];
    v0141 = qcdr(v0141);
    stack[-1] = v0141;
    goto v0136;

v0136:
    v0141 = stack[-1];
    if (v0141 == nil) goto v0044;
    v0141 = stack[-1];
    v0141 = qcar(v0141);
    fn = elt(env, 12); /* qqe_arg!-check!-b */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    if (!(v0141 == nil)) goto v0093;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    v0210 = stack[0];
    v0141 = elt(env, 3); /* "some arguments are not of basic type" */
    fn = elt(env, 14); /* typerr */
    v0141 = (*qfn2(fn))(qenv(fn), v0210, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    goto v0093;

v0093:
    v0141 = stack[-1];
    v0141 = qcdr(v0141);
    stack[-1] = v0141;
    goto v0136;

v0034:
    v0141 = stack[0];
    v0141 = qcdr(v0141);
    v0141 = qcar(v0141);
    fn = elt(env, 15); /* qqe_arg!-check!-q */
    v0141 = (*qfn1(fn))(qenv(fn), v0141);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    if (!(v0141 == nil)) goto v0044;
    fn = elt(env, 13); /* qqe_arg!-check!-marked!-ids!-rollback */
    v0141 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    v0210 = stack[0];
    v0141 = elt(env, 1); /* "some arguments are not of queue type" */
    fn = elt(env, 14); /* typerr */
    v0141 = (*qfn2(fn))(qenv(fn), v0210, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0190;
    env = stack[-2];
    goto v0044;
/* error exit handlers */
v0190:
    popv(3);
    return nil;
}



/* Code for pasf_vf */

static Lisp_Object CC_pasf_vf(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0157, v0212;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_vf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0157 = v0040;
/* end of prologue */
    v0212 = v0157;
    v0009 = elt(env, 1); /* true */
    if (v0212 == v0009) goto v0127;
    v0212 = v0157;
    v0009 = elt(env, 3); /* false */
    v0009 = (v0212 == v0009 ? lisp_true : nil);
    goto v0122;

v0122:
    if (v0009 == nil) goto v0119;
    v0009 = qvalue(elt(env, 4)); /* nil */
    goto v0097;

v0097:
    if (v0009 == nil) { popv(1); return onevalue(v0157); }
    v0009 = v0157;
    v0009 = Lconsp(nil, v0009);
    env = stack[0];
    if (v0009 == nil) goto v0213;
    v0009 = v0157;
    v0009 = qcar(v0009);
    v0009 = Lconsp(nil, v0009);
    env = stack[0];
    if (v0009 == nil) goto v0213;
    v0009 = v0157;
    v0009 = qcar(v0009);
    v0212 = qcar(v0009);
    v0009 = elt(env, 5); /* (cong ncong) */
    v0009 = Lmemq(nil, v0212, v0009);
    if (v0009 == nil) goto v0213;
    v0009 = v0157;
    v0009 = qcar(v0009);
    v0009 = qcdr(v0009);
    if (!consp(v0009)) goto v0036;
    v0009 = v0157;
    v0009 = qcar(v0009);
    v0009 = qcdr(v0009);
    v0009 = qcar(v0009);
    v0009 = (consp(v0009) ? nil : lisp_true);
    goto v0037;

v0037:
    if (!(v0009 == nil)) goto v0213;
    v0009 = v0157;
    v0009 = qcdr(v0009);
    v0009 = qcar(v0009);
    if (!(v0009 == nil)) { popv(1); return onevalue(v0157); }
    v0009 = elt(env, 3); /* false */
    { popv(1); return onevalue(v0009); }

v0213:
    v0009 = v0157;
    v0009 = qcar(v0009);
    v0157 = qcdr(v0157);
    v0157 = qcar(v0157);
    fn = elt(env, 6); /* pasf_evalatp */
    v0009 = (*qfn2(fn))(qenv(fn), v0009, v0157);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[0];
    if (v0009 == nil) goto v0204;
    v0009 = elt(env, 1); /* true */
    { popv(1); return onevalue(v0009); }

v0204:
    v0009 = elt(env, 3); /* false */
    { popv(1); return onevalue(v0009); }

v0036:
    v0009 = qvalue(elt(env, 2)); /* t */
    goto v0037;

v0119:
    v0009 = v0157;
    v0009 = qcdr(v0009);
    v0009 = qcar(v0009);
    if (!consp(v0009)) goto v0026;
    v0009 = v0157;
    v0009 = qcdr(v0009);
    v0009 = qcar(v0009);
    v0009 = qcar(v0009);
    v0009 = (consp(v0009) ? nil : lisp_true);
    goto v0097;

v0026:
    v0009 = qvalue(elt(env, 2)); /* t */
    goto v0097;

v0127:
    v0009 = qvalue(elt(env, 2)); /* t */
    goto v0122;
/* error exit handlers */
v0214:
    popv(1);
    return nil;
}



/* Code for ibalp_var!-wclist */

static Lisp_Object CC_ibalp_varKwclist(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0150, v0184;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_var-wclist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0040;
/* end of prologue */
    stack[-3] = nil;
    v0150 = stack[-4];
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcar(v0150);
    stack[-2] = v0150;
    goto v0097;

v0097:
    v0150 = stack[-2];
    if (v0150 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    v0150 = stack[-2];
    v0150 = qcar(v0150);
    stack[-1] = v0150;
    v0150 = stack[-1];
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcar(v0150);
    if (!(v0150 == nil)) goto v0041;
    v0150 = stack[-1];
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    stack[0] = qcdr(v0150);
    v0184 = stack[-4];
    v0150 = stack[-1];
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcar(v0150);
    fn = elt(env, 2); /* delq */
    v0150 = (*qfn2(fn))(qenv(fn), v0184, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0150 = (*qfn2(fn))(qenv(fn), stack[0], v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-6];
    v0150 = stack[-4];
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    stack[0] = qcdr(v0150);
    v0184 = stack[-1];
    v0150 = stack[-4];
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcar(v0150);
    fn = elt(env, 2); /* delq */
    v0150 = (*qfn2(fn))(qenv(fn), v0184, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0150 = (*qfn2(fn))(qenv(fn), stack[0], v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-6];
    v0150 = stack[-1];
    fn = elt(env, 4); /* ibalp_getnewwl */
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-6];
    stack[-5] = v0150;
    v0150 = stack[-5];
    if (v0150 == nil) goto v0187;
    v0150 = stack[-1];
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    stack[0] = qcdr(v0150);
    v0184 = stack[-5];
    v0150 = stack[-1];
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcar(v0150);
    v0150 = cons(v0184, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0150 = (*qfn2(fn))(qenv(fn), stack[0], v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-6];
    v0150 = stack[-5];
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    stack[0] = qcdr(v0150);
    v0184 = stack[-1];
    v0150 = stack[-5];
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcdr(v0150);
    v0150 = qcar(v0150);
    v0150 = cons(v0184, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-6];
    fn = elt(env, 3); /* setcar */
    v0150 = (*qfn2(fn))(qenv(fn), stack[0], v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-6];
    goto v0041;

v0041:
    v0150 = stack[-2];
    v0150 = qcdr(v0150);
    stack[-2] = v0150;
    goto v0097;

v0187:
    v0184 = stack[-1];
    v0150 = stack[-3];
    v0150 = cons(v0184, v0150);
    nil = C_nil;
    if (exception_pending()) goto v0200;
    env = stack[-6];
    stack[-3] = v0150;
    goto v0041;
/* error exit handlers */
v0200:
    popv(7);
    return nil;
}



/* Code for cgb_buch!-ev_divides!? */

static Lisp_Object CC_cgb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0121;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgb_buch-ev_divides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0121 = v0005;
    v0120 = v0040;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v0121, v0120);
    }
}



/* Code for diff!-over!-k!-mod!-p */

static Lisp_Object MS_CDECL CC_diffKoverKkKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0040, Lisp_Object v0005,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0226, v0103, v0000;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-over-k-mod-p");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diff-over-k-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0002,v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0040,v0005,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0002;
    stack[-2] = v0005;
    stack[-3] = v0040;
/* end of prologue */
    v0226 = stack[-3];
    if (!consp(v0226)) goto v0119;
    v0226 = stack[-3];
    v0226 = qcar(v0226);
    v0226 = (consp(v0226) ? nil : lisp_true);
    goto v0097;

v0097:
    if (v0226 == nil) goto v0164;
    v0226 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0226); }

v0164:
    v0226 = stack[-3];
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    v0103 = qcar(v0226);
    v0226 = stack[-1];
    if (equal(v0103, v0226)) goto v0026;
    v0226 = stack[-3];
    v0226 = qcar(v0226);
    stack[-4] = qcar(v0226);
    v0226 = stack[-3];
    v0226 = qcar(v0226);
    v0000 = qcdr(v0226);
    v0103 = stack[-2];
    v0226 = stack[-1];
    stack[0] = CC_diffKoverKkKmodKp(env, 3, v0000, v0103, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    v0226 = stack[-3];
    v0000 = qcdr(v0226);
    v0103 = stack[-2];
    v0226 = stack[-1];
    v0226 = CC_diffKoverKkKmodKp(env, 3, v0000, v0103, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    {
        Lisp_Object v0228 = stack[-4];
        Lisp_Object v0032 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0228, v0032, v0226);
    }

v0026:
    v0226 = stack[-3];
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    v0103 = qcdr(v0226);
    v0226 = (Lisp_Object)17; /* 1 */
    if (v0103 == v0226) goto v0101;
    v0103 = stack[-1];
    v0226 = stack[-3];
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    v0226 = qcdr(v0226);
    v0226 = (Lisp_Object)((int32_t)(v0226) - 0x10);
    fn = elt(env, 4); /* mksp */
    stack[-4] = (*qfn2(fn))(qenv(fn), v0103, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    v0226 = stack[-3];
    v0226 = qcar(v0226);
    v0226 = qcar(v0226);
    v0226 = qcdr(v0226);
    v0103 = Lmodular_number(nil, v0226);
    env = stack[-5];
    v0226 = stack[-3];
    v0226 = qcar(v0226);
    v0226 = qcdr(v0226);
    fn = elt(env, 5); /* times!-mod!-p */
    v0103 = (*qfn2(fn))(qenv(fn), v0103, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    v0226 = stack[-2];
    v0226 = Lmodular_number(nil, v0226);
    env = stack[-5];
    fn = elt(env, 6); /* quotient!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v0103, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    v0226 = stack[-3];
    v0000 = qcdr(v0226);
    v0103 = stack[-2];
    v0226 = stack[-1];
    v0226 = CC_diffKoverKkKmodKp(env, 3, v0000, v0103, v0226);
    nil = C_nil;
    if (exception_pending()) goto v0227;
    env = stack[-5];
    {
        Lisp_Object v0154 = stack[-4];
        Lisp_Object v0152 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0154, v0152, v0226);
    }

v0101:
    v0226 = stack[-3];
    v0226 = qcar(v0226);
    v0103 = qcdr(v0226);
    v0226 = stack[-2];
    v0226 = Lmodular_number(nil, v0226);
    env = stack[-5];
    {
        popv(6);
        fn = elt(env, 6); /* quotient!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0103, v0226);
    }

v0119:
    v0226 = qvalue(elt(env, 1)); /* t */
    goto v0097;
/* error exit handlers */
v0227:
    popv(6);
    return nil;
}



/* Code for ir2mml */

static Lisp_Object CC_ir2mml(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ir2mml");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0040;
/* end of prologue */
    v0045 = elt(env, 1); /* (indent) */
    fn = elt(env, 8); /* fluid */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-1];
    v0045 = (Lisp_Object)49; /* 3 */
    qvalue(elt(env, 2)) = v0045; /* ind */
    v0045 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v0045; /* indent */
    v0045 = elt(env, 4); /* "<math>" */
    fn = elt(env, 9); /* printout */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-1];
    v0045 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 10); /* indent!* */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-1];
    v0045 = stack[0];
    fn = elt(env, 11); /* expression */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-1];
    v0045 = qvalue(elt(env, 6)); /* nil */
    fn = elt(env, 10); /* indent!* */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    env = stack[-1];
    v0045 = elt(env, 7); /* "</math>" */
    fn = elt(env, 9); /* printout */
    v0045 = (*qfn1(fn))(qenv(fn), v0045);
    nil = C_nil;
    if (exception_pending()) goto v0163;
    v0045 = nil;
    { popv(2); return onevalue(v0045); }
/* error exit handlers */
v0163:
    popv(2);
    return nil;
}



/* Code for pfordp */

static Lisp_Object CC_pfordp(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0126, v0136, v0208, v0020;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pfordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0136 = v0005;
    v0208 = v0040;
/* end of prologue */

v0052:
    v0126 = v0208;
    if (v0126 == nil) goto v0117;
    v0126 = v0136;
    if (v0126 == nil) goto v0027;
    v0126 = v0208;
    v0126 = qcar(v0126);
    v0020 = qcar(v0126);
    v0126 = v0136;
    v0126 = qcar(v0126);
    v0126 = qcar(v0126);
    if (v0020 == v0126) goto v0023;
    v0126 = v0208;
    v0126 = qcar(v0126);
    v0126 = qcar(v0126);
    v0136 = qcar(v0136);
    v0136 = qcar(v0136);
    {
        fn = elt(env, 2); /* termordp */
        return (*qfn2(fn))(qenv(fn), v0126, v0136);
    }

v0023:
    v0126 = v0208;
    v0126 = qcdr(v0126);
    v0208 = v0126;
    v0126 = v0136;
    v0126 = qcdr(v0126);
    v0136 = v0126;
    goto v0052;

v0027:
    v0126 = v0208;
    v0126 = qcar(v0126);
    v0136 = qcar(v0126);
    v0126 = (Lisp_Object)17; /* 1 */
        return Lneq(nil, v0136, v0126);

v0117:
    v0126 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0126);
}



/* Code for delete!-dups */

static Lisp_Object CC_deleteKdups(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0050, v0051, v0087;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delete-dups");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0040;
/* end of prologue */
    v0087 = nil;
    goto v0052;

v0052:
    v0050 = stack[0];
    if (v0050 == nil) goto v0229;
    v0050 = stack[0];
    v0051 = qcar(v0050);
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    v0050 = Lmember(nil, v0051, v0050);
    if (v0050 == nil) goto v0086;
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    stack[0] = v0050;
    goto v0052;

v0086:
    v0050 = stack[0];
    v0050 = qcar(v0050);
    v0051 = v0087;
    v0050 = cons(v0050, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0123;
    env = stack[-1];
    v0087 = v0050;
    v0050 = stack[0];
    v0050 = qcdr(v0050);
    stack[0] = v0050;
    goto v0052;

v0229:
    v0050 = v0087;
    {
        popv(2);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0050);
    }
/* error exit handlers */
v0123:
    popv(2);
    return nil;
}



/* Code for fortranname */

static Lisp_Object CC_fortranname(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0035, v0129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for fortranname");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0040;
/* end of prologue */
    v0035 = stack[0];
    v0035 = Lstringp(nil, v0035);
    env = stack[-1];
    if (v0035 == nil) goto v0027;
    v0035 = stack[0];
    {
        popv(2);
        fn = elt(env, 9); /* stringtoatom */
        return (*qfn1(fn))(qenv(fn), v0035);
    }

v0027:
    v0129 = stack[0];
    v0035 = qvalue(elt(env, 1)); /* !*notfortranfuns!* */
    v0035 = Lmemq(nil, v0129, v0035);
    if (v0035 == nil) goto v0122;
    v0035 = qvalue(elt(env, 2)); /* !*stdout!* */
    v0035 = qcdr(v0035);
    v0035 = Lwrs(nil, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    v0035 = elt(env, 3); /* "*** WARNING: " */
    v0035 = Lprinc(nil, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    v0035 = stack[0];
    v0035 = Lprin(nil, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    v0035 = elt(env, 4); /* " is not an intrinsic Fortran function" */
    fn = elt(env, 10); /* prin2t */
    v0035 = (*qfn1(fn))(qenv(fn), v0035);
    nil = C_nil;
    if (exception_pending()) goto v0131;
    env = stack[-1];
    goto v0122;

v0122:
    v0035 = qvalue(elt(env, 6)); /* !*double */
    if (v0035 == nil) goto v0136;
    v0129 = stack[0];
    v0035 = elt(env, 7); /* !*doublename!* */
    v0035 = get(v0129, v0035);
    if (v0035 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v0035); }

v0136:
    v0129 = stack[0];
    v0035 = elt(env, 8); /* !*fortranname!* */
    v0035 = get(v0129, v0035);
    if (v0035 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { popv(2); return onevalue(v0035); }
/* error exit handlers */
v0131:
    popv(2);
    return nil;
}



/* Code for coposp */

static Lisp_Object CC_coposp(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0130, v0108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for coposp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0108 = v0040;
/* end of prologue */
    v0130 = v0108;
    v0130 = qcdr(v0130);
    if (v0130 == nil) goto v0053;
    v0130 = v0108;
    v0130 = qcar(v0130);
    if (!consp(v0130)) goto v0122;
    v0130 = v0108;
    v0130 = qcdr(v0130);
    {
        fn = elt(env, 2); /* covposp */
        return (*qfn1(fn))(qenv(fn), v0130);
    }

v0122:
    v0130 = v0108;
    v0130 = qcdr(v0130);
    {
        fn = elt(env, 3); /* contposp */
        return (*qfn1(fn))(qenv(fn), v0130);
    }

v0053:
    v0130 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0130);
}



/* Code for factorial */

static Lisp_Object CC_factorial(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0087;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for factorial");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0040;
/* end of prologue */
    v0051 = stack[-1];
    v0051 = integerp(v0051);
    if (v0051 == nil) goto v0117;
    v0087 = stack[-1];
    v0051 = (Lisp_Object)1; /* 0 */
    v0051 = (Lisp_Object)lessp2(v0087, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    v0051 = v0051 ? lisp_true : nil;
    env = stack[-3];
    goto v0118;

v0118:
    if (v0051 == nil) goto v0162;
    stack[-2] = elt(env, 2); /* arith */
    stack[0] = (Lisp_Object)65; /* 4 */
    v0087 = stack[-1];
    v0051 = elt(env, 3); /* "invalid factorial argument" */
    v0051 = list2(v0087, v0051);
    nil = C_nil;
    if (exception_pending()) goto v0023;
    env = stack[-3];
    {
        Lisp_Object v0124 = stack[-2];
        Lisp_Object v0125 = stack[0];
        popv(4);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0124, v0125, v0051);
    }

v0162:
    v0051 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); /* nfactorial */
        return (*qfn1(fn))(qenv(fn), v0051);
    }

v0117:
    v0051 = qvalue(elt(env, 1)); /* t */
    goto v0118;
/* error exit handlers */
v0023:
    popv(4);
    return nil;
}



/* Code for in_list1 */

static Lisp_Object CC_in_list1(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0127, v0028, v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for in_list1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0127 = v0005;
    v0028 = v0040;
/* end of prologue */
    v0027 = v0028;
    v0028 = v0127;
    v0127 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* in_list1a */
        return (*qfnn(fn))(qenv(fn), 3, v0027, v0028, v0127);
    }
}



/* Code for mv!-domainlist!-!* */

static Lisp_Object CC_mvKdomainlistKH(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0025;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mv-domainlist-*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
    stack[-1] = v0040;
/* end of prologue */
    stack[-2] = nil;
    goto v0044;

v0044:
    v0099 = stack[0];
    if (v0099 == nil) goto v0097;
    v0025 = stack[-1];
    v0099 = stack[0];
    v0099 = qcar(v0099);
    v0025 = times2(v0025, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    v0099 = stack[-2];
    v0099 = cons(v0025, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    stack[-2] = v0099;
    v0099 = stack[0];
    v0099 = qcdr(v0099);
    stack[0] = v0099;
    goto v0044;

v0097:
    v0099 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0099);
    }
/* error exit handlers */
v0048:
    popv(4);
    return nil;
}



/* Code for dv_cambhead */

static Lisp_Object CC_dv_cambhead(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_cambhead");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0040;
/* end of prologue */

v0197:
    v0049 = stack[0];
    fn = elt(env, 4); /* listp */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    if (v0049 == nil) goto v0052;
    v0049 = stack[0];
    stack[-1] = qcar(v0049);
    v0050 = elt(env, 1); /* expt */
    v0049 = elt(env, 2); /* minus */
    v0049 = list2(v0050, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    env = stack[-2];
    v0049 = Lmember(nil, stack[-1], v0049);
    if (v0049 == nil) goto v0120;
    v0049 = stack[0];
    v0049 = qcdr(v0049);
    v0049 = qcar(v0049);
    stack[0] = v0049;
    goto v0197;

v0120:
    v0049 = stack[0];
    fn = elt(env, 4); /* listp */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0101;
    if (v0049 == nil) goto v0052;
    v0049 = stack[0];
    v0049 = qcar(v0049);
    { popv(3); return onevalue(v0049); }

v0052:
    v0049 = nil;
    { popv(3); return onevalue(v0049); }
/* error exit handlers */
v0101:
    popv(3);
    return nil;
}



/* Code for kernord!-split */

static Lisp_Object CC_kernordKsplit(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0171, v0231, v0169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernord-split");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0005;
    stack[-3] = v0040;
/* end of prologue */
    stack[-4] = nil;
    stack[-1] = nil;
    v0171 = stack[-3];
    fn = elt(env, 2); /* powers */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-5];
    stack[-3] = v0171;
    v0171 = stack[-2];
    fn = elt(env, 2); /* powers */
    v0171 = (*qfn1(fn))(qenv(fn), v0171);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-5];
    stack[-2] = v0171;
    v0171 = stack[-3];
    stack[0] = v0171;
    goto v0127;

v0127:
    v0171 = stack[0];
    if (v0171 == nil) goto v0122;
    v0171 = stack[0];
    v0171 = qcar(v0171);
    v0169 = v0171;
    v0171 = v0169;
    v0231 = qcar(v0171);
    v0171 = stack[-2];
    v0171 = Lassoc(nil, v0231, v0171);
    if (v0171 == nil) goto v0024;
    v0231 = v0169;
    v0171 = stack[-1];
    v0171 = cons(v0231, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-5];
    stack[-1] = v0171;
    goto v0108;

v0108:
    v0171 = stack[0];
    v0171 = qcdr(v0171);
    stack[0] = v0171;
    goto v0127;

v0024:
    v0231 = v0169;
    v0171 = stack[-4];
    v0171 = cons(v0231, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-5];
    stack[-4] = v0171;
    goto v0108;

v0122:
    v0171 = stack[-2];
    stack[0] = v0171;
    goto v0022;

v0022:
    v0171 = stack[0];
    if (v0171 == nil) goto v0139;
    v0171 = stack[0];
    v0171 = qcar(v0171);
    v0169 = v0171;
    v0171 = v0169;
    v0231 = qcar(v0171);
    v0171 = stack[-3];
    v0171 = Lassoc(nil, v0231, v0171);
    if (v0171 == nil) goto v0014;
    v0231 = v0169;
    v0171 = stack[-1];
    v0171 = cons(v0231, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-5];
    stack[-1] = v0171;
    goto v0018;

v0018:
    v0171 = stack[0];
    v0171 = qcdr(v0171);
    stack[0] = v0171;
    goto v0022;

v0014:
    v0231 = v0169;
    v0171 = stack[-4];
    v0171 = cons(v0231, v0171);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-5];
    stack[-4] = v0171;
    goto v0018;

v0139:
    v0171 = stack[-4];
    v0231 = Lnreverse(nil, v0171);
    env = stack[-5];
    v0171 = stack[-1];
    v0171 = Lnreverse(nil, v0171);
    popv(6);
    return cons(v0231, v0171);
/* error exit handlers */
v0009:
    popv(6);
    return nil;
}



/* Code for ibalp_isinminclause */

static Lisp_Object CC_ibalp_isinminclause(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0233, v0217;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_isinminclause");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0005;
    stack[-2] = v0040;
/* end of prologue */
    stack[0] = nil;
    v0233 = stack[-2];
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcar(v0233);
    stack[-3] = v0233;
    goto v0122;

v0122:
    v0233 = stack[-3];
    if (v0233 == nil) goto v0121;
    v0233 = stack[0];
    if (!(v0233 == nil)) goto v0121;
    v0233 = stack[-3];
    v0233 = qcar(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcar(v0233);
    if (v0233 == nil) goto v0051;
    v0233 = qvalue(elt(env, 1)); /* nil */
    goto v0230;

v0230:
    if (v0233 == nil) goto v0166;
    v0233 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0233;
    goto v0166;

v0166:
    v0233 = stack[-3];
    v0233 = qcdr(v0233);
    stack[-3] = v0233;
    goto v0122;

v0051:
    v0233 = stack[-3];
    v0233 = qcar(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0217 = qcar(v0233);
    v0233 = stack[-3];
    v0233 = qcar(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcar(v0233);
    v0217 = plus2(v0217, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-4];
    v0233 = stack[-1];
    v0233 = Leqn(nil, v0217, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-4];
    goto v0230;

v0121:
    v0233 = stack[-2];
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcar(v0233);
    stack[-3] = v0233;
    goto v0091;

v0091:
    v0233 = stack[-3];
    if (v0233 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0233 = stack[0];
    if (!(v0233 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v0233 = stack[-3];
    v0233 = qcar(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcar(v0233);
    if (v0233 == nil) goto v0213;
    v0233 = qvalue(elt(env, 1)); /* nil */
    goto v0224;

v0224:
    if (v0233 == nil) goto v0016;
    v0233 = qvalue(elt(env, 2)); /* t */
    stack[0] = v0233;
    goto v0016;

v0016:
    v0233 = stack[-3];
    v0233 = qcdr(v0233);
    stack[-3] = v0233;
    goto v0091;

v0213:
    v0233 = stack[-3];
    v0233 = qcar(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0217 = qcar(v0233);
    v0233 = stack[-3];
    v0233 = qcar(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcdr(v0233);
    v0233 = qcar(v0233);
    v0217 = plus2(v0217, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-4];
    v0233 = stack[-1];
    v0233 = Leqn(nil, v0217, v0233);
    nil = C_nil;
    if (exception_pending()) goto v0072;
    env = stack[-4];
    goto v0224;
/* error exit handlers */
v0072:
    popv(5);
    return nil;
}



/* Code for aex_lc */

static Lisp_Object CC_aex_lc(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0025, v0026, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_lc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0025 = v0005;
    stack[0] = v0040;
/* end of prologue */
    v0026 = stack[0];
    fn = elt(env, 2); /* aex_mvartest */
    v0025 = (*qfn2(fn))(qenv(fn), v0026, v0025);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-2];
    if (v0025 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v0025 = stack[0];
    fn = elt(env, 3); /* aex_ex */
    v0025 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-2];
    fn = elt(env, 4); /* ratpoly_lc */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-2];
    v0025 = stack[0];
    fn = elt(env, 5); /* aex_ctx */
    v0046 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-2];
    v0026 = qvalue(elt(env, 1)); /* nil */
    v0025 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0162 = stack[-1];
        popv(3);
        fn = elt(env, 6); /* aex_mk */
        return (*qfnn(fn))(qenv(fn), 4, v0162, v0046, v0026, v0025);
    }
/* error exit handlers */
v0229:
    popv(3);
    return nil;
}



/* Code for ofsf_smwupdknowl */

static Lisp_Object MS_CDECL CC_ofsf_smwupdknowl(Lisp_Object env, int nargs,
                         Lisp_Object v0040, Lisp_Object v0005,
                         Lisp_Object v0002, Lisp_Object v0084, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0229, v0162, v0137, v0049, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ofsf_smwupdknowl");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_smwupdknowl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0162 = v0084;
    v0137 = v0002;
    v0049 = v0005;
    v0050 = v0040;
/* end of prologue */
    v0229 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0229 == nil) goto v0177;
    v0229 = v0050;
    {
        fn = elt(env, 2); /* cl_susiupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v0229, v0049, v0137, v0162);
    }

v0177:
    v0229 = v0050;
    {
        fn = elt(env, 3); /* ofsf_smupdknowl */
        return (*qfnn(fn))(qenv(fn), 4, v0229, v0049, v0137, v0162);
    }
}



/* Code for resume */

static Lisp_Object CC_resume(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0229, v0162, v0137, v0049;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for resume");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0229 = v0005;
    v0162 = v0040;
/* end of prologue */
    v0137 = v0229;
    if (v0137 == nil) goto v0086;
    v0137 = v0229;
    v0137 = qcar(v0137);
    v0049 = qcar(v0137);
    v0137 = v0229;
    v0137 = qcar(v0137);
    v0137 = qcdr(v0137);
    v0137 = qcar(v0137);
    v0229 = qcdr(v0229);
    {
        popv(1);
        fn = elt(env, 3); /* amatch */
        return (*qfnn(fn))(qenv(fn), 4, v0049, v0137, v0162, v0229);
    }

v0086:
    v0229 = v0162;
    fn = elt(env, 4); /* chk */
    v0162 = (*qfn1(fn))(qenv(fn), v0229);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[0];
    v0229 = qvalue(elt(env, 1)); /* t */
    if (v0162 == v0229) goto v0230;
    v0229 = nil;
    { popv(1); return onevalue(v0229); }

v0230:
    v0229 = qvalue(elt(env, 2)); /* substitution */
    {
        popv(1);
        fn = elt(env, 5); /* bsubs */
        return (*qfn1(fn))(qenv(fn), v0229);
    }
/* error exit handlers */
v0050:
    popv(1);
    return nil;
}



/* Code for onoff */

static Lisp_Object CC_onoff(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0211, v0102, v0234;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for onoff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0005;
    stack[0] = v0040;
/* end of prologue */
    v0211 = stack[0];
    if (symbolp(v0211)) goto v0119;
    v0102 = stack[0];
    v0211 = elt(env, 1); /* "switch" */
    fn = elt(env, 10); /* typerr */
    v0211 = (*qfn2(fn))(qenv(fn), v0102, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    goto v0051;

v0051:
    v0211 = elt(env, 4); /* !* */
    stack[-1] = Lexplode(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    v0211 = stack[0];
    v0211 = Lexplode(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    v0211 = Lappend(nil, stack[-1], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    v0211 = Lcompress(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    v0211 = Lintern(nil, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    stack[-3] = v0211;
    v0211 = qvalue(elt(env, 5)); /* !*switchcheck */
    if (v0211 == nil) goto v0019;
    v0211 = stack[-3];
    fn = elt(env, 11); /* lispeval */
    v0102 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    v0211 = stack[-2];
    if (!(v0102 == v0211)) goto v0019;
    v0211 = qvalue(elt(env, 6)); /* nil */
    { popv(5); return onevalue(v0211); }

v0019:
    v0234 = stack[-2];
    v0102 = stack[0];
    v0211 = elt(env, 7); /* simpfg */
    v0211 = get(v0102, v0211);
    env = stack[-4];
    v0211 = Latsoc(nil, v0234, v0211);
    v0102 = v0211;
    if (v0211 == nil) goto v0100;
    stack[-1] = elt(env, 8); /* progn */
    v0211 = v0102;
    stack[0] = qcdr(v0211);
    v0211 = qvalue(elt(env, 6)); /* nil */
    v0211 = ncons(v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    v0211 = Lappend(nil, stack[0], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    v0211 = cons(stack[-1], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    fn = elt(env, 11); /* lispeval */
    v0211 = (*qfn1(fn))(qenv(fn), v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    goto v0100;

v0100:
    v0211 = stack[-2];
    if (v0211 == nil) goto v0010;
    v0102 = stack[-3];
    v0211 = elt(env, 9); /* !*raise */
    if (!(v0102 == v0211)) goto v0010;
    v0211 = elt(env, 9); /* !*raise */
    stack[-3] = v0211;
    goto v0010;

v0010:
    v0102 = stack[-3];
    v0211 = stack[-2];
    v0211 = Lset(nil, v0102, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    v0211 = nil;
    { popv(5); return onevalue(v0211); }

v0119:
    v0211 = stack[0];
    if (!symbolp(v0211)) v0211 = nil;
    else { v0211 = qfastgets(v0211);
           if (v0211 != nil) { v0211 = elt(v0211, 51); /* switch */
#ifdef RECORD_GET
             if (v0211 == SPID_NOPROP)
                record_get(elt(fastget_names, 51), 0),
                v0211 = nil;
             else record_get(elt(fastget_names, 51), 1),
                v0211 = lisp_true; }
           else record_get(elt(fastget_names, 51), 0); }
#else
             if (v0211 == SPID_NOPROP) v0211 = nil; else v0211 = lisp_true; }}
#endif
    if (!(v0211 == nil)) goto v0051;
    stack[-3] = elt(env, 2); /* rlisp */
    stack[-1] = (Lisp_Object)401; /* 25 */
    v0102 = stack[0];
    v0211 = elt(env, 3); /* "not defined as switch" */
    v0211 = list2(v0102, v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    fn = elt(env, 12); /* rerror */
    v0211 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[-1], v0211);
    nil = C_nil;
    if (exception_pending()) goto v0218;
    env = stack[-4];
    goto v0051;
/* error exit handlers */
v0218:
    popv(5);
    return nil;
}



/* Code for evdif */

static Lisp_Object CC_evdif(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0124, v0125, v0203;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evdif");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
    stack[-1] = v0040;
/* end of prologue */
    v0203 = nil;
    goto v0117;

v0117:
    v0124 = stack[0];
    if (v0124 == nil) goto v0049;
    v0124 = stack[-1];
    if (!(v0124 == nil)) goto v0177;
    v0124 = elt(env, 2); /* (0) */
    stack[-1] = v0124;
    goto v0177;

v0177:
    v0124 = stack[-1];
    v0125 = qcar(v0124);
    v0124 = stack[0];
    v0124 = qcar(v0124);
    v0124 = (Lisp_Object)(int32_t)((int32_t)v0125 - (int32_t)v0124 + TAG_FIXNUM);
    v0125 = v0203;
    v0124 = cons(v0124, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-2];
    v0203 = v0124;
    v0124 = stack[-1];
    v0124 = qcdr(v0124);
    stack[-1] = v0124;
    v0124 = stack[0];
    v0124 = qcdr(v0124);
    stack[0] = v0124;
    goto v0117;

v0049:
    v0124 = v0203;
    v0125 = Lnreverse(nil, v0124);
    v0124 = stack[-1];
        popv(3);
        return Lnconc(nil, v0125, v0124);
/* error exit handlers */
v0126:
    popv(3);
    return nil;
}



/* Code for all_defined_vertex */

static Lisp_Object CC_all_defined_vertex(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0132, v0045, v0034, v0163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for all_defined_vertex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0132 = v0005;
    v0045 = v0040;
/* end of prologue */
    v0163 = v0045;
    v0034 = qvalue(elt(env, 1)); /* nil */
    v0045 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* al1_defined_vertex */
        return (*qfnn(fn))(qenv(fn), 4, v0163, v0034, v0045, v0132);
    }
}



/* Code for set!-global!-mode */

static Lisp_Object CC_setKglobalKmode(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for set-global-mode");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0040;
/* end of prologue */
    v0108 = qvalue(elt(env, 1)); /* nil */
    v0108 = ncons(v0108);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    qvalue(elt(env, 2)) = v0108; /* alglist!* */
    v0108 = stack[-2];
    qvalue(elt(env, 3)) = v0108; /* !*mode */
    stack[-3] = elt(env, 4); /* null */
    stack[-1] = elt(env, 5); /* setq */
    stack[0] = elt(env, 3); /* !*mode */
    v0108 = stack[-2];
    v0108 = Lmkquote(nil, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0108 = list3(stack[-1], stack[0], v0108);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    {
        Lisp_Object v0041 = stack[-3];
        popv(5);
        return list2(v0041, v0108);
    }
/* error exit handlers */
v0042:
    popv(5);
    return nil;
}



/* Code for groeb!=weight */

static Lisp_Object MS_CDECL CC_groebMweight(Lisp_Object env, int nargs,
                         Lisp_Object v0040, Lisp_Object v0005,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0164;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groeb=weight");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for groeb=weight");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0002,v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0040,v0005,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0002;
    stack[-1] = v0005;
    v0164 = v0040;
/* end of prologue */
    fn = elt(env, 1); /* mo_ecart */
    stack[-2] = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0164 = stack[-1];
    fn = elt(env, 2); /* bas_dpecart */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0164 = stack[0];
    fn = elt(env, 2); /* bas_dpecart */
    v0164 = (*qfn1(fn))(qenv(fn), v0164);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0164 = Lmin2(nil, stack[-1], v0164);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    {
        Lisp_Object v0177 = stack[-2];
        popv(4);
        return plus2(v0177, v0164);
    }
/* error exit handlers */
v0108:
    popv(4);
    return nil;
}



/* Code for general!-evaluate!-mod!-p */

static Lisp_Object MS_CDECL CC_generalKevaluateKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0040, Lisp_Object v0005,
                         Lisp_Object v0002, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0011, v0187, v0188, v0171;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "general-evaluate-mod-p");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-evaluate-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0002,v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0040,v0005,v0002);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0002;
    stack[-2] = v0005;
    stack[-3] = v0040;
/* end of prologue */

v0044:
    v0012 = stack[-3];
    if (!consp(v0012)) goto v0122;
    v0012 = stack[-3];
    v0012 = qcar(v0012);
    v0012 = (consp(v0012) ? nil : lisp_true);
    goto v0121;

v0121:
    if (!(v0012 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0011 = stack[-1];
    v0012 = (Lisp_Object)1; /* 0 */
    if (v0011 == v0012) goto v0065;
    v0012 = stack[-2];
    if (v0012 == nil) goto v0043;
    v0012 = stack[-3];
    v0012 = qcar(v0012);
    v0012 = qcar(v0012);
    v0011 = qcar(v0012);
    v0012 = stack[-2];
    if (equal(v0011, v0012)) goto v0124;
    v0012 = stack[-3];
    v0012 = qcar(v0012);
    stack[-4] = qcar(v0012);
    v0012 = stack[-3];
    v0012 = qcar(v0012);
    v0187 = qcdr(v0012);
    v0011 = stack[-2];
    v0012 = stack[-1];
    stack[0] = CC_generalKevaluateKmodKp(env, 3, v0187, v0011, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-5];
    v0012 = stack[-3];
    v0187 = qcdr(v0012);
    v0011 = stack[-2];
    v0012 = stack[-1];
    v0012 = CC_generalKevaluateKmodKp(env, 3, v0187, v0011, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-5];
    {
        Lisp_Object v0008 = stack[-4];
        Lisp_Object v0009 = stack[0];
        popv(6);
        fn = elt(env, 4); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0008, v0009, v0012);
    }

v0124:
    v0012 = stack[-3];
    v0012 = qcar(v0012);
    v0171 = qcdr(v0012);
    v0012 = stack[-3];
    v0012 = qcar(v0012);
    v0012 = qcar(v0012);
    v0188 = qcdr(v0012);
    v0012 = stack[-3];
    v0187 = qcdr(v0012);
    v0011 = stack[-1];
    v0012 = stack[-2];
    {
        popv(6);
        fn = elt(env, 5); /* general!-horner!-rule!-mod!-p */
        return (*qfnn(fn))(qenv(fn), 5, v0171, v0188, v0187, v0011, v0012);
    }

v0043:
    v0012 = elt(env, 3); /* "Variable=NIL in GENERAL-EVALUATE-MOD-P" */
    {
        popv(6);
        fn = elt(env, 6); /* errorf */
        return (*qfn1(fn))(qenv(fn), v0012);
    }

v0065:
    v0012 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v0012;
    goto v0044;

v0122:
    v0012 = qvalue(elt(env, 1)); /* t */
    goto v0121;
/* error exit handlers */
v0010:
    popv(6);
    return nil;
}



/* Code for delet */

static Lisp_Object CC_delet(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0018, v0207;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delet");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
    stack[-1] = v0040;
/* end of prologue */
    v0207 = nil;
    goto v0044;

v0044:
    v0019 = stack[-1];
    if (v0019 == nil) goto v0122;
    v0019 = stack[0];
    if (v0019 == nil) goto v0166;
    v0018 = stack[-1];
    v0019 = stack[0];
    v0019 = (equal(v0018, v0019) ? lisp_true : nil);
    goto v0065;

v0065:
    if (v0019 == nil) goto v0137;
    v0019 = v0207;
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0019);
    }

v0137:
    v0018 = stack[-1];
    v0019 = stack[0];
    v0019 = qcar(v0019);
    if (equal(v0018, v0019)) goto v0124;
    v0019 = stack[0];
    v0019 = qcar(v0019);
    v0018 = v0207;
    v0019 = cons(v0019, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0013;
    env = stack[-2];
    v0207 = v0019;
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    stack[0] = v0019;
    goto v0044;

v0124:
    v0018 = v0207;
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0018, v0019);
    }

v0166:
    v0019 = qvalue(elt(env, 1)); /* t */
    goto v0065;

v0122:
    v0018 = v0207;
    v0019 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0018, v0019);
    }
/* error exit handlers */
v0013:
    popv(3);
    return nil;
}



/* Code for ibalp_var!-set */

static Lisp_Object MS_CDECL CC_ibalp_varKset(Lisp_Object env, int nargs,
                         Lisp_Object v0040, Lisp_Object v0005,
                         Lisp_Object v0002, Lisp_Object v0084, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0218, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ibalp_var-set");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_var-set");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0084,v0002,v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0040,v0005,v0002,v0084);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0084;
    stack[-1] = v0002;
    stack[-2] = v0005;
    stack[-3] = v0040;
/* end of prologue */
    v0218 = stack[-3];
    v0006 = qcdr(v0218);
    v0218 = stack[-2];
    fn = elt(env, 1); /* setcar */
    v0218 = (*qfn2(fn))(qenv(fn), v0006, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-4];
    v0218 = stack[-3];
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0006 = qcdr(v0218);
    v0218 = stack[-1];
    fn = elt(env, 1); /* setcar */
    v0218 = (*qfn2(fn))(qenv(fn), v0006, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-4];
    v0218 = stack[-3];
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0006 = qcdr(v0218);
    v0218 = stack[0];
    fn = elt(env, 1); /* setcar */
    v0218 = (*qfn2(fn))(qenv(fn), v0006, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-4];
    v0218 = stack[-3];
    v0218 = qcar(v0218);
    stack[0] = v0218;
    v0006 = stack[-2];
    v0218 = (Lisp_Object)1; /* 0 */
    v0218 = Leqn(nil, v0006, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-4];
    if (v0218 == nil) goto v0033;
    v0218 = stack[-3];
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcar(v0218);
    goto v0207;

v0207:
    v0006 = v0218;
    v0218 = stack[0];
    fn = elt(env, 2); /* ibalp_var!-satlist */
    v0218 = (*qfn2(fn))(qenv(fn), v0006, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-4];
    v0006 = stack[-2];
    v0218 = (Lisp_Object)17; /* 1 */
    v0218 = Leqn(nil, v0006, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-4];
    if (v0218 == nil) goto v0225;
    v0218 = stack[-3];
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcar(v0218);
    goto v0138;

v0138:
    v0006 = v0218;
    v0218 = stack[-2];
    fn = elt(env, 3); /* ibalp_var!-unsatlist */
    v0218 = (*qfn2(fn))(qenv(fn), v0006, v0218);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-4];
    v0218 = stack[-3];
    fn = elt(env, 4); /* ibalp_var!-wclist */
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-4];
    stack[-1] = v0218;
    v0218 = stack[-3];
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    stack[0] = qcdr(v0218);
    v0218 = stack[-3];
    fn = elt(env, 5); /* ibalp_calcmom */
    v0218 = (*qfn1(fn))(qenv(fn), v0218);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    env = stack[-4];
    fn = elt(env, 1); /* setcar */
    v0218 = (*qfn2(fn))(qenv(fn), stack[0], v0218);
    nil = C_nil;
    if (exception_pending()) goto v0195;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v0225:
    v0218 = stack[-3];
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcar(v0218);
    goto v0138;

v0033:
    v0218 = stack[-3];
    v0218 = qcdr(v0218);
    v0218 = qcdr(v0218);
    v0218 = qcar(v0218);
    goto v0207;
/* error exit handlers */
v0195:
    popv(5);
    return nil;
}



/* Code for ratpoly_1 */

static Lisp_Object MS_CDECL CC_ratpoly_1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0097, v0119;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "ratpoly_1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ratpoly_1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0119 = (Lisp_Object)17; /* 1 */
    v0097 = (Lisp_Object)17; /* 1 */
    return cons(v0119, v0097);
}



/* Code for reln */

static Lisp_Object CC_reln(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0043, v0099;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reln");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
    stack[-1] = v0040;
/* end of prologue */
    v0043 = elt(env, 1); /* "<reln>" */
    fn = elt(env, 6); /* printout */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0043 = elt(env, 2); /* "<" */
    v0043 = Lprinc(nil, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0043 = stack[0];
    v0043 = Lprinc(nil, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0043 = elt(env, 3); /* "/>" */
    v0043 = Lprinc(nil, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0099 = qvalue(elt(env, 4)); /* indent */
    v0043 = (Lisp_Object)49; /* 3 */
    v0043 = plus2(v0099, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0043; /* indent */
    v0043 = stack[-1];
    fn = elt(env, 7); /* multi_elem */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    v0099 = qvalue(elt(env, 4)); /* indent */
    v0043 = (Lisp_Object)49; /* 3 */
    v0043 = difference2(v0099, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-2];
    qvalue(elt(env, 4)) = v0043; /* indent */
    v0043 = elt(env, 5); /* "</reln>" */
    fn = elt(env, 6); /* printout */
    v0043 = (*qfn1(fn))(qenv(fn), v0043);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    v0043 = nil;
    { popv(3); return onevalue(v0043); }
/* error exit handlers */
v0046:
    popv(3);
    return nil;
}



/* Code for diffsq */

static Lisp_Object CC_diffsq(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0124;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for diffsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0005;
    stack[-2] = v0040;
/* end of prologue */
    v0023 = stack[-2];
    v0124 = qcar(v0023);
    v0023 = stack[-1];
    fn = elt(env, 1); /* difff */
    stack[-3] = (*qfn2(fn))(qenv(fn), v0124, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    stack[0] = stack[-2];
    v0023 = stack[-2];
    v0124 = qcdr(v0023);
    v0023 = stack[-1];
    fn = elt(env, 1); /* difff */
    v0023 = (*qfn2(fn))(qenv(fn), v0124, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    fn = elt(env, 2); /* multsq */
    v0023 = (*qfn2(fn))(qenv(fn), stack[0], v0023);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    fn = elt(env, 3); /* negsq */
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v0023);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    v0124 = (Lisp_Object)17; /* 1 */
    v0023 = stack[-2];
    v0023 = qcdr(v0023);
    v0023 = cons(v0124, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0126;
    env = stack[-4];
    {
        Lisp_Object v0136 = stack[0];
        popv(5);
        fn = elt(env, 2); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0136, v0023);
    }
/* error exit handlers */
v0126:
    popv(5);
    return nil;
}



/* Code for take!-realpart */

static Lisp_Object CC_takeKrealpart(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for take-realpart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0040;
/* end of prologue */
    v0122 = stack[0];
    v0122 = qcar(v0122);
    fn = elt(env, 1); /* repartf */
    v0127 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    v0122 = stack[0];
    v0122 = qcdr(v0122);
    popv(1);
    return cons(v0127, v0122);
/* error exit handlers */
v0027:
    popv(1);
    return nil;
}



/* Code for sc_minussq */

static Lisp_Object CC_sc_minussq(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0052;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_minussq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0052 = v0040;
/* end of prologue */
    v0052 = qcar(v0052);
    {
        fn = elt(env, 1); /* minusf */
        return (*qfn1(fn))(qenv(fn), v0052);
    }
}



/* Code for ordop2 */

static Lisp_Object CC_ordop2(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051, v0087, v0101, v0123, v0024;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordop2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0123 = v0005;
    v0024 = v0040;
/* end of prologue */
    v0051 = qvalue(elt(env, 1)); /* kord!* */
    v0101 = v0051;
    goto v0044;

v0044:
    v0051 = v0101;
    if (v0051 == nil) goto v0127;
    v0087 = v0024;
    v0051 = v0101;
    v0051 = qcar(v0051);
    if (v0087 == v0051) goto v0198;
    v0087 = v0123;
    v0051 = v0101;
    v0051 = qcar(v0051);
    if (v0087 == v0051) goto v0041;
    v0051 = v0101;
    v0051 = qcdr(v0051);
    v0101 = v0051;
    goto v0044;

v0041:
    v0051 = qvalue(elt(env, 3)); /* nil */
    return onevalue(v0051);

v0198:
    v0051 = qvalue(elt(env, 2)); /* t */
    return onevalue(v0051);

v0127:
    v0051 = v0024;
    v0087 = v0123;
    {
        fn = elt(env, 4); /* ordp */
        return (*qfn2(fn))(qenv(fn), v0051, v0087);
    }
}



/* Code for mksetq */

static Lisp_Object CC_mksetq(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0208, v0020, v0021, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mksetq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0020 = v0005;
    v0021 = v0040;
/* end of prologue */
    v0208 = v0021;
    if (!consp(v0208)) goto v0097;
    v0208 = v0021;
    v0022 = qcar(v0208);
    v0208 = elt(env, 2); /* setfn */
    v0208 = get(v0022, v0208);
    env = stack[0];
    v0022 = v0208;
    if (v0208 == nil) goto v0124;
    v0208 = v0022;
        popv(1);
        return Lapply2(nil, 3, v0208, v0021, v0020);

v0124:
    v0020 = v0021;
    v0208 = elt(env, 3); /* "assignment argument" */
    fn = elt(env, 4); /* typerr */
    v0208 = (*qfn2(fn))(qenv(fn), v0020, v0208);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    v0208 = nil;
    { popv(1); return onevalue(v0208); }

v0097:
    v0208 = elt(env, 1); /* setq */
    popv(1);
    return list3(v0208, v0021, v0020);
/* error exit handlers */
v0160:
    popv(1);
    return nil;
}



/* Code for mo_from_a */

static Lisp_Object CC_mo_from_a(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0213, v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_from_a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0040;
/* end of prologue */
    stack[0] = stack[-3];
    v0213 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-5];
    v0213 = Lmember(nil, stack[0], v0213);
    if (v0213 == nil) goto v0027;
    v0213 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_all_names */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-5];
    stack[-4] = v0213;
    v0213 = stack[-4];
    if (v0213 == nil) goto v0229;
    v0213 = stack[-4];
    v0213 = qcar(v0213);
    v0088 = v0213;
    v0213 = stack[-3];
    if (equal(v0088, v0213)) goto v0023;
    v0213 = (Lisp_Object)1; /* 0 */
    goto v0024;

v0024:
    v0213 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-5];
    stack[-1] = v0213;
    stack[-2] = v0213;
    goto v0025;

v0025:
    v0213 = stack[-4];
    v0213 = qcdr(v0213);
    stack[-4] = v0213;
    v0213 = stack[-4];
    if (v0213 == nil) goto v0033;
    stack[0] = stack[-1];
    v0213 = stack[-4];
    v0213 = qcar(v0213);
    v0088 = v0213;
    v0213 = stack[-3];
    if (equal(v0088, v0213)) goto v0202;
    v0213 = (Lisp_Object)1; /* 0 */
    goto v0159;

v0159:
    v0213 = ncons(v0213);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-5];
    v0213 = Lrplacd(nil, stack[0], v0213);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-5];
    v0213 = stack[-1];
    v0213 = qcdr(v0213);
    stack[-1] = v0213;
    goto v0025;

v0202:
    v0213 = (Lisp_Object)17; /* 1 */
    goto v0159;

v0033:
    v0213 = stack[-2];
    goto v0099;

v0099:
    fn = elt(env, 5); /* mo!=shorten */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    env = stack[-5];
    stack[0] = v0213;
    fn = elt(env, 6); /* mo!=deglist */
    v0213 = (*qfn1(fn))(qenv(fn), v0213);
    nil = C_nil;
    if (exception_pending()) goto v0171;
    {
        Lisp_Object v0231 = stack[0];
        popv(6);
        return cons(v0231, v0213);
    }

v0023:
    v0213 = (Lisp_Object)17; /* 1 */
    goto v0024;

v0229:
    v0213 = qvalue(elt(env, 3)); /* nil */
    goto v0099;

v0027:
    v0088 = stack[-3];
    v0213 = elt(env, 2); /* "dpoly variable" */
    {
        popv(6);
        fn = elt(env, 7); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0088, v0213);
    }
/* error exit handlers */
v0171:
    popv(6);
    return nil;
}



/* Code for pst_termnodep */

static Lisp_Object CC_pst_termnodep(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0127;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pst_termnodep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0122 = v0040;
/* end of prologue */
    v0127 = qcdr(v0122);
    v0122 = (Lisp_Object)1; /* 0 */
    v0122 = *(Lisp_Object *)((char *)v0127 + (CELL-TAG_VECTOR) + ((int32_t)v0122/(16/CELL)));
    v0122 = qcdr(v0122);
    v0122 = (v0122 == nil ? lisp_true : nil);
    return onevalue(v0122);
}



/* Code for delete_from_alglist */

static Lisp_Object CC_delete_from_alglist(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0163, v0198;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delete_from_alglist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
    v0198 = v0040;
/* end of prologue */
    v0163 = stack[0];
    if (v0163 == nil) goto v0052;
    v0163 = stack[0];
    fn = elt(env, 2); /* remhash */
    v0163 = (*qfn2(fn))(qenv(fn), v0198, v0163);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    { Lisp_Object res = stack[0]; popv(1); return onevalue(res); }

v0052:
    v0163 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v0163); }
/* error exit handlers */
v0065:
    popv(1);
    return nil;
}



/* Code for lx2xx */

static Lisp_Object CC_lx2xx(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013, v0037;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lx2xx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0040;
/* end of prologue */
    v0013 = stack[-2];
    if (!consp(v0013)) goto v0027;
    v0013 = stack[-2];
    v0013 = qcar(v0013);
    v0013 = (consp(v0013) ? nil : lisp_true);
    goto v0028;

v0028:
    if (v0013 == nil) goto v0108;
    v0013 = qvalue(elt(env, 1)); /* t */
    goto v0120;

v0120:
    if (!(v0013 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v0013 = stack[-2];
    v0013 = qcdr(v0013);
    v0013 = qcar(v0013);
    stack[-3] = v0013;
    v0013 = stack[-3];
    fn = elt(env, 2); /* lastnondomain */
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-4];
    v0013 = qcdr(v0013);
    stack[-1] = v0013;
    v0013 = stack[-2];
    stack[0] = qcar(v0013);
    v0037 = stack[-1];
    v0013 = stack[-3];
    fn = elt(env, 3); /* delet */
    v0013 = (*qfn2(fn))(qenv(fn), v0037, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-4];
    fn = elt(env, 4); /* xxsort */
    v0037 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    env = stack[-4];
    v0013 = stack[-1];
    v0037 = Lappend(nil, v0037, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0159;
    v0013 = stack[-2];
    v0013 = qcdr(v0013);
    v0013 = qcdr(v0013);
    {
        Lisp_Object v0202 = stack[0];
        popv(5);
        return list2star(v0202, v0037, v0013);
    }

v0108:
    v0013 = stack[-2];
    v0013 = qcar(v0013);
    if (!consp(v0013)) goto v0086;
    v0013 = stack[-2];
    v0013 = qcar(v0013);
    v0013 = qcar(v0013);
    v0013 = (consp(v0013) ? nil : lisp_true);
    goto v0120;

v0086:
    v0013 = qvalue(elt(env, 1)); /* t */
    goto v0120;

v0027:
    v0013 = qvalue(elt(env, 1)); /* t */
    goto v0028;
/* error exit handlers */
v0159:
    popv(5);
    return nil;
}



/* Code for ev_revgradlexcomp */

static Lisp_Object CC_ev_revgradlexcomp(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0207, v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ev_revgradlexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0005;
    stack[-2] = v0040;
/* end of prologue */

v0197:
    v0207 = stack[-2];
    if (v0207 == nil) goto v0097;
    v0207 = stack[-2];
    v0090 = qcar(v0207);
    v0207 = stack[-1];
    v0207 = qcar(v0207);
    fn = elt(env, 1); /* iequal */
    v0207 = (*qfn2(fn))(qenv(fn), v0090, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    if (v0207 == nil) goto v0127;
    v0207 = stack[-2];
    v0090 = qcdr(v0207);
    v0207 = stack[-1];
    v0207 = qcdr(v0207);
    stack[-2] = v0090;
    stack[-1] = v0207;
    goto v0197;

v0127:
    v0207 = stack[-2];
    fn = elt(env, 2); /* ev_tdeg */
    v0207 = (*qfn1(fn))(qenv(fn), v0207);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    stack[-3] = v0207;
    v0207 = stack[-1];
    fn = elt(env, 2); /* ev_tdeg */
    v0207 = (*qfn1(fn))(qenv(fn), v0207);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    stack[0] = v0207;
    v0090 = stack[-3];
    v0207 = stack[0];
    fn = elt(env, 1); /* iequal */
    v0207 = (*qfn2(fn))(qenv(fn), v0090, v0207);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-4];
    if (v0207 == nil) goto v0035;
    v0090 = stack[-2];
    v0207 = stack[-1];
    {
        popv(5);
        fn = elt(env, 3); /* ev_invlexcomp */
        return (*qfn2(fn))(qenv(fn), v0090, v0207);
    }

v0035:
    v0090 = stack[-3];
    v0207 = stack[0];
    if (((int32_t)(v0090)) > ((int32_t)(v0207))) goto v0140;
    v0207 = (Lisp_Object)-15; /* -1 */
    { popv(5); return onevalue(v0207); }

v0140:
    v0207 = (Lisp_Object)17; /* 1 */
    { popv(5); return onevalue(v0207); }

v0097:
    v0207 = (Lisp_Object)1; /* 0 */
    { popv(5); return onevalue(v0207); }
/* error exit handlers */
v0115:
    popv(5);
    return nil;
}



/* Code for unaryrd */

static Lisp_Object MS_CDECL CC_unaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0117;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "unaryrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for unaryrd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    fn = elt(env, 1); /* mathml */
    v0117 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-1];
    stack[0] = v0117;
    fn = elt(env, 2); /* lex */
    v0117 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    v0117 = stack[0];
    popv(2);
    return ncons(v0117);
/* error exit handlers */
v0119:
    popv(2);
    return nil;
}



/* Code for cr!:prep */

static Lisp_Object CC_crTprep(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cr:prep");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0040;
/* end of prologue */
    v0041 = elt(env, 1); /* !:rd!: */
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    v0042 = qcar(v0042);
    v0042 = cons(v0041, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    stack[-1] = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    v0041 = elt(env, 1); /* !:rd!: */
    v0042 = stack[0];
    v0042 = qcdr(v0042);
    v0042 = qcdr(v0042);
    v0042 = cons(v0041, v0042);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    fn = elt(env, 2); /* rd!:prep */
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    v0042 = cons(stack[-1], v0042);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 3); /* crprep1 */
        return (*qfn1(fn))(qenv(fn), v0042);
    }
/* error exit handlers */
v0025:
    popv(3);
    return nil;
}



/* Code for take!-impart */

static Lisp_Object CC_takeKimpart(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0122, v0127;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for take-impart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0040;
/* end of prologue */
    v0122 = stack[0];
    v0122 = qcar(v0122);
    fn = elt(env, 1); /* impartf */
    v0127 = (*qfn1(fn))(qenv(fn), v0122);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    v0122 = stack[0];
    v0122 = qcdr(v0122);
    popv(1);
    return cons(v0127, v0122);
/* error exit handlers */
v0027:
    popv(1);
    return nil;
}



/* Code for oprinla */

static Lisp_Object CC_oprinla(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0050, v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for oprinla");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0050 = v0040;
/* end of prologue */
    v0051 = v0050;
    v0049 = elt(env, 1); /* lapr */
    v0049 = get(v0051, v0049);
    env = stack[0];
    v0051 = v0049;
    if (v0049 == nil) goto v0117;
    v0049 = v0051;
    fn = elt(env, 4); /* prin2la */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    goto v0044;

v0044:
    v0049 = nil;
    { popv(1); return onevalue(v0049); }

v0117:
    v0049 = v0050;
    if (!symbolp(v0049)) v0049 = nil;
    else { v0049 = qfastgets(v0049);
           if (v0049 != nil) { v0049 = elt(v0049, 37); /* prtch */
#ifdef RECORD_GET
             if (v0049 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0049 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0049 == SPID_NOPROP) v0049 = nil; }}
#endif
    v0051 = v0049;
    if (v0049 == nil) goto v0230;
    v0049 = v0051;
    fn = elt(env, 4); /* prin2la */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    goto v0044;

v0230:
    v0051 = v0050;
    v0049 = elt(env, 2); /* lapop */
    v0049 = get(v0051, v0049);
    env = stack[0];
    v0051 = v0049;
    if (v0049 == nil) goto v0048;
    v0049 = v0051;
    fn = elt(env, 4); /* prin2la */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    env = stack[0];
    v0049 = elt(env, 3); /* !  */
    fn = elt(env, 4); /* prin2la */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    goto v0044;

v0048:
    v0049 = v0050;
    fn = elt(env, 5); /* prinlatom */
    v0049 = (*qfn1(fn))(qenv(fn), v0049);
    nil = C_nil;
    if (exception_pending()) goto v0087;
    goto v0044;
/* error exit handlers */
v0087:
    popv(1);
    return nil;
}



/* Code for setel1 */

static Lisp_Object MS_CDECL CC_setel1(Lisp_Object env, int nargs,
                         Lisp_Object v0040, Lisp_Object v0005,
                         Lisp_Object v0002, Lisp_Object v0084, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0141, v0210, v0168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "setel1");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setel1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0084,v0002,v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0040,v0005,v0002,v0084);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0084;
    stack[-1] = v0002;
    stack[-2] = v0005;
    stack[-3] = v0040;
/* end of prologue */

v0118:
    v0141 = stack[-2];
    v0141 = qcar(v0141);
    v0141 = integerp(v0141);
    if (v0141 == nil) goto v0027;
    v0141 = stack[-2];
    v0210 = qcar(v0141);
    v0141 = stack[0];
    v0141 = qcar(v0141);
    v0141 = (Lisp_Object)geq2(v0210, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    v0141 = v0141 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0141 == nil)) goto v0123;
    v0141 = stack[-2];
    v0210 = qcar(v0141);
    v0141 = (Lisp_Object)1; /* 0 */
    v0141 = (Lisp_Object)lessp2(v0210, v0141);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    v0141 = v0141 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0141 == nil)) goto v0123;
    v0141 = stack[-2];
    v0141 = qcdr(v0141);
    if (v0141 == nil) goto v0160;
    v0210 = stack[-3];
    v0141 = stack[-2];
    v0141 = qcar(v0141);
    v0141 = *(Lisp_Object *)((char *)v0210 + (CELL-TAG_VECTOR) + ((int32_t)v0141/(16/CELL)));
    stack[-3] = v0141;
    v0141 = stack[-2];
    v0141 = qcdr(v0141);
    stack[-2] = v0141;
    v0141 = stack[0];
    v0141 = qcdr(v0141);
    stack[0] = v0141;
    goto v0118;

v0160:
    v0168 = stack[-3];
    v0141 = stack[-2];
    v0210 = qcar(v0141);
    v0141 = stack[-1];
    *(Lisp_Object *)((char *)v0168 + (CELL-TAG_VECTOR) + ((int32_t)v0210/(16/CELL))) = v0141;
    { popv(5); return onevalue(v0141); }

v0123:
    v0168 = elt(env, 2); /* rlisp */
    v0210 = (Lisp_Object)369; /* 23 */
    v0141 = elt(env, 3); /* "Array out of bounds" */
    {
        popv(5);
        fn = elt(env, 4); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0168, v0210, v0141);
    }

v0027:
    v0141 = stack[-2];
    v0210 = qcar(v0141);
    v0141 = elt(env, 1); /* "array index" */
    {
        popv(5);
        fn = elt(env, 5); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0210, v0141);
    }
/* error exit handlers */
v0133:
    popv(5);
    return nil;
}



/* Code for reduce!-degree!-mod!-p */

static Lisp_Object CC_reduceKdegreeKmodKp(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0225, v0116, v0236;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-degree-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0005;
    stack[-1] = v0040;
/* end of prologue */
    v0225 = stack[-1];
    v0225 = qcar(v0225);
    v0225 = qcdr(v0225);
    {   int32_t w = int_of_fixnum(v0225);
        if (w != 0) w = current_modulus - w;
        v0116 = fixnum_of_int(w);
    }
    v0225 = stack[0];
    v0225 = qcar(v0225);
    v0225 = qcdr(v0225);
    v0225 = Lmodular_quotient(nil, v0116, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    stack[-2] = v0225;
    v0225 = stack[-1];
    v0225 = qcar(v0225);
    v0225 = qcar(v0225);
    v0116 = qcdr(v0225);
    v0225 = stack[0];
    v0225 = qcar(v0225);
    v0225 = qcar(v0225);
    v0225 = qcdr(v0225);
    v0225 = (Lisp_Object)(int32_t)((int32_t)v0116 - (int32_t)v0225 + TAG_FIXNUM);
    v0236 = v0225;
    v0116 = v0236;
    v0225 = (Lisp_Object)1; /* 0 */
    if (v0116 == v0225) goto v0087;
    v0225 = stack[-1];
    stack[-1] = qcdr(v0225);
    v0225 = stack[0];
    v0225 = qcar(v0225);
    v0225 = qcar(v0225);
    v0225 = qcar(v0225);
    v0116 = v0236;
    fn = elt(env, 1); /* mksp */
    v0116 = (*qfn2(fn))(qenv(fn), v0225, v0116);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    v0225 = stack[-2];
    v0116 = cons(v0116, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    v0225 = stack[0];
    v0225 = qcdr(v0225);
    fn = elt(env, 2); /* times!-term!-mod!-p */
    v0225 = (*qfn2(fn))(qenv(fn), v0116, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    {
        Lisp_Object v0138 = stack[-1];
        popv(4);
        fn = elt(env, 3); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0138, v0225);
    }

v0087:
    v0225 = stack[-1];
    stack[-1] = qcdr(v0225);
    v0225 = stack[0];
    v0116 = qcdr(v0225);
    v0225 = stack[-2];
    fn = elt(env, 4); /* multiply!-by!-constant!-mod!-p */
    v0225 = (*qfn2(fn))(qenv(fn), v0116, v0225);
    nil = C_nil;
    if (exception_pending()) goto v0206;
    env = stack[-3];
    {
        Lisp_Object v0139 = stack[-1];
        popv(4);
        fn = elt(env, 3); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0139, v0225);
    }
/* error exit handlers */
v0206:
    popv(4);
    return nil;
}



/* Code for pasf_smwmkatl */

static Lisp_Object MS_CDECL CC_pasf_smwmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0040, Lisp_Object v0005,
                         Lisp_Object v0002, Lisp_Object v0084, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0229, v0162, v0137, v0049, v0050;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "pasf_smwmkatl");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_smwmkatl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0162 = v0084;
    v0137 = v0002;
    v0049 = v0005;
    v0050 = v0040;
/* end of prologue */
    v0229 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v0229 == nil) goto v0177;
    v0229 = v0050;
    {
        fn = elt(env, 2); /* cl_susimkatl */
        return (*qfnn(fn))(qenv(fn), 4, v0229, v0049, v0137, v0162);
    }

v0177:
    v0229 = v0050;
    {
        fn = elt(env, 3); /* cl_smmkatl */
        return (*qfnn(fn))(qenv(fn), 4, v0229, v0049, v0137, v0162);
    }
}



/* Code for row */

static Lisp_Object CC_row(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for row");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0040;
/* end of prologue */
    v0027 = stack[0];
    if (v0027 == nil) goto v0052;
    v0027 = stack[0];
    v0027 = qcar(v0027);
    fn = elt(env, 2); /* expression */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    env = stack[-1];
    v0027 = stack[0];
    v0027 = qcdr(v0027);
    v0027 = CC_row(env, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0045;
    goto v0052;

v0052:
    v0027 = nil;
    { popv(2); return onevalue(v0027); }
/* error exit handlers */
v0045:
    popv(2);
    return nil;
}



/* Code for spband_matrix */

static Lisp_Object CC_spband_matrix(Lisp_Object env,
                         Lisp_Object v0040, Lisp_Object v0005)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0250, v0251, v0252;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for spband_matrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0005,v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0040,v0005);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = v0005;
    stack[-8] = v0040;
/* end of prologue */
    stack[0] = stack[-7];
    v0252 = elt(env, 1); /* spm */
    v0251 = stack[-7];
    v0250 = stack[-7];
    v0250 = list3(v0252, v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    fn = elt(env, 9); /* mkempspmat */
    v0250 = (*qfn2(fn))(qenv(fn), stack[0], v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    stack[-9] = v0250;
    v0250 = stack[-7];
    v0250 = integerp(v0250);
    if (!(v0250 == nil)) goto v0025;
    v0250 = elt(env, 2); /* "Error in spband_matrix(second argument): should be an integer." 
*/
    fn = elt(env, 10); /* rederr */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    goto v0025;

v0025:
    v0250 = stack[-8];
    if (!consp(v0250)) goto v0050;
    v0250 = stack[-8];
    v0251 = qcar(v0250);
    v0250 = elt(env, 3); /* list */
    if (v0251 == v0250) goto v0024;
    v0250 = elt(env, 4); /* "Error in spband_matrix(first argument): should be single value or list." 
*/
    fn = elt(env, 10); /* rederr */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    goto v0049;

v0049:
    v0250 = stack[-8];
    v0250 = Llength(nil, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    stack[-4] = v0250;
    v0250 = stack[-4];
    v0250 = Levenp(nil, v0250);
    env = stack[-10];
    if (v0250 == nil) goto v0013;
    v0250 = elt(env, 5); /* "Error in spband matrix(first argument): number of elements must be odd." 
*/
    fn = elt(env, 10); /* rederr */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    goto v0013;

v0013:
    stack[0] = elt(env, 6); /* quotient */
    v0250 = stack[-4];
    v0251 = add1(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    v0250 = (Lisp_Object)33; /* 2 */
    v0250 = list3(stack[0], v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    fn = elt(env, 11); /* reval */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    stack[-3] = v0250;
    v0250 = stack[-3];
    v0250 = integerp(v0250);
    if (v0250 == nil) goto v0138;
    v0250 = stack[-3];
    v0251 = v0250;
    goto v0133;

v0133:
    v0250 = stack[-7];
    v0250 = (Lisp_Object)greaterp2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    v0250 = v0250 ? lisp_true : nil;
    env = stack[-10];
    if (v0250 == nil) goto v0210;
    v0250 = elt(env, 7); /* "Error in spband_matrix: too many elements. Band matrix is overflowing." 
*/
    fn = elt(env, 10); /* rederr */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    goto v0210;

v0210:
    v0250 = (Lisp_Object)33; /* 2 */
    stack[-5] = v0250;
    v0250 = (Lisp_Object)17; /* 1 */
    stack[-2] = v0250;
    goto v0157;

v0157:
    v0251 = stack[-7];
    v0250 = stack[-2];
    v0250 = difference2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    v0250 = Lminusp(nil, v0250);
    env = stack[-10];
    if (!(v0250 == nil)) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    v0251 = stack[-2];
    v0250 = stack[-3];
    v0250 = (Lisp_Object)lesseq2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    v0250 = v0250 ? lisp_true : nil;
    env = stack[-10];
    if (v0250 == nil) goto v0004;
    v0250 = (Lisp_Object)17; /* 1 */
    stack[-6] = v0250;
    goto v0082;

v0082:
    v0251 = stack[-3];
    v0250 = stack[-2];
    v0251 = difference2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    v0250 = stack[-6];
    v0251 = plus2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    v0250 = (Lisp_Object)1; /* 0 */
    v0250 = (Lisp_Object)greaterp2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    v0250 = v0250 ? lisp_true : nil;
    env = stack[-10];
    if (v0250 == nil) goto v0254;
    v0251 = stack[-6];
    v0250 = stack[-7];
    v0250 = (Lisp_Object)lesseq2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    v0250 = v0250 ? lisp_true : nil;
    env = stack[-10];
    if (v0250 == nil) goto v0254;
    v0251 = stack[-3];
    v0250 = stack[-2];
    v0251 = difference2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    v0250 = stack[-6];
    v0251 = plus2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    v0250 = stack[-4];
    v0250 = (Lisp_Object)lesseq2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    v0250 = v0250 ? lisp_true : nil;
    env = stack[-10];
    if (v0250 == nil) goto v0254;
    v0252 = stack[-9];
    v0251 = stack[-2];
    v0250 = stack[-6];
    stack[-1] = list3(v0252, v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    stack[0] = stack[-8];
    v0251 = stack[-3];
    v0250 = stack[-2];
    v0251 = difference2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    v0250 = stack[-6];
    v0250 = plus2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    fn = elt(env, 12); /* nth */
    v0252 = (*qfn2(fn))(qenv(fn), stack[0], v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    v0251 = stack[-9];
    v0250 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 13); /* letmtr3 */
    v0250 = (*qfnn(fn))(qenv(fn), 4, stack[-1], v0252, v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    v0250 = stack[-6];
    v0250 = add1(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    stack[-6] = v0250;
    goto v0082;

v0254:
    v0251 = stack[-2];
    v0250 = stack[-3];
    v0250 = (Lisp_Object)greaterp2(v0251, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    v0250 = v0250 ? lisp_true : nil;
    env = stack[-10];
    if (v0250 == nil) goto v0255;
    v0250 = stack[-5];
    v0250 = add1(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    stack[-5] = v0250;
    goto v0255;

v0255:
    v0250 = stack[-2];
    v0250 = add1(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    stack[-2] = v0250;
    goto v0157;

v0004:
    v0250 = stack[-5];
    stack[-6] = v0250;
    goto v0082;

v0138:
    v0250 = stack[-3];
    fn = elt(env, 11); /* reval */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    v0251 = v0250;
    goto v0133;

v0024:
    v0250 = stack[-8];
    v0250 = qcdr(v0250);
    stack[-8] = v0250;
    goto v0049;

v0050:
    v0250 = stack[-8];
    v0250 = ncons(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0253;
    env = stack[-10];
    stack[-8] = v0250;
    goto v0049;
/* error exit handlers */
v0253:
    popv(11);
    return nil;
}



/* Code for xdegreecheck */

static Lisp_Object CC_xdegreecheck(Lisp_Object env,
                         Lisp_Object v0040)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0034, v0163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xdegreecheck");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0040);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0040);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0163 = v0040;
/* end of prologue */
    v0034 = qvalue(elt(env, 1)); /* xtruncate!* */
    if (v0034 == nil) goto v0053;
    v0034 = v0163;
    fn = elt(env, 3); /* xdegree */
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0198;
    env = stack[0];
    v0163 = qvalue(elt(env, 1)); /* xtruncate!* */
        popv(1);
        return Lgreaterp(nil, v0034, v0163);

v0053:
    v0034 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0034); }
/* error exit handlers */
v0198:
    popv(1);
    return nil;
}



setup_type const u16_setup[] =
{
    {"rread1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rread1},
    {"rnprep:",                 CC_rnprepT,     too_many_1,    wrong_no_1},
    {"prepsq*",                 CC_prepsqH,     too_many_1,    wrong_no_1},
    {"sfto_ucontentf",          CC_sfto_ucontentf,too_many_1,  wrong_no_1},
    {"cl_fvarl",                CC_cl_fvarl,    too_many_1,    wrong_no_1},
    {"ibalp_tvb",               too_few_2,      CC_ibalp_tvb,  wrong_no_2},
    {"ratpoly_tad",             CC_ratpoly_tad, too_many_1,    wrong_no_1},
    {"ofsf_clnegrel",           too_few_2,      CC_ofsf_clnegrel,wrong_no_2},
    {"applyrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_applyrd},
    {"rd:zerop:",               CC_rdTzeropT,   too_many_1,    wrong_no_1},
    {"freeoff",                 too_few_2,      CC_freeoff,    wrong_no_2},
    {"wedgek2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_wedgek2},
    {"indordp",                 too_few_2,      CC_indordp,    wrong_no_2},
    {"sfpx1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sfpx1},
    {"fs:times",                too_few_2,      CC_fsTtimes,   wrong_no_2},
    {"evaluatecoeffts",         too_few_2,      CC_evaluatecoeffts,wrong_no_2},
    {"qqe_arg-check",           CC_qqe_argKcheck,too_many_1,   wrong_no_1},
    {"pasf_vf",                 CC_pasf_vf,     too_many_1,    wrong_no_1},
    {"ibalp_var-wclist",        CC_ibalp_varKwclist,too_many_1,wrong_no_1},
    {"cgb_buch-ev_divides?",    too_few_2,      CC_cgb_buchKev_dividesW,wrong_no_2},
    {"diff-over-k-mod-p",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKoverKkKmodKp},
    {"ir2mml",                  CC_ir2mml,      too_many_1,    wrong_no_1},
    {"pfordp",                  too_few_2,      CC_pfordp,     wrong_no_2},
    {"delete-dups",             CC_deleteKdups, too_many_1,    wrong_no_1},
    {"fortranname",             CC_fortranname, too_many_1,    wrong_no_1},
    {"coposp",                  CC_coposp,      too_many_1,    wrong_no_1},
    {"factorial",               CC_factorial,   too_many_1,    wrong_no_1},
    {"in_list1",                too_few_2,      CC_in_list1,   wrong_no_2},
    {"mv-domainlist-*",         too_few_2,      CC_mvKdomainlistKH,wrong_no_2},
    {"dv_cambhead",             CC_dv_cambhead, too_many_1,    wrong_no_1},
    {"kernord-split",           too_few_2,      CC_kernordKsplit,wrong_no_2},
    {"ibalp_isinminclause",     too_few_2,      CC_ibalp_isinminclause,wrong_no_2},
    {"aex_lc",                  too_few_2,      CC_aex_lc,     wrong_no_2},
    {"ofsf_smwupdknowl",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smwupdknowl},
    {"resume",                  too_few_2,      CC_resume,     wrong_no_2},
    {"onoff",                   too_few_2,      CC_onoff,      wrong_no_2},
    {"evdif",                   too_few_2,      CC_evdif,      wrong_no_2},
    {"all_defined_vertex",      too_few_2,      CC_all_defined_vertex,wrong_no_2},
    {"set-global-mode",         CC_setKglobalKmode,too_many_1, wrong_no_1},
    {"groeb=weight",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebMweight},
    {"general-evaluate-mod-p",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_generalKevaluateKmodKp},
    {"delet",                   too_few_2,      CC_delet,      wrong_no_2},
    {"ibalp_var-set",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_varKset},
    {"ratpoly_1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratpoly_1},
    {"reln",                    too_few_2,      CC_reln,       wrong_no_2},
    {"diffsq",                  too_few_2,      CC_diffsq,     wrong_no_2},
    {"take-realpart",           CC_takeKrealpart,too_many_1,   wrong_no_1},
    {"sc_minussq",              CC_sc_minussq,  too_many_1,    wrong_no_1},
    {"ordop2",                  too_few_2,      CC_ordop2,     wrong_no_2},
    {"mksetq",                  too_few_2,      CC_mksetq,     wrong_no_2},
    {"mo_from_a",               CC_mo_from_a,   too_many_1,    wrong_no_1},
    {"pst_termnodep",           CC_pst_termnodep,too_many_1,   wrong_no_1},
    {"delete_from_alglist",     too_few_2,      CC_delete_from_alglist,wrong_no_2},
    {"lx2xx",                   CC_lx2xx,       too_many_1,    wrong_no_1},
    {"ev_revgradlexcomp",       too_few_2,      CC_ev_revgradlexcomp,wrong_no_2},
    {"unaryrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_unaryrd},
    {"cr:prep",                 CC_crTprep,     too_many_1,    wrong_no_1},
    {"take-impart",             CC_takeKimpart, too_many_1,    wrong_no_1},
    {"oprinla",                 CC_oprinla,     too_many_1,    wrong_no_1},
    {"setel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_setel1},
    {"reduce-degree-mod-p",     too_few_2,      CC_reduceKdegreeKmodKp,wrong_no_2},
    {"pasf_smwmkatl",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_pasf_smwmkatl},
    {"row",                     CC_row,         too_many_1,    wrong_no_1},
    {"spband_matrix",           too_few_2,      CC_spband_matrix,wrong_no_2},
    {"xdegreecheck",            CC_xdegreecheck,too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u16", (two_args *)"3604 6899146 8736913", 0}
};

/* end of generated code */
