
/* $destdir\u13.c        Machine generated C code */

/* Signature: 00000000 26-Mar-2013 */

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
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
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
#define _pi       3.14159265358979323846
#define _half_pi  1.57079632679489661923
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
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
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


/* Code for ibalp_hassimple */

static Lisp_Object CC_ibalp_hassimple(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0005, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_hassimple");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0005 = v0000;
/* end of prologue */
    stack[-1] = nil;
    stack[0] = v0005;
    goto v0007;

v0007:
    v0005 = stack[0];
    if (v0005 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0005 = stack[-1];
    if (!(v0005 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v0005 = stack[0];
    v0005 = qcar(v0005);
    v0006 = qcar(v0005);
    v0005 = stack[0];
    v0005 = qcar(v0005);
    v0005 = qcdr(v0005);
    v0005 = qcar(v0005);
    fn = elt(env, 2); /* ibalp_commonlenisone */
    v0005 = (*qfn2(fn))(qenv(fn), v0006, v0005);
    nil = C_nil;
    if (exception_pending()) goto v0008;
    env = stack[-2];
    if (v0005 == nil) goto v0009;
    v0005 = stack[0];
    v0005 = qcar(v0005);
    stack[-1] = v0005;
    goto v0009;

v0009:
    v0005 = stack[0];
    v0005 = qcdr(v0005);
    stack[0] = v0005;
    goto v0007;
/* error exit handlers */
v0008:
    popv(3);
    return nil;
}



/* Code for matrixrowrd */

static Lisp_Object MS_CDECL CC_matrixrowrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "matrixrowrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matrixrowrd");
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
    fn = elt(env, 2); /* mathml */
    v0012 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-1];
    v0013 = v0012;
    v0012 = v0013;
    if (v0012 == nil) goto v0015;
    stack[0] = v0013;
    v0012 = CC_matrixrowrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    {
        Lisp_Object v0016 = stack[0];
        popv(2);
        return cons(v0016, v0012);
    }

v0015:
    v0012 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0012); }
/* error exit handlers */
v0014:
    popv(2);
    return nil;
}



/* Code for isimplicit */

static Lisp_Object CC_isimplicit(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0020, v0021, v0005;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isimplicit");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0020 = elt(env, 1); /* implicit!  */
    v0020 = Lexplode(nil, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-2];
    stack[-1] = v0020;
    v0020 = stack[0];
    v0020 = Lexplode(nil, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    v0021 = v0020;
    v0020 = lisp_true;
    v0005 = v0020;
    goto v0023;

v0023:
    v0020 = v0005;
    if (v0020 == nil) { popv(3); return onevalue(v0005); }
    v0020 = stack[-1];
    if (v0020 == nil) { popv(3); return onevalue(v0005); }
    v0020 = v0021;
    v0005 = qcar(v0020);
    v0020 = stack[-1];
    v0020 = qcar(v0020);
    v0020 = (equal(v0005, v0020) ? lisp_true : nil);
    v0005 = v0020;
    v0020 = stack[-1];
    v0020 = qcdr(v0020);
    stack[-1] = v0020;
    v0020 = v0021;
    v0020 = qcdr(v0020);
    v0021 = v0020;
    goto v0023;
/* error exit handlers */
v0022:
    popv(3);
    return nil;
}



/* Code for vdpzero */

static Lisp_Object MS_CDECL CC_vdpzero(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0003;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "vdpzero");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdpzero");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* end of prologue */
    v0003 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* a2vdp */
        return (*qfn1(fn))(qenv(fn), v0003);
    }
}



/* Code for quotdd */

static Lisp_Object CC_quotdd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0033, v0034, v0035;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotdd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0000;
/* end of prologue */
    v0033 = stack[-1];
    if (!(!consp(v0033))) goto v0036;
    v0033 = stack[0];
    if (!consp(v0033)) goto v0037;
    v0033 = stack[0];
    v0033 = qcar(v0033);
    if (!symbolp(v0033)) v0033 = nil;
    else { v0033 = qfastgets(v0033);
           if (v0033 != nil) { v0033 = elt(v0033, 34); /* i2d */
#ifdef RECORD_GET
             if (v0033 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0033 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0033 == SPID_NOPROP) v0033 = nil; }}
#endif
    v0035 = v0033;
    if (v0033 == nil) goto v0006;
    v0034 = v0035;
    v0033 = stack[-1];
    v0033 = Lapply1(nil, v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    stack[-1] = v0033;
    goto v0036;

v0036:
    v0035 = stack[-1];
    v0034 = stack[0];
    v0033 = elt(env, 2); /* quotient */
    {
        popv(3);
        fn = elt(env, 3); /* dcombine */
        return (*qfnn(fn))(qenv(fn), 3, v0035, v0034, v0033);
    }

v0006:
    v0033 = stack[0];
    if (!consp(v0033)) goto v0039;
    v0033 = qvalue(elt(env, 1)); /* nil */
    goto v0040;

v0040:
    if (v0033 == nil) goto v0036;
    v0034 = v0035;
    v0033 = stack[0];
    v0033 = Lapply1(nil, v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    stack[0] = v0033;
    goto v0036;

v0039:
    v0033 = stack[-1];
    v0033 = qcar(v0033);
    if (!symbolp(v0033)) v0033 = nil;
    else { v0033 = qfastgets(v0033);
           if (v0033 != nil) { v0033 = elt(v0033, 34); /* i2d */
#ifdef RECORD_GET
             if (v0033 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0033 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0033 == SPID_NOPROP) v0033 = nil; }}
#endif
    v0035 = v0033;
    goto v0040;

v0037:
    v0034 = stack[-1];
    v0033 = stack[0];
    v0033 = Ldivide(nil, v0034, v0033);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-2];
    v0035 = v0033;
    v0033 = v0035;
    v0034 = qcdr(v0033);
    v0033 = (Lisp_Object)1; /* 0 */
    if (v0034 == v0033) goto v0016;
    v0033 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0033); }

v0016:
    v0033 = v0035;
    v0033 = qcar(v0033);
    { popv(3); return onevalue(v0033); }
/* error exit handlers */
v0038:
    popv(3);
    return nil;
}



/* Code for assert_declarestat */

static Lisp_Object MS_CDECL CC_assert_declarestat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_declarestat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_declarestat");
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
/* end of prologue */
    fn = elt(env, 3); /* assert_stat!-parse */
    v0041 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[0];
    v0023 = v0041;
    v0041 = qvalue(elt(env, 1)); /* !*assert */
    if (v0041 == nil) goto v0043;
    v0041 = v0023;
    {
        popv(1);
        fn = elt(env, 4); /* assert_declarestat1 */
        return (*qfn1(fn))(qenv(fn), v0041);
    }

v0043:
    v0041 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v0041); }
/* error exit handlers */
v0042:
    popv(1);
    return nil;
}



/* Code for dp_times_bcmo */

static Lisp_Object MS_CDECL CC_dp_times_bcmo(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0011,
                         Lisp_Object v0004, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0055, v0038;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dp_times_bcmo");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_times_bcmo");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0011,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0055 = v0004;
    stack[-5] = v0011;
    stack[-6] = v0000;
/* end of prologue */
    stack[-7] = v0055;
    v0055 = stack[-7];
    if (v0055 == nil) goto v0041;
    v0055 = stack[-7];
    v0055 = qcar(v0055);
    stack[-1] = v0055;
    v0038 = stack[-5];
    v0055 = stack[-1];
    v0055 = qcar(v0055);
    fn = elt(env, 2); /* mo_sum */
    stack[0] = (*qfn2(fn))(qenv(fn), v0038, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-8];
    v0038 = stack[-6];
    v0055 = stack[-1];
    v0055 = qcdr(v0055);
    fn = elt(env, 3); /* bc_prod */
    v0055 = (*qfn2(fn))(qenv(fn), v0038, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-8];
    v0055 = cons(stack[0], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-8];
    v0055 = ncons(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-8];
    stack[-3] = v0055;
    stack[-4] = v0055;
    goto v0007;

v0007:
    v0055 = stack[-7];
    v0055 = qcdr(v0055);
    stack[-7] = v0055;
    v0055 = stack[-7];
    if (v0055 == nil) { Lisp_Object res = stack[-4]; popv(9); return onevalue(res); }
    stack[-2] = stack[-3];
    v0055 = stack[-7];
    v0055 = qcar(v0055);
    stack[-1] = v0055;
    v0038 = stack[-5];
    v0055 = stack[-1];
    v0055 = qcar(v0055);
    fn = elt(env, 2); /* mo_sum */
    stack[0] = (*qfn2(fn))(qenv(fn), v0038, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-8];
    v0038 = stack[-6];
    v0055 = stack[-1];
    v0055 = qcdr(v0055);
    fn = elt(env, 3); /* bc_prod */
    v0055 = (*qfn2(fn))(qenv(fn), v0038, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-8];
    v0055 = cons(stack[0], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-8];
    v0055 = ncons(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-8];
    v0055 = Lrplacd(nil, stack[-2], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-8];
    v0055 = stack[-3];
    v0055 = qcdr(v0055);
    stack[-3] = v0055;
    goto v0007;

v0041:
    v0055 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v0055); }
/* error exit handlers */
v0056:
    popv(9);
    return nil;
}



/* Code for mvar_member */

static Lisp_Object CC_mvar_member(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0002, v0053, v0059;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mvar_member");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0053 = v0011;
    v0059 = v0000;
/* end of prologue */
    v0002 = v0059;
    v0032 = v0053;
    if (equal(v0002, v0032)) goto v0051;
    v0032 = v0053;
    if (!consp(v0032)) goto v0001;
    v0032 = v0059;
    v0002 = v0053;
    v0002 = qcdr(v0002);
    {
        fn = elt(env, 3); /* arglist_member */
        return (*qfn2(fn))(qenv(fn), v0032, v0002);
    }

v0001:
    v0032 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v0032);

v0051:
    v0032 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0032);
}



/* Code for b!:ordexn */

static Lisp_Object CC_bTordexn(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0066, v0067;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for b:ordexn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0011;
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    stack[-3] = nil;
    goto v0043;

v0043:
    v0066 = stack[-1];
    if (v0066 == nil) goto v0012;
    v0067 = stack[-2];
    v0066 = stack[-1];
    v0066 = qcar(v0066);
    if (equal(v0067, v0066)) goto v0068;
    v0066 = stack[-2];
    if (v0066 == nil) goto v0069;
    v0067 = stack[-2];
    v0066 = stack[-1];
    v0066 = qcar(v0066);
    v0066 = (Lisp_Object)greaterp2(v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    v0066 = v0066 ? lisp_true : nil;
    env = stack[-4];
    if (v0066 == nil) goto v0069;
    v0067 = stack[-2];
    v0066 = stack[-3];
    v0066 = cons(v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-4];
    v0067 = Lreverse(nil, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-4];
    v0066 = stack[-1];
    v0066 = Lappend(nil, v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    {
        Lisp_Object v0071 = stack[0];
        popv(5);
        return cons(v0071, v0066);
    }

v0069:
    v0066 = stack[-1];
    v0067 = qcar(v0066);
    v0066 = stack[-3];
    v0066 = cons(v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-4];
    stack[-3] = v0066;
    v0066 = stack[-1];
    v0066 = qcdr(v0066);
    stack[-1] = v0066;
    v0066 = stack[0];
    v0066 = (v0066 == nil ? lisp_true : nil);
    stack[0] = v0066;
    goto v0043;

v0068:
    v0066 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0066); }

v0012:
    v0067 = stack[-2];
    v0066 = stack[-3];
    v0066 = cons(v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    env = stack[-4];
    v0066 = Lreverse(nil, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0070;
    {
        Lisp_Object v0056 = stack[0];
        popv(5);
        return cons(v0056, v0066);
    }
/* error exit handlers */
v0070:
    popv(5);
    return nil;
}



/* Code for difference!-mod!-p */

static Lisp_Object CC_differenceKmodKp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for difference-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0058 = v0011;
    v0041 = v0000;
/* end of prologue */
    stack[0] = v0041;
    fn = elt(env, 1); /* minus!-mod!-p */
    v0058 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    {
        Lisp_Object v0073 = stack[0];
        popv(2);
        fn = elt(env, 2); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v0073, v0058);
    }
/* error exit handlers */
v0042:
    popv(2);
    return nil;
}



/* Code for janettreefind */

static Lisp_Object CC_janettreefind(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0084, v0085;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for janettreefind");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0000;
/* end of prologue */
    v0084 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    if (v0084 == nil) goto v0019;
    stack[-5] = nil;
    v0084 = qvalue(elt(env, 1)); /* fluidbibasisjanettreerootnode */
    stack[-3] = v0084;
    v0085 = stack[-4];
    v0084 = (Lisp_Object)1; /* 0 */
    v0084 = *(Lisp_Object *)((char *)v0085 + (CELL-TAG_VECTOR) + ((int32_t)v0084/(16/CELL)));
    stack[-2] = v0084;
    v0084 = (Lisp_Object)17; /* 1 */
    stack[-1] = v0084;
    goto v0002;

v0002:
    v0085 = stack[-2];
    v0084 = (Lisp_Object)1; /* 0 */
    if (!(((int32_t)(v0085)) > ((int32_t)(v0084)))) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }

