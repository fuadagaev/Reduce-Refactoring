
// $destdir/u11.c        Machine generated C code

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
#ifndef DEBUG
#define NDEBUG 1
#endif
#if defined HAVE_COMPLEX_H && \
 defined HAVE_COMPLEX_DOUBLE && \
 defined HAVE_CSQRT
#define HAVE_COMPLEX 1
#endif
#if defined HAVE_SIGNAL_H && defined HAVE_SETJMP_H
#if defined HAVE_SIGSETJMP && defined HAVE_SIGLONGJMP
#if defined HAVE_SIGACTION && defined HAVE_SIGALTSTACK
#define USE_SIGALTSTACK 1
#endif
#endif
#endif
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif
#ifdef WIN32
#define __USE_MINGW_ANSI_STDIO 1
#endif
#ifdef WIN32
#include <winsock.h>
#include <semaphore.h>
#include <windows.h>
#else 
#define unix_posix 1 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <fcntl.h>
#define WSAGetLastError() errno 
#define WSACleanup() 
#define closesocket(a) close(a)
#define SOCKET int
#define SOCKET_ERROR (-1)
#ifndef INADDR_NONE
# define INADDR_NONE 0xffffffff
#endif
#ifdef HAVE_LIBPTHREAD
#include <semaphore.h>
#include <pthread.h>
#endif
#endif 
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <exception>
#include <errno.h>
#include <assert.h>
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
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
#if !defined HAVE_INTPTR_T && (SIZEOF_VOID_P == 4)
typedef int32_t intptr_t;
#define INTPTR_MAX INT32_MAX
#define INTPTR_MIN INT32_MIN
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && (SIZEOF_VOID_P == 8)
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && (SIZEOF_VOID_P == 4)
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && (SIZEOF_VOID_P == 8)
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#ifndef UINTPTR_MAX
#define UINTPTR_MAX ((uintptr_t)(-1))
#endif
#ifndef INTPTR_MAX
#define INTPTR_MAX ((intptr_t)((UINTPTR_MAX-1)/2))
#endif
#ifndef INTPTR_MIN
#define INTPTR_MIN (-1-INTPTR_MAX)
#endif
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
#ifdef HAVE_UINT128_T
#define HAVE_NATIVE_UINT128 1
#elif defined HAVE_UNSIGNED___INT128
typedef unsigned __int128 uint128_t;
#define HAVE_NATIVE_UINT128
#else
#include "uint128_t.h" 
#endif
#ifdef HAVE_INT128_T
#define HAVE_NATIVE_INT128 1
#elif defined HAVE___INT128
typedef __int128 int128_t;
#define HAVE_NATIVE_INT128
#elif defined HAVE_UINT128_T || defined HAVE_UNSIGNED___INT128
#error Seem to have unsigned 128-bit type but not a signed one!
#endif
#endif 
#ifndef header_int128_t_h
#define header_int128_t_h 1
#ifdef HAVE_NATIVE_INT128
static inline bool greaterp128(int128_t a, int128_t b)
{ return a > b;
}
static inline bool lessp128(int128_t a, int128_t b)
{ return a < b;
}
static inline bool geq128(int128_t a, int128_t b)
{ return a >= b;
}
static inline bool leq128(int128_t a, int128_t b)
{ return a <= b;
}
static inline int128_t ASL128(int128_t a, int n)
{ return (uint128_t)a << MAXSHIFT(n, int128_t);
}
#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
static inline int128_t ASR128(int128_t a, int n)
{ return a >> MAXSHIFT(n, int128_t);
}
#else 
static inline int128_t ASR128(int128_t a, int n)
{ n = MAXSHIFT(n, int128_t);
 return (a & ~((uint128_t)1<<n - 1))/(int128_t)1<<n;
}
#endif 
static inline int64_t NARROW128(int128_t a)
{ return (int64_t)a;
}
static inline void divrem128(int128_t a, int128_t b,
 int128_t & q, int128_t & r)
{ uint128_t qq = a/b;
 q = qq;
 r = a - qq*b;
}
#else 
typedef uint128_t int128_t;
static inline bool greaterp128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa > bb;
}
static inline bool lessp128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa < bb;
}
static inline bool geq128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa >= bb;
}
static inline bool leq128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa <= bb;
}
static inline int128_t ASL128(const int128_t & a, int n)
{ n = MAXSHIFT(n, int128_t);
 if (n < 64) return
 int128_t((a.upper()<<n) | (a.lower()>>(64-n)),
 a.lower()<<n);
 else if (n == 64) return int128_t(a.lower(), 0);
 else return int128_t(a.lower()<<(n-64), 0);
}
static inline int128_t ASR128(const int128_t & a, int n)
{ n = MAXSHIFT(n, int128_t);
 if (n < 64) return int128_t(ASR((int64_t)a.upper(), n),
 (a.upper()<<(64-n)) | (a.lower()>>n));
 else if (n == 64) return int128_t(-(int64_t)(a.upper()<0),
 a.upper());
 else return int128_t(-(int64_t)(a.upper()<0),
 ASR(((int64_t)a.upper()), n-64));
}
static inline int64_t NARROW128(const int128_t & a)
{ return (int64_t)a.lower();
}
static inline void divrem128(const int128_t & a, const int128_t & b,
 int128_t & q, int128_t & r)
{ if ((int64_t)a.upper() < 0)
 { if ((int64_t)b.upper() < 0) q = (-a)/(-b);
 else q = -((-a)/b);
 }
 else
 { if ((int64_t)b.upper() < 0) q = -(a/(-b));
 else q = a/b;
 }
 r = a - q*b;
}
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
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
static inline bool is_forward(LispObject p)
{ return (p & TAG_BITS) == TAG_FORWARD;
}
static inline bool is_number(LispObject p)
{ return (p & TAG_BITS) >= TAG_NUMBERS;
}
static inline bool is_float(LispObject p)
{ return ((0xc040 >> (p & XTAG_BITS)) & 1) != 0;
}
static inline bool is_immed_or_cons(LispObject p)
{ return ((0x85 >> (p & TAG_BITS)) & 1) != 0;
}
static inline bool is_immed_cons_sym(LispObject p)
{ return ((0x95 >> (p & TAG_BITS)) & 1) != 0;
}
static inline bool need_more_than_eq(LispObject p)
{ return ((0x63 >> (p & TAG_BITS)) & 1) != 0;
}
static inline LispObject fixnum_of_int(intptr_t x)
{ return (LispObject)((((uintptr_t)x)<<4) + TAG_FIXNUM);
}
static inline intptr_t int_of_fixnum(LispObject x)
{ return ((intptr_t)x & ~(intptr_t)15)/16;
}
static inline bool valid_as_fixnum(int32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return int_of_fixnum(fixnum_of_int(x)) == x;
}
static inline bool valid_as_fixnum(int64_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
static inline bool valid_as_fixnum(int128_t x)
{ return int_of_fixnum(fixnum_of_int(NARROW128(x))) == x;
}
static inline bool intptr_valid_as_fixnum(intptr_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
static inline bool valid_as_fixnum(uint32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return x < (((uintptr_t)1) << 28);
}
static inline bool valid_as_fixnum(uint64_t x)
{ return x < (((uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
static inline bool uint128_valid_as_fixnum(uint128_t x)
{ return x < (((uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
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
#if 0
#define TYPE_MAPLEREF ( 0x2f <<Tw) 
 
#endif
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
typedef union _Float_union
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
typedef union _Double_union
{ double f;
 uint32_t i[2];
 uint64_t i64;
 float64_t f64;
} Double_union;
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
extern LispObject err_table, progn_symbol, gcknt_symbol;
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
extern int64_t gc_number;
extern int64_t reclaim_trap_count;
extern uintptr_t reclaim_stack_limit;
extern bool next_gc_is_hard;
extern uint64_t force_cons, force_vec;
static inline bool cons_forced(size_t n)
{
#ifdef DEBUG
 if (force_cons == 0) return false;
 if (force_cons <= n)
 { force_cons = 0;
 next_gc_is_hard = true;
 return true;
 }
 force_cons -= n;
#endif
 return false;
}
static inline bool vec_forced(size_t n)
{
#ifdef DEBUG
 if (force_vec == 0) return false;
 if (force_vec <= n)
 { force_vec = 0;
 next_gc_is_hard = true;
 return true;
 }
 force_vec -= n;
#endif
 return false;
}
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
extern bool isprime(uint64_t);
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
extern uint64_t sixty_four_bits_unsigned(LispObject a);
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
static inline bool equal(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return equal_fn(a, b);
 else return false;
}
static inline bool cl_equal(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return cl_equal_fn(a, b);
 else return false;
}
static inline bool eql(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return eql_fn(a, b);
 else return false;
}
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
extern unsigned char msd_table[256], lsd_table[256];
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
#define FIX_TRUNCATE softfloat_round_minMag
#define FIX_ROUND softfloat_round_near_even
#define FIX_FLOOR softfloat_round_min
#define FIX_CEILING softfloat_round_max
extern LispObject lisp_fix(LispObject a, int roundmode);
extern LispObject lisp_ifix(LispObject a, LispObject b, int roundmode);
static inline bool floating_edge_case(double r)
{ return (1.0/r == 0.0 || r != r);
}
static inline void floating_clear_flags()
{}
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
#define fixnum_minusp(a) ((intptr_t)(a) < 0)
#define bignum_minusp(a) \
 ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
static inline double value_of_immediate_float(LispObject a)
{ Float_union aa;
 if (SIXTY_FOUR_BIT) aa.i = (int32_t)((uint64_t)a>>32);
 else aa.i = (int32_t)(a - XTAG_SFLOAT);
 return aa.f;
}
extern LispObject make_boxfloat(double a, int type);
extern LispObject make_boxfloat128(float128_t a);
static inline LispObject pack_short_float(double d)
{ Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 aerror("exception with short float");
 }
 aa.i &= ~0xf;
 if (SIXTY_FOUR_BIT)
 return (LispObject)(((uint64_t)aa.i) << 32) + XTAG_SFLOAT;
 else return aa.i + XTAG_SFLOAT;
}
static inline LispObject pack_single_float(double d)
{ if (SIXTY_FOUR_BIT)
 { Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 aerror("exception with single float");
 }
 return (LispObject)((uint64_t)aa.i << 32) + XTAG_SFLOAT + XTAG_FLOAT32;
 }
 else
 { LispObject r = getvector(TAG_BOXFLOAT,
 TYPE_SINGLE_FLOAT, sizeof(Single_Float));
 single_float_val(r) = (float)d;
 if (trap_floating_overflow &&
 floating_edge_case(single_float_val(r)))
 { floating_clear_flags();
 aerror("exception with single float");
 }
 return r;
 }
}
static inline LispObject pack_immediate_float(double d,
 LispObject l1, LispObject l2=0)
{ Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 if (((l1 | l2) & XTAG_FLOAT32) != 0)
 aerror("exception with single float");
 else aerror("exception with short float");
 }
 if (SIXTY_FOUR_BIT)
 { if (((l1 | l2) & XTAG_FLOAT32) == 0) aa.i &= ~0xf;
 return (LispObject)(((uint64_t)aa.i) << 32) + XTAG_SFLOAT +
 ((l1 | l2) & XTAG_FLOAT32);
 }
 aa.i &= ~0xf;
 return aa.i + XTAG_SFLOAT;
}
static inline bool eq_i64d(int64_t a, double b)
{
 if (b != (double)a) return false;
 if (b == (double)((uint64_t)1<<63)) return false;
 return a == (int64_t)b;
}
static inline bool lessp_i64d(int64_t a, double b)
{
 if (a <= ((int64_t)1<<53) &&
 a >= -((int64_t)1<<53)) return (double)a < b;
 if (!(b >= -(double)((uint64_t)1<<63))) return false;
 if (!(b < (double)((uint64_t)1<<63))) return true;
 return a < (int64_t)b;
}
static inline bool lessp_di64(double a, int64_t b)
{
 if (b <= ((int64_t)1<<53) &&
 b >= -((int64_t)1<<53)) return a < (double)b;
 if (!(a < (double)((uint64_t)1<<63))) return false;
 if (!(a >= -(double)((uint64_t)1<<63))) return true;
 return (int64_t)a < b;
}
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
extern "C" LispObject integer_decode_long_float(LispObject a);
extern "C" LispObject Linteger_decode_float(LispObject env, LispObject a);
extern LispObject validate_number(const char *s, LispObject a,
 LispObject b, LispObject c);
extern LispObject make_fake_bignum(intptr_t n);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_four_word_bignum(int32_t a, uint32_t b,
 uint32_t c, uint32_t d);
extern LispObject make_n_word_bignum(int32_t a2, uint32_t a1,
 uint32_t a0, size_t n);
extern LispObject make_n4_word_bignum(int32_t a3, uint32_t a2,
 uint32_t a1, uint32_t a0, size_t n);
extern LispObject make_n5_word_bignum(int32_t a4, uint32_t a3,
 uint32_t a2, uint32_t a1,
 uint32_t a0, size_t n);
extern LispObject make_power_of_two(size_t n);
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
{ if (intptr_valid_as_fixnum(n)) return fixnum_of_int(n);
 else return make_lisp_integerptr_fn(n);
}
extern LispObject make_lisp_unsignedptr_fn(uintptr_t n);
static inline LispObject make_lisp_unsignedptr(uintptr_t n)
{ if (n < ((uintptr_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsignedptr_fn(n);
}
extern LispObject make_lisp_integer128_fn(int128_t n);
static inline LispObject make_lisp_integer128(int128_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int(NARROW128(n));
 else return make_lisp_integer128_fn(n);
}
extern LispObject make_lisp_unsigned128_fn(uint128_t n);
static inline LispObject make_lisp_unsigned128(uint128_t n)
{ if (uint128_valid_as_fixnum(n))
 return fixnum_of_int((uint64_t)NARROW128(n));
 else return make_lisp_unsigned128_fn(n);
}
extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern float128_t float128_of_number(LispObject a);
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern LispObject make_approx_ratio(LispObject p, LispObject q, int bits);
extern "C" LispObject ash(LispObject a, LispObject b);
extern "C" LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);
extern LispObject rationalf128(float128_t *d);
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
#ifdef WIN32
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
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
static int f128M_exponent(const float128_t *p);
static void f128M_set_exponent(float128_t *p, int n);
extern "C" void f128M_ldexp(float128_t *p, int n);
extern "C" void f128M_frexp(float128_t *p, float128_t *r, int *x);
static bool f128M_infinite(const float128_t *p);
static bool f128M_finite(const float128_t *p);
static bool f128M_nan(const float128_t *x);
static bool f128M_subnorm(const float128_t *x);
static bool f128M_negative(const float128_t *x);
static void f128M_negate(float128_t *x);
extern "C" void f128M_split(
 const float128_t *x, float128_t *yhi, float128_t *ylo);
#ifdef LITTLEENDIAN
#define HIPART 1
#define LOPART 0
#else
#define HIPART 0
#define LOPART 1
#endif
static inline bool f128M_zero(const float128_t *p)
{ return ((p->v[HIPART] & INT64_C(0x7fffffffffffffff)) == 0) &&
 (p->v[LOPART] == 0);
}
static inline bool f128M_infinite(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
 ((p->v[HIPART] & INT64_C(0xffffffffffff)) == 0) &&
 (p->v[LOPART] == 0);
}
static inline bool f128M_finite(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) != 0x7fff);
}
static inline void f128M_make_infinite(float128_t *p)
{ p->v[HIPART] |= UINT64_C(0x7fff000000000000);
 p->v[HIPART] &= UINT64_C(0xffff000000000000);
 p->v[LOPART] = 0;
}
static inline void f128M_make_zero(float128_t *p)
{ p->v[HIPART] &= UINT64_C(0x8000000000000000);
 p->v[LOPART] = 0;
}
static inline bool f128M_subnorm(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0) &&
 (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
 (p->v[LOPART] != 0));
}
static inline bool f128M_nan(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
 (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
 (p->v[LOPART] != 0));
}
static inline bool f128M_negative(const float128_t *x)
{ if (f128M_nan(x)) return false;
 return ((int64_t)x->v[HIPART]) < 0;
}
static inline int f128M_exponent(const float128_t *p)
{ return ((p->v[HIPART] >> 48) & 0x7fff) - 0x3fff;
}
static inline void f128M_set_exponent(float128_t *p, int n)
{ p->v[HIPART] = (p->v[HIPART] & INT64_C(0x8000ffffffffffff)) |
 (((uint64_t)n + 0x3fff) << 48);
}
static inline void f128M_negate(float128_t *x)
{ x->v[HIPART] ^= UINT64_C(0x8000000000000000);
}
static inline bool floating_edge_case128(float128_t *r)
{ return f128M_infinite(r) || f128M_nan(r);
}
extern int double_to_binary(double d, int64_t &m);
extern int float128_to_binary(const float128_t *d,
 int64_t &mhi, uint64_t &mlo);
extern intptr_t double_to_3_digits(double d,
 int32_t &a2, uint32_t &a1, uint32_t &a0);
extern intptr_t float128_to_5_digits(float128_t *d,
 int32_t &a4, uint32_t &a3, uint32_t &a2, uint32_t &a1, uint32_t &a0);
extern "C" float128_t f128_0, 
 f128_half, 
 f128_mhalf, 
 f128_1, 
 f128_10, 
 f128_10_17, 
 f128_10_18, 
 f128_r10, 
 f128_N1; 
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
static inline void f128M_to_f256M(const float128_t *a, float256_t *b)
{ b->hi = *a;
 b->lo = f128_0;
} 
extern "C" void f256M_add(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" void f256M_mul(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" void f256M_pow(const float256_t *x, unsigned int y, float256_t *z);
extern "C" float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;
extern "C" int f128M_sprint_E(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_F(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_G(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_print_E(int width, int precision, float128_t *p);
extern "C" int f128M_print_F(int width, int precision, float128_t *p);
extern "C" int f128M_print_G(int width, int precision, float128_t *p);
extern "C" float128_t atof128(const char *s);
#define arith_dispatch_1(stgclass, type, name) \
stgclass type name(LispObject a1) \
{ if (is_fixnum(a1)) return name##_i(a1); \
 switch (a1 & TAG_BITS) \
 { \
 case (XTAG_SFLOAT & TAG_BITS): \
 return name##_s(a1); \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a1))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1); \
 case TYPE_RATNUM: \
 return name##_r(a1); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1); \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a1))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1); \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
}
#define arith_dispatch_1a(stgclass, type, name, rawname) \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a2)) return name##_i(a1, a2); \
 switch (a2 & TAG_BITS) \
 { \
 case (XTAG_SFLOAT & TAG_BITS): \
 return name##_s(a1, a2); \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a2))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1, a2); \
 case TYPE_RATNUM: \
 return name##_r(a1, a2); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1, a2); \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a2))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1, a2); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1, a2); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1, a2); \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
}
#define arith_dispatch_2(stgclass, type, name) \
arith_dispatch_1a(static inline, type, name##_i, name) \
 \
arith_dispatch_1a(static inline, type, name##_b, name) \
 \
arith_dispatch_1a(static inline, type, name##_r, name) \
 \
arith_dispatch_1a(static inline, type, name##_c, name) \
 \
arith_dispatch_1a(static inline, type, name##_s, name) \
 \
arith_dispatch_1a(static inline, type, name##_f, name) \
 \
arith_dispatch_1a(static inline, type, name##_d, name) \
 \
arith_dispatch_1a(static inline, type, name##_l, name) \
 \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a1)) return name##_i(a1, a2); \
 switch (a1 & TAG_BITS) \
 { \
 case (XTAG_SFLOAT & TAG_BITS): \
 return name##_s(a1, a2); \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a1))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1, a2); \
 case TYPE_RATNUM: \
 return name##_r(a1, a2); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1, a2); \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a1))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1, a2); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1, a2); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1, a2); \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
}
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



// Code for assert_analyze

static LispObject CC_assert_analyze(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5922, v_5923;
    LispObject fn;
    argcheck(nargs, 0, "assert_analyze");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// end of prologue
    v_5922 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_5922;
    v_5922 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-4] = v_5922;
    v_5922 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_5922;
    goto v_5655;
v_5651:
    v_5923 = qvalue(elt(env, 2)); // assertstatistics!*
    goto v_5652;
v_5653:
    v_5922 = elt(env, 3); // lambda_46uwl1lq71ua2
    goto v_5654;
v_5655:
    goto v_5651;
v_5652:
    goto v_5653;
v_5654:
    fn = elt(env, 8); // sort
    v_5922 = (*qfn2(fn))(fn, v_5923, v_5922);
    env = stack[-5];
    qvalue(elt(env, 2)) = v_5922; // assertstatistics!*
    v_5922 = qvalue(elt(env, 2)); // assertstatistics!*
    stack[-3] = v_5922;
v_5661:
    v_5922 = stack[-3];
    if (v_5922 == nil) goto v_5665;
    else goto v_5666;
v_5665:
    goto v_5660;
v_5666:
    v_5922 = stack[-3];
    v_5922 = qcar(v_5922);
    stack[-1] = v_5922;
    goto v_5677;
v_5673:
    v_5923 = stack[0];
    goto v_5674;
v_5675:
    v_5922 = stack[-1];
    v_5922 = qcdr(v_5922);
    v_5922 = qcar(v_5922);
    goto v_5676;
v_5677:
    goto v_5673;
v_5674:
    goto v_5675;
v_5676:
    v_5922 = plus2(v_5923, v_5922);
    env = stack[-5];
    stack[0] = v_5922;
    goto v_5687;
v_5683:
    v_5923 = stack[-4];
    goto v_5684;
v_5685:
    v_5922 = stack[-1];
    v_5922 = qcdr(v_5922);
    v_5922 = qcdr(v_5922);
    v_5922 = qcar(v_5922);
    goto v_5686;
v_5687:
    goto v_5683;
v_5684:
    goto v_5685;
v_5686:
    v_5922 = plus2(v_5923, v_5922);
    env = stack[-5];
    stack[-4] = v_5922;
    goto v_5698;
v_5694:
    v_5923 = stack[-2];
    goto v_5695;
v_5696:
    v_5922 = stack[-1];
    v_5922 = qcdr(v_5922);
    v_5922 = qcdr(v_5922);
    v_5922 = qcdr(v_5922);
    v_5922 = qcar(v_5922);
    goto v_5697;
v_5698:
    goto v_5694;
v_5695:
    goto v_5696;
v_5697:
    v_5922 = plus2(v_5923, v_5922);
    env = stack[-5];
    stack[-2] = v_5922;
    v_5922 = stack[-3];
    v_5922 = qcdr(v_5922);
    stack[-3] = v_5922;
    goto v_5661;
v_5660:
    v_5922 = elt(env, 4); // (function !#calls !#bad! calls !#assertion! violations)
    stack[-3] = v_5922;
    goto v_5715;
v_5709:
    stack[-1] = elt(env, 5); // sum
    goto v_5710;
v_5711:
    goto v_5712;
v_5713:
    goto v_5723;
v_5719:
    v_5923 = stack[-4];
    goto v_5720;
v_5721:
    v_5922 = stack[-2];
    goto v_5722;
v_5723:
    goto v_5719;
v_5720:
    goto v_5721;
v_5722:
    v_5922 = list2(v_5923, v_5922);
    env = stack[-5];
    goto v_5714;
v_5715:
    goto v_5709;
v_5710:
    goto v_5711;
v_5712:
    goto v_5713;
v_5714:
    v_5922 = list2star(stack[-1], stack[0], v_5922);
    env = stack[-5];
    goto v_5733;
v_5727:
    stack[-4] = nil;
    goto v_5728;
v_5729:
    goto v_5730;
v_5731:
    goto v_5741;
v_5737:
    stack[-2] = nil;
    goto v_5738;
v_5739:
    goto v_5751;
v_5745:
    stack[-1] = nil;
    goto v_5746;
v_5747:
    stack[0] = v_5922;
    goto v_5748;
v_5749:
    goto v_5759;
v_5755:
    v_5923 = nil;
    goto v_5756;
v_5757:
    v_5922 = qvalue(elt(env, 2)); // assertstatistics!*
    goto v_5758;
v_5759:
    goto v_5755;
v_5756:
    goto v_5757;
v_5758:
    v_5922 = cons(v_5923, v_5922);
    env = stack[-5];
    goto v_5750;
v_5751:
    goto v_5745;
v_5746:
    goto v_5747;
v_5748:
    goto v_5749;
v_5750:
    v_5922 = list2star(stack[-1], stack[0], v_5922);
    env = stack[-5];
    v_5922 = Lnreverse(nil, v_5922);
    env = stack[-5];
    goto v_5740;
v_5741:
    goto v_5737;
v_5738:
    goto v_5739;
v_5740:
    v_5922 = cons(stack[-2], v_5922);
    env = stack[-5];
    goto v_5732;
v_5733:
    goto v_5727;
v_5728:
    goto v_5729;
v_5730:
    goto v_5731;
v_5732:
    v_5922 = list2star(stack[-4], stack[-3], v_5922);
    env = stack[-5];
    qvalue(elt(env, 2)) = v_5922; // assertstatistics!*
    v_5922 = qvalue(elt(env, 2)); // assertstatistics!*
    stack[-2] = v_5922;
v_5765:
    v_5922 = stack[-2];
    if (v_5922 == nil) goto v_5769;
    else goto v_5770;
v_5769:
    goto v_5764;
v_5770:
    v_5922 = stack[-2];
    v_5922 = qcar(v_5922);
    stack[-1] = v_5922;
    v_5922 = stack[-1];
    if (v_5922 == nil) goto v_5779;
    v_5922 = stack[-1];
    v_5922 = qcar(v_5922);
    v_5922 = Lprinc(nil, v_5922);
    env = stack[-5];
    goto v_5793;
v_5789:
    v_5922 = stack[-1];
    v_5922 = qcar(v_5922);
    v_5922 = Lexplodec(nil, v_5922);
    env = stack[-5];
    stack[0] = Llength(nil, v_5922);
    env = stack[-5];
    goto v_5790;
v_5791:
    v_5922 = stack[-1];
    v_5922 = qcdr(v_5922);
    v_5922 = qcar(v_5922);
    v_5922 = Lexplodec(nil, v_5922);
    env = stack[-5];
    v_5922 = Llength(nil, v_5922);
    env = stack[-5];
    goto v_5792;
v_5793:
    goto v_5789;
v_5790:
    goto v_5791;
v_5792:
    v_5922 = plus2(stack[0], v_5922);
    env = stack[-5];
    stack[0] = v_5922;
v_5787:
    goto v_5813;
v_5809:
    v_5923 = (LispObject)368+TAG_FIXNUM; // 23
    goto v_5810;
v_5811:
    v_5922 = stack[0];
    goto v_5812;
v_5813:
    goto v_5809;
v_5810:
    goto v_5811;
v_5812:
    v_5922 = difference2(v_5923, v_5922);
    env = stack[-5];
    v_5922 = Lminusp(nil, v_5922);
    env = stack[-5];
    if (v_5922 == nil) goto v_5806;
    goto v_5786;
v_5806:
    v_5922 = elt(env, 6); // " "
    v_5922 = Lprinc(nil, v_5922);
    env = stack[-5];
    v_5922 = stack[0];
    v_5922 = add1(v_5922);
    env = stack[-5];
    stack[0] = v_5922;
    goto v_5787;
v_5786:
    v_5922 = stack[-1];
    v_5922 = qcdr(v_5922);
    v_5922 = qcar(v_5922);
    v_5922 = Lprinc(nil, v_5922);
    env = stack[-5];
    v_5922 = stack[-1];
    v_5922 = qcdr(v_5922);
    v_5922 = qcdr(v_5922);
    v_5922 = qcar(v_5922);
    v_5922 = Lexplodec(nil, v_5922);
    env = stack[-5];
    v_5922 = Llength(nil, v_5922);
    env = stack[-5];
    stack[0] = v_5922;
v_5828:
    goto v_5845;
v_5841:
    v_5923 = (LispObject)368+TAG_FIXNUM; // 23
    goto v_5842;
v_5843:
    v_5922 = stack[0];
    goto v_5844;
v_5845:
    goto v_5841;
v_5842:
    goto v_5843;
v_5844:
    v_5922 = difference2(v_5923, v_5922);
    env = stack[-5];
    v_5922 = Lminusp(nil, v_5922);
    env = stack[-5];
    if (v_5922 == nil) goto v_5838;
    goto v_5827;
v_5838:
    v_5922 = elt(env, 6); // " "
    v_5922 = Lprinc(nil, v_5922);
    env = stack[-5];
    v_5922 = stack[0];
    v_5922 = add1(v_5922);
    env = stack[-5];
    stack[0] = v_5922;
    goto v_5828;
v_5827:
    v_5922 = stack[-1];
    v_5922 = qcdr(v_5922);
    v_5922 = qcdr(v_5922);
    v_5922 = qcar(v_5922);
    v_5922 = Lprinc(nil, v_5922);
    env = stack[-5];
    v_5922 = stack[-1];
    v_5922 = qcdr(v_5922);
    v_5922 = qcdr(v_5922);
    v_5922 = qcdr(v_5922);
    v_5922 = qcar(v_5922);
    v_5922 = Lexplodec(nil, v_5922);
    env = stack[-5];
    v_5922 = Llength(nil, v_5922);
    env = stack[-5];
    stack[0] = v_5922;
v_5861:
    goto v_5879;
v_5875:
    v_5923 = (LispObject)368+TAG_FIXNUM; // 23
    goto v_5876;
v_5877:
    v_5922 = stack[0];
    goto v_5878;
v_5879:
    goto v_5875;
v_5876:
    goto v_5877;
v_5878:
    v_5922 = difference2(v_5923, v_5922);
    env = stack[-5];
    v_5922 = Lminusp(nil, v_5922);
    env = stack[-5];
    if (v_5922 == nil) goto v_5872;
    goto v_5860;
v_5872:
    v_5922 = elt(env, 6); // " "
    v_5922 = Lprinc(nil, v_5922);
    env = stack[-5];
    v_5922 = stack[0];
    v_5922 = add1(v_5922);
    env = stack[-5];
    stack[0] = v_5922;
    goto v_5861;
v_5860:
    v_5922 = stack[-1];
    v_5922 = qcdr(v_5922);
    v_5922 = qcdr(v_5922);
    v_5922 = qcdr(v_5922);
    v_5922 = qcar(v_5922);
    fn = elt(env, 9); // prin2t
    v_5922 = (*qfn1(fn))(fn, v_5922);
    env = stack[-5];
    goto v_5777;
v_5779:
    v_5922 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_5922;
v_5898:
    goto v_5910;
v_5906:
    v_5923 = (LispObject)1152+TAG_FIXNUM; // 72
    goto v_5907;
v_5908:
    v_5922 = stack[0];
    goto v_5909;
v_5910:
    goto v_5906;
v_5907:
    goto v_5908;
v_5909:
    v_5922 = difference2(v_5923, v_5922);
    env = stack[-5];
    v_5922 = Lminusp(nil, v_5922);
    env = stack[-5];
    if (v_5922 == nil) goto v_5903;
    goto v_5897;
v_5903:
    v_5922 = elt(env, 7); // "-"
    v_5922 = Lprinc(nil, v_5922);
    env = stack[-5];
    v_5922 = stack[0];
    v_5922 = add1(v_5922);
    env = stack[-5];
    stack[0] = v_5922;
    goto v_5898;
v_5897:
    v_5922 = Lterpri(nil, 0);
    env = stack[-5];
    goto v_5777;
v_5777:
    v_5922 = stack[-2];
    v_5922 = qcdr(v_5922);
    stack[-2] = v_5922;
    goto v_5765;
v_5764:
    v_5922 = nil;
    qvalue(elt(env, 2)) = v_5922; // assertstatistics!*
    v_5922 = nil;
    return onevalue(v_5922);
}



// Code for lambda_46uwl1lq71ua2

static LispObject CC_lambda_46uwl1lq71ua2(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5651, v_5652;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5652 = v_5639;
    v_5651 = v_5638;
// end of prologue
    goto v_5646;
v_5642:
    v_5652 = qcar(v_5652);
    goto v_5643;
v_5644:
    v_5651 = qcar(v_5651);
    goto v_5645;
v_5646:
    goto v_5642;
v_5643:
    goto v_5644;
v_5645:
    {
        fn = elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_5652, v_5651);
    }
}



// Code for red_better

static LispObject CC_red_better(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5651;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5639;
    v_5651 = v_5638;
// end of prologue
    goto v_5646;
v_5642:
    fn = elt(env, 1); // bas_dplen
    stack[-1] = (*qfn1(fn))(fn, v_5651);
    env = stack[-2];
    goto v_5643;
v_5644:
    v_5651 = stack[0];
    fn = elt(env, 1); // bas_dplen
    v_5651 = (*qfn1(fn))(fn, v_5651);
    goto v_5645;
v_5646:
    goto v_5642;
v_5643:
    goto v_5644;
v_5645:
    {
        LispObject v_5654 = stack[-1];
        return Llessp(nil, v_5654, v_5651);
    }
}



// Code for oprin

static LispObject CC_oprin(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5701, v_5702;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5638;
// end of prologue
    v_5701 = stack[0];
    if (!symbolp(v_5701)) v_5701 = nil;
    else { v_5701 = qfastgets(v_5701);
           if (v_5701 != nil) { v_5701 = elt(v_5701, 37); // prtch
#ifdef RECORD_GET
             if (v_5701 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v_5701 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v_5701 == SPID_NOPROP) v_5701 = nil; }}
#endif
    stack[-1] = v_5701;
    v_5701 = stack[-1];
    if (v_5701 == nil) goto v_5645;
    else goto v_5646;
v_5645:
    v_5701 = elt(env, 1); // " "
    fn = elt(env, 8); // prin2!*
    v_5701 = (*qfn1(fn))(fn, v_5701);
    env = stack[-2];
    v_5701 = stack[0];
    fn = elt(env, 8); // prin2!*
    v_5701 = (*qfn1(fn))(fn, v_5701);
    env = stack[-2];
    v_5701 = elt(env, 1); // " "
    {
        fn = elt(env, 8); // prin2!*
        return (*qfn1(fn))(fn, v_5701);
    }
v_5646:
    v_5701 = qvalue(elt(env, 2)); // !*fort
    if (v_5701 == nil) goto v_5655;
    v_5701 = stack[-1];
    {
        fn = elt(env, 8); // prin2!*
        return (*qfn1(fn))(fn, v_5701);
    }
v_5655:
    v_5701 = qvalue(elt(env, 3)); // !*list
    if (v_5701 == nil) goto v_5660;
    v_5701 = qvalue(elt(env, 4)); // obrkp!*
    if (v_5701 == nil) goto v_5660;
    goto v_5671;
v_5667:
    v_5702 = stack[0];
    goto v_5668;
v_5669:
    v_5701 = elt(env, 5); // (plus minus)
    goto v_5670;
v_5671:
    goto v_5667;
v_5668:
    goto v_5669;
v_5670:
    v_5701 = Lmemq(nil, v_5702, v_5701);
    if (v_5701 == nil) goto v_5660;
    v_5701 = qvalue(elt(env, 6)); // testing!-width!*
    if (v_5701 == nil) goto v_5678;
    v_5701 = lisp_true;
    qvalue(elt(env, 7)) = v_5701; // overflowed!*
    goto v_5676;
v_5678:
    v_5701 = lisp_true;
    fn = elt(env, 9); // terpri!*
    v_5701 = (*qfn1(fn))(fn, v_5701);
    env = stack[-2];
    v_5701 = stack[-1];
    {
        fn = elt(env, 8); // prin2!*
        return (*qfn1(fn))(fn, v_5701);
    }
    v_5701 = nil;
v_5676:
    goto v_5644;
v_5660:
    v_5701 = stack[0];
    if (!symbolp(v_5701)) v_5701 = nil;
    else { v_5701 = qfastgets(v_5701);
           if (v_5701 != nil) { v_5701 = elt(v_5701, 61); // spaced
#ifdef RECORD_GET
             if (v_5701 == SPID_NOPROP)
                record_get(elt(fastget_names, 61), 0),
                v_5701 = nil;
             else record_get(elt(fastget_names, 61), 1),
                v_5701 = lisp_true; }
           else record_get(elt(fastget_names, 61), 0); }
#else
             if (v_5701 == SPID_NOPROP) v_5701 = nil; else v_5701 = lisp_true; }}
#endif
    if (v_5701 == nil) goto v_5688;
    v_5701 = elt(env, 1); // " "
    fn = elt(env, 8); // prin2!*
    v_5701 = (*qfn1(fn))(fn, v_5701);
    env = stack[-2];
    v_5701 = stack[-1];
    fn = elt(env, 8); // prin2!*
    v_5701 = (*qfn1(fn))(fn, v_5701);
    env = stack[-2];
    v_5701 = elt(env, 1); // " "
    {
        fn = elt(env, 8); // prin2!*
        return (*qfn1(fn))(fn, v_5701);
    }
v_5688:
    v_5701 = stack[-1];
    {
        fn = elt(env, 8); // prin2!*
        return (*qfn1(fn))(fn, v_5701);
    }
    v_5701 = nil;
v_5644:
    return onevalue(v_5701);
}



// Code for !*i2gi

static LispObject CC_Hi2gi(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5651, v_5652, v_5653;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5651 = v_5638;
// end of prologue
    goto v_5647;
v_5641:
    v_5653 = elt(env, 1); // !:gi!:
    goto v_5642;
v_5643:
    v_5652 = v_5651;
    goto v_5644;
v_5645:
    v_5651 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5646;
v_5647:
    goto v_5641;
v_5642:
    goto v_5643;
v_5644:
    goto v_5645;
v_5646:
    return list2star(v_5653, v_5652, v_5651);
}



// Code for split_ext

static LispObject CC_split_ext(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5752, v_5753, v_5754;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    v_5753 = v_5639;
    v_5754 = v_5638;
// end of prologue
    v_5752 = v_5754;
    v_5752 = qcdr(v_5752);
    stack[-7] = v_5752;
    goto v_5653;
v_5649:
    v_5752 = v_5754;
    v_5752 = qcar(v_5752);
    goto v_5650;
v_5651:
    goto v_5652;
v_5653:
    goto v_5649;
v_5650:
    goto v_5651;
v_5652:
    fn = elt(env, 3); // split_form
    v_5752 = (*qfn2(fn))(fn, v_5752, v_5753);
    env = stack[-8];
    stack[0] = v_5752;
    goto v_5664;
v_5658:
    v_5752 = elt(env, 2); // ext
    stack[-6] = ncons(v_5752);
    env = stack[-8];
    goto v_5659;
v_5660:
    goto v_5673;
v_5669:
    v_5752 = stack[0];
    v_5753 = qcar(v_5752);
    goto v_5670;
v_5671:
    v_5752 = stack[-7];
    goto v_5672;
v_5673:
    goto v_5669;
v_5670:
    goto v_5671;
v_5672:
    v_5752 = cons(v_5753, v_5752);
    env = stack[-8];
    fn = elt(env, 4); // cancel
    stack[-5] = (*qfn1(fn))(fn, v_5752);
    env = stack[-8];
    goto v_5661;
v_5662:
    v_5752 = stack[0];
    v_5752 = qcdr(v_5752);
    stack[-4] = v_5752;
    v_5752 = stack[-4];
    if (v_5752 == nil) goto v_5687;
    else goto v_5688;
v_5687:
    v_5752 = nil;
    goto v_5681;
v_5688:
    v_5752 = stack[-4];
    v_5752 = qcar(v_5752);
    v_5753 = v_5752;
    goto v_5700;
v_5696:
    v_5752 = v_5753;
    stack[0] = qcar(v_5752);
    goto v_5697;
v_5698:
    goto v_5709;
v_5705:
    v_5752 = v_5753;
    v_5753 = qcdr(v_5752);
    goto v_5706;
v_5707:
    v_5752 = stack[-7];
    goto v_5708;
v_5709:
    goto v_5705;
v_5706:
    goto v_5707;
v_5708:
    v_5752 = cons(v_5753, v_5752);
    env = stack[-8];
    fn = elt(env, 4); // cancel
    v_5752 = (*qfn1(fn))(fn, v_5752);
    env = stack[-8];
    goto v_5699;
v_5700:
    goto v_5696;
v_5697:
    goto v_5698;
v_5699:
    v_5752 = cons(stack[0], v_5752);
    env = stack[-8];
    v_5752 = ncons(v_5752);
    env = stack[-8];
    stack[-2] = v_5752;
    stack[-3] = v_5752;
v_5682:
    v_5752 = stack[-4];
    v_5752 = qcdr(v_5752);
    stack[-4] = v_5752;
    v_5752 = stack[-4];
    if (v_5752 == nil) goto v_5717;
    else goto v_5718;
v_5717:
    v_5752 = stack[-3];
    goto v_5681;
v_5718:
    goto v_5726;
v_5722:
    stack[-1] = stack[-2];
    goto v_5723;
v_5724:
    v_5752 = stack[-4];
    v_5752 = qcar(v_5752);
    v_5753 = v_5752;
    goto v_5737;
v_5733:
    v_5752 = v_5753;
    stack[0] = qcar(v_5752);
    goto v_5734;
v_5735:
    goto v_5746;
v_5742:
    v_5752 = v_5753;
    v_5753 = qcdr(v_5752);
    goto v_5743;
v_5744:
    v_5752 = stack[-7];
    goto v_5745;
v_5746:
    goto v_5742;
v_5743:
    goto v_5744;
v_5745:
    v_5752 = cons(v_5753, v_5752);
    env = stack[-8];
    fn = elt(env, 4); // cancel
    v_5752 = (*qfn1(fn))(fn, v_5752);
    env = stack[-8];
    goto v_5736;
v_5737:
    goto v_5733;
v_5734:
    goto v_5735;
v_5736:
    v_5752 = cons(stack[0], v_5752);
    env = stack[-8];
    v_5752 = ncons(v_5752);
    env = stack[-8];
    goto v_5725;
v_5726:
    goto v_5722;
v_5723:
    goto v_5724;
v_5725:
    v_5752 = Lrplacd(nil, stack[-1], v_5752);
    env = stack[-8];
    v_5752 = stack[-2];
    v_5752 = qcdr(v_5752);
    stack[-2] = v_5752;
    goto v_5682;
v_5681:
    goto v_5663;
v_5664:
    goto v_5658;
v_5659:
    goto v_5660;
v_5661:
    goto v_5662;
v_5663:
    {
        LispObject v_5763 = stack[-6];
        LispObject v_5764 = stack[-5];
        return acons(v_5763, v_5764, v_5752);
    }
    return onevalue(v_5752);
}



// Code for portable_print

static LispObject CC_portable_print(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5644;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5638;
// end of prologue
    v_5644 = stack[0];
    fn = elt(env, 1); // portable_prin
    v_5644 = (*qfn1(fn))(fn, v_5644);
    env = stack[-1];
    v_5644 = Lterpri(nil, 0);
    v_5644 = stack[0];
    return onevalue(v_5644);
}



// Code for formc

static LispObject CC_formc(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5716, v_5717, v_5718, v_5719;
    LispObject fn;
    LispObject v_5640, v_5639, v_5638;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formc");
    va_start(aa, nargs);
    v_5638 = va_arg(aa, LispObject);
    v_5639 = va_arg(aa, LispObject);
    v_5640 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_5640,v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_5638,v_5639,v_5640);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_5640;
    stack[-1] = v_5639;
    stack[-2] = v_5638;
// end of prologue
    v_5716 = qvalue(elt(env, 1)); // !*rlisp88
    if (v_5716 == nil) goto v_5645;
    goto v_5655;
v_5651:
    v_5717 = stack[-2];
    goto v_5652;
v_5653:
    v_5716 = elt(env, 2); // modefn
    goto v_5654;
v_5655:
    goto v_5651;
v_5652:
    goto v_5653;
v_5654:
    v_5716 = Lflagpcar(nil, v_5717, v_5716);
    env = stack[-3];
    if (v_5716 == nil) goto v_5645;
    goto v_5663;
v_5659:
    v_5716 = stack[-2];
    v_5717 = qcar(v_5716);
    goto v_5660;
v_5661:
    v_5716 = elt(env, 3); // symbolic
    goto v_5662;
v_5663:
    goto v_5659;
v_5660:
    goto v_5661;
v_5662:
    if (v_5717 == v_5716) goto v_5645;
    goto v_5672;
v_5668:
    v_5717 = elt(env, 4); // "algebraic expression"
    goto v_5669;
v_5670:
    v_5716 = elt(env, 5); // "Rlisp88 form"
    goto v_5671;
v_5672:
    goto v_5668;
v_5669:
    goto v_5670;
v_5671:
    {
        fn = elt(env, 7); // typerr
        return (*qfn2(fn))(fn, v_5717, v_5716);
    }
v_5645:
    goto v_5685;
v_5681:
    v_5717 = stack[0];
    goto v_5682;
v_5683:
    v_5716 = elt(env, 6); // algebraic
    goto v_5684;
v_5685:
    goto v_5681;
v_5682:
    goto v_5683;
v_5684:
    if (v_5717 == v_5716) goto v_5679;
    else goto v_5680;
v_5679:
    goto v_5693;
v_5689:
    v_5717 = stack[-2];
    goto v_5690;
v_5691:
    v_5716 = stack[-1];
    goto v_5692;
v_5693:
    goto v_5689;
v_5690:
    goto v_5691;
v_5692:
    fn = elt(env, 8); // intexprnp
    v_5716 = (*qfn2(fn))(fn, v_5717, v_5716);
    env = stack[-3];
    goto v_5678;
v_5680:
    v_5716 = nil;
    goto v_5678;
    v_5716 = nil;
v_5678:
    if (v_5716 == nil) goto v_5676;
    v_5716 = stack[-2];
    goto v_5643;
v_5676:
    goto v_5711;
v_5703:
    v_5719 = stack[-2];
    goto v_5704;
v_5705:
    v_5718 = stack[-1];
    goto v_5706;
v_5707:
    v_5717 = elt(env, 3); // symbolic
    goto v_5708;
v_5709:
    v_5716 = stack[0];
    goto v_5710;
v_5711:
    goto v_5703;
v_5704:
    goto v_5705;
v_5706:
    goto v_5707;
v_5708:
    goto v_5709;
v_5710:
    {
        fn = elt(env, 9); // convertmode
        return (*qfnn(fn))(fn, 4, v_5719, v_5718, v_5717, v_5716);
    }
    v_5716 = nil;
v_5643:
    return onevalue(v_5716);
}



// Code for talp_simplt1

static LispObject CC_talp_simplt1(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5860, v_5861;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_5639;
    stack[0] = v_5638;
// end of prologue
v_5637:
    v_5860 = stack[0];
    fn = elt(env, 2); // talp_invp
    v_5860 = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    if (v_5860 == nil) goto v_5648;
    v_5860 = stack[0];
    fn = elt(env, 3); // talp_invarg
    v_5860 = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    stack[-2] = v_5860;
    v_5860 = stack[-2];
    if (!consp(v_5860)) goto v_5659;
    else goto v_5660;
v_5659:
    goto v_5666;
v_5662:
    stack[-1] = stack[-2];
    goto v_5663;
v_5664:
    fn = elt(env, 4); // talp_getl
    v_5860 = (*qfnn(fn))(fn, 0);
    env = stack[-6];
    goto v_5665;
v_5666:
    goto v_5662;
v_5663:
    goto v_5664;
v_5665:
    v_5860 = Latsoc(nil, stack[-1], v_5860);
    v_5860 = (v_5860 == nil ? lisp_true : nil);
    goto v_5658;
v_5660:
    v_5860 = nil;
    goto v_5658;
    v_5860 = nil;
v_5658:
    if (v_5860 == nil) goto v_5656;
    v_5860 = stack[-4];
    if (v_5860 == nil) goto v_5677;
v_5681:
    v_5860 = stack[-4];
    if (v_5860 == nil) goto v_5684;
    else goto v_5685;
v_5684:
    goto v_5680;
v_5685:
    goto v_5693;
v_5689:
    v_5860 = stack[-4];
    fn = elt(env, 5); // stack_top
    v_5861 = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    goto v_5690;
v_5691:
    v_5860 = stack[0];
    goto v_5692;
v_5693:
    goto v_5689;
v_5690:
    goto v_5691;
v_5692:
    fn = elt(env, 6); // talp_mkinv
    v_5860 = (*qfn2(fn))(fn, v_5861, v_5860);
    env = stack[-6];
    stack[0] = v_5860;
    v_5860 = stack[-4];
    fn = elt(env, 7); // stack_pop
    v_5860 = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    stack[-4] = v_5860;
    goto v_5681;
v_5680:
    goto v_5675;
v_5677:
v_5675:
    v_5860 = stack[0];
    goto v_5643;
v_5656:
    v_5860 = stack[-2];
    fn = elt(env, 2); // talp_invp
    v_5860 = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    if (v_5860 == nil) goto v_5701;
    goto v_5709;
v_5705:
    stack[-1] = stack[-2];
    goto v_5706;
v_5707:
    goto v_5716;
v_5712:
    v_5860 = stack[0];
    fn = elt(env, 8); // talp_op
    v_5861 = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    goto v_5713;
v_5714:
    v_5860 = stack[-4];
    goto v_5715;
v_5716:
    goto v_5712;
v_5713:
    goto v_5714;
v_5715:
    fn = elt(env, 9); // stack_push
    v_5860 = (*qfn2(fn))(fn, v_5861, v_5860);
    env = stack[-6];
    goto v_5708;
v_5709:
    goto v_5705;
v_5706:
    goto v_5707;
v_5708:
    stack[0] = stack[-1];
    stack[-4] = v_5860;
    goto v_5637;
v_5701:
    goto v_5727;
v_5723:
    stack[-1] = stack[-2];
    goto v_5724;
v_5725:
    v_5860 = stack[0];
    fn = elt(env, 10); // talp_invf
    v_5860 = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    goto v_5726;
v_5727:
    goto v_5723;
v_5724:
    goto v_5725;
v_5726:
    if (!consp(stack[-1])) goto v_5721;
    stack[-1] = qcar(stack[-1]);
    if (stack[-1] == v_5860) goto v_5720;
    else goto v_5721;
v_5720:
    goto v_5736;
v_5732:
    goto v_5742;
v_5738:
    v_5860 = stack[-2];
    fn = elt(env, 11); // talp_fargl
    stack[-1] = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    goto v_5739;
v_5740:
    v_5860 = stack[0];
    fn = elt(env, 12); // talp_invn
    v_5860 = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    goto v_5741;
v_5742:
    goto v_5738;
v_5739:
    goto v_5740;
v_5741:
    fn = elt(env, 13); // nth
    v_5861 = (*qfn2(fn))(fn, stack[-1], v_5860);
    env = stack[-6];
    goto v_5733;
v_5734:
    v_5860 = stack[-4];
    goto v_5735;
v_5736:
    goto v_5732;
v_5733:
    goto v_5734;
v_5735:
    stack[0] = v_5861;
    stack[-4] = v_5860;
    goto v_5637;
v_5721:
    goto v_5755;
v_5751:
    v_5861 = stack[-2];
    goto v_5752;
v_5753:
    v_5860 = stack[-4];
    goto v_5754;
v_5755:
    goto v_5751;
v_5752:
    goto v_5753;
v_5754:
    stack[0] = v_5861;
    stack[-4] = v_5860;
    goto v_5637;
    goto v_5646;
v_5648:
    v_5860 = stack[0];
    v_5860 = Lconsp(nil, v_5860);
    env = stack[-6];
    if (v_5860 == nil) goto v_5763;
    goto v_5771;
v_5767:
    v_5860 = stack[0];
    fn = elt(env, 14); // talp_fop
    stack[-5] = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    goto v_5768;
v_5769:
    v_5860 = stack[0];
    fn = elt(env, 11); // talp_fargl
    v_5860 = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    stack[-3] = v_5860;
    v_5860 = stack[-3];
    if (v_5860 == nil) goto v_5784;
    else goto v_5785;
v_5784:
    v_5860 = nil;
    goto v_5778;
v_5785:
    v_5860 = stack[-3];
    v_5860 = qcar(v_5860);
    goto v_5797;
v_5793:
    v_5861 = v_5860;
    goto v_5794;
v_5795:
    v_5860 = nil;
    goto v_5796;
v_5797:
    goto v_5793;
v_5794:
    goto v_5795;
v_5796:
    v_5860 = CC_talp_simplt1(elt(env, 0), v_5861, v_5860);
    env = stack[-6];
    v_5860 = ncons(v_5860);
    env = stack[-6];
    stack[-1] = v_5860;
    stack[-2] = v_5860;
v_5779:
    v_5860 = stack[-3];
    v_5860 = qcdr(v_5860);
    stack[-3] = v_5860;
    v_5860 = stack[-3];
    if (v_5860 == nil) goto v_5804;
    else goto v_5805;
v_5804:
    v_5860 = stack[-2];
    goto v_5778;
v_5805:
    goto v_5813;
v_5809:
    stack[0] = stack[-1];
    goto v_5810;
v_5811:
    v_5860 = stack[-3];
    v_5860 = qcar(v_5860);
    goto v_5824;
v_5820:
    v_5861 = v_5860;
    goto v_5821;
v_5822:
    v_5860 = nil;
    goto v_5823;
v_5824:
    goto v_5820;
v_5821:
    goto v_5822;
v_5823:
    v_5860 = CC_talp_simplt1(elt(env, 0), v_5861, v_5860);
    env = stack[-6];
    v_5860 = ncons(v_5860);
    env = stack[-6];
    goto v_5812;
v_5813:
    goto v_5809;
v_5810:
    goto v_5811;
v_5812:
    v_5860 = Lrplacd(nil, stack[0], v_5860);
    env = stack[-6];
    v_5860 = stack[-1];
    v_5860 = qcdr(v_5860);
    stack[-1] = v_5860;
    goto v_5779;
v_5778:
    goto v_5770;
v_5771:
    goto v_5767;
v_5768:
    goto v_5769;
v_5770:
    v_5860 = cons(stack[-5], v_5860);
    env = stack[-6];
    stack[0] = v_5860;
    goto v_5761;
v_5763:
v_5761:
    v_5860 = stack[-4];
    if (v_5860 == nil) goto v_5832;
    goto v_5839;
v_5835:
    goto v_5845;
v_5841:
    v_5860 = stack[-4];
    fn = elt(env, 5); // stack_top
    v_5861 = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    goto v_5842;
v_5843:
    v_5860 = stack[0];
    goto v_5844;
v_5845:
    goto v_5841;
v_5842:
    goto v_5843;
v_5844:
    fn = elt(env, 6); // talp_mkinv
    stack[0] = (*qfn2(fn))(fn, v_5861, v_5860);
    env = stack[-6];
    goto v_5836;
v_5837:
    v_5860 = stack[-4];
    fn = elt(env, 7); // stack_pop
    v_5860 = (*qfn1(fn))(fn, v_5860);
    env = stack[-6];
    goto v_5838;
v_5839:
    goto v_5835;
v_5836:
    goto v_5837;
v_5838:
    stack[-4] = v_5860;
    goto v_5637;
v_5832:
    v_5860 = stack[0];
    fn = elt(env, 2); // talp_invp
    v_5860 = (*qfn1(fn))(fn, v_5860);
    if (v_5860 == nil) goto v_5852;
    v_5860 = stack[0];
    v_5860 = qcar(v_5860);
    goto v_5643;
v_5852:
    v_5860 = stack[0];
    goto v_5643;
    goto v_5646;
v_5646:
    v_5860 = nil;
v_5643:
    return onevalue(v_5860);
}



// Code for mri_2pasfat

static LispObject CC_mri_2pasfat(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5653, v_5654;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5638;
// end of prologue
    goto v_5647;
v_5641:
    v_5653 = stack[0];
    fn = elt(env, 1); // mri_op
    stack[-1] = (*qfn1(fn))(fn, v_5653);
    env = stack[-2];
    goto v_5642;
v_5643:
    v_5653 = stack[0];
    fn = elt(env, 2); // mri_arg2l
    v_5654 = (*qfn1(fn))(fn, v_5653);
    goto v_5644;
v_5645:
    v_5653 = nil;
    goto v_5646;
v_5647:
    goto v_5641;
v_5642:
    goto v_5643;
v_5644:
    goto v_5645;
v_5646:
    {
        LispObject v_5657 = stack[-1];
        return list3(v_5657, v_5654, v_5653);
    }
}



// Code for ibalp_vequal

static LispObject CC_ibalp_vequal(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5651, v_5652;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5651 = v_5639;
    v_5652 = v_5638;
// end of prologue
    goto v_5645;
v_5641:
    v_5652 = qcar(v_5652);
    goto v_5642;
v_5643:
    v_5651 = qcar(v_5651);
    goto v_5644;
v_5645:
    goto v_5641;
v_5642:
    goto v_5643;
v_5644:
    v_5651 = (v_5652 == v_5651 ? lisp_true : nil);
    return onevalue(v_5651);
}



// Code for vdp_zero!?

static LispObject CC_vdp_zeroW(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5643;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
// copy arguments values to proper place
    v_5643 = v_5638;
// end of prologue
    fn = elt(env, 1); // vdp_poly
    v_5643 = (*qfn1(fn))(fn, v_5643);
    v_5643 = (v_5643 == nil ? lisp_true : nil);
    return onevalue(v_5643);
}



// Code for objectom

static LispObject CC_objectom(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5685, v_5686, v_5687;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_5686 = v_5638;
// end of prologue
    v_5685 = v_5686;
    v_5685 = Lconsp(nil, v_5685);
    env = stack[-1];
    if (v_5685 == nil) goto v_5647;
    goto v_5658;
v_5654:
    v_5685 = v_5686;
    v_5687 = qcar(v_5685);
    goto v_5655;
v_5656:
    v_5685 = qvalue(elt(env, 2)); // ir2mml!*
    goto v_5657;
v_5658:
    goto v_5654;
v_5655:
    goto v_5656;
v_5657:
    v_5685 = Lassoc(nil, v_5687, v_5685);
    v_5687 = v_5685;
    if (v_5685 == nil) goto v_5653;
    goto v_5668;
v_5664:
    v_5685 = v_5687;
    v_5685 = qcdr(v_5685);
    v_5685 = qcdr(v_5685);
    v_5685 = qcdr(v_5685);
    stack[0] = qcar(v_5685);
    goto v_5665;
v_5666:
    v_5685 = v_5686;
    v_5685 = ncons(v_5685);
    env = stack[-1];
    goto v_5667;
v_5668:
    goto v_5664;
v_5665:
    goto v_5666;
v_5667:
    fn = elt(env, 3); // apply
    v_5685 = (*qfn2(fn))(fn, stack[0], v_5685);
    goto v_5651;
v_5653:
    v_5685 = v_5686;
    fn = elt(env, 4); // fnom
    v_5685 = (*qfn1(fn))(fn, v_5685);
    goto v_5651;
v_5651:
    goto v_5645;
v_5647:
    v_5685 = v_5686;
    fn = elt(env, 5); // basicom
    v_5685 = (*qfn1(fn))(fn, v_5685);
    goto v_5645;
v_5645:
    v_5685 = nil;
    return onevalue(v_5685);
}



// Code for bcone!?

static LispObject CC_bconeW(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5679, v_5680, v_5681;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5680 = v_5638;
// end of prologue
    v_5679 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_5679 == nil) goto v_5643;
    goto v_5650;
v_5646:
    goto v_5647;
v_5648:
    v_5679 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5649;
v_5650:
    goto v_5646;
v_5647:
    goto v_5648;
v_5649:
        return Leqn(nil, v_5680, v_5679);
v_5643:
    goto v_5663;
v_5659:
    v_5679 = v_5680;
    v_5681 = qcdr(v_5679);
    goto v_5660;
v_5661:
    v_5679 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5662;
v_5663:
    goto v_5659;
v_5660:
    goto v_5661;
v_5662:
    if (v_5681 == v_5679) goto v_5657;
    else goto v_5658;
v_5657:
    goto v_5671;
v_5667:
    v_5679 = v_5680;
    v_5680 = qcar(v_5679);
    goto v_5668;
v_5669:
    v_5679 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5670;
v_5671:
    goto v_5667;
v_5668:
    goto v_5669;
v_5670:
    v_5679 = (v_5680 == v_5679 ? lisp_true : nil);
    goto v_5656;
v_5658:
    v_5679 = nil;
    goto v_5656;
    v_5679 = nil;
v_5656:
    goto v_5641;
    v_5679 = nil;
v_5641:
    return onevalue(v_5679);
}



// Code for contrsp

static LispObject CC_contrsp(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5676, v_5677, v_5678;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5639;
    stack[-1] = v_5638;
// end of prologue
    goto v_5651;
v_5645:
    v_5676 = stack[-1];
    v_5676 = qcdr(v_5676);
    v_5678 = qcar(v_5676);
    goto v_5646;
v_5647:
    v_5676 = stack[-1];
    v_5676 = qcdr(v_5676);
    v_5676 = qcdr(v_5676);
    v_5677 = qcar(v_5676);
    goto v_5648;
v_5649:
    v_5676 = stack[0];
    goto v_5650;
v_5651:
    goto v_5645;
v_5646:
    goto v_5647;
v_5648:
    goto v_5649;
v_5650:
    fn = elt(env, 1); // contrsp2
    v_5676 = (*qfnn(fn))(fn, 3, v_5678, v_5677, v_5676);
    env = stack[-2];
    if (v_5676 == nil) goto v_5643;
    else goto v_5642;
v_5643:
    goto v_5667;
v_5661:
    v_5676 = stack[-1];
    v_5676 = qcdr(v_5676);
    v_5676 = qcdr(v_5676);
    v_5678 = qcar(v_5676);
    goto v_5662;
v_5663:
    v_5676 = stack[-1];
    v_5676 = qcdr(v_5676);
    v_5677 = qcar(v_5676);
    goto v_5664;
v_5665:
    v_5676 = stack[0];
    goto v_5666;
v_5667:
    goto v_5661;
v_5662:
    goto v_5663;
v_5664:
    goto v_5665;
v_5666:
    {
        fn = elt(env, 1); // contrsp2
        return (*qfnn(fn))(fn, 3, v_5678, v_5677, v_5676);
    }
v_5642:
    return onevalue(v_5676);
}



// Code for lispapply

static LispObject CC_lispapply(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5674, v_5675, v_5676;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_5675 = v_5639;
    v_5676 = v_5638;
// end of prologue
    v_5674 = v_5676;
    if (!consp(v_5674)) goto v_5644;
    goto v_5653;
v_5647:
    stack[-1] = elt(env, 1); // rlisp
    goto v_5648;
v_5649:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_5650;
v_5651:
    goto v_5661;
v_5657:
    v_5674 = elt(env, 2); // "Apply called with non-id arg"
    goto v_5658;
v_5659:
    v_5675 = v_5676;
    goto v_5660;
v_5661:
    goto v_5657;
v_5658:
    goto v_5659;
v_5660:
    v_5674 = list2(v_5674, v_5675);
    env = stack[-2];
    goto v_5652;
v_5653:
    goto v_5647;
v_5648:
    goto v_5649;
v_5650:
    goto v_5651;
v_5652:
    {
        LispObject v_5679 = stack[-1];
        LispObject v_5680 = stack[0];
        fn = elt(env, 3); // rerror
        return (*qfnn(fn))(fn, 3, v_5679, v_5680, v_5674);
    }
v_5644:
    goto v_5671;
v_5667:
    v_5674 = v_5676;
    goto v_5668;
v_5669:
    goto v_5670;
v_5671:
    goto v_5667;
v_5668:
    goto v_5669;
v_5670:
    {
        fn = elt(env, 4); // apply
        return (*qfn2(fn))(fn, v_5674, v_5675);
    }
    v_5674 = nil;
    return onevalue(v_5674);
}



// Code for ord

static LispObject CC_ord(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5664, v_5665, v_5666;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5666 = v_5638;
// end of prologue
    goto v_5648;
v_5644:
    v_5665 = qvalue(elt(env, 1)); // ordering
    goto v_5645;
v_5646:
    v_5664 = elt(env, 2); // lex
    goto v_5647;
v_5648:
    goto v_5644;
v_5645:
    goto v_5646;
v_5647:
    if (v_5665 == v_5664) goto v_5642;
    else goto v_5643;
v_5642:
    goto v_5657;
v_5653:
    v_5664 = elt(env, 3); // plus
    goto v_5654;
v_5655:
    v_5665 = v_5666;
    goto v_5656;
v_5657:
    goto v_5653;
v_5654:
    goto v_5655;
v_5656:
    v_5664 = cons(v_5664, v_5665);
    env = stack[0];
    {
        fn = elt(env, 4); // eval
        return (*qfn1(fn))(fn, v_5664);
    }
v_5643:
    v_5664 = v_5666;
    v_5664 = qcar(v_5664);
    goto v_5641;
    v_5664 = nil;
v_5641:
    return onevalue(v_5664);
}



// Code for th_match0

static LispObject CC_th_match0(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5671, v_5672, v_5673;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5639;
    v_5673 = v_5638;
// end of prologue
    goto v_5649;
v_5645:
    v_5671 = v_5673;
    v_5672 = qcar(v_5671);
    goto v_5646;
v_5647:
    v_5671 = stack[0];
    v_5671 = qcar(v_5671);
    goto v_5648;
v_5649:
    goto v_5645;
v_5646:
    goto v_5647;
v_5648:
    if (equal(v_5672, v_5671)) goto v_5643;
    else goto v_5644;
v_5643:
    goto v_5658;
v_5654:
    v_5671 = v_5673;
    v_5671 = qcdr(v_5671);
    v_5671 = qcar(v_5671);
    stack[-1] = Llength(nil, v_5671);
    env = stack[-2];
    goto v_5655;
v_5656:
    v_5671 = stack[0];
    v_5671 = qcdr(v_5671);
    v_5671 = qcar(v_5671);
    v_5671 = Llength(nil, v_5671);
    goto v_5657;
v_5658:
    goto v_5654;
v_5655:
    goto v_5656;
v_5657:
    v_5671 = (equal(stack[-1], v_5671) ? lisp_true : nil);
    goto v_5642;
v_5644:
    v_5671 = nil;
    goto v_5642;
    v_5671 = nil;
v_5642:
    return onevalue(v_5671);
}



// Code for exptf

static LispObject CC_exptf(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5711, v_5712, v_5713;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5639;
    stack[-1] = v_5638;
// end of prologue
    goto v_5650;
v_5646:
    v_5712 = stack[0];
    goto v_5647;
v_5648:
    v_5711 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5649;
v_5650:
    goto v_5646;
v_5647:
    goto v_5648;
v_5649:
    v_5711 = (LispObject)lessp2(v_5712, v_5711);
    v_5711 = v_5711 ? lisp_true : nil;
    env = stack[-2];
    if (v_5711 == nil) goto v_5644;
    goto v_5661;
v_5655:
    v_5713 = elt(env, 1); // "exptf"
    goto v_5656;
v_5657:
    v_5712 = stack[-1];
    goto v_5658;
v_5659:
    v_5711 = stack[0];
    goto v_5660;
v_5661:
    goto v_5655;
v_5656:
    goto v_5657;
v_5658:
    goto v_5659;
v_5660:
    v_5711 = list3(v_5713, v_5712, v_5711);
    env = stack[-2];
    {
        fn = elt(env, 3); // errach
        return (*qfn1(fn))(fn, v_5711);
    }
v_5644:
    v_5711 = stack[-1];
    if (!consp(v_5711)) goto v_5669;
    else goto v_5670;
v_5669:
    v_5711 = lisp_true;
    goto v_5668;
v_5670:
    v_5711 = stack[-1];
    v_5711 = qcar(v_5711);
    v_5711 = (consp(v_5711) ? nil : lisp_true);
    goto v_5668;
    v_5711 = nil;
v_5668:
    if (v_5711 == nil) goto v_5666;
    goto v_5683;
v_5679:
    v_5712 = stack[-1];
    goto v_5680;
v_5681:
    v_5711 = stack[0];
    goto v_5682;
v_5683:
    goto v_5679;
v_5680:
    goto v_5681;
v_5682:
    {
        fn = elt(env, 4); // !:expt
        return (*qfn2(fn))(fn, v_5712, v_5711);
    }
v_5666:
    v_5711 = qvalue(elt(env, 2)); // !*exp
    if (v_5711 == nil) goto v_5688;
    else goto v_5686;
v_5688:
    v_5711 = stack[-1];
    fn = elt(env, 5); // kernlp
    v_5711 = (*qfn1(fn))(fn, v_5711);
    env = stack[-2];
    if (v_5711 == nil) goto v_5690;
    else goto v_5686;
v_5690:
    goto v_5687;
v_5686:
    goto v_5698;
v_5694:
    v_5712 = stack[-1];
    goto v_5695;
v_5696:
    v_5711 = stack[0];
    goto v_5697;
v_5698:
    goto v_5694;
v_5695:
    goto v_5696;
v_5697:
    {
        fn = elt(env, 6); // exptf1
        return (*qfn2(fn))(fn, v_5712, v_5711);
    }
v_5687:
    goto v_5708;
v_5704:
    v_5712 = stack[-1];
    goto v_5705;
v_5706:
    v_5711 = stack[0];
    goto v_5707;
v_5708:
    goto v_5704;
v_5705:
    goto v_5706;
v_5707:
    {
        fn = elt(env, 7); // mksfpf
        return (*qfn2(fn))(fn, v_5712, v_5711);
    }
    v_5711 = nil;
    return onevalue(v_5711);
}



// Code for lalr_list_of_actions

static LispObject CC_lalr_list_of_actions(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5828, v_5829, v_5830;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_5638;
// end of prologue
    stack[-6] = nil;
    v_5828 = stack[-5];
    v_5828 = qcar(v_5828);
    stack[-2] = v_5828;
v_5653:
    v_5828 = stack[-2];
    if (v_5828 == nil) goto v_5658;
    else goto v_5659;
v_5658:
    goto v_5652;
v_5659:
    v_5828 = stack[-2];
    v_5828 = qcar(v_5828);
    stack[0] = v_5828;
    v_5828 = stack[0];
    v_5828 = qcar(v_5828);
    v_5828 = qcar(v_5828);
    stack[-3] = v_5828;
    goto v_5672;
v_5668:
    v_5829 = elt(env, 2); // !.
    goto v_5669;
v_5670:
    v_5828 = stack[0];
    v_5828 = qcar(v_5828);
    goto v_5671;
v_5672:
    goto v_5668;
v_5669:
    goto v_5670;
v_5671:
    v_5828 = Lmember(nil, v_5829, v_5828);
    v_5828 = qcdr(v_5828);
    stack[-1] = v_5828;
    v_5828 = stack[-1];
    if (v_5828 == nil) goto v_5681;
    v_5828 = stack[-1];
    v_5828 = qcar(v_5828);
    if (is_number(v_5828)) goto v_5684;
    else goto v_5681;
v_5684:
    v_5828 = stack[-1];
    v_5828 = qcar(v_5828);
    stack[0] = v_5828;
    goto v_5694;
v_5690:
    v_5829 = stack[-5];
    goto v_5691;
v_5692:
    v_5828 = stack[0];
    goto v_5693;
v_5694:
    goto v_5690;
v_5691:
    goto v_5692;
v_5693:
    fn = elt(env, 7); // lalr_goto
    v_5828 = (*qfn2(fn))(fn, v_5829, v_5828);
    env = stack[-7];
    v_5828 = qcdr(v_5828);
    goto v_5703;
v_5699:
    goto v_5709;
v_5705:
    goto v_5706;
v_5707:
    goto v_5716;
v_5712:
    v_5829 = elt(env, 3); // shift
    goto v_5713;
v_5714:
    goto v_5715;
v_5716:
    goto v_5712;
v_5713:
    goto v_5714;
v_5715:
    v_5828 = list2(v_5829, v_5828);
    env = stack[-7];
    goto v_5708;
v_5709:
    goto v_5705;
v_5706:
    goto v_5707;
v_5708:
    v_5829 = list2(stack[0], v_5828);
    env = stack[-7];
    goto v_5700;
v_5701:
    v_5828 = stack[-6];
    goto v_5702;
v_5703:
    goto v_5699;
v_5700:
    goto v_5701;
v_5702:
    v_5828 = cons(v_5829, v_5828);
    env = stack[-7];
    stack[-6] = v_5828;
    goto v_5679;
v_5681:
    v_5828 = stack[-1];
    if (v_5828 == nil) goto v_5724;
    else goto v_5725;
v_5724:
    goto v_5732;
v_5728:
    v_5829 = stack[-3];
    goto v_5729;
v_5730:
    v_5828 = elt(env, 4); // !S!'
    goto v_5731;
v_5732:
    goto v_5728;
v_5729:
    goto v_5730;
v_5731:
    v_5828 = Lneq(nil, v_5829, v_5828);
    env = stack[-7];
    goto v_5723;
v_5725:
    v_5828 = nil;
    goto v_5723;
    v_5828 = nil;
v_5723:
    if (v_5828 == nil) goto v_5721;
    goto v_5743;
v_5739:
    v_5829 = elt(env, 2); // !.
    goto v_5740;
v_5741:
    v_5828 = stack[0];
    v_5828 = qcar(v_5828);
    goto v_5742;
v_5743:
    goto v_5739;
v_5740:
    goto v_5741;
v_5742:
    v_5828 = Ldeleq(nil, v_5829, v_5828);
    env = stack[-7];
    stack[-4] = v_5828;
    v_5828 = stack[-4];
    fn = elt(env, 8); // lalr_reduction_index
    v_5828 = (*qfn1(fn))(fn, v_5828);
    env = stack[-7];
    stack[-3] = v_5828;
    v_5828 = stack[0];
    v_5828 = qcdr(v_5828);
    stack[-1] = v_5828;
v_5752:
    v_5828 = stack[-1];
    if (v_5828 == nil) goto v_5757;
    else goto v_5758;
v_5757:
    goto v_5751;
v_5758:
    v_5828 = stack[-1];
    v_5828 = qcar(v_5828);
    goto v_5769;
v_5765:
    goto v_5775;
v_5771:
    stack[0] = v_5828;
    goto v_5772;
v_5773:
    goto v_5784;
v_5778:
    v_5830 = elt(env, 5); // reduce
    goto v_5779;
v_5780:
    v_5829 = stack[-4];
    goto v_5781;
v_5782:
    v_5828 = stack[-3];
    goto v_5783;
v_5784:
    goto v_5778;
v_5779:
    goto v_5780;
v_5781:
    goto v_5782;
v_5783:
    v_5828 = list3(v_5830, v_5829, v_5828);
    env = stack[-7];
    goto v_5774;
v_5775:
    goto v_5771;
v_5772:
    goto v_5773;
v_5774:
    v_5829 = list2(stack[0], v_5828);
    env = stack[-7];
    goto v_5766;
v_5767:
    v_5828 = stack[-6];
    goto v_5768;
v_5769:
    goto v_5765;
v_5766:
    goto v_5767;
v_5768:
    v_5828 = cons(v_5829, v_5828);
    env = stack[-7];
    stack[-6] = v_5828;
    v_5828 = stack[-1];
    v_5828 = qcdr(v_5828);
    stack[-1] = v_5828;
    goto v_5752;
v_5751:
    goto v_5679;
v_5721:
    v_5828 = stack[-1];
    if (v_5828 == nil) goto v_5795;
    else goto v_5796;
v_5795:
    goto v_5802;
v_5798:
    v_5829 = stack[-3];
    goto v_5799;
v_5800:
    v_5828 = elt(env, 4); // !S!'
    goto v_5801;
v_5802:
    goto v_5798;
v_5799:
    goto v_5800;
v_5801:
    v_5828 = (v_5829 == v_5828 ? lisp_true : nil);
    goto v_5794;
v_5796:
    v_5828 = nil;
    goto v_5794;
    v_5828 = nil;
v_5794:
    if (v_5828 == nil) goto v_5792;
    goto v_5814;
v_5810:
    goto v_5820;
v_5816:
    v_5829 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5817;
v_5818:
    v_5828 = elt(env, 6); // (accept)
    goto v_5819;
v_5820:
    goto v_5816;
v_5817:
    goto v_5818;
v_5819:
    v_5829 = list2(v_5829, v_5828);
    env = stack[-7];
    goto v_5811;
v_5812:
    v_5828 = stack[-6];
    goto v_5813;
v_5814:
    goto v_5810;
v_5811:
    goto v_5812;
v_5813:
    v_5828 = cons(v_5829, v_5828);
    env = stack[-7];
    stack[-6] = v_5828;
    goto v_5679;
v_5792:
v_5679:
    v_5828 = stack[-2];
    v_5828 = qcdr(v_5828);
    stack[-2] = v_5828;
    goto v_5653;
v_5652:
    v_5828 = stack[-6];
    {
        fn = elt(env, 9); // lalr_remove_duplicates
        return (*qfn1(fn))(fn, v_5828);
    }
    return onevalue(v_5828);
}



// Code for quotfx

static LispObject CC_quotfx(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5673, v_5674, v_5675;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5674 = v_5639;
    v_5675 = v_5638;
// end of prologue
    v_5673 = qvalue(elt(env, 1)); // !*exp
    if (v_5673 == nil) goto v_5647;
    else goto v_5648;
v_5647:
    v_5673 = lisp_true;
    goto v_5646;
v_5648:
    v_5673 = qvalue(elt(env, 2)); // !*mcd
    v_5673 = (v_5673 == nil ? lisp_true : nil);
    goto v_5646;
    v_5673 = nil;
v_5646:
    if (v_5673 == nil) goto v_5644;
    goto v_5660;
v_5656:
    v_5673 = v_5675;
    goto v_5657;
v_5658:
    goto v_5659;
v_5660:
    goto v_5656;
v_5657:
    goto v_5658;
v_5659:
    {
        fn = elt(env, 3); // quotf
        return (*qfn2(fn))(fn, v_5673, v_5674);
    }
v_5644:
    goto v_5670;
v_5666:
    v_5673 = v_5675;
    goto v_5667;
v_5668:
    goto v_5669;
v_5670:
    goto v_5666;
v_5667:
    goto v_5668;
v_5669:
    {
        fn = elt(env, 4); // quotfx1
        return (*qfn2(fn))(fn, v_5673, v_5674);
    }
    v_5673 = nil;
    return onevalue(v_5673);
}



// Code for ofsf_smwupdknowl

static LispObject CC_ofsf_smwupdknowl(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5678, v_5679, v_5680, v_5681, v_5682;
    LispObject fn;
    LispObject v_5641, v_5640, v_5639, v_5638;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "ofsf_smwupdknowl");
    va_start(aa, nargs);
    v_5638 = va_arg(aa, LispObject);
    v_5639 = va_arg(aa, LispObject);
    v_5640 = va_arg(aa, LispObject);
    v_5641 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5679 = v_5641;
    v_5680 = v_5640;
    v_5681 = v_5639;
    v_5682 = v_5638;
// end of prologue
    v_5678 = qvalue(elt(env, 1)); // !*rlsusi
    if (v_5678 == nil) goto v_5646;
    goto v_5657;
v_5649:
    v_5678 = v_5682;
    goto v_5650;
v_5651:
    goto v_5652;
v_5653:
    goto v_5654;
v_5655:
    goto v_5656;
v_5657:
    goto v_5649;
v_5650:
    goto v_5651;
v_5652:
    goto v_5653;
v_5654:
    goto v_5655;
v_5656:
    {
        fn = elt(env, 2); // cl_susiupdknowl
        return (*qfnn(fn))(fn, 4, v_5678, v_5681, v_5680, v_5679);
    }
v_5646:
    goto v_5673;
v_5665:
    v_5678 = v_5682;
    goto v_5666;
v_5667:
    goto v_5668;
v_5669:
    goto v_5670;
v_5671:
    goto v_5672;
v_5673:
    goto v_5665;
v_5666:
    goto v_5667;
v_5668:
    goto v_5669;
v_5670:
    goto v_5671;
v_5672:
    {
        fn = elt(env, 3); // ofsf_smupdknowl
        return (*qfnn(fn))(fn, 4, v_5678, v_5681, v_5680, v_5679);
    }
    v_5678 = nil;
    return onevalue(v_5678);
}



// Code for diffp1

static LispObject CC_diffp1(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5694, v_5695, v_5696;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_5694 = v_5639;
    v_5696 = v_5638;
// end of prologue
    goto v_5649;
v_5645:
    v_5695 = v_5696;
    v_5695 = qcar(v_5695);
    goto v_5646;
v_5647:
    goto v_5648;
v_5649:
    goto v_5645;
v_5646:
    goto v_5647;
v_5648:
    if (v_5695 == v_5694) goto v_5644;
    v_5694 = nil;
    goto v_5642;
v_5644:
    goto v_5660;
v_5656:
    v_5694 = v_5696;
    v_5695 = qcdr(v_5694);
    goto v_5657;
v_5658:
    v_5694 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5659;
v_5660:
    goto v_5656;
v_5657:
    goto v_5658;
v_5659:
    if (v_5695 == v_5694) goto v_5654;
    else goto v_5655;
v_5654:
    v_5694 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5642;
v_5655:
    goto v_5672;
v_5668:
    v_5694 = v_5696;
    stack[-1] = qcdr(v_5694);
    goto v_5669;
v_5670:
    goto v_5681;
v_5677:
    goto v_5687;
v_5683:
    v_5694 = v_5696;
    stack[0] = qcar(v_5694);
    goto v_5684;
v_5685:
    v_5694 = v_5696;
    v_5694 = qcdr(v_5694);
    v_5694 = sub1(v_5694);
    env = stack[-2];
    goto v_5686;
v_5687:
    goto v_5683;
v_5684:
    goto v_5685;
v_5686:
    fn = elt(env, 1); // to
    v_5695 = (*qfn2(fn))(fn, stack[0], v_5694);
    env = stack[-2];
    goto v_5678;
v_5679:
    v_5694 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5680;
v_5681:
    goto v_5677;
v_5678:
    goto v_5679;
v_5680:
    v_5694 = cons(v_5695, v_5694);
    env = stack[-2];
    v_5694 = ncons(v_5694);
    env = stack[-2];
    goto v_5671;
v_5672:
    goto v_5668;
v_5669:
    goto v_5670;
v_5671:
    {
        LispObject v_5699 = stack[-1];
        fn = elt(env, 2); // multd
        return (*qfn2(fn))(fn, v_5699, v_5694);
    }
    v_5694 = nil;
v_5642:
    return onevalue(v_5694);
}



// Code for rl_external

static LispObject CC_rl_external(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5667, v_5668, v_5669;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5668 = v_5639;
    v_5667 = v_5638;
// end of prologue
    if (!symbolp(v_5667)) v_5667 = nil;
    else { v_5667 = qfastgets(v_5667);
           if (v_5667 != nil) { v_5667 = elt(v_5667, 21); // rl_external
#ifdef RECORD_GET
             if (v_5667 != SPID_NOPROP)
                record_get(elt(fastget_names, 21), 1);
             else record_get(elt(fastget_names, 21), 0),
                v_5667 = nil; }
           else record_get(elt(fastget_names, 21), 0); }
#else
             if (v_5667 == SPID_NOPROP) v_5667 = nil; }}
#endif
    v_5669 = v_5667;
    v_5667 = v_5669;
    if (v_5667 == nil) goto v_5650;
    goto v_5656;
v_5652:
    v_5667 = v_5668;
    goto v_5653;
v_5654:
    v_5668 = v_5669;
    goto v_5655;
v_5656:
    goto v_5652;
v_5653:
    goto v_5654;
v_5655:
    v_5667 = Latsoc(nil, v_5667, v_5668);
    v_5669 = v_5667;
    v_5667 = v_5669;
    if (v_5667 == nil) goto v_5663;
    v_5667 = v_5669;
    v_5667 = qcdr(v_5667);
    goto v_5643;
v_5663:
    goto v_5648;
v_5650:
v_5648:
    v_5667 = nil;
v_5643:
    return onevalue(v_5667);
}



// Code for exchk2

static LispObject CC_exchk2(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5751, v_5752, v_5753;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_5639;
    stack[-1] = v_5638;
// end of prologue
v_5644:
    v_5751 = stack[-1];
    if (v_5751 == nil) goto v_5647;
    else goto v_5648;
v_5647:
    v_5751 = stack[0];
    goto v_5643;
v_5648:
    v_5751 = stack[-1];
    v_5751 = qcdr(v_5751);
    stack[-2] = v_5751;
    goto v_5660;
v_5656:
    v_5751 = stack[-1];
    v_5751 = qcar(v_5751);
    v_5751 = qcdr(v_5751);
    fn = elt(env, 6); // prepsqx
    v_5751 = (*qfn1(fn))(fn, v_5751);
    env = stack[-3];
    goto v_5674;
v_5670:
    v_5753 = v_5751;
    goto v_5671;
v_5672:
    v_5752 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5673;
v_5674:
    goto v_5670;
v_5671:
    goto v_5672;
v_5673:
    if (v_5753 == v_5752) goto v_5668;
    else goto v_5669;
v_5668:
    v_5751 = stack[-1];
    v_5751 = qcar(v_5751);
    v_5751 = qcar(v_5751);
    v_5752 = v_5751;
    goto v_5667;
v_5669:
    v_5752 = qvalue(elt(env, 1)); // !*nosqrts
    if (v_5752 == nil) goto v_5681;
    goto v_5690;
v_5684:
    v_5753 = elt(env, 2); // expt
    goto v_5685;
v_5686:
    v_5752 = stack[-1];
    v_5752 = qcar(v_5752);
    v_5752 = qcar(v_5752);
    goto v_5687;
v_5688:
    goto v_5689;
v_5690:
    goto v_5684;
v_5685:
    goto v_5686;
v_5687:
    goto v_5688;
v_5689:
    v_5751 = list3(v_5753, v_5752, v_5751);
    env = stack[-3];
    v_5752 = v_5751;
    goto v_5667;
v_5681:
    goto v_5702;
v_5698:
    v_5753 = v_5751;
    goto v_5699;
v_5700:
    v_5752 = elt(env, 3); // (quotient 1 2)
    goto v_5701;
v_5702:
    goto v_5698;
v_5699:
    goto v_5700;
v_5701:
    if (equal(v_5753, v_5752)) goto v_5696;
    else goto v_5697;
v_5696:
    goto v_5710;
v_5706:
    v_5752 = elt(env, 4); // sqrt
    goto v_5707;
v_5708:
    v_5751 = stack[-1];
    v_5751 = qcar(v_5751);
    v_5751 = qcar(v_5751);
    goto v_5709;
v_5710:
    goto v_5706;
v_5707:
    goto v_5708;
v_5709:
    v_5751 = list2(v_5752, v_5751);
    env = stack[-3];
    v_5752 = v_5751;
    goto v_5667;
v_5697:
    goto v_5721;
v_5717:
    v_5753 = v_5751;
    goto v_5718;
v_5719:
    v_5752 = elt(env, 5); // 0.5
    goto v_5720;
v_5721:
    goto v_5717;
v_5718:
    goto v_5719;
v_5720:
    if (equal(v_5753, v_5752)) goto v_5715;
    else goto v_5716;
v_5715:
    goto v_5729;
v_5725:
    v_5752 = elt(env, 4); // sqrt
    goto v_5726;
v_5727:
    v_5751 = stack[-1];
    v_5751 = qcar(v_5751);
    v_5751 = qcar(v_5751);
    goto v_5728;
v_5729:
    goto v_5725;
v_5726:
    goto v_5727;
v_5728:
    v_5751 = list2(v_5752, v_5751);
    env = stack[-3];
    v_5752 = v_5751;
    goto v_5667;
v_5716:
    goto v_5743;
v_5737:
    v_5753 = elt(env, 2); // expt
    goto v_5738;
v_5739:
    v_5752 = stack[-1];
    v_5752 = qcar(v_5752);
    v_5752 = qcar(v_5752);
    goto v_5740;
v_5741:
    goto v_5742;
v_5743:
    goto v_5737;
v_5738:
    goto v_5739;
v_5740:
    goto v_5741;
v_5742:
    v_5751 = list3(v_5753, v_5752, v_5751);
    env = stack[-3];
    v_5752 = v_5751;
    goto v_5667;
    v_5752 = nil;
v_5667:
    goto v_5657;
v_5658:
    v_5751 = stack[0];
    goto v_5659;
v_5660:
    goto v_5656;
v_5657:
    goto v_5658;
v_5659:
    v_5751 = cons(v_5752, v_5751);
    env = stack[-3];
    stack[0] = v_5751;
    v_5751 = stack[-2];
    stack[-1] = v_5751;
    goto v_5644;
    v_5751 = nil;
v_5643:
    return onevalue(v_5751);
}



// Code for on

static LispObject CC_on(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5658;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_5658 = v_5638;
// end of prologue
    stack[0] = v_5658;
v_5643:
    v_5658 = stack[0];
    if (v_5658 == nil) goto v_5647;
    else goto v_5648;
v_5647:
    v_5658 = nil;
    goto v_5642;
v_5648:
    v_5658 = stack[0];
    v_5658 = qcar(v_5658);
    fn = elt(env, 1); // on1
    v_5658 = (*qfn1(fn))(fn, v_5658);
    env = stack[-1];
    v_5658 = stack[0];
    v_5658 = qcdr(v_5658);
    stack[0] = v_5658;
    goto v_5643;
v_5642:
    return onevalue(v_5658);
}



// Code for vdpgetprop

static LispObject CC_vdpgetprop(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5704, v_5705, v_5706, v_5707;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_5706 = v_5639;
    v_5707 = v_5638;
// end of prologue
    v_5704 = v_5707;
    if (v_5704 == nil) goto v_5643;
    else goto v_5644;
v_5643:
    v_5704 = nil;
    goto v_5642;
v_5644:
    goto v_5654;
v_5650:
    v_5705 = v_5707;
    goto v_5651;
v_5652:
    v_5704 = elt(env, 1); // vdp
    goto v_5653;
v_5654:
    goto v_5650;
v_5651:
    goto v_5652;
v_5653:
    if (!consp(v_5705)) goto v_5647;
    v_5705 = qcar(v_5705);
    if (v_5705 == v_5704) goto v_5648;
v_5647:
    goto v_5664;
v_5658:
    stack[-1] = elt(env, 2); // dipoly
    goto v_5659;
v_5660:
    stack[0] = (LispObject)112+TAG_FIXNUM; // 7
    goto v_5661;
v_5662:
    goto v_5674;
v_5668:
    v_5704 = elt(env, 3); // "vdpgetprop given a non-vdp as 1st parameter"
    goto v_5669;
v_5670:
    v_5705 = v_5707;
    goto v_5671;
v_5672:
    goto v_5673;
v_5674:
    goto v_5668;
v_5669:
    goto v_5670;
v_5671:
    goto v_5672;
v_5673:
    v_5704 = list3(v_5704, v_5705, v_5706);
    env = stack[-2];
    goto v_5663;
v_5664:
    goto v_5658;
v_5659:
    goto v_5660;
v_5661:
    goto v_5662;
v_5663:
    {
        LispObject v_5710 = stack[-1];
        LispObject v_5711 = stack[0];
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_5710, v_5711, v_5704);
    }
v_5648:
    goto v_5684;
v_5680:
    v_5704 = v_5706;
    goto v_5681;
v_5682:
    v_5705 = v_5707;
    v_5705 = qcdr(v_5705);
    v_5705 = qcdr(v_5705);
    v_5705 = qcdr(v_5705);
    v_5705 = qcdr(v_5705);
    v_5705 = qcar(v_5705);
    goto v_5683;
v_5684:
    goto v_5680;
v_5681:
    goto v_5682;
v_5683:
    v_5704 = Lassoc(nil, v_5704, v_5705);
    v_5705 = v_5704;
    v_5704 = v_5705;
    if (v_5704 == nil) goto v_5697;
    v_5704 = v_5705;
    v_5704 = qcdr(v_5704);
    goto v_5695;
v_5697:
    v_5704 = nil;
    goto v_5695;
    v_5704 = nil;
v_5695:
    goto v_5642;
    v_5704 = nil;
v_5642:
    return onevalue(v_5704);
}



// Code for has_parents

static LispObject CC_has_parents(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5668, v_5669, v_5670;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5668 = v_5638;
// end of prologue
    v_5668 = qcdr(v_5668);
    v_5668 = qcar(v_5668);
    v_5670 = v_5668;
    goto v_5652;
v_5648:
    v_5668 = v_5670;
    v_5669 = qcar(v_5668);
    goto v_5649;
v_5650:
    v_5668 = elt(env, 1); // !?
    goto v_5651;
v_5652:
    goto v_5648;
v_5649:
    goto v_5650;
v_5651:
    if (v_5669 == v_5668) goto v_5647;
    goto v_5661;
v_5657:
    v_5668 = v_5670;
    v_5668 = qcdr(v_5668);
    goto v_5658;
v_5659:
    v_5669 = elt(env, 1); // !?
    goto v_5660;
v_5661:
    goto v_5657;
v_5658:
    goto v_5659;
v_5660:
        return Lneq(nil, v_5668, v_5669);
v_5647:
    v_5668 = nil;
    goto v_5645;
    v_5668 = nil;
v_5645:
    return onevalue(v_5668);
}



// Code for sc_kern

static LispObject CC_sc_kern(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5652;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5652 = v_5638;
// end of prologue
    goto v_5644;
v_5640:
    stack[0] = qvalue(elt(env, 1)); // g_sc_ve
    goto v_5641;
v_5642:
    v_5652 = sub1(v_5652);
    goto v_5643;
v_5644:
    goto v_5640;
v_5641:
    goto v_5642;
v_5643:
    v_5652 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + (((intptr_t)v_5652-TAG_FIXNUM)/(16/CELL)));
    v_5652 = qcdr(v_5652);
    v_5652 = qcdr(v_5652);
    v_5652 = qcar(v_5652);
    return onevalue(v_5652);
}



// Code for list_assoc

static LispObject CC_list_assoc(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5666, v_5667, v_5668, v_5669;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5667 = v_5639;
    v_5668 = v_5638;
// end of prologue
v_5643:
    v_5666 = v_5667;
    if (v_5666 == nil) goto v_5646;
    else goto v_5647;
v_5646:
    v_5666 = v_5667;
    goto v_5642;
v_5647:
    goto v_5656;
v_5652:
    v_5666 = v_5667;
    v_5666 = qcar(v_5666);
    v_5669 = qcar(v_5666);
    goto v_5653;
v_5654:
    v_5666 = v_5668;
    goto v_5655;
v_5656:
    goto v_5652;
v_5653:
    goto v_5654;
v_5655:
    if (equal(v_5669, v_5666)) goto v_5650;
    else goto v_5651;
v_5650:
    v_5666 = v_5667;
    goto v_5642;
v_5651:
    v_5666 = v_5667;
    v_5666 = qcdr(v_5666);
    v_5667 = v_5666;
    goto v_5643;
    v_5666 = nil;
v_5642:
    return onevalue(v_5666);
}



// Code for aex_simplenullp

static LispObject CC_aex_simplenullp(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5644;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
// copy arguments values to proper place
    v_5644 = v_5638;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v_5644 = (*qfn1(fn))(fn, v_5644);
    v_5644 = qcar(v_5644);
    v_5644 = (v_5644 == nil ? lisp_true : nil);
    return onevalue(v_5644);
}



// Code for ofsf_ordatp

static LispObject CC_ofsf_ordatp(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5682, v_5683, v_5684, v_5685, v_5686, v_5687;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
// copy arguments values to proper place
    v_5686 = v_5639;
    v_5687 = v_5638;
// end of prologue
    v_5682 = v_5687;
    v_5682 = qcdr(v_5682);
    v_5682 = qcar(v_5682);
    v_5685 = v_5682;
    v_5682 = v_5686;
    v_5682 = qcdr(v_5682);
    v_5682 = qcar(v_5682);
    v_5684 = v_5682;
    goto v_5660;
v_5656:
    v_5683 = v_5685;
    goto v_5657;
v_5658:
    v_5682 = v_5684;
    goto v_5659;
v_5660:
    goto v_5656;
v_5657:
    goto v_5658;
v_5659:
    if (equal(v_5683, v_5682)) goto v_5655;
    goto v_5668;
v_5664:
    v_5682 = v_5685;
    goto v_5665;
v_5666:
    v_5683 = v_5684;
    goto v_5667;
v_5668:
    goto v_5664;
v_5665:
    goto v_5666;
v_5667:
    fn = elt(env, 2); // ordp
    v_5682 = (*qfn2(fn))(fn, v_5682, v_5683);
    v_5682 = (v_5682 == nil ? lisp_true : nil);
    goto v_5644;
v_5655:
    goto v_5677;
v_5673:
    v_5682 = v_5687;
    v_5682 = qcar(v_5682);
    goto v_5674;
v_5675:
    v_5683 = v_5686;
    v_5683 = qcar(v_5683);
    goto v_5676;
v_5677:
    goto v_5673;
v_5674:
    goto v_5675;
v_5676:
    {
        fn = elt(env, 3); // ofsf_ordrelp
        return (*qfn2(fn))(fn, v_5682, v_5683);
    }
v_5644:
    return onevalue(v_5682);
}



// Code for polynommultiplybymonom

static LispObject CC_polynommultiplybymonom(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5687, v_5688;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5639;
    v_5688 = v_5638;
// end of prologue
    v_5687 = v_5688;
    if (v_5687 == nil) goto v_5643;
    else goto v_5644;
v_5643:
    v_5687 = nil;
    goto v_5642;
v_5644:
    v_5687 = v_5688;
    fn = elt(env, 2); // polynomclone
    v_5687 = (*qfn1(fn))(fn, v_5687);
    env = stack[-2];
    stack[-1] = v_5687;
    goto v_5660;
v_5656:
    v_5688 = stack[0];
    goto v_5657;
v_5658:
    v_5687 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5659;
v_5660:
    goto v_5656;
v_5657:
    goto v_5658;
v_5659:
    v_5687 = *(LispObject *)((char *)v_5688 + (CELL-TAG_VECTOR) + (((intptr_t)v_5687-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_5687;
v_5666:
    v_5687 = stack[0];
    v_5687 = qcar(v_5687);
    if (v_5687 == nil) goto v_5669;
    else goto v_5670;
v_5669:
    goto v_5665;
v_5670:
    goto v_5679;
v_5675:
    v_5688 = stack[-1];
    goto v_5676;
v_5677:
    v_5687 = stack[0];
    v_5687 = qcar(v_5687);
    goto v_5678;
v_5679:
    goto v_5675;
v_5676:
    goto v_5677;
v_5678:
    fn = elt(env, 3); // polynommultiplybyvariable
    v_5687 = (*qfn2(fn))(fn, v_5688, v_5687);
    env = stack[-2];
    v_5687 = stack[0];
    v_5687 = qcdr(v_5687);
    stack[0] = v_5687;
    goto v_5666;
v_5665:
    v_5687 = stack[-1];
    goto v_5642;
    v_5687 = nil;
v_5642:
    return onevalue(v_5687);
}



// Code for revv0

static LispObject CC_revv0(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5709, v_5710;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_5639;
    stack[-1] = v_5638;
// end of prologue
v_5637:
    goto v_5649;
v_5645:
    v_5709 = stack[-1];
    v_5709 = qcdr(v_5709);
    v_5710 = qcar(v_5709);
    goto v_5646;
v_5647:
    v_5709 = stack[0];
    goto v_5648;
v_5649:
    goto v_5645;
v_5646:
    goto v_5647;
v_5648:
    if (v_5710 == v_5709) goto v_5643;
    else goto v_5644;
v_5643:
    v_5709 = stack[-1];
    goto v_5642;
v_5644:
    v_5709 = stack[-1];
    v_5709 = qcdr(v_5709);
    v_5709 = qcar(v_5709);
    stack[-2] = v_5709;
    goto v_5669;
v_5665:
    v_5709 = stack[-1];
    v_5710 = qcdr(v_5709);
    goto v_5666;
v_5667:
    v_5709 = stack[-1];
    v_5709 = qcdr(v_5709);
    v_5709 = qcdr(v_5709);
    v_5709 = qcar(v_5709);
    goto v_5668;
v_5669:
    goto v_5665;
v_5666:
    goto v_5667;
v_5668:
    v_5709 = Lrplaca(nil, v_5710, v_5709);
    env = stack[-3];
    goto v_5681;
v_5677:
    v_5709 = stack[-1];
    v_5709 = qcdr(v_5709);
    v_5710 = qcdr(v_5709);
    goto v_5678;
v_5679:
    v_5709 = stack[-1];
    v_5709 = qcdr(v_5709);
    v_5709 = qcdr(v_5709);
    v_5709 = qcdr(v_5709);
    v_5709 = qcar(v_5709);
    goto v_5680;
v_5681:
    goto v_5677;
v_5678:
    goto v_5679;
v_5680:
    v_5709 = Lrplaca(nil, v_5710, v_5709);
    env = stack[-3];
    goto v_5695;
v_5691:
    v_5709 = stack[-1];
    v_5709 = qcdr(v_5709);
    v_5709 = qcdr(v_5709);
    v_5710 = qcdr(v_5709);
    goto v_5692;
v_5693:
    v_5709 = stack[-2];
    goto v_5694;
v_5695:
    goto v_5691;
v_5692:
    goto v_5693;
v_5694:
    v_5709 = Lrplaca(nil, v_5710, v_5709);
    env = stack[-3];
    goto v_5706;
v_5702:
    v_5710 = stack[-1];
    goto v_5703;
v_5704:
    v_5709 = stack[0];
    goto v_5705;
v_5706:
    goto v_5702;
v_5703:
    goto v_5704;
v_5705:
    stack[-1] = v_5710;
    stack[0] = v_5709;
    goto v_5637;
    goto v_5642;
    v_5709 = nil;
v_5642:
    return onevalue(v_5709);
}



// Code for cl_smcpknowl

static LispObject CC_cl_smcpknowl(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5680;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_5680 = v_5638;
// end of prologue
    stack[-3] = v_5680;
    v_5680 = stack[-3];
    if (v_5680 == nil) goto v_5649;
    else goto v_5650;
v_5649:
    v_5680 = nil;
    goto v_5644;
v_5650:
    v_5680 = stack[-3];
    v_5680 = qcar(v_5680);
    v_5680 = ncons(v_5680);
    env = stack[-4];
    stack[-1] = v_5680;
    stack[-2] = v_5680;
v_5645:
    v_5680 = stack[-3];
    v_5680 = qcdr(v_5680);
    stack[-3] = v_5680;
    v_5680 = stack[-3];
    if (v_5680 == nil) goto v_5662;
    else goto v_5663;
v_5662:
    v_5680 = stack[-2];
    goto v_5644;
v_5663:
    goto v_5671;
v_5667:
    stack[0] = stack[-1];
    goto v_5668;
v_5669:
    v_5680 = stack[-3];
    v_5680 = qcar(v_5680);
    v_5680 = ncons(v_5680);
    env = stack[-4];
    goto v_5670;
v_5671:
    goto v_5667;
v_5668:
    goto v_5669;
v_5670:
    v_5680 = Lrplacd(nil, stack[0], v_5680);
    env = stack[-4];
    v_5680 = stack[-1];
    v_5680 = qcdr(v_5680);
    stack[-1] = v_5680;
    goto v_5645;
v_5644:
    return onevalue(v_5680);
}



// Code for ofsf_prepat

static LispObject CC_ofsf_prepat(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5659;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_5638;
// end of prologue
    goto v_5647;
v_5641:
    v_5659 = stack[-1];
    stack[-2] = qcar(v_5659);
    goto v_5642;
v_5643:
    v_5659 = stack[-1];
    v_5659 = qcdr(v_5659);
    v_5659 = qcar(v_5659);
    fn = elt(env, 1); // prepf
    stack[0] = (*qfn1(fn))(fn, v_5659);
    env = stack[-3];
    goto v_5644;
v_5645:
    v_5659 = stack[-1];
    v_5659 = qcdr(v_5659);
    v_5659 = qcdr(v_5659);
    v_5659 = qcar(v_5659);
    fn = elt(env, 1); // prepf
    v_5659 = (*qfn1(fn))(fn, v_5659);
    goto v_5646;
v_5647:
    goto v_5641;
v_5642:
    goto v_5643;
v_5644:
    goto v_5645;
v_5646:
    {
        LispObject v_5663 = stack[-2];
        LispObject v_5664 = stack[0];
        return list3(v_5663, v_5664, v_5659);
    }
}



// Code for quotfail!-mod!-p

static LispObject CC_quotfailKmodKp(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5664, v_5665, v_5666;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5665 = v_5639;
    v_5666 = v_5638;
// end of prologue
    v_5664 = lisp_true;
    qvalue(elt(env, 2)) = v_5664; // exact!-quotient!-flag
    goto v_5651;
v_5647:
    v_5664 = v_5666;
    goto v_5648;
v_5649:
    goto v_5650;
v_5651:
    goto v_5647;
v_5648:
    goto v_5649;
v_5650:
    fn = elt(env, 4); // quotient!-mod!-p
    v_5664 = (*qfn2(fn))(fn, v_5664, v_5665);
    env = stack[0];
    v_5665 = v_5664;
    v_5664 = qvalue(elt(env, 2)); // exact!-quotient!-flag
    if (v_5664 == nil) goto v_5657;
    v_5664 = v_5665;
    goto v_5643;
v_5657:
    v_5664 = elt(env, 3); // "Quotient not exact (mod p)"
    fn = elt(env, 5); // errorf
    v_5664 = (*qfn1(fn))(fn, v_5664);
    goto v_5655;
v_5655:
    v_5664 = nil;
v_5643:
    return onevalue(v_5664);
}



// Code for expression

static LispObject CC_expression(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5732, v_5733, v_5734;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_5734 = v_5638;
// end of prologue
    v_5732 = v_5734;
    if (v_5732 == nil) goto v_5647;
    v_5732 = v_5734;
    if (!consp(v_5732)) goto v_5651;
    else goto v_5652;
v_5651:
    v_5732 = v_5734;
    fn = elt(env, 4); // constsml
    v_5732 = (*qfn1(fn))(fn, v_5732);
    goto v_5650;
v_5652:
    goto v_5666;
v_5662:
    v_5732 = v_5734;
    v_5733 = qcar(v_5732);
    goto v_5663;
v_5664:
    v_5732 = qvalue(elt(env, 2)); // ir2mml!*
    goto v_5665;
v_5666:
    goto v_5662;
v_5663:
    goto v_5664;
v_5665:
    v_5732 = Lassoc(nil, v_5733, v_5732);
    v_5733 = v_5732;
    if (v_5732 == nil) goto v_5661;
    v_5732 = v_5733;
    v_5732 = qcdr(v_5732);
    v_5732 = qcdr(v_5732);
    v_5732 = qcar(v_5732);
    if (v_5732 == nil) goto v_5673;
    else goto v_5674;
v_5673:
    goto v_5684;
v_5680:
    v_5732 = v_5733;
    v_5732 = qcdr(v_5732);
    stack[0] = qcar(v_5732);
    goto v_5681;
v_5682:
    v_5732 = v_5734;
    v_5732 = qcdr(v_5732);
    v_5732 = ncons(v_5732);
    env = stack[-1];
    goto v_5683;
v_5684:
    goto v_5680;
v_5681:
    goto v_5682;
v_5683:
    fn = elt(env, 5); // apply
    v_5732 = (*qfn2(fn))(fn, stack[0], v_5732);
    goto v_5672;
v_5674:
    goto v_5698;
v_5694:
    v_5732 = v_5733;
    v_5732 = qcdr(v_5732);
    stack[0] = qcar(v_5732);
    goto v_5695;
v_5696:
    goto v_5707;
v_5703:
    v_5732 = v_5734;
    v_5732 = qcdr(v_5732);
    goto v_5704;
v_5705:
    v_5733 = v_5734;
    v_5733 = qcar(v_5733);
    goto v_5706;
v_5707:
    goto v_5703;
v_5704:
    goto v_5705;
v_5706:
    v_5732 = list2(v_5732, v_5733);
    env = stack[-1];
    goto v_5697;
v_5698:
    goto v_5694;
v_5695:
    goto v_5696;
v_5697:
    fn = elt(env, 5); // apply
    v_5732 = (*qfn2(fn))(fn, stack[0], v_5732);
    goto v_5672;
v_5672:
    goto v_5659;
v_5661:
    goto v_5718;
v_5714:
    v_5732 = v_5734;
    v_5733 = qcar(v_5732);
    goto v_5715;
v_5716:
    v_5732 = elt(env, 3); // !*sq
    goto v_5717;
v_5718:
    goto v_5714;
v_5715:
    goto v_5716;
v_5717:
    if (v_5733 == v_5732) goto v_5712;
    else goto v_5713;
v_5712:
    v_5732 = v_5734;
    v_5732 = qcdr(v_5732);
    v_5732 = qcar(v_5732);
    fn = elt(env, 6); // prepsq
    v_5732 = (*qfn1(fn))(fn, v_5732);
    env = stack[-1];
    v_5732 = CC_expression(elt(env, 0), v_5732);
    goto v_5659;
v_5713:
    v_5732 = v_5734;
    fn = elt(env, 7); // operator_fn
    v_5732 = (*qfn1(fn))(fn, v_5732);
    goto v_5659;
v_5659:
    goto v_5650;
v_5650:
    goto v_5645;
v_5647:
v_5645:
    v_5732 = nil;
    return onevalue(v_5732);
}



// Code for smtp

static LispObject CC_smtp(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5840, v_5841, v_5842, v_5843;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-6] = v_5639;
    stack[0] = v_5638;
// end of prologue
    v_5840 = stack[0];
    if (!consp(v_5840)) goto v_5655;
    else goto v_5656;
v_5655:
    v_5840 = stack[0];
    if (!symbolp(v_5840)) v_5840 = nil;
    else { v_5840 = qfastgets(v_5840);
           if (v_5840 != nil) { v_5840 = elt(v_5840, 4); // avalue
#ifdef RECORD_GET
             if (v_5840 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_5840 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_5840 == SPID_NOPROP) v_5840 = nil; }}
#endif
    v_5840 = qcdr(v_5840);
    v_5840 = qcar(v_5840);
    stack[-7] = v_5840;
    v_5840 = stack[-7];
    v_5840 = qcdr(v_5840);
    v_5840 = qcdr(v_5840);
    v_5840 = qcar(v_5840);
    v_5841 = v_5840;
    goto v_5654;
v_5656:
    goto v_5673;
v_5669:
    v_5841 = stack[0];
    goto v_5670;
v_5671:
    v_5840 = elt(env, 2); // sparsemat
    goto v_5672;
v_5673:
    goto v_5669;
v_5670:
    goto v_5671;
v_5672:
    if (!consp(v_5841)) goto v_5667;
    v_5841 = qcar(v_5841);
    if (v_5841 == v_5840) goto v_5666;
    else goto v_5667;
v_5666:
    v_5840 = stack[0];
    stack[-7] = v_5840;
    v_5840 = stack[-7];
    v_5840 = qcdr(v_5840);
    v_5840 = qcdr(v_5840);
    v_5840 = qcar(v_5840);
    v_5841 = v_5840;
    goto v_5654;
v_5667:
    goto v_5688;
v_5684:
    v_5840 = stack[0];
    v_5840 = qcdr(v_5840);
    v_5841 = qcar(v_5840);
    goto v_5685;
v_5686:
    v_5840 = stack[-6];
    goto v_5687;
v_5688:
    goto v_5684;
v_5685:
    goto v_5686;
v_5687:
    v_5840 = CC_smtp(elt(env, 0), v_5841, v_5840);
    env = stack[-8];
    stack[-7] = v_5840;
    v_5840 = stack[-7];
    v_5840 = qcdr(v_5840);
    v_5840 = qcdr(v_5840);
    v_5840 = qcar(v_5840);
    v_5841 = v_5840;
    goto v_5654;
v_5654:
    v_5840 = v_5841;
    v_5840 = qcdr(v_5840);
    v_5840 = qcar(v_5840);
    stack[-4] = v_5840;
    v_5840 = v_5841;
    v_5840 = qcdr(v_5840);
    v_5840 = qcdr(v_5840);
    v_5840 = qcar(v_5840);
    goto v_5709;
v_5705:
    stack[-1] = v_5840;
    goto v_5706;
v_5707:
    goto v_5718;
v_5712:
    v_5842 = elt(env, 3); // spm
    goto v_5713;
v_5714:
    v_5841 = v_5840;
    goto v_5715;
v_5716:
    v_5840 = stack[-4];
    goto v_5717;
v_5718:
    goto v_5712;
v_5713:
    goto v_5714;
v_5715:
    goto v_5716;
v_5717:
    v_5840 = list3(v_5842, v_5841, v_5840);
    env = stack[-8];
    goto v_5708;
v_5709:
    goto v_5705;
v_5706:
    goto v_5707;
v_5708:
    fn = elt(env, 7); // mkempspmat
    v_5840 = (*qfn2(fn))(fn, stack[-1], v_5840);
    env = stack[-8];
    stack[-5] = v_5840;
    goto v_5731;
v_5727:
    v_5841 = stack[-7];
    goto v_5728;
v_5729:
    v_5840 = elt(env, 2); // sparsemat
    goto v_5730;
v_5731:
    goto v_5727;
v_5728:
    goto v_5729;
v_5730:
    if (!consp(v_5841)) goto v_5724;
    v_5841 = qcar(v_5841);
    if (v_5841 == v_5840) goto v_5725;
v_5724:
    goto v_5741;
v_5735:
    stack[-2] = elt(env, 4); // matrix
    goto v_5736;
v_5737:
    stack[-1] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_5738;
v_5739:
    goto v_5751;
v_5745:
    v_5842 = elt(env, 5); // "Matrix"
    goto v_5746;
v_5747:
    v_5841 = stack[0];
    goto v_5748;
v_5749:
    v_5840 = elt(env, 6); // "not set"
    goto v_5750;
v_5751:
    goto v_5745;
v_5746:
    goto v_5747;
v_5748:
    goto v_5749;
v_5750:
    v_5840 = list3(v_5842, v_5841, v_5840);
    env = stack[-8];
    goto v_5740;
v_5741:
    goto v_5735;
v_5736:
    goto v_5737;
v_5738:
    goto v_5739;
v_5740:
    fn = elt(env, 8); // rerror
    v_5840 = (*qfnn(fn))(fn, 3, stack[-2], stack[-1], v_5840);
    goto v_5723;
v_5725:
    v_5840 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_5840;
v_5760:
    goto v_5772;
v_5768:
    v_5841 = stack[-4];
    goto v_5769;
v_5770:
    v_5840 = stack[-1];
    goto v_5771;
v_5772:
    goto v_5768;
v_5769:
    goto v_5770;
v_5771:
    v_5840 = difference2(v_5841, v_5840);
    env = stack[-8];
    v_5840 = Lminusp(nil, v_5840);
    env = stack[-8];
    if (v_5840 == nil) goto v_5765;
    goto v_5759;
v_5765:
    goto v_5781;
v_5777:
    v_5841 = stack[-7];
    goto v_5778;
v_5779:
    v_5840 = stack[-1];
    goto v_5780;
v_5781:
    goto v_5777;
v_5778:
    goto v_5779;
v_5780:
    fn = elt(env, 9); // findrow
    v_5840 = (*qfn2(fn))(fn, v_5841, v_5840);
    env = stack[-8];
    v_5841 = v_5840;
    v_5840 = v_5841;
    if (v_5840 == nil) goto v_5787;
    v_5840 = stack[-1];
    stack[-3] = v_5840;
    v_5840 = v_5841;
    v_5840 = qcdr(v_5840);
    stack[0] = v_5840;
v_5793:
    v_5840 = stack[0];
    if (v_5840 == nil) goto v_5798;
    else goto v_5799;
v_5798:
    goto v_5792;
v_5799:
    v_5840 = stack[0];
    v_5840 = qcar(v_5840);
    v_5841 = v_5840;
    v_5840 = v_5841;
    v_5840 = qcar(v_5840);
    v_5841 = qcdr(v_5841);
    stack[-2] = v_5841;
    goto v_5818;
v_5810:
    goto v_5826;
v_5820:
    v_5842 = stack[-5];
    goto v_5821;
v_5822:
    v_5841 = v_5840;
    goto v_5823;
v_5824:
    v_5840 = stack[-3];
    goto v_5825;
v_5826:
    goto v_5820;
v_5821:
    goto v_5822;
v_5823:
    goto v_5824;
v_5825:
    v_5843 = list3(v_5842, v_5841, v_5840);
    env = stack[-8];
    goto v_5811;
v_5812:
    v_5842 = stack[-2];
    goto v_5813;
v_5814:
    v_5841 = stack[-5];
    goto v_5815;
v_5816:
    v_5840 = stack[-6];
    goto v_5817;
v_5818:
    goto v_5810;
v_5811:
    goto v_5812;
v_5813:
    goto v_5814;
v_5815:
    goto v_5816;
v_5817:
    fn = elt(env, 10); // letmtr3
    v_5840 = (*qfnn(fn))(fn, 4, v_5843, v_5842, v_5841, v_5840);
    env = stack[-8];
    v_5840 = stack[0];
    v_5840 = qcdr(v_5840);
    stack[0] = v_5840;
    goto v_5793;
v_5792:
    goto v_5785;
v_5787:
v_5785:
    v_5840 = stack[-1];
    v_5840 = add1(v_5840);
    env = stack[-8];
    stack[-1] = v_5840;
    goto v_5760;
v_5759:
    goto v_5723;
v_5723:
    v_5840 = stack[-5];
    return onevalue(v_5840);
}



// Code for off

static LispObject CC_off(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5658;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_5658 = v_5638;
// end of prologue
    stack[0] = v_5658;
v_5643:
    v_5658 = stack[0];
    if (v_5658 == nil) goto v_5647;
    else goto v_5648;
v_5647:
    v_5658 = nil;
    goto v_5642;
v_5648:
    v_5658 = stack[0];
    v_5658 = qcar(v_5658);
    fn = elt(env, 1); // off1
    v_5658 = (*qfn1(fn))(fn, v_5658);
    env = stack[-1];
    v_5658 = stack[0];
    v_5658 = qcdr(v_5658);
    stack[0] = v_5658;
    goto v_5643;
v_5642:
    return onevalue(v_5658);
}



// Code for xord_lex

static LispObject CC_xord_lex(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5713, v_5714, v_5715, v_5716;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5714 = v_5639;
    v_5715 = v_5638;
// end of prologue
v_5643:
    v_5713 = v_5715;
    if (v_5713 == nil) goto v_5650;
    else goto v_5651;
v_5650:
    v_5713 = lisp_true;
    goto v_5649;
v_5651:
    goto v_5660;
v_5656:
    v_5713 = v_5715;
    v_5716 = qcar(v_5713);
    goto v_5657;
v_5658:
    v_5713 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5659;
v_5660:
    goto v_5656;
v_5657:
    goto v_5658;
v_5659:
    v_5713 = (v_5716 == v_5713 ? lisp_true : nil);
    goto v_5649;
    v_5713 = nil;
v_5649:
    if (v_5713 == nil) goto v_5647;
    v_5713 = nil;
    goto v_5642;
v_5647:
    v_5713 = v_5714;
    if (v_5713 == nil) goto v_5670;
    else goto v_5671;
v_5670:
    v_5713 = lisp_true;
    goto v_5669;
v_5671:
    goto v_5680;
v_5676:
    v_5713 = v_5714;
    v_5716 = qcar(v_5713);
    goto v_5677;
v_5678:
    v_5713 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5679;
v_5680:
    goto v_5676;
v_5677:
    goto v_5678;
v_5679:
    v_5713 = (v_5716 == v_5713 ? lisp_true : nil);
    goto v_5669;
    v_5713 = nil;
v_5669:
    if (v_5713 == nil) goto v_5667;
    v_5713 = lisp_true;
    goto v_5642;
v_5667:
    goto v_5692;
v_5688:
    v_5713 = v_5715;
    v_5716 = qcar(v_5713);
    goto v_5689;
v_5690:
    v_5713 = v_5714;
    v_5713 = qcar(v_5713);
    goto v_5691;
v_5692:
    goto v_5688;
v_5689:
    goto v_5690;
v_5691:
    if (v_5716 == v_5713) goto v_5686;
    else goto v_5687;
v_5686:
    v_5713 = v_5715;
    v_5713 = qcdr(v_5713);
    v_5715 = v_5713;
    v_5713 = v_5714;
    v_5713 = qcdr(v_5713);
    v_5714 = v_5713;
    goto v_5643;
v_5687:
    goto v_5708;
v_5704:
    v_5713 = v_5715;
    v_5713 = qcar(v_5713);
    goto v_5705;
v_5706:
    v_5714 = qcar(v_5714);
    goto v_5707;
v_5708:
    goto v_5704;
v_5705:
    goto v_5706;
v_5707:
    {
        fn = elt(env, 1); // factorordp
        return (*qfn2(fn))(fn, v_5713, v_5714);
    }
    v_5713 = nil;
v_5642:
    return onevalue(v_5713);
}



// Code for !:difference

static LispObject CC_Tdifference(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5695, v_5696, v_5697, v_5698;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5697 = v_5639;
    v_5698 = v_5638;
// end of prologue
    v_5695 = v_5698;
    if (v_5695 == nil) goto v_5643;
    else goto v_5644;
v_5643:
    v_5695 = v_5697;
    {
        fn = elt(env, 2); // !:minus
        return (*qfn1(fn))(fn, v_5695);
    }
v_5644:
    v_5695 = v_5697;
    if (v_5695 == nil) goto v_5648;
    else goto v_5649;
v_5648:
    v_5695 = v_5698;
    goto v_5642;
v_5649:
    goto v_5658;
v_5654:
    v_5696 = v_5698;
    goto v_5655;
v_5656:
    v_5695 = v_5697;
    goto v_5657;
v_5658:
    goto v_5654;
v_5655:
    goto v_5656;
v_5657:
    if (equal(v_5696, v_5695)) goto v_5652;
    else goto v_5653;
v_5652:
    v_5695 = nil;
    goto v_5642;
v_5653:
    v_5695 = v_5698;
    if (!consp(v_5695)) goto v_5666;
    else goto v_5667;
v_5666:
    v_5695 = v_5697;
    v_5695 = (consp(v_5695) ? nil : lisp_true);
    goto v_5665;
v_5667:
    v_5695 = nil;
    goto v_5665;
    v_5695 = nil;
v_5665:
    if (v_5695 == nil) goto v_5663;
    goto v_5679;
v_5675:
    v_5695 = v_5698;
    goto v_5676;
v_5677:
    v_5696 = v_5697;
    goto v_5678;
v_5679:
    goto v_5675;
v_5676:
    goto v_5677;
v_5678:
    return difference2(v_5695, v_5696);
v_5663:
    goto v_5691;
v_5685:
    v_5696 = v_5698;
    goto v_5686;
v_5687:
    goto v_5688;
v_5689:
    v_5695 = elt(env, 1); // difference
    goto v_5690;
v_5691:
    goto v_5685;
v_5686:
    goto v_5687;
v_5688:
    goto v_5689;
v_5690:
    {
        fn = elt(env, 3); // dcombine
        return (*qfnn(fn))(fn, 3, v_5696, v_5697, v_5695);
    }
    v_5695 = nil;
v_5642:
    return onevalue(v_5695);
}



// Code for getphystype

static LispObject CC_getphystype(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5744, v_5745;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5638;
// end of prologue
    v_5744 = stack[0];
    fn = elt(env, 8); // physopp
    v_5744 = (*qfn1(fn))(fn, v_5744);
    env = stack[-2];
    if (v_5744 == nil) goto v_5647;
    v_5744 = stack[0];
    fn = elt(env, 9); // scalopp
    v_5744 = (*qfn1(fn))(fn, v_5744);
    env = stack[-2];
    if (v_5744 == nil) goto v_5653;
    v_5744 = elt(env, 2); // scalar
    goto v_5651;
v_5653:
    v_5744 = stack[0];
    fn = elt(env, 10); // vecopp
    v_5744 = (*qfn1(fn))(fn, v_5744);
    env = stack[-2];
    if (v_5744 == nil) goto v_5658;
    v_5744 = elt(env, 3); // vector
    goto v_5651;
v_5658:
    v_5744 = stack[0];
    fn = elt(env, 11); // tensopp
    v_5744 = (*qfn1(fn))(fn, v_5744);
    env = stack[-2];
    if (v_5744 == nil) goto v_5663;
    v_5744 = elt(env, 4); // tensor
    goto v_5651;
v_5663:
    v_5744 = stack[0];
    fn = elt(env, 12); // po!:statep
    v_5744 = (*qfn1(fn))(fn, v_5744);
    env = stack[-2];
    if (v_5744 == nil) goto v_5668;
    v_5744 = elt(env, 5); // state
    goto v_5651;
v_5668:
    v_5744 = nil;
    goto v_5651;
    v_5744 = nil;
v_5651:
    goto v_5645;
v_5647:
    v_5744 = stack[0];
    if (!consp(v_5744)) goto v_5675;
    else goto v_5676;
v_5675:
    v_5744 = nil;
    goto v_5645;
v_5676:
    v_5744 = stack[0];
    v_5744 = qcar(v_5744);
    if (!symbolp(v_5744)) v_5745 = nil;
    else { v_5745 = qfastgets(v_5744);
           if (v_5745 != nil) { v_5745 = elt(v_5745, 18); // phystype
#ifdef RECORD_GET
             if (v_5745 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_5745 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_5745 == SPID_NOPROP) v_5745 = nil; }}
#endif
    v_5744 = v_5745;
    if (v_5745 == nil) goto v_5680;
    goto v_5645;
v_5680:
    goto v_5692;
v_5688:
    v_5744 = stack[0];
    v_5745 = qcar(v_5744);
    goto v_5689;
v_5690:
    v_5744 = elt(env, 6); // phystypefn
    goto v_5691;
v_5692:
    goto v_5688;
v_5689:
    goto v_5690;
v_5691:
    v_5745 = get(v_5745, v_5744);
    env = stack[-2];
    v_5744 = v_5745;
    if (v_5745 == nil) goto v_5686;
    goto v_5701;
v_5697:
    v_5745 = v_5744;
    goto v_5698;
v_5699:
    v_5744 = stack[0];
    v_5744 = qcdr(v_5744);
    goto v_5700;
v_5701:
    goto v_5697;
v_5698:
    goto v_5699;
v_5700:
        return Lapply1(nil, v_5745, v_5744);
v_5686:
    v_5744 = stack[0];
    fn = elt(env, 13); // collectphystype
    v_5745 = (*qfn1(fn))(fn, v_5744);
    env = stack[-2];
    v_5744 = v_5745;
    if (v_5745 == nil) goto v_5705;
    else goto v_5706;
v_5705:
    v_5744 = nil;
    goto v_5645;
v_5706:
    v_5745 = v_5744;
    v_5745 = qcdr(v_5745);
    if (v_5745 == nil) goto v_5710;
    else goto v_5711;
v_5710:
    v_5744 = qcar(v_5744);
    goto v_5645;
v_5711:
    goto v_5722;
v_5718:
    v_5745 = elt(env, 5); // state
    goto v_5719;
v_5720:
    goto v_5721;
v_5722:
    goto v_5718;
v_5719:
    goto v_5720;
v_5721:
    v_5744 = Lmember(nil, v_5745, v_5744);
    if (v_5744 == nil) goto v_5717;
    v_5744 = elt(env, 5); // state
    goto v_5645;
v_5717:
    goto v_5734;
v_5730:
    stack[-1] = elt(env, 0); // getphystype
    goto v_5731;
v_5732:
    goto v_5741;
v_5737:
    v_5745 = elt(env, 7); // "PHYSOP type conflict in"
    goto v_5738;
v_5739:
    v_5744 = stack[0];
    goto v_5740;
v_5741:
    goto v_5737;
v_5738:
    goto v_5739;
v_5740:
    v_5744 = list2(v_5745, v_5744);
    env = stack[-2];
    goto v_5733;
v_5734:
    goto v_5730;
v_5731:
    goto v_5732;
v_5733:
    {
        LispObject v_5748 = stack[-1];
        fn = elt(env, 14); // rederr2
        return (*qfn2(fn))(fn, v_5748, v_5744);
    }
    v_5744 = nil;
v_5645:
    return onevalue(v_5744);
}



// Code for lprim

static LispObject CC_lprim(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5656, v_5657;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5656 = v_5638;
// end of prologue
    v_5657 = qvalue(elt(env, 1)); // !*msg
    if (v_5657 == nil) goto v_5642;
    else goto v_5643;
v_5642:
    v_5656 = nil;
    goto v_5641;
v_5643:
    goto v_5653;
v_5649:
    v_5657 = elt(env, 2); // "***"
    goto v_5650;
v_5651:
    goto v_5652;
v_5653:
    goto v_5649;
v_5650:
    goto v_5651;
v_5652:
    {
        fn = elt(env, 3); // lpriw
        return (*qfn2(fn))(fn, v_5657, v_5656);
    }
    v_5656 = nil;
v_5641:
    return onevalue(v_5656);
}



// Code for mv!-domainlist!-!-

static LispObject CC_mvKdomainlistKK(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5675, v_5676;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_5639;
    stack[-1] = v_5638;
// end of prologue
    stack[-2] = nil;
v_5644:
    v_5675 = stack[-1];
    if (v_5675 == nil) goto v_5647;
    else goto v_5648;
v_5647:
    v_5675 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_5675);
    }
v_5648:
    goto v_5659;
v_5655:
    goto v_5665;
v_5661:
    v_5675 = stack[-1];
    v_5676 = qcar(v_5675);
    goto v_5662;
v_5663:
    v_5675 = stack[0];
    v_5675 = qcar(v_5675);
    goto v_5664;
v_5665:
    goto v_5661;
v_5662:
    goto v_5663;
v_5664:
    v_5676 = difference2(v_5676, v_5675);
    env = stack[-3];
    goto v_5656;
v_5657:
    v_5675 = stack[-2];
    goto v_5658;
v_5659:
    goto v_5655;
v_5656:
    goto v_5657;
v_5658:
    v_5675 = cons(v_5676, v_5675);
    env = stack[-3];
    stack[-2] = v_5675;
    v_5675 = stack[-1];
    v_5675 = qcdr(v_5675);
    stack[-1] = v_5675;
    v_5675 = stack[0];
    v_5675 = qcdr(v_5675);
    stack[0] = v_5675;
    goto v_5644;
    v_5675 = nil;
    return onevalue(v_5675);
}



// Code for formop

static LispObject CC_formop(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5702, v_5703;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_5638;
// end of prologue
    stack[-2] = nil;
v_5644:
    v_5702 = stack[-1];
    if (!consp(v_5702)) goto v_5653;
    else goto v_5654;
v_5653:
    v_5702 = lisp_true;
    goto v_5652;
v_5654:
    v_5702 = stack[-1];
    v_5702 = qcar(v_5702);
    v_5702 = (consp(v_5702) ? nil : lisp_true);
    goto v_5652;
    v_5702 = nil;
v_5652:
    if (v_5702 == nil) goto v_5650;
    goto v_5645;
v_5650:
    goto v_5667;
v_5663:
    goto v_5673;
v_5669:
    v_5702 = stack[-1];
    v_5702 = qcar(v_5702);
    stack[0] = qcar(v_5702);
    goto v_5670;
v_5671:
    v_5702 = stack[-1];
    v_5702 = qcar(v_5702);
    v_5702 = qcdr(v_5702);
    v_5702 = CC_formop(elt(env, 0), v_5702);
    env = stack[-3];
    goto v_5672;
v_5673:
    goto v_5669;
v_5670:
    goto v_5671;
v_5672:
    fn = elt(env, 1); // multop
    v_5703 = (*qfn2(fn))(fn, stack[0], v_5702);
    env = stack[-3];
    goto v_5664;
v_5665:
    v_5702 = stack[-2];
    goto v_5666;
v_5667:
    goto v_5663;
v_5664:
    goto v_5665;
v_5666:
    v_5702 = cons(v_5703, v_5702);
    env = stack[-3];
    stack[-2] = v_5702;
    v_5702 = stack[-1];
    v_5702 = qcdr(v_5702);
    stack[-1] = v_5702;
    goto v_5644;
v_5645:
    v_5702 = stack[-1];
    v_5703 = v_5702;
v_5646:
    v_5702 = stack[-2];
    if (v_5702 == nil) goto v_5687;
    else goto v_5688;
v_5687:
    v_5702 = v_5703;
    goto v_5643;
v_5688:
    goto v_5696;
v_5692:
    v_5702 = stack[-2];
    v_5702 = qcar(v_5702);
    goto v_5693;
v_5694:
    goto v_5695;
v_5696:
    goto v_5692;
v_5693:
    goto v_5694;
v_5695:
    fn = elt(env, 2); // raddf
    v_5702 = (*qfn2(fn))(fn, v_5702, v_5703);
    env = stack[-3];
    v_5703 = v_5702;
    v_5702 = stack[-2];
    v_5702 = qcdr(v_5702);
    stack[-2] = v_5702;
    goto v_5646;
v_5643:
    return onevalue(v_5702);
}



// Code for listtest

static LispObject CC_listtest(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5680, v_5681, v_5682;
    LispObject v_5640, v_5639, v_5638;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "listtest");
    va_start(aa, nargs);
    v_5638 = va_arg(aa, LispObject);
    v_5639 = va_arg(aa, LispObject);
    v_5640 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_5640,v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_5638,v_5639,v_5640);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_5640;
    stack[-1] = v_5639;
    stack[-2] = v_5638;
// end of prologue
v_5644:
    v_5680 = stack[-2];
    if (v_5680 == nil) goto v_5647;
    else goto v_5648;
v_5647:
    v_5680 = nil;
    goto v_5643;
v_5648:
    goto v_5660;
v_5654:
    v_5682 = stack[0];
    goto v_5655;
v_5656:
    v_5680 = stack[-2];
    v_5681 = qcar(v_5680);
    goto v_5657;
v_5658:
    v_5680 = stack[-1];
    goto v_5659;
v_5660:
    goto v_5654;
v_5655:
    goto v_5656;
v_5657:
    goto v_5658;
v_5659:
    v_5680 = Lapply2(nil, 3, v_5682, v_5681, v_5680);
    env = stack[-3];
    if (v_5680 == nil) goto v_5652;
    v_5680 = stack[-2];
    v_5680 = qcar(v_5680);
    if (v_5680 == nil) goto v_5667;
    else goto v_5668;
v_5667:
    v_5680 = lisp_true;
    goto v_5643;
v_5668:
    v_5680 = stack[-2];
    v_5680 = qcar(v_5680);
    goto v_5643;
    goto v_5646;
v_5652:
    v_5680 = stack[-2];
    v_5680 = qcdr(v_5680);
    stack[-2] = v_5680;
    goto v_5644;
v_5646:
    v_5680 = nil;
v_5643:
    return onevalue(v_5680);
}



// Code for leftzeros

static LispObject CC_leftzeros(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5696, v_5697;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5638;
// end of prologue
    stack[-1] = nil;
v_5644:
    v_5696 = stack[0];
    if (v_5696 == nil) goto v_5653;
    else goto v_5654;
v_5653:
    v_5696 = lisp_true;
    goto v_5652;
v_5654:
    goto v_5664;
v_5660:
    v_5696 = stack[0];
    v_5697 = qcar(v_5696);
    goto v_5661;
v_5662:
    v_5696 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5663;
v_5664:
    goto v_5660;
v_5661:
    goto v_5662;
v_5663:
    v_5696 = Lneq(nil, v_5697, v_5696);
    env = stack[-2];
    goto v_5652;
    v_5696 = nil;
v_5652:
    if (v_5696 == nil) goto v_5650;
    goto v_5645;
v_5650:
    goto v_5673;
v_5669:
    v_5697 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5670;
v_5671:
    v_5696 = stack[-1];
    goto v_5672;
v_5673:
    goto v_5669;
v_5670:
    goto v_5671;
v_5672:
    v_5696 = cons(v_5697, v_5696);
    env = stack[-2];
    stack[-1] = v_5696;
    v_5696 = stack[0];
    v_5696 = qcdr(v_5696);
    stack[0] = v_5696;
    goto v_5644;
v_5645:
    v_5696 = (LispObject)0+TAG_FIXNUM; // 0
    v_5697 = v_5696;
v_5646:
    v_5696 = stack[-1];
    if (v_5696 == nil) goto v_5681;
    else goto v_5682;
v_5681:
    v_5696 = v_5697;
    goto v_5643;
v_5682:
    goto v_5689;
v_5685:
    v_5696 = stack[-1];
    v_5696 = qcar(v_5696);
    goto v_5686;
v_5687:
    goto v_5688;
v_5689:
    goto v_5685;
v_5686:
    goto v_5687;
v_5688:
    v_5696 = (LispObject)(intptr_t)((intptr_t)v_5696 + (intptr_t)v_5697 - TAG_FIXNUM);
    v_5697 = v_5696;
    v_5696 = stack[-1];
    v_5696 = qcdr(v_5696);
    stack[-1] = v_5696;
    goto v_5646;
v_5643:
    return onevalue(v_5696);
}



// Code for get_action_without_lookahead

static LispObject CC_get_action_without_lookahead(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5663, v_5664;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5663 = v_5638;
// end of prologue
    goto v_5648;
v_5644:
    v_5664 = qvalue(elt(env, 2)); // parser_action_table
    goto v_5645;
v_5646:
    goto v_5647;
v_5648:
    goto v_5644;
v_5645:
    goto v_5646;
v_5647:
    v_5663 = *(LispObject *)((char *)v_5664 + (CELL-TAG_VECTOR) + (((intptr_t)v_5663-TAG_FIXNUM)/(16/CELL)));
    v_5664 = v_5663;
    v_5663 = v_5664;
    v_5663 = qcar(v_5663);
    if (v_5663 == nil) goto v_5654;
    else goto v_5655;
v_5654:
    v_5663 = v_5664;
    v_5663 = qcdr(v_5663);
    goto v_5642;
v_5655:
    v_5663 = nil;
    goto v_5642;
    v_5663 = nil;
v_5642:
    return onevalue(v_5663);
}



// Code for polynomlistfinddivisor

static LispObject CC_polynomlistfinddivisor(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5730, v_5731, v_5732;
    LispObject fn;
    LispObject v_5640, v_5639, v_5638;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "polynomlistfinddivisor");
    va_start(aa, nargs);
    v_5638 = va_arg(aa, LispObject);
    v_5639 = va_arg(aa, LispObject);
    v_5640 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_5640,v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_5638,v_5639,v_5640);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_5640;
    v_5731 = v_5639;
    v_5732 = v_5638;
// end of prologue
    v_5730 = v_5731;
    v_5730 = qcar(v_5730);
    if (v_5730 == nil) goto v_5648;
    else goto v_5649;
v_5648:
    v_5730 = lisp_true;
    goto v_5647;
v_5649:
    v_5730 = v_5732;
    v_5730 = qcar(v_5730);
    v_5730 = (v_5730 == nil ? lisp_true : nil);
    goto v_5647;
    v_5730 = nil;
v_5647:
    if (v_5730 == nil) goto v_5645;
    v_5730 = nil;
    goto v_5643;
v_5645:
    stack[0] = nil;
    v_5730 = v_5731;
    v_5730 = qcar(v_5730);
    stack[-3] = v_5730;
    v_5730 = v_5732;
    stack[-1] = v_5730;
v_5672:
    v_5730 = stack[-1];
    v_5730 = qcar(v_5730);
    if (v_5730 == nil) goto v_5675;
    v_5730 = stack[0];
    if (v_5730 == nil) goto v_5680;
    else goto v_5675;
v_5680:
    goto v_5676;
v_5675:
    goto v_5671;
v_5676:
    v_5730 = stack[-2];
    if (v_5730 == nil) goto v_5687;
    goto v_5696;
v_5692:
    v_5731 = stack[-3];
    goto v_5693;
v_5694:
    v_5730 = stack[-1];
    v_5730 = qcar(v_5730);
    v_5730 = qcar(v_5730);
    goto v_5695;
v_5696:
    goto v_5692;
v_5693:
    goto v_5694;
v_5695:
    fn = elt(env, 2); // monomisdivisibleby
    v_5730 = (*qfn2(fn))(fn, v_5731, v_5730);
    env = stack[-4];
    if (v_5730 == nil) goto v_5687;
    goto v_5685;
v_5687:
    v_5730 = stack[-2];
    if (v_5730 == nil) goto v_5704;
    else goto v_5705;
v_5704:
    goto v_5712;
v_5708:
    v_5731 = stack[-3];
    goto v_5709;
v_5710:
    v_5730 = stack[-1];
    v_5730 = qcar(v_5730);
    v_5730 = qcar(v_5730);
    goto v_5711;
v_5712:
    goto v_5708;
v_5709:
    goto v_5710;
v_5711:
    fn = elt(env, 3); // monomispommaretdivisibleby
    v_5730 = (*qfn2(fn))(fn, v_5731, v_5730);
    env = stack[-4];
    goto v_5703;
v_5705:
    v_5730 = nil;
    goto v_5703;
    v_5730 = nil;
v_5703:
    if (v_5730 == nil) goto v_5701;
    else goto v_5685;
v_5701:
    goto v_5686;
v_5685:
    v_5730 = lisp_true;
    stack[0] = v_5730;
    goto v_5684;
v_5686:
    v_5730 = stack[-1];
    v_5730 = qcdr(v_5730);
    stack[-1] = v_5730;
    goto v_5684;
v_5684:
    goto v_5672;
v_5671:
    v_5730 = stack[-1];
    v_5730 = qcar(v_5730);
    goto v_5643;
    v_5730 = nil;
v_5643:
    return onevalue(v_5730);
}



// Code for tayexp!-difference

static LispObject CC_tayexpKdifference(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5721, v_5722, v_5723;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5639;
    v_5722 = v_5638;
// end of prologue
    v_5721 = v_5722;
    if (!consp(v_5721)) goto v_5647;
    else goto v_5648;
v_5647:
    v_5721 = stack[0];
    v_5721 = (consp(v_5721) ? nil : lisp_true);
    goto v_5646;
v_5648:
    v_5721 = nil;
    goto v_5646;
    v_5721 = nil;
v_5646:
    if (v_5721 == nil) goto v_5644;
    goto v_5660;
v_5656:
    goto v_5657;
v_5658:
    v_5721 = stack[0];
    goto v_5659;
v_5660:
    goto v_5656;
v_5657:
    goto v_5658;
v_5659:
    return difference2(v_5722, v_5721);
v_5644:
    v_5721 = v_5722;
    if (!consp(v_5721)) goto v_5667;
    else goto v_5668;
v_5667:
    goto v_5675;
v_5671:
    v_5721 = v_5722;
    fn = elt(env, 1); // !*i2rn
    v_5722 = (*qfn1(fn))(fn, v_5721);
    env = stack[-2];
    goto v_5672;
v_5673:
    v_5721 = stack[0];
    goto v_5674;
v_5675:
    goto v_5671;
v_5672:
    goto v_5673;
v_5674:
    fn = elt(env, 2); // rndifference!:
    v_5721 = (*qfn2(fn))(fn, v_5722, v_5721);
    goto v_5666;
v_5668:
    v_5721 = stack[0];
    if (!consp(v_5721)) goto v_5679;
    else goto v_5680;
v_5679:
    goto v_5687;
v_5683:
    stack[-1] = v_5722;
    goto v_5684;
v_5685:
    v_5721 = stack[0];
    fn = elt(env, 1); // !*i2rn
    v_5721 = (*qfn1(fn))(fn, v_5721);
    env = stack[-2];
    goto v_5686;
v_5687:
    goto v_5683;
v_5684:
    goto v_5685;
v_5686:
    fn = elt(env, 2); // rndifference!:
    v_5721 = (*qfn2(fn))(fn, stack[-1], v_5721);
    goto v_5666;
v_5680:
    goto v_5698;
v_5694:
    goto v_5695;
v_5696:
    v_5721 = stack[0];
    goto v_5697;
v_5698:
    goto v_5694;
v_5695:
    goto v_5696;
v_5697:
    fn = elt(env, 2); // rndifference!:
    v_5721 = (*qfn2(fn))(fn, v_5722, v_5721);
    goto v_5666;
    v_5721 = nil;
v_5666:
    v_5723 = v_5721;
    goto v_5710;
v_5706:
    v_5721 = v_5723;
    v_5721 = qcdr(v_5721);
    v_5722 = qcdr(v_5721);
    goto v_5707;
v_5708:
    v_5721 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5709;
v_5710:
    goto v_5706;
v_5707:
    goto v_5708;
v_5709:
    if (v_5722 == v_5721) goto v_5704;
    else goto v_5705;
v_5704:
    v_5721 = v_5723;
    v_5721 = qcdr(v_5721);
    v_5721 = qcar(v_5721);
    goto v_5703;
v_5705:
    v_5721 = v_5723;
    goto v_5703;
    v_5721 = nil;
v_5703:
    goto v_5642;
    v_5721 = nil;
v_5642:
    return onevalue(v_5721);
}



// Code for cl_varl1

static LispObject CC_cl_varl1(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5654, v_5655, v_5656, v_5657;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5654 = v_5638;
// end of prologue
    goto v_5649;
v_5641:
    v_5657 = v_5654;
    goto v_5642;
v_5643:
    v_5656 = nil;
    goto v_5644;
v_5645:
    v_5655 = nil;
    goto v_5646;
v_5647:
    v_5654 = nil;
    goto v_5648;
v_5649:
    goto v_5641;
v_5642:
    goto v_5643;
v_5644:
    goto v_5645;
v_5646:
    goto v_5647;
v_5648:
    {
        fn = elt(env, 1); // cl_varl2
        return (*qfnn(fn))(fn, 4, v_5657, v_5656, v_5655, v_5654);
    }
}



// Code for lastnondomain

static LispObject CC_lastnondomain(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5687, v_5688;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5687 = v_5638;
// end of prologue
v_5642:
    v_5688 = v_5687;
    if (!consp(v_5688)) goto v_5649;
    else goto v_5650;
v_5649:
    v_5688 = lisp_true;
    goto v_5648;
v_5650:
    v_5688 = v_5687;
    v_5688 = qcar(v_5688);
    v_5688 = (consp(v_5688) ? nil : lisp_true);
    goto v_5648;
    v_5688 = nil;
v_5648:
    if (v_5688 == nil) goto v_5646;
    goto v_5664;
v_5660:
    v_5688 = elt(env, 1); // "non-domain"
    goto v_5661;
v_5662:
    goto v_5663;
v_5664:
    goto v_5660;
v_5661:
    goto v_5662;
v_5663:
    v_5687 = list2(v_5688, v_5687);
    env = stack[0];
    {
        fn = elt(env, 2); // errach
        return (*qfn1(fn))(fn, v_5687);
    }
v_5646:
    v_5688 = v_5687;
    v_5688 = qcdr(v_5688);
    if (!consp(v_5688)) goto v_5671;
    else goto v_5672;
v_5671:
    v_5688 = lisp_true;
    goto v_5670;
v_5672:
    v_5688 = v_5687;
    v_5688 = qcdr(v_5688);
    v_5688 = qcar(v_5688);
    v_5688 = (consp(v_5688) ? nil : lisp_true);
    goto v_5670;
    v_5688 = nil;
v_5670:
    if (v_5688 == nil) goto v_5668;
    goto v_5641;
v_5668:
    v_5687 = qcdr(v_5687);
    goto v_5642;
    v_5687 = nil;
v_5641:
    return onevalue(v_5687);
}



// Code for rl_gettype

static LispObject CC_rl_gettype(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5654, v_5655, v_5656;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5655 = v_5638;
// end of prologue
    v_5654 = v_5655;
    if (!symbolp(v_5654)) v_5654 = nil;
    else { v_5654 = qfastgets(v_5654);
           if (v_5654 != nil) { v_5654 = elt(v_5654, 4); // avalue
#ifdef RECORD_GET
             if (v_5654 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_5654 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_5654 == SPID_NOPROP) v_5654 = nil; }}
#endif
    v_5656 = v_5654;
    v_5654 = v_5656;
    if (v_5654 == nil) goto v_5646;
    v_5654 = v_5656;
    v_5654 = qcar(v_5654);
    goto v_5644;
v_5646:
    v_5654 = v_5655;
    if (!symbolp(v_5654)) v_5654 = nil;
    else { v_5654 = qfastgets(v_5654);
           if (v_5654 != nil) { v_5654 = elt(v_5654, 2); // rtype
#ifdef RECORD_GET
             if (v_5654 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_5654 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_5654 == SPID_NOPROP) v_5654 = nil; }}
#endif
    goto v_5644;
    v_5654 = nil;
v_5644:
    return onevalue(v_5654);
}



// Code for omair

static LispObject CC_omair(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5671, v_5672;
    LispObject fn;
    argcheck(nargs, 0, "omair");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// end of prologue
    stack[0] = nil;
    fn = elt(env, 4); // lex
    v_5671 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 5); // omobj
    v_5671 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_5671;
    goto v_5654;
v_5650:
    v_5671 = stack[-1];
    v_5672 = qcar(v_5671);
    goto v_5651;
v_5652:
    v_5671 = elt(env, 2); // matrix
    goto v_5653;
v_5654:
    goto v_5650;
v_5651:
    goto v_5652;
v_5653:
    if (v_5672 == v_5671) goto v_5649;
    fn = elt(env, 4); // lex
    v_5671 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    fn = elt(env, 6); // omobjs
    v_5671 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_5671;
    v_5671 = elt(env, 3); // (!/ o m a)
    fn = elt(env, 7); // checktag
    v_5671 = (*qfn1(fn))(fn, v_5671);
    goto v_5647;
v_5649:
v_5647:
    goto v_5668;
v_5664:
    v_5672 = stack[-1];
    goto v_5665;
v_5666:
    v_5671 = stack[0];
    goto v_5667;
v_5668:
    goto v_5664;
v_5665:
    goto v_5666;
v_5667:
        return Lappend(nil, v_5672, v_5671);
    return onevalue(v_5671);
}



// Code for dfn_prop

static LispObject CC_dfn_prop(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5686, v_5687, v_5688;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5686 = v_5638;
// end of prologue
    v_5686 = qcdr(v_5686);
    v_5686 = Llength(nil, v_5686);
    env = stack[0];
    v_5688 = v_5686;
    goto v_5652;
v_5648:
    v_5687 = v_5688;
    goto v_5649;
v_5650:
    v_5686 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5651;
v_5652:
    goto v_5648;
v_5649:
    goto v_5650;
v_5651:
    if (v_5687 == v_5686) goto v_5646;
    else goto v_5647;
v_5646:
    v_5686 = elt(env, 1); // dfn
    goto v_5645;
v_5647:
    goto v_5662;
v_5658:
    v_5687 = v_5688;
    goto v_5659;
v_5660:
    v_5686 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_5661;
v_5662:
    goto v_5658;
v_5659:
    goto v_5660;
v_5661:
    if (v_5687 == v_5686) goto v_5656;
    else goto v_5657;
v_5656:
    v_5686 = elt(env, 2); // dfn2
    goto v_5645;
v_5657:
    goto v_5672;
v_5668:
    v_5687 = v_5688;
    goto v_5669;
v_5670:
    v_5686 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_5671;
v_5672:
    goto v_5668;
v_5669:
    goto v_5670;
v_5671:
    if (v_5687 == v_5686) goto v_5666;
    else goto v_5667;
v_5666:
    v_5686 = elt(env, 3); // dfn3
    goto v_5645;
v_5667:
    goto v_5683;
v_5679:
    v_5686 = elt(env, 1); // dfn
    goto v_5680;
v_5681:
    v_5687 = v_5688;
    goto v_5682;
v_5683:
    goto v_5679;
v_5680:
    goto v_5681;
v_5682:
    {
        fn = elt(env, 4); // mkid
        return (*qfn2(fn))(fn, v_5686, v_5687);
    }
    v_5686 = nil;
v_5645:
    return onevalue(v_5686);
}



// Code for mkuwedge

static LispObject CC_mkuwedge(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5660, v_5661;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5660 = v_5638;
// end of prologue
    v_5661 = v_5660;
    v_5661 = qcdr(v_5661);
    if (v_5661 == nil) goto v_5643;
    goto v_5652;
v_5648:
    v_5661 = elt(env, 1); // wedge
    goto v_5649;
v_5650:
    goto v_5651;
v_5652:
    goto v_5648;
v_5649:
    goto v_5650;
v_5651:
    v_5660 = cons(v_5661, v_5660);
    env = stack[0];
    fn = elt(env, 2); // fkern
    v_5660 = (*qfn1(fn))(fn, v_5660);
    v_5660 = qcar(v_5660);
    goto v_5641;
v_5643:
    v_5660 = qcar(v_5660);
    goto v_5641;
    v_5660 = nil;
v_5641:
    return onevalue(v_5660);
}



// Code for plus!:

static LispObject CC_plusT(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5776, v_5777, v_5778, v_5779;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_5778 = v_5639;
    v_5779 = v_5638;
// end of prologue
    goto v_5657;
v_5653:
    v_5776 = v_5779;
    v_5776 = qcdr(v_5776);
    v_5777 = qcar(v_5776);
    stack[-1] = v_5777;
    goto v_5654;
v_5655:
    v_5776 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5656;
v_5657:
    goto v_5653;
v_5654:
    goto v_5655;
v_5656:
    if (v_5777 == v_5776) goto v_5651;
    else goto v_5652;
v_5651:
    v_5776 = v_5778;
    goto v_5650;
v_5652:
    goto v_5669;
v_5665:
    v_5776 = v_5778;
    v_5776 = qcdr(v_5776);
    v_5777 = qcar(v_5776);
    stack[0] = v_5777;
    goto v_5666;
v_5667:
    v_5776 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5668;
v_5669:
    goto v_5665;
v_5666:
    goto v_5667;
v_5668:
    if (v_5777 == v_5776) goto v_5663;
    else goto v_5664;
v_5663:
    v_5776 = v_5779;
    goto v_5650;
v_5664:
    goto v_5681;
v_5677:
    goto v_5687;
v_5683:
    v_5776 = v_5779;
    v_5776 = qcdr(v_5776);
    v_5776 = qcdr(v_5776);
    stack[-4] = v_5776;
    goto v_5684;
v_5685:
    v_5777 = v_5778;
    v_5777 = qcdr(v_5777);
    v_5777 = qcdr(v_5777);
    stack[-2] = v_5777;
    goto v_5686;
v_5687:
    goto v_5683;
v_5684:
    goto v_5685;
v_5686:
    v_5777 = difference2(v_5776, v_5777);
    env = stack[-5];
    stack[-3] = v_5777;
    goto v_5678;
v_5679:
    v_5776 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5680;
v_5681:
    goto v_5677;
v_5678:
    goto v_5679;
v_5680:
    if (v_5777 == v_5776) goto v_5675;
    else goto v_5676;
v_5675:
    goto v_5702;
v_5696:
    stack[-2] = elt(env, 2); // !:rd!:
    goto v_5697;
v_5698:
    goto v_5709;
v_5705:
    v_5777 = stack[-1];
    goto v_5706;
v_5707:
    v_5776 = stack[0];
    goto v_5708;
v_5709:
    goto v_5705;
v_5706:
    goto v_5707;
v_5708:
    v_5777 = plus2(v_5777, v_5776);
    goto v_5699;
v_5700:
    v_5776 = stack[-4];
    goto v_5701;
v_5702:
    goto v_5696;
v_5697:
    goto v_5698;
v_5699:
    goto v_5700;
v_5701:
    {
        LispObject v_5785 = stack[-2];
        return list2star(v_5785, v_5777, v_5776);
    }
v_5676:
    goto v_5720;
v_5716:
    v_5777 = stack[-3];
    goto v_5717;
v_5718:
    v_5776 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5719;
v_5720:
    goto v_5716;
v_5717:
    goto v_5718;
v_5719:
    v_5776 = (LispObject)greaterp2(v_5777, v_5776);
    v_5776 = v_5776 ? lisp_true : nil;
    env = stack[-5];
    if (v_5776 == nil) goto v_5714;
    goto v_5730;
v_5724:
    stack[-4] = elt(env, 2); // !:rd!:
    goto v_5725;
v_5726:
    goto v_5737;
v_5733:
    goto v_5743;
v_5739:
    v_5777 = stack[-1];
    goto v_5740;
v_5741:
    v_5776 = stack[-3];
    goto v_5742;
v_5743:
    goto v_5739;
v_5740:
    goto v_5741;
v_5742:
    fn = elt(env, 3); // ashift
    v_5777 = (*qfn2(fn))(fn, v_5777, v_5776);
    env = stack[-5];
    goto v_5734;
v_5735:
    v_5776 = stack[0];
    goto v_5736;
v_5737:
    goto v_5733;
v_5734:
    goto v_5735;
v_5736:
    v_5777 = plus2(v_5777, v_5776);
    goto v_5727;
v_5728:
    v_5776 = stack[-2];
    goto v_5729;
v_5730:
    goto v_5724;
v_5725:
    goto v_5726;
v_5727:
    goto v_5728;
v_5729:
    {
        LispObject v_5786 = stack[-4];
        return list2star(v_5786, v_5777, v_5776);
    }
v_5714:
    goto v_5757;
v_5751:
    stack[-2] = elt(env, 2); // !:rd!:
    goto v_5752;
v_5753:
    goto v_5764;
v_5760:
    goto v_5761;
v_5762:
    goto v_5771;
v_5767:
    goto v_5768;
v_5769:
    v_5776 = stack[-3];
    v_5776 = negate(v_5776);
    env = stack[-5];
    goto v_5770;
v_5771:
    goto v_5767;
v_5768:
    goto v_5769;
v_5770:
    fn = elt(env, 3); // ashift
    v_5776 = (*qfn2(fn))(fn, stack[0], v_5776);
    env = stack[-5];
    goto v_5763;
v_5764:
    goto v_5760;
v_5761:
    goto v_5762;
v_5763:
    v_5777 = plus2(stack[-1], v_5776);
    goto v_5754;
v_5755:
    v_5776 = stack[-4];
    goto v_5756;
v_5757:
    goto v_5751;
v_5752:
    goto v_5753;
v_5754:
    goto v_5755;
v_5756:
    {
        LispObject v_5787 = stack[-2];
        return list2star(v_5787, v_5777, v_5776);
    }
    v_5776 = nil;
v_5650:
    return onevalue(v_5776);
}



// Code for !*id2num

static LispObject CC_Hid2num(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5658, v_5659;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5658 = v_5638;
// end of prologue
    goto v_5652;
v_5648:
    goto v_5649;
v_5650:
    v_5659 = qvalue(elt(env, 2)); // pair_id_num!*
    goto v_5651;
v_5652:
    goto v_5648;
v_5649:
    goto v_5650;
v_5651:
    v_5658 = Lassoc(nil, v_5658, v_5659);
    v_5659 = v_5658;
    if (v_5658 == nil) goto v_5647;
    v_5658 = v_5659;
    v_5658 = qcdr(v_5658);
    goto v_5642;
v_5647:
    v_5658 = nil;
v_5642:
    return onevalue(v_5658);
}



// Code for arintequiv!:

static LispObject CC_arintequivT(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5684, v_5685, v_5686;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5685 = v_5638;
// end of prologue
    v_5684 = v_5685;
    v_5684 = qcdr(v_5684);
    if (is_number(v_5684)) goto v_5642;
    else goto v_5643;
v_5642:
    v_5684 = v_5685;
    v_5684 = qcdr(v_5684);
    goto v_5641;
v_5643:
    goto v_5658;
v_5654:
    v_5684 = v_5685;
    v_5684 = qcdr(v_5684);
    v_5684 = qcar(v_5684);
    goto v_5655;
v_5656:
    v_5686 = elt(env, 1); // !:rn!:
    goto v_5657;
v_5658:
    goto v_5654;
v_5655:
    goto v_5656;
v_5657:
    if (v_5684 == v_5686) goto v_5652;
    else goto v_5653;
v_5652:
    goto v_5667;
v_5663:
    v_5684 = v_5685;
    v_5684 = qcdr(v_5684);
    v_5684 = qcdr(v_5684);
    v_5686 = qcdr(v_5684);
    goto v_5664;
v_5665:
    v_5684 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_5666;
v_5667:
    goto v_5663;
v_5664:
    goto v_5665;
v_5666:
    v_5684 = (v_5686 == v_5684 ? lisp_true : nil);
    goto v_5651;
v_5653:
    v_5684 = nil;
    goto v_5651;
    v_5684 = nil;
v_5651:
    if (v_5684 == nil) goto v_5649;
    v_5684 = v_5685;
    v_5684 = qcdr(v_5684);
    v_5684 = qcdr(v_5684);
    v_5684 = qcar(v_5684);
    goto v_5641;
v_5649:
    v_5684 = nil;
    goto v_5641;
    v_5684 = nil;
v_5641:
    return onevalue(v_5684);
}



// Code for reduce!-mod!-p

static LispObject CC_reduceKmodKp(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5694, v_5695, v_5696;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_5638;
// end of prologue
    v_5694 = stack[0];
    if (v_5694 == nil) goto v_5642;
    else goto v_5643;
v_5642:
    v_5694 = nil;
    goto v_5641;
v_5643:
    v_5694 = stack[0];
    if (!consp(v_5694)) goto v_5650;
    else goto v_5651;
v_5650:
    v_5694 = lisp_true;
    goto v_5649;
v_5651:
    v_5694 = stack[0];
    v_5694 = qcar(v_5694);
    v_5694 = (consp(v_5694) ? nil : lisp_true);
    goto v_5649;
    v_5694 = nil;
v_5649:
    if (v_5694 == nil) goto v_5647;
    v_5694 = stack[0];
    v_5694 = Lmodular_number(nil, v_5694);
    env = stack[-2];
    {
        fn = elt(env, 1); // !*n2f
        return (*qfn1(fn))(fn, v_5694);
    }
v_5647:
    v_5694 = stack[0];
    v_5694 = qcar(v_5694);
    v_5694 = qcdr(v_5694);
    stack[-1] = CC_reduceKmodKp(elt(env, 0), v_5694);
    env = stack[-2];
    v_5694 = stack[0];
    v_5694 = qcdr(v_5694);
    v_5694 = CC_reduceKmodKp(elt(env, 0), v_5694);
    v_5695 = stack[-1];
    v_5696 = v_5695;
    if (v_5696 == nil) goto v_5675;
    else goto v_5676;
v_5675:
    goto v_5674;
v_5676:
    goto v_5688;
v_5682:
    v_5696 = stack[0];
    v_5696 = qcar(v_5696);
    v_5696 = qcar(v_5696);
    goto v_5683;
v_5684:
    goto v_5685;
v_5686:
    goto v_5687;
v_5688:
    goto v_5682;
v_5683:
    goto v_5684;
v_5685:
    goto v_5686;
v_5687:
    return acons(v_5696, v_5695, v_5694);
    v_5694 = nil;
v_5674:
    goto v_5641;
    v_5694 = nil;
v_5641:
    return onevalue(v_5694);
}



// Code for ra_budancount

static LispObject CC_ra_budancount(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5654, v_5655, v_5656;
    LispObject fn;
    LispObject v_5640, v_5639, v_5638;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ra_budancount");
    va_start(aa, nargs);
    v_5638 = va_arg(aa, LispObject);
    v_5639 = va_arg(aa, LispObject);
    v_5640 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_5640,v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_5638,v_5639,v_5640);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_5654 = v_5640;
    v_5655 = v_5639;
    v_5656 = v_5638;
// end of prologue
    goto v_5650;
v_5644:
    goto v_5645;
v_5646:
    goto v_5647;
v_5648:
    goto v_5649;
v_5650:
    goto v_5644;
v_5645:
    goto v_5646;
v_5647:
    goto v_5648;
v_5649:
    fn = elt(env, 1); // ra_transform
    v_5654 = (*qfnn(fn))(fn, 3, v_5656, v_5655, v_5654);
    env = stack[0];
    {
        fn = elt(env, 2); // ra_budan!-0!-1
        return (*qfn1(fn))(fn, v_5654);
    }
}



