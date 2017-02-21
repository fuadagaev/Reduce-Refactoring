
// $destdir/u12.c        Machine generated C code

// $Id$

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include <setjmp.h>
#include <exception>
#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
extern "C"
{
#include "softfloat.h"
}
#if !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS 1
#endif
#endif
#ifdef WIN32
# if defined WIN64 || defined __WIN64__
# define OPSYS "win64"
# define IMPNAME "win64"
# else
# define OPSYS "win32"
# define IMPNAME "win32"
# endif
#else
# ifdef HOST_OS
# define OPSYS HOST_OS
# ifdef HOST_CPU
# define IMPNAME HOST_OS ":" HOST_CPU
# else
# define IMPNAME HOST_OS
# endif
# else
# define OPSYS "Unknown"
# define IMPNAME "Generic"
# endif
#endif
#ifdef HAVE_STDINT_H
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef HAVE_U_INTPTR_T
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
#define CSL_IGNORE(x) ((void)(x))
#ifndef PAGE_BITS
# define PAGE_BITS 22
#endif 
#define PAGE_POWER_OF_TWO (((intptr_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE (PAGE_POWER_OF_TWO - 256)
#ifndef MAX_HEAPSIZE
# define MAX_HEAPSIZE (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#define MEGABYTE ((intptr_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES (MAX_HEAPSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES (MAX_HEAPSIZE << (20-PAGE_BITS))
#endif
#define LONGEST_LEGAL_FILENAME 1024
typedef intptr_t LispObject;
#define CELL ((size_t)sizeof(LispObject))
#define TAG_BITS 7
#define XTAG_BITS 15
#define TAG_CONS 0 
#define TAG_VECTOR 1 
#define TAG_HDR_IMMED 2 
#define TAG_FORWARD 3 
#define TAG_SYMBOL 4 
#define TAG_NUMBERS 5 
#define TAG_BOXFLOAT 6 
#define TAG_FIXNUM 7 
#define TAG_XBIT 8 
#define XTAG_SFLOAT 15 
#define XTAG_FLOAT32 16
#define is_forward(p) ((((int)(p)) & TAG_BITS) == TAG_FORWARD)
#define is_number(p) ((((int)(p)) & TAG_BITS) >= TAG_NUMBERS)
#define is_float(p) (((0xc040 >> (((int)(p)) & XTAG_BITS)) & 1) != 0)
#define is_immed_or_cons(p) (((0x85 >> (((int)(p)) & TAG_BITS)) & 1) != 0)
#define is_immed_cons_sym(p) (((0x95 >> (((int)(p)) & TAG_BITS)) & 1) != 0)
#define need_more_than_eq(p) (((0x63 >> (((int)(p)) & TAG_BITS)) & 1) != 0)
#define fixnum_of_int(x) ((LispObject)((((uintptr_t)(x))<<4)+TAG_FIXNUM))
#define int_of_fixnum(x) (((intptr_t)(x) & ~(intptr_t)15)/16)
#define valid_as_fixnum(x) (int_of_fixnum(fixnum_of_int(x)) == (x))
#define MOST_POSITIVE_FIXVAL (((intptr_t)1 << (8*sizeof(LispObject)-5)) - 1)
#define MOST_NEGATIVE_FIXVAL (-((intptr_t)1 << (8*sizeof(LispObject)-5)))
#define MOST_POSITIVE_FIXNUM fixnum_of_int(MOST_POSITIVE_FIXVAL)
#define MOST_NEGATIVE_FIXNUM fixnum_of_int(MOST_NEGATIVE_FIXVAL)
#define is_cons(p) ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & XTAG_BITS) == TAG_FIXNUM)
#define is_odds(p) ((((int)(p)) & TAG_BITS) == TAG_HDR_IMMED) 
#define is_sfloat(p) ((((int)(p)) & XTAG_BITS) == XTAG_SFLOAT)
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#define consp(p) is_cons(p)
#define symbolp(p) is_symbol(p)
#define car_legal(p) is_cons(p)
typedef struct Cons_Cell
{ LispObject car;
 LispObject cdr;
} Cons_Cell;
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef LispObject Special_Form(LispObject, LispObject);
typedef LispObject no_args(LispObject);
typedef LispObject one_args(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject three_args(LispObject, LispObject, LispObject, LispObject);
typedef LispObject n_args(LispObject, int, ...);
typedef LispObject four_args(LispObject, size_t, LispObject, LispObject,
 LispObject, LispObject);
typedef uintptr_t Header;
#define Tw (3)
#define header_mask (0x7f<<Tw)
#define type_of_header(h) (((unsigned int)(h)) & header_mask)
#define length_of_header(h) ((((size_t)(h)) >> (Tw+7)) << 2)
#define length_of_bitheader(h) ((((size_t)(h)) >> (Tw+2)) - 31)
#define length_of_byteheader(h) ((((size_t)(h)) >> (Tw+5)) - 3)
#define length_of_hwordheader(h) ((((size_t)(h)) >> (Tw+6)) - 1)
#define bitvechdr_(n) (TYPE_BITVEC_1 + ((((n)+31)&31)<<(Tw+2)))
#define TYPE_SYMBOL 0x00000000 
#define SYM_SPECIAL_VAR 0x00000080 
#define SYM_FLUID_VAR 0x00000080 
#define SYM_GLOBAL_VAR 0x00000100 
#define SYM_KEYWORD_VAR 0x00000180 
#define SYM_SPECIAL_FORM 0x00000200 
#define SYM_MACRO 0x00000400 
#define SYM_C_DEF 0x00000800 
#define SYM_CODEPTR 0x00001000 
#define SYM_ANY_GENSYM 0x00002000 
#define SYM_TRACED 0x00004000 
#define SYM_TRACESET 0x00008000 
#define SYM_TAGGED 0x00010000 
#define SYM_FASTGET_MASK 0x007e0000 
#define SYM_FASTGET_SHIFT 17
#ifdef COMMON
#define SYM_EXTERN_IN_HOME 0x00800000 
#define SYM_IN_PACKAGE 0xff000000U 
#define SYM_IN_PKG_SHIFT 24
#define SYM_IN_PKG_COUNT 8
#else 
#define SYM_UNPRINTED_GENSYM 0x00800000 
#endif 
#define symhdr_length (doubleword_align_up(sizeof(Symbol_Head)))
#define is_symbol_header(h) (((int)h & (0xf<<Tw)) == TYPE_SYMBOL)
#define is_symbol_header_full_test(h) \
 (((int)h & ((0xf<<Tw) + TAG_BITS)) == (TYPE_SYMBOL + TAG_HDR_IMMED))
#define header_fastget(h) (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define is_number_header_full_test(h) \
 (((int)h & ((0x1d<<Tw) + TAG_BITS)) == ((0x1d<<Tw) + TAG_HDR_IMMED))
#define is_vector_header_full_test(h) \
 (is_odds(h) && (((int)h & (0x3<<Tw)) != 0))
#define is_array_header(h) (type_of_header(h) == TYPE_ARRAY)
#define vector_i8(h) (((0x7f070707u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i16(h) (((0x00080008u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i32(h) (((0x00000090u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i64(h) (((0x00007820u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i128(h) (((0x00000040u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f32(h) (((0x00108000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f64(h) (((0x00a00000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f128(h) (((0x80400000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define TYPE_BIGNUM ( 0x1f <<Tw)
#define TYPE_RATNUM ( 0x1d <<Tw)
#define TYPE_COMPLEX_NUM ( 0x3d <<Tw)
#define TYPE_SINGLE_FLOAT ( 0x3f <<Tw)
#define TYPE_DOUBLE_FLOAT ( 0x5f <<Tw)
#define TYPE_LONG_FLOAT ( 0x7f <<Tw)
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#define is_ratio(n) \
 (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
 (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define is_string_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_STRING_1)
#define is_string(n) is_string_header(vechdr(n))
#define is_vec8_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_VEC8_1)
#define is_vec8(n) is_vec8_header(vechdr(n))
#define is_bps_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_BPS_1)
#define is_bps(n) is_bps_header(vechdr(n))
#define is_vec16_header(h) ((type_of_header(h) & (0x3f<<Tw)) == TYPE_VEC16_1)
#define is_vec16(n) is_vec16_header(vechdr(n))
#define is_bitvec_header(h) ((type_of_header(h) & (0x03<<Tw)) == TYPE_BITVEC_1)
#define is_bitvec(n) is_bitvec_header(vechdr(n))
#define vechdr(v) (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n) (*(LispObject *)((char *)(v) + \
 (CELL-TAG_VECTOR) + \
 (((intptr_t)(n))*sizeof(LispObject))))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define data_of_bps(v) ((unsigned char *)(v) + (CELL-TAG_VECTOR))
#define BPS_DATA_OFFSET (CELL-TAG_VECTOR)
#define vselt(v, n) (*(LispObject *)(((intptr_t)(v) & ~((intptr_t)TAG_BITS)) + \
 ((1 + (intptr_t)(n))*sizeof(LispObject))))
#define helt(v, n) (*(int16_t *)((char *)(v) + \
 (CELL-TAG_VECTOR) + ((intptr_t)(n))*sizeof(int16_t)))
#define sethelt(v, n, x) (*(int16_t *)((char *)(v) + \
 (CELL-TAG_VECTOR) + ((intptr_t)(n))*sizeof(int16_t)) = (x))
#define ielt(v, n) (*(intptr_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(intptr_t))))
#define ielt32(v, n) (*(int32_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(int32_t))))
#define felt(v, n) (*(float *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(float))))
#define delt(v, n) (*(double *)((char *)(v) + \
 (2*CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(double))))
#define TYPE_BITVEC_1 ( 0x02 <<Tw) 
#define TYPE_BITVEC_2 ( 0x06 <<Tw) 
#define TYPE_BITVEC_3 ( 0x0a <<Tw) 
#define TYPE_BITVEC_4 ( 0x0c <<Tw) 
#define TYPE_BITVEC_5 ( 0x12 <<Tw) 
#define TYPE_BITVEC_6 ( 0x16 <<Tw) 
#define TYPE_BITVEC_7 ( 0x1a <<Tw) 
#define TYPE_BITVEC_8 ( 0x1c <<Tw) 
#define TYPE_BITVEC_9 ( 0x22 <<Tw) 
#define TYPE_BITVEC_10 ( 0x26 <<Tw) 
#define TYPE_BITVEC_11 ( 0x2a <<Tw) 
#define TYPE_BITVEC_12 ( 0x2c <<Tw) 
#define TYPE_BITVEC_13 ( 0x32 <<Tw) 
#define TYPE_BITVEC_14 ( 0x36 <<Tw) 
#define TYPE_BITVEC_15 ( 0x3a <<Tw) 
#define TYPE_BITVEC_16 ( 0x3c <<Tw) 
#define TYPE_BITVEC_17 ( 0x42 <<Tw) 
#define TYPE_BITVEC_18 ( 0x46 <<Tw) 
#define TYPE_BITVEC_19 ( 0x4a <<Tw) 
#define TYPE_BITVEC_20 ( 0x4c <<Tw) 
#define TYPE_BITVEC_21 ( 0x52 <<Tw) 
#define TYPE_BITVEC_22 ( 0x56 <<Tw) 
#define TYPE_BITVEC_23 ( 0x5a <<Tw) 
#define TYPE_BITVEC_24 ( 0x5c <<Tw) 
#define TYPE_BITVEC_25 ( 0x62 <<Tw) 
#define TYPE_BITVEC_26 ( 0x66 <<Tw) 
#define TYPE_BITVEC_27 ( 0x6a <<Tw) 
#define TYPE_BITVEC_28 ( 0x6c <<Tw) 
#define TYPE_BITVEC_29 ( 0x72 <<Tw) 
#define TYPE_BITVEC_30 ( 0x76 <<Tw) 
#define TYPE_BITVEC_31 ( 0x7a <<Tw) 
#define TYPE_BITVEC_32 ( 0x7c <<Tw) 
#define TYPE_STRING_1 ( 0x07 <<Tw) 
#define TYPE_STRING_2 ( 0x27 <<Tw) 
#define TYPE_STRING_3 ( 0x47 <<Tw) 
#define TYPE_STRING_4 ( 0x67 <<Tw) 
#define TYPE_VEC8_1 ( 0x03 <<Tw) 
#define TYPE_VEC8_2 ( 0x23 <<Tw) 
#define TYPE_VEC8_3 ( 0x43 <<Tw) 
#define TYPE_VEC8_4 ( 0x63 <<Tw) 
#define TYPE_BPS_1 ( 0x0b <<Tw) 
#define TYPE_BPS_2 ( 0x2b <<Tw) 
#define TYPE_BPS_3 ( 0x4b <<Tw) 
#define TYPE_BPS_4 ( 0x6b <<Tw) 
#define TYPE_VEC16_1 ( 0x0f <<Tw) 
#define TYPE_VEC16_2 ( 0x4f <<Tw) 
#define TYPE_MAPLEREF ( 0x2f <<Tw) 
 
#define TYPE_FOREIGN ( 0x33 <<Tw) 
#define TYPE_SP ( 0x37 <<Tw) 
#define TYPE_ENCAPSULATE ( 0x3b <<Tw) 
#define vector_holds_binary(h) (((h) & (0x2<<Tw)) != 0)
#define TYPE_SIMPLE_VEC ( 0x01 <<Tw) 
#define TYPE_INDEXVEC ( 0x11 <<Tw) 
#define TYPE_NEWHASH ( 0x15 <<Tw) 
#define TYPE_NEWHASHX ( 0x19 <<Tw) 
#define TYPE_HASH ( 0x21 <<Tw) 
#define TYPE_ARRAY ( 0x05 <<Tw) 
#define TYPE_STRUCTURE ( 0x09 <<Tw) 
#define TYPE_OBJECT ( 0x0d <<Tw) 
#define TYPE_VEC32 ( 0x13 <<Tw) 
#define TYPE_VEC64 ( 0x17 <<Tw) 
#define TYPE_VEC128 ( 0x1b <<Tw) 
#define TYPE_VECFLOAT32 ( 0x53 <<Tw) 
#define TYPE_VECFLOAT64 ( 0x57 <<Tw) 
#define TYPE_VECFLOAT128 ( 0x5b <<Tw) 
#define is_mixed_header(h) (((h) & (0x73<<Tw)) == TYPE_MIXED1)
#define TYPE_MIXED1 ( 0x41 <<Tw) 
#define TYPE_MIXED2 ( 0x45 <<Tw) 
#define TYPE_MIXED3 ( 0x49 <<Tw) 
#define TYPE_STREAM ( 0x4d <<Tw) 
#define VIRTUAL_TYPE_CONS ( 0x7d <<Tw) 
#define HDR_IMMED_MASK (( 0xf <<Tw) | TAG_BITS)
#define TAG_CHAR (( 0x4 <<Tw) | TAG_HDR_IMMED) 
#define TAG_SPID (( 0xc <<Tw) | TAG_HDR_IMMED) 
#define SPID_NIL (TAG_SPID+(0x00<<(Tw+4))) 
#define SPID_FBIND (TAG_SPID+(0x01<<(Tw+4))) 
#define SPID_CATCH (TAG_SPID+(0x02<<(Tw+4))) 
#define SPID_PROTECT (TAG_SPID+(0x03<<(Tw+4))) 
#define SPID_HASHEMPTY (TAG_SPID+(0x04<<(Tw+4))) 
#define SPID_HASHTOMB (TAG_SPID+(0x05<<(Tw+4))) 
#define SPID_GCMARK (TAG_SPID+(0x06<<(Tw+4))) 
#define SPID_NOINPUT (TAG_SPID+(0x07<<(Tw+4))) 
#define SPID_ERROR (TAG_SPID+(0x08<<(Tw+4))) 
#define SPID_PVBIND (TAG_SPID+(0x09<<(Tw+4))) 
#define SPID_NOARG (TAG_SPID+(0x0a<<(Tw+4))) 
#define SPID_NOPROP (TAG_SPID+(0x0b<<(Tw+4))) 
#define SPID_LIBRARY (TAG_SPID+(0x0c<<(Tw+4))) 
#define is_header(x) (((int)(x) & (0x3<<Tw)) != 0) 
#define is_char(x) (((int)(x) & HDR_IMMED_MASK) == TAG_CHAR)
#define is_spid(x) (((int)(x) & HDR_IMMED_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xfffff) == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n) (((int32_t)(n) >> (21+4+Tw)) & 0xf)
#define bits_of_char(n) (0)
#define code_of_char(n) (((int32_t)(n) >> (4+Tw)) & 0x001fffff)
#define pack_char(font, code) \
 ((LispObject)((((uint32_t)(font)) << (21+4+Tw)) | \
 (((uint32_t)(code)) << (4+Tw)) | TAG_CHAR))
#define CHAR_EOF pack_char(0, 0x0010ffff)
typedef int32_t junk; 
typedef intptr_t junkxx; 
typedef struct Symbol_Head
{
 Header header; 
 LispObject value; 
 LispObject env; 
 LispObject plist; 
 LispObject fastgets; 
 LispObject package; 
 LispObject pname; 
 intptr_t function0; 
 intptr_t function1; 
 intptr_t function2; 
 intptr_t function3; 
 union {
 intptr_t functionn; 
 intptr_t function4; 
 intptr_t function5up;
 };
 uint64_t count; 
} Symbol_Head;
#define MAX_FASTGET_SIZE 63
#define qheader(p) (*(Header *)((char *)(p) + (0*CELL-TAG_SYMBOL)))
#define qvalue(p) (*(LispObject *)((char *)(p) + (1*CELL-TAG_SYMBOL)))
#define qenv(p) (*(LispObject *)((char *)(p) + (2*CELL-TAG_SYMBOL)))
#define qplist(p) (*(LispObject *)((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define qfastgets(p) (*(LispObject *)((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define qpackage(p) (*(LispObject *)((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p) (*(LispObject *)((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define ifn0(p) (*(intptr_t *)((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define ifn1(p) (*(intptr_t *)((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define ifn2(p) (*(intptr_t *)((char *)(p) + (9*CELL-TAG_SYMBOL)))
#define ifn3(p) (*(intptr_t *)((char *)(p) + (10*CELL-TAG_SYMBOL)))
#define ifnn(p) (*(intptr_t *)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define ifn4(p) (*(intptr_t *)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qfn0(p) (*(no_args **)((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfn1(p) (*(one_args **)((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qfn2(p) (*(two_args **)((char *)(p) + (9*CELL-TAG_SYMBOL)))
#define qfn3(p) (*(three_args **)((char *)(p) + (10*CELL-TAG_SYMBOL)))
#define qfnn(p) (*(n_args **)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qfn4(p) (*(four_args **)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qcount(p) (*(uint64_t *)((char *)(p) + (12*CELL-TAG_SYMBOL)))
typedef union Float_union
{ float f;
 uint32_t i;
 float32_t f32;
} Float_union;
#define low32(a) ((LispObject)(uint32_t)(a))
typedef struct Big_Number
{
 Header h;
 uint32_t d[1]; 
} Big_Number;
#define bignum_length(b) length_of_header(numhdr(b))
#define bignum_digits(b) \
 ((uint32_t *)((char *)(b) + (CELL-TAG_NUMBERS)))
#define bignum_digits64(b, n) \
 ((int64_t)((int32_t *)((char *)(b)+(CELL-TAG_NUMBERS)))[n])
#define make_bighdr(n) (TAG_HDR_IMMED+TYPE_BIGNUM+(((intptr_t)(n))<<(Tw+7)))
#define pack_hdrlength(n) (((intptr_t)(n))<<(Tw+7))
#define make_padder(n) (pack_hdrlength((n)/4) + TYPE_VEC8_1 + TAG_HDR_IMMED)
typedef struct Rational_Number
{ Header header;
 LispObject num;
 LispObject den;
} Rational_Number;
#define numerator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{ Header header;
 LispObject real;
 LispObject imag;
} Complex_Number;
#define real_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{ Header header;
 union float_or_int
 { float f;
 float32_t f32;
 int32_t i;
 } f;
} Single_Float;
#define single_float_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#define float32_t_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f32)
#define intfloat32_t_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.i)
#define SIZEOF_DOUBLE_FLOAT 16
#define double_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define double_float_pad(v) (*(int32_t *)((char *)(v) + \
 (4-TAG_BOXFLOAT)))
#define double_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define float64_t_val(v) (*(float64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat64_t_val(v) (*(int64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define SIZEOF_LONG_FLOAT 24
#define long_float_addr(v) ((float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define long_float_pad(v) (*(int32_t *)((char *)(v) + \
 (4-TAG_BOXFLOAT)))
#define long_float_val(v) (*(float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define float128_t_val(v) (*(float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat128_t_val0(v) (*(int64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat128_t_val1(v) (*(int64_t *)((char *)(v) + \
 (16-TAG_BOXFLOAT)))
#define word_align_up(n) ((LispObject)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((uintptr_t)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((uintptr_t)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((uintptr_t)(((intptr_t)(n) + \
 sizeof(LispObject) - 1) & (-sizeof(LispObject))))
#define quadword_align_up(n) ((uintptr_t)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((uintptr_t)((intptr_t)(n) & (-16)))
#define UNWIND_NULL 0x0 
#define UNWIND_GO 0x1 
#define UNWIND_RETURN 0x2 
#define UNWIND_THROW 0x3 
#define UNWIND_RESTART 0x4 
#define UNWIND_RESOURCE 0x5 
#define UNWIND_SIGNAL 0x6 
#define UNWIND_SIGINT 0x7 
#define UNWIND_FNAME 0x100 
#define UNWIND_ARGS 0x200 
#define UNWIND_ERROR (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND 0x400 
#define SHOW_FNAME ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS ((exit_reason & UNWIND_ARGS) != 0)
#define MAXSHIFT(n, a) ((n) >= (int)(8*sizeof(a)) || (n) < 0 ? 0 : (n))
#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
#define ASR(a, n) ((a) >> MAXSHIFT((n), a))
#else 
#include <type_traits>
template <typename T>
static inline T ASR(T a, int n)
{ typedef typename std::make_signed<T>::type ST;
 return ((ST)(a&~(((T)1<<MAXSHIFT(n,T))-1)))/((ST)1<<MAXSHIFT(n,T));
}
#endif 
#define ASL32(a,n) ((int32_t)((uint32_t)(a)<<MAXSHIFT((n),uint32_t)))
#define ASLptr(a,n) ((intptr_t)((uintptr_t)(a)<<MAXSHIFT((n),uintptr_t)))
#define ASL64(a,n) ((int64_t)((uint64_t)(a)<<MAXSHIFT((n),uint64_t)))
#define ASL128(a,n) ((int128_t)((uint128_t)(a)<<MAXSHIFT((n),uint128_t)))
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern "C" LispObject interrupted(LispObject p);
extern "C" NORETURN void error(int nargs, int code, ...);
extern "C" NORETURN void cerror(int nargs, int code1, int code2, ...);
extern "C" NORETURN void too_few_2(LispObject env, LispObject a1);
extern "C" NORETURN void too_many_1(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_0a(LispObject env, LispObject a1);
extern "C" NORETURN void wrong_no_0b(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_3a(LispObject env, LispObject a1);
extern "C" NORETURN void wrong_no_3b(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_na(LispObject env, LispObject a1);
extern "C" NORETURN void wrong_no_nb(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_1(LispObject env, int nargs, ...);
extern "C" NORETURN void wrong_no_2(LispObject env, int nargs, ...);
extern "C" NORETURN void bad_specialn(LispObject env, int nargs, ...);
#define TOO_FEW_2 ((one_args *)too_few_2)
#define TOO_MANY_1 ((two_args *)too_many_1)
#define WRONG_NO_0A ((one_args *)wrong_no_0a)
#define WRONG_NO_0B ((two_args *)wrong_no_0b)
#define WRONG_NO_3A ((one_args *)wrong_no_3a)
#define WRONG_NO_3B ((two_args *)wrong_no_3b)
#define WRONG_NO_NA ((one_args *)wrong_no_na)
#define WRONG_NO_NB ((two_args *)wrong_no_nb)
#define WRONG_NO_1 ((n_args *)wrong_no_1)
#define WRONG_NO_2 ((n_args *)wrong_no_2)
#define BAD_SPECIALN ((n_args *)bad_specialn)
extern "C" NORETURN void aerror(const char *s); 
extern "C" NORETURN void aerror0(const char *s);
extern "C" NORETURN void aerror1(const char *s, LispObject a);
extern "C" NORETURN void aerror2(const char *s, LispObject a, LispObject b);
extern "C" NORETURN void fatal_error(int code, ...);
extern "C" LispObject carerror(LispObject a);
extern "C" LispObject cdrerror(LispObject a);
#define GC_MESSAGES 0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS 0x04
#define GC_MSG_BITS 0x07
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG 0x10
#define ARGS_FLAG 0x20
#define BACKTRACE_MSG_BITS 0x38
#define err_bad_car 0 
#define err_bad_cdr 1 
#define err_no_store 2 
#define err_undefined_function_0 3 
#define err_undefined_function_1 4 
#define err_undefined_function_2 5 
#define err_undefined_function_3 6 
#define err_undefined_function_4 7 
#define err_undefined_function_n 7 
#define err_wrong_no_args 8 
#define err_unbound_lexical 9 
#define err_bad_rplac 10 
#define err_bad_arith 11 
#define err_redef_special 12 
#define err_bad_arg 13 
#define err_bad_declare 14 
#define err_bad_fn 15 
#define err_unset_var 16 
#define err_too_many_args0 17 
#define err_too_many_args1 18 
#define err_too_many_args2 19 
#define err_too_many_args3 20 
#define err_bad_apply 21 
#define err_macroex_hook 22 
#define err_block_tag 23 
#define err_go_tag 24 
#define err_excess_args 25
#define err_insufficient_args 26
#define err_bad_bvl 27 
#define err_bad_keyargs 28
#define err_write_err 29
#define err_bad_endp 30 
#define err_no_fasldir 31
#define err_no_fasl 32 
#define err_open_failed 33 
#define err_pipe_failed 34 
#define err_stack_overflow 35
#define err_top_bit 36
#define err_mem_spans_zero 37
#define err_no_longer_used 38 
#define err_no_tempdir 39
#ifdef INCLUDE_ERROR_STRING_TABLE
static const char *error_message_table[] =
{ "attempt to take car of an atom",
 "attempt to take cdr of an atom",
 "insufficient freestore to run this package",
 "undefined function (0 arg)",
 "undefined function (1 arg)",
 "undefined function (2 args)",
 "undefined function (3 arg)",
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
 "too many arguments for 0-arg function",
 "too many arguments for 1-arg function",
 "too many arguments for 2-arg function",
 "too many arguments for 3-arg function",
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
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
 fflush(stderr); \
 } while (0)
#define DS(s) do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
 fflush(stderr); \
 } while (0)
#define DX(s) do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
 (long long unsigned)(s)); \
 fflush(stderr); \
 } while (0)
extern void **pages, **heap_pages, **vheap_pages;
extern void **new_heap_pages, **new_vheap_pages;
extern void *allocate_page(const char *why);
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS 0
#define PAGE_TYPE_VECTOR 1
typedef struct page_map_t
{ void *start;
 void *end;
 int type;
} page_map_t;
#endif
extern int32_t pages_count, heap_pages_count, vheap_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count;
extern LispObject *list_bases[];
extern LispObject *nilsegment, *stacksegment;
extern LispObject *stackbase;
extern int32_t stack_segsize; 
extern LispObject *stack;
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern bool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern LispObject *C_stackbase, *C_stacktop;
#endif
extern LispObject multiplication_buffer;
#define push(a) { *++stack = (a); }
#define push2(a,b) { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack += 3; }
#define push4(a,b,c,d) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) { \
 stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack[6] = (f); \
 stack += 6; }
#define pop(a) { (a) = *stack--; }
#define pop2(a,b) { stack -= 2; (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c) { stack -= 3; (a) = stack[3]; (b) = stack[2]; \
 (c) = stack[1]; }
#define pop4(a,b,c,d) { stack -= 4; (a) = stack[4]; (b) = stack[3]; \
 (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5; (a) = stack[5]; (b) = stack[4]; \
 (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6; \
 (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
 (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n) stack -= (n)
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK 2
#define GC_CONS 3
#define GC_VEC 4
#define GC_BPS 5
#define GC_PRESERVE 6
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(const char *file, int line);
extern void show_stack();
#define if_check_stack \
 if (check_stack("@" __FILE__,__LINE__)) \
 { show_stack(); aerror("stack overflow"); }
#else
#define if_check_stack \
 { const char *_p_ = (char *)&_p_; \
 if (_p_ < C_stack_limit) aerror("stack overflow"); \
 }
#endif
extern int32_t software_ticks, countdown;
#ifdef DEBUG
extern char debug_trail[32][32];
extern char debug_trail_file[32][32];
extern int debug_trail_line[32];
extern int debug_trailp;
extern void debug_record_raw(const char *data, const char *file, int line);
extern void debug_record_int_raw(const char *s, int n, const char *file, int line);
extern void debug_show_trail_raw(const char *msg, const char *file, int line);
#define debug_record(data) debug_record_raw(data, __FILE__, __LINE__)
#define debug_record_int(s, n) debug_record_int_raw(s, n, __FILE__, __LINE__)
#define debug_record_string(s) debug_record(&celt(s, 0))
#define debug_record_symbol(x) debug_record_string(qpname(x))
#define debug_show_trail(data) debug_show_trail_raw(data, __FILE__, __LINE__)
#define debug_assert(x) \
 if (!(x)) { debug_show_trail("Assertion failed"); exit(7); }
#else
#define debug_record(data)
#define debug_record_int(s, n)
#define debug_record_string(s)
#define debug_record_symbol(x)
#define debug_show_trail(x)
#define debug_assert(x)
#endif
#define stackcheck0(k) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { reclaim(nil, "stack", GC_STACK, 0); \
 }
#define stackcheck1(k, a1) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { a1 = reclaim(a1, "stack", GC_STACK, 0); \
 }
#define stackcheck2(k, a1, a2) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push(a2); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2); \
 }
#define stackcheck3(k, a1, a2, a3) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push2(a2, a3); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop2(a3, a2); \
 }
#define stackcheck4(k, a1, a2, a3, a4) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push3(a2, a3, a4); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop3(a4, a3, a2); \
 }