v0030:
    v0084 = stack[-3];
    v0084 = qcar(v0084);
    stack[0] = qcar(v0084);
    v0085 = stack[-4];
    v0084 = stack[-1];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0084 = (*qfn2(fn))(qenv(fn), v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    v0084 = (Lisp_Object)lessp2(stack[0], v0084);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    v0084 = v0084 ? lisp_true : nil;
    env = stack[-6];
    if (v0084 == nil) goto v0087;
    v0084 = stack[-3];
    v0084 = qcdr(v0084);
    v0084 = qcar(v0084);
    if (v0084 == nil) goto v0087;
    v0084 = stack[-3];
    v0084 = qcdr(v0084);
    v0084 = qcar(v0084);
    stack[-3] = v0084;
    goto v0030;

v0087:
    v0084 = stack[-3];
    v0084 = qcar(v0084);
    stack[0] = qcar(v0084);
    v0085 = stack[-4];
    v0084 = stack[-1];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0084 = (*qfn2(fn))(qenv(fn), v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    if (equal(stack[0], v0084)) goto v0069;
    v0084 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0084;
    goto v0002;

v0069:
    v0084 = stack[-3];
    v0084 = qcdr(v0084);
    v0084 = qcdr(v0084);
    if (v0084 == nil) goto v0088;
    stack[0] = stack[-2];
    v0085 = stack[-4];
    v0084 = stack[-1];
    fn = elt(env, 3); /* monomgetvariabledegree */
    v0084 = (*qfn2(fn))(qenv(fn), v0085, v0084);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-6];
    v0084 = (Lisp_Object)(int32_t)((int32_t)stack[0] - (int32_t)v0084 + TAG_FIXNUM);
    stack[-2] = v0084;
    v0084 = stack[-1];
    v0084 = (Lisp_Object)((int32_t)(v0084) + 0x10);
    stack[-1] = v0084;
    v0084 = stack[-3];
    v0084 = qcdr(v0084);
    v0084 = qcdr(v0084);
    stack[-3] = v0084;
    goto v0002;

v0088:
    v0084 = (Lisp_Object)1; /* 0 */
    stack[-2] = v0084;
    v0084 = stack[-3];
    v0084 = qcar(v0084);
    v0084 = qcdr(v0084);
    stack[-5] = v0084;
    goto v0002;

v0019:
    v0084 = qvalue(elt(env, 2)); /* nil */
    { popv(7); return onevalue(v0084); }
/* error exit handlers */
v0086:
    popv(7);
    return nil;
}



/* Code for rl_simpl */

static Lisp_Object MS_CDECL CC_rl_simpl(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0011,
                         Lisp_Object v0004, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0013, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "rl_simpl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0011,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0012 = v0004;
    v0013 = v0011;
    v0081 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_simpl!* */
    v0012 = list3(v0081, v0013, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-1];
    {
        Lisp_Object v0052 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0052, v0012);
    }
/* error exit handlers */
v0016:
    popv(2);
    return nil;
}



/* Code for terpri!* */

static Lisp_Object CC_terpriH(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0049, v0047, v0069;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for terpri*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0049 = qvalue(elt(env, 1)); /* outputhandler!* */
    if (v0049 == nil) goto v0007;
    v0047 = qvalue(elt(env, 1)); /* outputhandler!* */
    v0069 = elt(env, 2); /* terpri */
    v0049 = stack[0];
        popv(3);
        return Lapply2(nil, 3, v0047, v0069, v0049);

v0007:
    v0049 = qvalue(elt(env, 3)); /* testing!-width!* */
    if (v0049 == nil) goto v0013;
    v0049 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 5)) = v0049; /* overflowed!* */
    { popv(3); return onevalue(v0049); }

v0013:
    v0049 = qvalue(elt(env, 6)); /* !*fort */
    if (v0049 == nil) goto v0052;
    v0049 = stack[0];
    {
        popv(3);
        fn = elt(env, 15); /* fterpri */
        return (*qfn1(fn))(qenv(fn), v0049);
    }

v0052:
    v0049 = qvalue(elt(env, 7)); /* !*nat */
    if (v0049 == nil) goto v0043;
    v0049 = qvalue(elt(env, 8)); /* pline!* */
    if (v0049 == nil) goto v0043;
    v0049 = qvalue(elt(env, 8)); /* pline!* */
    v0049 = Lreverse(nil, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    qvalue(elt(env, 8)) = v0049; /* pline!* */
    v0049 = qvalue(elt(env, 9)); /* ymax!* */
    stack[-1] = v0049;
    goto v0092;

v0092:
    v0047 = stack[-1];
    v0049 = qvalue(elt(env, 10)); /* ymin!* */
    v0049 = difference2(v0047, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0049 = Lminusp(nil, v0049);
    env = stack[-2];
    if (v0049 == nil) goto v0044;
    v0049 = qvalue(elt(env, 11)); /* nil */
    qvalue(elt(env, 8)) = v0049; /* pline!* */
    goto v0043;

v0043:
    v0049 = stack[0];
    if (v0049 == nil) goto v0093;
    v0049 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    goto v0093;

v0093:
    v0049 = qvalue(elt(env, 12)); /* orig!* */
    qvalue(elt(env, 13)) = v0049; /* posn!* */
    v0049 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 10)) = v0049; /* ymin!* */
    qvalue(elt(env, 9)) = v0049; /* ymax!* */
    qvalue(elt(env, 14)) = v0049; /* ycoord!* */
    v0049 = nil;
    { popv(3); return onevalue(v0049); }

v0044:
    v0047 = qvalue(elt(env, 8)); /* pline!* */
    v0049 = stack[-1];
    fn = elt(env, 16); /* scprint */
    v0049 = (*qfn2(fn))(qenv(fn), v0047, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0049 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    v0049 = stack[-1];
    v0049 = sub1(v0049);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-2];
    stack[-1] = v0049;
    goto v0092;
/* error exit handlers */
v0024:
    popv(3);
    return nil;
}



/* Code for ldt!-tvar */

static Lisp_Object CC_ldtKtvar(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0014, v0016;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldt-tvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0081 = v0000;
/* end of prologue */
    v0081 = qcar(v0081);
    v0081 = qcar(v0081);
    v0014 = v0081;
    v0081 = v0014;
    v0016 = elt(env, 1); /* df */
    if (!consp(v0081)) return onevalue(v0014);
    v0081 = qcar(v0081);
    if (!(v0081 == v0016)) return onevalue(v0014);
    v0081 = v0014;
    v0081 = qcdr(v0081);
    v0081 = qcar(v0081);
    return onevalue(v0081);
}



/* Code for findnewvars */

static Lisp_Object CC_findnewvars(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for findnewvars");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0046 = stack[0];
    if (!consp(v0046)) goto v0019;
    v0046 = stack[0];
    stack[-3] = v0046;
    goto v0014;

v0014:
    v0046 = stack[-3];
    if (v0046 == nil) goto v0017;
    v0046 = stack[-3];
    v0046 = qcar(v0046);
    v0046 = CC_findnewvars(env, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    stack[-2] = v0046;
    v0046 = stack[-2];
    fn = elt(env, 2); /* lastpair */
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    stack[-1] = v0046;
    v0046 = stack[-3];
    v0046 = qcdr(v0046);
    stack[-3] = v0046;
    v0046 = stack[-1];
    if (!consp(v0046)) goto v0014;
    else goto v0016;

v0016:
    v0046 = stack[-3];
    if (v0046 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0046 = stack[-3];
    v0046 = qcar(v0046);
    v0046 = CC_findnewvars(env, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    v0046 = Lrplacd(nil, stack[0], v0046);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    v0046 = stack[-1];
    fn = elt(env, 2); /* lastpair */
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    stack[-1] = v0046;
    v0046 = stack[-3];
    v0046 = qcdr(v0046);
    stack[-3] = v0046;
    goto v0016;

v0017:
    v0046 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0046); }

v0019:
    v0046 = stack[0];
    fn = elt(env, 3); /* genp */
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-4];
    if (v0046 == nil) goto v0042;
    v0046 = stack[0];
    popv(5);
    return ncons(v0046);

v0042:
    v0046 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0046); }
/* error exit handlers */
v0062:
    popv(5);
    return nil;
}



/* Code for unchecked_getmatelem */

static Lisp_Object CC_unchecked_getmatelem(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0048, v0089, v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unchecked_getmatelem");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0048 = stack[-1];
    v0089 = qcar(v0048);
    v0090 = v0089;
    v0048 = elt(env, 1); /* mat */
    if (!consp(v0089)) goto v0065;
    v0089 = qcar(v0089);
    if (!(v0089 == v0048)) goto v0065;
    v0048 = v0090;
    v0089 = qcdr(v0048);
    v0048 = stack[-1];
    v0048 = qcdr(v0048);
    v0048 = qcar(v0048);
    fn = elt(env, 5); /* nth */
    v0089 = (*qfn2(fn))(qenv(fn), v0089, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-3];
    v0048 = stack[-1];
    v0048 = qcdr(v0048);
    v0048 = qcdr(v0048);
    v0048 = qcar(v0048);
    {
        popv(4);
        fn = elt(env, 5); /* nth */
        return (*qfn2(fn))(qenv(fn), v0089, v0048);
    }

v0065:
    stack[-2] = elt(env, 2); /* matrix */
    stack[0] = (Lisp_Object)17; /* 1 */
    v0090 = elt(env, 3); /* "Matrix" */
    v0048 = stack[-1];
    v0089 = qcar(v0048);
    v0048 = elt(env, 4); /* "not set" */
    v0048 = list3(v0090, v0089, v0048);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-3];
    fn = elt(env, 6); /* rerror */
    v0048 = (*qfnn(fn))(qenv(fn), 3, stack[-2], stack[0], v0048);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    v0048 = nil;
    { popv(4); return onevalue(v0048); }
/* error exit handlers */
v0096:
    popv(4);
    return nil;
}



/* Code for gpexp1p */

static Lisp_Object CC_gpexp1p(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0013;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gpexp1p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0097:
    v0013 = stack[0];
    if (v0013 == nil) goto v0019;
    v0013 = stack[0];
    v0013 = qcar(v0013);
    fn = elt(env, 3); /* gpexpp */
    v0013 = (*qfn1(fn))(qenv(fn), v0013);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-1];
    if (v0013 == nil) goto v0058;
    v0013 = stack[0];
    v0013 = qcdr(v0013);
    stack[0] = v0013;
    goto v0097;

v0058:
    v0013 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v0013); }

v0019:
    v0013 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v0013); }
/* error exit handlers */
v0014:
    popv(2);
    return nil;
}



/* Code for assert_uninstall1 */

static Lisp_Object CC_assert_uninstall1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0063, v0030, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_uninstall1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0030 = stack[0];
    v0063 = elt(env, 1); /* assert_installed */
    v0063 = get(v0030, v0063);
    env = stack[-1];
    if (v0063 == nil) goto v0073;
    v0031 = stack[0];
    v0030 = stack[0];
    v0063 = elt(env, 3); /* assert_noassertfn */
    v0063 = get(v0030, v0063);
    env = stack[-1];
    fn = elt(env, 5); /* copyd */
    v0063 = (*qfn2(fn))(qenv(fn), v0031, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    v0030 = stack[0];
    v0063 = elt(env, 1); /* assert_installed */
    v0031 = qvalue(elt(env, 4)); /* nil */
        popv(2);
        return Lputprop(nil, 3, v0030, v0063, v0031);

v0073:
    v0030 = elt(env, 2); /* "assert not installed for" */
    v0063 = stack[0];
    v0063 = list2(v0030, v0063);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 6); /* lprim */
        return (*qfn1(fn))(qenv(fn), v0063);
    }
/* error exit handlers */
v0091:
    popv(2);
    return nil;
}



/* Code for mv!-domainlist!-!- */

static Lisp_Object CC_mvKdomainlistKK(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-domainlist--");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0050;

v0050:
    v0059 = stack[-1];
    if (v0059 == nil) goto v0007;
    v0059 = stack[-1];
    v0064 = qcar(v0059);
    v0059 = stack[0];
    v0059 = qcar(v0059);
    v0064 = difference2(v0064, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    v0059 = stack[-2];
    v0059 = cons(v0064, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    stack[-2] = v0059;
    v0059 = stack[-1];
    v0059 = qcdr(v0059);
    stack[-1] = v0059;
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    stack[0] = v0059;
    goto v0050;

v0007:
    v0059 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0059);
    }
/* error exit handlers */
v0006:
    popv(4);
    return nil;
}



/* Code for wi_new */

static Lisp_Object CC_wi_new(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0017;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wi_new");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    v0068 = qvalue(elt(env, 1)); /* wi_number */
    v0068 = add1(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    qvalue(elt(env, 1)) = v0068; /* wi_number */
    v0017 = elt(env, 2); /* !: */
    v0068 = qvalue(elt(env, 1)); /* wi_number */
    fn = elt(env, 4); /* mkid */
    v0068 = (*qfn2(fn))(qenv(fn), v0017, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    v0068 = Lintern(nil, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    stack[-3] = v0068;
    stack[-1] = stack[-3];
    stack[0] = elt(env, 3); /* windex */
    v0068 = stack[-2];
    v0068 = ncons(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-4];
    v0068 = Lputprop(nil, 3, stack[-1], stack[0], v0068);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }
/* error exit handlers */
v0002:
    popv(5);
    return nil;
}



/* Code for prepreform */

static Lisp_Object CC_prepreform(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0037, v0099;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepreform");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0037 = v0000;
/* end of prologue */
    stack[0] = v0037;
    v0099 = qvalue(elt(env, 1)); /* ordl!* */
    v0037 = qvalue(elt(env, 2)); /* factors!* */
    v0037 = Lappend(nil, v0099, v0037);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[-1];
    {
        Lisp_Object v0010 = stack[0];
        popv(2);
        fn = elt(env, 3); /* prepreform1 */
        return (*qfn2(fn))(qenv(fn), v0010, v0037);
    }
/* error exit handlers */
v0009:
    popv(2);
    return nil;
}



/* Code for updtemplate */

static Lisp_Object MS_CDECL CC_updtemplate(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0011,
                         Lisp_Object v0004, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0102, v0088, v0103;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "updtemplate");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for updtemplate");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0011,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0004;
    v0102 = v0011;
    stack[-6] = v0000;
/* end of prologue */
    stack[-4] = v0102;
    v0102 = stack[-4];
    if (v0102 == nil) goto v0037;
    v0102 = stack[-4];
    v0102 = qcar(v0102);
    stack[0] = v0102;
    v0088 = stack[-6];
    v0102 = stack[0];
    v0088 = Lsubla(nil, v0088, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-8];
    stack[-7] = v0088;
    v0102 = stack[0];
    if (equal(v0088, v0102)) goto v0052;
    v0088 = stack[-7];
    v0102 = stack[-5];
    fn = elt(env, 2); /* reval!-without */
    v0088 = (*qfn2(fn))(qenv(fn), v0088, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-8];
    v0103 = v0088;
    v0102 = stack[-7];
    if (equal(v0088, v0102)) goto v0060;
    v0102 = v0103;
    goto v0016;

v0016:
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-8];
    stack[-2] = v0102;
    stack[-3] = v0102;
    goto v0041;

v0041:
    v0102 = stack[-4];
    v0102 = qcdr(v0102);
    stack[-4] = v0102;
    v0102 = stack[-4];
    if (v0102 == nil) { Lisp_Object res = stack[-3]; popv(9); return onevalue(res); }
    stack[-1] = stack[-2];
    v0102 = stack[-4];
    v0102 = qcar(v0102);
    stack[0] = v0102;
    v0088 = stack[-6];
    v0102 = stack[0];
    v0088 = Lsubla(nil, v0088, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-8];
    stack[-7] = v0088;
    v0102 = stack[0];
    if (equal(v0088, v0102)) goto v0026;
    v0088 = stack[-7];
    v0102 = stack[-5];
    fn = elt(env, 2); /* reval!-without */
    v0088 = (*qfn2(fn))(qenv(fn), v0088, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-8];
    v0103 = v0088;
    v0102 = stack[-7];
    if (equal(v0088, v0102)) goto v0104;
    v0102 = v0103;
    goto v0025;

v0025:
    v0102 = ncons(v0102);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-8];
    v0102 = Lrplacd(nil, stack[-1], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[-8];
    v0102 = stack[-2];
    v0102 = qcdr(v0102);
    stack[-2] = v0102;
    goto v0041;

v0104:
    v0102 = stack[-7];
    goto v0025;

v0026:
    v0102 = stack[0];
    goto v0025;

v0060:
    v0102 = stack[-7];
    goto v0016;

v0052:
    v0102 = stack[0];
    goto v0016;

v0037:
    v0102 = qvalue(elt(env, 1)); /* nil */
    { popv(9); return onevalue(v0102); }
/* error exit handlers */
v0085:
    popv(9);
    return nil;
}