// Code for lalr_generate_lr0_collection

static LispObject CC_lalr_generate_lr0_collection(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_5756, v_5757, v_5758;
    LispObject fn;
    argcheck(nargs, 0, "lalr_generate_lr0_collection");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// end of prologue
    goto v_5655;
v_5651:
    fn = elt(env, 4); // lalr_lr0_initial_itemset
    v_5757 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    goto v_5652;
v_5653:
    v_5756 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5654;
v_5655:
    goto v_5651;
v_5652:
    goto v_5653;
v_5654:
    v_5756 = cons(v_5757, v_5756);
    env = stack[-7];
    v_5756 = ncons(v_5756);
    env = stack[-7];
    qvalue(elt(env, 2)) = v_5756; // itemset_collection
    v_5756 = qvalue(elt(env, 2)); // itemset_collection
    v_5756 = qcar(v_5756);
    v_5756 = ncons(v_5756);
    env = stack[-7];
    stack[-6] = v_5756;
    v_5756 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-5] = v_5756;
v_5664:
    v_5756 = stack[-6];
    if (v_5756 == nil) goto v_5667;
    else goto v_5668;
v_5667:
    goto v_5663;
v_5668:
    v_5756 = stack[-6];
    v_5756 = qcar(v_5756);
    stack[-4] = v_5756;
    v_5756 = stack[-6];
    v_5756 = qcdr(v_5756);
    stack[-6] = v_5756;
    v_5756 = stack[-4];
    v_5756 = qcar(v_5756);
    stack[-3] = v_5756;
    v_5756 = qvalue(elt(env, 3)); // symbols
    stack[-2] = v_5756;