extern LispObject nil;
#define first_nil_offset 50 
#define work_0_offset 250
#define last_nil_offset 301
#define NIL_SEGMENT_SIZE (last_nil_offset*sizeof(LispObject) + 32)
#define SPARE 512
extern intptr_t byteflip;
extern LispObject * volatile stacklimit;
extern LispObject fringe;
extern LispObject volatile heaplimit;
extern LispObject volatile vheaplimit;
extern LispObject vfringe;
extern intptr_t nwork;
extern unsigned int exit_count;
extern uint64_t gensym_ser;
extern intptr_t print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
extern LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern LispObject quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol, apply_symbol;
extern LispObject work_symbol, evalhook, applyhook, macroexpand_hook;
extern LispObject append_symbol, exit_tag, exit_value, catch_tags;
extern LispObject current_package, startfn;
extern LispObject gensym_base, string_char_sym, boffo;
extern LispObject err_table, progn_symbol;
extern LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern LispObject echo_symbol, codevec, litvec, supervisor, B_reg;
extern LispObject savedef, comp_symbol, compiler_symbol, faslvec;
extern LispObject tracedfn, lisp_terminal_io;
extern LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
extern LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
extern LispObject prompt_thing, faslgensyms;
extern LispObject prinl_symbol, emsg_star, redef_msg;
extern LispObject expr_symbol, fexpr_symbol, macro_symbol;
extern LispObject big_divisor, big_dividend, big_quotient;
extern LispObject big_fake1, big_fake2, active_stream, current_module;
extern LispObject mv_call_symbol, features_symbol, lisp_package;
extern LispObject sys_hash_table, help_index, cfunarg, lex_words;
extern LispObject get_counts, fastget_names, input_libraries;
extern LispObject output_library, current_file, break_function;
extern LispObject standard_output, standard_input, debug_io;
extern LispObject error_output, query_io, terminal_io;
extern LispObject trace_output, fasl_stream;
extern LispObject startup_symbol, mv_call_symbol, traceprint_symbol;
extern LispObject load_source_symbol, load_selected_source_symbol;
extern LispObject bytecoded_symbol, funcall_symbol, autoload_symbol;
extern LispObject gchook, resources, callstack, procstack, procmem;
extern LispObject trap_time, current_function, keyword_package;
extern LispObject all_packages, package_symbol, internal_symbol;
extern LispObject external_symbol, inherited_symbol;
extern LispObject key_key, allow_other_keys, aux_key;
extern LispObject format_symbol, expand_def_symbol, allow_key_key;
extern LispObject declare_symbol, special_symbol, large_modulus;
extern LispObject used_space, avail_space, eof_symbol, call_stack;
extern LispObject nicknames_symbol, use_symbol, and_symbol, or_symbol;
extern LispObject not_symbol, reader_workspace, named_character;
extern LispObject read_float_format, short_float, single_float, double_float;
extern LispObject long_float, bit_symbol, pathname_symbol, print_array_sym;
extern LispObject read_base, initial_element;
extern LispObject builtin0_symbol, builtin1_symbol, builtin2_symbol;
extern LispObject builtin3_symbol, builtin4_symbol; 
#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, int nargs, ...);
extern LispObject om_openStringDev(LispObject env, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject env, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern LispObject om_closeConn(LispObject env, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject env, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject env, LispObject lconn);
extern LispObject om_connectTCP(LispObject env, int nargs, ...);
extern LispObject om_bindTCP(LispObject env, LispObject lconn, LispObject lport);
extern LispObject om_putApp(LispObject env, LispObject ldev);
extern LispObject om_putEndApp(LispObject env, LispObject ldev);
extern LispObject om_putAtp(LispObject env, LispObject ldev);
extern LispObject om_putEndAtp(LispObject env, LispObject ldev);
extern LispObject om_putAttr(LispObject env, LispObject ldev);
extern LispObject om_putEndAttr(LispObject env, LispObject ldev);
extern LispObject om_putBind(LispObject env, LispObject ldev);
extern LispObject om_putEndBind(LispObject env, LispObject ldev);
extern LispObject om_putBVar(LispObject env, LispObject ldev);
extern LispObject om_putEndBVar(LispObject env, LispObject ldev);
extern LispObject om_putError(LispObject env, LispObject ldev);
extern LispObject om_putEndError(LispObject env, LispObject ldev);
extern LispObject om_putObject(LispObject env, LispObject ldev);
extern LispObject om_putEndObject(LispObject env, LispObject ldev);
extern LispObject om_putInt(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject env, int nargs, ...);
extern LispObject om_getApp(LispObject env, LispObject ldev);
extern LispObject om_getEndApp(LispObject env, LispObject ldev);
extern LispObject om_getAtp(LispObject env, LispObject ldev);
extern LispObject om_getEndAtp(LispObject env, LispObject ldev);
extern LispObject om_getAttr(LispObject env, LispObject ldev);
extern LispObject om_getEndAttr(LispObject env, LispObject ldev);
extern LispObject om_getBind(LispObject env, LispObject ldev);
extern LispObject om_getEndBind(LispObject env, LispObject ldev);
extern LispObject om_getBVar(LispObject env, LispObject ldev);
extern LispObject om_getEndBVar(LispObject env, LispObject ldev);
extern LispObject om_getError(LispObject env, LispObject ldev);
extern LispObject om_getEndError(LispObject env, LispObject ldev);
extern LispObject om_getObject(LispObject env, LispObject ldev);
extern LispObject om_getEndObject(LispObject env, LispObject ldev);
extern LispObject om_getInt(LispObject env, LispObject ldev);
extern LispObject om_getFloat(LispObject env, LispObject ldev);
extern LispObject om_getByteArray(LispObject env, LispObject ldev);
extern LispObject om_getVar(LispObject env, LispObject ldev);
extern LispObject om_getString(LispObject env, LispObject ldev);
extern LispObject om_getSymbol(LispObject env, LispObject ldev);
extern LispObject om_getType(LispObject env, LispObject ldev);
extern LispObject om_stringToStringPtr(LispObject env, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject env, LispObject lpstr);
extern LispObject om_read(LispObject env, LispObject dev);
extern LispObject om_supportsCD(LispObject env, LispObject lcd);
extern LispObject om_supportsSymbol(LispObject env, LispObject lcd, LispObject lsym);
extern LispObject om_listCDs(LispObject env, int nargs, ...);
extern LispObject om_listSymbols(LispObject env, LispObject lcd);
extern LispObject om_whichCDs(LispObject env, LispObject lsym);
#endif
extern LispObject workbase[51];
extern LispObject user_base_0, user_base_1, user_base_2;
extern LispObject user_base_3, user_base_4, user_base_5;
extern LispObject user_base_6, user_base_7, user_base_8;
extern LispObject user_base_9;
#define work_0 workbase[0]
#define work_1 workbase[1]
#define mv_1 workbase[1]
#define mv_2 workbase[2]
#define mv_3 workbase[3]
#define work_50 workbase[50]
extern void copy_into_nilseg();
extern void copy_out_of_nilseg();
#define LOG2_VECTOR_CHUNK_WORDS 17
#define VECTOR_CHUNK_WORDS ((size_t)(1<<LOG2_VECTOR_CHUNK_WORDS)) 
extern LispObject free_vectors[LOG2_VECTOR_CHUNK_WORDS+1];
extern void rehash_this_table(LispObject v);
extern void simple_print(LispObject x);
extern void simple_msg(const char *s, LispObject x);
extern LispObject eq_hash_tables, equal_hash_tables;
extern uint32_t hash_equal(LispObject key);
extern LispObject * volatile savestacklimit;
extern LispObject volatile saveheaplimit;
extern LispObject volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
extern bool garbage_collection_permitted;
#define MAX_INPUT_FILES 40 
#define MAX_SYMBOLS_TO_DEFINE 40
#define MAX_FASL_PATHS 20
extern const char *files_to_read[MAX_INPUT_FILES],
 *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
 *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern const char **csl_argv;
extern bool fasl_output_file;
extern size_t output_directory;
extern LispObject *repeat_heap;
extern size_t repeat_count;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
extern FILE *binary_write_file;
extern size_t boffop;
extern void packcharacter(int c);
extern void packbyte(int c);
#define boffo_char(i) ucelt(boffo, i)
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#ifdef SOCKETS
extern bool sockets_ready;
extern void flush_socket();
#endif
extern void report_file(const char *s);
extern bool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern int errorset_min, errorset_max;
extern size_t number_of_input_files,
 number_of_symbols_to_define,
 number_of_fasl_paths;
extern int init_flags;
extern const char *standard_directory;
extern int gc_number;
extern int force_reclaim_method, reclaim_trap_count, reclaim_stack_limit;
#define INIT_QUIET 1
#define INIT_VERBOSE 2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p) ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
#define CODESIZE 0x1000
typedef struct _entry_point0
{ no_args *p;
 const char *s;
} entry_point0;
typedef struct _entry_point1
{ one_args *p;
 const char *s;
} entry_point1;
typedef struct _entry_point2
{ two_args *p;
 const char *s;
} entry_point2;
typedef struct _entry_point3
{ three_args *p;
 const char *s;
} entry_point3;
typedef struct _entry_point4
{ four_args *p;
 const char *s;
} entry_point4;
typedef struct _entry_pointn
{ n_args *p;
 const char *s;
} entry_pointn;
extern entry_point0 entries_table0[];
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_point3 entries_table3[];
extern entry_point4 entries_table4[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_tableio[];
extern void set_up_entry_lookup();
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);
extern int doubled_execution;
extern const char *linker_type;
extern const char *compiler_command[], *import_data[],
 *config_header[], *csl_headers[];
extern LispObject encapsulate_pointer(void *);
extern void *extract_pointer(LispObject a);
extern LispObject Lencapsulatedp(LispObject env, LispObject a);
typedef void initfn(LispObject *, LispObject **, LispObject * volatile *);
extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit();
extern void IreInit();
extern void Ilist();
extern bool open_output(const char *s, size_t len);
#define IMAGE_CODE ((size_t)(-1000))
#define HELP_CODE ((size_t)(-1001))
#define BANNER_CODE ((size_t)(-1002))
#define IOPEN_OUT 0
#define IOPEN_IN 1
extern bool Iopen(const char *name, size_t len, int dirn, char *expanded_name);
extern bool Iopen_from_stdin(), Iopen_to_stdout();
extern bool IopenRoot(char *expanded_name, size_t hard, int sixtyfour);
extern bool Iwriterootp(char *expanded);
extern bool Iopen_banner(int code);
extern bool Imodulep(const char *name, size_t len, char *datestamp,
 size_t *size, char *expanded_name);
extern char *trim_module_name(char *name, size_t *lenp);
extern bool Icopy(const char *name, size_t len);
extern bool Idelete(const char *name, size_t len);
extern bool IcloseInput();
extern bool IcloseOutput();
extern bool Ifinished();
extern int Igetc();
extern bool Iread(void *buff, size_t size);
extern bool Iputc(int ch);
extern bool Iwrite(const void *buff, size_t size);
extern bool def_init();
extern bool inf_init();
extern bool def_finish();
extern bool inf_finish();
extern int Zgetc();
extern bool Zread(void *buff, size_t size);
extern bool Zputc(int ch);
extern bool Zwrite(const void *buff, size_t size);
extern long int Ioutsize();
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(const char *suffix, int32_t suffixlen);
extern int Cmkdir(const char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init();
extern void CSL_MD5_Update(const unsigned char *data, size_t len);
extern void CSL_MD5_Final(unsigned char *md);
extern bool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(LispObject a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen();
extern int window_heading;
extern void my_abort();
extern "C" NORETURN void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock();
extern double pop_clock();
extern double consolidated_time[10], gc_time;
extern bool volatile already_in_gc, tick_on_gc_exit;
extern bool volatile interrupt_pending, tick_pending;
extern int deal_with_tick();
extern bool trap_floating_overflow;
extern const volatile char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject *, bool findcatch);
extern bool segvtrap;
extern bool batch_flag;
extern int escaped_printing;
extern "C" void low_level_signal_handler(int code);
extern "C" void sigint_handler(int code);
extern "C" int async_interrupt(int a);
extern "C" void record_get(LispObject tag, bool found);
extern int primep(int32_t);
extern void set_up_functions(int restartp);
extern void get_user_files_checksum(unsigned char *);
extern "C" LispObject acons(LispObject a, LispObject b, LispObject c);
extern "C" LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(size_t ppc, LispObject lit,
 LispObject *entry_stack);
extern bool complex_stringp(LispObject a);
extern LispObject copy_string(LispObject a, size_t n);
extern void freshline_trace();
extern void freshline_debug();
extern "C" LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject eval(LispObject u, LispObject env);
extern uint32_t Crand();
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(uint32_t a, uint32_t b);
extern void discard(LispObject a);
extern "C" bool eql_fn(LispObject a, LispObject b);
extern "C" bool cl_equal_fn(LispObject a, LispObject b);
extern "C" bool equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern bool traced_equal_fn(LispObject a, LispObject b,
 const char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern "C" bool equalp(LispObject a, LispObject b);
extern LispObject apply(LispObject fn, int nargs, LispObject env,
 LispObject from);
extern LispObject apply_lambda(LispObject def, int nargs,
 LispObject env, LispObject name);
extern void deallocate_pages();
extern void drop_heap_segments();
extern LispObject gcd(LispObject a, LispObject b);
extern LispObject get_pname(LispObject a);
extern "C" LispObject get(LispObject a, LispObject b, LispObject c=nil);
extern LispObject getvector(int tag, int type, size_t length);
extern LispObject getvector_init(size_t n, LispObject v);
extern uint32_t hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern "C" bool geq2(LispObject a, LispObject b);
extern "C" bool greaterp2(LispObject a, LispObject b);
extern "C" bool lesseq2(LispObject a, LispObject b);
extern "C" bool lessp2(LispObject a, LispObject b);
extern "C" LispObject list2(LispObject a, LispObject b);
extern "C" LispObject list2star(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3star(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject list4(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
extern LispObject make_package(LispObject name);
extern LispObject make_string(const char *b);
extern LispObject make_nstring(const char *b, int32_t n);
extern LispObject make_undefined_symbol(const char *s);
extern LispObject make_symbol(char const *s, int restartp,
 one_args *f1, two_args *f2, n_args *fn);
extern void stdout_printf(const char *fmt, ...);
extern void term_printf(const char *fmt, ...);
extern void err_printf(const char *fmt, ...);
extern void debug_printf(const char *fmt, ...);
extern void trace_printf(const char *fmt, ...);
extern const char *my_getenv(const char *name);
extern "C" LispObject ncons(LispObject a);
extern LispObject ndelete(LispObject a, LispObject b);
extern "C" LispObject negate(LispObject a);
extern LispObject nreverse(LispObject a);
extern FILE *open_file(char *filename, const char *original_name,
 size_t n, const char *dirn, FILE *old_file);
extern "C" LispObject plus2(LispObject a, LispObject b);
extern void preserve(const char *msg, size_t len);
extern LispObject prin(LispObject u);
extern const char *get_string_data(LispObject a, const char *why, size_t &len);
extern void prin_to_stdout(LispObject u);
extern void prin_to_terminal(LispObject u);
extern void prin_to_debug(LispObject u);
extern void prin_to_query(LispObject u);
extern void prin_to_trace(LispObject u);
extern void prinhex_to_trace(const char *msg, LispObject value);
extern void prin_to_error(LispObject u);
extern void loop_print_stdout(LispObject o);
extern void loop_print_terminal(LispObject o);
extern void loop_print_debug(LispObject o);
extern void loop_print_query(LispObject o);
extern void loop_print_trace(LispObject o);
extern void loop_print_error(LispObject o);
extern void internal_prin(LispObject u, int prefix);
extern LispObject princ(LispObject u);
extern LispObject print(LispObject u);
extern LispObject printc(LispObject u);
extern void print_bignum(LispObject u, bool blankp, int nobreak);
extern void print_bighexoctbin(LispObject u,
 int radix, int width, bool blankp, int nobreak);
extern LispObject putprop(LispObject a, LispObject b,
 LispObject c);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject quotrem2(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern void read_eval_print(int noisy);
extern "C" LispObject reclaim(LispObject value_to_return, const char *why,
 int stg_class, intptr_t size);
extern void set_fns(LispObject sym, one_args *f1,
 two_args *f2, n_args *fn);
extern void setup(int restartp, double storesize);
extern void set_up_variables(int restart_flag);
extern void warm_setup();
extern void write_everything();
extern LispObject simplify_string(LispObject s);
extern bool stringp(LispObject a);
extern "C" LispObject times2(LispObject a, LispObject b);
extern int32_t thirty_two_bits(LispObject a);
extern int64_t sixty_four_bits(LispObject a);
extern uint64_t crc64(uint64_t crc, const void *buf, size_t size);
#ifdef DEBUG
extern void validate_string_fn(LispObject a, const char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
static inline LispObject onevalue(LispObject r)
{ exit_count = 1;
 return r;
}
static inline LispObject nvalues(LispObject r, int n)
{ exit_count = n;
 return r;
}
#define equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 need_more_than_eq(a) && \
 equal_fn(a, b)))
#define cl_equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 need_more_than_eq(a) && \
 cl_equal_fn(a, b)))
#define eql(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 need_more_than_eq(a) && \
 eql_fn(a, b)))
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
 uint32_t b, uint32_t c);
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
 uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#define argcheck(var, n, msg) if ((var)!=(n)) aerror(msg);
extern n_args *no_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern four_args *four_arg_functions[];
extern n_args *three_arg_functions[];
extern bool no_arg_traceflags[];
extern bool one_arg_traceflags[];
extern bool two_arg_traceflags[];
extern bool four_arg_traceflags[];
extern bool three_arg_traceflags[];
extern const char *no_arg_names[];
extern const char *one_arg_names[];
extern const char *two_arg_names[];
extern const char *four_arg_names[];
extern const char *three_arg_names[];
typedef struct setup_type
{ const char *name;
 one_args *one;
 two_args *two;
 n_args *n;
} setup_type;
typedef struct setup_type_1
{ const char *name;
 one_args *one;
 two_args *two;
 n_args *n;
 uint32_t c1;
 uint32_t c2;
} setup_type_1;
extern setup_type const
 arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
 arith13_setup[], char_setup[], eval1_setup[], eval2_setup[],
 eval3_setup[], funcs1_setup[], funcs2_setup[], funcs3_setup[],
 lisphash_setup[], newhash_setup[], print_setup[], read_setup[],
 restart_setup[], mpi_setup[];
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
extern const char *find_image_directory(int argc, const char *argv[]);
extern char program_name[64];
extern LispObject declare_fn(LispObject args, LispObject env);
extern LispObject function_fn(LispObject args, LispObject env);
extern LispObject let_fn_1(LispObject bvl, LispObject body,
 LispObject env, int compilerp);
extern LispObject mv_call_fn(LispObject args, LispObject env);
extern LispObject progn_fn(LispObject args, LispObject env);
extern LispObject quote_fn(LispObject args, LispObject env);
extern LispObject tagbody_fn(LispObject args, LispObject env);
NORETURN extern void resource_exceeded();
extern int64_t time_base, space_base, io_base, errors_base;
extern int64_t time_now, space_now, io_now, errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern bool symbol_protect_flag, warn_about_protected_symbols;
#ifdef HASH_STATISTICS
extern uint64_t Nhget, Nhgetp, Nhput1, Nhputp1, Nhput2, Nhputp2, Nhputtmp;
extern uint64_t Noget, Nogetp, Noput, Noputp, Noputtmp;
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#if defined HAVE___INT128 && !defined __HAVE_INT128_T
typedef __int128 int128_t;
#define HAVE_INT128_T
#endif
#if defined HAVE_UNSIGNED___INT128 && !defined __HAVE_UINT128_T
typedef unsigned __int128 uint128_t;
#define HAVE_UINT128_T
#endif
#define TWO_32 4294967296.0 
#define TWO_31 2147483648.0 
#define TWO_24 16777216.0 
#define TWO_22 4194304.0 
#define TWO_21 2097152.0 
#define TWO_20 1048576.0 
#define _pi ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi ((12868.0 - 0.036490896206895257)/8192.0)
#define boole_clr 0
#define boole_and 1
#define boole_andc2 2
#define boole_1 3
#define boole_andc1 4
#define boole_2 5
#define boole_xor 6
#define boole_ior 7
#define boole_nor 8
#define boole_eqv 9
#define boole_c2 10
#define boole_orc2 11
#define boole_c1 12
#define boole_orc1 13
#define boole_nand 14
#define boole_set 15
#define top_bit_set(n) (((int32_t)(n)) < 0)
#define top_bit(n) ((int32_t)(((uint32_t)(n)) >> 31))
#define set_top_bit(n) ((int32_t)((uint32_t)(n) | (uint32_t)0x80000000U))
#define clear_top_bit(n) ((int32_t)(n) & 0x7fffffff)
#define signed_overflow(n) \
 top_bit_set((uint32_t)(n) ^ ((uint32_t)(n) << 1))
#define ADD32(a, b) ((uint32_t)(a) + (uint32_t)(b))
#define signed29_in_64(n) \
 (((int64_t)(((uint64_t)(n) & 0x1fffffffU) << 35) / ((int64_t)1 << 35)) == \
 (int64_t)(n))
#define signed31_in_64(n) \
 (((int64_t)(((uint64_t)(n) & 0x7fffffffU) << 33) / ((int64_t)1 << 33)) == \
 (int64_t)(n))
#define signed31_in_ptr(n) \
 (((intptr_t)(((uintptr_t)(n)&0x7fffffffU) << (8*sizeof(intptr_t) - 31)) / \
 ((intptr_t)1 << (8*sizeof(intptr_t) - 31))) == (intptr_t)(n))
#define floating_edge_case(r) (1.0/(r) == 0.0 || (r) != (r))
#define floating_clear_flags() ((void)0)
#define floating_edge_case128(r) \
 (f128M_infinite(r) || f128M_nan(r))
#define Dmultiply(hi, lo, a, b, c) \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) + \
 (uint32_t)(c); \
 (lo) = 0x7fffffffu & (uint32_t)r64; \
 (hi) = (uint32_t)(r64 >> 31); } while (0)
#define Ddivide(r, q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#define Ddivideq(q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); } while (0)
#define Ddiv10_9q(r, q, a, b) Ddivideq(q, a, b, 1000000000u)
#define Ddivider(r, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9r(r, q, a, b) Ddivider(r, a, b, 1000000000u)
#define bignum_minusp(a) \
 ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern "C" LispObject negateb(LispObject);