/* Code for qqe_number!-of!-adds!-in!-qterm */

static Lisp_Object CC_qqe_numberKofKaddsKinKqterm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0001;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_number-of-adds-in-qterm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0019:
    v0017 = stack[0];
    if (!consp(v0017)) goto v0043;
    v0017 = stack[0];
    fn = elt(env, 2); /* qqe_op */
    v0001 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    v0017 = elt(env, 1); /* (ladd radd) */
    v0017 = Lmemq(nil, v0001, v0017);
    if (v0017 == nil) goto v0016;
    v0017 = stack[0];
    fn = elt(env, 3); /* qqe_arg2r */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    v0017 = CC_qqe_numberKofKaddsKinKqterm(env, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    popv(2);
    return add1(v0017);

v0016:
    v0017 = stack[0];
    fn = elt(env, 4); /* qqe_arg2l */
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    stack[0] = v0017;
    goto v0019;

v0043:
    v0017 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0017); }
/* error exit handlers */
v0054:
    popv(2);
    return nil;
}



/* Code for rl_simp1 */

static Lisp_Object CC_rl_simp1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0125, v0126, v0127, v0128;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_simp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0097:
    v0125 = qvalue(elt(env, 1)); /* rl_cid!* */
    if (!(v0125 == nil)) goto v0050;
    v0125 = elt(env, 2); /* "select a context" */
    v0125 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    fn = elt(env, 8); /* rederr */
    v0125 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    goto v0050;

v0050:
    v0125 = stack[0];
    if (!consp(v0125)) goto v0042;
    v0125 = stack[0];
    fn = elt(env, 9); /* argnochk */
    v0125 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0125 = stack[0];
    v0126 = qcar(v0125);
    v0125 = elt(env, 3); /* rl_simpfn */
    v0125 = get(v0126, v0125);
    env = stack[-5];
    v0126 = v0125;
    if (v0125 == nil) goto v0061;
    v0125 = v0126;
    if (!symbolp(v0125)) v0125 = nil;
    else { v0125 = qfastgets(v0125);
           if (v0125 != nil) { v0125 = elt(v0125, 62); /* full */
#ifdef RECORD_GET
             if (v0125 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v0125 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v0125 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v0125 == SPID_NOPROP) v0125 = nil; else v0125 = lisp_true; }}
#endif
    if (v0125 == nil) goto v0031;
    stack[-1] = v0126;
    v0125 = stack[0];
    v0125 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    {
        Lisp_Object v0130 = stack[-1];
        popv(6);
        fn = elt(env, 10); /* apply */
        return (*qfn2(fn))(qenv(fn), v0130, v0125);
    }

v0031:
    stack[-1] = v0126;
    v0125 = stack[0];
    v0125 = qcdr(v0125);
    v0125 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    {
        Lisp_Object v0131 = stack[-1];
        popv(6);
        fn = elt(env, 10); /* apply */
        return (*qfn2(fn))(qenv(fn), v0131, v0125);
    }

v0061:
    v0125 = stack[0];
    v0127 = qcar(v0125);
    v0125 = qvalue(elt(env, 1)); /* rl_cid!* */
    v0126 = qcar(v0125);
    v0125 = elt(env, 4); /* simpfnname */
    v0125 = get(v0126, v0125);
    env = stack[-5];
    v0125 = get(v0127, v0125);
    env = stack[-5];
    v0126 = v0125;
    if (v0125 == nil) goto v0048;
    v0125 = v0126;
    if (!symbolp(v0125)) v0125 = nil;
    else { v0125 = qfastgets(v0125);
           if (v0125 != nil) { v0125 = elt(v0125, 62); /* full */
#ifdef RECORD_GET
             if (v0125 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v0125 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v0125 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v0125 == SPID_NOPROP) v0125 = nil; else v0125 = lisp_true; }}
#endif
    if (v0125 == nil) goto v0132;
    stack[-1] = v0126;
    v0125 = stack[0];
    v0125 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    {
        Lisp_Object v0133 = stack[-1];
        popv(6);
        fn = elt(env, 10); /* apply */
        return (*qfn2(fn))(qenv(fn), v0133, v0125);
    }

v0132:
    stack[-1] = v0126;
    v0125 = stack[0];
    v0125 = qcdr(v0125);
    v0125 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    {
        Lisp_Object v0134 = stack[-1];
        popv(6);
        fn = elt(env, 10); /* apply */
        return (*qfn2(fn))(qenv(fn), v0134, v0125);
    }

v0048:
    v0125 = stack[0];
    v0125 = qcar(v0125);
    if (!symbolp(v0125)) v0125 = nil;
    else { v0125 = qfastgets(v0125);
           if (v0125 != nil) { v0125 = elt(v0125, 45); /* psopfn */
#ifdef RECORD_GET
             if (v0125 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v0125 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v0125 == SPID_NOPROP) v0125 = nil; }}