v_5680:
    v_5756 = stack[-2];
    if (v_5756 == nil) goto v_5684;
    else goto v_5685;
v_5684:
    goto v_5679;
v_5685:
    v_5756 = stack[-2];
    v_5756 = qcar(v_5756);
    stack[-1] = v_5756;
    goto v_5700;
v_5696:
    v_5757 = stack[-3];
    goto v_5697;
v_5698:
    v_5756 = stack[-1];
    goto v_5699;
v_5700:
    goto v_5696;
v_5697:
    goto v_5698;
v_5699:
    fn = elt(env, 5); // lalr_compute_lr0_goto
    v_5756 = (*qfn2(fn))(fn, v_5757, v_5756);
    env = stack[-7];
    v_5757 = v_5756;
    if (v_5756 == nil) goto v_5694;
    goto v_5711;
v_5707:
    v_5758 = v_5757;
    goto v_5708;
v_5709:
    v_5756 = qvalue(elt(env, 2)); // itemset_collection
    goto v_5710;
v_5711:
    goto v_5707;
v_5708:
    goto v_5709;
v_5710:
    v_5756 = Lassoc(nil, v_5758, v_5756);
    v_5758 = v_5756;
    if (v_5756 == nil) goto v_5706;
    v_5756 = v_5758;
    stack[0] = v_5756;
    goto v_5704;