extern "C" LispObject copyb(LispObject);
extern "C" LispObject negate(LispObject);
extern "C" LispObject plus2(LispObject a, LispObject b);
extern "C" LispObject difference2(LispObject a, LispObject b);
extern "C" LispObject times2(LispObject a, LispObject b);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject CLquot2(LispObject a, LispObject b);
extern "C" LispObject quotbn(LispObject a, int32_t n);
extern "C" LispObject quotbn1(LispObject a, int32_t n);
#define QUOTBB_QUOTIENT_NEEDED 1
#define QUOTBB_REMAINDER_NEEDED 2
extern "C" LispObject quotbb(LispObject a, LispObject b, int needs);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern "C" LispObject rembi(LispObject a, LispObject b);
extern "C" LispObject rembb(LispObject a, LispObject b);
extern "C" LispObject shrink_bignum(LispObject a, size_t lena);
extern "C" LispObject modulus(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern "C" LispObject rationalize(LispObject a);
extern "C" LispObject lcm(LispObject a, LispObject b);
extern "C" LispObject lengthen_by_one_bit(LispObject a, int32_t msd);
extern "C" bool numeq2(LispObject a, LispObject b);
extern "C" bool zerop(LispObject a);
extern "C" bool onep(LispObject a);
extern "C" bool minusp(LispObject a);
extern "C" bool plusp(LispObject a);
extern "C" bool lesspbd(LispObject a, double b);
extern "C" bool lessprd(LispObject a, double b);
extern "C" bool lesspdb(double a, LispObject b);
extern "C" bool lesspdr(double a, LispObject b);
extern LispObject validate_number(const char *s, LispObject a,
 LispObject b, LispObject c);
extern LispObject make_fake_bignum(intptr_t n);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_four_word_bignum(int32_t a, uint32_t b,
 uint32_t c, uint32_t d);
extern LispObject make_n_word_bignum(int32_t a1, uint32_t a2,
 uint32_t a3, size_t n);
extern LispObject make_lisp_integer32_fn(int32_t n);
static inline LispObject make_lisp_integer32(int32_t n)
{ if (SIXTY_FOUR_BIT || valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer32_fn(n);
}
extern LispObject make_lisp_integer64_fn(int64_t n);
static inline LispObject make_lisp_integer64(int64_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer64_fn(n);
}
extern LispObject make_lisp_unsigned64_fn(uint64_t n);
static inline LispObject make_lisp_unsigned64(uint64_t n)
{ if (n < ((uint64_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsigned64_fn(n);
}
extern LispObject make_lisp_integerptr_fn(intptr_t n);
static inline LispObject make_lisp_integerptr(intptr_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int(n);
 else return make_lisp_integerptr_fn(n);
}
extern LispObject make_lisp_unsignedptr_fn(uintptr_t n);
static inline LispObject make_lisp_unsignedptr(uintptr_t n)
{ if (n < ((uintptr_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsignedptr_fn(n);
}
#ifdef HAVE_INT128_T
extern LispObject make_lisp_integer128_fn(int128_t n);
static inline LispObject make_lisp_integer128(int128_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer128_fn(n);
}
#endif
extern LispObject make_sfloat(double d);
extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern float128_t float128_of_number(LispObject a);
extern LispObject make_boxfloat(double a, int32_t type);
extern LispObject make_boxfloat128(float128_t a);
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern "C" LispObject ash(LispObject a, LispObject b);
extern "C" LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);
extern int _reduced_exp(double, double *);
extern bool lesspbi(LispObject a, LispObject b);
extern bool lesspib(LispObject a, LispObject b);
typedef struct Complex
{ double real;
 double imag;
} Complex;
extern Complex Cln(Complex a);
extern Complex Ccos(Complex a);
extern Complex Cexp(Complex a);
extern Complex Cpow(Complex a, Complex b);
extern double Cabs(Complex a);
#if defined HAVE_LIBPTHREAD || defined WIN32
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG void *
#define WINAPI
extern KARARESULT kara_worker1(KARAARG p);
extern KARARESULT kara_worker2(KARAARG p);
#endif
#ifdef MACINTOSH
extern sem_t *kara_sem1a, *kara_sem1b, *kara_sem1c,
 *kara_sem2a, *kara_sem2b, *kara_sem2c;
#else
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
 kara_sem2a, kara_sem2b, kara_sem2c;
#endif
extern size_t karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
# define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
#endif
extern "C" int f128M_exponent(const float128_t *p);
extern "C" void f128M_set_exponent(float128_t *p, int n);
extern "C" void f128M_ldexp(float128_t *p, int n);
extern "C" bool f128M_infinite(const float128_t *p);
extern "C" bool f128M_nan(const float128_t *x);
extern "C" bool f128M_subnorm(const float128_t *x);
extern "C" bool f128M_negative(const float128_t *x);
extern "C" void f128M_negate(float128_t *x);
extern "C" void f128M_split(
 const float128_t *x, float128_t *yhi, float128_t *ylo);
extern "C" float128_t f128_0, f128_1, f128_10, f128_10_17,
 f128_10_18, f128_r10, f128_N1;
typedef struct _float256_t
{
#ifdef LITTLEENDIAN
 float128_t lo;
 float128_t hi;
#else
 float128_t hi;
 float128_t lo;
#endif
} float256_t;
extern "C" void f256M_mul(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" void f256M_add(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;
extern "C" int f128M_sprint_E(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_F(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_G(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_print_E(int width, int precision, float128_t *p);
extern "C" int f128M_print_F(int width, int precision, float128_t *p);
extern "C" int f128M_print_G(int width, int precision, float128_t *p);
extern "C" float128_t atof128(const char *s);
#endif 
#ifndef header_entries_h
#define header_entries_h 1
extern "C" LispObject Lbatchp(LispObject env, int nargs, ...);
extern "C" LispObject bytecounts(LispObject env, int nargs, ...);
extern "C" LispObject Ldate(LispObject env, int nargs, ...);
extern "C" LispObject Ldatestamp(LispObject env, int nargs, ...);
extern "C" LispObject Leject(LispObject env, int nargs, ...);
extern "C" NORETURN void Lerror(LispObject env, int nargs, ...);
extern "C" NORETURN void Lerror0(LispObject env, int nargs, ...);
extern "C" LispObject Lall_symbols0(LispObject env, int nargs, ...);
extern "C" LispObject Lflush(LispObject env, int nargs, ...);
extern "C" LispObject Lgc0(LispObject env, int nargs, ...);
extern "C" LispObject Lgctime(LispObject env, int nargs, ...);
extern "C" LispObject Lgensym(LispObject env, int nargs, ...);
extern "C" LispObject Llist_modules(LispObject env, int nargs, ...);
extern "C" LispObject Llibrary_members0(LispObject env, int nargs, ...);
extern "C" LispObject Lload_source0(LispObject env, int nargs, ...);
extern "C" LispObject Lload_selected_source0(LispObject env, int nargs, ...);
extern "C" LispObject Lload_spid(LispObject, int nargs, ...);
extern "C" LispObject Llposn(LispObject env, int nargs, ...);
extern "C" LispObject Lmapstore0(LispObject env, int nargs, ...);
extern "C" LispObject Lnext_random(LispObject env, int nargs, ...);
extern "C" LispObject Lposn(LispObject env, int nargs, ...);
extern "C" LispObject Lread(LispObject env, int nargs, ...);
extern "C" LispObject Lreadch(LispObject env, int nargs, ...);
extern "C" LispObject Lrtell(LispObject env, int nargs, ...);
extern "C" LispObject Lterpri(LispObject env, int nargs, ...);
extern "C" LispObject Ltime(LispObject env, int nargs, ...);
extern "C" LispObject Ltmpnam(LispObject env, int nargs, ...);
extern "C" LispObject Ltyi(LispObject env, int nargs, ...);
extern "C" LispObject Lunserialize(LispObject env, int nargs, ...);
extern "C" LispObject undefined0(LispObject env);
extern "C" LispObject autoload1(LispObject env, LispObject a1);
extern "C" LispObject bytecoded1(LispObject env, LispObject a);
extern "C" LispObject bytecounts1(LispObject env, LispObject a);
extern "C" LispObject byteopt1(LispObject def, LispObject a);
extern "C" LispObject byteoptrest1(LispObject def, LispObject a);
extern "C" LispObject funarged1(LispObject env, LispObject a1);
extern "C" LispObject tracefunarged1(LispObject env, LispObject a1);
extern "C" LispObject hardopt1(LispObject def, LispObject a);
extern "C" LispObject hardoptrest1(LispObject def, LispObject a);
extern "C" LispObject interpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject tracebyteopt1(LispObject def, LispObject a);
extern "C" LispObject tracebyteoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject traceinterpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracehardopt1(LispObject def, LispObject a);
extern "C" LispObject tracehardoptrest1(LispObject def, LispObject a);
extern "C" LispObject undefined1(LispObject env, LispObject a1);
extern "C" LispObject f1_as_0(LispObject env, LispObject a);
extern "C" LispObject f1_as_1(LispObject env, LispObject a);
extern "C" LispObject Labsval(LispObject env, LispObject a);
extern "C" LispObject Ladd1(LispObject env, LispObject a);
extern "C" LispObject Lalpha_char_p(LispObject env, LispObject a);
extern "C" LispObject Lall_symbols(LispObject env, LispObject a1);
extern "C" LispObject Lapply0(LispObject env, LispObject a);
extern "C" LispObject Lapply_1(LispObject env, LispObject fn);
extern "C" LispObject Latan(LispObject env, LispObject a);
extern "C" LispObject Latom(LispObject env, LispObject a);
extern "C" LispObject Lbanner(LispObject env, LispObject a);
extern "C" LispObject Lboundp(LispObject env, LispObject a);
extern "C" LispObject Lbpsp(LispObject env, LispObject a);
extern "C" LispObject Lbpsupbv(LispObject env, LispObject v);
extern "C" LispObject Lcaaaar(LispObject env, LispObject a);
extern "C" LispObject Lcaaadr(LispObject env, LispObject a);
extern "C" LispObject Lcaaar(LispObject env, LispObject a);
extern "C" LispObject Lcaadar(LispObject env, LispObject a);
extern "C" LispObject Lcaaddr(LispObject env, LispObject a);
extern "C" LispObject Lcaadr(LispObject env, LispObject a);
extern "C" LispObject Lcaar(LispObject env, LispObject a);
extern "C" LispObject Lcaar(LispObject env, LispObject a);
extern "C" LispObject Lcadaar(LispObject env, LispObject a);
extern "C" LispObject Lcadadr(LispObject env, LispObject a);
extern "C" LispObject Lcadar(LispObject env, LispObject a);
extern "C" LispObject Lcaddar(LispObject env, LispObject a);
extern "C" LispObject Lcadddr(LispObject env, LispObject a);
extern "C" LispObject Lcaddr(LispObject env, LispObject a);
extern "C" LispObject Lcadr(LispObject env, LispObject a);
extern "C" LispObject Lcadr(LispObject env, LispObject a);
extern "C" LispObject Lcar(LispObject env, LispObject a);
extern "C" LispObject Lcar(LispObject env, LispObject a);
extern "C" LispObject Lcdaaar(LispObject env, LispObject a);
extern "C" LispObject Lcdaadr(LispObject env, LispObject a);
extern "C" LispObject Lcdaar(LispObject env, LispObject a);
extern "C" LispObject Lcdadar(LispObject env, LispObject a);
extern "C" LispObject Lcdaddr(LispObject env, LispObject a);
extern "C" LispObject Lcdadr(LispObject env, LispObject a);
extern "C" LispObject Lcdar(LispObject env, LispObject a);
extern "C" LispObject Lcdar(LispObject env, LispObject a);
extern "C" LispObject Lcddaar(LispObject env, LispObject a);
extern "C" LispObject Lcddadr(LispObject env, LispObject a);
extern "C" LispObject Lcddar(LispObject env, LispObject a);
extern "C" LispObject Lcdddar(LispObject env, LispObject a);
extern "C" LispObject Lcddddr(LispObject env, LispObject a);
extern "C" LispObject Lcdddr(LispObject env, LispObject a);
extern "C" LispObject Lcddr(LispObject env, LispObject a);
extern "C" LispObject Lcddr(LispObject env, LispObject a);
extern "C" LispObject Lcdr(LispObject env, LispObject a);
extern "C" LispObject Lcdr(LispObject env, LispObject a);
extern "C" LispObject Lchar_code(LispObject env, LispObject a);
extern "C" LispObject Lclose(LispObject env, LispObject a);
extern "C" LispObject Lcodep(LispObject env, LispObject a);
extern "C" LispObject Lcompress(LispObject env, LispObject a);
extern "C" LispObject Lconsp(LispObject env, LispObject a);
extern "C" LispObject Lconstantp(LispObject env, LispObject a);
extern "C" LispObject Lcopy_module(LispObject env, LispObject a);
extern "C" LispObject Ldefine_in_module(LispObject env, LispObject a);
extern "C" LispObject Ldelete_module(LispObject env, LispObject a);
extern "C" LispObject Ldigitp(LispObject env, LispObject a);
extern "C" LispObject Lendp(LispObject env, LispObject a);
extern "C" NORETURN void Lerror1(LispObject env, LispObject a1);
extern "C" LispObject Lerrorset1(LispObject env, LispObject form);
extern "C" LispObject Leval(LispObject env, LispObject a);
extern "C" LispObject Levenp(LispObject env, LispObject a);
extern "C" LispObject Levlis(LispObject env, LispObject a);
extern "C" LispObject Lexplode(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lc(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lcn(LispObject env, LispObject a);
extern "C" LispObject Lexplode2n(LispObject env, LispObject a);
extern "C" LispObject Lexplodec(LispObject env, LispObject a);
extern "C" LispObject Lexplodecn(LispObject env, LispObject a);
extern "C" LispObject Lexplodehex(LispObject env, LispObject a);
extern "C" LispObject Lexploden(LispObject env, LispObject a);
extern "C" LispObject Lexplodeoctal(LispObject env, LispObject a);
extern "C" LispObject Lfixp(LispObject env, LispObject a);
extern "C" LispObject Lfloat(LispObject env, LispObject a);
extern "C" LispObject Lfloatp(LispObject env, LispObject a);
extern "C" LispObject Lfrexp(LispObject env, LispObject a);
extern "C" LispObject Lfuncall1(LispObject env, LispObject fn);
extern "C" LispObject Lgc(LispObject env, LispObject a);
extern "C" LispObject Lgensym0(LispObject env, LispObject a, const char *s);
extern "C" LispObject Lgensym1(LispObject env, LispObject a);
extern "C" LispObject Lgensym2(LispObject env, LispObject a);
extern "C" LispObject Lgetd(LispObject env, LispObject a);
extern "C" LispObject Lgetenv(LispObject env, LispObject a);
extern "C" LispObject Lget_bps(LispObject env, LispObject a);
extern "C" LispObject Liadd1(LispObject env, LispObject a);
extern "C" LispObject Lidentity(LispObject env, LispObject a);
extern "C" LispObject Liminus(LispObject env, LispObject a);
extern "C" LispObject Liminusp(LispObject env, LispObject a);
extern "C" LispObject Lindirect(LispObject env, LispObject a);
extern "C" LispObject Lintegerp(LispObject env, LispObject a);
extern "C" LispObject Lintern(LispObject env, LispObject a);
extern "C" LispObject Lionep(LispObject env, LispObject a);
extern "C" LispObject Lis_spid(LispObject env, LispObject a);
extern "C" LispObject Lisub1(LispObject env, LispObject a);
extern "C" LispObject Lizerop(LispObject env, LispObject a);
extern "C" LispObject Llength(LispObject env, LispObject a);
extern "C" LispObject Llengthc(LispObject env, LispObject a);
extern "C" LispObject Llibrary_members(LispObject env, LispObject a);
extern "C" LispObject Llinelength(LispObject env, LispObject a);
extern "C" LispObject Llist_to_string(LispObject env, LispObject a);
extern "C" LispObject Llist_to_vector(LispObject env, LispObject a);
extern "C" LispObject Lload_module(LispObject env, LispObject a);
extern "C" LispObject Lload_source(LispObject env, LispObject a);
extern "C" LispObject Lload_selected_source(LispObject env, LispObject a);
extern "C" LispObject Llognot(LispObject env, LispObject a);
extern "C" LispObject Llog_1(LispObject env, LispObject a);
extern "C" LispObject Llsd(LispObject env, LispObject a);
extern "C" LispObject Lmacroexpand(LispObject env, LispObject a);
extern "C" LispObject Lmacroexpand_1(LispObject env, LispObject a);
extern "C" LispObject Lmacro_function(LispObject env, LispObject a);
extern "C" LispObject Lmake_global(LispObject env, LispObject a);
extern "C" LispObject Lmake_special(LispObject env, LispObject a);
extern "C" LispObject Lmapstore(LispObject env, LispObject a);
extern "C" LispObject Lmd5(LispObject env, LispObject a1);
extern "C" LispObject Lmd60(LispObject env, LispObject a1);
extern "C" LispObject Lminus(LispObject env, LispObject a);
extern "C" LispObject Lminusp(LispObject env, LispObject a);
extern "C" LispObject Lmkevect(LispObject env, LispObject n);
extern "C" LispObject Lmkquote(LispObject env, LispObject a);
extern "C" LispObject Lmkvect(LispObject env, LispObject a);
extern "C" LispObject Lmodular_minus(LispObject env, LispObject a);
extern "C" LispObject Lmodular_number(LispObject env, LispObject a);
extern "C" LispObject Lmodular_reciprocal(LispObject env, LispObject a);
extern "C" LispObject Lmodule_exists(LispObject env, LispObject a);
extern "C" LispObject Lmsd(LispObject env, LispObject a);
extern "C" LispObject Lmv_list(LispObject env, LispObject a);
extern "C" LispObject Lncons(LispObject env, LispObject a);
extern "C" LispObject Lnreverse(LispObject env, LispObject a);
extern "C" LispObject Lnull(LispObject env, LispObject a);
extern "C" LispObject Lnumberp(LispObject env, LispObject a);
extern "C" LispObject Loddp(LispObject env, LispObject a);
extern "C" LispObject Lonep(LispObject env, LispObject a);
extern "C" LispObject Lpagelength(LispObject env, LispObject a);
extern "C" LispObject Lplist(LispObject env, LispObject a);
extern "C" LispObject Lplusp(LispObject env, LispObject a);
extern "C" LispObject Lprin(LispObject env, LispObject a);
extern "C" LispObject Lprin(LispObject env, LispObject a);
extern "C" LispObject Lprin2a(LispObject env, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprint(LispObject env, LispObject a);
extern "C" LispObject Lprintc(LispObject env, LispObject a);
extern "C" LispObject Lrandom(LispObject env, LispObject a);
extern "C" LispObject Lrational(LispObject env, LispObject a);
extern "C" LispObject Lrdf1(LispObject env, LispObject a);
extern "C" LispObject Lrds(LispObject env, LispObject a);
extern "C" LispObject Lremd(LispObject env, LispObject a);
extern "C" LispObject Lrepresentation1(LispObject env, LispObject a);
extern "C" LispObject Lreverse(LispObject env, LispObject a);
extern "C" LispObject Lserialize(LispObject env, LispObject a);
extern "C" LispObject Lserialize1(LispObject env, LispObject a);
extern "C" LispObject Lsetpchar(LispObject env, LispObject a);
extern "C" LispObject Lset_small_modulus(LispObject env, LispObject a);
extern "C" LispObject Lsmkvect(LispObject env, LispObject a);
extern "C" LispObject Lspecial_char(LispObject env, LispObject a);
extern "C" LispObject Lspecial_form_p(LispObject env, LispObject a);
extern "C" LispObject Lspid_to_nil(LispObject env, LispObject a);
extern "C" LispObject Lspool(LispObject env, LispObject a);
extern "C" LispObject Lstart_module(LispObject env, LispObject a);
extern "C" NORETURN void Lstop(LispObject env, LispObject a);
extern "C" LispObject Lstringp(LispObject env, LispObject a);
extern "C" LispObject Lsub1(LispObject env, LispObject a);
extern "C" LispObject Lsymbolp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_argcount(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_argcode(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_env(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_function(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_globalp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_name(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_restore_fns(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_specialp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_value(LispObject env, LispObject a);
extern "C" LispObject Lsystem(LispObject env, LispObject a);
extern "C" LispObject Lthreevectorp(LispObject env, LispObject a);
extern "C" LispObject Lthrow_nil(LispObject env, LispObject a);
extern "C" LispObject Ltrace(LispObject env, LispObject a);
extern "C" LispObject Ltruncate(LispObject env, LispObject a);
extern "C" LispObject Lttab(LispObject env, LispObject a);
extern "C" LispObject Ltyo(LispObject env, LispObject a);
extern "C" LispObject Lunintern(LispObject env, LispObject a);
extern "C" LispObject Lunmake_global(LispObject env, LispObject a);
extern "C" LispObject Lunmake_special(LispObject env, LispObject a);
extern "C" LispObject Luntrace(LispObject env, LispObject a);
extern "C" LispObject Lupbv(LispObject env, LispObject a);
extern "C" LispObject Lsimple_vectorp(LispObject env, LispObject a);
extern "C" LispObject Lvectorp(LispObject env, LispObject a);
extern "C" LispObject Lverbos(LispObject env, LispObject a);
extern "C" LispObject Lwhitespace_char_p(LispObject env, LispObject a);
extern "C" LispObject Lwritable_libraryp(LispObject env, LispObject a);
extern "C" LispObject Lwrs(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lzerop(LispObject env, LispObject a);
extern "C" LispObject Lfind_symbol_1(LispObject env, LispObject str);
extern "C" LispObject Llistp(LispObject env, LispObject a);
extern "C" LispObject autoload2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject bytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject byteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject byteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject funarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracefunarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject hardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject hardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject interpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracebyteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebyteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject traceinterpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracehardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracehardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject undefined2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject f2_as_0(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lappend(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lapply1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lassoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2d(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latsoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lbpsgetv(LispObject env, LispObject v, LispObject n);
extern "C" LispObject Lcons(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldeleq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldelete(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldifference2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldivide(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leqcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lequalcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leql(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leqn(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lcl_equal(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lequal(LispObject env, LispObject a, LispObject b);
extern "C" NORETURN void Lerror2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject Lerrorset2(LispObject env, LispObject form, LispObject ffg1);
extern "C" LispObject Lexpt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflagp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflagpcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfuncall2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lgcd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgeq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lget(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lget_hash_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lidifference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ligeq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ligreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lileq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lilessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limax(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limin(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Linorm(LispObject env, LispObject a, LispObject k);
extern "C" LispObject Lintersect(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lintersect_symlist(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liremainder(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lirightshift(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Litimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llcm(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lleq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llist2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llog(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llog_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmax2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmember(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmin2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmod(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_difference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_expt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_plus(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_quotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_times(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lnconc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lneq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lnreverse2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lorderp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lpair(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrem(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremprop(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrepresentation2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lresource_limit2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplaca(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplacd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrseek(LispObject env, LispObject a);
extern "C" LispObject Lset(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lset_help_file(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsubla(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsublis(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_protect(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_definition(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_env(LispObject env, LispObject a, LispObject b);
extern "C" NORETURN void Lthrow_one_value(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ltimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunion(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunion_symlist(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lwrite_module(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lxcons(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Laref2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfloat_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lintern_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_1_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrandom_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ltruncate_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunintern_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject undefined3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern "C" LispObject autoloadn(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject bytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject byteoptn(LispObject def, int nargs, ...);
extern "C" LispObject byteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject funargedn(LispObject env, int nargs, ...);
extern "C" LispObject tracefunargedn(LispObject env, int nargs, ...);
extern "C" LispObject hardoptn(LispObject def, int nargs, ...);
extern "C" LispObject hardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject interpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracebyteoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracebyteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracebytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject traceinterpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracehardoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracehardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject undefinedn(LispObject env, int nargs, ...);
extern "C" LispObject f0_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_1(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_2(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_3(LispObject env, int nargs, ...);
extern "C" LispObject Lacons(LispObject env, int nargs, ...);
extern "C" LispObject Lapply_n(LispObject env, int nargs, ...);
extern "C" LispObject Lapply2(LispObject env, int nargs, ...);
extern "C" LispObject Lapply3(LispObject env, int nargs, ...);
extern "C" LispObject Lbpsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lerrorset3(LispObject env, int nargs, ...);
extern "C" LispObject Lerrorsetn(LispObject env, int nargs, ...);
extern "C" LispObject Lfuncalln(LispObject env, int nargs, ...);
extern "C" LispObject Llist(LispObject env, int nargs, ...);
extern "C" LispObject Llist2star(LispObject env, int nargs, ...);
extern "C" LispObject Llist3(LispObject env, int nargs, ...);
extern "C" LispObject Llogand(LispObject env, int nargs, ...);
extern "C" LispObject Llogeqv(LispObject env, int nargs, ...);
extern "C" LispObject Llogor(LispObject env, int nargs, ...);
extern "C" LispObject Llogxor(LispObject env, int nargs, ...);
extern "C" LispObject Lmax(LispObject env, int nargs, ...);
extern "C" LispObject Lmin(LispObject env, int nargs, ...);
extern "C" LispObject Lmkhash(LispObject env, int nargs, ...);
extern "C" LispObject Lput_hash(LispObject env, int nargs, ...);
extern "C" LispObject Lputprop(LispObject env, int nargs, ...);
extern "C" LispObject Lputv(LispObject env, int nargs, ...);
extern "C" LispObject Lresource_limitn(LispObject env, int nargs, ...);
extern "C" LispObject Lsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lsubst(LispObject env, int nargs, ...);
extern "C" LispObject Lvalues(LispObject env, int nargs, ...);
extern "C" LispObject Lappend_n(LispObject env, int nargs, ...);
extern "C" LispObject Laref(LispObject env, int nargs, ...);
extern "C" LispObject Laset(LispObject env, int nargs, ...);
extern "C" LispObject Leqn_n(LispObject env, int nargs, ...);
extern "C" LispObject Lgcd_n(LispObject env, int nargs, ...);
extern "C" LispObject Lgeq_n(LispObject env, int nargs, ...);
extern "C" LispObject Lget_3(LispObject env, int nargs, ...);
extern "C" LispObject Lgreaterp_n(LispObject env, int nargs, ...);
extern "C" LispObject Llcm_n(LispObject env, int nargs, ...);
extern "C" LispObject Lleq_n(LispObject env, int nargs, ...);
extern "C" LispObject Llessp_n(LispObject env, int nargs, ...);
extern "C" LispObject Lquotient_n(LispObject env, int nargs, ...);
#ifdef OPENMATH
extern "C" LispObject om_openFileDev(LispObject env, int nargs, ...);
extern "C" LispObject om_openStringDev(LispObject env, LispObject lstr, LispObject lenc);
extern "C" LispObject om_closeDev(LispObject env, LispObject dev);
extern "C" LispObject om_setDevEncoding(LispObject env, LispObject ldev, LispObject lenc);
extern "C" LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern "C" LispObject om_closeConn(LispObject env, LispObject lconn);
extern "C" LispObject om_getConnInDevice(LispObject env, LispObject lconn);
extern "C" LispObject om_getConnOutDevice(LispObject env, LispObject lconn);
extern "C" LispObject om_connectTCP(LispObject env, int nargs, ...);
extern "C" LispObject om_bindTCP(LispObject env, LispObject lconn, LispObject lport);
extern "C" LispObject om_putApp(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndApp(LispObject env, LispObject ldev);
extern "C" LispObject om_putAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_putAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_putBind(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndBind(LispObject env, LispObject ldev);
extern "C" LispObject om_putBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_putError(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndError(LispObject env, LispObject ldev);
extern "C" LispObject om_putObject(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndObject(LispObject env, LispObject ldev);
extern "C" LispObject om_putInt(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putFloat(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putByteArray(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putVar(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putString(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol2(LispObject env, int nargs, ...);
extern "C" LispObject om_getApp(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndApp(LispObject env, LispObject ldev);
extern "C" LispObject om_getAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_getAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_getBind(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndBind(LispObject env, LispObject ldev);
extern "C" LispObject om_getBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_getError(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndError(LispObject env, LispObject ldev);
extern "C" LispObject om_getObject(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndObject(LispObject env, LispObject ldev);
extern "C" LispObject om_getInt(LispObject env, LispObject ldev);
extern "C" LispObject om_getFloat(LispObject env, LispObject ldev);
extern "C" LispObject om_getByteArray(LispObject env, LispObject ldev);
extern "C" LispObject om_getVar(LispObject env, LispObject ldev);
extern "C" LispObject om_getString(LispObject env, LispObject ldev);
extern "C" LispObject om_getSymbol(LispObject env, LispObject ldev);
extern "C" LispObject om_getType(LispObject env, LispObject ldev);
extern "C" LispObject om_stringToStringPtr(LispObject env, LispObject lstr);
extern "C" LispObject om_stringPtrToString(LispObject env, LispObject lpstr);
extern "C" LispObject om_read(LispObject env, LispObject dev);
extern "C" LispObject om_supportsCD(LispObject env, LispObject lcd);
extern "C" LispObject om_supportsSymbol(LispObject env, LispObject lcd, LispObject lsym);
extern "C" LispObject om_listCDs(LispObject env, int nargs, ...);
extern "C" LispObject om_listSymbols(LispObject env, LispObject lcd);
extern "C" LispObject om_whichCDs(LispObject env, LispObject lsym);
#endif
extern "C" LispObject undefined4(LispObject env, size_t n, LispObject a1,
 LispObject a2, LispObject a3, LispObject a4);
#endif 
#ifndef __lispthrow_h
#define __lispthrow_h 1
class stack_popper
{ int n;
public:
 stack_popper(int nn)
 { n = nn;
 }
 ~stack_popper()
 { popv(n);
 }
};
class stack_restorer
{ LispObject *stackSave;
public:
 stack_restorer()
 { stackSave = stack;
 }
 ~stack_restorer()
 { stack = stackSave;
 }
};
class save_current_function
{ LispObject *savestack;
public:
 save_current_function(LispObject newfn)
 { push(current_function);
 savestack = stack;
 current_function = newfn;
 }
 ~save_current_function()
 { stack = savestack;
 pop(current_function);
 }
};
class bind_fluid_stack
{ LispObject *savestack;
 int env_loc;
 int name_loc;
 int val_loc;
public:
 bind_fluid_stack(int e, int name, int val)
 { savestack = stack;
 env_loc = e;
 name_loc = name;
 val_loc = val;
#ifdef TRACE_FLUID
 debug_printf("bind_fluid_stack(%d, %d, %d) @ %p\n", e, name, val, stack);
 debug_printf("name="); prin_to_debug(elt(savestack[e], name));
 debug_printf(" old-val="); prin_to_debug(qvalue(elt(savestack[e], name)));
 debug_printf("\n");
#endif
 savestack[val] = qvalue(elt(savestack[e], name));
 }
 ~bind_fluid_stack()
 {
#ifdef TRACE_FLUID
 debug_printf("restore(%d, %d, %d) @ %p\n", env_loc, name_loc, val_loc, savestack);
 debug_printf("name="); prin_to_debug(elt(savestack[env_loc], name_loc));
 debug_printf(" local-val="); prin_to_debug(qvalue(elt(savestack[env_loc], name_loc)));
 debug_printf(" restored-val="); prin_to_debug(savestack[val_loc]);
 debug_printf("\n");
#endif
 qvalue(elt(savestack[env_loc], name_loc)) = savestack[val_loc];
 }
};
struct LispException : public std::exception
{ virtual const char *what() const throw()
 { return "Generic Lisp Exception";
 }
};
 struct LispError : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Error";
 }
 };
 struct LispSignal : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Signal";
 }
 };
 struct LispResource : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Resouce Limiter";
 }
 };
 struct LispSigint : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Sigint";
 }
 };
 struct LispGo : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Go";
 }
 };
 struct LispReturnFrom : public LispException
 { virtual const char *what() const throw()
 { return "Lisp ReturnFrom";
 }
 };
 struct LispThrow : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Throw";
 }
 };
 struct LispRestart : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Restart";
 }
 };
class RAIIstack_sanity
{ LispObject *saveStack;
 const char *fname;
 const char *file;
 int line;
 LispObject w;
public:
 RAIIstack_sanity(const char *fn, const char *fi, int li)
 { saveStack = stack;
 fname = fn;
 file = fi;
 line = li;
 w = nil;
 }
 RAIIstack_sanity(const char *fn, const char *fi, int li, LispObject ww)
 { saveStack = stack;
 fname = fn;
 file = fi;
 line = li;
 w = ww;
 }
 ~RAIIstack_sanity()
 { if (saveStack != stack && !std::uncaught_exception())
 { printf("???SP %p => %p in %s : %s:%d\n",
 saveStack, stack, fname, file, line);
 if (w != nil)
 { err_printf("Data: ");
 prin_to_error(w);
 err_printf("\n");
 }
 }
 }
};
static inline const char *tidy_filename(const char *a)
{ const char *b = strrchr(a, '/');
 return (b == NULL ? a : b+1);
}
#ifdef DEBUG
#define STACK_SANITY \
 RAIIstack_sanity stack_sanity_object(__func__, \
 tidy_filename(__FILE__), __LINE__);
#define STACK_SANITY1(w) \
 RAIIstack_sanity stack_sanity_object(__func__, \
 tidy_filename(__FILE__), __LINE__, w);
#else
#define STACK_SANITY ;
#define STACK_SANITY1(w) ;
#endif
class RAIIsave_codevec
{ LispObject *saveStack;
public:
 RAIIsave_codevec()
 { push2(litvec, codevec);
 saveStack = stack;
 }
 ~RAIIsave_codevec()
 { stack = saveStack;
 pop2(codevec, litvec);
 }
};
#define SAVE_CODEVEC RAIIsave_codevec save_codevec_object;
extern LispObject *stack;
extern jmp_buf *global_jb;
class RAIIsave_stack_and_jb
{ LispObject *saveStack;
 jmp_buf *jbsave;
public:
 RAIIsave_stack_and_jb()
 { jbsave = global_jb; 
 saveStack = stack; 
 }
 ~RAIIsave_stack_and_jb()
 { global_jb = jbsave; 
 stack = saveStack; 
 }
};
class RAIIsave_stack
{ LispObject *saveStack;
public:
 RAIIsave_stack()
 { saveStack = stack; 
 }
 ~RAIIsave_stack()
 { stack = saveStack; 
 }
};
#define START_SETJMP_BLOCK \
 jmp_buf jb; \
 RAIIsave_stack_and_jb save_stack_Object; \
 switch (setjmp(jb)) \
 { default: \
 case 1: exit_reason = UNWIND_SIGNAL; \
 throw LispSignal(); \
 case 2: exit_reason = UNWIND_SIGINT; \
 throw LispSigint(); \
 case 0: break; \
 } \
 global_jb = &jb;
#define START_TRY_BLOCK \
 RAIIsave_stack save_stack_Object;
#define on_backtrace(a, b) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { int _reason = exit_reason; \
 b; \
 exit_reason = _reason; \
 throw; \
 }
#define if_error(a, b) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { b; \
 }
#define ignore_error(a) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { \
 }
#define ignore_exception(a) \
 try \
 { START_SETJMP_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { \
 }
#endif 



// Code for integerom

static LispObject CC_integerom(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6329;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_6319;
// end of prologue
    v_6329 = elt(env, 1); // "<OMI> "
    fn = elt(env, 3); // printout
    v_6329 = (*qfn1(fn))(fn, v_6329);
    env = stack[-1];
    v_6329 = stack[0];
    v_6329 = Lprinc(nil, v_6329);
    env = stack[-1];
    v_6329 = elt(env, 2); // " </OMI>"
    v_6329 = Lprinc(nil, v_6329);
    v_6329 = nil;
    return onevalue(v_6329);
}



// Code for writepri

static LispObject CC_writepri(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6334, v_6335, v_6336;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_6320;
    v_6334 = v_6319;
// end of prologue
    goto v_6329;
v_6323:
    fn = elt(env, 1); // eval
    v_6336 = (*qfn1(fn))(fn, v_6334);
    env = stack[-1];
    goto v_6324;
v_6325:
    v_6335 = nil;
    goto v_6326;
v_6327:
    v_6334 = stack[0];
    goto v_6328;
v_6329:
    goto v_6323;
v_6324:
    goto v_6325;
v_6326:
    goto v_6327;
v_6328:
    {
        fn = elt(env, 2); // assgnpri
        return (*qfnn(fn))(fn, 3, v_6336, v_6335, v_6334);
    }
}



// Code for cut!:ep

static LispObject CC_cutTep(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6412, v_6413;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_6320;
    stack[-2] = v_6319;
// end of prologue
    goto v_6339;
v_6335:
    v_6413 = stack[-2];
    goto v_6336;
v_6337:
    v_6412 = elt(env, 1); // !:rd!:
    goto v_6338;
v_6339:
    goto v_6335;
v_6336:
    goto v_6337;
v_6338:
    if (!consp(v_6413)) goto v_6333;
    v_6413 = qcar(v_6413);
    if (v_6413 == v_6412) goto v_6332;
    else goto v_6333;
v_6332:
    v_6412 = stack[-2];
    v_6412 = qcdr(v_6412);
    v_6412 = (consp(v_6412) ? nil : lisp_true);
    v_6412 = (v_6412 == nil ? lisp_true : nil);
    goto v_6331;
v_6333:
    v_6412 = nil;
    goto v_6331;
    v_6412 = nil;
v_6331:
    if (v_6412 == nil) goto v_6329;
    v_6412 = stack[-1];
    v_6412 = integerp(v_6412);
    goto v_6327;
v_6329:
    v_6412 = nil;
    goto v_6327;
    v_6412 = nil;
v_6327:
    if (v_6412 == nil) goto v_6325;
    goto v_6363;
v_6359:
    goto v_6369;
v_6365:
    v_6413 = stack[-1];
    goto v_6366;
v_6367:
    v_6412 = stack[-2];
    v_6412 = qcdr(v_6412);
    v_6412 = qcdr(v_6412);
    goto v_6368;
v_6369:
    goto v_6365;
v_6366:
    goto v_6367;
v_6368:
    v_6413 = difference2(v_6413, v_6412);
    env = stack[-4];
    stack[-1] = v_6413;
    goto v_6360;
v_6361:
    v_6412 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6362;
v_6363:
    goto v_6359;
v_6360:
    goto v_6361;
v_6362:
    v_6412 = (LispObject)lesseq2(v_6413, v_6412);
    v_6412 = v_6412 ? lisp_true : nil;
    env = stack[-4];
    if (v_6412 == nil) goto v_6357;
    v_6412 = stack[-2];
    goto v_6355;
v_6357:
    goto v_6385;
v_6379:
    stack[-3] = elt(env, 1); // !:rd!:
    goto v_6380;
v_6381:
    goto v_6392;
v_6388:
    v_6412 = stack[-2];
    v_6412 = qcdr(v_6412);
    stack[0] = qcar(v_6412);
    goto v_6389;
v_6390:
    v_6412 = stack[-1];
    v_6412 = negate(v_6412);
    env = stack[-4];
    goto v_6391;
v_6392:
    goto v_6388;
v_6389:
    goto v_6390;
v_6391:
    fn = elt(env, 2); // ashift
    stack[0] = (*qfn2(fn))(fn, stack[0], v_6412);
    env = stack[-4];
    goto v_6382;
v_6383:
    goto v_6403;
v_6399:
    v_6412 = stack[-2];
    v_6412 = qcdr(v_6412);
    v_6413 = qcdr(v_6412);
    goto v_6400;
v_6401:
    v_6412 = stack[-1];
    goto v_6402;
v_6403:
    goto v_6399;
v_6400:
    goto v_6401;
v_6402:
    v_6412 = plus2(v_6413, v_6412);
    goto v_6384;
v_6385:
    goto v_6379;
v_6380:
    goto v_6381;
v_6382:
    goto v_6383;
v_6384:
    {
        LispObject v_6418 = stack[-3];
        LispObject v_6419 = stack[0];
        return list2star(v_6418, v_6419, v_6412);
    }
    v_6412 = nil;
v_6355:
    goto v_6323;
v_6325:
    v_6412 = elt(env, 0); // cut!:ep
    {
        fn = elt(env, 3); // bflerrmsg
        return (*qfn1(fn))(fn, v_6412);
    }
    v_6412 = nil;
v_6323:
    return onevalue(v_6412);
}



// Code for split!-road

static LispObject CC_splitKroad(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6363, v_6364, v_6365;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_6320;
    stack[-2] = v_6319;
// end of prologue
    goto v_6329;
v_6323:
    v_6363 = stack[-1];
    stack[-3] = qcar(v_6363);
    goto v_6324;
v_6325:
    goto v_6339;
v_6333:
    v_6363 = stack[-2];
    v_6365 = qcar(v_6363);
    goto v_6334;
v_6335:
    v_6363 = stack[-2];
    v_6364 = qcdr(v_6363);
    goto v_6336;
v_6337:
    v_6363 = stack[-1];
    v_6363 = qcdr(v_6363);
    v_6363 = qcar(v_6363);
    goto v_6338;
v_6339:
    goto v_6333;
v_6334:
    goto v_6335;
v_6336:
    goto v_6337;
v_6338:
    fn = elt(env, 1); // sroad
    stack[0] = (*qfnn(fn))(fn, 3, v_6365, v_6364, v_6363);
    env = stack[-4];
    goto v_6326;
v_6327:
    goto v_6354;
v_6348:
    v_6363 = stack[-2];
    v_6365 = qcar(v_6363);
    goto v_6349;
v_6350:
    v_6363 = stack[-2];
    v_6364 = qcdr(v_6363);
    goto v_6351;
v_6352:
    v_6363 = stack[-1];
    v_6363 = qcdr(v_6363);
    v_6363 = qcdr(v_6363);
    v_6363 = qcar(v_6363);
    goto v_6353;
v_6354:
    goto v_6348;
v_6349:
    goto v_6350;
v_6351:
    goto v_6352;
v_6353:
    fn = elt(env, 1); // sroad
    v_6363 = (*qfnn(fn))(fn, 3, v_6365, v_6364, v_6363);
    goto v_6328;
v_6329:
    goto v_6323;
v_6324:
    goto v_6325;
v_6326:
    goto v_6327;
v_6328:
    {
        LispObject v_6370 = stack[-3];
        LispObject v_6371 = stack[0];
        return list3(v_6370, v_6371, v_6363);
    }
}



// Code for formc

static LispObject CC_formc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6397, v_6398, v_6399, v_6400;
    LispObject fn;
    LispObject v_6321, v_6320, v_6319;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formc");
    va_start(aa, nargs);
    v_6319 = va_arg(aa, LispObject);
    v_6320 = va_arg(aa, LispObject);
    v_6321 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_6321,v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_6319,v_6320,v_6321);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_6321;
    stack[-1] = v_6320;
    stack[-2] = v_6319;
// end of prologue
    v_6397 = qvalue(elt(env, 1)); // !*rlisp88
    if (v_6397 == nil) goto v_6326;
    goto v_6336;
v_6332:
    v_6398 = stack[-2];
    goto v_6333;
v_6334:
    v_6397 = elt(env, 2); // modefn
    goto v_6335;
v_6336:
    goto v_6332;
v_6333:
    goto v_6334;
v_6335:
    v_6397 = Lflagpcar(nil, v_6398, v_6397);
    env = stack[-3];
    if (v_6397 == nil) goto v_6326;
    goto v_6344;
v_6340:
    v_6397 = stack[-2];
    v_6398 = qcar(v_6397);
    goto v_6341;
v_6342:
    v_6397 = elt(env, 3); // symbolic
    goto v_6343;
v_6344:
    goto v_6340;
v_6341:
    goto v_6342;
v_6343:
    if (v_6398 == v_6397) goto v_6326;
    goto v_6353;
v_6349:
    v_6398 = elt(env, 4); // "algebraic expression"
    goto v_6350;
v_6351:
    v_6397 = elt(env, 5); // "Rlisp88 form"
    goto v_6352;
v_6353:
    goto v_6349;
v_6350:
    goto v_6351;
v_6352:
    {
        fn = elt(env, 7); // typerr
        return (*qfn2(fn))(fn, v_6398, v_6397);
    }
v_6326:
    goto v_6366;
v_6362:
    v_6398 = stack[0];
    goto v_6363;
v_6364:
    v_6397 = elt(env, 6); // algebraic
    goto v_6365;
v_6366:
    goto v_6362;
v_6363:
    goto v_6364;
v_6365:
    if (v_6398 == v_6397) goto v_6360;
    else goto v_6361;
v_6360:
    goto v_6374;
v_6370:
    v_6398 = stack[-2];
    goto v_6371;
v_6372:
    v_6397 = stack[-1];
    goto v_6373;
v_6374:
    goto v_6370;
v_6371:
    goto v_6372;
v_6373:
    fn = elt(env, 8); // intexprnp
    v_6397 = (*qfn2(fn))(fn, v_6398, v_6397);
    env = stack[-3];
    goto v_6359;
v_6361:
    v_6397 = nil;
    goto v_6359;
    v_6397 = nil;
v_6359:
    if (v_6397 == nil) goto v_6357;
    v_6397 = stack[-2];
    goto v_6324;
v_6357:
    goto v_6392;
v_6384:
    v_6400 = stack[-2];
    goto v_6385;
v_6386:
    v_6399 = stack[-1];
    goto v_6387;
v_6388:
    v_6398 = elt(env, 3); // symbolic
    goto v_6389;
v_6390:
    v_6397 = stack[0];
    goto v_6391;
v_6392:
    goto v_6384;
v_6385:
    goto v_6386;
v_6387:
    goto v_6388;
v_6389:
    goto v_6390;
v_6391:
    {
        fn = elt(env, 9); // convertmode
        return (*qfnn(fn))(fn, 4, v_6400, v_6399, v_6398, v_6397);
    }
    v_6397 = nil;
v_6324:
    return onevalue(v_6397);
}



// Code for simp

static LispObject CC_simp(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_7053, v_7054, v_7055;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_6319;
// end of prologue
    v_7053 = qvalue(elt(env, 1)); // varstack!*
// Binding varstack!*
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    qvalue(elt(env, 1)) = v_7053; // varstack!*
    stack[-1] = nil;
    v_7053 = stack[-5];
    v_7053 = integerp(v_7053);
    if (v_7053 == nil) goto v_6330;
    goto v_6341;
v_6337:
    v_7054 = stack[-5];
    goto v_6338;
v_6339:
    v_7053 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6340;
v_6341:
    goto v_6337;
v_6338:
    goto v_6339;
v_6340:
    if (v_7054 == v_7053) goto v_6335;
    else goto v_6336;
v_6335:
    goto v_6349;
v_6345:
    v_7054 = nil;
    goto v_6346;
v_6347:
    v_7053 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6348;
v_6349:
    goto v_6345;
v_6346:
    goto v_6347;
v_6348:
    v_7053 = cons(v_7054, v_7053);
    goto v_6326;
v_6336:
    v_7053 = qvalue(elt(env, 2)); // dmode!*
    if (v_7053 == nil) goto v_6352;
    else goto v_6353;
v_6352:
    goto v_6360;
v_6356:
    v_7054 = stack[-5];
    goto v_6357;
v_6358:
    v_7053 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6359;
v_6360:
    goto v_6356;
v_6357:
    goto v_6358;
v_6359:
    v_7053 = cons(v_7054, v_7053);
    goto v_6326;
v_6353:
    goto v_6334;
v_6334:
    goto v_6328;
v_6330:
    goto v_6372;
v_6368:
    v_7054 = stack[-5];
    goto v_6369;
v_6370:
    v_7053 = qvalue(elt(env, 1)); // varstack!*
    goto v_6371;
v_6372:
    goto v_6368;
v_6369:
    goto v_6370;
v_6371:
    v_7053 = Lmember(nil, v_7054, v_7053);
    if (v_7053 == nil) goto v_6367;
    v_7053 = stack[-5];
    fn = elt(env, 22); // recursiveerror
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    goto v_6328;
v_6367:
v_6328:
    goto v_6383;
v_6379:
    v_7054 = stack[-5];
    goto v_6380;
v_6381:
    v_7053 = qvalue(elt(env, 1)); // varstack!*
    goto v_6382;
v_6383:
    goto v_6379;
v_6380:
    goto v_6381;
v_6382:
    v_7053 = cons(v_7054, v_7053);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_7053; // varstack!*
    goto v_6395;
v_6391:
    v_7054 = qvalue(elt(env, 3)); // simpcount!*
    goto v_6392;
v_6393:
    v_7053 = qvalue(elt(env, 4)); // simplimit!*
    goto v_6394;
v_6395:
    goto v_6391;
v_6392:
    goto v_6393;
v_6394:
    v_7053 = (LispObject)greaterp2(v_7054, v_7053);
    v_7053 = v_7053 ? lisp_true : nil;
    env = stack[-7];
    if (v_7053 == nil) goto v_6389;
    v_7053 = (LispObject)0+TAG_FIXNUM; // 0
    qvalue(elt(env, 3)) = v_7053; // simpcount!*
    goto v_6406;
v_6400:
    v_7055 = elt(env, 5); // alg
    goto v_6401;
v_6402:
    v_7054 = (LispObject)192+TAG_FIXNUM; // 12
    goto v_6403;
v_6404:
    v_7053 = elt(env, 6); // "Simplification recursion too deep"
    goto v_6405;
v_6406:
    goto v_6400;
v_6401:
    goto v_6402;
v_6403:
    goto v_6404;
v_6405:
    fn = elt(env, 23); // rerror
    v_7053 = (*qfnn(fn))(fn, 3, v_7055, v_7054, v_7053);
    env = stack[-7];
    goto v_6387;
v_6389:
    goto v_6421;
v_6417:
    v_7054 = stack[-5];
    goto v_6418;
v_6419:
    v_7053 = elt(env, 7); // !*sq
    goto v_6420;
v_6421:
    goto v_6417;
v_6418:
    goto v_6419;
v_6420:
    if (!consp(v_7054)) goto v_6415;
    v_7054 = qcar(v_7054);
    if (v_7054 == v_7053) goto v_6414;
    else goto v_6415;
v_6414:
    v_7053 = stack[-5];
    v_7053 = qcdr(v_7053);
    v_7053 = qcdr(v_7053);
    v_7053 = qcar(v_7053);
    if (v_7053 == nil) goto v_6426;
    else goto v_6427;
v_6426:
    v_7053 = nil;
    goto v_6425;
v_6427:
    v_7053 = qvalue(elt(env, 8)); // !*resimp
    v_7053 = (v_7053 == nil ? lisp_true : nil);
    goto v_6425;
    v_7053 = nil;
v_6425:
    goto v_6413;
v_6415:
    v_7053 = nil;
    goto v_6413;
    v_7053 = nil;
v_6413:
    if (v_7053 == nil) goto v_6411;
    v_7053 = stack[-5];
    v_7053 = qcdr(v_7053);
    v_7053 = qcar(v_7053);
    goto v_6326;
v_6411:
    v_7053 = qvalue(elt(env, 9)); // !*uncached
    if (v_7053 == nil) goto v_6447;
    else goto v_6448;
v_6447:
    v_7053 = qvalue(elt(env, 10)); // alglist!*
    v_7053 = qcar(v_7053);
    v_7054 = v_7053;
    if (v_7054 == nil) goto v_6455;
    else goto v_6456;
v_6455:
    v_7053 = nil;
    goto v_6454;
v_6456:
    goto v_6466;
v_6462:
    v_7054 = stack[-5];
    goto v_6463;
v_6464:
    goto v_6465;
v_6466:
    goto v_6462;
v_6463:
    goto v_6464;
v_6465:
    fn = elt(env, 24); // gethash
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    env = stack[-7];
    goto v_6454;
    v_7053 = nil;
v_6454:
    stack[-1] = v_7053;
    goto v_6446;
v_6448:
    v_7053 = nil;
    goto v_6446;
    v_7053 = nil;
v_6446:
    if (v_7053 == nil) goto v_6444;
    v_7053 = stack[-1];
    v_7053 = qcar(v_7053);
    if (v_7053 == nil) goto v_6475;
    v_7053 = lisp_true;
    qvalue(elt(env, 11)) = v_7053; // !*sub2
    goto v_6473;
v_6475:
v_6473:
    v_7053 = stack[-1];
    v_7053 = qcdr(v_7053);
    goto v_6326;
v_6444:
v_6387:
    v_7053 = qvalue(elt(env, 3)); // simpcount!*
    v_7053 = add1(v_7053);
    env = stack[-7];
    qvalue(elt(env, 3)) = v_7053; // simpcount!*
    v_7053 = stack[-5];
    if (!consp(v_7053)) goto v_6485;
    else goto v_6486;
v_6485:
    goto v_6493;
v_6489:
    v_7053 = stack[-5];
    fn = elt(env, 25); // simpatom
    v_7054 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    goto v_6490;
v_6491:
    v_7053 = stack[-5];
    goto v_6492;
v_6493:
    goto v_6489;
v_6490:
    goto v_6491;
v_6492:
    fn = elt(env, 26); // !*ssave
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6326;
v_6486:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (symbolp(v_7053)) goto v_6502;
    v_7053 = lisp_true;
    goto v_6500;
v_6502:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    v_7053 = (v_7053 == nil ? lisp_true : nil);
    goto v_6500;
    v_7053 = nil;
v_6500:
    if (v_7053 == nil) goto v_6498;
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!consp(v_7053)) goto v_6513;
    else goto v_6514;
v_6513:
    goto v_6522;
v_6518:
    v_7053 = stack[-5];
    v_7054 = qcar(v_7053);
    goto v_6519;
v_6520:
    v_7053 = elt(env, 12); // "operator"
    goto v_6521;
v_6522:
    goto v_6518;
v_6519:
    goto v_6520;
v_6521:
    fn = elt(env, 27); // typerr
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6512;
v_6514:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    v_7053 = qcar(v_7053);
    if (symbolp(v_7053)) goto v_6528;
    else goto v_6527;
v_6528:
    goto v_6538;
v_6534:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    v_7054 = qcar(v_7053);
    goto v_6535;
v_6536:
    v_7053 = elt(env, 13); // name
    goto v_6537;
v_6538:
    goto v_6534;
v_6535:
    goto v_6536;
v_6537:
    v_7053 = get(v_7054, v_7053);
    env = stack[-7];
    stack[-1] = v_7053;
    if (v_7053 == nil) goto v_6527;
    goto v_6548;
v_6544:
    v_7054 = stack[-5];
    goto v_6545;
v_6546:
    v_7053 = stack[-5];
    goto v_6547;
v_6548:
    goto v_6544;
v_6545:
    goto v_6546;
v_6547:
    fn = elt(env, 26); // !*ssave
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6326;
v_6527:
    goto v_6562;
v_6558:
    v_7053 = stack[-5];
    v_7054 = qcar(v_7053);
    goto v_6559;
v_6560:
    v_7053 = elt(env, 14); // mat
    goto v_6561;
v_6562:
    goto v_6558;
v_6559:
    goto v_6560;
v_6561:
    if (!consp(v_7054)) goto v_6556;
    v_7054 = qcar(v_7054);
    if (v_7054 == v_7053) goto v_6555;
    else goto v_6556;
v_6555:
    v_7053 = stack[-5];
    v_7053 = qcdr(v_7053);
    fn = elt(env, 28); // revlis
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    stack[-1] = v_7053;
    fn = elt(env, 29); // numlis
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    if (v_7053 == nil) goto v_6568;
    else goto v_6569;
v_6568:
    v_7053 = nil;
    goto v_6567;
v_6569:
    goto v_6581;
v_6577:
    v_7053 = stack[-1];
    v_7054 = Llength(nil, v_7053);
    env = stack[-7];
    goto v_6578;
v_6579:
    v_7053 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_6580;
v_6581:
    goto v_6577;
v_6578:
    goto v_6579;
v_6580:
    v_7053 = (v_7054 == v_7053 ? lisp_true : nil);
    goto v_6567;
    v_7053 = nil;
v_6567:
    goto v_6554;
v_6556:
    v_7053 = nil;
    goto v_6554;
    v_7053 = nil;
v_6554:
    if (v_7053 == nil) goto v_6552;
    goto v_6594;
v_6590:
    goto v_6601;
v_6597:
    goto v_6607;
v_6603:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    v_7054 = qcdr(v_7053);
    goto v_6604;
v_6605:
    v_7053 = stack[-1];
    v_7053 = qcar(v_7053);
    goto v_6606;
v_6607:
    goto v_6603;
v_6604:
    goto v_6605;
v_6606:
    fn = elt(env, 30); // nth
    v_7054 = (*qfn2(fn))(fn, v_7054, v_7053);
    env = stack[-7];
    goto v_6598;
v_6599:
    v_7053 = stack[-1];
    v_7053 = qcdr(v_7053);
    v_7053 = qcar(v_7053);
    goto v_6600;
v_6601:
    goto v_6597;
v_6598:
    goto v_6599;
v_6600:
    fn = elt(env, 30); // nth
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    env = stack[-7];
    v_7054 = CC_simp(elt(env, 0), v_7053);
    env = stack[-7];
    goto v_6591;
v_6592:
    v_7053 = stack[-5];
    goto v_6593;
v_6594:
    goto v_6590;
v_6591:
    goto v_6592;
v_6593:
    fn = elt(env, 26); // !*ssave
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6326;
v_6552:
    goto v_6624;
v_6620:
    v_7054 = stack[-5];
    goto v_6621;
v_6622:
    v_7053 = lisp_true;
    goto v_6623;
v_6624:
    goto v_6620;
v_6621:
    goto v_6622;
v_6623:
    fn = elt(env, 31); // errpri2
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6512;
v_6512:
    goto v_6484;
v_6498:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!symbolp(v_7053)) v_7053 = nil;
    else { v_7053 = qfastgets(v_7053);
           if (v_7053 != nil) { v_7053 = elt(v_7053, 59); // opfn
#ifdef RECORD_GET
             if (v_7053 == SPID_NOPROP)
                record_get(elt(fastget_names, 59), 0),
                v_7053 = nil;
             else record_get(elt(fastget_names, 59), 1),
                v_7053 = lisp_true; }
           else record_get(elt(fastget_names, 59), 0); }
#else
             if (v_7053 == SPID_NOPROP) v_7053 = nil; else v_7053 = lisp_true; }}
#endif
    if (v_7053 == nil) goto v_6628;
    v_7053 = stack[-5];
    fn = elt(env, 32); // opfneval
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    stack[-1] = v_7053;
    fn = elt(env, 33); // getrtype
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    v_7054 = v_7053;
    if (v_7053 == nil) goto v_6634;
    else goto v_6635;
v_6634:
    goto v_6644;
v_6640:
    v_7053 = stack[-1];
    fn = elt(env, 34); // simp_without_resimp
    v_7054 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    goto v_6641;
v_6642:
    v_7053 = stack[-5];
    goto v_6643;
v_6644:
    goto v_6640;
v_6641:
    goto v_6642;
v_6643:
    fn = elt(env, 26); // !*ssave
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6326;
v_6635:
    goto v_6658;
v_6654:
    goto v_6655;
v_6656:
    v_7053 = elt(env, 15); // yetunknowntype
    goto v_6657;
v_6658:
    goto v_6654;
v_6655:
    goto v_6656;
v_6657:
    if (v_7054 == v_7053) goto v_6652;
    else goto v_6653;
v_6652:
    v_7053 = stack[-1];
    fn = elt(env, 35); // reval
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    stack[-1] = v_7053;
    fn = elt(env, 33); // getrtype
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    v_7053 = (v_7053 == nil ? lisp_true : nil);
    goto v_6651;
v_6653:
    v_7053 = nil;
    goto v_6651;
    v_7053 = nil;
v_6651:
    if (v_7053 == nil) goto v_6649;
    v_7053 = stack[-1];
    v_7053 = CC_simp(elt(env, 0), v_7053);
    goto v_6326;
v_6649:
    goto v_6677;
v_6673:
    v_7054 = stack[-5];
    goto v_6674;
v_6675:
    v_7053 = elt(env, 16); // "scalar"
    goto v_6676;
v_6677:
    goto v_6673;
v_6674:
    goto v_6675;
v_6676:
    fn = elt(env, 27); // typerr
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6633;
v_6633:
    goto v_6484;
v_6628:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!symbolp(v_7053)) v_7053 = nil;
    else { v_7053 = qfastgets(v_7053);
           if (v_7053 != nil) { v_7053 = elt(v_7053, 45); // psopfn
#ifdef RECORD_GET
             if (v_7053 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_7053 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_7053 == SPID_NOPROP) v_7053 = nil; }}
#endif
    stack[-1] = v_7053;
    if (v_7053 == nil) goto v_6681;
    goto v_6695;
v_6691:
    stack[0] = stack[-1];
    goto v_6692;
v_6693:
    v_7053 = stack[-5];
    fn = elt(env, 36); // argnochk
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    v_7053 = qcdr(v_7053);
    goto v_6694;
v_6695:
    goto v_6691;
v_6692:
    goto v_6693;
v_6694:
    v_7053 = Lapply1(nil, stack[0], v_7053);
    env = stack[-7];
    stack[-1] = v_7053;
    fn = elt(env, 33); // getrtype
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    if (v_7053 == nil) goto v_6688;
    goto v_6705;
v_6701:
    v_7054 = stack[-5];
    goto v_6702;
v_6703:
    v_7053 = elt(env, 16); // "scalar"
    goto v_6704;
v_6705:
    goto v_6701;
v_6702:
    goto v_6703;
v_6704:
    fn = elt(env, 27); // typerr
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6686;
v_6688:
    goto v_6714;
v_6710:
    v_7054 = stack[-1];
    goto v_6711;
v_6712:
    v_7053 = stack[-5];
    goto v_6713;
v_6714:
    goto v_6710;
v_6711:
    goto v_6712;
v_6713:
    if (equal(v_7054, v_7053)) goto v_6708;
    else goto v_6709;
v_6708:
    goto v_6722;
v_6718:
    goto v_6728;
v_6724:
    goto v_6735;
v_6731:
    goto v_6741;
v_6737:
    v_7054 = stack[-1];
    goto v_6738;
v_6739:
    v_7053 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6740;
v_6741:
    goto v_6737;
v_6738:
    goto v_6739;
v_6740:
    fn = elt(env, 37); // to
    v_7054 = (*qfn2(fn))(fn, v_7054, v_7053);
    env = stack[-7];
    goto v_6732;
v_6733:
    v_7053 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6734;
v_6735:
    goto v_6731;
v_6732:
    goto v_6733;
v_6734:
    v_7053 = cons(v_7054, v_7053);
    env = stack[-7];
    v_7054 = ncons(v_7053);
    env = stack[-7];
    goto v_6725;
v_6726:
    v_7053 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6727;
v_6728:
    goto v_6724;
v_6725:
    goto v_6726;
v_6727:
    v_7054 = cons(v_7054, v_7053);
    env = stack[-7];
    goto v_6719;
v_6720:
    v_7053 = stack[-5];
    goto v_6721;
v_6722:
    goto v_6718;
v_6719:
    goto v_6720;
v_6721:
    fn = elt(env, 26); // !*ssave
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6326;
v_6709:
    goto v_6754;
v_6750:
    v_7053 = stack[-1];
    fn = elt(env, 34); // simp_without_resimp
    v_7054 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    goto v_6751;
v_6752:
    v_7053 = stack[-5];
    goto v_6753;
v_6754:
    goto v_6750;
v_6751:
    goto v_6752;
v_6753:
    fn = elt(env, 26); // !*ssave
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6326;
v_6686:
    goto v_6484;
v_6681:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!symbolp(v_7053)) v_7053 = nil;
    else { v_7053 = qfastgets(v_7053);
           if (v_7053 != nil) { v_7053 = elt(v_7053, 41); // polyfn
#ifdef RECORD_GET
             if (v_7053 != SPID_NOPROP)
                record_get(elt(fastget_names, 41), 1);
             else record_get(elt(fastget_names, 41), 0),
                v_7053 = nil; }
           else record_get(elt(fastget_names, 41), 0); }
#else
             if (v_7053 == SPID_NOPROP) v_7053 = nil; }}
#endif
    stack[-1] = v_7053;
    if (v_7053 == nil) goto v_6759;
    v_7053 = stack[-5];
    fn = elt(env, 36); // argnochk
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    goto v_6770;
v_6766:
    goto v_6776;
v_6772:
    goto v_6782;
v_6778:
    stack[-4] = stack[-1];
    goto v_6779;
v_6780:
    v_7053 = stack[-5];
    v_7053 = qcdr(v_7053);
    stack[-3] = v_7053;
    v_7053 = stack[-3];
    if (v_7053 == nil) goto v_6794;
    else goto v_6795;
v_6794:
    v_7053 = nil;
    goto v_6788;
v_6795:
    v_7053 = stack[-3];
    v_7053 = qcar(v_7053);
    fn = elt(env, 38); // simp!*
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    fn = elt(env, 39); // !*q2f
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    v_7053 = ncons(v_7053);
    env = stack[-7];
    stack[-1] = v_7053;
    stack[-2] = v_7053;
v_6789:
    v_7053 = stack[-3];
    v_7053 = qcdr(v_7053);
    stack[-3] = v_7053;
    v_7053 = stack[-3];
    if (v_7053 == nil) goto v_6809;
    else goto v_6810;
v_6809:
    v_7053 = stack[-2];
    goto v_6788;
v_6810:
    goto v_6818;
v_6814:
    stack[0] = stack[-1];
    goto v_6815;
v_6816:
    v_7053 = stack[-3];
    v_7053 = qcar(v_7053);
    fn = elt(env, 38); // simp!*
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    fn = elt(env, 39); // !*q2f
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    v_7053 = ncons(v_7053);
    env = stack[-7];
    goto v_6817;
v_6818:
    goto v_6814;
v_6815:
    goto v_6816;
v_6817:
    v_7053 = Lrplacd(nil, stack[0], v_7053);
    env = stack[-7];
    v_7053 = stack[-1];
    v_7053 = qcdr(v_7053);
    stack[-1] = v_7053;
    goto v_6789;
v_6788:
    goto v_6781;
v_6782:
    goto v_6778;
v_6779:
    goto v_6780;
v_6781:
    fn = elt(env, 40); // lispapply
    v_7054 = (*qfn2(fn))(fn, stack[-4], v_7053);
    env = stack[-7];
    goto v_6773;
v_6774:
    v_7053 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6775;
v_6776:
    goto v_6772;
v_6773:
    goto v_6774;
v_6775:
    v_7054 = cons(v_7054, v_7053);
    env = stack[-7];
    goto v_6767;
v_6768:
    v_7053 = stack[-5];
    goto v_6769;
v_6770:
    goto v_6766;
v_6767:
    goto v_6768;
v_6769:
    fn = elt(env, 26); // !*ssave
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6326;
v_6759:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!symbolp(v_7053)) v_7053 = nil;
    else { v_7053 = qfastgets(v_7053);
           if (v_7053 != nil) { v_7053 = elt(v_7053, 9); // opmtch
#ifdef RECORD_GET
             if (v_7053 != SPID_NOPROP)
                record_get(elt(fastget_names, 9), 1);
             else record_get(elt(fastget_names, 9), 0),
                v_7053 = nil; }
           else record_get(elt(fastget_names, 9), 0); }
#else
             if (v_7053 == SPID_NOPROP) v_7053 = nil; }}
#endif
    if (v_7053 == nil) goto v_6832;
    goto v_6846;
v_6842:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!symbolp(v_7053)) v_7054 = nil;
    else { v_7054 = qfastgets(v_7053);
           if (v_7054 != nil) { v_7054 = elt(v_7054, 22); // simpfn
#ifdef RECORD_GET
             if (v_7054 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_7054 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_7054 == SPID_NOPROP) v_7054 = nil; }}
#endif
    goto v_6843;
v_6844:
    v_7053 = elt(env, 17); // simpiden
    goto v_6845;
v_6846:
    goto v_6842;
v_6843:
    goto v_6844;
v_6845:
    if (v_7054 == v_7053) goto v_6841;
    v_7053 = stack[-5];
    fn = elt(env, 41); // opmtchrevop
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    stack[-1] = v_7053;
    goto v_6839;
v_6841:
    v_7053 = nil;
    goto v_6839;
    v_7053 = nil;
v_6839:
    if (v_7053 == nil) goto v_6832;
    goto v_6861;
v_6857:
    v_7053 = stack[-1];
    v_7054 = CC_simp(elt(env, 0), v_7053);
    env = stack[-7];
    goto v_6858;
v_6859:
    v_7053 = stack[-5];
    goto v_6860;
v_6861:
    goto v_6857;
v_6858:
    goto v_6859;
v_6860:
    fn = elt(env, 26); // !*ssave
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6326;
v_6832:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!symbolp(v_7053)) v_7053 = nil;
    else { v_7053 = qfastgets(v_7053);
           if (v_7053 != nil) { v_7053 = elt(v_7053, 22); // simpfn
#ifdef RECORD_GET
             if (v_7053 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_7053 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_7053 == SPID_NOPROP) v_7053 = nil; }}
#endif
    stack[-1] = v_7053;
    if (v_7053 == nil) goto v_6866;
    goto v_6875;
v_6871:
    goto v_6881;
v_6877:
    stack[0] = stack[-1];
    goto v_6878;
v_6879:
    goto v_6895;
v_6891:
    v_7054 = stack[-1];
    goto v_6892;
v_6893:
    v_7053 = elt(env, 17); // simpiden
    goto v_6894;
v_6895:
    goto v_6891;
v_6892:
    goto v_6893;
v_6894:
    if (v_7054 == v_7053) goto v_6889;
    else goto v_6890;
v_6889:
    v_7053 = lisp_true;
    goto v_6888;
v_6890:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!symbolp(v_7053)) v_7053 = nil;
    else { v_7053 = qfastgets(v_7053);
           if (v_7053 != nil) { v_7053 = elt(v_7053, 62); // full
#ifdef RECORD_GET
             if (v_7053 == SPID_NOPROP)
                record_get(elt(fastget_names, 62), 0),
                v_7053 = nil;
             else record_get(elt(fastget_names, 62), 1),
                v_7053 = lisp_true; }
           else record_get(elt(fastget_names, 62), 0); }
#else
             if (v_7053 == SPID_NOPROP) v_7053 = nil; else v_7053 = lisp_true; }}
#endif
    goto v_6888;
    v_7053 = nil;
v_6888:
    if (v_7053 == nil) goto v_6886;
    v_7053 = stack[-5];
    fn = elt(env, 36); // argnochk
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    goto v_6884;
v_6886:
    v_7053 = stack[-5];
    fn = elt(env, 36); // argnochk
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    v_7053 = qcdr(v_7053);
    goto v_6884;
    v_7053 = nil;
v_6884:
    goto v_6880;
v_6881:
    goto v_6877;
v_6878:
    goto v_6879;
v_6880:
    v_7054 = Lapply1(nil, stack[0], v_7053);
    env = stack[-7];
    goto v_6872;
v_6873:
    v_7053 = stack[-5];
    goto v_6874;
v_6875:
    goto v_6871;
v_6872:
    goto v_6873;
v_6874:
    fn = elt(env, 26); // !*ssave
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6326;
v_6866:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!symbolp(v_7053)) v_7053 = nil;
    else { v_7053 = qfastgets(v_7053);
           if (v_7053 != nil) { v_7053 = elt(v_7053, 2); // rtype
#ifdef RECORD_GET
             if (v_7053 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_7053 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_7053 == SPID_NOPROP) v_7053 = nil; }}
#endif
    stack[-1] = v_7053;
    if (v_7053 == nil) goto v_6913;
    goto v_6924;
v_6920:
    v_7054 = stack[-1];
    goto v_6921;
v_6922:
    v_7053 = elt(env, 18); // getelemfn
    goto v_6923;
v_6924:
    goto v_6920;
v_6921:
    goto v_6922;
v_6923:
    v_7053 = get(v_7054, v_7053);
    env = stack[-7];
    stack[-1] = v_7053;
    if (v_7053 == nil) goto v_6913;
    goto v_6932;
v_6928:
    goto v_6939;
v_6935:
    v_7054 = stack[-1];
    goto v_6936;
v_6937:
    v_7053 = stack[-5];
    goto v_6938;
v_6939:
    goto v_6935;
v_6936:
    goto v_6937;
v_6938:
    v_7053 = Lapply1(nil, v_7054, v_7053);
    env = stack[-7];
    v_7054 = CC_simp(elt(env, 0), v_7053);
    env = stack[-7];
    goto v_6929;
v_6930:
    v_7053 = stack[-5];
    goto v_6931;
v_6932:
    goto v_6928;
v_6929:
    goto v_6930;
v_6931:
    fn = elt(env, 26); // !*ssave
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6326;
v_6913:
    goto v_6954;
v_6950:
    v_7053 = stack[-5];
    v_7054 = qcar(v_7053);
    goto v_6951;
v_6952:
    v_7053 = elt(env, 19); // boolean
    goto v_6953;
v_6954:
    goto v_6950;
v_6951:
    goto v_6952;
v_6953:
    v_7053 = Lflagp(nil, v_7054, v_7053);
    env = stack[-7];
    if (v_7053 == nil) goto v_6948;
    v_7053 = lisp_true;
    goto v_6946;
v_6948:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!symbolp(v_7053)) v_7053 = nil;
    else { v_7053 = qfastgets(v_7053);
           if (v_7053 != nil) { v_7053 = elt(v_7053, 23); // infix
#ifdef RECORD_GET
             if (v_7053 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_7053 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_7053 == SPID_NOPROP) v_7053 = nil; }}
#endif
    goto v_6946;
    v_7053 = nil;
v_6946:
    if (v_7053 == nil) goto v_6944;
    goto v_6969;
v_6965:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!symbolp(v_7053)) v_7053 = nil;
    else { v_7053 = qfastgets(v_7053);
           if (v_7053 != nil) { v_7053 = elt(v_7053, 37); // prtch
#ifdef RECORD_GET
             if (v_7053 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_7053 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_7053 == SPID_NOPROP) v_7053 = nil; }}
#endif
    stack[-1] = v_7053;
    if (v_7053 == nil) goto v_6973;
    v_7053 = stack[-1];
    v_7054 = v_7053;
    goto v_6971;
v_6973:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    v_7054 = v_7053;
    goto v_6971;
    v_7054 = nil;
v_6971:
    goto v_6966;
v_6967:
    v_7053 = elt(env, 20); // "algebraic operator"
    goto v_6968;
v_6969:
    goto v_6965;
v_6966:
    goto v_6967;
v_6968:
    fn = elt(env, 27); // typerr
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6484;
v_6944:
    goto v_6990;
v_6986:
    v_7053 = stack[-5];
    v_7054 = qcar(v_7053);
    goto v_6987;
v_6988:
    v_7053 = elt(env, 21); // nochange
    goto v_6989;
v_6990:
    goto v_6986;
v_6987:
    goto v_6988;
v_6989:
    v_7053 = Lflagp(nil, v_7054, v_7053);
    env = stack[-7];
    if (v_7053 == nil) goto v_6984;
    goto v_6999;
v_6995:
    v_7053 = stack[-5];
    fn = elt(env, 42); // lispeval
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    v_7054 = CC_simp(elt(env, 0), v_7053);
    env = stack[-7];
    goto v_6996;
v_6997:
    v_7053 = stack[-5];
    goto v_6998;
v_6999:
    goto v_6995;
v_6996:
    goto v_6997;
v_6998:
    fn = elt(env, 26); // !*ssave
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6326;
v_6984:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!symbolp(v_7053)) v_7053 = nil;
    else { v_7053 = qfastgets(v_7053);
           if (v_7053 != nil) { v_7053 = elt(v_7053, 45); // psopfn
#ifdef RECORD_GET
             if (v_7053 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_7053 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_7053 == SPID_NOPROP) v_7053 = nil; }}
#endif
    if (v_7053 == nil) goto v_7006;
    else goto v_7004;
v_7006:
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    if (!symbolp(v_7053)) v_7053 = nil;
    else { v_7053 = qfastgets(v_7053);
           if (v_7053 != nil) { v_7053 = elt(v_7053, 19); // rtypefn
#ifdef RECORD_GET
             if (v_7053 != SPID_NOPROP)
                record_get(elt(fastget_names, 19), 1);
             else record_get(elt(fastget_names, 19), 0),
                v_7053 = nil; }
           else record_get(elt(fastget_names, 19), 0); }
#else
             if (v_7053 == SPID_NOPROP) v_7053 = nil; }}
#endif
    if (v_7053 == nil) goto v_7010;
    else goto v_7004;
v_7010:
    goto v_7005;
v_7004:
    goto v_7019;
v_7015:
    v_7054 = stack[-5];
    goto v_7016;
v_7017:
    v_7053 = elt(env, 16); // "scalar"
    goto v_7018;
v_7019:
    goto v_7015;
v_7016:
    goto v_7017;
v_7018:
    fn = elt(env, 27); // typerr
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6484;
v_7005:
    goto v_7029;
v_7025:
    v_7053 = stack[-5];
    v_7054 = qcar(v_7053);
    goto v_7026;
v_7027:
    v_7053 = elt(env, 12); // "operator"
    goto v_7028;
v_7029:
    goto v_7025;
v_7026:
    goto v_7027;
v_7028:
    fn = elt(env, 43); // redmsg
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    env = stack[-7];
    v_7053 = stack[-5];
    v_7053 = qcar(v_7053);
    fn = elt(env, 44); // mkop
    v_7053 = (*qfn1(fn))(fn, v_7053);
    env = stack[-7];
    goto v_7041;
v_7037:
    v_7054 = stack[-5];
    goto v_7038;
v_7039:
    v_7053 = qvalue(elt(env, 1)); // varstack!*
    goto v_7040;
v_7041:
    goto v_7037;
v_7038:
    goto v_7039;
v_7040:
    v_7053 = Ldelete(nil, v_7054, v_7053);
    env = stack[-7];
    qvalue(elt(env, 1)) = v_7053; // varstack!*
    goto v_7049;
v_7045:
    v_7053 = stack[-5];
    v_7054 = CC_simp(elt(env, 0), v_7053);
    env = stack[-7];
    goto v_7046;
v_7047:
    v_7053 = stack[-5];
    goto v_7048;
v_7049:
    goto v_7045;
v_7046:
    goto v_7047;
v_7048:
    fn = elt(env, 26); // !*ssave
    v_7053 = (*qfn2(fn))(fn, v_7054, v_7053);
    goto v_6326;
v_6484:
    v_7053 = nil;
v_6326:
    ;}  // end of a binding scope
    return onevalue(v_7053);
}



// Code for compactfmatch2

static LispObject CC_compactfmatch2(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6353, v_6354;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_6319;
// end of prologue
    v_6353 = stack[0];
    if (!consp(v_6353)) goto v_6323;
    else goto v_6324;
v_6323:
    v_6353 = nil;
    goto v_6322;
v_6324:
    goto v_6333;
v_6329:
    v_6353 = stack[0];
    v_6354 = qcar(v_6353);
    goto v_6330;
v_6331:
    v_6353 = elt(env, 1); // !~
    goto v_6332;
v_6333:
    goto v_6329;
v_6330:
    goto v_6331;
v_6332:
    if (v_6354 == v_6353) goto v_6327;
    else goto v_6328;
v_6327:
    v_6353 = stack[0];
    return ncons(v_6353);
v_6328:
    goto v_6346;
v_6342:
    v_6353 = stack[0];
    v_6353 = qcar(v_6353);
    stack[-1] = CC_compactfmatch2(elt(env, 0), v_6353);
    env = stack[-2];
    goto v_6343;
v_6344:
    v_6353 = stack[0];
    v_6353 = qcdr(v_6353);
    v_6353 = CC_compactfmatch2(elt(env, 0), v_6353);
    goto v_6345;
v_6346:
    goto v_6342;
v_6343:
    goto v_6344;
v_6345:
    {
        LispObject v_6357 = stack[-1];
        return Lappend(nil, v_6357, v_6353);
    }
    v_6353 = nil;
v_6322:
    return onevalue(v_6353);
}



// Code for dp!=mocompare

static LispObject CC_dpMmocompare(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6339, v_6340;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
// copy arguments values to proper place
    v_6339 = v_6320;
    v_6340 = v_6319;
// end of prologue
    goto v_6327;
v_6323:
    goto v_6333;
v_6329:
    v_6340 = qcar(v_6340);
    goto v_6330;
v_6331:
    v_6339 = qcar(v_6339);
    goto v_6332;
v_6333:
    goto v_6329;
v_6330:
    goto v_6331;
v_6332:
    fn = elt(env, 1); // mo_compare
    v_6340 = (*qfn2(fn))(fn, v_6340, v_6339);
    goto v_6324;
v_6325:
    v_6339 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6326;
v_6327:
    goto v_6323;
v_6324:
    goto v_6325;
v_6326:
        return Leqn(nil, v_6340, v_6339);
}



// Code for raiseind!:

static LispObject CC_raiseindT(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6332, v_6333;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6332 = v_6319;
// end of prologue
    v_6333 = v_6332;
    if (!consp(v_6333)) goto v_6323;
    else goto v_6324;
v_6323:
    goto v_6322;
v_6324:
    v_6332 = qcdr(v_6332);
    v_6332 = qcar(v_6332);
    goto v_6322;
    v_6332 = nil;
v_6322:
    return onevalue(v_6332);
}



// Code for set!-general!-modulus

static LispObject CC_setKgeneralKmodulus(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6360, v_6361;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_6319;
// end of prologue
    v_6360 = stack[0];
    if (is_number(v_6360)) goto v_6328;
    v_6360 = lisp_true;
    goto v_6326;
v_6328:
    goto v_6337;
v_6333:
    v_6361 = stack[0];
    goto v_6334;
v_6335:
    v_6360 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6336;
v_6337:
    goto v_6333;
v_6334:
    goto v_6335;
v_6336:
    v_6360 = (v_6361 == v_6360 ? lisp_true : nil);
    goto v_6326;
    v_6360 = nil;
v_6326:
    if (v_6360 == nil) goto v_6324;
    v_6360 = qvalue(elt(env, 1)); // current!-modulus
    goto v_6322;
v_6324:
    v_6360 = qvalue(elt(env, 1)); // current!-modulus
    stack[-1] = v_6360;
    v_6360 = stack[0];
    qvalue(elt(env, 1)) = v_6360; // current!-modulus
    goto v_6354;
v_6350:
    v_6361 = stack[0];
    goto v_6351;
v_6352:
    v_6360 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_6353;
v_6354:
    goto v_6350;
v_6351:
    goto v_6352;
v_6353:
    v_6360 = quot2(v_6361, v_6360);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_6360; // modulus!/2
    v_6360 = stack[0];
    v_6360 = Lset_small_modulus(nil, v_6360);
    v_6360 = stack[-1];
    goto v_6322;
    v_6360 = nil;
v_6322:
    return onevalue(v_6360);
}



// Code for ra_budan!-transform

static LispObject CC_ra_budanKtransform(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6427, v_6428;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_6319;
// end of prologue
    goto v_6331;
v_6327:
    goto v_6338;
v_6334:
    goto v_6344;
v_6340:
    v_6428 = elt(env, 1); // x
    goto v_6341;
v_6342:
    v_6427 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6343;
v_6344:
    goto v_6340;
v_6341:
    goto v_6342;
v_6343:
    fn = elt(env, 2); // to
    v_6428 = (*qfn2(fn))(fn, v_6428, v_6427);
    env = stack[-4];
    goto v_6335;
v_6336:
    v_6427 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6337;
v_6338:
    goto v_6334;
v_6335:
    goto v_6336;
v_6337:
    v_6427 = cons(v_6428, v_6427);
    env = stack[-4];
    v_6428 = ncons(v_6427);
    env = stack[-4];
    goto v_6328;
v_6329:
    v_6427 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6330;
v_6331:
    goto v_6327;
v_6328:
    goto v_6329;
v_6330:
    fn = elt(env, 3); // addf
    v_6427 = (*qfn2(fn))(fn, v_6428, v_6427);
    env = stack[-4];
    stack[0] = v_6427;
    v_6427 = stack[-2];
    if (!consp(v_6427)) goto v_6355;
    else goto v_6356;
v_6355:
    v_6427 = lisp_true;
    goto v_6354;
v_6356:
    v_6427 = stack[-2];
    v_6427 = qcar(v_6427);
    v_6427 = (consp(v_6427) ? nil : lisp_true);
    goto v_6354;
    v_6427 = nil;
v_6354:
    if (v_6427 == nil) goto v_6352;
    v_6427 = stack[-2];
    goto v_6325;
v_6352:
    v_6427 = stack[-2];
    v_6427 = qcdr(v_6427);
    v_6427 = CC_ra_budanKtransform(elt(env, 0), v_6427);
    env = stack[-4];
    stack[-3] = v_6427;
    v_6427 = stack[-2];
    v_6427 = qcdr(v_6427);
    if (!consp(v_6427)) goto v_6374;
    else goto v_6375;
v_6374:
    v_6427 = lisp_true;
    goto v_6373;
v_6375:
    v_6427 = stack[-2];
    v_6427 = qcdr(v_6427);
    v_6427 = qcar(v_6427);
    v_6427 = (consp(v_6427) ? nil : lisp_true);
    goto v_6373;
    v_6427 = nil;
v_6373:
    if (v_6427 == nil) goto v_6371;
    v_6427 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6369;
v_6371:
    v_6427 = stack[-2];
    v_6427 = qcdr(v_6427);
    v_6427 = qcar(v_6427);
    v_6427 = qcar(v_6427);
    v_6427 = qcdr(v_6427);
    goto v_6369;
    v_6427 = nil;
v_6369:
    goto v_6398;
v_6394:
    v_6428 = stack[-2];
    v_6428 = qcar(v_6428);
    stack[-1] = qcdr(v_6428);
    goto v_6395;
v_6396:
    goto v_6407;
v_6403:
    goto v_6413;
v_6409:
    goto v_6410;
v_6411:
    goto v_6420;
v_6416:
    v_6428 = stack[-2];
    v_6428 = qcar(v_6428);
    v_6428 = qcar(v_6428);
    v_6428 = qcdr(v_6428);
    goto v_6417;
v_6418:
    goto v_6419;
v_6420:
    goto v_6416;
v_6417:
    goto v_6418;
v_6419:
    v_6427 = difference2(v_6428, v_6427);
    env = stack[-4];
    goto v_6412;
v_6413:
    goto v_6409;
v_6410:
    goto v_6411;
v_6412:
    fn = elt(env, 4); // exptf
    v_6428 = (*qfn2(fn))(fn, stack[0], v_6427);
    env = stack[-4];
    goto v_6404;
v_6405:
    v_6427 = stack[-3];
    goto v_6406;
v_6407:
    goto v_6403;
v_6404:
    goto v_6405;
v_6406:
    fn = elt(env, 5); // multf
    v_6427 = (*qfn2(fn))(fn, v_6428, v_6427);
    env = stack[-4];
    goto v_6397;
v_6398:
    goto v_6394;
v_6395:
    goto v_6396;
v_6397:
    {
        LispObject v_6433 = stack[-1];
        fn = elt(env, 3); // addf
        return (*qfn2(fn))(fn, v_6433, v_6427);
    }
v_6325:
    return onevalue(v_6427);
}



// Code for rempropss

static LispObject CC_rempropss(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6362, v_6363, v_6364, v_6365, v_6366, v_6367;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_6366 = v_6320;
    v_6362 = v_6319;
// end of prologue
    v_6367 = v_6362;
v_6325:
    v_6362 = v_6367;
    if (v_6362 == nil) goto v_6329;
    else goto v_6330;
v_6329:
    v_6362 = nil;
    goto v_6324;
v_6330:
    v_6362 = v_6367;
    v_6362 = qcar(v_6362);
    v_6365 = v_6362;
    v_6362 = v_6366;
    v_6364 = v_6362;
v_6339:
    v_6362 = v_6364;
    if (v_6362 == nil) goto v_6343;
    else goto v_6344;
v_6343:
    goto v_6338;
v_6344:
    v_6362 = v_6364;
    v_6362 = qcar(v_6362);
    goto v_6355;
v_6351:
    v_6363 = v_6365;
    goto v_6352;
v_6353:
    goto v_6354;
v_6355:
    goto v_6351;
v_6352:
    goto v_6353;
v_6354:
    v_6362 = Lremprop(nil, v_6363, v_6362);
    env = stack[0];
    v_6362 = v_6364;
    v_6362 = qcdr(v_6362);
    v_6364 = v_6362;
    goto v_6339;
v_6338:
    v_6362 = v_6367;
    v_6362 = qcdr(v_6362);
    v_6367 = v_6362;
    goto v_6325;
v_6324:
    return onevalue(v_6362);
}



// Code for ofsf_smwcpknowl

static LispObject CC_ofsf_smwcpknowl(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6332, v_6333;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6333 = v_6319;
// end of prologue
    v_6332 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_6332 == nil) goto v_6324;
    v_6332 = v_6333;
    {
        fn = elt(env, 2); // cl_susicpknowl
        return (*qfn1(fn))(fn, v_6332);
    }
v_6324:
    v_6332 = v_6333;
    {
        fn = elt(env, 3); // ofsf_smcpknowl
        return (*qfn1(fn))(fn, v_6332);
    }
    v_6332 = nil;
    return onevalue(v_6332);
}



// Code for color1

static LispObject CC_color1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6654, v_6655, v_6656, v_6657;
    LispObject fn;
    LispObject v_6321, v_6320, v_6319;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "color1");
    va_start(aa, nargs);
    v_6319 = va_arg(aa, LispObject);
    v_6320 = va_arg(aa, LispObject);
    v_6321 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_6321,v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_6319,v_6320,v_6321);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_6321;
    stack[-1] = v_6320;
    v_6656 = v_6319;
// end of prologue
v_6318:
v_6326:
    v_6654 = v_6656;
    v_6654 = qcar(v_6654);
    v_6654 = qcar(v_6654);
    if (v_6654 == nil) goto v_6333;
    else goto v_6334;
v_6333:
    v_6654 = lisp_true;
    goto v_6332;
v_6334:
    v_6654 = v_6656;
    v_6654 = qcdr(v_6654);
    v_6654 = (v_6654 == nil ? lisp_true : nil);
    goto v_6332;
    v_6654 = nil;
v_6332:
    if (v_6654 == nil) goto v_6330;
    v_6654 = stack[-1];
    if (v_6654 == nil) goto v_6346;
    else goto v_6347;
v_6346:
    goto v_6354;
v_6350:
    v_6654 = v_6656;
    v_6655 = qcar(v_6654);
    goto v_6351;
v_6352:
    v_6654 = stack[0];
    goto v_6353;
v_6354:
    goto v_6350;
v_6351:
    goto v_6352;
v_6353:
    {
        fn = elt(env, 5); // addsq
        return (*qfn2(fn))(fn, v_6655, v_6654);
    }
v_6347:
    v_6654 = stack[-1];
    v_6654 = qcar(v_6654);
    stack[-2] = v_6654;
    v_6654 = stack[-1];
    v_6654 = qcdr(v_6654);
    stack[-1] = v_6654;
    goto v_6369;
v_6365:
    v_6654 = v_6656;
    v_6655 = qcar(v_6654);
    goto v_6366;
v_6367:
    v_6654 = stack[0];
    goto v_6368;
v_6369:
    goto v_6365;
v_6366:
    goto v_6367;
v_6368:
    fn = elt(env, 5); // addsq
    v_6654 = (*qfn2(fn))(fn, v_6655, v_6654);
    env = stack[-3];
    stack[0] = v_6654;
    v_6654 = stack[-2];
    v_6656 = v_6654;
    goto v_6326;
    goto v_6328;
v_6330:
    goto v_6387;
v_6383:
    v_6655 = elt(env, 1); // qg
    goto v_6384;
v_6385:
    v_6654 = v_6656;
    v_6654 = qcdr(v_6654);
    goto v_6386;
v_6387:
    goto v_6383;
v_6384:
    goto v_6385;
v_6386:
    v_6654 = Lassoc(nil, v_6655, v_6654);
    v_6657 = v_6654;
    if (v_6654 == nil) goto v_6382;
    goto v_6404;
v_6400:
    v_6654 = v_6657;
    v_6654 = qcdr(v_6654);
    v_6655 = qcar(v_6654);
    goto v_6401;
v_6402:
    v_6654 = v_6657;
    v_6654 = qcdr(v_6654);
    v_6654 = qcdr(v_6654);
    v_6654 = qcar(v_6654);
    goto v_6403;
v_6404:
    goto v_6400;
v_6401:
    goto v_6402;
v_6403:
    if (v_6655 == v_6654) goto v_6398;
    else goto v_6399;
v_6398:
    v_6654 = lisp_true;
    goto v_6397;
v_6399:
    goto v_6423;
v_6419:
    v_6654 = v_6657;
    v_6654 = qcdr(v_6654);
    v_6655 = qcar(v_6654);
    goto v_6420;
v_6421:
    v_6654 = v_6657;
    v_6654 = qcdr(v_6654);
    v_6654 = qcdr(v_6654);
    v_6654 = qcdr(v_6654);
    v_6654 = qcar(v_6654);
    goto v_6422;
v_6423:
    goto v_6419;
v_6420:
    goto v_6421;
v_6422:
    if (v_6655 == v_6654) goto v_6417;
    else goto v_6418;
v_6417:
    v_6654 = lisp_true;
    goto v_6416;
v_6418:
    goto v_6439;
v_6435:
    v_6654 = v_6657;
    v_6654 = qcdr(v_6654);
    v_6654 = qcdr(v_6654);
    v_6655 = qcar(v_6654);
    goto v_6436;
v_6437:
    v_6654 = v_6657;
    v_6654 = qcdr(v_6654);
    v_6654 = qcdr(v_6654);
    v_6654 = qcdr(v_6654);
    v_6654 = qcar(v_6654);
    goto v_6438;
v_6439:
    goto v_6435;
v_6436:
    goto v_6437;
v_6438:
    v_6654 = (v_6655 == v_6654 ? lisp_true : nil);
    goto v_6416;
    v_6654 = nil;
v_6416:
    goto v_6397;
    v_6654 = nil;
v_6397:
    if (v_6654 == nil) goto v_6395;
    goto v_6457;
v_6451:
    goto v_6464;
v_6460:
    v_6655 = nil;
    goto v_6461;
v_6462:
    v_6654 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6463;
v_6464:
    goto v_6460;
v_6461:
    goto v_6462;
v_6463:
    v_6654 = cons(v_6655, v_6654);
    env = stack[-3];
    v_6656 = ncons(v_6654);
    env = stack[-3];
    goto v_6452;
v_6453:
    v_6655 = stack[-1];
    goto v_6454;
v_6455:
    v_6654 = stack[0];
    goto v_6456;
v_6457:
    goto v_6451;
v_6452:
    goto v_6453;
v_6454:
    goto v_6455;
v_6456:
    stack[-1] = v_6655;
    stack[0] = v_6654;
    goto v_6318;
v_6395:
    goto v_6474;
v_6470:
    v_6654 = v_6656;
    goto v_6471;
v_6472:
    v_6655 = v_6657;
    goto v_6473;
v_6474:
    goto v_6470;
v_6471:
    goto v_6472;
v_6473:
    fn = elt(env, 6); // removeg
    v_6654 = (*qfn2(fn))(fn, v_6654, v_6655);
    env = stack[-3];
    v_6656 = v_6654;
    goto v_6484;
v_6478:
    v_6654 = v_6656;
    stack[-2] = qcar(v_6654);
    goto v_6479;
v_6480:
    v_6654 = v_6656;
    v_6654 = qcdr(v_6654);
    if (v_6654 == nil) goto v_6490;
    goto v_6498;
v_6494:
    v_6654 = v_6656;
    v_6655 = qcdr(v_6654);
    goto v_6495;
v_6496:
    v_6654 = stack[-1];
    goto v_6497;
v_6498:
    goto v_6494;
v_6495:
    goto v_6496;
v_6497:
    v_6654 = cons(v_6655, v_6654);
    env = stack[-3];
    v_6655 = v_6654;
    goto v_6488;
v_6490:
    v_6654 = stack[-1];
    v_6655 = v_6654;
    goto v_6488;
    v_6655 = nil;
v_6488:
    goto v_6481;
v_6482:
    v_6654 = stack[0];
    goto v_6483;
v_6484:
    goto v_6478;
v_6479:
    goto v_6480;
v_6481:
    goto v_6482;
v_6483:
    v_6656 = stack[-2];
    stack[-1] = v_6655;
    stack[0] = v_6654;
    goto v_6318;
v_6382:
    goto v_6512;
v_6508:
    v_6655 = elt(env, 2); // g3
    goto v_6509;
v_6510:
    v_6654 = v_6656;
    v_6654 = qcdr(v_6654);
    goto v_6511;
v_6512:
    goto v_6508;
v_6509:
    goto v_6510;
v_6511:
    v_6654 = Lassoc(nil, v_6655, v_6654);
    v_6657 = v_6654;
    if (v_6654 == nil) goto v_6507;
    goto v_6529;
v_6525:
    v_6654 = v_6657;
    v_6654 = qcdr(v_6654);
    v_6655 = qcar(v_6654);
    goto v_6526;
v_6527:
    v_6654 = v_6657;
    v_6654 = qcdr(v_6654);
    v_6654 = qcdr(v_6654);
    v_6654 = qcar(v_6654);
    goto v_6528;
v_6529:
    goto v_6525;
v_6526:
    goto v_6527;
v_6528:
    if (v_6655 == v_6654) goto v_6523;
    else goto v_6524;
v_6523:
    v_6654 = lisp_true;
    goto v_6522;
v_6524:
    goto v_6548;
v_6544:
    v_6654 = v_6657;
    v_6654 = qcdr(v_6654);
    v_6655 = qcar(v_6654);
    goto v_6545;
v_6546:
    v_6654 = v_6657;
    v_6654 = qcdr(v_6654);
    v_6654 = qcdr(v_6654);
    v_6654 = qcdr(v_6654);
    v_6654 = qcar(v_6654);
    goto v_6547;
v_6548:
    goto v_6544;
v_6545:
    goto v_6546;
v_6547:
    if (v_6655 == v_6654) goto v_6542;
    else goto v_6543;
v_6542:
    v_6654 = lisp_true;
    goto v_6541;
v_6543:
    goto v_6564;
v_6560:
    v_6654 = v_6657;
    v_6654 = qcdr(v_6654);
    v_6654 = qcdr(v_6654);
    v_6655 = qcar(v_6654);
    goto v_6561;
v_6562:
    v_6654 = v_6657;
    v_6654 = qcdr(v_6654);
    v_6654 = qcdr(v_6654);
    v_6654 = qcdr(v_6654);
    v_6654 = qcar(v_6654);
    goto v_6563;
v_6564:
    goto v_6560;
v_6561:
    goto v_6562;
v_6563:
    v_6654 = (v_6655 == v_6654 ? lisp_true : nil);
    goto v_6541;
    v_6654 = nil;
v_6541:
    goto v_6522;
    v_6654 = nil;
v_6522:
    if (v_6654 == nil) goto v_6520;
    goto v_6582;
v_6576:
    goto v_6589;
v_6585:
    v_6655 = nil;
    goto v_6586;
v_6587:
    v_6654 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6588;
v_6589:
    goto v_6585;
v_6586:
    goto v_6587;
v_6588:
    v_6654 = cons(v_6655, v_6654);
    env = stack[-3];
    v_6656 = ncons(v_6654);
    env = stack[-3];
    goto v_6577;
v_6578:
    v_6655 = stack[-1];
    goto v_6579;
v_6580:
    v_6654 = stack[0];
    goto v_6581;
v_6582:
    goto v_6576;
v_6577:
    goto v_6578;
v_6579:
    goto v_6580;
v_6581:
    stack[-1] = v_6655;
    stack[0] = v_6654;
    goto v_6318;
v_6520:
    goto v_6599;
v_6595:
    v_6654 = v_6656;
    goto v_6596;
v_6597:
    v_6655 = v_6657;
    goto v_6598;
v_6599:
    goto v_6595;
v_6596:
    goto v_6597;
v_6598:
    fn = elt(env, 7); // split3gv
    v_6654 = (*qfn2(fn))(fn, v_6654, v_6655);
    env = stack[-3];
    v_6656 = v_6654;
    goto v_6609;
v_6603:
    v_6654 = v_6656;
    stack[-2] = qcar(v_6654);
    goto v_6604;
v_6605:
    goto v_6617;
v_6613:
    v_6654 = v_6656;
    v_6655 = qcdr(v_6654);
    goto v_6614;
v_6615:
    v_6654 = stack[-1];
    goto v_6616;
v_6617:
    goto v_6613;
v_6614:
    goto v_6615;
v_6616:
    v_6655 = cons(v_6655, v_6654);
    env = stack[-3];
    goto v_6606;
v_6607:
    v_6654 = stack[0];
    goto v_6608;
v_6609:
    goto v_6603;
v_6604:
    goto v_6605;
v_6606:
    goto v_6607;
v_6608:
    v_6656 = stack[-2];
    stack[-1] = v_6655;
    stack[0] = v_6654;
    goto v_6318;
v_6507:
    goto v_6630;
v_6626:
    stack[0] = elt(env, 3); // "Invalid structure of c0-graph."
    goto v_6627;
v_6628:
    v_6654 = v_6656;
    if (v_6654 == nil) goto v_6634;
    else goto v_6635;
v_6634:
    v_6654 = nil;
    goto v_6633;
v_6635:
    v_6654 = v_6656;
    v_6654 = qcdr(v_6654);
    if (v_6654 == nil) goto v_6638;
    else goto v_6639;
v_6638:
    v_6654 = v_6656;
    v_6654 = qcar(v_6654);
    goto v_6633;
v_6639:
    goto v_6651;
v_6647:
    v_6654 = elt(env, 4); // times
    goto v_6648;
v_6649:
    v_6655 = v_6656;
    goto v_6650;
v_6651:
    goto v_6647;
v_6648:
    goto v_6649;
v_6650:
    v_6654 = cons(v_6654, v_6655);
    env = stack[-3];
    goto v_6633;
    v_6654 = nil;
v_6633:
    goto v_6629;
v_6630:
    goto v_6626;
v_6627:
    goto v_6628;
v_6629:
    v_6654 = list2(stack[0], v_6654);
    env = stack[-3];
    fn = elt(env, 8); // cerror
    v_6654 = (*qfn1(fn))(fn, v_6654);
    goto v_6380;
v_6380:
    v_6654 = nil;
    goto v_6325;
v_6328:
    v_6654 = nil;
v_6325:
    return onevalue(v_6654);
}



// Code for msappend

static LispObject CC_msappend(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6390, v_6391;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_6320;
    v_6390 = v_6319;
// end of prologue
    stack[-5] = v_6390;
    v_6390 = stack[-5];
    if (v_6390 == nil) goto v_6331;
    else goto v_6332;
v_6331:
    v_6390 = nil;
    goto v_6326;
v_6332:
    v_6390 = stack[-5];
    v_6390 = qcar(v_6390);
    goto v_6344;
v_6340:
    stack[0] = stack[-4];
    goto v_6341;
v_6342:
    goto v_6351;
v_6347:
    v_6391 = stack[-4];
    goto v_6348;
v_6349:
    goto v_6350;
v_6351:
    goto v_6347;
v_6348:
    goto v_6349;
v_6350:
    v_6390 = Lsublis(nil, v_6391, v_6390);
    env = stack[-6];
    goto v_6343;
v_6344:
    goto v_6340;
v_6341:
    goto v_6342;
v_6343:
    v_6390 = Lappend(nil, stack[0], v_6390);
    env = stack[-6];
    v_6390 = ncons(v_6390);
    env = stack[-6];
    stack[-2] = v_6390;
    stack[-3] = v_6390;
v_6327:
    v_6390 = stack[-5];
    v_6390 = qcdr(v_6390);
    stack[-5] = v_6390;
    v_6390 = stack[-5];
    if (v_6390 == nil) goto v_6358;
    else goto v_6359;
v_6358:
    v_6390 = stack[-3];
    goto v_6326;
v_6359:
    goto v_6367;
v_6363:
    stack[-1] = stack[-2];
    goto v_6364;
v_6365:
    v_6390 = stack[-5];
    v_6390 = qcar(v_6390);
    goto v_6378;
v_6374:
    stack[0] = stack[-4];
    goto v_6375;
v_6376:
    goto v_6385;
v_6381:
    v_6391 = stack[-4];
    goto v_6382;
v_6383:
    goto v_6384;
v_6385:
    goto v_6381;
v_6382:
    goto v_6383;
v_6384:
    v_6390 = Lsublis(nil, v_6391, v_6390);
    env = stack[-6];
    goto v_6377;
v_6378:
    goto v_6374;
v_6375:
    goto v_6376;
v_6377:
    v_6390 = Lappend(nil, stack[0], v_6390);
    env = stack[-6];
    v_6390 = ncons(v_6390);
    env = stack[-6];
    goto v_6366;
v_6367:
    goto v_6363;
v_6364:
    goto v_6365;
v_6366:
    v_6390 = Lrplacd(nil, stack[-1], v_6390);
    env = stack[-6];
    v_6390 = stack[-2];
    v_6390 = qcdr(v_6390);
    stack[-2] = v_6390;
    goto v_6327;
v_6326:
    return onevalue(v_6390);
}



// Code for cl_simpl

static LispObject CC_cl_simpl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6401, v_6402, v_6403, v_6404;
    LispObject fn;
    LispObject v_6321, v_6320, v_6319;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "cl_simpl");
    va_start(aa, nargs);
    v_6319 = va_arg(aa, LispObject);
    v_6320 = va_arg(aa, LispObject);
    v_6321 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_6321,v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_6319,v_6320,v_6321);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_6321;
    v_6402 = v_6320;
    stack[-3] = v_6319;
// end of prologue
    v_6401 = qvalue(elt(env, 1)); // !*rlsism
    if (v_6401 == nil) goto v_6328;
    else goto v_6329;
v_6328:
    goto v_6340;
v_6332:
    v_6404 = stack[-3];
    goto v_6333;
v_6334:
    v_6403 = nil;
    goto v_6335;
v_6336:
    v_6402 = stack[-2];
    goto v_6337;
v_6338:
    v_6401 = nil;
    goto v_6339;
v_6340:
    goto v_6332;
v_6333:
    goto v_6334;
v_6335:
    goto v_6336;
v_6337:
    goto v_6338;
v_6339:
    {
        fn = elt(env, 5); // cl_simpl1
        return (*qfnn(fn))(fn, 4, v_6404, v_6403, v_6402, v_6401);
    }
v_6329:
    v_6401 = v_6402;
    fn = elt(env, 6); // cl_sitheo
    v_6401 = (*qfn1(fn))(fn, v_6401);
    env = stack[-5];
    v_6402 = v_6401;
    goto v_6355;
v_6351:
    v_6403 = v_6402;
    goto v_6352;
v_6353:
    v_6401 = elt(env, 2); // inctheo
    goto v_6354;
v_6355:
    goto v_6351;
v_6352:
    goto v_6353;
v_6354:
    if (v_6403 == v_6401) goto v_6349;
    else goto v_6350;
v_6349:
    v_6401 = elt(env, 2); // inctheo
    {
        fn = elt(env, 7); // rl_exc
        return (*qfn1(fn))(fn, v_6401);
    }
v_6350:
    goto v_6369;
v_6361:
    stack[-4] = elt(env, 3); // and
    goto v_6362;
v_6363:
    stack[-1] = v_6402;
    goto v_6364;
v_6365:
    stack[0] = nil;
    goto v_6366;
v_6367:
    v_6401 = stack[-2];
    v_6401 = add1(v_6401);
    env = stack[-5];
    goto v_6368;
v_6369:
    goto v_6361;
v_6362:
    goto v_6363;
v_6364:
    goto v_6365;
v_6366:
    goto v_6367;
v_6368:
    fn = elt(env, 8); // rl_smupdknowl
    v_6401 = (*qfnn(fn))(fn, 4, stack[-4], stack[-1], stack[0], v_6401);
    env = stack[-5];
    v_6402 = v_6401;
    goto v_6383;
v_6379:
    v_6403 = v_6402;
    goto v_6380;
v_6381:
    v_6401 = elt(env, 4); // false
    goto v_6382;
v_6383:
    goto v_6379;
v_6380:
    goto v_6381;
v_6382:
    if (v_6403 == v_6401) goto v_6377;
    else goto v_6378;
v_6377:
    v_6401 = elt(env, 2); // inctheo
    goto v_6325;
v_6378:
    goto v_6396;
v_6388:
    v_6404 = stack[-3];
    goto v_6389;
v_6390:
    v_6403 = v_6402;
    goto v_6391;
v_6392:
    v_6402 = stack[-2];
    goto v_6393;
v_6394:
    v_6401 = nil;
    goto v_6395;
v_6396:
    goto v_6388;
v_6389:
    goto v_6390;
v_6391:
    goto v_6392;
v_6393:
    goto v_6394;
v_6395:
    {
        fn = elt(env, 5); // cl_simpl1
        return (*qfnn(fn))(fn, 4, v_6404, v_6403, v_6402, v_6401);
    }
v_6325:
    return onevalue(v_6401);
}



// Code for qsort

static LispObject CC_qsort(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6396, v_6397;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_6397 = v_6319;
// end of prologue
    stack[-2] = nil;
    stack[-1] = nil;
    v_6396 = v_6397;
    if (v_6396 == nil) goto v_6331;
    else goto v_6332;
v_6331:
    v_6396 = nil;
    goto v_6326;
v_6332:
    v_6396 = v_6397;
    v_6396 = qcar(v_6396);
    stack[-3] = v_6396;
    v_6396 = v_6397;
    v_6396 = qcdr(v_6396);
    stack[0] = v_6396;
v_6327:
    v_6396 = stack[0];
    if (v_6396 == nil) goto v_6341;
    else goto v_6342;
v_6341:
    goto v_6328;
v_6342:
    goto v_6353;
v_6349:
    v_6397 = stack[-3];
    goto v_6350;
v_6351:
    v_6396 = stack[0];
    v_6396 = qcar(v_6396);
    goto v_6352;
v_6353:
    goto v_6349;
v_6350:
    goto v_6351;
v_6352:
    fn = elt(env, 1); // ordop
    v_6396 = (*qfn2(fn))(fn, v_6397, v_6396);
    env = stack[-4];
    if (v_6396 == nil) goto v_6347;
    goto v_6362;
v_6358:
    v_6396 = stack[0];
    v_6397 = qcar(v_6396);
    goto v_6359;
v_6360:
    v_6396 = stack[-1];
    goto v_6361;
v_6362:
    goto v_6358;
v_6359:
    goto v_6360;
v_6361:
    v_6396 = cons(v_6397, v_6396);
    env = stack[-4];
    stack[-1] = v_6396;
    goto v_6345;
v_6347:
    goto v_6373;
v_6369:
    v_6396 = stack[0];
    v_6397 = qcar(v_6396);
    goto v_6370;
v_6371:
    v_6396 = stack[-2];
    goto v_6372;
v_6373:
    goto v_6369;
v_6370:
    goto v_6371;
v_6372:
    v_6396 = cons(v_6397, v_6396);
    env = stack[-4];
    stack[-2] = v_6396;
    goto v_6345;
v_6345:
    v_6396 = stack[0];
    v_6396 = qcdr(v_6396);
    stack[0] = v_6396;
    goto v_6327;
v_6328:
    goto v_6384;
v_6380:
    v_6396 = stack[-2];
    stack[0] = CC_qsort(elt(env, 0), v_6396);
    env = stack[-4];
    goto v_6381;
v_6382:
    goto v_6392;
v_6388:
    stack[-2] = stack[-3];
    goto v_6389;
v_6390:
    v_6396 = stack[-1];
    v_6396 = CC_qsort(elt(env, 0), v_6396);
    env = stack[-4];
    goto v_6391;
v_6392:
    goto v_6388;
v_6389:
    goto v_6390;
v_6391:
    v_6396 = cons(stack[-2], v_6396);
    goto v_6383;
v_6384:
    goto v_6380;
v_6381:
    goto v_6382;
v_6383:
    {
        LispObject v_6402 = stack[0];
        return Lappend(nil, v_6402, v_6396);
    }
v_6326:
    return onevalue(v_6396);
}



// Code for cl_varl2

static LispObject CC_cl_varl2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6697, v_6698, v_6699, v_6700;
    LispObject fn;
    LispObject v_6322, v_6321, v_6320, v_6319;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "cl_varl2");
    va_start(aa, nargs);
    v_6319 = va_arg(aa, LispObject);
    v_6320 = va_arg(aa, LispObject);
    v_6321 = va_arg(aa, LispObject);
    v_6322 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_6322,v_6321,v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_6319,v_6320,v_6321,v_6322);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_6322;
    stack[-1] = v_6321;
    stack[-2] = v_6320;
    stack[-3] = v_6319;
// end of prologue
v_6318:
    v_6697 = stack[-3];
    if (!consp(v_6697)) goto v_6329;
    else goto v_6330;
v_6329:
    v_6697 = stack[-3];
    goto v_6328;
v_6330:
    v_6697 = stack[-3];
    v_6697 = qcar(v_6697);
    goto v_6328;
    v_6697 = nil;
v_6328:
    v_6699 = v_6697;
    goto v_6349;
v_6345:
    v_6698 = v_6699;
    goto v_6346;
v_6347:
    v_6697 = elt(env, 1); // true
    goto v_6348;
v_6349:
    goto v_6345;
v_6346:
    goto v_6347;
v_6348:
    if (v_6698 == v_6697) goto v_6343;
    else goto v_6344;
v_6343:
    v_6697 = lisp_true;
    goto v_6342;
v_6344:
    goto v_6359;
v_6355:
    v_6698 = v_6699;
    goto v_6356;
v_6357:
    v_6697 = elt(env, 2); // false
    goto v_6358;
v_6359:
    goto v_6355;
v_6356:
    goto v_6357;
v_6358:
    v_6697 = (v_6698 == v_6697 ? lisp_true : nil);
    goto v_6342;
    v_6697 = nil;
v_6342:
    if (v_6697 == nil) goto v_6340;
    goto v_6368;
v_6364:
    v_6698 = stack[-2];
    goto v_6365;
v_6366:
    v_6697 = stack[0];
    goto v_6367;
v_6368:
    goto v_6364;
v_6365:
    goto v_6366;
v_6367:
    return cons(v_6698, v_6697);
v_6340:
    goto v_6391;
v_6387:
    v_6698 = v_6699;
    goto v_6388;
v_6389:
    v_6697 = elt(env, 3); // or
    goto v_6390;
v_6391:
    goto v_6387;
v_6388:
    goto v_6389;
v_6390:
    if (v_6698 == v_6697) goto v_6385;
    else goto v_6386;
v_6385:
    v_6697 = lisp_true;
    goto v_6384;
v_6386:
    goto v_6401;
v_6397:
    v_6698 = v_6699;
    goto v_6398;
v_6399:
    v_6697 = elt(env, 4); // and
    goto v_6400;
v_6401:
    goto v_6397;
v_6398:
    goto v_6399;
v_6400:
    v_6697 = (v_6698 == v_6697 ? lisp_true : nil);
    goto v_6384;
    v_6697 = nil;
v_6384:
    if (v_6697 == nil) goto v_6382;
    v_6697 = lisp_true;
    goto v_6380;
v_6382:
    goto v_6412;
v_6408:
    v_6698 = v_6699;
    goto v_6409;
v_6410:
    v_6697 = elt(env, 5); // not
    goto v_6411;
v_6412:
    goto v_6408;
v_6409:
    goto v_6410;
v_6411:
    v_6697 = (v_6698 == v_6697 ? lisp_true : nil);
    goto v_6380;
    v_6697 = nil;
v_6380:
    if (v_6697 == nil) goto v_6378;
    v_6697 = lisp_true;
    goto v_6376;
v_6378:
    goto v_6427;
v_6423:
    v_6698 = v_6699;
    goto v_6424;
v_6425:
    v_6697 = elt(env, 6); // impl
    goto v_6426;
v_6427:
    goto v_6423;
v_6424:
    goto v_6425;
v_6426:
    if (v_6698 == v_6697) goto v_6421;
    else goto v_6422;
v_6421:
    v_6697 = lisp_true;
    goto v_6420;
v_6422:
    goto v_6441;
v_6437:
    v_6698 = v_6699;
    goto v_6438;
v_6439:
    v_6697 = elt(env, 7); // repl
    goto v_6440;
v_6441:
    goto v_6437;
v_6438:
    goto v_6439;
v_6440:
    if (v_6698 == v_6697) goto v_6435;
    else goto v_6436;
v_6435:
    v_6697 = lisp_true;
    goto v_6434;
v_6436:
    goto v_6451;
v_6447:
    v_6698 = v_6699;
    goto v_6448;
v_6449:
    v_6697 = elt(env, 8); // equiv
    goto v_6450;
v_6451:
    goto v_6447;
v_6448:
    goto v_6449;
v_6450:
    v_6697 = (v_6698 == v_6697 ? lisp_true : nil);
    goto v_6434;
    v_6697 = nil;
v_6434:
    goto v_6420;
    v_6697 = nil;
v_6420:
    goto v_6376;
    v_6697 = nil;
v_6376:
    if (v_6697 == nil) goto v_6374;
    v_6697 = stack[-3];
    v_6697 = qcdr(v_6697);
    stack[-3] = v_6697;
v_6458:
    v_6697 = stack[-3];
    if (v_6697 == nil) goto v_6463;
    else goto v_6464;
v_6463:
    goto v_6457;
v_6464:
    v_6697 = stack[-3];
    v_6697 = qcar(v_6697);
    goto v_6482;
v_6474:
    v_6700 = v_6697;
    goto v_6475;
v_6476:
    v_6699 = stack[-2];
    goto v_6477;
v_6478:
    v_6698 = stack[-1];
    goto v_6479;
v_6480:
    v_6697 = stack[0];
    goto v_6481;
v_6482:
    goto v_6474;
v_6475:
    goto v_6476;
v_6477:
    goto v_6478;
v_6479:
    goto v_6480;
v_6481:
    v_6697 = CC_cl_varl2(elt(env, 0), 4, v_6700, v_6699, v_6698, v_6697);
    env = stack[-5];
    v_6698 = v_6697;
    v_6697 = v_6698;
    v_6697 = qcar(v_6697);
    stack[-2] = v_6697;
    v_6697 = v_6698;
    v_6697 = qcdr(v_6697);
    stack[0] = v_6697;
    v_6697 = stack[-3];
    v_6697 = qcdr(v_6697);
    stack[-3] = v_6697;
    goto v_6458;
v_6457:
    goto v_6499;
v_6495:
    v_6698 = stack[-2];
    goto v_6496;
v_6497:
    v_6697 = stack[0];
    goto v_6498;
v_6499:
    goto v_6495;
v_6496:
    goto v_6497;
v_6498:
    return cons(v_6698, v_6697);
v_6374:
    goto v_6514;
v_6510:
    v_6698 = v_6699;
    goto v_6511;
v_6512:
    v_6697 = elt(env, 9); // ex
    goto v_6513;
v_6514:
    goto v_6510;
v_6511:
    goto v_6512;
v_6513:
    if (v_6698 == v_6697) goto v_6508;
    else goto v_6509;
v_6508:
    v_6697 = lisp_true;
    goto v_6507;
v_6509:
    goto v_6524;
v_6520:
    v_6698 = v_6699;
    goto v_6521;
v_6522:
    v_6697 = elt(env, 10); // all
    goto v_6523;
v_6524:
    goto v_6520;
v_6521:
    goto v_6522;
v_6523:
    v_6697 = (v_6698 == v_6697 ? lisp_true : nil);
    goto v_6507;
    v_6697 = nil;
v_6507:
    if (v_6697 == nil) goto v_6505;
    goto v_6537;
v_6529:
    v_6697 = stack[-3];
    v_6697 = qcdr(v_6697);
    v_6697 = qcdr(v_6697);
    stack[-4] = qcar(v_6697);
    goto v_6530;
v_6531:
    goto v_6532;
v_6533:
    goto v_6548;
v_6544:
    v_6697 = stack[-3];
    v_6697 = qcdr(v_6697);
    v_6698 = qcar(v_6697);
    goto v_6545;
v_6546:
    v_6697 = stack[-1];
    goto v_6547;
v_6548:
    goto v_6544;
v_6545:
    goto v_6546;
v_6547:
    fn = elt(env, 13); // lto_insertq
    v_6698 = (*qfn2(fn))(fn, v_6698, v_6697);
    env = stack[-5];
    goto v_6534;
v_6535:
    v_6697 = stack[0];
    goto v_6536;
v_6537:
    goto v_6529;
v_6530:
    goto v_6531;
v_6532:
    goto v_6533;
v_6534:
    goto v_6535;
v_6536:
    stack[-3] = stack[-4];
    stack[-1] = v_6698;
    stack[0] = v_6697;
    goto v_6318;
v_6505:
    goto v_6566;
v_6562:
    v_6698 = v_6699;
    goto v_6563;
v_6564:
    v_6697 = elt(env, 11); // bex
    goto v_6565;
v_6566:
    goto v_6562;
v_6563:
    goto v_6564;
v_6565:
    if (v_6698 == v_6697) goto v_6560;
    else goto v_6561;
v_6560:
    v_6697 = lisp_true;
    goto v_6559;
v_6561:
    goto v_6576;
v_6572:
    v_6698 = v_6699;
    goto v_6573;
v_6574:
    v_6697 = elt(env, 12); // ball
    goto v_6575;
v_6576:
    goto v_6572;
v_6573:
    goto v_6574;
v_6575:
    v_6697 = (v_6698 == v_6697 ? lisp_true : nil);
    goto v_6559;
    v_6697 = nil;
v_6559:
    if (v_6697 == nil) goto v_6557;
    goto v_6585;
v_6581:
    v_6697 = stack[-3];
    v_6697 = qcdr(v_6697);
    v_6698 = qcar(v_6697);
    goto v_6582;
v_6583:
    v_6697 = stack[-1];
    goto v_6584;
v_6585:
    goto v_6581;
v_6582:
    goto v_6583;
v_6584:
    fn = elt(env, 13); // lto_insertq
    v_6697 = (*qfn2(fn))(fn, v_6698, v_6697);
    env = stack[-5];
    stack[-1] = v_6697;
    goto v_6602;
v_6594:
    v_6697 = stack[-3];
    v_6697 = qcdr(v_6697);
    v_6697 = qcdr(v_6697);
    v_6697 = qcdr(v_6697);
    v_6700 = qcar(v_6697);
    goto v_6595;
v_6596:
    v_6699 = stack[-2];
    goto v_6597;
v_6598:
    v_6698 = stack[-1];
    goto v_6599;
v_6600:
    v_6697 = stack[0];
    goto v_6601;
v_6602:
    goto v_6594;
v_6595:
    goto v_6596;
v_6597:
    goto v_6598;
v_6599:
    goto v_6600;
v_6601:
    v_6697 = CC_cl_varl2(elt(env, 0), 4, v_6700, v_6699, v_6698, v_6697);
    env = stack[-5];
    v_6698 = v_6697;
    v_6697 = v_6698;
    v_6697 = qcar(v_6697);
    stack[-2] = v_6697;
    v_6697 = v_6698;
    v_6697 = qcdr(v_6697);
    stack[0] = v_6697;
    goto v_6625;
v_6617:
    v_6697 = stack[-3];
    v_6697 = qcdr(v_6697);
    v_6697 = qcdr(v_6697);
    stack[-4] = qcar(v_6697);
    goto v_6618;
v_6619:
    goto v_6620;
v_6621:
    goto v_6636;
v_6632:
    v_6697 = stack[-3];
    v_6697 = qcdr(v_6697);
    v_6698 = qcar(v_6697);
    goto v_6633;
v_6634:
    v_6697 = stack[-1];
    goto v_6635;
v_6636:
    goto v_6632;
v_6633:
    goto v_6634;
v_6635:
    fn = elt(env, 13); // lto_insertq
    v_6698 = (*qfn2(fn))(fn, v_6698, v_6697);
    env = stack[-5];
    goto v_6622;
v_6623:
    v_6697 = stack[0];
    goto v_6624;
v_6625:
    goto v_6617;
v_6618:
    goto v_6619;
v_6620:
    goto v_6621;
v_6622:
    goto v_6623;
v_6624:
    stack[-3] = stack[-4];
    stack[-1] = v_6698;
    stack[0] = v_6697;
    goto v_6318;
v_6557:
    v_6697 = stack[-3];
    fn = elt(env, 14); // rl_varlat
    v_6697 = (*qfn1(fn))(fn, v_6697);
    env = stack[-5];
    stack[-3] = v_6697;
v_6645:
    v_6697 = stack[-3];
    if (v_6697 == nil) goto v_6650;
    else goto v_6651;
v_6650:
    goto v_6644;
v_6651:
    v_6697 = stack[-3];
    v_6697 = qcar(v_6697);
    v_6699 = v_6697;
    goto v_6665;
v_6661:
    v_6698 = v_6699;
    goto v_6662;
v_6663:
    v_6697 = stack[-1];
    goto v_6664;
v_6665:
    goto v_6661;
v_6662:
    goto v_6663;
v_6664:
    v_6697 = Lmemq(nil, v_6698, v_6697);
    if (v_6697 == nil) goto v_6660;
    goto v_6674;
v_6670:
    v_6698 = v_6699;
    goto v_6671;
v_6672:
    v_6697 = stack[0];
    goto v_6673;
v_6674:
    goto v_6670;
v_6671:
    goto v_6672;
v_6673:
    fn = elt(env, 13); // lto_insertq
    v_6697 = (*qfn2(fn))(fn, v_6698, v_6697);
    env = stack[-5];
    stack[0] = v_6697;
    goto v_6658;
v_6660:
    goto v_6684;
v_6680:
    v_6698 = v_6699;
    goto v_6681;
v_6682:
    v_6697 = stack[-2];
    goto v_6683;
v_6684:
    goto v_6680;
v_6681:
    goto v_6682;
v_6683:
    fn = elt(env, 13); // lto_insertq
    v_6697 = (*qfn2(fn))(fn, v_6698, v_6697);
    env = stack[-5];
    stack[-2] = v_6697;
    goto v_6658;
v_6658:
    v_6697 = stack[-3];
    v_6697 = qcdr(v_6697);
    stack[-3] = v_6697;
    goto v_6645;
v_6644:
    goto v_6694;
v_6690:
    v_6698 = stack[-2];
    goto v_6691;
v_6692:
    v_6697 = stack[0];
    goto v_6693;
v_6694:
    goto v_6690;
v_6691:
    goto v_6692;
v_6693:
    return cons(v_6698, v_6697);
    return onevalue(v_6697);
}



// Code for omiir

static LispObject CC_omiir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6328;
    LispObject fn;
    argcheck(nargs, 0, "omiir");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// end of prologue
    fn = elt(env, 2); // lex
    v_6328 = (*qfnn(fn))(fn, 0);
    env = stack[-1];
    v_6328 = qvalue(elt(env, 1)); // char
    v_6328 = Lcompress(nil, v_6328);
    env = stack[-1];
    stack[0] = v_6328;
    fn = elt(env, 2); // lex
    v_6328 = (*qfnn(fn))(fn, 0);
    v_6328 = stack[0];
    return onevalue(v_6328);
}



// Code for c!:extadd

static LispObject CC_cTextadd(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6451, v_6452, v_6453;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_6320;
    stack[-1] = v_6319;
// end of prologue
    stack[-2] = nil;
v_6327:
    v_6451 = stack[-1];
    if (v_6451 == nil) goto v_6331;
    else goto v_6332;
v_6331:
    v_6451 = stack[0];
    v_6452 = v_6451;
    goto v_6328;
v_6332:
    v_6451 = stack[0];
    if (v_6451 == nil) goto v_6335;
    else goto v_6336;
v_6335:
    v_6451 = stack[-1];
    v_6452 = v_6451;
    goto v_6328;
v_6336:
    goto v_6345;
v_6341:
    v_6451 = stack[-1];
    v_6451 = qcar(v_6451);
    v_6452 = qcar(v_6451);
    goto v_6342;
v_6343:
    v_6451 = stack[0];
    v_6451 = qcar(v_6451);
    v_6451 = qcar(v_6451);
    goto v_6344;
v_6345:
    goto v_6341;
v_6342:
    goto v_6343;
v_6344:
    if (equal(v_6452, v_6451)) goto v_6339;
    else goto v_6340;
v_6339:
    goto v_6357;
v_6353:
    v_6451 = stack[-1];
    v_6451 = qcar(v_6451);
    v_6452 = qcdr(v_6451);
    goto v_6354;
v_6355:
    v_6451 = stack[0];
    v_6451 = qcar(v_6451);
    v_6451 = qcdr(v_6451);
    goto v_6356;
v_6357:
    goto v_6353;
v_6354:
    goto v_6355;
v_6356:
    fn = elt(env, 1); // addf
    v_6451 = (*qfn2(fn))(fn, v_6452, v_6451);
    env = stack[-3];
    v_6452 = v_6451;
    if (v_6452 == nil) goto v_6366;
    else goto v_6367;
v_6366:
    v_6451 = stack[-1];
    v_6451 = qcdr(v_6451);
    stack[-1] = v_6451;
    v_6451 = stack[0];
    v_6451 = qcdr(v_6451);
    stack[0] = v_6451;
    goto v_6327;
v_6367:
    goto v_6382;
v_6376:
    v_6452 = stack[-1];
    v_6452 = qcar(v_6452);
    v_6453 = qcar(v_6452);
    goto v_6377;
v_6378:
    v_6452 = v_6451;
    goto v_6379;
v_6380:
    v_6451 = stack[-2];
    goto v_6381;
v_6382:
    goto v_6376;
v_6377:
    goto v_6378;
v_6379:
    goto v_6380;
v_6381:
    v_6451 = acons(v_6453, v_6452, v_6451);
    env = stack[-3];
    stack[-2] = v_6451;
    v_6451 = stack[-1];
    v_6451 = qcdr(v_6451);
    stack[-1] = v_6451;
    v_6451 = stack[0];
    v_6451 = qcdr(v_6451);
    stack[0] = v_6451;
    goto v_6327;
    goto v_6330;
v_6340:
    goto v_6399;
v_6395:
    v_6451 = stack[-1];
    v_6451 = qcar(v_6451);
    v_6452 = qcar(v_6451);
    goto v_6396;
v_6397:
    v_6451 = stack[0];
    v_6451 = qcar(v_6451);
    v_6451 = qcar(v_6451);
    goto v_6398;
v_6399:
    goto v_6395;
v_6396:
    goto v_6397;
v_6398:
    fn = elt(env, 2); // c!:ordexp
    v_6451 = (*qfn2(fn))(fn, v_6452, v_6451);
    env = stack[-3];
    if (v_6451 == nil) goto v_6393;
    goto v_6411;
v_6407:
    v_6451 = stack[-1];
    v_6452 = qcar(v_6451);
    goto v_6408;
v_6409:
    v_6451 = stack[-2];
    goto v_6410;
v_6411:
    goto v_6407;
v_6408:
    goto v_6409;
v_6410:
    v_6451 = cons(v_6452, v_6451);
    env = stack[-3];
    stack[-2] = v_6451;
    v_6451 = stack[-1];
    v_6451 = qcdr(v_6451);
    stack[-1] = v_6451;
    goto v_6327;
v_6393:
    goto v_6424;
v_6420:
    v_6451 = stack[0];
    v_6452 = qcar(v_6451);
    goto v_6421;
v_6422:
    v_6451 = stack[-2];
    goto v_6423;
v_6424:
    goto v_6420;
v_6421:
    goto v_6422;
v_6423:
    v_6451 = cons(v_6452, v_6451);
    env = stack[-3];
    stack[-2] = v_6451;
    v_6451 = stack[0];
    v_6451 = qcdr(v_6451);
    stack[0] = v_6451;
    goto v_6327;
v_6330:
v_6328:
v_6432:
    v_6451 = stack[-2];
    if (v_6451 == nil) goto v_6435;
    else goto v_6436;
v_6435:
    goto v_6431;
v_6436:
    goto v_6444;
v_6440:
    v_6451 = stack[-2];
    v_6451 = qcar(v_6451);
    goto v_6441;
v_6442:
    goto v_6443;
v_6444:
    goto v_6440;
v_6441:
    goto v_6442;
v_6443:
    v_6451 = cons(v_6451, v_6452);
    env = stack[-3];
    v_6452 = v_6451;
    v_6451 = stack[-2];
    v_6451 = qcdr(v_6451);
    stack[-2] = v_6451;
    goto v_6432;
v_6431:
    v_6451 = v_6452;
    return onevalue(v_6451);
}



// Code for comm_kernels1

static LispObject CC_comm_kernels1(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6390, v_6391;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_6320;
    v_6390 = v_6319;
// end of prologue
v_6318:
    v_6391 = v_6390;
    if (!consp(v_6391)) goto v_6328;
    else goto v_6329;
v_6328:
    v_6391 = lisp_true;
    goto v_6327;
v_6329:
    v_6391 = v_6390;
    v_6391 = qcar(v_6391);
    v_6391 = (consp(v_6391) ? nil : lisp_true);
    goto v_6327;
    v_6391 = nil;
v_6327:
    if (v_6391 == nil) goto v_6325;
    v_6390 = stack[-2];
    goto v_6323;
v_6325:
    v_6391 = v_6390;
    v_6391 = qcar(v_6391);
    v_6391 = qcar(v_6391);
    v_6391 = qcar(v_6391);
    stack[-3] = v_6391;
    goto v_6350;
v_6346:
    v_6391 = v_6390;
    v_6391 = qcar(v_6391);
    stack[-1] = qcdr(v_6391);
    goto v_6347;
v_6348:
    goto v_6359;
v_6355:
    stack[0] = qcdr(v_6390);
    goto v_6356;
v_6357:
    goto v_6371;
v_6367:
    v_6391 = stack[-3];
    goto v_6368;
v_6369:
    v_6390 = stack[-2];
    goto v_6370;
v_6371:
    goto v_6367;
v_6368:
    goto v_6369;
v_6370:
    v_6390 = Lmemq(nil, v_6391, v_6390);
    if (v_6390 == nil) goto v_6366;
    else goto v_6364;
v_6366:
    v_6390 = stack[-3];
    fn = elt(env, 1); // noncomp
    v_6390 = (*qfn1(fn))(fn, v_6390);
    env = stack[-4];
    if (v_6390 == nil) goto v_6375;
    else goto v_6364;
v_6375:
    goto v_6365;
v_6364:
    v_6390 = stack[-2];
    goto v_6363;
v_6365:
    goto v_6386;
v_6382:
    goto v_6383;
v_6384:
    v_6390 = stack[-3];
    v_6390 = ncons(v_6390);
    env = stack[-4];
    goto v_6385;
v_6386:
    goto v_6382;
v_6383:
    goto v_6384;
v_6385:
    v_6390 = Lappend(nil, stack[-2], v_6390);
    env = stack[-4];
    goto v_6363;
    v_6390 = nil;
v_6363:
    goto v_6358;
v_6359:
    goto v_6355;
v_6356:
    goto v_6357;
v_6358:
    v_6391 = CC_comm_kernels1(elt(env, 0), stack[0], v_6390);
    env = stack[-4];
    goto v_6349;
v_6350:
    goto v_6346;
v_6347:
    goto v_6348;
v_6349:
    v_6390 = stack[-1];
    stack[-2] = v_6391;
    goto v_6318;
    v_6390 = nil;
v_6323:
    return onevalue(v_6390);
}



// Code for addpf

static LispObject CC_addpf(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6506, v_6507, v_6508;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_6320;
    stack[-2] = v_6319;
// end of prologue
    stack[0] = nil;
v_6325:
    v_6506 = stack[-2];
    if (v_6506 == nil) goto v_6328;
    else goto v_6329;
v_6328:
    goto v_6336;
v_6332:
    v_6507 = stack[0];
    goto v_6333;
v_6334:
    v_6506 = stack[-1];
    goto v_6335;
v_6336:
    goto v_6332;
v_6333:
    goto v_6334;
v_6335:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_6507, v_6506);
    }
v_6329:
    v_6506 = stack[-1];
    if (v_6506 == nil) goto v_6339;
    else goto v_6340;
v_6339:
    goto v_6347;
v_6343:
    v_6507 = stack[0];
    goto v_6344;
v_6345:
    v_6506 = stack[-2];
    goto v_6346;
v_6347:
    goto v_6343;
v_6344:
    goto v_6345;
v_6346:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_6507, v_6506);
    }
v_6340:
    goto v_6356;
v_6352:
    v_6506 = stack[-2];
    v_6506 = qcar(v_6506);
    v_6507 = qcar(v_6506);
    goto v_6353;
v_6354:
    v_6506 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6355;
v_6356:
    goto v_6352;
v_6353:
    goto v_6354;
v_6355:
    if (v_6507 == v_6506) goto v_6350;
    else goto v_6351;
v_6350:
    goto v_6366;
v_6362:
    goto v_6363;
v_6364:
    goto v_6373;
v_6369:
    v_6507 = stack[-2];
    goto v_6370;
v_6371:
    v_6506 = stack[-1];
    goto v_6372;
v_6373:
    goto v_6369;
v_6370:
    goto v_6371;
v_6372:
    fn = elt(env, 2); // addmpf
    v_6506 = (*qfn2(fn))(fn, v_6507, v_6506);
    env = stack[-4];
    goto v_6365;
v_6366:
    goto v_6362;
v_6363:
    goto v_6364;
v_6365:
    {
        LispObject v_6513 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_6513, v_6506);
    }
v_6351:
    goto v_6382;
v_6378:
    v_6506 = stack[-1];
    v_6506 = qcar(v_6506);
    v_6507 = qcar(v_6506);
    goto v_6379;
v_6380:
    v_6506 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6381;
v_6382:
    goto v_6378;
v_6379:
    goto v_6380;
v_6381:
    if (v_6507 == v_6506) goto v_6376;
    else goto v_6377;
v_6376:
    goto v_6392;
v_6388:
    goto v_6389;
v_6390:
    goto v_6399;
v_6395:
    v_6507 = stack[-1];
    goto v_6396;
v_6397:
    v_6506 = stack[-2];
    goto v_6398;
v_6399:
    goto v_6395;
v_6396:
    goto v_6397;
v_6398:
    fn = elt(env, 2); // addmpf
    v_6506 = (*qfn2(fn))(fn, v_6507, v_6506);
    env = stack[-4];
    goto v_6391;
v_6392:
    goto v_6388;
v_6389:
    goto v_6390;
v_6391:
    {
        LispObject v_6514 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_6514, v_6506);
    }
v_6377:
    goto v_6408;
v_6404:
    v_6506 = stack[-2];
    v_6506 = qcar(v_6506);
    v_6507 = qcar(v_6506);
    goto v_6405;
v_6406:
    v_6506 = stack[-1];
    v_6506 = qcar(v_6506);
    v_6506 = qcar(v_6506);
    goto v_6407;
v_6408:
    goto v_6404;
v_6405:
    goto v_6406;
v_6407:
    if (equal(v_6507, v_6506)) goto v_6402;
    else goto v_6403;
v_6402:
    goto v_6420;
v_6416:
    stack[-3] = stack[0];
    goto v_6417;
v_6418:
    goto v_6427;
v_6423:
    v_6506 = stack[-2];
    v_6506 = qcar(v_6506);
    v_6507 = qcdr(v_6506);
    goto v_6424;
v_6425:
    v_6506 = stack[-1];
    v_6506 = qcar(v_6506);
    v_6506 = qcdr(v_6506);
    goto v_6426;
v_6427:
    goto v_6423;
v_6424:
    goto v_6425;
v_6426:
    fn = elt(env, 3); // addsq
    stack[0] = (*qfn2(fn))(fn, v_6507, v_6506);
    env = stack[-4];
    goto v_6439;
v_6435:
    v_6506 = stack[-2];
    v_6507 = qcdr(v_6506);
    goto v_6436;
v_6437:
    v_6506 = stack[-1];
    v_6506 = qcdr(v_6506);
    goto v_6438;
v_6439:
    goto v_6435;
v_6436:
    goto v_6437;
v_6438:
    v_6506 = CC_addpf(elt(env, 0), v_6507, v_6506);
    env = stack[-4];
    v_6507 = stack[0];
    v_6508 = v_6507;
    v_6508 = qcar(v_6508);
    if (v_6508 == nil) goto v_6448;
    else goto v_6449;
v_6448:
    goto v_6447;
v_6449:
    goto v_6462;
v_6456:
    v_6508 = stack[-2];
    v_6508 = qcar(v_6508);
    v_6508 = qcar(v_6508);
    goto v_6457;
v_6458:
    goto v_6459;
v_6460:
    goto v_6461;
v_6462:
    goto v_6456;
v_6457:
    goto v_6458;
v_6459:
    goto v_6460;
v_6461:
    v_6506 = acons(v_6508, v_6507, v_6506);
    env = stack[-4];
    goto v_6447;
    v_6506 = nil;
v_6447:
    goto v_6419;
v_6420:
    goto v_6416;
v_6417:
    goto v_6418;
v_6419:
    {
        LispObject v_6515 = stack[-3];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_6515, v_6506);
    }
v_6403:
    goto v_6475;
v_6471:
    v_6506 = stack[-2];
    v_6506 = qcar(v_6506);
    v_6507 = qcar(v_6506);
    goto v_6472;
v_6473:
    v_6506 = stack[-1];
    v_6506 = qcar(v_6506);
    v_6506 = qcar(v_6506);
    goto v_6474;
v_6475:
    goto v_6471;
v_6472:
    goto v_6473;
v_6474:
    fn = elt(env, 4); // termordp!!
    v_6506 = (*qfn2(fn))(fn, v_6507, v_6506);
    env = stack[-4];
    if (v_6506 == nil) goto v_6469;
    goto v_6487;
v_6483:
    v_6506 = stack[-2];
    v_6507 = qcar(v_6506);
    goto v_6484;
v_6485:
    v_6506 = stack[0];
    goto v_6486;
v_6487:
    goto v_6483;
v_6484:
    goto v_6485;
v_6486:
    v_6506 = cons(v_6507, v_6506);
    env = stack[-4];
    stack[0] = v_6506;
    v_6506 = stack[-2];
    v_6506 = qcdr(v_6506);
    stack[-2] = v_6506;
    goto v_6325;
v_6469:
    goto v_6500;
v_6496:
    v_6506 = stack[-1];
    v_6507 = qcar(v_6506);
    goto v_6497;
v_6498:
    v_6506 = stack[0];
    goto v_6499;
v_6500:
    goto v_6496;
v_6497:
    goto v_6498;
v_6499:
    v_6506 = cons(v_6507, v_6506);
    env = stack[-4];
    stack[0] = v_6506;
    v_6506 = stack[-1];
    v_6506 = qcdr(v_6506);
    stack[-1] = v_6506;
    goto v_6325;
    v_6506 = nil;
    return onevalue(v_6506);
}



// Code for gfrsq

static LispObject CC_gfrsq(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6329, v_6330;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6329 = v_6319;
// end of prologue
    goto v_6326;
v_6322:
    v_6330 = v_6329;
    goto v_6323;
v_6324:
    goto v_6325;
v_6326:
    goto v_6322;
v_6323:
    goto v_6324;
v_6325:
    {
        fn = elt(env, 1); // gfdot
        return (*qfn2(fn))(fn, v_6330, v_6329);
    }
}



// Code for safe!-fp!-times

static LispObject CC_safeKfpKtimes(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6413, v_6414;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_6320;
    stack[-1] = v_6319;
// end of prologue
    goto v_6330;
v_6326:
    v_6414 = stack[-1];
    goto v_6327;
v_6328:
    v_6413 = stack[0];
    goto v_6329;
v_6330:
    goto v_6326;
v_6327:
    goto v_6328;
v_6329:
    v_6413 = times2(v_6414, v_6413);
    env = stack[-3];
    stack[-2] = v_6413;
    goto v_6343;
v_6339:
    v_6414 = stack[-2];
    goto v_6340;
v_6341:
    v_6413 = qvalue(elt(env, 1)); // !!minnorm
    goto v_6342;
v_6343:
    goto v_6339;
v_6340:
    goto v_6341;
v_6342:
    v_6413 = (LispObject)lessp2(v_6414, v_6413);
    v_6413 = v_6413 ? lisp_true : nil;
    env = stack[-3];
    if (v_6413 == nil) goto v_6336;
    goto v_6353;
v_6349:
    v_6414 = stack[-2];
    goto v_6350;
v_6351:
    v_6413 = qvalue(elt(env, 2)); // !!minnegnorm
    goto v_6352;
v_6353:
    goto v_6349;
v_6350:
    goto v_6351;
v_6352:
    v_6413 = (LispObject)greaterp2(v_6414, v_6413);
    v_6413 = v_6413 ? lisp_true : nil;
    env = stack[-3];
    if (v_6413 == nil) goto v_6336;
    goto v_6365;
v_6361:
    v_6414 = stack[-1];
    goto v_6362;
v_6363:
    v_6413 = elt(env, 3); // 0.0
    goto v_6364;
v_6365:
    goto v_6361;
v_6362:
    goto v_6363;
v_6364:
    if (equal(v_6414, v_6413)) goto v_6360;
    goto v_6373;
v_6369:
    v_6414 = stack[0];
    goto v_6370;
v_6371:
    v_6413 = elt(env, 3); // 0.0
    goto v_6372;
v_6373:
    goto v_6369;
v_6370:
    goto v_6371;
v_6372:
    v_6413 = Lneq(nil, v_6414, v_6413);
    env = stack[-3];
    goto v_6358;
v_6360:
    v_6413 = nil;
    goto v_6358;
    v_6413 = nil;
v_6358:
    if (v_6413 == nil) goto v_6336;
    v_6413 = nil;
    goto v_6324;
v_6336:
    v_6413 = qvalue(elt(env, 4)); // !*nonegzerotimes
    if (v_6413 == nil) goto v_6381;
    goto v_6389;
v_6385:
    v_6414 = stack[-2];
    goto v_6386;
v_6387:
    v_6413 = elt(env, 3); // 0.0
    goto v_6388;
v_6389:
    goto v_6385;
v_6386:
    goto v_6387;
v_6388:
    if (equal(v_6414, v_6413)) goto v_6384;
    else goto v_6381;
v_6384:
    v_6413 = elt(env, 3); // 0.0
    goto v_6324;
v_6381:
    goto v_6399;
v_6395:
    goto v_6405;
v_6401:
    v_6414 = stack[-2];
    goto v_6402;
v_6403:
    v_6413 = stack[-2];
    goto v_6404;
v_6405:
    goto v_6401;
v_6402:
    goto v_6403;
v_6404:
    v_6413 = difference2(v_6414, v_6413);
    env = stack[-3];
    goto v_6396;
v_6397:
    v_6414 = elt(env, 3); // 0.0
    goto v_6398;
v_6399:
    goto v_6395;
v_6396:
    goto v_6397;
v_6398:
    if (equal(v_6413, v_6414)) goto v_6393;
    else goto v_6394;
v_6393:
    v_6413 = stack[-2];
    goto v_6324;
v_6394:
    v_6413 = nil;
    goto v_6324;
    v_6413 = nil;
v_6324:
    return onevalue(v_6413);
}



// Code for tokquote

static LispObject CC_tokquote(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6328;
    LispObject fn;
    argcheck(nargs, 0, "tokquote");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
    stack_popper stack_popper_var(1);
// end of prologue
    fn = elt(env, 5); // readch1
    v_6328 = (*qfnn(fn))(fn, 0);
    env = stack[0];
    qvalue(elt(env, 1)) = v_6328; // crchar!*
    fn = elt(env, 6); // rread
    v_6328 = (*qfnn(fn))(fn, 0);
    env = stack[0];
    v_6328 = Lmkquote(nil, v_6328);
    env = stack[0];
    qvalue(elt(env, 2)) = v_6328; // nxtsym!*
    v_6328 = nil;
    qvalue(elt(env, 3)) = v_6328; // curescaped!*
    v_6328 = (LispObject)64+TAG_FIXNUM; // 4
    qvalue(elt(env, 4)) = v_6328; // ttype!*
    v_6328 = qvalue(elt(env, 2)); // nxtsym!*
    return onevalue(v_6328);
}



// Code for argnochk

static LispObject CC_argnochk(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6490, v_6491, v_6492;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_6319;
// end of prologue
    v_6490 = qvalue(elt(env, 1)); // !*argnochk
    if (v_6490 == nil) goto v_6326;
    else goto v_6327;
v_6326:
    v_6490 = stack[-5];
    goto v_6323;
v_6327:
    v_6490 = stack[-5];
    v_6490 = qcar(v_6490);
    fn = elt(env, 11); // argsofopr
    v_6490 = (*qfn1(fn))(fn, v_6490);
    env = stack[-7];
    stack[-6] = v_6490;
    if (v_6490 == nil) goto v_6331;
    goto v_6347;
v_6343:
    stack[0] = stack[-6];
    goto v_6344;
v_6345:
    v_6490 = stack[-5];
    v_6490 = qcdr(v_6490);
    v_6490 = Llength(nil, v_6490);
    env = stack[-7];
    goto v_6346;
v_6347:
    goto v_6343;
v_6344:
    goto v_6345;
v_6346:
    if (equal(stack[0], v_6490)) goto v_6342;
    v_6490 = stack[-5];
    v_6490 = qcar(v_6490);
    if (!symbolp(v_6490)) v_6490 = nil;
    else { v_6490 = qfastgets(v_6490);
           if (v_6490 != nil) { v_6490 = elt(v_6490, 22); // simpfn
#ifdef RECORD_GET
             if (v_6490 != SPID_NOPROP)
                record_get(elt(fastget_names, 22), 1);
             else record_get(elt(fastget_names, 22), 0),
                v_6490 = nil; }
           else record_get(elt(fastget_names, 22), 0); }
#else
             if (v_6490 == SPID_NOPROP) v_6490 = nil; }}
#endif
    if (v_6490 == nil) goto v_6354;
    else goto v_6353;
v_6354:
    v_6490 = stack[-5];
    v_6490 = qcar(v_6490);
    if (!symbolp(v_6490)) v_6490 = nil;
    else { v_6490 = qfastgets(v_6490);
           if (v_6490 != nil) { v_6490 = elt(v_6490, 45); // psopfn
#ifdef RECORD_GET
             if (v_6490 != SPID_NOPROP)
                record_get(elt(fastget_names, 45), 1);
             else record_get(elt(fastget_names, 45), 0),
                v_6490 = nil; }
           else record_get(elt(fastget_names, 45), 0); }
#else
             if (v_6490 == SPID_NOPROP) v_6490 = nil; }}
#endif
    if (v_6490 == nil) goto v_6360;
    else goto v_6359;
v_6360:
    goto v_6369;
v_6365:
    v_6490 = stack[-5];
    v_6491 = qcar(v_6490);
    goto v_6366;
v_6367:
    v_6490 = elt(env, 2); // variadic
    goto v_6368;
v_6369:
    goto v_6365;
v_6366:
    goto v_6367;
v_6368:
    v_6490 = Lflagp(nil, v_6491, v_6490);
    env = stack[-7];
v_6359:
v_6353:
    v_6490 = (v_6490 == nil ? lisp_true : nil);
    goto v_6340;
v_6342:
    v_6490 = nil;
    goto v_6340;
    v_6490 = nil;
v_6340:
    if (v_6490 == nil) goto v_6338;
    v_6490 = qvalue(elt(env, 3)); // !*strict_argcount
    if (v_6490 == nil) goto v_6380;
    v_6490 = elt(env, 4); // "+++++ "
    v_6490 = Lprinc(nil, v_6490);
    env = stack[-7];
    v_6490 = stack[-5];
    v_6490 = Lprint(nil, v_6490);
    env = stack[-7];
    goto v_6393;
v_6387:
    stack[-4] = elt(env, 5); // rlisp
    goto v_6388;
v_6389:
    stack[-3] = (LispObject)176+TAG_FIXNUM; // 11
    goto v_6390;
v_6391:
    goto v_6405;
v_6397:
    v_6490 = stack[-5];
    stack[-2] = qcar(v_6490);
    goto v_6398;
v_6399:
    stack[-1] = elt(env, 6); // "called with"
    goto v_6400;
v_6401:
    v_6490 = stack[-5];
    v_6490 = qcdr(v_6490);
    stack[0] = Llength(nil, v_6490);
    env = stack[-7];
    goto v_6402;
v_6403:
    goto v_6419;
v_6413:
    goto v_6428;
v_6424:
    v_6490 = stack[-5];
    v_6490 = qcdr(v_6490);
    v_6491 = Llength(nil, v_6490);
    env = stack[-7];
    goto v_6425;
v_6426:
    v_6490 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6427;
v_6428:
    goto v_6424;
v_6425:
    goto v_6426;
v_6427:
    if (v_6491 == v_6490) goto v_6422;
    else goto v_6423;
v_6422:
    v_6490 = elt(env, 7); // "argument"
    v_6492 = v_6490;
    goto v_6421;
v_6423:
    v_6490 = elt(env, 8); // "arguments"
    v_6492 = v_6490;
    goto v_6421;
    v_6492 = nil;
v_6421:
    goto v_6414;
v_6415:
    v_6491 = elt(env, 9); // "instead of"
    goto v_6416;
v_6417:
    v_6490 = stack[-6];
    goto v_6418;
v_6419:
    goto v_6413;
v_6414:
    goto v_6415;
v_6416:
    goto v_6417;
v_6418:
    v_6490 = list3(v_6492, v_6491, v_6490);
    env = stack[-7];
    goto v_6404;
v_6405:
    goto v_6397;
v_6398:
    goto v_6399;
v_6400:
    goto v_6401;
v_6402:
    goto v_6403;
v_6404:
    v_6490 = list3star(stack[-2], stack[-1], stack[0], v_6490);
    env = stack[-7];
    goto v_6392;
v_6393:
    goto v_6387;
v_6388:
    goto v_6389;
v_6390:
    goto v_6391;
v_6392:
    fn = elt(env, 12); // rerror
    v_6490 = (*qfnn(fn))(fn, 3, stack[-4], stack[-3], v_6490);
    goto v_6378;
v_6380:
    goto v_6451;
v_6443:
    v_6490 = stack[-5];
    stack[-2] = qcar(v_6490);
    goto v_6444;
v_6445:
    stack[-1] = elt(env, 6); // "called with"
    goto v_6446;
v_6447:
    v_6490 = stack[-5];
    v_6490 = qcdr(v_6490);
    stack[0] = Llength(nil, v_6490);
    env = stack[-7];
    goto v_6448;
v_6449:
    goto v_6465;
v_6459:
    v_6492 = elt(env, 9); // "instead of"
    goto v_6460;
v_6461:
    v_6491 = stack[-6];
    goto v_6462;
v_6463:
    v_6490 = elt(env, 8); // "arguments"
    goto v_6464;
v_6465:
    goto v_6459;
v_6460:
    goto v_6461;
v_6462:
    goto v_6463;
v_6464:
    v_6490 = list3(v_6492, v_6491, v_6490);
    env = stack[-7];
    goto v_6450;
v_6451:
    goto v_6443;
v_6444:
    goto v_6445;
v_6446:
    goto v_6447;
v_6448:
    goto v_6449;
v_6450:
    v_6490 = list3star(stack[-2], stack[-1], stack[0], v_6490);
    env = stack[-7];
    fn = elt(env, 13); // lprim
    v_6490 = (*qfn1(fn))(fn, v_6490);
    v_6490 = stack[-5];
    goto v_6323;
v_6378:
    goto v_6336;
v_6338:
    v_6490 = stack[-5];
    goto v_6323;
v_6336:
    goto v_6325;
v_6331:
    goto v_6482;
v_6476:
    v_6490 = stack[-5];
    stack[-1] = qcar(v_6490);
    goto v_6477;
v_6478:
    stack[0] = elt(env, 10); // number!-of!-args
    goto v_6479;
v_6480:
    v_6490 = stack[-5];
    v_6490 = qcdr(v_6490);
    v_6490 = Llength(nil, v_6490);
    env = stack[-7];
    goto v_6481;
v_6482:
    goto v_6476;
v_6477:
    goto v_6478;
v_6479:
    goto v_6480;
v_6481:
    v_6490 = Lputprop(nil, 3, stack[-1], stack[0], v_6490);
    v_6490 = stack[-5];
    goto v_6323;
v_6325:
    v_6490 = nil;
v_6323:
    return onevalue(v_6490);
}



// Code for make!-term

static LispObject CC_makeKterm(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6535, v_6536, v_6537;
    LispObject fn;
    LispObject v_6321, v_6320, v_6319;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "make-term");
    va_start(aa, nargs);
    v_6319 = va_arg(aa, LispObject);
    v_6320 = va_arg(aa, LispObject);
    v_6321 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_6321,v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_6319,v_6320,v_6321);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_6321;
    stack[-4] = v_6320;
    stack[-5] = v_6319;
// end of prologue
    v_6535 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_6535;
    v_6535 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_6535;
v_6328:
    goto v_6340;
v_6336:
    goto v_6345;
v_6341:
    v_6536 = stack[-4];
    goto v_6342;
v_6343:
    v_6535 = stack[0];
    goto v_6344;
v_6345:
    goto v_6341;
v_6342:
    goto v_6343;
v_6344:
    v_6536 = *(LispObject *)((char *)v_6536 + (CELL-TAG_VECTOR) + (((intptr_t)v_6535-TAG_FIXNUM)/(16/CELL)));
    goto v_6337;
v_6338:
    v_6535 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6339;
v_6340:
    goto v_6336;
v_6337:
    goto v_6338;
v_6339:
    v_6535 = (LispObject)lessp2(v_6536, v_6535);
    v_6535 = v_6535 ? lisp_true : nil;
    env = stack[-7];
    if (v_6535 == nil) goto v_6334;
    v_6535 = (LispObject)-16+TAG_FIXNUM; // -1
    stack[-2] = v_6535;
    goto v_6332;
v_6334:
    goto v_6358;
v_6354:
    goto v_6363;
v_6359:
    v_6536 = stack[-4];
    goto v_6360;
v_6361:
    v_6535 = stack[0];
    goto v_6362;
v_6363:
    goto v_6359;
v_6360:
    goto v_6361;
v_6362:
    v_6536 = *(LispObject *)((char *)v_6536 + (CELL-TAG_VECTOR) + (((intptr_t)v_6535-TAG_FIXNUM)/(16/CELL)));
    goto v_6355;
v_6356:
    v_6535 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6357;
v_6358:
    goto v_6354;
v_6355:
    goto v_6356;
v_6357:
    v_6535 = (LispObject)greaterp2(v_6536, v_6535);
    v_6535 = v_6535 ? lisp_true : nil;
    env = stack[-7];
    if (v_6535 == nil) goto v_6352;
    v_6535 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_6535;
    goto v_6332;
v_6352:
    goto v_6375;
v_6371:
    v_6536 = stack[0];
    goto v_6372;
v_6373:
    v_6535 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_6374;
v_6375:
    goto v_6371;
v_6372:
    goto v_6373;
v_6374:
    if (v_6536 == v_6535) goto v_6369;
    else goto v_6370;
v_6369:
    goto v_6386;
v_6382:
    v_6536 = stack[-5];
    goto v_6383;
v_6384:
    v_6535 = elt(env, 1); // sin
    goto v_6385;
v_6386:
    goto v_6382;
v_6383:
    goto v_6384;
v_6385:
    if (v_6536 == v_6535) goto v_6380;
    else goto v_6381;
v_6380:
    v_6535 = nil;
    goto v_6327;
v_6381:
    goto v_6332;
v_6370:
    v_6535 = stack[0];
    v_6535 = (LispObject)((intptr_t)(v_6535) + 0x10);
    stack[0] = v_6535;
    goto v_6328;
v_6332:
    v_6535 = (LispObject)48+TAG_FIXNUM; // 3
    v_6535 = Lmkvect(nil, v_6535);
    env = stack[-7];
    stack[-6] = v_6535;
    goto v_6408;
v_6404:
    v_6536 = stack[-2];
    goto v_6405;
v_6406:
    v_6535 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6407;
v_6408:
    goto v_6404;
v_6405:
    goto v_6406;
v_6407:
    if (v_6536 == v_6535) goto v_6402;
    else goto v_6403;
v_6402:
    v_6535 = lisp_true;
    goto v_6401;
v_6403:
    goto v_6418;
v_6414:
    v_6536 = stack[-5];
    goto v_6415;
v_6416:
    v_6535 = elt(env, 2); // cos
    goto v_6417;
v_6418:
    goto v_6414;
v_6415:
    goto v_6416;
v_6417:
    v_6535 = (v_6536 == v_6535 ? lisp_true : nil);
    goto v_6401;
    v_6535 = nil;
v_6401:
    if (v_6535 == nil) goto v_6399;
    goto v_6428;
v_6422:
    v_6537 = stack[-6];
    goto v_6423;
v_6424:
    v_6536 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6425;
v_6426:
    v_6535 = stack[-3];
    goto v_6427;
v_6428:
    goto v_6422;
v_6423:
    goto v_6424;
v_6425:
    goto v_6426;
v_6427:
    *(LispObject *)((char *)v_6537 + (CELL-TAG_VECTOR) + (((intptr_t)v_6536-TAG_FIXNUM)/(16/CELL))) = v_6535;
    goto v_6397;
v_6399:
    goto v_6440;
v_6434:
    stack[-1] = stack[-6];
    goto v_6435;
v_6436:
    stack[0] = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6437;
v_6438:
    goto v_6448;
v_6444:
    v_6536 = elt(env, 3); // (-1 . 1)
    goto v_6445;
v_6446:
    v_6535 = stack[-3];
    goto v_6447;
v_6448:
    goto v_6444;
v_6445:
    goto v_6446;
v_6447:
    fn = elt(env, 4); // multsq
    v_6535 = (*qfn2(fn))(fn, v_6536, v_6535);
    env = stack[-7];
    goto v_6439;
v_6440:
    goto v_6434;
v_6435:
    goto v_6436;
v_6437:
    goto v_6438;
v_6439:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_6535;
    goto v_6397;
v_6397:
    goto v_6457;
v_6451:
    v_6537 = stack[-6];
    goto v_6452;
v_6453:
    v_6536 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6454;
v_6455:
    v_6535 = stack[-5];
    goto v_6456;
v_6457:
    goto v_6451;
v_6452:
    goto v_6453;
v_6454:
    goto v_6455;
v_6456:
    *(LispObject *)((char *)v_6537 + (CELL-TAG_VECTOR) + (((intptr_t)v_6536-TAG_FIXNUM)/(16/CELL))) = v_6535;
    goto v_6469;
v_6465:
    v_6536 = stack[-2];
    goto v_6466;
v_6467:
    v_6535 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_6468;
v_6469:
    goto v_6465;
v_6466:
    goto v_6467;
v_6468:
    if (v_6536 == v_6535) goto v_6463;
    else goto v_6464;
v_6463:
    v_6535 = (LispObject)112+TAG_FIXNUM; // 7
    v_6535 = Lmkvect(nil, v_6535);
    env = stack[-7];
    stack[-2] = v_6535;
    v_6535 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_6535;
v_6477:
    goto v_6489;
v_6485:
    v_6536 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_6486;
v_6487:
    v_6535 = stack[-3];
    goto v_6488;
v_6489:
    goto v_6485;
v_6486:
    goto v_6487;
v_6488:
    v_6535 = difference2(v_6536, v_6535);
    env = stack[-7];
    v_6535 = Lminusp(nil, v_6535);
    env = stack[-7];
    if (v_6535 == nil) goto v_6482;
    goto v_6476;
v_6482:
    goto v_6499;
v_6493:
    stack[-1] = stack[-2];
    goto v_6494;
v_6495:
    stack[0] = stack[-3];
    goto v_6496;
v_6497:
    goto v_6507;
v_6503:
    v_6536 = stack[-4];
    goto v_6504;
v_6505:
    v_6535 = stack[-3];
    goto v_6506;
v_6507:
    goto v_6503;
v_6504:
    goto v_6505;
v_6506:
    v_6535 = *(LispObject *)((char *)v_6536 + (CELL-TAG_VECTOR) + (((intptr_t)v_6535-TAG_FIXNUM)/(16/CELL)));
    v_6535 = negate(v_6535);
    env = stack[-7];
    goto v_6498;
v_6499:
    goto v_6493;
v_6494:
    goto v_6495;
v_6496:
    goto v_6497;
v_6498:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_6535;
    v_6535 = stack[-3];
    v_6535 = add1(v_6535);
    env = stack[-7];
    stack[-3] = v_6535;
    goto v_6477;
v_6476:
    v_6535 = stack[-2];
    stack[-4] = v_6535;
    goto v_6462;
v_6464:
v_6462:
    goto v_6520;
v_6514:
    v_6537 = stack[-6];
    goto v_6515;
v_6516:
    v_6536 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_6517;
v_6518:
    v_6535 = stack[-4];
    goto v_6519;
v_6520:
    goto v_6514;
v_6515:
    goto v_6516;
v_6517:
    goto v_6518;
v_6519:
    *(LispObject *)((char *)v_6537 + (CELL-TAG_VECTOR) + (((intptr_t)v_6536-TAG_FIXNUM)/(16/CELL))) = v_6535;
    goto v_6530;
v_6524:
    v_6537 = stack[-6];
    goto v_6525;
v_6526:
    v_6536 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_6527;
v_6528:
    v_6535 = nil;
    goto v_6529;
v_6530:
    goto v_6524;
v_6525:
    goto v_6526;
v_6527:
    goto v_6528;
v_6529:
    *(LispObject *)((char *)v_6537 + (CELL-TAG_VECTOR) + (((intptr_t)v_6536-TAG_FIXNUM)/(16/CELL))) = v_6535;
    v_6535 = stack[-6];
v_6327:
    return onevalue(v_6535);
}



// Code for red_divtest

static LispObject CC_red_divtest(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6350, v_6351;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_6320;
    stack[-1] = v_6319;
// end of prologue
v_6324:
    v_6350 = stack[-1];
    if (v_6350 == nil) goto v_6327;
    else goto v_6328;
v_6327:
    v_6350 = nil;
    goto v_6323;
v_6328:
    goto v_6338;
v_6334:
    v_6350 = stack[-1];
    v_6350 = qcar(v_6350);
    fn = elt(env, 1); // bas_dpoly
    v_6350 = (*qfn1(fn))(fn, v_6350);
    env = stack[-2];
    fn = elt(env, 2); // dp_lmon
    v_6351 = (*qfn1(fn))(fn, v_6350);
    env = stack[-2];
    goto v_6335;
v_6336:
    v_6350 = stack[0];
    goto v_6337;
v_6338:
    goto v_6334;
v_6335:
    goto v_6336;
v_6337:
    fn = elt(env, 3); // mo_vdivides!?
    v_6350 = (*qfn2(fn))(fn, v_6351, v_6350);
    env = stack[-2];
    if (v_6350 == nil) goto v_6332;
    v_6350 = stack[-1];
    v_6350 = qcar(v_6350);
    goto v_6323;
v_6332:
    v_6350 = stack[-1];
    v_6350 = qcdr(v_6350);
    stack[-1] = v_6350;
    goto v_6324;
    v_6350 = nil;
v_6323:
    return onevalue(v_6350);
}



// Code for ordn

static LispObject CC_ordn(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6361, v_6362;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_6362 = v_6319;
// end of prologue
    v_6361 = v_6362;
    if (v_6361 == nil) goto v_6323;
    else goto v_6324;
v_6323:
    v_6361 = nil;
    goto v_6322;
v_6324:
    v_6361 = v_6362;
    v_6361 = qcdr(v_6361);
    if (v_6361 == nil) goto v_6327;
    else goto v_6328;
v_6327:
    v_6361 = v_6362;
    goto v_6322;
v_6328:
    v_6361 = v_6362;
    v_6361 = qcdr(v_6361);
    v_6361 = qcdr(v_6361);
    if (v_6361 == nil) goto v_6332;
    else goto v_6333;
v_6332:
    goto v_6342;
v_6338:
    v_6361 = v_6362;
    v_6361 = qcar(v_6361);
    goto v_6339;
v_6340:
    v_6362 = qcdr(v_6362);
    v_6362 = qcar(v_6362);
    goto v_6341;
v_6342:
    goto v_6338;
v_6339:
    goto v_6340;
v_6341:
    {
        fn = elt(env, 1); // ord2
        return (*qfn2(fn))(fn, v_6361, v_6362);
    }
v_6333:
    goto v_6355;
v_6351:
    v_6361 = v_6362;
    stack[0] = qcar(v_6361);
    goto v_6352;
v_6353:
    v_6361 = v_6362;
    v_6361 = qcdr(v_6361);
    v_6361 = CC_ordn(elt(env, 0), v_6361);
    env = stack[-1];
    goto v_6354;
v_6355:
    goto v_6351;
v_6352:
    goto v_6353;
v_6354:
    {
        LispObject v_6364 = stack[0];
        fn = elt(env, 2); // ordad
        return (*qfn2(fn))(fn, v_6364, v_6361);
    }
    v_6361 = nil;
v_6322:
    return onevalue(v_6361);
}



// Code for rnminus!:

static LispObject CC_rnminusT(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6338, v_6339;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_6319;
// end of prologue
    goto v_6328;
v_6322:
    v_6338 = stack[0];
    stack[-1] = qcar(v_6338);
    goto v_6323;
v_6324:
    v_6338 = stack[0];
    v_6338 = qcdr(v_6338);
    v_6338 = qcar(v_6338);
    fn = elt(env, 1); // !:minus
    v_6339 = (*qfn1(fn))(fn, v_6338);
    goto v_6325;
v_6326:
    v_6338 = stack[0];
    v_6338 = qcdr(v_6338);
    v_6338 = qcdr(v_6338);
    goto v_6327;
v_6328:
    goto v_6322;
v_6323:
    goto v_6324;
v_6325:
    goto v_6326;
v_6327:
    {
        LispObject v_6342 = stack[-1];
        return list2star(v_6342, v_6339, v_6338);
    }
}



// Code for horner!-rule

static LispObject CC_hornerKrule(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6526, v_6527, v_6528, v_6529;
    LispObject fn;
    LispObject v_6322, v_6321, v_6320, v_6319;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "horner-rule");
    va_start(aa, nargs);
    v_6319 = va_arg(aa, LispObject);
    v_6320 = va_arg(aa, LispObject);
    v_6321 = va_arg(aa, LispObject);
    v_6322 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_6322,v_6321,v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_6319,v_6320,v_6321,v_6322);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_6322;
    stack[-2] = v_6321;
    stack[-3] = v_6320;
    stack[-4] = v_6319;
// end of prologue
v_6318:
    v_6526 = stack[-2];
    if (!consp(v_6526)) goto v_6330;
    else goto v_6331;
v_6330:
    v_6526 = lisp_true;
    goto v_6329;
v_6331:
    v_6526 = stack[-2];
    v_6526 = qcar(v_6526);
    v_6526 = (consp(v_6526) ? nil : lisp_true);
    goto v_6329;
    v_6526 = nil;
v_6329:
    if (v_6526 == nil) goto v_6327;
    v_6526 = stack[-1];
    v_6526 = qcar(v_6526);
    v_6526 = qcdr(v_6526);
    v_6526 = (LispObject)zerop(v_6526);
    v_6526 = v_6526 ? lisp_true : nil;
    env = stack[-6];
    if (v_6526 == nil) goto v_6342;
    v_6526 = stack[-2];
    {
        fn = elt(env, 1); // !*d2n
        return (*qfn1(fn))(fn, v_6526);
    }
v_6342:
    goto v_6356;
v_6352:
    v_6526 = stack[-2];
    fn = elt(env, 1); // !*d2n
    stack[0] = (*qfn1(fn))(fn, v_6526);
    env = stack[-6];
    goto v_6353;
v_6354:
    goto v_6364;
v_6360:
    stack[-2] = stack[-4];
    goto v_6361;
v_6362:
    goto v_6371;
v_6367:
    v_6526 = stack[-1];
    v_6526 = qcar(v_6526);
    v_6527 = qcdr(v_6526);
    goto v_6368;
v_6369:
    v_6526 = stack[-3];
    goto v_6370;
v_6371:
    goto v_6367;
v_6368:
    goto v_6369;
v_6370:
    v_6526 = Lexpt(nil, v_6527, v_6526);
    env = stack[-6];
    goto v_6363;
v_6364:
    goto v_6360;
v_6361:
    goto v_6362;
v_6363:
    v_6526 = times2(stack[-2], v_6526);
    goto v_6355;
v_6356:
    goto v_6352;
v_6353:
    goto v_6354;
v_6355:
    {
        LispObject v_6536 = stack[0];
        return plus2(v_6536, v_6526);
    }
    v_6526 = nil;
    goto v_6325;
v_6327:
    goto v_6382;
v_6378:
    v_6526 = stack[-2];
    v_6526 = qcar(v_6526);
    v_6526 = qcar(v_6526);
    v_6527 = qcar(v_6526);
    goto v_6379;
v_6380:
    v_6526 = stack[-1];
    v_6526 = qcar(v_6526);
    v_6526 = qcar(v_6526);
    goto v_6381;
v_6382:
    goto v_6378;
v_6379:
    goto v_6380;
v_6381:
    if (equal(v_6527, v_6526)) goto v_6377;
    v_6526 = stack[-1];
    v_6526 = qcar(v_6526);
    v_6526 = qcdr(v_6526);
    v_6526 = (LispObject)zerop(v_6526);
    v_6526 = v_6526 ? lisp_true : nil;
    env = stack[-6];
    if (v_6526 == nil) goto v_6393;
    goto v_6403;
v_6399:
    v_6527 = stack[-2];
    goto v_6400;
v_6401:
    v_6526 = stack[-1];
    v_6526 = qcdr(v_6526);
    goto v_6402;
v_6403:
    goto v_6399;
v_6400:
    goto v_6401;
v_6402:
    {
        fn = elt(env, 2); // evaluate!-in!-order
        return (*qfn2(fn))(fn, v_6527, v_6526);
    }
v_6393:
    goto v_6414;
v_6410:
    goto v_6420;
v_6416:
    v_6527 = stack[-2];
    goto v_6417;
v_6418:
    v_6526 = stack[-1];
    v_6526 = qcdr(v_6526);
    goto v_6419;
v_6420:
    goto v_6416;
v_6417:
    goto v_6418;
v_6419:
    fn = elt(env, 2); // evaluate!-in!-order
    stack[0] = (*qfn2(fn))(fn, v_6527, v_6526);
    env = stack[-6];
    goto v_6411;
v_6412:
    goto v_6429;
v_6425:
    stack[-2] = stack[-4];
    goto v_6426;
v_6427:
    goto v_6436;
v_6432:
    v_6526 = stack[-1];
    v_6526 = qcar(v_6526);
    v_6527 = qcdr(v_6526);
    goto v_6433;
v_6434:
    v_6526 = stack[-3];
    goto v_6435;
v_6436:
    goto v_6432;
v_6433:
    goto v_6434;
v_6435:
    v_6526 = Lexpt(nil, v_6527, v_6526);
    env = stack[-6];
    goto v_6428;
v_6429:
    goto v_6425;
v_6426:
    goto v_6427;
v_6428:
    v_6526 = times2(stack[-2], v_6526);
    goto v_6413;
v_6414:
    goto v_6410;
v_6411:
    goto v_6412;
v_6413:
    {
        LispObject v_6537 = stack[0];
        return plus2(v_6537, v_6526);
    }
    v_6526 = nil;
    goto v_6325;
v_6377:
    v_6526 = stack[-2];
    v_6526 = qcar(v_6526);
    v_6526 = qcar(v_6526);
    v_6526 = qcdr(v_6526);
    stack[-5] = v_6526;
    goto v_6459;
v_6451:
    v_6526 = stack[-1];
    v_6526 = qcar(v_6526);
    v_6526 = qcdr(v_6526);
    v_6526 = (LispObject)zerop(v_6526);
    v_6526 = v_6526 ? lisp_true : nil;
    env = stack[-6];
    if (v_6526 == nil) goto v_6463;
    goto v_6473;
v_6469:
    v_6526 = stack[-2];
    v_6526 = qcar(v_6526);
    v_6527 = qcdr(v_6526);
    goto v_6470;
v_6471:
    v_6526 = stack[-1];
    v_6526 = qcdr(v_6526);
    goto v_6472;
v_6473:
    goto v_6469;
v_6470:
    goto v_6471;
v_6472:
    fn = elt(env, 2); // evaluate!-in!-order
    v_6526 = (*qfn2(fn))(fn, v_6527, v_6526);
    env = stack[-6];
    v_6529 = v_6526;
    goto v_6461;
v_6463:
    goto v_6486;
v_6482:
    goto v_6492;
v_6488:
    v_6526 = stack[-2];
    v_6526 = qcar(v_6526);
    v_6527 = qcdr(v_6526);
    goto v_6489;
v_6490:
    v_6526 = stack[-1];
    v_6526 = qcdr(v_6526);
    goto v_6491;
v_6492:
    goto v_6488;
v_6489:
    goto v_6490;
v_6491:
    fn = elt(env, 2); // evaluate!-in!-order
    stack[0] = (*qfn2(fn))(fn, v_6527, v_6526);
    env = stack[-6];
    goto v_6483;
v_6484:
    goto v_6503;
v_6499:
    goto v_6500;
v_6501:
    goto v_6510;
v_6506:
    v_6526 = stack[-1];
    v_6526 = qcar(v_6526);
    v_6528 = qcdr(v_6526);
    goto v_6507;
v_6508:
    goto v_6518;
v_6514:
    v_6527 = stack[-3];
    goto v_6515;
v_6516:
    v_6526 = stack[-5];
    goto v_6517;
v_6518:
    goto v_6514;
v_6515:
    goto v_6516;
v_6517:
    v_6526 = (LispObject)(intptr_t)((intptr_t)v_6527 - (intptr_t)v_6526 + TAG_FIXNUM);
    goto v_6509;
v_6510:
    goto v_6506;
v_6507:
    goto v_6508;
v_6509:
    v_6526 = Lexpt(nil, v_6528, v_6526);
    env = stack[-6];
    goto v_6502;
v_6503:
    goto v_6499;
v_6500:
    goto v_6501;
v_6502:
    v_6526 = times2(stack[-4], v_6526);
    env = stack[-6];
    goto v_6485;
v_6486:
    goto v_6482;
v_6483:
    goto v_6484;
v_6485:
    v_6526 = plus2(stack[0], v_6526);
    env = stack[-6];
    v_6529 = v_6526;
    goto v_6461;
    v_6529 = nil;
v_6461:
    goto v_6452;
v_6453:
    v_6528 = stack[-5];
    goto v_6454;
v_6455:
    v_6526 = stack[-2];
    v_6527 = qcdr(v_6526);
    goto v_6456;
v_6457:
    v_6526 = stack[-1];
    goto v_6458;
v_6459:
    goto v_6451;
v_6452:
    goto v_6453;
v_6454:
    goto v_6455;
v_6456:
    goto v_6457;
v_6458:
    stack[-4] = v_6529;
    stack[-3] = v_6528;
    stack[-2] = v_6527;
    stack[-1] = v_6526;
    goto v_6318;
    goto v_6325;
    v_6526 = nil;
v_6325:
    return onevalue(v_6526);
}



// Code for freeofl

static LispObject CC_freeofl(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6355, v_6356;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_6320;
    stack[-1] = v_6319;
// end of prologue
v_6318:
    v_6355 = stack[0];
    if (v_6355 == nil) goto v_6324;
    else goto v_6325;
v_6324:
    v_6355 = lisp_true;
    goto v_6323;
v_6325:
    goto v_6339;
v_6335:
    v_6356 = stack[-1];
    goto v_6336;
v_6337:
    v_6355 = stack[0];
    v_6355 = qcar(v_6355);
    goto v_6338;
v_6339:
    goto v_6335;
v_6336:
    goto v_6337;
v_6338:
    fn = elt(env, 1); // freeof
    v_6355 = (*qfn2(fn))(fn, v_6356, v_6355);
    env = stack[-2];
    if (v_6355 == nil) goto v_6332;
    else goto v_6333;
v_6332:
    v_6355 = nil;
    goto v_6331;
v_6333:
    goto v_6351;
v_6347:
    v_6356 = stack[-1];
    goto v_6348;
v_6349:
    v_6355 = stack[0];
    v_6355 = qcdr(v_6355);
    goto v_6350;
v_6351:
    goto v_6347;
v_6348:
    goto v_6349;
v_6350:
    stack[-1] = v_6356;
    stack[0] = v_6355;
    goto v_6318;
    v_6355 = nil;
v_6331:
    goto v_6323;
    v_6355 = nil;
v_6323:
    return onevalue(v_6355);
}



// Code for lalr_make_compressed_action_row

static LispObject CC_lalr_make_compressed_action_row(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6337, v_6338;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_6319;
// end of prologue
    v_6337 = stack[0];
    fn = elt(env, 1); // lalr_list_of_actions
    v_6337 = (*qfn1(fn))(fn, v_6337);
    env = stack[-1];
    goto v_6331;
v_6327:
    v_6338 = v_6337;
    goto v_6328;
v_6329:
    v_6337 = stack[0];
    v_6337 = qcdr(v_6337);
    goto v_6330;
v_6331:
    goto v_6327;
v_6328:
    goto v_6329;
v_6330:
    fn = elt(env, 2); // lalr_resolve_conflicts
    v_6337 = (*qfn2(fn))(fn, v_6338, v_6337);
    env = stack[-1];
    {
        fn = elt(env, 3); // lalr_make_compressed_action_row1
        return (*qfn1(fn))(fn, v_6337);
    }
    return onevalue(v_6337);
}



// Code for get_rep_matrix_in

static LispObject CC_get_rep_matrix_in(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6387, v_6388;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_6388 = v_6320;
    stack[-2] = v_6319;
// end of prologue
    stack[-1] = nil;
    v_6387 = nil;
    stack[-3] = v_6387;
    v_6387 = v_6388;
    v_6387 = qcdr(v_6387);
    stack[0] = v_6387;
v_6332:
    v_6387 = stack[-3];
    if (v_6387 == nil) goto v_6339;
    else goto v_6340;
v_6339:
    goto v_6347;
v_6343:
    v_6387 = stack[0];
    v_6388 = Llength(nil, v_6387);
    env = stack[-4];
    goto v_6344;
v_6345:
    v_6387 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6346;
v_6347:
    goto v_6343;
v_6344:
    goto v_6345;
v_6346:
    v_6387 = (LispObject)greaterp2(v_6388, v_6387);
    v_6387 = v_6387 ? lisp_true : nil;
    env = stack[-4];
    goto v_6338;
v_6340:
    v_6387 = nil;
    goto v_6338;
    v_6387 = nil;
v_6338:
    if (v_6387 == nil) goto v_6335;
    else goto v_6336;
v_6335:
    goto v_6331;
v_6336:
    goto v_6363;
v_6359:
    v_6387 = stack[0];
    v_6387 = qcar(v_6387);
    v_6388 = qcar(v_6387);
    goto v_6360;
v_6361:
    v_6387 = stack[-2];
    goto v_6362;
v_6363:
    goto v_6359;
v_6360:
    goto v_6361;
v_6362:
    if (equal(v_6388, v_6387)) goto v_6357;
    else goto v_6358;
v_6357:
    v_6387 = stack[0];
    v_6387 = qcar(v_6387);
    v_6387 = qcdr(v_6387);
    v_6387 = qcar(v_6387);
    stack[-1] = v_6387;
    v_6387 = lisp_true;
    stack[-3] = v_6387;
    goto v_6356;
v_6358:
v_6356:
    v_6387 = stack[0];
    v_6387 = qcdr(v_6387);
    stack[0] = v_6387;
    goto v_6332;
v_6331:
    v_6387 = stack[-3];
    if (v_6387 == nil) goto v_6380;
    v_6387 = stack[-1];
    goto v_6326;
v_6380:
    v_6387 = elt(env, 1); // "error in get representation matrix"
    fn = elt(env, 2); // rederr
    v_6387 = (*qfn1(fn))(fn, v_6387);
    goto v_6378;
v_6378:
    v_6387 = nil;
v_6326:
    return onevalue(v_6387);
}



// Code for cl_fvarl

static LispObject CC_cl_fvarl(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6330, v_6331;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_6330 = v_6319;
// end of prologue
    goto v_6326;
v_6322:
    fn = elt(env, 2); // cl_fvarl1
    v_6331 = (*qfn1(fn))(fn, v_6330);
    env = stack[0];
    goto v_6323;
v_6324:
    v_6330 = elt(env, 1); // ordp
    goto v_6325;
v_6326:
    goto v_6322;
v_6323:
    goto v_6324;
v_6325:
    {
        fn = elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_6331, v_6330);
    }
}



// Code for qqe_ofsf_varlterm

static LispObject CC_qqe_ofsf_varlterm(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6390, v_6391, v_6392, v_6393;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_6392 = v_6320;
    v_6393 = v_6319;
// end of prologue
    v_6390 = v_6393;
    if (!consp(v_6390)) goto v_6330;
    else goto v_6331;
v_6330:
    v_6390 = v_6393;
    if (symbolp(v_6390)) goto v_6336;
    v_6390 = nil;
    goto v_6334;
v_6336:
    goto v_6345;
v_6341:
    v_6391 = v_6393;
    goto v_6342;
v_6343:
    v_6390 = elt(env, 1); // qepsilon
    goto v_6344;
v_6345:
    goto v_6341;
v_6342:
    goto v_6343;
v_6344:
    v_6390 = (v_6391 == v_6390 ? lisp_true : nil);
    v_6390 = (v_6390 == nil ? lisp_true : nil);
    goto v_6334;
    v_6390 = nil;
v_6334:
    goto v_6329;
v_6331:
    v_6390 = nil;
    goto v_6329;
    v_6390 = nil;
v_6329:
    if (v_6390 == nil) goto v_6327;
    goto v_6358;
v_6354:
    v_6390 = v_6393;
    goto v_6355;
v_6356:
    v_6391 = v_6392;
    goto v_6357;
v_6358:
    goto v_6354;
v_6355:
    goto v_6356;
v_6357:
    fn = elt(env, 2); // lto_insertq
    v_6390 = (*qfn2(fn))(fn, v_6390, v_6391);
    v_6392 = v_6390;
    goto v_6325;
v_6327:
    v_6390 = v_6393;
    if (!consp(v_6390)) goto v_6362;
    v_6390 = v_6393;
    v_6390 = qcdr(v_6390);
    stack[0] = v_6390;
v_6367:
    v_6390 = stack[0];
    if (v_6390 == nil) goto v_6372;
    else goto v_6373;
v_6372:
    goto v_6366;
v_6373:
    v_6390 = stack[0];
    v_6390 = qcar(v_6390);
    goto v_6384;
v_6380:
    goto v_6381;
v_6382:
    v_6391 = v_6392;
    goto v_6383;
v_6384:
    goto v_6380;
v_6381:
    goto v_6382;
v_6383:
    v_6390 = CC_qqe_ofsf_varlterm(elt(env, 0), v_6390, v_6391);
    env = stack[-1];
    v_6392 = v_6390;
    v_6390 = stack[0];
    v_6390 = qcdr(v_6390);
    stack[0] = v_6390;
    goto v_6367;
v_6366:
    goto v_6325;
v_6362:
v_6325:
    v_6390 = v_6392;
    return onevalue(v_6390);
}



// Code for omvir

static LispObject CC_omvir(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6372, v_6373;
    LispObject fn;
    argcheck(nargs, 0, "omvir");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// end of prologue
    goto v_6328;
v_6324:
    v_6373 = qvalue(elt(env, 1)); // atts
    goto v_6325;
v_6326:
    v_6372 = elt(env, 2); // name
    goto v_6327;
v_6328:
    goto v_6324;
v_6325:
    goto v_6326;
v_6327:
    fn = elt(env, 6); // find
    v_6372 = (*qfn2(fn))(fn, v_6373, v_6372);
    env = stack[-1];
    stack[0] = v_6372;
    goto v_6340;
v_6336:
    v_6373 = qvalue(elt(env, 1)); // atts
    goto v_6337;
v_6338:
    v_6372 = elt(env, 3); // hex
    goto v_6339;
v_6340:
    goto v_6336;
v_6337:
    goto v_6338;
v_6339:
    fn = elt(env, 6); // find
    v_6372 = (*qfn2(fn))(fn, v_6373, v_6372);
    env = stack[-1];
    if (v_6372 == nil) goto v_6334;
    goto v_6348;
v_6344:
    v_6373 = elt(env, 4); // "wrong att"
    goto v_6345;
v_6346:
    v_6372 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_6347;
v_6348:
    goto v_6344;
v_6345:
    goto v_6346;
v_6347:
    fn = elt(env, 7); // errorml
    v_6372 = (*qfn2(fn))(fn, v_6373, v_6372);
    env = stack[-1];
    goto v_6332;
v_6334:
v_6332:
    goto v_6360;
v_6356:
    v_6373 = qvalue(elt(env, 1)); // atts
    goto v_6357;
v_6358:
    v_6372 = elt(env, 5); // dec
    goto v_6359;
v_6360:
    goto v_6356;
v_6357:
    goto v_6358;
v_6359:
    fn = elt(env, 6); // find
    v_6372 = (*qfn2(fn))(fn, v_6373, v_6372);
    env = stack[-1];
    if (v_6372 == nil) goto v_6354;
    goto v_6368;
v_6364:
    v_6373 = elt(env, 4); // "wrong att"
    goto v_6365;
v_6366:
    v_6372 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_6367;
v_6368:
    goto v_6364;
v_6365:
    goto v_6366;
v_6367:
    fn = elt(env, 7); // errorml
    v_6372 = (*qfn2(fn))(fn, v_6373, v_6372);
    goto v_6352;
v_6354:
v_6352:
    v_6372 = stack[0];
    return onevalue(v_6372);
}



// Code for simpexpon1

static LispObject CC_simpexpon1(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6375, v_6376;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_6320;
    stack[-2] = v_6319;
// end of prologue
    v_6375 = qvalue(elt(env, 1)); // !*numval
    if (v_6375 == nil) goto v_6325;
    goto v_6337;
v_6333:
    v_6376 = qvalue(elt(env, 2)); // dmode!*
    goto v_6334;
v_6335:
    v_6375 = elt(env, 3); // !:rd!:
    goto v_6336;
v_6337:
    goto v_6333;
v_6334:
    goto v_6335;
v_6336:
    if (v_6376 == v_6375) goto v_6331;
    else goto v_6332;
v_6331:
    v_6375 = lisp_true;
    goto v_6330;
v_6332:
    goto v_6347;
v_6343:
    v_6376 = qvalue(elt(env, 2)); // dmode!*
    goto v_6344;
v_6345:
    v_6375 = elt(env, 4); // !:cr!:
    goto v_6346;
v_6347:
    goto v_6343;
v_6344:
    goto v_6345;
v_6346:
    v_6375 = (v_6376 == v_6375 ? lisp_true : nil);
    goto v_6330;
    v_6375 = nil;
v_6330:
    if (v_6375 == nil) goto v_6325;
    goto v_6356;
v_6352:
    v_6376 = stack[-1];
    goto v_6353;
v_6354:
    v_6375 = stack[-2];
    goto v_6355;
v_6356:
    goto v_6352;
v_6353:
    goto v_6354;
v_6355:
        return Lapply1(nil, v_6376, v_6375);
v_6325:
// Binding dmode!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=3
{   bind_fluid_stack bind_fluid_var(-4, 2, -3);
    qvalue(elt(env, 2)) = nil; // dmode!*
// Binding alglist!*
// FLUIDBIND: reloadenv=4 litvec-offset=5 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 5, 0);
    qvalue(elt(env, 5)) = nil; // alglist!*
    v_6375 = nil;
    v_6375 = ncons(v_6375);
    env = stack[-4];
    qvalue(elt(env, 5)) = v_6375; // alglist!*
    goto v_6372;
v_6368:
    v_6376 = stack[-1];
    goto v_6369;
v_6370:
    v_6375 = stack[-2];
    goto v_6371;
v_6372:
    goto v_6368;
v_6369:
    goto v_6370;
v_6371:
    v_6375 = Lapply1(nil, v_6376, v_6375);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    goto v_6323;
    v_6375 = nil;
v_6323:
    return onevalue(v_6375);
}



// Code for sc_setmat

static LispObject CC_sc_setmat(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6343, v_6344;
    LispObject v_6322, v_6321, v_6320, v_6319;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "sc_setmat");
    va_start(aa, nargs);
    v_6319 = va_arg(aa, LispObject);
    v_6320 = va_arg(aa, LispObject);
    v_6321 = va_arg(aa, LispObject);
    v_6322 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v_6322,v_6321,v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v_6319,v_6320,v_6321,v_6322);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_6322;
    stack[-1] = v_6321;
    v_6343 = v_6320;
    v_6344 = v_6319;
// end of prologue
    goto v_6330;
v_6324:
    goto v_6335;
v_6331:
    stack[-2] = v_6344;
    goto v_6332;
v_6333:
    v_6343 = sub1(v_6343);
    env = stack[-3];
    goto v_6334;
v_6335:
    goto v_6331;
v_6332:
    goto v_6333;
v_6334:
    stack[-2] = *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + (((intptr_t)v_6343-TAG_FIXNUM)/(16/CELL)));
    goto v_6325;
v_6326:
    v_6343 = stack[-1];
    v_6344 = sub1(v_6343);
    goto v_6327;
v_6328:
    v_6343 = stack[0];
    goto v_6329;
v_6330:
    goto v_6324;
v_6325:
    goto v_6326;
v_6327:
    goto v_6328;
v_6329:
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + (((intptr_t)v_6344-TAG_FIXNUM)/(16/CELL))) = v_6343;
    return onevalue(v_6343);
}



// Code for vdpzero

static LispObject CC_vdpzero(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_6322;
    LispObject fn;
    argcheck(nargs, 0, "vdpzero");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_6322 = (LispObject)0+TAG_FIXNUM; // 0
    {
        fn = elt(env, 1); // a2vdp
        return (*qfn1(fn))(fn, v_6322);
    }
}



// Code for revalind

static LispObject CC_revalind(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6347, v_6348, v_6349;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_6319;
// end of prologue
// Binding alglist!*
// FLUIDBIND: reloadenv=4 litvec-offset=1 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 1, -1);
    qvalue(elt(env, 1)) = nil; // alglist!*
// Binding dmode!*
// FLUIDBIND: reloadenv=4 litvec-offset=2 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 2, 0);
    qvalue(elt(env, 2)) = nil; // dmode!*
    v_6347 = nil;
    v_6347 = ncons(v_6347);
    env = stack[-4];
    qvalue(elt(env, 1)) = v_6347; // alglist!*
    v_6347 = qvalue(elt(env, 3)); // subfg!*
    stack[-3] = v_6347;
    v_6347 = nil;
    qvalue(elt(env, 3)) = v_6347; // subfg!*
    goto v_6338;
v_6332:
    v_6349 = elt(env, 4); // !0
    goto v_6333;
v_6334:
    v_6348 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6335;
v_6336:
    v_6347 = stack[-2];
    goto v_6337;
v_6338:
    goto v_6332;
v_6333:
    goto v_6334;
v_6335:
    goto v_6336;
v_6337:
    v_6347 = Lsubst(nil, 3, v_6349, v_6348, v_6347);
    env = stack[-4];
    stack[-2] = v_6347;
    v_6347 = stack[-2];
    fn = elt(env, 5); // simp
    v_6347 = (*qfn1(fn))(fn, v_6347);
    env = stack[-4];
    fn = elt(env, 6); // prepsq
    v_6347 = (*qfn1(fn))(fn, v_6347);
    env = stack[-4];
    v_6348 = v_6347;
    v_6347 = stack[-3];
    qvalue(elt(env, 3)) = v_6347; // subfg!*
    v_6347 = v_6348;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_6347);
}



// Code for flatindxl

static LispObject CC_flatindxl(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6381, v_6382;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_6381 = v_6319;
// end of prologue
    stack[-3] = v_6381;
    v_6381 = stack[-3];
    if (v_6381 == nil) goto v_6330;
    else goto v_6331;
v_6330:
    v_6381 = nil;
    goto v_6325;
v_6331:
    v_6381 = stack[-3];
    v_6381 = qcar(v_6381);
    v_6382 = v_6381;
    v_6381 = v_6382;
    if (!consp(v_6381)) goto v_6340;
    else goto v_6341;
v_6340:
    v_6381 = v_6382;
    goto v_6339;
v_6341:
    v_6381 = v_6382;
    v_6381 = qcdr(v_6381);
    v_6381 = qcar(v_6381);
    goto v_6339;
    v_6381 = nil;
v_6339:
    v_6381 = ncons(v_6381);
    env = stack[-4];
    stack[-1] = v_6381;
    stack[-2] = v_6381;
v_6326:
    v_6381 = stack[-3];
    v_6381 = qcdr(v_6381);
    stack[-3] = v_6381;
    v_6381 = stack[-3];
    if (v_6381 == nil) goto v_6353;
    else goto v_6354;
v_6353:
    v_6381 = stack[-2];
    goto v_6325;
v_6354:
    goto v_6362;
v_6358:
    stack[0] = stack[-1];
    goto v_6359;
v_6360:
    v_6381 = stack[-3];
    v_6381 = qcar(v_6381);
    v_6382 = v_6381;
    v_6381 = v_6382;
    if (!consp(v_6381)) goto v_6370;
    else goto v_6371;
v_6370:
    v_6381 = v_6382;
    goto v_6369;
v_6371:
    v_6381 = v_6382;
    v_6381 = qcdr(v_6381);
    v_6381 = qcar(v_6381);
    goto v_6369;
    v_6381 = nil;
v_6369:
    v_6381 = ncons(v_6381);
    env = stack[-4];
    goto v_6361;
v_6362:
    goto v_6358;
v_6359:
    goto v_6360;
v_6361:
    v_6381 = Lrplacd(nil, stack[0], v_6381);
    env = stack[-4];
    v_6381 = stack[-1];
    v_6381 = qcdr(v_6381);
    stack[-1] = v_6381;
    goto v_6326;
v_6325:
    return onevalue(v_6381);
}



// Code for convchk

static LispObject CC_convchk(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6378, v_6379, v_6380;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6319);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_6378 = v_6319;
// end of prologue
    v_6379 = qvalue(elt(env, 1)); // !*!*roundbf
    if (v_6379 == nil) goto v_6324;
    v_6379 = v_6378;
    if (!consp(v_6379)) goto v_6328;
    else goto v_6329;
v_6328:
    v_6379 = v_6378;
    v_6379 = Lfloatp(nil, v_6379);
    env = stack[0];
    if (v_6379 == nil) goto v_6334;
    {
        fn = elt(env, 3); // fl2bf
        return (*qfn1(fn))(fn, v_6378);
    }
v_6334:
    v_6379 = v_6378;
    if (!consp(v_6379)) goto v_6345;
    goto v_6343;
v_6345:
    v_6379 = v_6378;
    v_6379 = integerp(v_6379);
    if (v_6379 == nil) goto v_6349;
    goto v_6359;
v_6353:
    v_6380 = elt(env, 2); // !:rd!:
    goto v_6354;
v_6355:
    v_6379 = v_6378;
    goto v_6356;
v_6357:
    v_6378 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6358;
v_6359:
    goto v_6353;
v_6354:
    goto v_6355;
v_6356:
    goto v_6357;
v_6358:
    v_6378 = list2star(v_6380, v_6379, v_6378);
    env = stack[0];
    goto v_6343;
v_6349:
    fn = elt(env, 4); // read!:num
    v_6378 = (*qfn1(fn))(fn, v_6378);
    env = stack[0];
    goto v_6343;
    v_6378 = nil;
v_6343:
    {
        fn = elt(env, 5); // normbf
        return (*qfn1(fn))(fn, v_6378);
    }
    v_6378 = nil;
    goto v_6327;
v_6329:
    goto v_6327;
    v_6378 = nil;
v_6327:
    goto v_6322;
v_6324:
    v_6379 = v_6378;
    if (!consp(v_6379)) goto v_6370;
    else goto v_6371;
v_6370:
    goto v_6322;
v_6371:
    {
        fn = elt(env, 6); // bf2flck
        return (*qfn1(fn))(fn, v_6378);
    }
    v_6378 = nil;
v_6322:
    return onevalue(v_6378);
}



// Code for ncmpchk

static LispObject CC_ncmpchk(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6345, v_6346;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_6320;
    stack[-1] = v_6319;
// end of prologue
    goto v_6331;
v_6327:
    v_6346 = stack[-1];
    goto v_6328;
v_6329:
    v_6345 = stack[0];
    goto v_6330;
v_6331:
    goto v_6327;
v_6328:
    goto v_6329;
v_6330:
    fn = elt(env, 1); // noncommuting
    v_6345 = (*qfn2(fn))(fn, v_6346, v_6345);
    env = stack[-2];
    if (v_6345 == nil) goto v_6324;
    else goto v_6325;
v_6324:
    v_6345 = lisp_true;
    goto v_6323;
v_6325:
    goto v_6342;
v_6338:
    v_6346 = stack[-1];
    goto v_6339;
v_6340:
    v_6345 = stack[0];
    goto v_6341;
v_6342:
    goto v_6338;
v_6339:
    goto v_6340;
v_6341:
    {
        fn = elt(env, 2); // physop!-ordop
        return (*qfn2(fn))(fn, v_6346, v_6345);
    }
    v_6345 = nil;
v_6323:
    return onevalue(v_6345);
}



// Code for mv!-pow!-!-

static LispObject CC_mvKpowKK(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6356, v_6357;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_6320;
    stack[-1] = v_6319;
// end of prologue
    stack[-2] = nil;
v_6325:
    v_6356 = stack[-1];
    if (v_6356 == nil) goto v_6328;
    else goto v_6329;
v_6328:
    v_6356 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_6356);
    }