#endif
    v0126 = v0125;
    if (v0125 == nil) goto v0135;
    v0125 = stack[0];
    v0125 = qcdr(v0125);
    v0125 = Lapply1(nil, v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    stack[0] = v0125;
    goto v0097;

v0135:
    v0125 = stack[0];
    v0125 = qcar(v0125);
    if (!symbolp(v0125)) v0125 = nil;
    else { v0125 = qfastgets(v0125);
           if (v0125 != nil) { v0125 = elt(v0125, 59); /* opfn */
#ifdef RECORD_GET
             if (v0125 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v0125 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v0125 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v0125 == SPID_NOPROP) v0125 = nil; else v0125 = lisp_true; }}
#endif
    if (v0125 == nil) goto v0136;
    v0125 = stack[0];
    stack[-4] = qcar(v0125);
    v0125 = stack[0];
    v0125 = qcdr(v0125);
    stack[-3] = v0125;
    v0125 = stack[-3];
    if (v0125 == nil) goto v0137;
    v0125 = stack[-3];
    v0125 = qcar(v0125);
    fn = elt(env, 11); /* reval */
    v0125 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0125 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    stack[-1] = v0125;
    stack[-2] = v0125;
    goto v0138;

v0138:
    v0125 = stack[-3];
    v0125 = qcdr(v0125);
    stack[-3] = v0125;
    v0125 = stack[-3];
    if (v0125 == nil) goto v0139;
    stack[0] = stack[-1];
    v0125 = stack[-3];
    v0125 = qcar(v0125);
    fn = elt(env, 11); /* reval */
    v0125 = (*qfn1(fn))(qenv(fn), v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0125 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0125 = Lrplacd(nil, stack[0], v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0125 = stack[-1];
    v0125 = qcdr(v0125);
    stack[-1] = v0125;
    goto v0138;

v0139:
    v0125 = stack[-2];
    goto v0140;

v0140:
    fn = elt(env, 10); /* apply */
    v0125 = (*qfn2(fn))(qenv(fn), stack[-4], v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    stack[0] = v0125;
    goto v0097;

v0137:
    v0125 = qvalue(elt(env, 5)); /* nil */
    goto v0140;

v0136:
    v0125 = stack[0];
    v0125 = qcar(v0125);
    if (!symbolp(v0125)) v0125 = nil;
    else { v0125 = qfastgets(v0125);
           if (v0125 != nil) { v0125 = elt(v0125, 44); /* prepfn2 */
#ifdef RECORD_GET
             if (v0125 != SPID_NOPROP)
                record_get(elt(fastget_names, 44), 1);
             else record_get(elt(fastget_names, 44), 0),
                v0125 = nil; }
           else record_get(elt(fastget_names, 44), 0); }
#else
             if (v0125 == SPID_NOPROP) v0125 = nil; }}
#endif
    v0126 = v0125;
    if (v0125 == nil) goto v0141;
    stack[-1] = v0126;
    v0125 = stack[0];
    v0125 = ncons(v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    fn = elt(env, 10); /* apply */
    v0125 = (*qfn2(fn))(qenv(fn), stack[-1], v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    stack[0] = v0125;
    goto v0097;

v0141:
    v0125 = stack[0];
    v0126 = qcar(v0125);
    v0125 = elt(env, 6); /* "predicate" */
    fn = elt(env, 12); /* rl_redmsg */
    v0125 = (*qfn2(fn))(qenv(fn), v0126, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0125 = stack[0];
    v0128 = qcar(v0125);
    v0125 = qvalue(elt(env, 1)); /* rl_cid!* */
    v0126 = qcar(v0125);
    v0125 = elt(env, 4); /* simpfnname */
    v0127 = get(v0126, v0125);
    env = stack[-5];
    v0125 = qvalue(elt(env, 1)); /* rl_cid!* */
    v0126 = qcar(v0125);
    v0125 = elt(env, 7); /* simpdefault */
    v0125 = get(v0126, v0125);
    env = stack[-5];
    v0125 = Lputprop(nil, 3, v0128, v0127, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0129;
    env = stack[-5];
    v0125 = stack[0];
    stack[0] = v0125;
    goto v0097;

v0042:
    v0125 = stack[0];
    {
        popv(6);
        fn = elt(env, 13); /* rl_simpatom */
        return (*qfn1(fn))(qenv(fn), v0125);
    }
/* error exit handlers */
v0129:
    popv(6);
    return nil;
}



/* Code for diff!-k!-times!-mod!-p */

static Lisp_Object MS_CDECL CC_diffKkKtimesKmodKp(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0011,
                         Lisp_Object v0004, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0153, v0154, v0155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "diff-k-times-mod-p");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diff-k-times-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0011,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0004;
    stack[-2] = v0011;
    stack[-3] = v0000;
/* end of prologue */
    v0153 = stack[-3];
    if (!consp(v0153)) goto v0072;
    v0153 = stack[-3];
    v0153 = qcar(v0153);
    v0153 = (consp(v0153) ? nil : lisp_true);
    goto v0007;

v0007:
    if (v0153 == nil) goto v0012;
    v0153 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0153); }

v0012:
    v0153 = stack[-3];
    v0153 = qcar(v0153);
    v0153 = qcar(v0153);
    v0154 = qcar(v0153);
    v0153 = stack[-1];
    if (equal(v0154, v0153)) goto v0059;
    v0153 = stack[-3];
    v0153 = qcar(v0153);
    stack[-4] = qcar(v0153);
    v0153 = stack[-3];
    v0153 = qcar(v0153);
    v0155 = qcdr(v0153);
    v0154 = stack[-2];
    v0153 = stack[-1];
    stack[0] = CC_diffKkKtimesKmodKp(env, 3, v0155, v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-5];
    v0153 = stack[-3];
    v0155 = qcdr(v0153);
    v0154 = stack[-2];
    v0153 = stack[-1];
    v0153 = CC_diffKkKtimesKmodKp(env, 3, v0155, v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-5];
    {
        Lisp_Object v0157 = stack[-4];
        Lisp_Object v0158 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0157, v0158, v0153);
    }

v0059:
    v0153 = stack[-3];
    v0153 = qcar(v0153);
    v0153 = qcar(v0153);
    v0154 = qcdr(v0153);
    v0153 = stack[-2];
    v0153 = (Lisp_Object)lessp2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    v0153 = v0153 ? lisp_true : nil;
    env = stack[-5];
    if (v0153 == nil) goto v0092;
    v0153 = qvalue(elt(env, 2)); /* nil */
    { popv(6); return onevalue(v0153); }

v0092:
    v0153 = stack[-3];
    v0153 = qcar(v0153);
    v0153 = qcar(v0153);
    v0154 = qcdr(v0153);
    v0153 = stack[-2];
    if (equal(v0154, v0153)) goto v0094;
    stack[0] = stack[-1];
    v0153 = stack[-3];
    v0153 = qcar(v0153);
    v0153 = qcar(v0153);
    v0154 = qcdr(v0153);
    v0153 = stack[-2];
    v0153 = difference2(v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-5];
    fn = elt(env, 4); /* mksp */
    stack[-4] = (*qfn2(fn))(qenv(fn), stack[0], v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-5];
    v0153 = stack[-3];
    v0153 = qcar(v0153);
    v0153 = qcar(v0153);
    v0154 = qcdr(v0153);
    v0153 = stack[-2];
    fn = elt(env, 5); /* binomial!-coefft!-mod!-p */
    v0154 = (*qfn2(fn))(qenv(fn), v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-5];
    v0153 = stack[-3];
    v0153 = qcar(v0153);
    v0153 = qcdr(v0153);
    fn = elt(env, 6); /* times!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-5];
    v0153 = stack[-3];
    v0155 = qcdr(v0153);
    v0154 = stack[-2];
    v0153 = stack[-1];
    v0153 = CC_diffKkKtimesKmodKp(env, 3, v0155, v0154, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0156;
    env = stack[-5];
    {
        Lisp_Object v0159 = stack[-4];
        Lisp_Object v0160 = stack[0];
        popv(6);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0159, v0160, v0153);
    }

v0094:
    v0153 = stack[-3];
    v0153 = qcar(v0153);
    v0153 = qcdr(v0153);
    { popv(6); return onevalue(v0153); }

v0072:
    v0153 = qvalue(elt(env, 1)); /* t */
    goto v0007;
/* error exit handlers */
v0156:
    popv(6);
    return nil;
}



/* Code for cird */

static Lisp_Object MS_CDECL CC_cird(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0029, v0040, v0039;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "cird");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cird");
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
    v0040 = qvalue(elt(env, 2)); /* atts */
    v0029 = elt(env, 3); /* (type) */
    fn = elt(env, 6); /* retattributes */
    v0029 = (*qfn2(fn))(qenv(fn), v0040, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    stack[0] = v0029;
    fn = elt(env, 7); /* lex */
    v0029 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0029 = qvalue(elt(env, 4)); /* char */
    stack[-1] = v0029;
    fn = elt(env, 7); /* lex */
    v0029 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0029 = stack[-1];
    v0029 = Lcompress(nil, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0040 = v0029;
    v0029 = v0040;
    if (!(is_number(v0029))) goto v0014;
    v0029 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 8); /* errorml */
    v0029 = (*qfn2(fn))(qenv(fn), v0040, v0029);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    goto v0014;

v0014:
    v0029 = stack[-1];
    fn = elt(env, 9); /* compress!* */
    v0029 = (*qfn1(fn))(qenv(fn), v0029);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0040 = v0029;
    v0029 = stack[0];
    if (v0029 == nil) { popv(3); return onevalue(v0040); }
    v0039 = elt(env, 5); /* ci */
    v0029 = stack[0];
    popv(3);
    return list3(v0039, v0029, v0040);
/* error exit handlers */
v0060:
    popv(3);
    return nil;
}



/* Code for newenv */

static Lisp_Object CC_newenv(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0072, v0076;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for newenv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0072 = v0000;
/* end of prologue */
    v0076 = v0072;
    v0072 = elt(env, 1); /* unbound */
    {
        fn = elt(env, 2); /* bind */
        return (*qfn2(fn))(qenv(fn), v0076, v0072);
    }
}



/* Code for xord_gradlex */

static Lisp_Object CC_xord_gradlex(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0039, v0044;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xord_gradlex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0000;
/* end of prologue */
    v0039 = stack[-1];
    v0044 = qcar(v0039);
    v0039 = (Lisp_Object)17; /* 1 */
    if (v0044 == v0039) goto v0051;
    v0039 = stack[0];
    v0044 = qcar(v0039);
    v0039 = (Lisp_Object)17; /* 1 */
    if (v0044 == v0039) goto v0073;
    v0039 = stack[-1];
    stack[-2] = Llength(nil, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    v0039 = stack[0];
    v0039 = Llength(nil, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    if (equal(stack[-2], v0039)) goto v0020;
    v0039 = stack[-1];
    stack[-1] = Llength(nil, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-3];
    v0039 = stack[0];
    v0039 = Llength(nil, v0039);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    {
        Lisp_Object v0089 = stack[-1];
        popv(4);
        return Lgreaterp(nil, v0089, v0039);
    }

v0020:
    v0044 = stack[-1];
    v0039 = stack[0];
    {
        popv(4);
        fn = elt(env, 3); /* xord_lex */
        return (*qfn2(fn))(qenv(fn), v0044, v0039);
    }

v0073:
    v0039 = qvalue(elt(env, 2)); /* t */
    { popv(4); return onevalue(v0039); }

v0051:
    v0039 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0039); }
/* error exit handlers */
v0048:
    popv(4);
    return nil;
}



/* Code for plus!: */

static Lisp_Object CC_plusT(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0168, v0169, v0140, v0170;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for plus:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0140 = v0011;
    v0170 = v0000;
/* end of prologue */
    v0168 = v0170;
    v0168 = qcdr(v0168);
    v0169 = qcar(v0168);
    stack[-1] = v0169;
    v0168 = (Lisp_Object)1; /* 0 */
    if (v0169 == v0168) { popv(6); return onevalue(v0140); }
    v0168 = v0140;
    v0168 = qcdr(v0168);
    v0169 = qcar(v0168);
    stack[0] = v0169;
    v0168 = (Lisp_Object)1; /* 0 */
    if (v0169 == v0168) { popv(6); return onevalue(v0170); }
    v0168 = v0170;
    v0168 = qcdr(v0168);
    v0168 = qcdr(v0168);
    stack[-4] = v0168;
    v0169 = v0140;
    v0169 = qcdr(v0169);
    v0169 = qcdr(v0169);
    stack[-2] = v0169;
    v0169 = difference2(v0168, v0169);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    stack[-3] = v0169;
    v0168 = (Lisp_Object)1; /* 0 */
    if (v0169 == v0168) goto v0040;
    v0169 = stack[-3];
    v0168 = (Lisp_Object)1; /* 0 */
    v0168 = (Lisp_Object)greaterp2(v0169, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    v0168 = v0168 ? lisp_true : nil;
    env = stack[-5];
    if (v0168 == nil) goto v0171;
    stack[-4] = elt(env, 1); /* !:rd!: */
    v0169 = stack[-1];
    v0168 = stack[-3];
    v0169 = Lash1(nil, v0169, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0168 = stack[0];
    v0169 = plus2(v0169, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    v0168 = stack[-2];
    {
        Lisp_Object v0147 = stack[-4];
        popv(6);
        return list2star(v0147, v0169, v0168);
    }

v0171:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v0168 = stack[-3];
    v0168 = negate(v0168);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0168 = Lash1(nil, stack[0], v0168);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    env = stack[-5];
    v0169 = plus2(stack[-1], v0168);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    v0168 = stack[-4];
    {
        Lisp_Object v0138 = stack[-2];
        popv(6);
        return list2star(v0138, v0169, v0168);
    }

v0040:
    stack[-2] = elt(env, 1); /* !:rd!: */
    v0169 = stack[-1];
    v0168 = stack[0];
    v0169 = plus2(v0169, v0168);
    nil = C_nil;
    if (exception_pending()) goto v0116;
    v0168 = stack[-4];
    {
        Lisp_Object v0143 = stack[-2];
        popv(6);
        return list2star(v0143, v0169, v0168);
    }
/* error exit handlers */
v0116:
    popv(6);
    return nil;
}



/* Code for prinfit */

static Lisp_Object MS_CDECL CC_prinfit(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0011,
                         Lisp_Object v0004, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0172, v0096, v0046;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "prinfit");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prinfit");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0011,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    stack[-1] = v0011;
    stack[-2] = v0000;
/* end of prologue */
    v0172 = qvalue(elt(env, 1)); /* !*nat */
    if (v0172 == nil) goto v0041;
    v0172 = qvalue(elt(env, 3)); /* testing!-width!* */
    goto v0058;

v0058:
    if (v0172 == nil) goto v0053;
    v0172 = stack[0];
    if (v0172 == nil) goto v0057;
    v0172 = stack[0];
    fn = elt(env, 4); /* oprin */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    goto v0057;

v0057:
    v0096 = stack[-2];
    v0172 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); /* maprint */
        return (*qfn2(fn))(qenv(fn), v0096, v0172);
    }

v0053:
    v0046 = stack[-2];
    v0096 = stack[-1];
    v0172 = stack[0];
    fn = elt(env, 6); /* layout!-formula */
    v0172 = (*qfnn(fn))(qenv(fn), 3, v0046, v0096, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0096 = v0172;
    v0172 = v0096;
    if (v0172 == nil) goto v0094;
    v0172 = v0096;
    fn = elt(env, 7); /* putpline */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    v0172 = nil;
    { popv(4); return onevalue(v0172); }

v0094:
    v0172 = stack[0];
    if (v0172 == nil) goto v0044;
    v0172 = stack[0];
    fn = elt(env, 4); /* oprin */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    goto v0044;

v0044:
    v0096 = stack[-2];
    v0172 = stack[-1];
    {
        popv(4);
        fn = elt(env, 5); /* maprint */
        return (*qfn2(fn))(qenv(fn), v0096, v0172);
    }

v0041:
    v0172 = qvalue(elt(env, 2)); /* t */
    goto v0058;
/* error exit handlers */
v0028:
    popv(4);
    return nil;
}



/* Code for mv!-pow!-!- */

static Lisp_Object CC_mvKpowKK(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0059, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mv-pow--");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    goto v0050;

v0050:
    v0059 = stack[-1];
    if (v0059 == nil) goto v0007;
    v0059 = stack[-1];
    v0064 = qcar(v0059);
    v0059 = stack[0];
    v0059 = qcar(v0059);
    v0064 = difference2(v0064, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    v0059 = stack[-2];
    v0059 = cons(v0064, v0059);
    nil = C_nil;
    if (exception_pending()) goto v0006;
    env = stack[-3];
    stack[-2] = v0059;
    v0059 = stack[-1];
    v0059 = qcdr(v0059);
    stack[-1] = v0059;
    v0059 = stack[0];
    v0059 = qcdr(v0059);
    stack[0] = v0059;
    goto v0050;

v0007:
    v0059 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0059);
    }
/* error exit handlers */
v0006:
    popv(4);
    return nil;
}



/* Code for mo_neworder */

static Lisp_Object CC_mo_neworder(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0042;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_neworder");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0042 = v0000;
/* end of prologue */
    v0042 = qcar(v0042);
    fn = elt(env, 1); /* mo!=shorten */
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[-1];
    stack[0] = v0042;
    fn = elt(env, 2); /* mo!=deglist */
    v0042 = (*qfn1(fn))(qenv(fn), v0042);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    {
        Lisp_Object v0099 = stack[0];
        popv(2);
        return cons(v0099, v0042);
    }
/* error exit handlers */
v0037:
    popv(2);
    return nil;
}



/* Code for gperm3 */

static Lisp_Object CC_gperm3(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0017, v0001, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm3");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0001 = v0011;
    v0017 = v0000;
/* end of prologue */

v0050:
    v0018 = v0017;
    if (v0018 == nil) { popv(2); return onevalue(v0001); }
    v0018 = v0017;
    v0018 = qcdr(v0018);
    stack[0] = v0018;
    v0018 = v0001;
    v0001 = qcar(v0017);
    v0017 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* gperm2 */
    v0017 = (*qfnn(fn))(qenv(fn), 3, v0018, v0001, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0032;
    env = stack[-1];
    v0001 = v0017;
    v0017 = stack[0];
    goto v0050;
/* error exit handlers */
v0032:
    popv(2);
    return nil;
}



/* Code for general!-reduce!-mod!-p */

static Lisp_Object CC_generalKreduceKmodKp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for general-reduce-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0022 = stack[-1];
    if (v0022 == nil) goto v0019;
    v0022 = stack[-1];
    if (!consp(v0022)) goto v0058;
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0022 = (consp(v0022) ? nil : lisp_true);
    goto v0076;

v0076:
    if (v0022 == nil) goto v0052;
    v0022 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-number */
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* !*n2f */
        return (*qfn1(fn))(qenv(fn), v0022);
    }

v0052:
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    stack[-2] = qcar(v0022);
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0022 = qcdr(v0022);
    stack[0] = CC_generalKreduceKmodKp(env, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    v0022 = stack[-1];
    v0022 = qcdr(v0022);
    v0022 = CC_generalKreduceKmodKp(env, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0094;
    env = stack[-3];
    {
        Lisp_Object v0098 = stack[-2];
        Lisp_Object v0092 = stack[0];
        popv(4);
        fn = elt(env, 5); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v0098, v0092, v0022);
    }

v0058:
    v0022 = qvalue(elt(env, 2)); /* t */
    goto v0076;

v0019:
    v0022 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0022); }
/* error exit handlers */
v0094:
    popv(4);
    return nil;
}



/* Code for ofsf_entry2at */

static Lisp_Object MS_CDECL CC_ofsf_entry2at(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0011,
                         Lisp_Object v0004, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0002, v0053, v0059;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_entry2at");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_entry2at");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0011,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0002 = v0004;
    v0053 = v0011;
    v0059 = v0000;
/* end of prologue */
    v0032 = qvalue(elt(env, 1)); /* !*rlidentify */
    if (v0032 == nil) goto v0081;
    v0032 = v0059;
    fn = elt(env, 2); /* ofsf_entry2at1 */
    v0032 = (*qfnn(fn))(qenv(fn), 3, v0032, v0053, v0002);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* cl_identifyat */
        return (*qfn1(fn))(qenv(fn), v0032);
    }

v0081:
    v0032 = v0059;
    {
        popv(1);
        fn = elt(env, 2); /* ofsf_entry2at1 */
        return (*qfnn(fn))(qenv(fn), 3, v0032, v0053, v0002);
    }
/* error exit handlers */
v0064:
    popv(1);
    return nil;
}



/* Code for qqe_simplat1 */

static Lisp_Object CC_qqe_simplat1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0031, v0161, v0091;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qqe_simplat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0000;
/* end of prologue */
    v0031 = stack[-1];
    fn = elt(env, 3); /* qqe_op */
    v0031 = (*qfn1(fn))(qenv(fn), v0031);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-2];
    v0091 = v0031;
    v0161 = v0091;
    v0031 = elt(env, 1); /* (qequal qneq) */
    v0031 = Lmemq(nil, v0161, v0031);
    if (v0031 == nil) goto v0065;
    v0161 = v0091;
    v0031 = elt(env, 2); /* qequal */
    if (v0161 == v0031) goto v0053;
    v0161 = stack[-1];
    v0031 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* qqe_simplqneq */
        return (*qfn2(fn))(qenv(fn), v0161, v0031);
    }

v0053:
    v0161 = stack[-1];
    v0031 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* qqe_simplqequal */
        return (*qfn2(fn))(qenv(fn), v0161, v0031);
    }

v0065:
    v0161 = stack[-1];
    v0031 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* qqe_simplbtat */
        return (*qfn2(fn))(qenv(fn), v0161, v0031);
    }
/* error exit handlers */
v0039:
    popv(3);
    return nil;
}



/* Code for cl_fvarl1 */