v_5706:
    goto v_5723;
v_5719:
    stack[0] = v_5757;
    goto v_5720;
v_5721:
    v_5756 = stack[-5];
    v_5756 = add1(v_5756);
    env = stack[-7];
    stack[-5] = v_5756;
    goto v_5722;
v_5723:
    goto v_5719;
v_5720:
    goto v_5721;
v_5722:
    v_5756 = cons(stack[0], v_5756);
    env = stack[-7];
    stack[0] = v_5756;
    goto v_5732;
v_5728:
    v_5757 = stack[0];
    goto v_5729;
v_5730:
    v_5756 = qvalue(elt(env, 2)); // itemset_collection
    goto v_5731;
v_5732:
    goto v_5728;
v_5729:
    goto v_5730;
v_5731:
    v_5756 = cons(v_5757, v_5756);
    env = stack[-7];
    qvalue(elt(env, 2)) = v_5756; // itemset_collection
    goto v_5740;
v_5736:
    v_5757 = stack[0];
    goto v_5737;
v_5738:
    v_5756 = stack[-6];
    goto v_5739;
v_5740:
    goto v_5736;
v_5737:
    goto v_5738;
v_5739:
    v_5756 = cons(v_5757, v_5756);
    env = stack[-7];
    stack[-6] = v_5756;
    goto v_5704;