v_6329:
    goto v_6340;
v_6336:
    goto v_6346;
v_6342:
    v_6356 = stack[-1];
    v_6357 = qcar(v_6356);
    goto v_6343;
v_6344:
    v_6356 = stack[0];
    v_6356 = qcar(v_6356);
    goto v_6345;
v_6346:
    goto v_6342;
v_6343:
    goto v_6344;
v_6345:
    v_6357 = difference2(v_6357, v_6356);
    env = stack[-3];
    goto v_6337;
v_6338:
    v_6356 = stack[-2];
    goto v_6339;
v_6340:
    goto v_6336;
v_6337:
    goto v_6338;
v_6339:
    v_6356 = cons(v_6357, v_6356);
    env = stack[-3];
    stack[-2] = v_6356;
    v_6356 = stack[-1];
    v_6356 = qcdr(v_6356);
    stack[-1] = v_6356;
    v_6356 = stack[0];
    v_6356 = qcdr(v_6356);
    stack[0] = v_6356;
    goto v_6325;
    v_6356 = nil;
    return onevalue(v_6356);
}



// Code for artimes!:

static LispObject CC_artimesT(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6345, v_6346, v_6347;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_6346 = v_6320;
    v_6347 = v_6319;
// end of prologue
// Binding dmode!*
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    qvalue(elt(env, 1)) = nil; // dmode!*
// Binding !*exp
// FLUIDBIND: reloadenv=3 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-3, 2, -1);
    qvalue(elt(env, 2)) = nil; // !*exp
    v_6345 = lisp_true;
    qvalue(elt(env, 2)) = v_6345; // !*exp
    goto v_6332;
v_6328:
    stack[0] = elt(env, 3); // !:ar!:
    goto v_6329;
v_6330:
    goto v_6340;
v_6336:
    v_6345 = v_6347;
    v_6345 = qcdr(v_6345);
    goto v_6337;
v_6338:
    v_6346 = qcdr(v_6346);
    goto v_6339;
v_6340:
    goto v_6336;
v_6337:
    goto v_6338;
v_6339:
    fn = elt(env, 4); // multf
    v_6345 = (*qfn2(fn))(fn, v_6345, v_6346);
    env = stack[-3];
    fn = elt(env, 5); // reducepowers
    v_6345 = (*qfn1(fn))(fn, v_6345);
    env = stack[-3];
    goto v_6331;
v_6332:
    goto v_6328;
v_6329:
    goto v_6330;
v_6331:
    v_6345 = cons(stack[0], v_6345);
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_6345);
}