static Lisp_Object CC_cl_fvarl1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_fvarl1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0051 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* cl_varl1 */
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    errexit();
    v0051 = qcar(v0051);
    return onevalue(v0051);
}



/* Code for aex_mvaroccurtest */

static Lisp_Object CC_aex_mvaroccurtest(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0058, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_mvaroccurtest");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    v0058 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v0041 = (*qfn1(fn))(qenv(fn), v0058);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-1];
    v0058 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* ratpoly_mvartest */
        return (*qfn2(fn))(qenv(fn), v0041, v0058);
    }
/* error exit handlers */
v0042:
    popv(2);
    return nil;
}



/* Code for spquotematrix */

static Lisp_Object CC_spquotematrix(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object v0003;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for spquotematrix");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0003 = v0000;
/* end of prologue */
    v0003 = elt(env, 1); /* sparse */
    return onevalue(v0003);
}



/* Code for initbrsea */

static Lisp_Object MS_CDECL CC_initbrsea(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0150, v0148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "initbrsea");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initbrsea");
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
    push3(nil, nil, nil);
/* end of prologue */
    v0104 = (Lisp_Object)3201; /* 200 */
    stack[-2] = v0104;
    v0104 = qvalue(elt(env, 1)); /* rowmin */
    stack[-1] = v0104;
    goto v0073;

v0073:
    v0150 = qvalue(elt(env, 2)); /* rowmax */
    v0104 = stack[-1];
    v0104 = difference2(v0150, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0104 = Lminusp(nil, v0104);
    env = stack[-3];
    if (v0104 == nil) goto v0054;
    fn = elt(env, 8); /* redcodmat */
    v0104 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0104 = qvalue(elt(env, 6)); /* codhisto */
    if (v0104 == nil) goto v0038;
    v0104 = (Lisp_Object)1; /* 0 */
    stack[0] = v0104;
    goto v0093;

v0093:
    v0150 = (Lisp_Object)3201; /* 200 */
    v0104 = stack[0];
    v0104 = difference2(v0150, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0104 = Lminusp(nil, v0104);
    env = stack[-3];
    if (!(v0104 == nil)) goto v0029;
    v0148 = qvalue(elt(env, 6)); /* codhisto */
    v0150 = stack[0];
    v0104 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v0148 + (CELL-TAG_VECTOR) + ((int32_t)v0150/(16/CELL))) = v0104;
    v0104 = stack[0];
    v0104 = add1(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    stack[0] = v0104;
    goto v0093;

v0029:
    v0104 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 7)) = v0104; /* headhisto */
    v0104 = (Lisp_Object)1; /* 0 */
    stack[0] = v0104;
    goto v0123;

v0123:
    v0150 = qvalue(elt(env, 2)); /* rowmax */
    v0104 = stack[0];
    v0104 = difference2(v0150, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0104 = Lminusp(nil, v0104);
    env = stack[-3];
    if (v0104 == nil) goto v0175;
    v0104 = nil;
    { popv(4); return onevalue(v0104); }

v0175:
    v0104 = stack[0];
    fn = elt(env, 9); /* inshisto */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0104 = stack[0];
    v0104 = add1(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    stack[0] = v0104;
    goto v0123;

v0038:
    v0104 = stack[-2];
    v0104 = Lmkvect(nil, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    qvalue(elt(env, 6)) = v0104; /* codhisto */
    goto v0029;

v0054:
    stack[0] = qvalue(elt(env, 4)); /* codmat */
    v0150 = qvalue(elt(env, 5)); /* maxvar */
    v0104 = stack[-1];
    v0104 = plus2(v0150, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    v0150 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0104/(16/CELL)));
    v0104 = (Lisp_Object)1; /* 0 */
    v0104 = *(Lisp_Object *)((char *)v0150 + (CELL-TAG_VECTOR) + ((int32_t)v0104/(16/CELL)));
    if (v0104 == nil) goto v0014;
    v0104 = stack[-1];
    fn = elt(env, 10); /* initwght */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    goto v0014;

v0014:
    v0104 = stack[-1];
    v0104 = add1(v0104);
    nil = C_nil;
    if (exception_pending()) goto v0088;
    env = stack[-3];
    stack[-1] = v0104;
    goto v0073;
/* error exit handlers */
v0088:
    popv(4);
    return nil;
}



/* Code for modminusp!: */

static Lisp_Object CC_modminuspT(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0016, v0052;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modminusp:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0016 = v0000;
/* end of prologue */
    v0052 = qvalue(elt(env, 1)); /* !*balanced_mod */
    if (v0052 == nil) goto v0013;
    v0052 = (Lisp_Object)33; /* 2 */
    v0016 = qcdr(v0016);
    v0016 = times2(v0052, v0016);
    nil = C_nil;
    if (exception_pending()) goto v0057;
    env = stack[0];
    v0052 = qvalue(elt(env, 2)); /* current!-modulus */
        popv(1);
        return Lgreaterp(nil, v0016, v0052);

v0013:
    v0016 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v0016); }
/* error exit handlers */
v0057:
    popv(1);
    return nil;
}



/* Code for numeric!-content */

static Lisp_Object CC_numericKcontent(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0045, v0060, v0095;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numeric-content");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */

v0019:
    v0045 = stack[0];
    if (!consp(v0045)) goto v0076;
    v0045 = stack[0];
    v0045 = qcar(v0045);
    v0045 = (consp(v0045) ? nil : lisp_true);
    goto v0072;

v0072:
    if (v0045 == nil) goto v0015;
    v0045 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* absf */
        return (*qfn1(fn))(qenv(fn), v0045);
    }

v0015:
    v0045 = stack[0];
    v0045 = qcdr(v0045);
    if (v0045 == nil) goto v0012;
    v0045 = stack[0];
    v0045 = qcar(v0045);
    v0045 = qcdr(v0045);
    v0045 = CC_numericKcontent(env, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    v0095 = v0045;
    v0060 = v0095;
    v0045 = (Lisp_Object)17; /* 1 */
    if (v0060 == v0045) { popv(3); return onevalue(v0095); }
    stack[-1] = v0095;
    v0045 = stack[0];
    v0045 = qcdr(v0045);
    v0045 = CC_numericKcontent(env, v0045);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    env = stack[-2];
    fn = elt(env, 3); /* gcddd */
    v0045 = (*qfn2(fn))(qenv(fn), stack[-1], v0045);
    nil = C_nil;
    if (exception_pending()) goto v0090;
    v0095 = v0045;
    { popv(3); return onevalue(v0095); }

v0012:
    v0045 = stack[0];
    v0045 = qcar(v0045);
    v0045 = qcdr(v0045);
    stack[0] = v0045;
    goto v0019;

v0076:
    v0045 = qvalue(elt(env, 1)); /* t */
    goto v0072;
/* error exit handlers */
v0090:
    popv(3);
    return nil;
}



/* Code for groebnormalform */

static Lisp_Object MS_CDECL CC_groebnormalform(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0011,
                         Lisp_Object v0004, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0065, v0009, v0010;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groebnormalform");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebnormalform");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0099 = v0004;
    v0065 = v0011;
    v0009 = v0000;
/* end of prologue */
    v0010 = v0009;
    v0009 = v0065;
    v0065 = v0099;
    v0099 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* groebnormalform0 */
        return (*qfnn(fn))(qenv(fn), 4, v0010, v0009, v0065, v0099);
    }
}



/* Code for prop!-simp */

static Lisp_Object CC_propKsimp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0009, v0010, v0012, v0013, v0081;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prop-simp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0009 = v0011;
    v0010 = v0000;
/* end of prologue */
    v0081 = v0010;
    v0013 = v0009;
    v0012 = qvalue(elt(env, 1)); /* nil */
    v0010 = (Lisp_Object)1; /* 0 */
    v0009 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 2); /* prop!-simp1 */
        return (*qfnn(fn))(qenv(fn), 5, v0081, v0013, v0012, v0010, v0009);
    }
}



/* Code for lpriw */

static Lisp_Object CC_lpriw(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0046, v0093;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lpriw");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0093 = v0011;
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    v0046 = v0093;
    if (v0046 == nil) goto v0016;
    v0046 = v0093;
    if (!(!consp(v0046))) goto v0016;
    v0046 = v0093;
    v0046 = ncons(v0046);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    goto v0041;

v0041:
    v0046 = cons(stack[0], v0046);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    stack[0] = v0046;
    v0046 = qvalue(elt(env, 1)); /* ofl!* */
    if (v0046 == nil) goto v0017;
    v0046 = qvalue(elt(env, 2)); /* !*fort */
    if (!(v0046 == nil)) goto v0015;
    v0046 = qvalue(elt(env, 3)); /* !*nat */
    if (v0046 == nil) goto v0005;
    v0046 = qvalue(elt(env, 5)); /* !*defn */
    goto v0021;

v0021:
    if (!(v0046 == nil)) goto v0015;

v0017:
    v0046 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    goto v0050;

v0050:
    v0046 = stack[0];
    fn = elt(env, 7); /* lpri */
    v0046 = (*qfn1(fn))(qenv(fn), v0046);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0046 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0046 = stack[-1];
    if (v0046 == nil) goto v0043;
    v0046 = stack[-1];
    v0046 = qcdr(v0046);
    v0046 = Lwrs(nil, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0046 = qvalue(elt(env, 6)); /* nil */
    { popv(3); return onevalue(v0046); }

v0043:
    v0046 = qvalue(elt(env, 1)); /* ofl!* */
    if (!(v0046 == nil)) goto v0015;
    v0046 = qvalue(elt(env, 6)); /* nil */
    { popv(3); return onevalue(v0046); }

v0015:
    v0046 = qvalue(elt(env, 1)); /* ofl!* */
    stack[-1] = v0046;
    v0046 = qvalue(elt(env, 6)); /* nil */
    v0046 = Lwrs(nil, v0046);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    goto v0050;

v0005:
    v0046 = qvalue(elt(env, 4)); /* t */
    goto v0021;

v0016:
    v0046 = v0093;
    goto v0041;
/* error exit handlers */
v0028:
    popv(3);
    return nil;
}



/* Code for dp_neg */

static Lisp_Object CC_dp_neg(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0095, v0048;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_neg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0095 = v0000;
/* end of prologue */
    stack[-4] = v0095;
    v0095 = stack[-4];
    if (v0095 == nil) goto v0076;
    v0095 = stack[-4];
    v0095 = qcar(v0095);
    v0048 = v0095;
    v0095 = v0048;
    stack[0] = qcar(v0095);
    v0095 = v0048;
    v0095 = qcdr(v0095);
    fn = elt(env, 2); /* bc_neg */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0095 = cons(stack[0], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0095 = ncons(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    stack[-2] = v0095;
    stack[-3] = v0095;
    goto v0043;

v0043:
    v0095 = stack[-4];
    v0095 = qcdr(v0095);
    stack[-4] = v0095;
    v0095 = stack[-4];
    if (v0095 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v0095 = stack[-4];
    v0095 = qcar(v0095);
    v0048 = v0095;
    v0095 = v0048;
    stack[0] = qcar(v0095);
    v0095 = v0048;
    v0095 = qcdr(v0095);
    fn = elt(env, 2); /* bc_neg */
    v0095 = (*qfn1(fn))(qenv(fn), v0095);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0095 = cons(stack[0], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0095 = ncons(v0095);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0095 = Lrplacd(nil, stack[-1], v0095);
    nil = C_nil;
    if (exception_pending()) goto v0096;
    env = stack[-5];
    v0095 = stack[-2];
    v0095 = qcdr(v0095);
    stack[-2] = v0095;
    goto v0043;

v0076:
    v0095 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0095); }
/* error exit handlers */
v0096:
    popv(6);
    return nil;
}



/* Code for invbf */

static Lisp_Object CC_invbf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0023, v0042, v0073;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for invbf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0023 = v0000;
/* end of prologue */
    v0073 = qvalue(elt(env, 1)); /* bfone!* */
    v0042 = v0023;
    v0023 = qvalue(elt(env, 2)); /* !:bprec!: */
    fn = elt(env, 3); /* divide!: */
    v0023 = (*qfnn(fn))(qenv(fn), 3, v0073, v0042, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0037;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v0023);
    }
/* error exit handlers */
v0037:
    popv(1);
    return nil;
}



/* Code for gcref_mkedges!-tgf */

static Lisp_Object CC_gcref_mkedgesKtgf(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0014;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcref_mkedges-tgf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0014 = v0011;
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = v0014;
    goto v0050;

v0050:
    v0014 = stack[-2];
    if (v0014 == nil) goto v0072;
    v0014 = stack[-2];
    v0014 = qcar(v0014);
    stack[0] = v0014;
    v0014 = stack[-1];
    v0014 = Lprinc(nil, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-3];
    v0014 = elt(env, 2); /* " " */
    v0014 = Lprinc(nil, v0014);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-3];
    v0014 = stack[0];
    fn = elt(env, 3); /* prin2t */
    v0014 = (*qfn1(fn))(qenv(fn), v0014);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-3];
    v0014 = stack[-2];
    v0014 = qcdr(v0014);
    stack[-2] = v0014;
    goto v0050;

v0072:
    v0014 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v0014); }
/* error exit handlers */
v0068:
    popv(4);
    return nil;
}



/* Code for get_rep_matrix_in */