v_5704:
    goto v_5750;
v_5744:
    v_5758 = stack[-4];
    goto v_5745;
v_5746:
    v_5757 = stack[-1];
    goto v_5747;
v_5748:
    v_5756 = stack[0];
    goto v_5749;
v_5750:
    goto v_5744;
v_5745:
    goto v_5746;
v_5747:
    goto v_5748;
v_5749:
    fn = elt(env, 6); // lalr_add_goto
    v_5756 = (*qfnn(fn))(fn, 3, v_5758, v_5757, v_5756);
    env = stack[-7];
    goto v_5692;
v_5694:
v_5692:
    v_5756 = stack[-2];
    v_5756 = qcdr(v_5756);
    stack[-2] = v_5756;
    goto v_5680;
v_5679:
    goto v_5664;
v_5663:
    v_5756 = nil;
    return onevalue(v_5756);
}



// Code for ofsf_posvarpat

static LispObject CC_ofsf_posvarpat(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5683, v_5684, v_5685;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5639;
    v_5685 = v_5638;
// end of prologue
    v_5683 = v_5685;
    if (!consp(v_5683)) goto v_5647;
    else goto v_5648;
v_5647:
    v_5683 = v_5685;
    goto v_5646;
v_5648:
    v_5683 = v_5685;
    v_5683 = qcar(v_5683);
    goto v_5646;
    v_5683 = nil;
v_5646:
    stack[-1] = v_5683;
    goto v_5663;
v_5659:
    v_5684 = stack[-1];
    goto v_5660;
v_5661:
    v_5683 = elt(env, 2); // (greaterp geq)
    goto v_5662;
v_5663:
    goto v_5659;
v_5660:
    goto v_5661;
v_5662:
    v_5683 = Lmemq(nil, v_5684, v_5683);
    if (v_5683 == nil) goto v_5657;
    else goto v_5658;
v_5657:
    v_5683 = nil;
    goto v_5643;
v_5658:
    goto v_5676;
v_5672:
    v_5683 = v_5685;
    v_5683 = qcdr(v_5683);
    v_5683 = qcar(v_5683);
    fn = elt(env, 3); // sfto_varp
    v_5684 = (*qfn1(fn))(fn, v_5683);
    goto v_5673;
v_5674:
    v_5683 = stack[0];
    goto v_5675;
v_5676:
    goto v_5672;
v_5673:
    goto v_5674;
v_5675:
    if (v_5684 == v_5683) goto v_5670;
    else goto v_5671;
v_5670:
    v_5683 = stack[-1];
    goto v_5643;
v_5671:
    v_5683 = nil;
v_5643:
    return onevalue(v_5683);
}