// Code for sfto_avgq

static LispObject CC_sfto_avgq(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6344, v_6345;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_6344 = v_6320;
    v_6345 = v_6319;
// end of prologue
    goto v_6327;
v_6323:
    goto v_6333;
v_6329:
    goto v_6330;
v_6331:
    goto v_6332;
v_6333:
    goto v_6329;
v_6330:
    goto v_6331;
v_6332:
    fn = elt(env, 1); // addsq
    stack[0] = (*qfn2(fn))(fn, v_6345, v_6344);
    env = stack[-1];
    goto v_6324;
v_6325:
    goto v_6341;
v_6337:
    v_6345 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_6338;
v_6339:
    v_6344 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6340;
v_6341:
    goto v_6337;
v_6338:
    goto v_6339;
v_6340:
    v_6344 = cons(v_6345, v_6344);
    env = stack[-1];
    goto v_6326;
v_6327:
    goto v_6323;
v_6324:
    goto v_6325;
v_6326:
    {
        LispObject v_6347 = stack[0];
        fn = elt(env, 2); // quotsq
        return (*qfn2(fn))(fn, v_6347, v_6344);
    }
}



// Code for efface1

static LispObject CC_efface1(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6358, v_6359, v_6360, v_6361;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_6360 = v_6320;
    v_6361 = v_6319;
// end of prologue
    v_6358 = v_6360;
    if (v_6358 == nil) goto v_6324;
    else goto v_6325;
v_6324:
    v_6358 = nil;
    goto v_6323;
v_6325:
    goto v_6334;
v_6330:
    v_6359 = v_6361;
    goto v_6331;
v_6332:
    v_6358 = v_6360;
    v_6358 = qcar(v_6358);
    goto v_6333;
v_6334:
    goto v_6330;
v_6331:
    goto v_6332;
v_6333:
    if (v_6359 == v_6358) goto v_6328;
    else goto v_6329;
v_6328:
    v_6358 = v_6360;
    v_6358 = qcdr(v_6358);
    goto v_6323;
v_6329:
    goto v_6347;
v_6343:
    stack[0] = v_6360;
    goto v_6344;
v_6345:
    goto v_6354;
v_6350:
    v_6358 = v_6361;
    goto v_6351;
v_6352:
    v_6359 = v_6360;
    v_6359 = qcdr(v_6359);
    goto v_6353;
v_6354:
    goto v_6350;
v_6351:
    goto v_6352;
v_6353:
    v_6358 = CC_efface1(elt(env, 0), v_6358, v_6359);
    goto v_6346;
v_6347:
    goto v_6343;
v_6344:
    goto v_6345;
v_6346:
    {
        LispObject v_6363 = stack[0];
        return Lrplacd(nil, v_6363, v_6358);
    }
    v_6358 = nil;
v_6323:
    return onevalue(v_6358);
}