static Lisp_Object CC_get_rep_matrix_in(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0172, v0096;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_rep_matrix_in");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0096 = v0011;
    stack[-2] = v0000;
/* end of prologue */
    stack[-1] = nil;
    v0172 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v0172;
    v0172 = v0096;
    v0172 = qcdr(v0172);
    stack[0] = v0172;
    goto v0041;

v0041:
    v0172 = stack[-3];
    if (v0172 == nil) goto v0081;
    v0172 = qvalue(elt(env, 1)); /* nil */
    goto v0065;

v0065:
    if (v0172 == nil) goto v0058;
    v0172 = stack[0];
    v0172 = qcar(v0172);
    v0096 = qcar(v0172);
    v0172 = stack[-2];
    if (!(equal(v0096, v0172))) goto v0059;
    v0172 = stack[0];
    v0172 = qcar(v0172);
    v0172 = qcdr(v0172);
    v0172 = qcar(v0172);
    stack[-1] = v0172;
    v0172 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v0172;
    goto v0059;

v0059:
    v0172 = stack[0];
    v0172 = qcdr(v0172);
    stack[0] = v0172;
    goto v0041;

v0058:
    v0172 = stack[-3];
    if (!(v0172 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0172 = elt(env, 3); /* "error in get representation matrix" */
    fn = elt(env, 4); /* rederr */
    v0172 = (*qfn1(fn))(qenv(fn), v0172);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    v0172 = nil;
    { popv(5); return onevalue(v0172); }

v0081:
    v0172 = stack[0];
    v0096 = Llength(nil, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-4];
    v0172 = (Lisp_Object)1; /* 0 */
    v0172 = (Lisp_Object)greaterp2(v0096, v0172);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    v0172 = v0172 ? lisp_true : nil;
    env = stack[-4];
    goto v0065;
/* error exit handlers */
v0028:
    popv(5);
    return nil;
}



/* Code for ibalp_var!-satlist */

static Lisp_Object CC_ibalp_varKsatlist(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0182, v0183;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-satlist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0011;
    v0182 = v0000;
/* end of prologue */
    stack[-5] = v0182;
    goto v0050;

v0050:
    v0182 = stack[-5];
    if (v0182 == nil) goto v0072;
    v0182 = stack[-5];
    v0182 = qcar(v0182);
    stack[-3] = v0182;
    v0182 = stack[-3];
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcar(v0182);
    if (!(v0182 == nil)) goto v0184;
    v0182 = stack[-3];
    v0182 = qcar(v0182);
    stack[-2] = v0182;
    goto v0017;

v0017:
    v0182 = stack[-2];
    if (v0182 == nil) goto v0068;
    v0182 = stack[-2];
    v0182 = qcar(v0182);
    stack[-1] = v0182;
    v0182 = stack[-1];
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    stack[0] = qcdr(v0182);
    v0182 = stack[-1];
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcar(v0182);
    v0182 = sub1(v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0182 = (*qfn2(fn))(qenv(fn), stack[0], v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    v0182 = stack[-1];
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    stack[0] = qcdr(v0182);
    v0182 = stack[-1];
    fn = elt(env, 3); /* ibalp_calcmom */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0182 = (*qfn2(fn))(qenv(fn), stack[0], v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    v0182 = stack[-2];
    v0182 = qcdr(v0182);
    stack[-2] = v0182;
    goto v0017;

v0068:
    v0182 = stack[-3];
    v0182 = qcdr(v0182);
    v0182 = qcar(v0182);
    stack[-2] = v0182;
    goto v0026;

v0026:
    v0182 = stack[-2];
    if (v0182 == nil) goto v0025;
    v0182 = stack[-2];
    v0182 = qcar(v0182);
    stack[-1] = v0182;
    v0182 = stack[-1];
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    stack[0] = qcdr(v0182);
    v0182 = stack[-1];
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcar(v0182);
    v0182 = sub1(v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0182 = (*qfn2(fn))(qenv(fn), stack[0], v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    v0182 = stack[-1];
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    stack[0] = qcdr(v0182);
    v0182 = stack[-1];
    fn = elt(env, 3); /* ibalp_calcmom */
    v0182 = (*qfn1(fn))(qenv(fn), v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0182 = (*qfn2(fn))(qenv(fn), stack[0], v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    v0182 = stack[-2];
    v0182 = qcdr(v0182);
    stack[-2] = v0182;
    goto v0026;

v0025:
    v0182 = stack[-3];
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcar(v0182);
    stack[-1] = v0182;
    goto v0119;

v0119:
    v0182 = stack[-1];
    if (v0182 == nil) goto v0114;
    v0182 = stack[-1];
    v0182 = qcar(v0182);
    v0183 = v0182;
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    v0183 = qcdr(v0183);
    stack[0] = qcdr(v0183);
    v0183 = stack[-3];
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcar(v0182);
    fn = elt(env, 4); /* delq */
    v0182 = (*qfn2(fn))(qenv(fn), v0183, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0182 = (*qfn2(fn))(qenv(fn), stack[0], v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    v0182 = stack[-1];
    v0182 = qcdr(v0182);
    stack[-1] = v0182;
    goto v0119;

v0114:
    v0182 = stack[-3];
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0183 = qcdr(v0182);
    v0182 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* setcar */
    v0182 = (*qfn2(fn))(qenv(fn), v0183, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    goto v0184;

v0184:
    v0182 = stack[-3];
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    stack[0] = qcdr(v0182);
    v0183 = stack[-4];
    v0182 = stack[-3];
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcdr(v0182);
    v0182 = qcar(v0182);
    v0182 = cons(v0183, v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    fn = elt(env, 2); /* setcar */
    v0182 = (*qfn2(fn))(qenv(fn), stack[0], v0182);
    nil = C_nil;
    if (exception_pending()) goto v0185;
    env = stack[-6];
    v0182 = stack[-5];
    v0182 = qcdr(v0182);
    stack[-5] = v0182;
    goto v0050;

v0072:
    v0182 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0182); }
/* error exit handlers */
v0185:
    popv(7);
    return nil;
}



/* Code for image!-of!-power */

static Lisp_Object CC_imageKofKpower(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0008, v0152;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for image-of-power");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0000;
/* end of prologue */
    v0008 = stack[-1];
    v0022 = qvalue(elt(env, 1)); /* image!-set */
    v0022 = Lassoc(nil, v0008, v0022);
    stack[-2] = v0022;
    v0022 = stack[-2];
    if (v0022 == nil) goto v0073;
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    stack[-2] = v0022;
    goto v0059;

v0059:
    v0008 = stack[-2];
    v0022 = stack[0];
        popv(4);
        return Lmodular_expt(nil, v0008, v0022);

v0073:
    fn = elt(env, 2); /* next!-random!-number */
    v0022 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-3];
    v0022 = Lmodular_number(nil, v0022);
    env = stack[-3];
    stack[-2] = v0022;
    v0152 = stack[-1];
    v0008 = stack[-2];
    v0022 = qvalue(elt(env, 1)); /* image!-set */
    v0022 = acons(v0152, v0008, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0092;
    env = stack[-3];
    qvalue(elt(env, 1)) = v0022; /* image!-set */
    goto v0059;
/* error exit handlers */
v0092:
    popv(4);
    return nil;
}



/* Code for variablesir */

static Lisp_Object MS_CDECL CC_variablesir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0167, v0022;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "variablesir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for variablesir");
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
    v0022 = qvalue(elt(env, 1)); /* char */
    v0167 = elt(env, 2); /* (!/ o m b v a r) */
    if (equal(v0022, v0167)) goto v0050;
    fn = elt(env, 4); /* omvir */
    v0167 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-1];
    stack[0] = v0167;
    fn = elt(env, 5); /* lex */
    v0167 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    env = stack[-1];
    v0167 = CC_variablesir(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0152;
    v0022 = stack[0];
    if (v0022 == nil) goto v0014;
    v0022 = stack[0];
    popv(2);
    return cons(v0022, v0167);

v0014:
    v0022 = stack[0];
        popv(2);
        return Lappend(nil, v0022, v0167);

v0050:
    v0167 = nil;
    { popv(2); return onevalue(v0167); }
/* error exit handlers */
v0152:
    popv(2);
    return nil;
}



/* Code for vbcgcd */

static Lisp_Object CC_vbcgcd(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0149, v0186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vbcgcd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0000;
/* end of prologue */
    v0186 = stack[-1];
    v0149 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v0149 = (*qfn2(fn))(qenv(fn), v0186, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    if (v0149 == nil) goto v0058;
    v0186 = stack[0];
    v0149 = (Lisp_Object)-1599; /* -100 */
    fn = elt(env, 4); /* vbcsize */
    v0149 = (*qfn2(fn))(qenv(fn), v0186, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    v0149 = (v0149 == nil ? lisp_true : nil);
    goto v0076;

v0076:
    if (v0149 == nil) goto v0167;
    v0149 = elt(env, 2); /* (1 . 1) */
    { popv(3); return onevalue(v0149); }

v0167:
    v0149 = stack[-1];
    v0186 = qcdr(v0149);
    v0149 = (Lisp_Object)17; /* 1 */
    if (v0186 == v0149) goto v0063;
    v0149 = qvalue(elt(env, 3)); /* nil */
    goto v0021;

v0021:
    if (v0149 == nil) goto v0187;
    v0149 = stack[-1];
    v0149 = qcar(v0149);
    v0149 = integerp(v0149);
    if (v0149 == nil) goto v0132;
    v0149 = stack[0];
    v0149 = qcar(v0149);
    v0149 = integerp(v0149);
    if (v0149 == nil) goto v0132;
    v0149 = stack[-1];
    v0186 = qcar(v0149);
    v0149 = stack[0];
    v0149 = qcar(v0149);
    v0186 = Lgcd(nil, v0186, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    v0149 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0186, v0149);

v0132:
    v0149 = stack[-1];
    v0186 = qcar(v0149);
    v0149 = stack[0];
    v0149 = qcar(v0149);
    fn = elt(env, 5); /* gcdf!* */
    v0186 = (*qfn2(fn))(qenv(fn), v0186, v0149);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    v0149 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0186, v0149);

v0187:
    v0186 = (Lisp_Object)17; /* 1 */
    v0149 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0186, v0149);

v0063:
    v0149 = stack[0];
    v0186 = qcdr(v0149);
    v0149 = (Lisp_Object)17; /* 1 */
    v0149 = (v0186 == v0149 ? lisp_true : nil);
    goto v0021;

v0058:
    v0149 = qvalue(elt(env, 1)); /* t */
    goto v0076;
/* error exit handlers */
v0103:
    popv(3);
    return nil;
}



/* Code for vevmaptozero1 */

static Lisp_Object CC_vevmaptozero1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0081, v0014;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevmaptozero1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0081 = v0011;
    stack[0] = v0000;
/* end of prologue */

v0051:
    v0014 = stack[0];
    if (v0014 == nil) { popv(2); return onevalue(v0081); }
    v0014 = stack[0];
    v0014 = qcdr(v0014);
    stack[0] = v0014;
    v0014 = (Lisp_Object)1; /* 0 */
    v0081 = cons(v0014, v0081);
    nil = C_nil;
    if (exception_pending()) goto v0052;
    env = stack[-1];
    goto v0051;
/* error exit handlers */
v0052:
    popv(2);
    return nil;
}



/* Code for listdiff */

static Lisp_Object CC_listdiff(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0068, v0017;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listdiff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    v0068 = v0000;
/* end of prologue */

v0051:
    v0017 = stack[0];
    if (v0017 == nil) { popv(2); return onevalue(v0068); }
    v0017 = v0068;
    if (v0017 == nil) goto v0058;
    v0017 = stack[0];
    v0017 = qcar(v0017);
    v0068 = Ldelete(nil, v0017, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    env = stack[-1];
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    stack[0] = v0017;
    goto v0051;

v0058:
    v0068 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v0068); }
/* error exit handlers */
v0018:
    popv(2);
    return nil;
}



/* Code for noncommuting */

static Lisp_Object CC_noncommuting(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0174, v0049, v0047, v0069;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncommuting");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0049 = v0011;
    v0047 = v0000;
/* end of prologue */
    v0069 = nil;
    v0174 = v0047;
    if (!consp(v0174)) goto v0007;
    v0174 = v0047;
    v0174 = qcar(v0174);
    goto v0015;

v0015:
    v0047 = v0174;
    v0174 = v0049;
    if (!consp(v0174)) goto v0065;
    v0174 = v0049;
    v0174 = qcar(v0174);
    goto v0099;

v0099:
    v0049 = v0174;
    v0174 = v0047;
    if (!consp(v0174)) goto v0032;
    v0174 = v0047;
    v0174 = qcar(v0174);
    if (!symbolp(v0174)) v0174 = nil;
    else { v0174 = qfastgets(v0174);
           if (v0174 != nil) { v0174 = elt(v0174, 0); /* noncom */
#ifdef RECORD_GET
             if (v0174 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0174 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0174 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0174 == SPID_NOPROP) v0174 = nil; else v0174 = lisp_true; }}
#endif
    goto v0054;

v0054:
    if (v0174 == nil) return onevalue(v0069);
    v0174 = v0049;
    if (!consp(v0174)) goto v0124;
    v0174 = v0049;
    v0174 = qcar(v0174);
    if (!symbolp(v0174)) v0174 = nil;
    else { v0174 = qfastgets(v0174);
           if (v0174 != nil) { v0174 = elt(v0174, 0); /* noncom */
#ifdef RECORD_GET
             if (v0174 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0174 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0174 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0174 == SPID_NOPROP) v0174 = nil; else v0174 = lisp_true; }}
#endif
    goto v0152;

v0152:
    if (v0174 == nil) return onevalue(v0069);
    v0174 = elt(env, 2); /* noncommutes */
    v0174 = get(v0047, v0174);
    v0174 = Lmember(nil, v0049, v0174);
    v0069 = v0174;
    return onevalue(v0069);

v0124:
    v0174 = v0049;
    if (!symbolp(v0174)) v0174 = nil;
    else { v0174 = qfastgets(v0174);
           if (v0174 != nil) { v0174 = elt(v0174, 0); /* noncom */
#ifdef RECORD_GET
             if (v0174 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0174 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0174 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0174 == SPID_NOPROP) v0174 = nil; else v0174 = lisp_true; }}
#endif
    goto v0152;

v0032:
    v0174 = v0047;
    if (!symbolp(v0174)) v0174 = nil;
    else { v0174 = qfastgets(v0174);
           if (v0174 != nil) { v0174 = elt(v0174, 0); /* noncom */
#ifdef RECORD_GET
             if (v0174 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v0174 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v0174 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v0174 == SPID_NOPROP) v0174 = nil; else v0174 = lisp_true; }}
#endif
    goto v0054;

v0065:
    v0174 = v0049;
    goto v0099;

v0007:
    v0174 = v0047;
    goto v0015;
}



/* Code for formclis */

static Lisp_Object MS_CDECL CC_formclis(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0011,
                         Lisp_Object v0004, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0059, v0064;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formclis");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for formclis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0011,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    stack[-1] = v0011;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0043;

v0043:
    v0053 = stack[-2];
    if (v0053 == nil) goto v0072;
    v0053 = stack[-2];
    v0064 = qcar(v0053);
    v0059 = stack[-1];
    v0053 = stack[0];
    fn = elt(env, 1); /* formc */
    v0059 = (*qfnn(fn))(qenv(fn), 3, v0064, v0059, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    v0053 = stack[-3];
    v0053 = cons(v0059, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    stack[-3] = v0053;
    v0053 = stack[-2];
    v0053 = qcdr(v0053);
    stack[-2] = v0053;
    goto v0043;

v0072:
    v0053 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* reversip!* */
        return (*qfn1(fn))(qenv(fn), v0053);
    }
/* error exit handlers */
v0167:
    popv(5);
    return nil;
}



/* Code for nzeros */

static Lisp_Object CC_nzeros(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0001, v0018;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nzeros");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    goto v0072;

v0072:
    v0018 = stack[0];
    v0001 = (Lisp_Object)1; /* 0 */
    if (v0018 == v0001) goto v0015;
    v0018 = (Lisp_Object)1; /* 0 */
    v0001 = stack[-1];
    v0001 = cons(v0018, v0001);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-2];
    stack[-1] = v0001;
    v0001 = stack[0];
    v0001 = sub1(v0001);
    nil = C_nil;
    if (exception_pending()) goto v0002;
    env = stack[-2];
    stack[0] = v0001;
    goto v0072;

v0015:
    v0001 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0001);
    }
/* error exit handlers */
v0002:
    popv(3);
    return nil;
}



/* Code for class */

static Lisp_Object CC_class(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0059;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for class");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0053 = stack[0];
    fn = elt(env, 3); /* ord */
    v0059 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-1];
    v0053 = (Lisp_Object)1; /* 0 */
    if (v0059 == v0053) goto v0019;
    v0059 = qvalue(elt(env, 1)); /* ordering */
    v0053 = elt(env, 2); /* lex */
    if (v0059 == v0053) goto v0010;
    v0053 = stack[0];
    v0053 = qcdr(v0053);
    goto v0009;

v0009:
    v0053 = Lreverse(nil, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    env = stack[-1];
    fn = elt(env, 4); /* leftzeros */
    v0053 = (*qfn1(fn))(qenv(fn), v0053);
    nil = C_nil;
    if (exception_pending()) goto v0020;
    v0053 = (Lisp_Object)((int32_t)(v0053) + 0x10);
    { popv(2); return onevalue(v0053); }

v0010:
    v0053 = stack[0];
    goto v0009;

v0019:
    v0053 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(v0053); }
/* error exit handlers */
v0020:
    popv(2);
    return nil;
}



/* Code for noncomperm */

static Lisp_Object CC_noncomperm(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0148, v0149, v0186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomperm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0000;
/* end of prologue */
    v0148 = stack[-4];
    if (v0148 == nil) goto v0019;
    v0148 = stack[-4];
    stack[-5] = v0148;
    goto v0073;

v0073:
    v0148 = stack[-5];
    if (v0148 == nil) goto v0010;
    v0148 = stack[-5];
    v0148 = qcar(v0148);
    stack[0] = v0148;
    v0149 = stack[0];
    v0148 = stack[-4];
    fn = elt(env, 3); /* noncomdel */
    v0148 = (*qfn2(fn))(qenv(fn), v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-6];
    v0186 = v0148;
    v0149 = v0186;
    v0148 = elt(env, 2); /* failed */
    if (v0149 == v0148) goto v0020;
    v0148 = v0186;
    v0149 = CC_noncomperm(env, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-6];
    v0148 = stack[0];
    fn = elt(env, 4); /* mapcons */
    v0148 = (*qfn2(fn))(qenv(fn), v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-6];
    goto v0064;

v0064:
    stack[-3] = v0148;
    v0148 = stack[-3];
    fn = elt(env, 5); /* lastpair */
    v0148 = (*qfn1(fn))(qenv(fn), v0148);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-6];
    stack[-2] = v0148;
    v0148 = stack[-5];
    v0148 = qcdr(v0148);
    stack[-5] = v0148;
    v0148 = stack[-2];
    if (!consp(v0148)) goto v0073;
    else goto v0037;

v0037:
    v0148 = stack[-5];
    if (v0148 == nil) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    stack[-1] = stack[-2];
    v0148 = stack[-5];
    v0148 = qcar(v0148);
    stack[0] = v0148;
    v0149 = stack[0];
    v0148 = stack[-4];
    fn = elt(env, 3); /* noncomdel */
    v0148 = (*qfn2(fn))(qenv(fn), v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-6];
    v0186 = v0148;
    v0149 = v0186;
    v0148 = elt(env, 2); /* failed */
    if (v0149 == v0148) goto v0079;
    v0148 = v0186;
    v0149 = CC_noncomperm(env, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-6];
    v0148 = stack[0];
    fn = elt(env, 4); /* mapcons */
    v0148 = (*qfn2(fn))(qenv(fn), v0149, v0148);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-6];
    goto v0047;

v0047:
    v0148 = Lrplacd(nil, stack[-1], v0148);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-6];
    v0148 = stack[-2];
    fn = elt(env, 5); /* lastpair */
    v0148 = (*qfn1(fn))(qenv(fn), v0148);
    nil = C_nil;
    if (exception_pending()) goto v0191;
    env = stack[-6];
    stack[-2] = v0148;
    v0148 = stack[-5];
    v0148 = qcdr(v0148);
    stack[-5] = v0148;
    goto v0037;

v0079:
    v0148 = qvalue(elt(env, 1)); /* nil */
    goto v0047;

v0020:
    v0148 = qvalue(elt(env, 1)); /* nil */
    goto v0064;

v0010:
    v0148 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v0148); }