// Code for janettreefind

static LispObject CC_janettreefind(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5773, v_5774;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_5638;
// end of prologue
    v_5773 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    if (v_5773 == nil) goto v_5642;
    else goto v_5643;
v_5642:
    v_5773 = nil;
    goto v_5641;
v_5643:
    stack[-5] = nil;
    v_5773 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    stack[-3] = v_5773;
    goto v_5662;
v_5658:
    v_5774 = stack[-4];
    goto v_5659;
v_5660:
    v_5773 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5661;
v_5662:
    goto v_5658;
v_5659:
    goto v_5660;
v_5661:
    v_5773 = *(LispObject *)((char *)v_5774 + (CELL-TAG_VECTOR) + (((intptr_t)v_5773-TAG_FIXNUM)/(16/CELL)));
    stack[-2] = v_5773;
    v_5773 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_5773;
v_5669:
    goto v_5678;
v_5674:
    v_5774 = stack[-2];
    goto v_5675;
v_5676:
    v_5773 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5677;
v_5678:
    goto v_5674;
v_5675:
    goto v_5676;
v_5677:
    if (((intptr_t)(v_5774)) > ((intptr_t)(v_5773))) goto v_5673;
    goto v_5668;
v_5673:
v_5684:
    goto v_5695;
v_5691:
    v_5773 = stack[-3];
    v_5773 = qcar(v_5773);
    stack[0] = qcar(v_5773);
    goto v_5692;
v_5693:
    goto v_5704;
v_5700:
    v_5774 = stack[-4];
    goto v_5701;
v_5702:
    v_5773 = stack[-1];
    goto v_5703;
v_5704:
    goto v_5700;
v_5701:
    goto v_5702;
v_5703:
    fn = elt(env, 3); // monomgetvariabledegree
    v_5773 = (*qfn2(fn))(fn, v_5774, v_5773);
    env = stack[-6];
    goto v_5694;
v_5695:
    goto v_5691;
v_5692:
    goto v_5693;
v_5694:
    v_5773 = (LispObject)lessp2(stack[0], v_5773);
    v_5773 = v_5773 ? lisp_true : nil;
    env = stack[-6];
    if (v_5773 == nil) goto v_5687;
    v_5773 = stack[-3];
    v_5773 = qcdr(v_5773);
    v_5773 = qcar(v_5773);
    if (v_5773 == nil) goto v_5687;
    goto v_5688;
v_5687:
    goto v_5683;
v_5688:
    v_5773 = stack[-3];
    v_5773 = qcdr(v_5773);
    v_5773 = qcar(v_5773);
    stack[-3] = v_5773;
    goto v_5684;
v_5683:
    goto v_5724;
v_5720:
    v_5773 = stack[-3];
    v_5773 = qcar(v_5773);
    stack[0] = qcar(v_5773);
    goto v_5721;
v_5722:
    goto v_5733;
v_5729:
    v_5774 = stack[-4];
    goto v_5730;
v_5731:
    v_5773 = stack[-1];
    goto v_5732;
v_5733:
    goto v_5729;
v_5730:
    goto v_5731;
v_5732:
    fn = elt(env, 3); // monomgetvariabledegree
    v_5773 = (*qfn2(fn))(fn, v_5774, v_5773);
    env = stack[-6];
    goto v_5723;
v_5724:
    goto v_5720;
v_5721:
    goto v_5722;
v_5723:
    if (equal(stack[0], v_5773)) goto v_5719;
    v_5773 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_5773;
    goto v_5717;
v_5719:
    v_5773 = stack[-3];
    v_5773 = qcdr(v_5773);
    v_5773 = qcdr(v_5773);
    if (v_5773 == nil) goto v_5739;
    goto v_5747;
v_5743:
    stack[0] = stack[-2];
    goto v_5744;
v_5745:
    goto v_5754;
v_5750:
    v_5774 = stack[-4];
    goto v_5751;
v_5752:
    v_5773 = stack[-1];
    goto v_5753;
v_5754:
    goto v_5750;
v_5751:
    goto v_5752;
v_5753:
    fn = elt(env, 3); // monomgetvariabledegree
    v_5773 = (*qfn2(fn))(fn, v_5774, v_5773);
    env = stack[-6];
    goto v_5746;
v_5747:
    goto v_5743;
v_5744:
    goto v_5745;
v_5746:
    v_5773 = (LispObject)(intptr_t)((intptr_t)stack[0] - (intptr_t)v_5773 + TAG_FIXNUM);
    stack[-2] = v_5773;
    v_5773 = stack[-1];
    v_5773 = (LispObject)((intptr_t)(v_5773) + 0x10);
    stack[-1] = v_5773;
    v_5773 = stack[-3];
    v_5773 = qcdr(v_5773);
    v_5773 = qcdr(v_5773);
    stack[-3] = v_5773;
    goto v_5717;
v_5739:
    v_5773 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_5773;
    v_5773 = stack[-3];
    v_5773 = qcar(v_5773);
    v_5773 = qcdr(v_5773);
    stack[-5] = v_5773;
    goto v_5717;
v_5717:
    goto v_5669;
v_5668:
    v_5773 = stack[-5];
    goto v_5641;
    v_5773 = nil;
v_5641:
    return onevalue(v_5773);
}