// Code for lto_almerge

static LispObject CC_lto_almerge(LispObject env,
                         LispObject v_6319, LispObject v_6320)
{
    env = qenv(env);
    LispObject v_6440, v_6441, v_6442;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_6320,v_6319);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_6319,v_6320);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-3] = v_6320;
    v_6440 = v_6319;
// end of prologue
v_6318:
    v_6441 = v_6440;
    if (v_6441 == nil) goto v_6328;
    else goto v_6329;
v_6328:
    v_6440 = nil;
    goto v_6325;
v_6329:
    v_6441 = v_6440;
    v_6441 = qcdr(v_6441);
    if (v_6441 == nil) goto v_6334;
    else goto v_6335;
v_6334:
    v_6440 = qcar(v_6440);
    goto v_6325;
v_6335:
    v_6441 = v_6440;
    v_6441 = qcdr(v_6441);
    v_6441 = qcdr(v_6441);
    if (v_6441 == nil) goto v_6342;
    else goto v_6343;
v_6342:
    v_6441 = v_6440;
    v_6441 = qcdr(v_6441);
    v_6441 = qcar(v_6441);
    stack[-4] = v_6441;
    v_6440 = qcar(v_6440);
    stack[-2] = v_6440;
v_6353:
    v_6440 = stack[-2];
    if (v_6440 == nil) goto v_6358;
    else goto v_6359;