v0019:
    v0148 = stack[-4];
    popv(7);
    return ncons(v0148);
/* error exit handlers */
v0191:
    popv(7);
    return nil;
}



/* Code for qcputx */

static Lisp_Object CC_qcputx(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0008, v0152;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for qcputx");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0008 = v0000;
/* end of prologue */
    v0152 = v0008;
    v0022 = elt(env, 1); /* quote */
    if (!consp(v0152)) goto v0005;
    v0152 = qcar(v0152);
    if (!(v0152 == v0022)) goto v0005;
    v0022 = v0008;
    v0022 = qcdr(v0022);
    v0152 = qcar(v0022);
    v0022 = elt(env, 2); /* cref */
    v0022 = Lflagp(nil, v0152, v0022);
    env = stack[0];
    if (v0022 == nil) goto v0018;
    v0022 = qvalue(elt(env, 3)); /* t */
    { popv(1); return onevalue(v0022); }

v0018:
    v0022 = v0008;
    v0022 = qcdr(v0022);
    v0022 = qcar(v0022);
    v0008 = elt(env, 4); /* compile */
        popv(1);
        return Lflagp(nil, v0022, v0008);

v0005:
    v0022 = qvalue(elt(env, 5)); /* nil */
    { popv(1); return onevalue(v0022); }
}



/* Code for sfto_varisnump */

static Lisp_Object CC_sfto_varisnump(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0087, v0101;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_varisnump");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0087 = stack[0];
    if (!consp(v0087)) goto v0058;
    v0087 = stack[0];
    v0087 = qcar(v0087);
    v0087 = (consp(v0087) ? nil : lisp_true);
    goto v0076;

v0076:
    if (v0087 == nil) goto v0015;
    v0087 = qvalue(elt(env, 2)); /* nil */
    goto v0043;

v0043:
    if (v0087 == nil) goto v0051;
    v0087 = stack[0];
    v0087 = qcar(v0087);
    v0087 = qcar(v0087);
    v0087 = qcar(v0087);
    { popv(1); return onevalue(v0087); }

v0051:
    v0087 = nil;
    { popv(1); return onevalue(v0087); }

v0015:
    v0087 = stack[0];
    v0087 = qcar(v0087);
    v0087 = qcdr(v0087);
    if (!consp(v0087)) goto v0052;
    v0087 = stack[0];
    v0087 = qcar(v0087);
    v0087 = qcdr(v0087);
    v0087 = qcar(v0087);
    v0087 = (consp(v0087) ? nil : lisp_true);
    goto v0016;

v0016:
    if (v0087 == nil) goto v0093;
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    if (!consp(v0087)) goto v0152;
    v0087 = stack[0];
    v0087 = qcdr(v0087);
    v0087 = qcar(v0087);
    v0087 = (consp(v0087) ? nil : lisp_true);
    goto v0008;

v0008:
    if (v0087 == nil) goto v0172;
    v0087 = stack[0];
    v0087 = qcar(v0087);
    v0087 = qcar(v0087);
    v0101 = qcdr(v0087);
    v0087 = (Lisp_Object)17; /* 1 */
    v0087 = Leqn(nil, v0101, v0087);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    goto v0043;

v0172:
    v0087 = qvalue(elt(env, 2)); /* nil */
    goto v0043;

v0152:
    v0087 = qvalue(elt(env, 1)); /* t */
    goto v0008;

v0093:
    v0087 = qvalue(elt(env, 2)); /* nil */
    goto v0043;

v0052:
    v0087 = qvalue(elt(env, 1)); /* t */
    goto v0016;

v0058:
    v0087 = qvalue(elt(env, 1)); /* t */
    goto v0076;
/* error exit handlers */
v0025:
    popv(1);
    return nil;
}



/* Code for rl_negateat */

static Lisp_Object CC_rl_negateat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_negateat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0076 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_negateat!* */
    v0076 = ncons(v0076);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    {
        Lisp_Object v0023 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0023, v0076);
    }
/* error exit handlers */
v0041:
    popv(2);
    return nil;
}



/* Code for opmtch */

static Lisp_Object CC_opmtch(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0156, v0157, v0158;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for opmtch");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-5] = v0000;
/* end of prologue */
    stack[-6] = nil;
    v0156 = stack[-5];
    v0156 = qcar(v0156);
    if (!symbolp(v0156)) v0156 = nil;
    else { v0156 = qfastgets(v0156);
           if (v0156 != nil) { v0156 = elt(v0156, 9); /* opmtch */
#ifdef RECORD_GET
             if (v0156 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v0156 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v0156 == SPID_NOPROP) v0156 = nil; }}
#endif
    stack[-4] = v0156;
    if (v0156 == nil) goto v0041;
    v0156 = qvalue(elt(env, 2)); /* subfg!* */
    if (v0156 == nil) goto v0065;
    v0156 = qvalue(elt(env, 3)); /* !*uncached */
    if (v0156 == nil) goto v0017;
    v0156 = qvalue(elt(env, 1)); /* nil */
    goto v0016;

v0016:
    if (v0156 == nil) goto v0058;
    v0156 = stack[-6];
    v0156 = qcdr(v0156);
    { popv(8); return onevalue(v0156); }

v0058:
    v0156 = stack[-5];
    v0156 = qcdr(v0156);
    stack[-3] = v0156;
    v0156 = stack[-3];
    if (v0156 == nil) goto v0161;
    v0156 = stack[-3];
    v0156 = qcar(v0156);
    fn = elt(env, 5); /* emtch */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0156 = ncons(v0156);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    stack[-1] = v0156;
    stack[-2] = v0156;
    goto v0098;

v0098:
    v0156 = stack[-3];
    v0156 = qcdr(v0156);
    stack[-3] = v0156;
    v0156 = stack[-3];
    if (v0156 == nil) goto v0172;
    stack[0] = stack[-1];
    v0156 = stack[-3];
    v0156 = qcar(v0156);
    fn = elt(env, 5); /* emtch */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0156 = ncons(v0156);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0156 = Lrplacd(nil, stack[0], v0156);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0156 = stack[-1];
    v0156 = qcdr(v0156);
    stack[-1] = v0156;
    goto v0098;

v0172:
    v0156 = stack[-2];
    goto v0094;

v0094:
    stack[0] = v0156;
    goto v0015;

v0015:
    v0156 = stack[-4];
    if (v0156 == nil) goto v0072;
    v0158 = stack[0];
    v0156 = stack[-4];
    v0156 = qcar(v0156);
    v0157 = qcar(v0156);
    v0156 = stack[-5];
    v0156 = qcar(v0156);
    fn = elt(env, 6); /* mcharg */
    v0156 = (*qfnn(fn))(qenv(fn), 3, v0158, v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    stack[-1] = v0156;
    goto v0007;

v0007:
    v0156 = stack[-1];
    if (v0156 == nil) goto v0164;
    v0156 = stack[-1];
    v0157 = qcar(v0156);
    v0156 = stack[-4];
    v0156 = qcar(v0156);
    v0156 = qcdr(v0156);
    v0156 = qcar(v0156);
    v0156 = qcdr(v0156);
    v0156 = Lsubla(nil, v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    fn = elt(env, 7); /* lispeval */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    if (v0156 == nil) goto v0123;
    v0156 = stack[-1];
    v0157 = qcar(v0156);
    v0156 = stack[-4];
    v0156 = qcar(v0156);
    v0156 = qcdr(v0156);
    v0156 = qcdr(v0156);
    v0156 = qcar(v0156);
    v0156 = Lsubla(nil, v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    stack[-6] = v0156;
    goto v0072;

v0072:
    v0156 = qvalue(elt(env, 3)); /* !*uncached */
    if (!(v0156 == nil)) { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }
    stack[0] = qvalue(elt(env, 4)); /* alglist!* */
    v0158 = stack[-5];
    v0157 = stack[-6];
    v0156 = qvalue(elt(env, 4)); /* alglist!* */
    v0156 = qcdr(v0156);
    v0156 = acons(v0158, v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    env = stack[-7];
    v0156 = Lrplacd(nil, stack[0], v0156);
    nil = C_nil;
    if (exception_pending()) goto v0197;
    { Lisp_Object res = stack[-6]; popv(8); return onevalue(res); }

v0123:
    v0156 = stack[-1];
    v0156 = qcdr(v0156);
    stack[-1] = v0156;
    goto v0007;

v0164:
    v0156 = stack[-4];
    v0156 = qcdr(v0156);
    stack[-4] = v0156;
    goto v0015;

v0161:
    v0156 = qvalue(elt(env, 1)); /* nil */
    goto v0094;

v0017:
    v0157 = stack[-5];
    v0156 = qvalue(elt(env, 4)); /* alglist!* */
    v0156 = qcdr(v0156);
    v0156 = Lassoc(nil, v0157, v0156);
    stack[-6] = v0156;
    goto v0016;

v0065:
    v0156 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v0156); }

v0041:
    v0156 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v0156); }
/* error exit handlers */
v0197:
    popv(8);
    return nil;
}