// Code for preptayexp

static LispObject CC_preptayexp(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5650, v_5651;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5651 = v_5638;
// end of prologue
    v_5650 = v_5651;
    if (!consp(v_5650)) goto v_5642;
    else goto v_5643;
v_5642:
    v_5650 = v_5651;
    goto v_5641;
v_5643:
    v_5650 = v_5651;
    {
        fn = elt(env, 1); // rnprep!:
        return (*qfn1(fn))(fn, v_5650);
    }
    v_5650 = nil;
v_5641:
    return onevalue(v_5650);
}



// Code for qqe_number!-of!-tails!-in!-qterm

static LispObject CC_qqe_numberKofKtailsKinKqterm(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5668, v_5669;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_5638;
// end of prologue
v_5642:
    v_5668 = stack[0];
    if (!consp(v_5668)) goto v_5645;
    else goto v_5646;
v_5645:
    v_5668 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5641;
v_5646:
    goto v_5655;
v_5651:
    v_5668 = stack[0];
    fn = elt(env, 2); // qqe_op
    v_5669 = (*qfn1(fn))(fn, v_5668);
    env = stack[-1];
    goto v_5652;
v_5653:
    v_5668 = elt(env, 1); // (ladd radd)
    goto v_5654;
v_5655:
    goto v_5651;
v_5652:
    goto v_5653;
v_5654:
    v_5668 = Lmemq(nil, v_5669, v_5668);
    if (v_5668 == nil) goto v_5650;
    v_5668 = stack[0];
    fn = elt(env, 3); // qqe_arg2r
    v_5668 = (*qfn1(fn))(fn, v_5668);
    env = stack[-1];
    stack[0] = v_5668;
    goto v_5642;
v_5650:
    v_5668 = stack[0];
    fn = elt(env, 4); // qqe_arg2l
    v_5668 = (*qfn1(fn))(fn, v_5668);
    env = stack[-1];
    v_5668 = CC_qqe_numberKofKtailsKinKqterm(elt(env, 0), v_5668);
    return add1(v_5668);
    v_5668 = nil;
v_5641:
    return onevalue(v_5668);
}