v_6358:
    goto v_6352;
v_6359:
    v_6440 = stack[-2];
    v_6440 = qcar(v_6440);
    v_6441 = v_6440;
    goto v_6369;
v_6365:
    v_6440 = v_6441;
    v_6442 = qcar(v_6440);
    goto v_6366;
v_6367:
    v_6440 = stack[-4];
    goto v_6368;
v_6369:
    goto v_6365;
v_6366:
    goto v_6367;
v_6368:
    v_6440 = Lassoc(nil, v_6442, v_6440);
    v_6442 = v_6440;
    v_6440 = v_6442;
    if (v_6440 == nil) goto v_6377;
    goto v_6384;
v_6380:
    stack[-1] = v_6442;
    goto v_6381;
v_6382:
    goto v_6391;
v_6387:
    stack[0] = stack[-3];
    goto v_6388;
v_6389:
    goto v_6398;
v_6394:
    v_6440 = v_6441;
    v_6440 = qcdr(v_6440);
    goto v_6395;
v_6396:
    v_6441 = v_6442;
    v_6441 = qcdr(v_6441);
    goto v_6397;
v_6398:
    goto v_6394;
v_6395:
    goto v_6396;
v_6397:
    v_6440 = list2(v_6440, v_6441);
    env = stack[-5];
    goto v_6390;