/* Code for bcplus!? */

static Lisp_Object CC_bcplusW(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0012;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcplus?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0010 = v0000;
/* end of prologue */
    v0010 = qcar(v0010);
    v0012 = v0010;
    v0010 = v0012;
    if (is_number(v0010)) goto v0073;
    v0010 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v0010);

v0073:
    v0010 = (Lisp_Object)1; /* 0 */
        return Lgreaterp(nil, v0012, v0010);
}



/* Code for triviallcm */

static Lisp_Object MS_CDECL CC_triviallcm(Lisp_Object env, int nargs,
                         Lisp_Object v0000, Lisp_Object v0011,
                         Lisp_Object v0004, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "triviallcm");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for triviallcm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0004,v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0011,v0004);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0004;
    v0009 = v0011;
    v0065 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* xdiv */
    v0009 = (*qfn2(fn))(qenv(fn), v0009, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0012;
    v0065 = stack[0];
    v0065 = (equal(v0009, v0065) ? lisp_true : nil);
    { popv(1); return onevalue(v0065); }
/* error exit handlers */
v0012:
    popv(1);
    return nil;
}



/* Code for th_match */

static Lisp_Object CC_th_match(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0032, v0002;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for th_match");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0000;
/* end of prologue */
    v0002 = stack[-1];
    v0032 = stack[0];
    fn = elt(env, 2); /* th_match0 */
    v0032 = (*qfn2(fn))(qenv(fn), v0002, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    if (v0032 == nil) goto v0051;
    v0032 = stack[-1];
    v0032 = qcdr(v0032);
    v0032 = qcar(v0032);
    fn = elt(env, 3); /* dl_get */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    stack[-1] = Llength(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0032 = stack[0];
    v0032 = qcdr(v0032);
    v0032 = qcar(v0032);
    fn = elt(env, 3); /* dl_get */
    v0032 = (*qfn1(fn))(qenv(fn), v0032);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-2];
    v0032 = Llength(nil, v0032);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    v0032 = (equal(stack[-1], v0032) ? lisp_true : nil);
    { popv(3); return onevalue(v0032); }

v0051:
    v0032 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0032); }
/* error exit handlers */
v0064:
    popv(3);
    return nil;
}



/* Code for arglist_member */

static Lisp_Object CC_arglist_member(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0018, v0054;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arglist_member");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0000;
/* end of prologue */

v0097:
    v0018 = stack[0];
    if (!consp(v0018)) goto v0068;
    v0054 = stack[-1];
    v0018 = stack[0];
    v0018 = qcar(v0018);
    fn = elt(env, 2); /* mvar_member */
    v0018 = (*qfn2(fn))(qenv(fn), v0054, v0018);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-2];
    if (!(v0018 == nil)) { popv(3); return onevalue(v0018); }
    v0054 = stack[-1];
    v0018 = stack[0];
    v0018 = qcdr(v0018);
    stack[-1] = v0054;
    stack[0] = v0018;
    goto v0097;

v0068:
    v0018 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0018); }
/* error exit handlers */
v0053:
    popv(3);
    return nil;
}



/* Code for moduntag */

static Lisp_Object CC_moduntag(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for moduntag");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    goto v0076;

v0076:
    v0031 = stack[0];
    v0030 = elt(env, 1); /* !:mod!: */
    if (!consp(v0031)) goto v0007;
    v0031 = qcar(v0031);
    if (!(v0031 == v0030)) goto v0007;
    v0031 = stack[-1];
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0031, v0030);
    }

v0007:
    v0030 = stack[0];
    if (!consp(v0030)) goto v0001;
    v0030 = stack[0];
    v0030 = qcar(v0030);
    v0031 = CC_moduntag(env, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    v0030 = stack[-1];
    v0030 = cons(v0031, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0029;
    env = stack[-2];
    stack[-1] = v0030;
    v0030 = stack[0];
    v0030 = qcdr(v0030);
    stack[0] = v0030;
    goto v0076;

v0001:
    v0031 = stack[-1];
    v0030 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0031, v0030);
    }
/* error exit handlers */
v0029:
    popv(3);
    return nil;
}



/* Code for gcref_mkgraph */

static Lisp_Object CC_gcref_mkgraph(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0041, v0023;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gcref_mkgraph");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0023 = v0000;
/* end of prologue */
    v0041 = qvalue(elt(env, 1)); /* !*gcrefudg */
    if (v0041 == nil) goto v0007;
    v0041 = v0023;
    {
        fn = elt(env, 2); /* gcref_mkgraph!-udg */
        return (*qfn1(fn))(qenv(fn), v0041);
    }

v0007:
    v0041 = v0023;
    {
        fn = elt(env, 3); /* gcref_mkgraph!-tgf */
        return (*qfn1(fn))(qenv(fn), v0041);
    }
}



/* Code for simp!*sq */

static Lisp_Object CC_simpHsq(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0065, v0009;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simp*sq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0009 = v0000;
/* end of prologue */
    v0065 = v0009;
    v0065 = qcdr(v0065);
    v0065 = qcar(v0065);
    if (v0065 == nil) goto v0023;
    v0065 = qvalue(elt(env, 1)); /* !*resimp */
    if (!(v0065 == nil)) goto v0023;
    v0065 = v0009;
    v0065 = qcar(v0065);
    return onevalue(v0065);

v0023:
    v0065 = v0009;
    v0065 = qcar(v0065);
    {
        fn = elt(env, 2); /* resimp1 */
        return (*qfn1(fn))(qenv(fn), v0065);
    }
}



/* Code for rl_prepfof */

static Lisp_Object CC_rl_prepfof(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0051;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_prepfof");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0051 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* rl_csimpl */
    v0051 = (*qfn1(fn))(qenv(fn), v0051);
    nil = C_nil;
    if (exception_pending()) goto v0050;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* rl_prepfof1 */
        return (*qfn1(fn))(qenv(fn), v0051);
    }
/* error exit handlers */
v0050:
    popv(1);
    return nil;
}



/* Code for wureducedpolysp */

static Lisp_Object CC_wureducedpolysp(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0053, v0059;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wureducedpolysp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0011,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0011);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0011;
    stack[-1] = v0000;
/* end of prologue */

v0097:
    v0053 = stack[0];
    if (v0053 == nil) goto v0051;
    v0059 = stack[-1];
    v0053 = stack[0];
    v0053 = qcar(v0053);
    fn = elt(env, 3); /* wureducedp */
    v0053 = (*qfn2(fn))(qenv(fn), v0059, v0053);
    nil = C_nil;
    if (exception_pending()) goto v0021;
    env = stack[-2];
    if (v0053 == nil) goto v0041;
    v0059 = stack[-1];
    v0053 = stack[0];
    v0053 = qcdr(v0053);
    stack[-1] = v0059;
    stack[0] = v0053;
    goto v0097;

v0041:
    v0053 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0053); }

v0051:
    v0053 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v0053); }
/* error exit handlers */
v0021:
    popv(3);
    return nil;
}



/* Code for numpoly_nullp */

static Lisp_Object CC_numpoly_nullp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0099, v0065;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for numpoly_nullp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0065 = v0000;
/* end of prologue */
    v0099 = v0065;
    if (v0099 == nil) goto v0019;
    v0099 = (Lisp_Object)1; /* 0 */
    v0099 = (v0065 == v0099 ? lisp_true : nil);
    return onevalue(v0099);

v0019:
    v0099 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0099);
}



/* Code for cgb_buch!-ev_divides!? */

static Lisp_Object CC_cgb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0011)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0058;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgb_buch-ev_divides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0058 = v0011;
    v0076 = v0000;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v0058, v0076);
    }
}



setup_type const u13_setup[] =
{
    {"ibalp_hassimple",         CC_ibalp_hassimple,too_many_1, wrong_no_1},
    {"matrixrowrd",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_matrixrowrd},
    {"isimplicit",              CC_isimplicit,  too_many_1,    wrong_no_1},
    {"vdpzero",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_vdpzero},
    {"quotdd",                  too_few_2,      CC_quotdd,     wrong_no_2},
    {"assert_declarestat",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_declarestat},
    {"dp_times_bcmo",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_dp_times_bcmo},
    {"mvar_member",             too_few_2,      CC_mvar_member,wrong_no_2},
    {"b:ordexn",                too_few_2,      CC_bTordexn,   wrong_no_2},
    {"difference-mod-p",        too_few_2,      CC_differenceKmodKp,wrong_no_2},
    {"janettreefind",           CC_janettreefind,too_many_1,   wrong_no_1},
    {"rl_simpl",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_simpl},
    {"terpri*",                 CC_terpriH,     too_many_1,    wrong_no_1},
    {"ldt-tvar",                CC_ldtKtvar,    too_many_1,    wrong_no_1},
    {"findnewvars",             CC_findnewvars, too_many_1,    wrong_no_1},
    {"unchecked_getmatelem",    CC_unchecked_getmatelem,too_many_1,wrong_no_1},
    {"gpexp1p",                 CC_gpexp1p,     too_many_1,    wrong_no_1},
    {"assert_uninstall1",       CC_assert_uninstall1,too_many_1,wrong_no_1},
    {"mv-domainlist--",         too_few_2,      CC_mvKdomainlistKK,wrong_no_2},
    {"wi_new",                  CC_wi_new,      too_many_1,    wrong_no_1},
    {"prepreform",              CC_prepreform,  too_many_1,    wrong_no_1},
    {"updtemplate",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_updtemplate},
    {"qqe_number-of-adds-in-qterm",CC_qqe_numberKofKaddsKinKqterm,too_many_1,wrong_no_1},
    {"rl_simp1",                CC_rl_simp1,    too_many_1,    wrong_no_1},
    {"diff-k-times-mod-p",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_diffKkKtimesKmodKp},
    {"cird",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_cird},
    {"newenv",                  CC_newenv,      too_many_1,    wrong_no_1},
    {"xord_gradlex",            too_few_2,      CC_xord_gradlex,wrong_no_2},
    {"plus:",                   too_few_2,      CC_plusT,      wrong_no_2},
    {"prinfit",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_prinfit},
    {"mv-pow--",                too_few_2,      CC_mvKpowKK,   wrong_no_2},
    {"mo_neworder",             CC_mo_neworder, too_many_1,    wrong_no_1},
    {"gperm3",                  too_few_2,      CC_gperm3,     wrong_no_2},
    {"general-reduce-mod-p",    CC_generalKreduceKmodKp,too_many_1,wrong_no_1},
    {"ofsf_entry2at",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_entry2at},
    {"qqe_simplat1",            too_few_2,      CC_qqe_simplat1,wrong_no_2},
    {"cl_fvarl1",               CC_cl_fvarl1,   too_many_1,    wrong_no_1},
    {"aex_mvaroccurtest",       too_few_2,      CC_aex_mvaroccurtest,wrong_no_2},
    {"spquotematrix",           CC_spquotematrix,too_many_1,   wrong_no_1},
    {"initbrsea",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_initbrsea},
    {"modminusp:",              CC_modminuspT,  too_many_1,    wrong_no_1},
    {"numeric-content",         CC_numericKcontent,too_many_1, wrong_no_1},
    {"groebnormalform",         wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebnormalform},
    {"prop-simp",               too_few_2,      CC_propKsimp,  wrong_no_2},
    {"lpriw",                   too_few_2,      CC_lpriw,      wrong_no_2},
    {"dp_neg",                  CC_dp_neg,      too_many_1,    wrong_no_1},
    {"invbf",                   CC_invbf,       too_many_1,    wrong_no_1},
    {"gcref_mkedges-tgf",       too_few_2,      CC_gcref_mkedgesKtgf,wrong_no_2},
    {"get_rep_matrix_in",       too_few_2,      CC_get_rep_matrix_in,wrong_no_2},
    {"ibalp_var-satlist",       too_few_2,      CC_ibalp_varKsatlist,wrong_no_2},
    {"image-of-power",          too_few_2,      CC_imageKofKpower,wrong_no_2},
    {"variablesir",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_variablesir},
    {"vbcgcd",                  too_few_2,      CC_vbcgcd,     wrong_no_2},
    {"vevmaptozero1",           too_few_2,      CC_vevmaptozero1,wrong_no_2},
    {"listdiff",                too_few_2,      CC_listdiff,   wrong_no_2},
    {"noncommuting",            too_few_2,      CC_noncommuting,wrong_no_2},
    {"formclis",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclis},
    {"nzeros",                  CC_nzeros,      too_many_1,    wrong_no_1},
    {"class",                   CC_class,       too_many_1,    wrong_no_1},
    {"noncomperm",              CC_noncomperm,  too_many_1,    wrong_no_1},
    {"qcputx",                  CC_qcputx,      too_many_1,    wrong_no_1},
    {"sfto_varisnump",          CC_sfto_varisnump,too_many_1,  wrong_no_1},
    {"rl_negateat",             CC_rl_negateat, too_many_1,    wrong_no_1},
    {"opmtch",                  CC_opmtch,      too_many_1,    wrong_no_1},
    {"bcplus?",                 CC_bcplusW,     too_many_1,    wrong_no_1},
    {"triviallcm",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_triviallcm},
    {"th_match",                too_few_2,      CC_th_match,   wrong_no_2},
    {"arglist_member",          too_few_2,      CC_arglist_member,wrong_no_2},
    {"moduntag",                CC_moduntag,    too_many_1,    wrong_no_1},
    {"gcref_mkgraph",           CC_gcref_mkgraph,too_many_1,   wrong_no_1},
    {"simp*sq",                 CC_simpHsq,     too_many_1,    wrong_no_1},
    {"rl_prepfof",              CC_rl_prepfof,  too_many_1,    wrong_no_1},
    {"wureducedpolysp",         too_few_2,      CC_wureducedpolysp,wrong_no_2},
    {"numpoly_nullp",           CC_numpoly_nullp,too_many_1,   wrong_no_1},
    {"cgb_buch-ev_divides?",    too_few_2,      CC_cgb_buchKev_dividesW,wrong_no_2},
    {NULL, (one_args *)"u13", (two_args *)"15560 2512072 1727149", 0}
};

/* end of generated code */