// Code for ibalp_simpat

static LispObject CC_ibalp_simpat(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5659;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5638);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_5638;
// end of prologue
    goto v_5647;
v_5641:
    v_5659 = stack[-1];
    stack[-2] = qcar(v_5659);
    goto v_5642;
v_5643:
    v_5659 = stack[-1];
    v_5659 = qcdr(v_5659);
    v_5659 = qcar(v_5659);
    fn = elt(env, 1); // ibalp_simpterm
    stack[0] = (*qfn1(fn))(fn, v_5659);
    env = stack[-3];
    goto v_5644;
v_5645:
    v_5659 = stack[-1];
    v_5659 = qcdr(v_5659);
    v_5659 = qcdr(v_5659);
    v_5659 = qcar(v_5659);
    fn = elt(env, 1); // ibalp_simpterm
    v_5659 = (*qfn1(fn))(fn, v_5659);
    env = stack[-3];
    goto v_5646;
v_5647:
    goto v_5641;
v_5642:
    goto v_5643;
v_5644:
    goto v_5645;
v_5646:
    {
        LispObject v_5663 = stack[-2];
        LispObject v_5664 = stack[0];
        fn = elt(env, 2); // ibalp_mk2
        return (*qfnn(fn))(fn, 3, v_5663, v_5664, v_5659);
    }
}



// Code for vdplength

static LispObject CC_vdplength(LispObject env,
                         LispObject v_5638)
{
    env = qenv(env);
    LispObject v_5646;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5646 = v_5638;
// end of prologue
    v_5646 = qcdr(v_5646);
    v_5646 = qcdr(v_5646);
    v_5646 = qcdr(v_5646);
    v_5646 = qcar(v_5646);
    {
        fn = elt(env, 1); // diplength
        return (*qfn1(fn))(fn, v_5646);
    }
}



// Code for cut!:ep

static LispObject CC_cutTep(LispObject env,
                         LispObject v_5638, LispObject v_5639)
{
    env = qenv(env);
    LispObject v_5731, v_5732;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_5639,v_5638);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_5638,v_5639);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_5639;
    stack[-2] = v_5638;
// end of prologue
    goto v_5658;
v_5654:
    v_5732 = stack[-2];
    goto v_5655;
v_5656:
    v_5731 = elt(env, 1); // !:rd!:
    goto v_5657;
v_5658:
    goto v_5654;
v_5655:
    goto v_5656;
v_5657:
    if (!consp(v_5732)) goto v_5652;
    v_5732 = qcar(v_5732);
    if (v_5732 == v_5731) goto v_5651;
    else goto v_5652;
v_5651:
    v_5731 = stack[-2];
    v_5731 = qcdr(v_5731);
    v_5731 = (consp(v_5731) ? nil : lisp_true);
    v_5731 = (v_5731 == nil ? lisp_true : nil);
    goto v_5650;
v_5652:
    v_5731 = nil;
    goto v_5650;
    v_5731 = nil;
v_5650:
    if (v_5731 == nil) goto v_5648;
    v_5731 = stack[-1];
    v_5731 = integerp(v_5731);
    goto v_5646;
v_5648:
    v_5731 = nil;
    goto v_5646;
    v_5731 = nil;
v_5646:
    if (v_5731 == nil) goto v_5644;
    goto v_5682;
v_5678:
    goto v_5688;
v_5684:
    v_5732 = stack[-1];
    goto v_5685;
v_5686:
    v_5731 = stack[-2];
    v_5731 = qcdr(v_5731);
    v_5731 = qcdr(v_5731);
    goto v_5687;
v_5688:
    goto v_5684;
v_5685:
    goto v_5686;
v_5687:
    v_5732 = difference2(v_5732, v_5731);
    env = stack[-4];
    stack[-1] = v_5732;
    goto v_5679;
v_5680:
    v_5731 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5681;
v_5682:
    goto v_5678;
v_5679:
    goto v_5680;
v_5681:
    v_5731 = (LispObject)lesseq2(v_5732, v_5731);
    v_5731 = v_5731 ? lisp_true : nil;
    env = stack[-4];
    if (v_5731 == nil) goto v_5676;
    v_5731 = stack[-2];
    goto v_5674;
v_5676:
    goto v_5704;
v_5698:
    stack[-3] = elt(env, 1); // !:rd!:
    goto v_5699;
v_5700:
    goto v_5711;
v_5707:
    v_5731 = stack[-2];
    v_5731 = qcdr(v_5731);
    stack[0] = qcar(v_5731);
    goto v_5708;
v_5709:
    v_5731 = stack[-1];
    v_5731 = negate(v_5731);
    env = stack[-4];
    goto v_5710;
v_5711:
    goto v_5707;
v_5708:
    goto v_5709;
v_5710:
    fn = elt(env, 2); // ashift
    stack[0] = (*qfn2(fn))(fn, stack[0], v_5731);
    env = stack[-4];
    goto v_5701;
v_5702:
    goto v_5722;
v_5718:
    v_5731 = stack[-2];
    v_5731 = qcdr(v_5731);
    v_5732 = qcdr(v_5731);
    goto v_5719;
v_5720:
    v_5731 = stack[-1];
    goto v_5721;
v_5722:
    goto v_5718;
v_5719:
    goto v_5720;
v_5721:
    v_5731 = plus2(v_5732, v_5731);
    goto v_5703;
v_5704:
    goto v_5698;
v_5699:
    goto v_5700;
v_5701:
    goto v_5702;
v_5703:
    {
        LispObject v_5737 = stack[-3];
        LispObject v_5738 = stack[0];
        return list2star(v_5737, v_5738, v_5731);
    }
    v_5731 = nil;
v_5674:
    goto v_5642;
v_5644:
    v_5731 = elt(env, 0); // cut!:ep
    {
        fn = elt(env, 3); // bflerrmsg
        return (*qfn1(fn))(fn, v_5731);
    }
    v_5731 = nil;
v_5642:
    return onevalue(v_5731);
}



setup_type const u11_setup[] =
{
    {"assert_analyze",          WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_assert_analyze},
    {"lambda_46uwl1lq71ua2",    TOO_FEW_2,      CC_lambda_46uwl1lq71ua2,WRONG_NO_2},
    {"red_better",              TOO_FEW_2,      CC_red_better, WRONG_NO_2},
    {"oprin",                   CC_oprin,       TOO_MANY_1,    WRONG_NO_1},
    {"*i2gi",                   CC_Hi2gi,       TOO_MANY_1,    WRONG_NO_1},
    {"split_ext",               TOO_FEW_2,      CC_split_ext,  WRONG_NO_2},
    {"portable_print",          CC_portable_print,TOO_MANY_1,  WRONG_NO_1},
    {"formc",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formc},
    {"talp_simplt1",            TOO_FEW_2,      CC_talp_simplt1,WRONG_NO_2},
    {"mri_2pasfat",             CC_mri_2pasfat, TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_vequal",            TOO_FEW_2,      CC_ibalp_vequal,WRONG_NO_2},
    {"vdp_zero?",               CC_vdp_zeroW,   TOO_MANY_1,    WRONG_NO_1},
    {"objectom",                CC_objectom,    TOO_MANY_1,    WRONG_NO_1},
    {"bcone?",                  CC_bconeW,      TOO_MANY_1,    WRONG_NO_1},
    {"contrsp",                 TOO_FEW_2,      CC_contrsp,    WRONG_NO_2},
    {"lispapply",               TOO_FEW_2,      CC_lispapply,  WRONG_NO_2},
    {"ord",                     CC_ord,         TOO_MANY_1,    WRONG_NO_1},
    {"th_match0",               TOO_FEW_2,      CC_th_match0,  WRONG_NO_2},
    {"exptf",                   TOO_FEW_2,      CC_exptf,      WRONG_NO_2},
    {"lalr_list_of_actions",    CC_lalr_list_of_actions,TOO_MANY_1,WRONG_NO_1},
    {"quotfx",                  TOO_FEW_2,      CC_quotfx,     WRONG_NO_2},
    {"ofsf_smwupdknowl",        WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smwupdknowl},
    {"diffp1",                  TOO_FEW_2,      CC_diffp1,     WRONG_NO_2},
    {"rl_external",             TOO_FEW_2,      CC_rl_external,WRONG_NO_2},
    {"exchk2",                  TOO_FEW_2,      CC_exchk2,     WRONG_NO_2},
    {"on",                      CC_on,          TOO_MANY_1,    WRONG_NO_1},
    {"vdpgetprop",              TOO_FEW_2,      CC_vdpgetprop, WRONG_NO_2},
    {"has_parents",             CC_has_parents, TOO_MANY_1,    WRONG_NO_1},
    {"sc_kern",                 CC_sc_kern,     TOO_MANY_1,    WRONG_NO_1},
    {"list_assoc",              TOO_FEW_2,      CC_list_assoc, WRONG_NO_2},
    {"aex_simplenullp",         CC_aex_simplenullp,TOO_MANY_1, WRONG_NO_1},
    {"ofsf_ordatp",             TOO_FEW_2,      CC_ofsf_ordatp,WRONG_NO_2},
    {"polynommultiplybymonom",  TOO_FEW_2,      CC_polynommultiplybymonom,WRONG_NO_2},
    {"revv0",                   TOO_FEW_2,      CC_revv0,      WRONG_NO_2},
    {"cl_smcpknowl",            CC_cl_smcpknowl,TOO_MANY_1,    WRONG_NO_1},
    {"ofsf_prepat",             CC_ofsf_prepat, TOO_MANY_1,    WRONG_NO_1},
    {"quotfail-mod-p",          TOO_FEW_2,      CC_quotfailKmodKp,WRONG_NO_2},
    {"expression",              CC_expression,  TOO_MANY_1,    WRONG_NO_1},
    {"smtp",                    TOO_FEW_2,      CC_smtp,       WRONG_NO_2},
    {"off",                     CC_off,         TOO_MANY_1,    WRONG_NO_1},
    {"xord_lex",                TOO_FEW_2,      CC_xord_lex,   WRONG_NO_2},
    {":difference",             TOO_FEW_2,      CC_Tdifference,WRONG_NO_2},
    {"getphystype",             CC_getphystype, TOO_MANY_1,    WRONG_NO_1},
    {"lprim",                   CC_lprim,       TOO_MANY_1,    WRONG_NO_1},
    {"mv-domainlist--",         TOO_FEW_2,      CC_mvKdomainlistKK,WRONG_NO_2},
    {"formop",                  CC_formop,      TOO_MANY_1,    WRONG_NO_1},
    {"listtest",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_listtest},
    {"leftzeros",               CC_leftzeros,   TOO_MANY_1,    WRONG_NO_1},
    {"get_action_without_lookahead",CC_get_action_without_lookahead,TOO_MANY_1,WRONG_NO_1},
    {"polynomlistfinddivisor",  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_polynomlistfinddivisor},
    {"tayexp-difference",       TOO_FEW_2,      CC_tayexpKdifference,WRONG_NO_2},
    {"cl_varl1",                CC_cl_varl1,    TOO_MANY_1,    WRONG_NO_1},
    {"lastnondomain",           CC_lastnondomain,TOO_MANY_1,   WRONG_NO_1},
    {"rl_gettype",              CC_rl_gettype,  TOO_MANY_1,    WRONG_NO_1},
    {"omair",                   WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_omair},
    {"dfn_prop",                CC_dfn_prop,    TOO_MANY_1,    WRONG_NO_1},
    {"mkuwedge",                CC_mkuwedge,    TOO_MANY_1,    WRONG_NO_1},
    {"plus:",                   TOO_FEW_2,      CC_plusT,      WRONG_NO_2},
    {"*id2num",                 CC_Hid2num,     TOO_MANY_1,    WRONG_NO_1},
    {"arintequiv:",             CC_arintequivT, TOO_MANY_1,    WRONG_NO_1},
    {"reduce-mod-p",            CC_reduceKmodKp,TOO_MANY_1,    WRONG_NO_1},
    {"ra_budancount",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ra_budancount},
    {"lalr_generate_lr0_collection",WRONG_NO_NA,WRONG_NO_NB,   (n_args *)CC_lalr_generate_lr0_collection},
    {"ofsf_posvarpat",          TOO_FEW_2,      CC_ofsf_posvarpat,WRONG_NO_2},
    {"janettreefind",           CC_janettreefind,TOO_MANY_1,   WRONG_NO_1},
    {"preptayexp",              CC_preptayexp,  TOO_MANY_1,    WRONG_NO_1},
    {"qqe_number-of-tails-in-qterm",CC_qqe_numberKofKtailsKinKqterm,TOO_MANY_1,WRONG_NO_1},
    {"ibalp_simpat",            CC_ibalp_simpat,TOO_MANY_1,    WRONG_NO_1},
    {"vdplength",               CC_vdplength,   TOO_MANY_1,    WRONG_NO_1},
    {"cut:ep",                  TOO_FEW_2,      CC_cutTep,     WRONG_NO_2},
    {NULL, (one_args *)"u11", (two_args *)"36718 5228724 9279058", 0}
};

// end of generated code