v_6391:
    goto v_6387;
v_6388:
    goto v_6389;
v_6390:
    fn = elt(env, 1); // apply
    v_6440 = (*qfn2(fn))(fn, stack[0], v_6440);
    env = stack[-5];
    goto v_6383;
v_6384:
    goto v_6380;
v_6381:
    goto v_6382;
v_6383:
    fn = elt(env, 2); // setcdr
    v_6440 = (*qfn2(fn))(fn, stack[-1], v_6440);
    env = stack[-5];
    goto v_6375;
v_6377:
    goto v_6410;
v_6406:
    goto v_6407;
v_6408:
    v_6440 = stack[-4];
    goto v_6409;
v_6410:
    goto v_6406;
v_6407:
    goto v_6408;
v_6409:
    v_6440 = cons(v_6441, v_6440);
    env = stack[-5];
    stack[-4] = v_6440;
    goto v_6375;
v_6375:
    v_6440 = stack[-2];
    v_6440 = qcdr(v_6440);
    stack[-2] = v_6440;
    goto v_6353;
v_6352:
    v_6440 = stack[-4];
    goto v_6325;
v_6343:
    goto v_6421;
v_6417:
    goto v_6427;
v_6423:
    v_6441 = v_6440;
    stack[0] = qcar(v_6441);
    goto v_6424;
v_6425:
    goto v_6435;
v_6431:
    v_6441 = qcdr(v_6440);
    goto v_6432;
v_6433:
    v_6440 = stack[-3];
    goto v_6434;
v_6435:
    goto v_6431;
v_6432:
    goto v_6433;
v_6434:
    v_6440 = CC_lto_almerge(elt(env, 0), v_6441, v_6440);
    env = stack[-5];
    goto v_6426;
v_6427:
    goto v_6423;
v_6424:
    goto v_6425;
v_6426:
    v_6440 = list2(stack[0], v_6440);
    env = stack[-5];
    goto v_6418;
v_6419:
    v_6441 = stack[-3];
    goto v_6420;
v_6421:
    goto v_6417;
v_6418:
    goto v_6419;
v_6420:
    stack[-3] = v_6441;
    goto v_6318;
v_6325:
    return onevalue(v_6440);
}



// Code for sfto_ucontentf

static LispObject CC_sfto_ucontentf(LispObject env,
                         LispObject v_6319)
{
    env = qenv(env);
    LispObject v_6350, v_6351;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6350 = v_6319;
// end of prologue
    v_6351 = v_6350;
    if (!consp(v_6351)) goto v_6327;
    else goto v_6328;
v_6327:
    v_6351 = lisp_true;
    goto v_6326;
v_6328:
    v_6351 = v_6350;
    v_6351 = qcar(v_6351);
    v_6351 = (consp(v_6351) ? nil : lisp_true);
    goto v_6326;
    v_6351 = nil;
v_6326:
    if (v_6351 == nil) goto v_6324;
    goto v_6322;
v_6324:
    goto v_6344;
v_6340:
    v_6351 = v_6350;
    goto v_6341;
v_6342:
    v_6350 = qcar(v_6350);
    v_6350 = qcar(v_6350);
    v_6350 = qcar(v_6350);
    goto v_6343;
v_6344:
    goto v_6340;
v_6341:
    goto v_6342;
v_6343:
    {
        fn = elt(env, 1); // sfto_ucontentf1
        return (*qfn2(fn))(fn, v_6351, v_6350);
    }
    v_6350 = nil;
v_6322:
    return onevalue(v_6350);
}



setup_type const u12_setup[] =
{
    {"integerom",               CC_integerom,   TOO_MANY_1,    WRONG_NO_1},
    {"writepri",                TOO_FEW_2,      CC_writepri,   WRONG_NO_2},
    {"cut:ep",                  TOO_FEW_2,      CC_cutTep,     WRONG_NO_2},
    {"split-road",              TOO_FEW_2,      CC_splitKroad, WRONG_NO_2},
    {"formc",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formc},
    {"simp",                    CC_simp,        TOO_MANY_1,    WRONG_NO_1},
    {"compactfmatch2",          CC_compactfmatch2,TOO_MANY_1,  WRONG_NO_1},
    {"dp=mocompare",            TOO_FEW_2,      CC_dpMmocompare,WRONG_NO_2},
    {"raiseind:",               CC_raiseindT,   TOO_MANY_1,    WRONG_NO_1},
    {"set-general-modulus",     CC_setKgeneralKmodulus,TOO_MANY_1,WRONG_NO_1},
    {"ra_budan-transform",      CC_ra_budanKtransform,TOO_MANY_1,WRONG_NO_1},
    {"rempropss",               TOO_FEW_2,      CC_rempropss,  WRONG_NO_2},
    {"ofsf_smwcpknowl",         CC_ofsf_smwcpknowl,TOO_MANY_1, WRONG_NO_1},
    {"color1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_color1},
    {"msappend",                TOO_FEW_2,      CC_msappend,   WRONG_NO_2},
    {"cl_simpl",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_simpl},
    {"qsort",                   CC_qsort,       TOO_MANY_1,    WRONG_NO_1},
    {"cl_varl2",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cl_varl2},
    {"omiir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omiir},
    {"c:extadd",                TOO_FEW_2,      CC_cTextadd,   WRONG_NO_2},
    {"comm_kernels1",           TOO_FEW_2,      CC_comm_kernels1,WRONG_NO_2},
    {"addpf",                   TOO_FEW_2,      CC_addpf,      WRONG_NO_2},
    {"gfrsq",                   CC_gfrsq,       TOO_MANY_1,    WRONG_NO_1},
    {"safe-fp-times",           TOO_FEW_2,      CC_safeKfpKtimes,WRONG_NO_2},
    {"tokquote",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_tokquote},
    {"argnochk",                CC_argnochk,    TOO_MANY_1,    WRONG_NO_1},
    {"make-term",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_makeKterm},
    {"red_divtest",             TOO_FEW_2,      CC_red_divtest,WRONG_NO_2},
    {"ordn",                    CC_ordn,        TOO_MANY_1,    WRONG_NO_1},
    {"rnminus:",                CC_rnminusT,    TOO_MANY_1,    WRONG_NO_1},
    {"horner-rule",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_hornerKrule},
    {"freeofl",                 TOO_FEW_2,      CC_freeofl,    WRONG_NO_2},
    {"lalr_make_compressed_action_row",CC_lalr_make_compressed_action_row,TOO_MANY_1,WRONG_NO_1},
    {"get_rep_matrix_in",       TOO_FEW_2,      CC_get_rep_matrix_in,WRONG_NO_2},
    {"cl_fvarl",                CC_cl_fvarl,    TOO_MANY_1,    WRONG_NO_1},
    {"qqe_ofsf_varlterm",       TOO_FEW_2,      CC_qqe_ofsf_varlterm,WRONG_NO_2},
    {"omvir",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omvir},
    {"simpexpon1",              TOO_FEW_2,      CC_simpexpon1, WRONG_NO_2},
    {"sc_setmat",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_sc_setmat},
    {"vdpzero",                 WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_vdpzero},
    {"revalind",                CC_revalind,    TOO_MANY_1,    WRONG_NO_1},
    {"flatindxl",               CC_flatindxl,   TOO_MANY_1,    WRONG_NO_1},
    {"convchk",                 CC_convchk,     TOO_MANY_1,    WRONG_NO_1},
    {"ncmpchk",                 TOO_FEW_2,      CC_ncmpchk,    WRONG_NO_2},
    {"mv-pow--",                TOO_FEW_2,      CC_mvKpowKK,   WRONG_NO_2},
    {"artimes:",                TOO_FEW_2,      CC_artimesT,   WRONG_NO_2},
    {"sfto_avgq",               TOO_FEW_2,      CC_sfto_avgq,  WRONG_NO_2},
    {"efface1",                 TOO_FEW_2,      CC_efface1,    WRONG_NO_2},
    {"lto_almerge",             TOO_FEW_2,      CC_lto_almerge,WRONG_NO_2},
    {"sfto_ucontentf",          CC_sfto_ucontentf,TOO_MANY_1,  WRONG_NO_1},
    {NULL, (one_args *)"u12", (two_args *)"149409 6374458 8140405", 0}
};

// end of generated code
