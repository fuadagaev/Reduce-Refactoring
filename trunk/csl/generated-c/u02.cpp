
// $destdir/u02.c        Machine generated C code

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



// Code for general!-modular!-times

static LispObject CC_generalKmodularKtimes(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_456, v_457;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_456 = v_414;
    v_457 = v_413;
// end of prologue
    goto v_425;
v_421:
    goto v_431;
v_427:
    goto v_428;
v_429:
    goto v_430;
v_431:
    goto v_427;
v_428:
    goto v_429;
v_430:
    v_457 = times2(v_457, v_456);
    env = stack[-1];
    goto v_422;
v_423:
    v_456 = qvalue(elt(env, 2)); // current!-modulus
    goto v_424;
v_425:
    goto v_421;
v_422:
    goto v_423;
v_424:
    v_456 = Cremainder(v_457, v_456);
    env = stack[-1];
    stack[0] = v_456;
    goto v_444;
v_440:
    v_457 = stack[0];
    goto v_441;
v_442:
    v_456 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_443;
v_444:
    goto v_440;
v_441:
    goto v_442;
v_443:
    v_456 = (LispObject)lessp2(v_457, v_456);
    v_456 = v_456 ? lisp_true : nil;
    env = stack[-1];
    if (v_456 == nil) goto v_438;
    goto v_452;
v_448:
    v_457 = stack[0];
    goto v_449;
v_450:
    v_456 = qvalue(elt(env, 2)); // current!-modulus
    goto v_451;
v_452:
    goto v_448;
v_449:
    goto v_450;
v_451:
    v_456 = plus2(v_457, v_456);
    stack[0] = v_456;
    goto v_436;
v_438:
v_436:
    v_456 = stack[0];
    return onevalue(v_456);
}



// Code for multd

static LispObject CC_multd(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_498, v_499;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_414;
    stack[-2] = v_413;
// end of prologue
    stack[-3] = nil;
v_419:
    v_498 = stack[-1];
    if (v_498 == nil) goto v_422;
    else goto v_423;
v_422:
    v_498 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_498);
    }
v_423:
    goto v_433;
v_429:
    v_499 = stack[-1];
    goto v_430;
v_431:
    v_498 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_432;
v_433:
    goto v_429;
v_430:
    goto v_431;
v_432:
    if (v_499 == v_498) goto v_427;
    else goto v_428;
v_427:
    goto v_441;
v_437:
    v_499 = stack[-3];
    goto v_438;
v_439:
    v_498 = stack[-2];
    goto v_440;
v_441:
    goto v_437;
v_438:
    goto v_439;
v_440:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_499, v_498);
    }
v_428:
    v_498 = stack[-1];
    if (!consp(v_498)) goto v_448;
    else goto v_449;
v_448:
    v_498 = lisp_true;
    goto v_447;
v_449:
    v_498 = stack[-1];
    v_498 = qcar(v_498);
    v_498 = (consp(v_498) ? nil : lisp_true);
    goto v_447;
    v_498 = nil;
v_447:
    if (v_498 == nil) goto v_445;
    goto v_462;
v_458:
    stack[0] = stack[-3];
    goto v_459;
v_460:
    goto v_469;
v_465:
    v_499 = stack[-2];
    goto v_466;
v_467:
    v_498 = stack[-1];
    goto v_468;
v_469:
    goto v_465;
v_466:
    goto v_467;
v_468:
    fn = elt(env, 2); // multdm
    v_498 = (*qfn2(fn))(fn, v_499, v_498);
    env = stack[-4];
    goto v_461;
v_462:
    goto v_458;
v_459:
    goto v_460;
v_461:
    {
        LispObject v_504 = stack[0];
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_504, v_498);
    }
v_445:
    goto v_481;
v_475:
    v_498 = stack[-1];
    v_498 = qcar(v_498);
    stack[0] = qcar(v_498);
    goto v_476;
v_477:
    goto v_490;
v_486:
    v_499 = stack[-2];
    goto v_487;
v_488:
    v_498 = stack[-1];
    v_498 = qcar(v_498);
    v_498 = qcdr(v_498);
    goto v_489;
v_490:
    goto v_486;
v_487:
    goto v_488;
v_489:
    v_499 = CC_multd(elt(env, 0), v_499, v_498);
    env = stack[-4];
    goto v_478;
v_479:
    v_498 = stack[-3];
    goto v_480;
v_481:
    goto v_475;
v_476:
    goto v_477;
v_478:
    goto v_479;
v_480:
    v_498 = acons(stack[0], v_499, v_498);
    env = stack[-4];
    stack[-3] = v_498;
    v_498 = stack[-1];
    v_498 = qcdr(v_498);
    stack[-1] = v_498;
    goto v_419;
    v_498 = nil;
    return onevalue(v_498);
}



// Code for lalr_lr0_move_dot

static LispObject CC_lalr_lr0_move_dot(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_499, v_500, v_501;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_414;
    stack[-1] = v_413;
// end of prologue
    stack[-2] = nil;
v_422:
    goto v_431;
v_427:
    v_499 = stack[-1];
    v_500 = qcar(v_499);
    goto v_428;
v_429:
    v_499 = elt(env, 2); // !.
    goto v_430;
v_431:
    goto v_427;
v_428:
    goto v_429;
v_430:
    if (v_500 == v_499) goto v_425;
    else goto v_426;
v_425:
    goto v_421;
v_426:
    goto v_441;
v_437:
    v_499 = stack[-1];
    v_500 = qcar(v_499);
    goto v_438;
v_439:
    v_499 = stack[-2];
    goto v_440;
v_441:
    goto v_437;
v_438:
    goto v_439;
v_440:
    v_499 = cons(v_500, v_499);
    env = stack[-3];
    stack[-2] = v_499;
    v_499 = stack[-1];
    v_499 = qcdr(v_499);
    stack[-1] = v_499;
    goto v_422;
v_421:
    v_499 = stack[-1];
    v_499 = qcdr(v_499);
    stack[-1] = v_499;
    v_499 = stack[-1];
    if (v_499 == nil) goto v_451;
    goto v_460;
v_456:
    v_499 = stack[-1];
    v_500 = qcar(v_499);
    goto v_457;
v_458:
    v_499 = stack[0];
    goto v_459;
v_460:
    goto v_456;
v_457:
    goto v_458;
v_459:
    if (equal(v_500, v_499)) goto v_455;
    else goto v_451;
v_455:
    goto v_452;
v_451:
    v_499 = nil;
    goto v_418;
v_452:
    goto v_472;
v_466:
    v_499 = stack[-1];
    v_501 = qcar(v_499);
    goto v_467;
v_468:
    v_500 = elt(env, 2); // !.
    goto v_469;
v_470:
    v_499 = stack[-1];
    v_499 = qcdr(v_499);
    goto v_471;
v_472:
    goto v_466;
v_467:
    goto v_468;
v_469:
    goto v_470;
v_471:
    v_499 = list2star(v_501, v_500, v_499);
    env = stack[-3];
    stack[-1] = v_499;
v_480:
    v_499 = stack[-2];
    if (v_499 == nil) goto v_483;
    else goto v_484;
v_483:
    goto v_479;
v_484:
    goto v_492;
v_488:
    v_499 = stack[-2];
    v_500 = qcar(v_499);
    goto v_489;
v_490:
    v_499 = stack[-1];
    goto v_491;
v_492:
    goto v_488;
v_489:
    goto v_490;
v_491:
    v_499 = cons(v_500, v_499);
    env = stack[-3];
    stack[-1] = v_499;
    v_499 = stack[-2];
    v_499 = qcdr(v_499);
    stack[-2] = v_499;
    goto v_480;
v_479:
    v_499 = stack[-1];
v_418:
    return onevalue(v_499);
}



// Code for reorder

static LispObject CC_reorder(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_477, v_478;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_413;
// end of prologue
    stack[-2] = nil;
v_419:
    v_477 = stack[-1];
    if (!consp(v_477)) goto v_428;
    else goto v_429;
v_428:
    v_477 = lisp_true;
    goto v_427;
v_429:
    v_477 = stack[-1];
    v_477 = qcar(v_477);
    v_477 = (consp(v_477) ? nil : lisp_true);
    goto v_427;
    v_477 = nil;
v_427:
    if (v_477 == nil) goto v_425;
    goto v_420;
v_425:
    goto v_442;
v_438:
    goto v_448;
v_444:
    v_477 = stack[-1];
    v_477 = qcar(v_477);
    stack[0] = qcar(v_477);
    goto v_445;
v_446:
    v_477 = stack[-1];
    v_477 = qcar(v_477);
    v_477 = qcdr(v_477);
    v_477 = CC_reorder(elt(env, 0), v_477);
    env = stack[-3];
    goto v_447;
v_448:
    goto v_444;
v_445:
    goto v_446;
v_447:
    fn = elt(env, 1); // rmultpf
    v_478 = (*qfn2(fn))(fn, stack[0], v_477);
    env = stack[-3];
    goto v_439;
v_440:
    v_477 = stack[-2];
    goto v_441;
v_442:
    goto v_438;
v_439:
    goto v_440;
v_441:
    v_477 = cons(v_478, v_477);
    env = stack[-3];
    stack[-2] = v_477;
    v_477 = stack[-1];
    v_477 = qcdr(v_477);
    stack[-1] = v_477;
    goto v_419;
v_420:
    v_477 = stack[-1];
    v_478 = v_477;
v_421:
    v_477 = stack[-2];
    if (v_477 == nil) goto v_462;
    else goto v_463;
v_462:
    v_477 = v_478;
    goto v_418;
v_463:
    goto v_471;
v_467:
    v_477 = stack[-2];
    v_477 = qcar(v_477);
    goto v_468;
v_469:
    goto v_470;
v_471:
    goto v_467;
v_468:
    goto v_469;
v_470:
    fn = elt(env, 2); // raddf
    v_477 = (*qfn2(fn))(fn, v_477, v_478);
    env = stack[-3];
    v_478 = v_477;
    v_477 = stack[-2];
    v_477 = qcdr(v_477);
    stack[-2] = v_477;
    goto v_421;
v_418:
    return onevalue(v_477);
}



// Code for aconc!*

static LispObject CC_aconcH(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_425, v_426;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_425 = v_414;
    v_426 = v_413;
// end of prologue
    goto v_421;
v_417:
    stack[0] = v_426;
    goto v_418;
v_419:
    v_425 = ncons(v_425);
    goto v_420;
v_421:
    goto v_417;
v_418:
    goto v_419;
v_420:
    {
        LispObject v_428 = stack[0];
        return Lnconc(nil, v_428, v_425);
    }
}



// Code for tayexp!-greaterp

static LispObject CC_tayexpKgreaterp(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_424, v_425;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_425 = v_414;
    v_424 = v_413;
// end of prologue
    goto v_421;
v_417:
    goto v_418;
v_419:
    goto v_420;
v_421:
    goto v_417;
v_418:
    goto v_419;
v_420:
    {
        fn = elt(env, 1); // tayexp!-lessp
        return (*qfn2(fn))(fn, v_425, v_424);
    }
}



// Code for !*d2q

static LispObject CC_Hd2q(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_466, v_467;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_413;
// end of prologue
    v_466 = stack[0];
    if (is_number(v_466)) goto v_417;
    else goto v_418;
v_417:
    v_466 = stack[0];
    v_466 = (LispObject)zerop(v_466);
    v_466 = v_466 ? lisp_true : nil;
    if (v_466 == nil) goto v_423;
    goto v_431;
v_427:
    v_467 = nil;
    goto v_428;
v_429:
    v_466 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_430;
v_431:
    goto v_427;
v_428:
    goto v_429;
v_430:
    return cons(v_467, v_466);
v_423:
    goto v_441;
v_437:
    v_467 = stack[0];
    goto v_438;
v_439:
    v_466 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_440;
v_441:
    goto v_437;
v_438:
    goto v_439;
v_440:
    return cons(v_467, v_466);
    v_466 = nil;
    goto v_416;
v_418:
    v_466 = stack[0];
    fn = elt(env, 1); // !:zerop
    v_466 = (*qfn1(fn))(fn, v_466);
    if (v_466 == nil) goto v_445;
    goto v_453;
v_449:
    v_467 = nil;
    goto v_450;
v_451:
    v_466 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_452;
v_453:
    goto v_449;
v_450:
    goto v_451;
v_452:
    return cons(v_467, v_466);
v_445:
    goto v_463;
v_459:
    v_467 = stack[0];
    goto v_460;
v_461:
    v_466 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_462;
v_463:
    goto v_459;
v_460:
    goto v_461;
v_462:
    return cons(v_467, v_466);
    v_466 = nil;
v_416:
    return onevalue(v_466);
}



// Code for talp_simplt

static LispObject CC_talp_simplt(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_423, v_424;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_423 = v_413;
// end of prologue
    goto v_420;
v_416:
    v_424 = v_423;
    goto v_417;
v_418:
    v_423 = nil;
    goto v_419;
v_420:
    goto v_416;
v_417:
    goto v_418;
v_419:
    {
        fn = elt(env, 1); // talp_simplt1
        return (*qfn2(fn))(fn, v_424, v_423);
    }
}



// Code for ibalp_emptyclausep

static LispObject CC_ibalp_emptyclausep(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_458, v_459;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_413;
// end of prologue
    v_458 = stack[0];
    v_458 = qcdr(v_458);
    v_458 = qcdr(v_458);
    v_458 = qcdr(v_458);
    v_458 = qcdr(v_458);
    v_458 = qcar(v_458);
    if (v_458 == nil) goto v_417;
    else goto v_418;
v_417:
    goto v_434;
v_430:
    v_458 = stack[0];
    v_458 = qcdr(v_458);
    v_458 = qcdr(v_458);
    v_459 = qcar(v_458);
    goto v_431;
v_432:
    v_458 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_433;
v_434:
    goto v_430;
v_431:
    goto v_432;
v_433:
    v_458 = Leqn(nil, v_459, v_458);
    if (v_458 == nil) goto v_427;
    else goto v_428;
v_427:
    v_458 = nil;
    goto v_426;
v_428:
    goto v_448;
v_444:
    v_458 = stack[0];
    v_458 = qcdr(v_458);
    v_458 = qcdr(v_458);
    v_458 = qcdr(v_458);
    v_459 = qcar(v_458);
    goto v_445;
v_446:
    v_458 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_447;
v_448:
    goto v_444;
v_445:
    goto v_446;
v_447:
        return Leqn(nil, v_459, v_458);
    v_458 = nil;
v_426:
    goto v_416;
v_418:
    v_458 = nil;
    goto v_416;
    v_458 = nil;
v_416:
    return onevalue(v_458);
}



// Code for compress!*

static LispObject CC_compressH(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_523, v_524, v_525, v_526;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_523 = v_413;
// end of prologue
    v_526 = nil;
    v_524 = v_523;
    v_524 = qcar(v_524);
    v_524 = Ldigitp(nil, v_524);
    env = stack[-1];
    if (v_524 == nil) goto v_422;
        return Lcompress(nil, v_523);
v_422:
    stack[0] = v_523;
v_431:
    v_523 = stack[0];
    if (v_523 == nil) goto v_435;
    else goto v_436;
v_435:
    goto v_430;
v_436:
    v_523 = stack[0];
    v_523 = qcar(v_523);
    v_525 = v_523;
    goto v_454;
v_450:
    v_524 = v_525;
    goto v_451;
v_452:
    v_523 = elt(env, 2); // !/
    goto v_453;
v_454:
    goto v_450;
v_451:
    goto v_452;
v_453:
    if (v_524 == v_523) goto v_448;
    else goto v_449;
v_448:
    v_523 = lisp_true;
    goto v_447;
v_449:
    goto v_468;
v_464:
    v_524 = v_525;
    goto v_465;
v_466:
    v_523 = elt(env, 3); // !-
    goto v_467;
v_468:
    goto v_464;
v_465:
    goto v_466;
v_467:
    if (v_524 == v_523) goto v_462;
    else goto v_463;
v_462:
    v_523 = lisp_true;
    goto v_461;
v_463:
    goto v_482;
v_478:
    v_524 = v_525;
    goto v_479;
v_480:
    v_523 = elt(env, 4); // !;
    goto v_481;
v_482:
    goto v_478;
v_479:
    goto v_480;
v_481:
    if (v_524 == v_523) goto v_476;
    else goto v_477;
v_476:
    v_523 = lisp_true;
    goto v_475;
v_477:
    goto v_492;
v_488:
    v_524 = v_525;
    goto v_489;
v_490:
    v_523 = elt(env, 5); // !.
    goto v_491;
v_492:
    goto v_488;
v_489:
    goto v_490;
v_491:
    v_523 = (v_524 == v_523 ? lisp_true : nil);
    goto v_475;
    v_523 = nil;
v_475:
    goto v_461;
    v_523 = nil;
v_461:
    goto v_447;
    v_523 = nil;
v_447:
    if (v_523 == nil) goto v_445;
    goto v_503;
v_497:
    v_524 = v_525;
    goto v_498;
v_499:
    v_523 = elt(env, 6); // !!
    goto v_500;
v_501:
    v_525 = v_526;
    goto v_502;
v_503:
    goto v_497;
v_498:
    goto v_499;
v_500:
    goto v_501;
v_502:
    v_523 = list2star(v_524, v_523, v_525);
    env = stack[-1];
    v_526 = v_523;
    goto v_443;
v_445:
    goto v_514;
v_510:
    v_523 = v_525;
    goto v_511;
v_512:
    v_524 = v_526;
    goto v_513;
v_514:
    goto v_510;
v_511:
    goto v_512;
v_513:
    v_523 = cons(v_523, v_524);
    env = stack[-1];
    v_526 = v_523;
    goto v_443;
v_443:
    v_523 = stack[0];
    v_523 = qcdr(v_523);
    stack[0] = v_523;
    goto v_431;
v_430:
    v_523 = v_526;
    v_523 = Lnreverse(nil, v_523);
    env = stack[-1];
    v_523 = Lcompress(nil, v_523);
        return Lintern(nil, v_523);
    return onevalue(v_523);
}



// Code for noncomfp1

static LispObject CC_noncomfp1(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_451;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_413;
// end of prologue
v_412:
    v_451 = stack[0];
    if (!consp(v_451)) goto v_421;
    else goto v_422;
v_421:
    v_451 = lisp_true;
    goto v_420;
v_422:
    v_451 = stack[0];
    v_451 = qcar(v_451);
    v_451 = (consp(v_451) ? nil : lisp_true);
    goto v_420;
    v_451 = nil;
v_420:
    if (v_451 == nil) goto v_417;
    else goto v_418;
v_417:
    v_451 = stack[0];
    v_451 = qcar(v_451);
    v_451 = qcar(v_451);
    v_451 = qcar(v_451);
    fn = elt(env, 1); // noncomp
    v_451 = (*qfn1(fn))(fn, v_451);
    env = stack[-1];
    if (v_451 == nil) goto v_432;
    else goto v_431;
v_432:
    v_451 = stack[0];
    v_451 = qcar(v_451);
    v_451 = qcdr(v_451);
    v_451 = CC_noncomfp1(elt(env, 0), v_451);
    env = stack[-1];
    if (v_451 == nil) goto v_440;
    else goto v_439;
v_440:
    v_451 = stack[0];
    v_451 = qcdr(v_451);
    stack[0] = v_451;
    goto v_412;
v_439:
v_431:
    goto v_416;
v_418:
    v_451 = nil;
    goto v_416;
    v_451 = nil;
v_416:
    return onevalue(v_451);
}



// Code for !*q2a

static LispObject CC_Hq2a(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_423, v_424;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_423 = v_413;
// end of prologue
    goto v_420;
v_416:
    v_424 = v_423;
    goto v_417;
v_418:
    v_423 = qvalue(elt(env, 1)); // !*nosq
    goto v_419;
v_420:
    goto v_416;
v_417:
    goto v_418;
v_419:
    {
        fn = elt(env, 2); // !*q2a1
        return (*qfn2(fn))(fn, v_424, v_423);
    }
}



// Code for !:minusp

static LispObject CC_Tminusp(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_434, v_435;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_434 = v_413;
// end of prologue
    v_435 = v_434;
    if (!consp(v_435)) goto v_417;
    else goto v_418;
v_417:
        return Lminusp(nil, v_434);
v_418:
    goto v_429;
v_425:
    v_435 = v_434;
    v_435 = qcar(v_435);
    if (!symbolp(v_435)) v_435 = nil;
    else { v_435 = qfastgets(v_435);
           if (v_435 != nil) { v_435 = elt(v_435, 30); // minusp
#ifdef RECORD_GET
             if (v_435 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v_435 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v_435 == SPID_NOPROP) v_435 = nil; }}
#endif
    goto v_426;
v_427:
    goto v_428;
v_429:
    goto v_425;
v_426:
    goto v_427;
v_428:
        return Lapply1(nil, v_435, v_434);
    v_434 = nil;
    return onevalue(v_434);
}



// Code for buchvevdivides!?

static LispObject CC_buchvevdividesW(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_450, v_451, v_452;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_414;
    stack[-1] = v_413;
// end of prologue
    goto v_425;
v_421:
    v_451 = stack[0];
    goto v_422;
v_423:
    v_450 = stack[-1];
    goto v_424;
v_425:
    goto v_421;
v_422:
    goto v_423;
v_424:
    fn = elt(env, 2); // vevmtest!?
    v_450 = (*qfn2(fn))(fn, v_451, v_450);
    env = stack[-2];
    if (v_450 == nil) goto v_418;
    else goto v_419;
v_418:
    v_450 = nil;
    goto v_417;
v_419:
    v_450 = qvalue(elt(env, 1)); // gmodule!*
    if (v_450 == nil) goto v_433;
    else goto v_434;
v_433:
    v_450 = lisp_true;
    goto v_432;
v_434:
    goto v_446;
v_440:
    v_452 = stack[-1];
    goto v_441;
v_442:
    v_451 = stack[0];
    goto v_443;
v_444:
    v_450 = qvalue(elt(env, 1)); // gmodule!*
    goto v_445;
v_446:
    goto v_440;
v_441:
    goto v_442;
v_443:
    goto v_444;
v_445:
    {
        fn = elt(env, 3); // gevcompatible1
        return (*qfnn(fn))(fn, 3, v_452, v_451, v_450);
    }
    v_450 = nil;
v_432:
    goto v_417;
    v_450 = nil;
v_417:
    return onevalue(v_450);
}



// Code for vevmtest!?

static LispObject CC_vevmtestW(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_484, v_485, v_486, v_487;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
// copy arguments values to proper place
    v_485 = v_414;
    v_486 = v_413;
// end of prologue
v_418:
    v_484 = v_485;
    if (v_484 == nil) goto v_421;
    else goto v_422;
v_421:
    v_484 = lisp_true;
    goto v_417;
v_422:
    v_484 = v_486;
    if (v_484 == nil) goto v_425;
    else goto v_426;
v_425:
    v_484 = v_485;
    if (v_484 == nil) goto v_434;
    else goto v_435;
v_434:
    v_484 = lisp_true;
    goto v_433;
v_435:
    goto v_448;
v_444:
    v_484 = v_485;
    v_486 = qcar(v_484);
    goto v_445;
v_446:
    v_484 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_447;
v_448:
    goto v_444;
v_445:
    goto v_446;
v_447:
    if (v_486 == v_484) goto v_442;
    else goto v_443;
v_442:
    v_484 = v_485;
    v_484 = qcdr(v_484);
    fn = elt(env, 1); // vevzero!?1
    v_484 = (*qfn1(fn))(fn, v_484);
    goto v_441;
v_443:
    v_484 = nil;
    goto v_441;
    v_484 = nil;
v_441:
    goto v_433;
    v_484 = nil;
v_433:
    if (v_484 == nil) goto v_431;
    v_484 = lisp_true;
    goto v_417;
v_431:
    v_484 = nil;
    goto v_417;
    goto v_420;
v_426:
    goto v_472;
v_468:
    v_484 = v_486;
    v_487 = qcar(v_484);
    goto v_469;
v_470:
    v_484 = v_485;
    v_484 = qcar(v_484);
    goto v_471;
v_472:
    goto v_468;
v_469:
    goto v_470;
v_471:
    if (((intptr_t)(v_487)) < ((intptr_t)(v_484))) goto v_467;
    v_484 = v_486;
    v_484 = qcdr(v_484);
    v_486 = v_484;
    v_484 = v_485;
    v_484 = qcdr(v_484);
    v_485 = v_484;
    goto v_418;
v_467:
    v_484 = nil;
    goto v_417;
    goto v_420;
v_420:
    v_484 = nil;
v_417:
    return onevalue(v_484);
}



// Code for ordpp

static LispObject CC_ordpp(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_486, v_487, v_488, v_489, v_490;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_488 = v_414;
    v_489 = v_413;
// end of prologue
    goto v_429;
v_425:
    v_486 = v_489;
    v_487 = qcar(v_486);
    goto v_426;
v_427:
    v_486 = v_488;
    v_486 = qcar(v_486);
    goto v_428;
v_429:
    goto v_425;
v_426:
    goto v_427;
v_428:
    if (v_487 == v_486) goto v_423;
    else goto v_424;
v_423:
    goto v_439;
v_435:
    v_486 = v_489;
    v_486 = qcdr(v_486);
    goto v_436;
v_437:
    v_487 = v_488;
    v_487 = qcdr(v_487);
    goto v_438;
v_439:
    goto v_435;
v_436:
    goto v_437;
v_438:
        return Lgreaterp(nil, v_486, v_487);
v_424:
    v_486 = qvalue(elt(env, 2)); // kord!*
    v_490 = v_486;
    v_486 = v_489;
    v_486 = qcar(v_486);
    v_489 = v_486;
    v_486 = v_488;
    v_486 = qcar(v_486);
    v_488 = v_486;
v_419:
    v_486 = v_490;
    if (v_486 == nil) goto v_451;
    else goto v_452;
v_451:
    goto v_459;
v_455:
    v_486 = v_489;
    goto v_456;
v_457:
    v_487 = v_488;
    goto v_458;
v_459:
    goto v_455;
v_456:
    goto v_457;
v_458:
    {
        fn = elt(env, 3); // ordpa
        return (*qfn2(fn))(fn, v_486, v_487);
    }
v_452:
    goto v_468;
v_464:
    v_487 = v_489;
    goto v_465;
v_466:
    v_486 = v_490;
    v_486 = qcar(v_486);
    goto v_467;
v_468:
    goto v_464;
v_465:
    goto v_466;
v_467:
    if (v_487 == v_486) goto v_462;
    else goto v_463;
v_462:
    v_486 = lisp_true;
    goto v_418;
v_463:
    goto v_479;
v_475:
    v_487 = v_488;
    goto v_476;
v_477:
    v_486 = v_490;
    v_486 = qcar(v_486);
    goto v_478;
v_479:
    goto v_475;
v_476:
    goto v_477;
v_478:
    if (v_487 == v_486) goto v_473;
    else goto v_474;
v_473:
    v_486 = nil;
    goto v_418;
v_474:
    v_486 = v_490;
    v_486 = qcdr(v_486);
    v_490 = v_486;
    goto v_419;
v_418:
    return onevalue(v_486);
}



// Code for factorordp

static LispObject CC_factorordp(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_438, v_439, v_440, v_441;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_440 = v_414;
    v_441 = v_413;
// end of prologue
    goto v_424;
v_420:
    v_439 = v_441;
    goto v_421;
v_422:
    v_438 = v_440;
    goto v_423;
v_424:
    goto v_420;
v_421:
    goto v_422;
v_423:
    if (v_439 == v_438) goto v_418;
    else goto v_419;
v_418:
    v_438 = nil;
    goto v_417;
v_419:
    goto v_435;
v_431:
    v_438 = v_441;
    goto v_432;
v_433:
    v_439 = v_440;
    goto v_434;
v_435:
    goto v_431;
v_432:
    goto v_433;
v_434:
    {
        fn = elt(env, 1); // worderp
        return (*qfn2(fn))(fn, v_438, v_439);
    }
    v_438 = nil;
v_417:
    return onevalue(v_438);
}



// Code for csl_normbf

static LispObject CC_csl_normbf(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_491, v_492, v_493;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_413;
// end of prologue
    stack[-3] = nil;
    goto v_430;
v_426:
    v_491 = stack[-2];
    v_491 = qcdr(v_491);
    v_492 = qcar(v_491);
    stack[0] = v_492;
    goto v_427;
v_428:
    v_491 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_429;
v_430:
    goto v_426;
v_427:
    goto v_428;
v_429:
    if (v_492 == v_491) goto v_424;
    else goto v_425;
v_424:
    v_491 = elt(env, 2); // (!:rd!: 0 . 0)
    goto v_419;
v_425:
    goto v_445;
v_441:
    v_492 = stack[0];
    goto v_442;
v_443:
    v_491 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_444;
v_445:
    goto v_441;
v_442:
    goto v_443;
v_444:
    v_491 = (LispObject)lessp2(v_492, v_491);
    v_491 = v_491 ? lisp_true : nil;
    env = stack[-4];
    if (v_491 == nil) goto v_439;
    v_491 = stack[0];
    v_491 = negate(v_491);
    env = stack[-4];
    stack[0] = v_491;
    v_491 = lisp_true;
    stack[-3] = v_491;
    goto v_437;
v_439:
v_437:
    v_491 = stack[0];
    fn = elt(env, 4); // lsd
    v_491 = (*qfn1(fn))(fn, v_491);
    env = stack[-4];
    v_491 = sub1(v_491);
    env = stack[-4];
    stack[-1] = v_491;
    goto v_459;
v_455:
    goto v_456;
v_457:
    v_491 = stack[-1];
    v_491 = negate(v_491);
    env = stack[-4];
    goto v_458;
v_459:
    goto v_455;
v_456:
    goto v_457;
v_458:
    fn = elt(env, 5); // lshift
    v_491 = (*qfn2(fn))(fn, stack[0], v_491);
    env = stack[-4];
    stack[0] = v_491;
    v_491 = stack[-3];
    if (v_491 == nil) goto v_466;
    v_491 = stack[0];
    v_491 = negate(v_491);
    env = stack[-4];
    stack[0] = v_491;
    goto v_464;
v_466:
v_464:
    goto v_475;
v_471:
    v_492 = stack[-1];
    goto v_472;
v_473:
    v_491 = stack[-2];
    v_491 = qcdr(v_491);
    v_491 = qcdr(v_491);
    goto v_474;
v_475:
    goto v_471;
v_472:
    goto v_473;
v_474:
    v_491 = plus2(v_492, v_491);
    env = stack[-4];
    stack[-1] = v_491;
    goto v_487;
v_481:
    v_493 = elt(env, 3); // !:rd!:
    goto v_482;
v_483:
    v_492 = stack[0];
    goto v_484;
v_485:
    v_491 = stack[-1];
    goto v_486;
v_487:
    goto v_481;
v_482:
    goto v_483;
v_484:
    goto v_485;
v_486:
    return list2star(v_493, v_492, v_491);
v_419:
    return onevalue(v_491);
}



// Code for collectindices

static LispObject CC_collectindices(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_424, v_425;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
// copy arguments values to proper place
    v_424 = v_413;
// end of prologue
    goto v_421;
v_417:
    v_425 = v_424;
    goto v_418;
v_419:
    v_424 = nil;
    goto v_420;
v_421:
    goto v_417;
v_418:
    goto v_419;
v_420:
    fn = elt(env, 1); // collectindices_reversed
    v_424 = (*qfn2(fn))(fn, v_425, v_424);
        return Lnreverse(nil, v_424);
}



// Code for reval_without_mod

static LispObject CC_reval_without_mod(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_434, v_435, v_436;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_436 = v_413;
// end of prologue
    goto v_423;
v_419:
    v_435 = qvalue(elt(env, 1)); // dmode!*
    goto v_420;
v_421:
    v_434 = elt(env, 2); // !:mod!:
    goto v_422;
v_423:
    goto v_419;
v_420:
    goto v_421;
v_422:
    if (v_435 == v_434) goto v_417;
    else goto v_418;
v_417:
    v_434 = nil;
// Binding dmode!*
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    qvalue(elt(env, 1)) = v_434; // dmode!*
    v_434 = v_436;
    fn = elt(env, 3); // reval
    v_434 = (*qfn1(fn))(fn, v_434);
    ;}  // end of a binding scope
    goto v_416;
v_418:
    v_434 = v_436;
    {
        fn = elt(env, 3); // reval
        return (*qfn1(fn))(fn, v_434);
    }
    v_434 = nil;
v_416:
    return onevalue(v_434);
}



// Code for mo!=sprod

static LispObject CC_moMsprod(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_476, v_477, v_478;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_414;
    stack[-1] = v_413;
// end of prologue
    v_478 = nil;
v_420:
    v_476 = stack[-1];
    if (v_476 == nil) goto v_429;
    else goto v_430;
v_429:
    v_476 = lisp_true;
    goto v_428;
v_430:
    v_476 = stack[0];
    v_476 = (v_476 == nil ? lisp_true : nil);
    goto v_428;
    v_476 = nil;
v_428:
    if (v_476 == nil) goto v_426;
    goto v_421;
v_426:
    goto v_442;
v_438:
    goto v_447;
v_443:
    v_476 = stack[-1];
    v_477 = qcar(v_476);
    goto v_444;
v_445:
    v_476 = stack[0];
    v_476 = qcar(v_476);
    goto v_446;
v_447:
    goto v_443;
v_444:
    goto v_445;
v_446:
    v_476 = fixnum_of_int((intptr_t)(int_of_fixnum(v_477) * int_of_fixnum(v_476)));
    goto v_439;
v_440:
    v_477 = v_478;
    goto v_441;
v_442:
    goto v_438;
v_439:
    goto v_440;
v_441:
    v_476 = cons(v_476, v_477);
    env = stack[-2];
    v_478 = v_476;
    v_476 = stack[-1];
    v_476 = qcdr(v_476);
    stack[-1] = v_476;
    v_476 = stack[0];
    v_476 = qcdr(v_476);
    stack[0] = v_476;
    goto v_420;
v_421:
    v_476 = (LispObject)0+TAG_FIXNUM; // 0
v_422:
    v_477 = v_478;
    if (v_477 == nil) goto v_461;
    else goto v_462;
v_461:
    goto v_419;
v_462:
    goto v_469;
v_465:
    v_477 = v_478;
    v_477 = qcar(v_477);
    goto v_466;
v_467:
    goto v_468;
v_469:
    goto v_465;
v_466:
    goto v_467;
v_468:
    v_476 = (LispObject)(intptr_t)((intptr_t)v_477 + (intptr_t)v_476 - TAG_FIXNUM);
    v_477 = v_478;
    v_477 = qcdr(v_477);
    v_478 = v_477;
    goto v_422;
v_419:
    return onevalue(v_476);
}



// Code for mtp

static LispObject CC_mtp(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_459, v_460, v_461;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_460 = v_413;
// end of prologue
v_412:
    v_459 = v_460;
    if (v_459 == nil) goto v_417;
    else goto v_418;
v_417:
    v_459 = lisp_true;
    goto v_416;
v_418:
    goto v_431;
v_427:
    v_459 = v_460;
    v_461 = qcar(v_459);
    goto v_428;
v_429:
    v_459 = qvalue(elt(env, 1)); // frlis!*
    goto v_430;
v_431:
    goto v_427;
v_428:
    goto v_429;
v_430:
    v_459 = Lmemq(nil, v_461, v_459);
    if (v_459 == nil) goto v_425;
    else goto v_426;
v_425:
    v_459 = nil;
    goto v_424;
v_426:
    goto v_447;
v_443:
    v_459 = v_460;
    v_461 = qcar(v_459);
    goto v_444;
v_445:
    v_459 = v_460;
    v_459 = qcdr(v_459);
    goto v_446;
v_447:
    goto v_443;
v_444:
    goto v_445;
v_446:
    v_459 = Lmember(nil, v_461, v_459);
    if (v_459 == nil) goto v_441;
    else goto v_442;
v_441:
    v_459 = v_460;
    v_459 = qcdr(v_459);
    v_460 = v_459;
    goto v_412;
v_442:
    v_459 = nil;
    goto v_440;
    v_459 = nil;
v_440:
    goto v_424;
    v_459 = nil;
v_424:
    goto v_416;
    v_459 = nil;
v_416:
    return onevalue(v_459);
}



// Code for reduce_pv

static LispObject CC_reduce_pv(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_427, v_428, v_429;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_427 = v_414;
    v_428 = v_413;
// end of prologue
    goto v_423;
v_417:
    v_429 = v_428;
    goto v_418;
v_419:
    v_428 = v_427;
    goto v_420;
v_421:
    v_427 = lisp_true;
    goto v_422;
v_423:
    goto v_417;
v_418:
    goto v_419;
v_420:
    goto v_421;
v_422:
    {
        fn = elt(env, 1); // reduce_pv0
        return (*qfnn(fn))(fn, 3, v_429, v_428, v_427);
    }
}



// Code for general!-modular!-plus

static LispObject CC_generalKmodularKplus(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_449, v_450;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_449 = v_414;
    v_450 = v_413;
// end of prologue
    goto v_425;
v_421:
    goto v_422;
v_423:
    goto v_424;
v_425:
    goto v_421;
v_422:
    goto v_423;
v_424:
    v_449 = plus2(v_450, v_449);
    env = stack[-1];
    stack[0] = v_449;
    goto v_437;
v_433:
    v_450 = stack[0];
    goto v_434;
v_435:
    v_449 = qvalue(elt(env, 2)); // current!-modulus
    goto v_436;
v_437:
    goto v_433;
v_434:
    goto v_435;
v_436:
    v_449 = (LispObject)geq2(v_450, v_449);
    v_449 = v_449 ? lisp_true : nil;
    env = stack[-1];
    if (v_449 == nil) goto v_431;
    goto v_445;
v_441:
    v_450 = stack[0];
    goto v_442;
v_443:
    v_449 = qvalue(elt(env, 2)); // current!-modulus
    goto v_444;
v_445:
    goto v_441;
v_442:
    goto v_443;
v_444:
    v_449 = difference2(v_450, v_449);
    stack[0] = v_449;
    goto v_429;
v_431:
v_429:
    v_449 = stack[0];
    return onevalue(v_449);
}



// Code for !*d2n

static LispObject CC_Hd2n(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_424, v_425;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_424 = v_413;
// end of prologue
    v_425 = v_424;
    if (v_425 == nil) goto v_417;
    else goto v_418;
v_417:
    v_424 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_416;
v_418:
    goto v_416;
    v_424 = nil;
v_416:
    return onevalue(v_424);
}



// Code for aex_ctx

static LispObject CC_aex_ctx(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_423, v_424;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_423 = v_413;
// end of prologue
    goto v_420;
v_416:
    v_424 = v_423;
    goto v_417;
v_418:
    v_423 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_419;
v_420:
    goto v_416;
v_417:
    goto v_418;
v_419:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_424, v_423);
    }
}



// Code for finde

static LispObject CC_finde(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_442, v_443, v_444, v_445;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_443 = v_414;
    v_444 = v_413;
// end of prologue
v_418:
    v_442 = v_444;
    if (v_442 == nil) goto v_421;
    else goto v_422;
v_421:
    v_442 = nil;
    goto v_417;
v_422:
    goto v_431;
v_427:
    v_445 = v_443;
    goto v_428;
v_429:
    v_442 = v_444;
    v_442 = qcar(v_442);
    v_442 = qcdr(v_442);
    goto v_430;
v_431:
    goto v_427;
v_428:
    goto v_429;
v_430:
    v_442 = Lmemq(nil, v_445, v_442);
    if (v_442 == nil) goto v_426;
    v_442 = v_444;
    goto v_417;
v_426:
    v_442 = v_444;
    v_442 = qcdr(v_442);
    v_444 = v_442;
    goto v_418;
    v_442 = nil;
v_417:
    return onevalue(v_442);
}



// Code for mchk

static LispObject CC_mchk(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_746, v_747, v_748;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_414;
    stack[-4] = v_413;
// end of prologue
v_418:
    goto v_427;
v_423:
    v_747 = stack[-4];
    goto v_424;
v_425:
    v_746 = stack[-3];
    goto v_426;
v_427:
    goto v_423;
v_424:
    goto v_425;
v_426:
    if (equal(v_747, v_746)) goto v_421;
    else goto v_422;
v_421:
    v_746 = nil;
    return ncons(v_746);
v_422:
    goto v_439;
v_435:
    v_747 = stack[-4];
    goto v_436;
v_437:
    v_746 = elt(env, 1); // !*sq
    goto v_438;
v_439:
    goto v_435;
v_436:
    goto v_437;
v_438:
    if (!consp(v_747)) goto v_433;
    v_747 = qcar(v_747);
    if (v_747 == v_746) goto v_432;
    else goto v_433;
v_432:
    v_746 = stack[-4];
    v_746 = qcdr(v_746);
    v_746 = qcar(v_746);
    fn = elt(env, 6); // prepsqxx
    v_746 = (*qfn1(fn))(fn, v_746);
    env = stack[-6];
    stack[-4] = v_746;
    goto v_418;
v_433:
    goto v_453;
v_449:
    v_747 = stack[-3];
    goto v_450;
v_451:
    v_746 = elt(env, 1); // !*sq
    goto v_452;
v_453:
    goto v_449;
v_450:
    goto v_451;
v_452:
    if (!consp(v_747)) goto v_447;
    v_747 = qcar(v_747);
    if (v_747 == v_746) goto v_446;
    else goto v_447;
v_446:
    v_746 = stack[-3];
    v_746 = qcdr(v_746);
    v_746 = qcar(v_746);
    fn = elt(env, 6); // prepsqxx
    v_746 = (*qfn1(fn))(fn, v_746);
    env = stack[-6];
    stack[-3] = v_746;
    goto v_418;
v_447:
    v_746 = stack[-3];
    if (!consp(v_746)) goto v_460;
    else goto v_461;
v_460:
    goto v_471;
v_467:
    v_747 = stack[-3];
    goto v_468;
v_469:
    v_746 = qvalue(elt(env, 2)); // frlis!*
    goto v_470;
v_471:
    goto v_467;
v_468:
    goto v_469;
v_470:
    v_746 = Lmemq(nil, v_747, v_746);
    if (v_746 == nil) goto v_466;
    goto v_482;
v_478:
    v_747 = stack[-3];
    goto v_479;
v_480:
    v_746 = stack[-4];
    goto v_481;
v_482:
    goto v_478;
v_479:
    goto v_480;
v_481:
    v_746 = cons(v_747, v_746);
    env = stack[-6];
    v_746 = ncons(v_746);
    return ncons(v_746);
v_466:
    v_746 = nil;
    goto v_417;
    goto v_420;
v_461:
    v_746 = stack[-4];
    if (!consp(v_746)) goto v_488;
    else goto v_489;
v_488:
    v_746 = stack[-4];
    if (is_number(v_746)) goto v_495;
    else goto v_494;
v_495:
    goto v_504;
v_500:
    v_747 = stack[-4];
    goto v_501;
v_502:
    v_746 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_503;
v_504:
    goto v_500;
v_501:
    goto v_502;
v_503:
    v_746 = (LispObject)lessp2(v_747, v_746);
    v_746 = v_746 ? lisp_true : nil;
    env = stack[-6];
    if (v_746 == nil) goto v_494;
    goto v_513;
v_509:
    v_747 = stack[-3];
    goto v_510;
v_511:
    v_746 = elt(env, 3); // minus
    goto v_512;
v_513:
    goto v_509;
v_510:
    goto v_511;
v_512:
    if (!consp(v_747)) goto v_494;
    v_747 = qcar(v_747);
    if (v_747 == v_746) goto v_507;
    else goto v_494;
v_507:
    goto v_521;
v_517:
    stack[0] = elt(env, 3); // minus
    goto v_518;
v_519:
    v_746 = stack[-4];
    v_746 = negate(v_746);
    env = stack[-6];
    goto v_520;
v_521:
    goto v_517;
v_518:
    goto v_519;
v_520:
    v_746 = list2(stack[0], v_746);
    env = stack[-6];
    stack[-4] = v_746;
    goto v_418;
v_494:
    goto v_532;
v_528:
    v_747 = stack[-4];
    goto v_529;
v_530:
    v_746 = stack[-3];
    goto v_531;
v_532:
    goto v_528;
v_529:
    goto v_530;
v_531:
    {
        fn = elt(env, 7); // mchkopt
        return (*qfn2(fn))(fn, v_747, v_746);
    }
    goto v_420;
v_489:
    goto v_541;
v_537:
    v_746 = stack[-3];
    v_747 = qcar(v_746);
    goto v_538;
v_539:
    v_746 = elt(env, 4); // difference
    goto v_540;
v_541:
    goto v_537;
v_538:
    goto v_539;
v_540:
    if (v_747 == v_746) goto v_535;
    else goto v_536;
v_535:
    goto v_552;
v_546:
    stack[-1] = elt(env, 5); // plus
    goto v_547;
v_548:
    v_746 = stack[-3];
    v_746 = qcdr(v_746);
    stack[0] = qcar(v_746);
    goto v_549;
v_550:
    goto v_562;
v_558:
    v_747 = elt(env, 3); // minus
    goto v_559;
v_560:
    v_746 = stack[-3];
    v_746 = qcdr(v_746);
    v_746 = qcdr(v_746);
    v_746 = qcar(v_746);
    goto v_561;
v_562:
    goto v_558;
v_559:
    goto v_560;
v_561:
    v_746 = list2(v_747, v_746);
    env = stack[-6];
    goto v_551;
v_552:
    goto v_546;
v_547:
    goto v_548;
v_549:
    goto v_550;
v_551:
    v_746 = list3(stack[-1], stack[0], v_746);
    env = stack[-6];
    stack[-3] = v_746;
    goto v_418;
v_536:
    v_746 = stack[-4];
    v_746 = qcar(v_746);
    if (!symbolp(v_746)) v_746 = nil;
    else { v_746 = qfastgets(v_746);
           if (v_746 != nil) { v_746 = elt(v_746, 8); // dname
#ifdef RECORD_GET
             if (v_746 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_746 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_746 == SPID_NOPROP) v_746 = nil; }}
#endif
    if (v_746 == nil) goto v_570;
    else goto v_568;
v_570:
    v_746 = stack[-3];
    v_746 = qcar(v_746);
    if (!symbolp(v_746)) v_746 = nil;
    else { v_746 = qfastgets(v_746);
           if (v_746 != nil) { v_746 = elt(v_746, 8); // dname
#ifdef RECORD_GET
             if (v_746 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_746 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_746 == SPID_NOPROP) v_746 = nil; }}
#endif
    if (v_746 == nil) goto v_574;
    else goto v_568;
v_574:
    goto v_569;
v_568:
    v_746 = nil;
    goto v_417;
v_569:
    goto v_585;
v_581:
    v_746 = stack[-4];
    v_747 = qcar(v_746);
    goto v_582;
v_583:
    v_746 = stack[-3];
    v_746 = qcar(v_746);
    goto v_584;
v_585:
    goto v_581;
v_582:
    goto v_583;
v_584:
    if (v_747 == v_746) goto v_579;
    else goto v_580;
v_579:
    goto v_597;
v_591:
    v_746 = stack[-4];
    v_748 = qcdr(v_746);
    goto v_592;
v_593:
    v_746 = stack[-3];
    v_747 = qcdr(v_746);
    goto v_594;
v_595:
    v_746 = stack[-4];
    v_746 = qcar(v_746);
    goto v_596;
v_597:
    goto v_591;
v_592:
    goto v_593;
v_594:
    goto v_595;
v_596:
    {
        fn = elt(env, 8); // mcharg
        return (*qfnn(fn))(fn, 3, v_748, v_747, v_746);
    }
v_580:
    goto v_610;
v_606:
    v_746 = stack[-3];
    v_747 = qcar(v_746);
    goto v_607;
v_608:
    v_746 = qvalue(elt(env, 2)); // frlis!*
    goto v_609;
v_610:
    goto v_606;
v_607:
    goto v_608;
v_609:
    v_746 = Lmemq(nil, v_747, v_746);
    if (v_746 == nil) goto v_605;
    goto v_628;
v_622:
    goto v_636;
v_630:
    v_746 = stack[-4];
    v_748 = qcar(v_746);
    goto v_631;
v_632:
    v_746 = stack[-3];
    v_747 = qcar(v_746);
    goto v_633;
v_634:
    v_746 = stack[-4];
    v_746 = qcdr(v_746);
    goto v_635;
v_636:
    goto v_630;
v_631:
    goto v_632;
v_633:
    goto v_634;
v_635:
    stack[0] = Lsubst(nil, 3, v_748, v_747, v_746);
    env = stack[-6];
    goto v_623;
v_624:
    goto v_650;
v_644:
    v_746 = stack[-4];
    v_748 = qcar(v_746);
    goto v_645;
v_646:
    v_746 = stack[-3];
    v_747 = qcar(v_746);
    goto v_647;
v_648:
    v_746 = stack[-3];
    v_746 = qcdr(v_746);
    goto v_649;
v_650:
    goto v_644;
v_645:
    goto v_646;
v_647:
    goto v_648;
v_649:
    v_747 = Lsubst(nil, 3, v_748, v_747, v_746);
    env = stack[-6];
    goto v_625;
v_626:
    v_746 = stack[-4];
    v_746 = qcar(v_746);
    goto v_627;
v_628:
    goto v_622;
v_623:
    goto v_624;
v_625:
    goto v_626;
v_627:
    fn = elt(env, 8); // mcharg
    v_746 = (*qfnn(fn))(fn, 3, stack[0], v_747, v_746);
    env = stack[-6];
    stack[-5] = v_746;
    v_746 = stack[-5];
    if (v_746 == nil) goto v_661;
    else goto v_662;
v_661:
    v_746 = nil;
    goto v_619;
v_662:
    v_746 = stack[-5];
    v_746 = qcar(v_746);
    goto v_676;
v_670:
    v_747 = stack[-3];
    v_748 = qcar(v_747);
    goto v_671;
v_672:
    v_747 = stack[-4];
    v_747 = qcar(v_747);
    goto v_673;
v_674:
    goto v_675;
v_676:
    goto v_670;
v_671:
    goto v_672;
v_673:
    goto v_674;
v_675:
    v_746 = acons(v_748, v_747, v_746);
    env = stack[-6];
    v_746 = ncons(v_746);
    env = stack[-6];
    stack[-1] = v_746;
    stack[-2] = v_746;
v_620:
    v_746 = stack[-5];
    v_746 = qcdr(v_746);
    stack[-5] = v_746;
    v_746 = stack[-5];
    if (v_746 == nil) goto v_686;
    else goto v_687;
v_686:
    v_746 = stack[-2];
    goto v_619;
v_687:
    goto v_695;
v_691:
    stack[0] = stack[-1];
    goto v_692;
v_693:
    v_746 = stack[-5];
    v_746 = qcar(v_746);
    goto v_708;
v_702:
    v_747 = stack[-3];
    v_748 = qcar(v_747);
    goto v_703;
v_704:
    v_747 = stack[-4];
    v_747 = qcar(v_747);
    goto v_705;
v_706:
    goto v_707;
v_708:
    goto v_702;
v_703:
    goto v_704;
v_705:
    goto v_706;
v_707:
    v_746 = acons(v_748, v_747, v_746);
    env = stack[-6];
    v_746 = ncons(v_746);
    env = stack[-6];
    goto v_694;
v_695:
    goto v_691;
v_692:
    goto v_693;
v_694:
    v_746 = Lrplacd(nil, stack[0], v_746);
    env = stack[-6];
    v_746 = stack[-1];
    v_746 = qcdr(v_746);
    stack[-1] = v_746;
    goto v_620;
v_619:
    goto v_417;
v_605:
    goto v_722;
v_718:
    v_746 = stack[-4];
    v_747 = qcar(v_746);
    goto v_719;
v_720:
    v_746 = elt(env, 3); // minus
    goto v_721;
v_722:
    goto v_718;
v_719:
    goto v_720;
v_721:
    if (v_747 == v_746) goto v_716;
    else goto v_717;
v_716:
    goto v_731;
v_727:
    v_746 = stack[-4];
    v_746 = qcdr(v_746);
    v_747 = qcar(v_746);
    goto v_728;
v_729:
    v_746 = stack[-3];
    goto v_730;
v_731:
    goto v_727;
v_728:
    goto v_729;
v_730:
    {
        fn = elt(env, 9); // mchkminus
        return (*qfn2(fn))(fn, v_747, v_746);
    }
v_717:
    goto v_743;
v_739:
    v_747 = stack[-4];
    goto v_740;
v_741:
    v_746 = stack[-3];
    goto v_742;
v_743:
    goto v_739;
v_740:
    goto v_741;
v_742:
    {
        fn = elt(env, 7); // mchkopt
        return (*qfn2(fn))(fn, v_747, v_746);
    }
v_420:
    v_746 = nil;
v_417:
    return onevalue(v_746);
}



// Code for quotsq

static LispObject CC_quotsq(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_425, v_426;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_425 = v_414;
    v_426 = v_413;
// end of prologue
    goto v_421;
v_417:
    stack[0] = v_426;
    goto v_418;
v_419:
    fn = elt(env, 1); // invsq
    v_425 = (*qfn1(fn))(fn, v_425);
    env = stack[-1];
    goto v_420;
v_421:
    goto v_417;
v_418:
    goto v_419;
v_420:
    {
        LispObject v_428 = stack[0];
        fn = elt(env, 2); // multsq
        return (*qfn2(fn))(fn, v_428, v_425);
    }
}



// Code for get!+vec!+entry

static LispObject CC_getLvecLentry(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_427, v_428;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_427 = v_414;
    v_428 = v_413;
// end of prologue
    goto v_424;
v_420:
    goto v_421;
v_422:
    goto v_423;
v_424:
    goto v_420;
v_421:
    goto v_422;
v_423:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_428, v_427);
    }
    return onevalue(v_427);
}



// Code for rl_simplat1

static LispObject CC_rl_simplat1(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_431, v_432;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_431 = v_414;
    v_432 = v_413;
// end of prologue
    goto v_421;
v_417:
    stack[0] = qvalue(elt(env, 1)); // rl_simplat1!*
    goto v_418;
v_419:
    goto v_428;
v_424:
    goto v_425;
v_426:
    goto v_427;
v_428:
    goto v_424;
v_425:
    goto v_426;
v_427:
    v_431 = list2(v_432, v_431);
    env = stack[-1];
    goto v_420;
v_421:
    goto v_417;
v_418:
    goto v_419;
v_420:
    {
        LispObject v_434 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_434, v_431);
    }
}



// Code for qqe_qoptailp

static LispObject CC_qqe_qoptailp(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_428, v_429;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_428 = v_413;
// end of prologue
    goto v_423;
v_419:
    goto v_420;
v_421:
    v_429 = elt(env, 1); // (rtail ltail)
    goto v_422;
v_423:
    goto v_419;
v_420:
    goto v_421;
v_422:
    v_428 = Lmemq(nil, v_428, v_429);
    if (v_428 == nil) goto v_418;
    v_428 = lisp_true;
    goto v_416;
v_418:
    v_428 = nil;
v_416:
    return onevalue(v_428);
}



// Code for ibalp_cequal

static LispObject CC_ibalp_cequal(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_618, v_619;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_414;
    stack[-5] = v_413;
// end of prologue
    v_618 = stack[-5];
    v_618 = qcar(v_618);
    stack[-3] = v_618;
    v_618 = stack[-3];
    if (v_618 == nil) goto v_433;
    else goto v_434;
v_433:
    v_618 = nil;
    goto v_427;
v_434:
    v_618 = stack[-3];
    v_618 = qcar(v_618);
    v_618 = qcar(v_618);
    v_618 = ncons(v_618);
    env = stack[-7];
    stack[-1] = v_618;
    stack[-2] = v_618;
v_428:
    v_618 = stack[-3];
    v_618 = qcdr(v_618);
    stack[-3] = v_618;
    v_618 = stack[-3];
    if (v_618 == nil) goto v_447;
    else goto v_448;
v_447:
    v_618 = stack[-2];
    goto v_427;
v_448:
    goto v_456;
v_452:
    stack[0] = stack[-1];
    goto v_453;
v_454:
    v_618 = stack[-3];
    v_618 = qcar(v_618);
    v_618 = qcar(v_618);
    v_618 = ncons(v_618);
    env = stack[-7];
    goto v_455;
v_456:
    goto v_452;
v_453:
    goto v_454;
v_455:
    v_618 = Lrplacd(nil, stack[0], v_618);
    env = stack[-7];
    v_618 = stack[-1];
    v_618 = qcdr(v_618);
    stack[-1] = v_618;
    goto v_428;
v_427:
    stack[-6] = v_618;
    v_618 = stack[-4];
    v_618 = qcar(v_618);
    stack[-3] = v_618;
    v_618 = stack[-3];
    if (v_618 == nil) goto v_476;
    else goto v_477;
v_476:
    v_618 = nil;
    goto v_470;
v_477:
    v_618 = stack[-3];
    v_618 = qcar(v_618);
    v_618 = qcar(v_618);
    v_618 = ncons(v_618);
    env = stack[-7];
    stack[-1] = v_618;
    stack[-2] = v_618;
v_471:
    v_618 = stack[-3];
    v_618 = qcdr(v_618);
    stack[-3] = v_618;
    v_618 = stack[-3];
    if (v_618 == nil) goto v_490;
    else goto v_491;
v_490:
    v_618 = stack[-2];
    goto v_470;
v_491:
    goto v_499;
v_495:
    stack[0] = stack[-1];
    goto v_496;
v_497:
    v_618 = stack[-3];
    v_618 = qcar(v_618);
    v_618 = qcar(v_618);
    v_618 = ncons(v_618);
    env = stack[-7];
    goto v_498;
v_499:
    goto v_495;
v_496:
    goto v_497;
v_498:
    v_618 = Lrplacd(nil, stack[0], v_618);
    env = stack[-7];
    v_618 = stack[-1];
    v_618 = qcdr(v_618);
    stack[-1] = v_618;
    goto v_471;
v_470:
    goto v_518;
v_514:
    v_619 = stack[-6];
    goto v_515;
v_516:
    goto v_517;
v_518:
    goto v_514;
v_515:
    goto v_516;
v_517:
    fn = elt(env, 2); // lto_setequalq
    v_618 = (*qfn2(fn))(fn, v_619, v_618);
    env = stack[-7];
    if (v_618 == nil) goto v_511;
    else goto v_512;
v_511:
    v_618 = nil;
    goto v_421;
v_512:
    v_618 = stack[-5];
    v_618 = qcdr(v_618);
    v_618 = qcar(v_618);
    stack[-3] = v_618;
    v_618 = stack[-3];
    if (v_618 == nil) goto v_533;
    else goto v_534;
v_533:
    v_618 = nil;
    goto v_526;
v_534:
    v_618 = stack[-3];
    v_618 = qcar(v_618);
    v_618 = qcar(v_618);
    v_618 = ncons(v_618);
    env = stack[-7];
    stack[-1] = v_618;
    stack[-2] = v_618;
v_527:
    v_618 = stack[-3];
    v_618 = qcdr(v_618);
    stack[-3] = v_618;
    v_618 = stack[-3];
    if (v_618 == nil) goto v_547;
    else goto v_548;
v_547:
    v_618 = stack[-2];
    goto v_526;
v_548:
    goto v_556;
v_552:
    stack[0] = stack[-1];
    goto v_553;
v_554:
    v_618 = stack[-3];
    v_618 = qcar(v_618);
    v_618 = qcar(v_618);
    v_618 = ncons(v_618);
    env = stack[-7];
    goto v_555;
v_556:
    goto v_552;
v_553:
    goto v_554;
v_555:
    v_618 = Lrplacd(nil, stack[0], v_618);
    env = stack[-7];
    v_618 = stack[-1];
    v_618 = qcdr(v_618);
    stack[-1] = v_618;
    goto v_527;
v_526:
    stack[-3] = v_618;
    v_618 = stack[-4];
    v_618 = qcdr(v_618);
    v_618 = qcar(v_618);
    stack[-4] = v_618;
    v_618 = stack[-4];
    if (v_618 == nil) goto v_577;
    else goto v_578;
v_577:
    v_618 = nil;
    goto v_570;
v_578:
    v_618 = stack[-4];
    v_618 = qcar(v_618);
    v_618 = qcar(v_618);
    v_618 = ncons(v_618);
    env = stack[-7];
    stack[-1] = v_618;
    stack[-2] = v_618;
v_571:
    v_618 = stack[-4];
    v_618 = qcdr(v_618);
    stack[-4] = v_618;
    v_618 = stack[-4];
    if (v_618 == nil) goto v_591;
    else goto v_592;
v_591:
    v_618 = stack[-2];
    goto v_570;
v_592:
    goto v_600;
v_596:
    stack[0] = stack[-1];
    goto v_597;
v_598:
    v_618 = stack[-4];
    v_618 = qcar(v_618);
    v_618 = qcar(v_618);
    v_618 = ncons(v_618);
    env = stack[-7];
    goto v_599;
v_600:
    goto v_596;
v_597:
    goto v_598;
v_599:
    v_618 = Lrplacd(nil, stack[0], v_618);
    env = stack[-7];
    v_618 = stack[-1];
    v_618 = qcdr(v_618);
    stack[-1] = v_618;
    goto v_571;
v_570:
    goto v_615;
v_611:
    v_619 = stack[-3];
    goto v_612;
v_613:
    goto v_614;
v_615:
    goto v_611;
v_612:
    goto v_613;
v_614:
    {
        fn = elt(env, 2); // lto_setequalq
        return (*qfn2(fn))(fn, v_619, v_618);
    }
v_421:
    return onevalue(v_618);
}



// Code for xsimp

static LispObject CC_xsimp(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_418;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_418 = v_413;
// end of prologue
    fn = elt(env, 1); // simp!*
    v_418 = (*qfn1(fn))(fn, v_418);
    env = stack[0];
    {
        fn = elt(env, 2); // expchk
        return (*qfn1(fn))(fn, v_418);
    }
}



// Code for !:onep

static LispObject CC_Tonep(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_434, v_435;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_434 = v_413;
// end of prologue
    v_435 = v_434;
    if (!consp(v_435)) goto v_417;
    else goto v_418;
v_417:
        return Lonep(nil, v_434);
v_418:
    goto v_429;
v_425:
    v_435 = v_434;
    v_435 = qcar(v_435);
    if (!symbolp(v_435)) v_435 = nil;
    else { v_435 = qfastgets(v_435);
           if (v_435 != nil) { v_435 = elt(v_435, 26); // onep
#ifdef RECORD_GET
             if (v_435 != SPID_NOPROP)
                record_get(elt(fastget_names, 26), 1);
             else record_get(elt(fastget_names, 26), 0),
                v_435 = nil; }
           else record_get(elt(fastget_names, 26), 0); }
#else
             if (v_435 == SPID_NOPROP) v_435 = nil; }}
#endif
    goto v_426;
v_427:
    goto v_428;
v_429:
    goto v_425;
v_426:
    goto v_427;
v_428:
        return Lapply1(nil, v_435, v_434);
    v_434 = nil;
    return onevalue(v_434);
}



// Code for sublistp

static LispObject CC_sublistp(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_457, v_458, v_459, v_460;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_458 = v_414;
    v_459 = v_413;
// end of prologue
v_412:
    v_457 = v_459;
    if (v_457 == nil) goto v_418;
    else goto v_419;
v_418:
    v_457 = lisp_true;
    goto v_417;
v_419:
    goto v_432;
v_428:
    v_457 = v_459;
    v_460 = qcar(v_457);
    goto v_429;
v_430:
    v_457 = v_458;
    goto v_431;
v_432:
    goto v_428;
v_429:
    goto v_430;
v_431:
    v_457 = Lmember(nil, v_460, v_457);
    if (v_457 == nil) goto v_426;
    else goto v_427;
v_426:
    v_457 = nil;
    goto v_425;
v_427:
    goto v_445;
v_441:
    v_457 = v_459;
    stack[0] = qcdr(v_457);
    goto v_442;
v_443:
    goto v_453;
v_449:
    v_457 = v_459;
    v_457 = qcar(v_457);
    goto v_450;
v_451:
    goto v_452;
v_453:
    goto v_449;
v_450:
    goto v_451;
v_452:
    v_457 = Ldelete(nil, v_457, v_458);
    env = stack[-1];
    goto v_444;
v_445:
    goto v_441;
v_442:
    goto v_443;
v_444:
    v_459 = stack[0];
    v_458 = v_457;
    goto v_412;
    v_457 = nil;
v_425:
    goto v_417;
    v_457 = nil;
v_417:
    return onevalue(v_457);
}



// Code for i2rd!*

static LispObject CC_i2rdH(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_418;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_418 = v_413;
// end of prologue
    fn = elt(env, 1); // chkint!*
    v_418 = (*qfn1(fn))(fn, v_418);
    env = stack[0];
    {
        fn = elt(env, 2); // mkround
        return (*qfn1(fn))(fn, v_418);
    }
}



// Code for aeval!*

static LispObject CC_aevalH(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_428, v_429;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_413;
// end of prologue
    v_428 = nil;
    v_428 = ncons(v_428);
    env = stack[-1];
    qvalue(elt(env, 1)) = v_428; // alglist!*
    goto v_425;
v_421:
    v_429 = stack[0];
    goto v_422;
v_423:
    v_428 = nil;
    goto v_424;
v_425:
    goto v_421;
v_422:
    goto v_423;
v_424:
    {
        fn = elt(env, 2); // reval1
        return (*qfn2(fn))(fn, v_429, v_428);
    }
    return onevalue(v_428);
}



// Code for angles!-equal

static LispObject CC_anglesKequal(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_463, v_464, v_465;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_414;
    stack[-1] = v_413;
// end of prologue
    v_463 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_463;
v_419:
    goto v_430;
v_426:
    goto v_435;
v_431:
    v_464 = stack[-1];
    goto v_432;
v_433:
    v_463 = stack[-2];
    goto v_434;
v_435:
    goto v_431;
v_432:
    goto v_433;
v_434:
    v_465 = *(LispObject *)((char *)v_464 + (CELL-TAG_VECTOR) + (((intptr_t)v_463-TAG_FIXNUM)/(16/CELL)));
    goto v_427;
v_428:
    goto v_443;
v_439:
    v_464 = stack[0];
    goto v_440;
v_441:
    v_463 = stack[-2];
    goto v_442;
v_443:
    goto v_439;
v_440:
    goto v_441;
v_442:
    v_463 = *(LispObject *)((char *)v_464 + (CELL-TAG_VECTOR) + (((intptr_t)v_463-TAG_FIXNUM)/(16/CELL)));
    goto v_429;
v_430:
    goto v_426;
v_427:
    goto v_428;
v_429:
    if (equal(v_465, v_463)) goto v_425;
    v_463 = nil;
    goto v_418;
v_425:
    v_463 = stack[-2];
    v_463 = add1(v_463);
    env = stack[-3];
    stack[-2] = v_463;
    goto v_459;
v_455:
    v_464 = stack[-2];
    goto v_456;
v_457:
    v_463 = (LispObject)128+TAG_FIXNUM; // 8
    goto v_458;
v_459:
    goto v_455;
v_456:
    goto v_457;
v_458:
    v_463 = (LispObject)lessp2(v_464, v_463);
    v_463 = v_463 ? lisp_true : nil;
    env = stack[-3];
    if (v_463 == nil) goto v_453;
    goto v_419;
v_453:
    v_463 = lisp_true;
v_418:
    return onevalue(v_463);
}



// Code for cali_bc_prod

static LispObject CC_cali_bc_prod(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_425, v_426;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_425 = v_414;
    v_426 = v_413;
// end of prologue
    goto v_422;
v_418:
    goto v_419;
v_420:
    goto v_421;
v_422:
    goto v_418;
v_419:
    goto v_420;
v_421:
    fn = elt(env, 1); // multf
    v_425 = (*qfn2(fn))(fn, v_426, v_425);
    env = stack[0];
    {
        fn = elt(env, 2); // bc!=simp
        return (*qfn1(fn))(fn, v_425);
    }
}



// Code for sieve_pv

static LispObject CC_sieve_pv(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_427, v_428, v_429;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_427 = v_414;
    v_428 = v_413;
// end of prologue
    goto v_423;
v_417:
    v_429 = v_428;
    goto v_418;
v_419:
    v_428 = v_427;
    goto v_420;
v_421:
    v_427 = lisp_true;
    goto v_422;
v_423:
    goto v_417;
v_418:
    goto v_419;
v_420:
    goto v_421;
v_422:
    {
        fn = elt(env, 1); // sieve_pv0
        return (*qfnn(fn))(fn, 3, v_429, v_428, v_427);
    }
}



// Code for !*i2mod

static LispObject CC_Hi2mod(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_418;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_418 = v_413;
// end of prologue
    fn = elt(env, 1); // general!-modular!-number
    v_418 = (*qfn1(fn))(fn, v_418);
    env = stack[0];
    {
        fn = elt(env, 2); // !*modular2f
        return (*qfn1(fn))(fn, v_418);
    }
}



// Code for getpower

static LispObject CC_getpower(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_454, v_455;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_414;
    stack[-1] = v_413;
// end of prologue
    goto v_429;
v_425:
    v_454 = stack[-1];
    v_455 = qcar(v_454);
    goto v_426;
v_427:
    v_454 = elt(env, 1); // expt
    goto v_428;
v_429:
    goto v_425;
v_426:
    goto v_427;
v_428:
    if (!consp(v_455)) goto v_423;
    v_455 = qcar(v_455);
    if (v_455 == v_454) goto v_422;
    else goto v_423;
v_422:
    goto v_438;
v_434:
    v_455 = stack[0];
    goto v_435;
v_436:
    v_454 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_437;
v_438:
    goto v_434;
v_435:
    goto v_436;
v_437:
    v_454 = (LispObject)greaterp2(v_455, v_454);
    v_454 = v_454 ? lisp_true : nil;
    env = stack[-2];
    goto v_421;
v_423:
    v_454 = nil;
    goto v_421;
    v_454 = nil;
v_421:
    if (v_454 == nil) goto v_419;
    v_454 = lisp_true;
    qvalue(elt(env, 2)) = v_454; // !*sub2
    goto v_417;
v_419:
v_417:
    goto v_450;
v_446:
    v_454 = stack[-1];
    v_455 = qcar(v_454);
    goto v_447;
v_448:
    v_454 = stack[0];
    goto v_449;
v_450:
    goto v_446;
v_447:
    goto v_448;
v_449:
    return cons(v_455, v_454);
}



// Code for delcp

static LispObject CC_delcp(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_417;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_417 = v_413;
// end of prologue
    if (!symbolp(v_417)) v_417 = nil;
    else { v_417 = qfastgets(v_417);
           if (v_417 != nil) { v_417 = elt(v_417, 40); // delchar
#ifdef RECORD_GET
             if (v_417 == SPID_NOPROP)
                record_get(elt(fastget_names, 40), 0),
                v_417 = nil;
             else record_get(elt(fastget_names, 40), 1),
                v_417 = lisp_true; }
           else record_get(elt(fastget_names, 40), 0); }
#else
             if (v_417 == SPID_NOPROP) v_417 = nil; else v_417 = lisp_true; }}
#endif
    return onevalue(v_417);
}



// Code for lalr_closure

static LispObject CC_lalr_closure(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_593, v_594, v_595;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_413;
// end of prologue
    v_593 = stack[-9];
    stack[-10] = v_593;
v_428:
    v_593 = stack[-10];
    if (v_593 == nil) goto v_431;
    else goto v_432;
v_431:
    goto v_427;
v_432:
    v_593 = stack[-10];
    v_593 = qcar(v_593);
    stack[-8] = v_593;
    v_593 = stack[-10];
    v_593 = qcdr(v_593);
    stack[-10] = v_593;
    v_593 = stack[-8];
    v_593 = qcdr(v_593);
    stack[-2] = v_593;
v_442:
    v_593 = stack[-2];
    if (v_593 == nil) goto v_447;
    else goto v_448;
v_447:
    goto v_441;
v_448:
    v_593 = stack[-2];
    v_593 = qcar(v_593);
    stack[-1] = v_593;
    goto v_458;
v_454:
    v_594 = elt(env, 2); // !.
    goto v_455;
v_456:
    v_593 = stack[-8];
    v_593 = qcar(v_593);
    goto v_457;
v_458:
    goto v_454;
v_455:
    goto v_456;
v_457:
    v_593 = Lmember(nil, v_594, v_593);
    v_593 = qcdr(v_593);
    stack[-7] = v_593;
    v_593 = stack[-7];
    if (v_593 == nil) goto v_467;
    v_593 = stack[-7];
    v_593 = qcar(v_593);
    stack[-6] = v_593;
    if (v_593 == nil) goto v_467;
    v_593 = stack[-6];
    if (symbolp(v_593)) goto v_474;
    else goto v_467;
v_474:
    v_593 = stack[-6];
    fn = elt(env, 3); // lalr_productions
    v_593 = (*qfn1(fn))(fn, v_593);
    env = stack[-11];
    stack[0] = v_593;
v_479:
    v_593 = stack[0];
    if (v_593 == nil) goto v_484;
    else goto v_485;
v_484:
    goto v_478;
v_485:
    v_593 = stack[0];
    v_593 = qcar(v_593);
    stack[-3] = v_593;
    goto v_497;
v_493:
    v_593 = stack[-7];
    stack[-4] = qcdr(v_593);
    goto v_494;
v_495:
    v_593 = stack[-1];
    v_593 = ncons(v_593);
    env = stack[-11];
    goto v_496;
v_497:
    goto v_493;
v_494:
    goto v_495;
v_496:
    v_593 = Lappend(nil, stack[-4], v_593);
    env = stack[-11];
    fn = elt(env, 4); // lalr_first
    v_593 = (*qfn1(fn))(fn, v_593);
    env = stack[-11];
    stack[-5] = v_593;
    goto v_509;
v_503:
    v_595 = stack[-6];
    goto v_504;
v_505:
    v_594 = elt(env, 2); // !.
    goto v_506;
v_507:
    v_593 = stack[-3];
    v_593 = qcar(v_593);
    goto v_508;
v_509:
    goto v_503;
v_504:
    goto v_505;
v_506:
    goto v_507;
v_508:
    v_593 = list2star(v_595, v_594, v_593);
    env = stack[-11];
    stack[-4] = v_593;
    goto v_519;
v_515:
    v_594 = stack[-4];
    goto v_516;
v_517:
    v_593 = stack[-9];
    goto v_518;
v_519:
    goto v_515;
v_516:
    goto v_517;
v_518:
    fn = elt(env, 5); // lalr_item_with_rule
    v_593 = (*qfn2(fn))(fn, v_594, v_593);
    env = stack[-11];
    stack[-3] = v_593;
    v_593 = stack[-3];
    if (v_593 == nil) goto v_525;
    goto v_532;
v_528:
    v_594 = stack[-5];
    goto v_529;
v_530:
    v_593 = stack[-3];
    v_593 = qcdr(v_593);
    goto v_531;
v_532:
    goto v_528;
v_529:
    goto v_530;
v_531:
    fn = elt(env, 6); // setdiff
    v_593 = (*qfn2(fn))(fn, v_594, v_593);
    env = stack[-11];
    stack[-5] = v_593;
    goto v_523;
v_525:
    v_593 = stack[-4];
    v_593 = ncons(v_593);
    env = stack[-11];
    stack[-3] = v_593;
    goto v_545;
v_541:
    v_594 = stack[-3];
    goto v_542;
v_543:
    v_593 = stack[-9];
    goto v_544;
v_545:
    goto v_541;
v_542:
    goto v_543;
v_544:
    v_593 = cons(v_594, v_593);
    env = stack[-11];
    stack[-9] = v_593;
    goto v_523;
v_523:
    v_593 = stack[-5];
    if (v_593 == nil) goto v_551;
    goto v_560;
v_554:
    v_595 = stack[-4];
    goto v_555;
v_556:
    v_594 = stack[-5];
    goto v_557;
v_558:
    v_593 = stack[-10];
    goto v_559;
v_560:
    goto v_554;
v_555:
    goto v_556;
v_557:
    goto v_558;
v_559:
    v_593 = acons(v_595, v_594, v_593);
    env = stack[-11];
    stack[-10] = v_593;
    v_593 = stack[-5];
    stack[-4] = v_593;
v_567:
    v_593 = stack[-4];
    if (v_593 == nil) goto v_571;
    else goto v_572;
v_571:
    goto v_566;
v_572:
    v_593 = stack[-4];
    v_593 = qcar(v_593);
    goto v_583;
v_579:
    v_594 = stack[-3];
    goto v_580;
v_581:
    goto v_582;
v_583:
    goto v_579;
v_580:
    goto v_581;
v_582:
    fn = elt(env, 7); // lalr_add_lookahead
    v_593 = (*qfn2(fn))(fn, v_594, v_593);
    env = stack[-11];
    v_593 = stack[-4];
    v_593 = qcdr(v_593);
    stack[-4] = v_593;
    goto v_567;
v_566:
    goto v_549;
v_551:
v_549:
    v_593 = stack[0];
    v_593 = qcdr(v_593);
    stack[0] = v_593;
    goto v_479;
v_478:
    goto v_465;
v_467:
v_465:
    v_593 = stack[-2];
    v_593 = qcdr(v_593);
    stack[-2] = v_593;
    goto v_442;
v_441:
    goto v_428;
v_427:
    v_593 = stack[-9];
    return onevalue(v_593);
}



// Code for rl_varlat

static LispObject CC_rl_varlat(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_424;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_424 = v_413;
// end of prologue
    goto v_420;
v_416:
    stack[0] = qvalue(elt(env, 1)); // rl_varlat!*
    goto v_417;
v_418:
    v_424 = ncons(v_424);
    env = stack[-1];
    goto v_419;
v_420:
    goto v_416;
v_417:
    goto v_418;
v_419:
    {
        LispObject v_426 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_426, v_424);
    }
}



// Code for sort

static LispObject CC_sort(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_431, v_432;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_414;
    v_431 = v_413;
// end of prologue
    goto v_421;
v_417:
    goto v_427;
v_423:
    v_432 = v_431;
    goto v_424;
v_425:
    v_431 = nil;
    goto v_426;
v_427:
    goto v_423;
v_424:
    goto v_425;
v_426:
    v_432 = Lappend(nil, v_432, v_431);
    env = stack[-1];
    goto v_418;
v_419:
    v_431 = stack[0];
    goto v_420;
v_421:
    goto v_417;
v_418:
    goto v_419;
v_420:
    {
        fn = elt(env, 1); // stable!-sortip
        return (*qfn2(fn))(fn, v_432, v_431);
    }
}



// Code for comfac!-to!-poly

static LispObject CC_comfacKtoKpoly(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_427, v_428;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_427 = v_413;
// end of prologue
    v_428 = v_427;
    v_428 = qcar(v_428);
    if (v_428 == nil) goto v_417;
    else goto v_418;
v_417:
    v_427 = qcdr(v_427);
    goto v_416;
v_418:
    return ncons(v_427);
    v_427 = nil;
v_416:
    return onevalue(v_427);
}



// Code for mtchk

static LispObject CC_mtchk(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_628, v_629, v_630, v_631;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_414;
    stack[-9] = v_413;
// end of prologue
    stack[-4] = nil;
    stack[-3] = nil;
    v_628 = stack[-9];
    v_628 = qcar(v_628);
    fn = elt(env, 2); // noncomp
    v_628 = (*qfn1(fn))(fn, v_628);
    env = stack[-11];
    stack[-10] = v_628;
v_425:
    v_628 = stack[-8];
    if (v_628 == nil) goto v_437;
    else goto v_438;
v_437:
    v_628 = stack[-4];
    goto v_424;
v_438:
    v_628 = stack[-8];
    v_628 = qcar(v_628);
    stack[-7] = v_628;
    v_628 = stack[-7];
    v_628 = qcar(v_628);
    stack[-6] = v_628;
v_426:
    v_628 = stack[-6];
    if (v_628 == nil) goto v_447;
    else goto v_448;
v_447:
    goto v_429;
v_448:
    goto v_459;
v_451:
    v_631 = stack[-9];
    goto v_452;
v_453:
    v_628 = stack[-6];
    v_630 = qcar(v_628);
    goto v_454;
v_455:
    v_628 = stack[-7];
    v_628 = qcdr(v_628);
    v_628 = qcar(v_628);
    v_629 = qcar(v_628);
    goto v_456;
v_457:
    v_628 = stack[-7];
    v_628 = qcdr(v_628);
    v_628 = qcar(v_628);
    v_628 = qcdr(v_628);
    goto v_458;
v_459:
    goto v_451;
v_452:
    goto v_453;
v_454:
    goto v_455;
v_456:
    goto v_457;
v_458:
    fn = elt(env, 3); // mtchp1
    v_628 = (*qfnn(fn))(fn, 4, v_631, v_630, v_629, v_628);
    env = stack[-11];
    stack[-5] = v_628;
v_427:
    v_628 = stack[-5];
    if (v_628 == nil) goto v_473;
    else goto v_474;
v_473:
    goto v_428;
v_474:
    goto v_485;
v_479:
    goto v_491;
v_487:
    v_628 = stack[-5];
    stack[0] = qcar(v_628);
    goto v_488;
v_489:
    goto v_499;
v_495:
    v_628 = stack[-6];
    v_629 = qcar(v_628);
    goto v_496;
v_497:
    v_628 = stack[-7];
    v_628 = qcar(v_628);
    goto v_498;
v_499:
    goto v_495;
v_496:
    goto v_497;
v_498:
    v_628 = Ldelete(nil, v_629, v_628);
    env = stack[-11];
    goto v_490;
v_491:
    goto v_487;
v_488:
    goto v_489;
v_490:
    stack[-2] = Lsubla(nil, stack[0], v_628);
    env = stack[-11];
    goto v_480;
v_481:
    goto v_509;
v_505:
    v_628 = stack[-5];
    v_629 = qcar(v_628);
    goto v_506;
v_507:
    v_628 = stack[-7];
    v_628 = qcdr(v_628);
    v_628 = qcar(v_628);
    goto v_508;
v_509:
    goto v_505;
v_506:
    goto v_507;
v_508:
    stack[-1] = Lsubla(nil, v_629, v_628);
    env = stack[-11];
    goto v_482;
v_483:
    goto v_520;
v_516:
    goto v_526;
v_522:
    v_628 = stack[-5];
    v_629 = qcar(v_628);
    goto v_523;
v_524:
    v_628 = stack[-7];
    v_628 = qcdr(v_628);
    v_628 = qcdr(v_628);
    v_628 = qcar(v_628);
    goto v_525;
v_526:
    goto v_522;
v_523:
    goto v_524;
v_525:
    stack[0] = Lsubla(nil, v_629, v_628);
    env = stack[-11];
    goto v_517;
v_518:
    goto v_538;
v_534:
    goto v_544;
v_540:
    v_628 = stack[-5];
    v_629 = qcar(v_628);
    goto v_541;
v_542:
    v_628 = stack[-6];
    v_628 = qcar(v_628);
    goto v_543;
v_544:
    goto v_540;
v_541:
    goto v_542;
v_543:
    v_629 = Lsubla(nil, v_629, v_628);
    env = stack[-11];
    goto v_535;
v_536:
    v_628 = stack[-7];
    v_628 = qcdr(v_628);
    v_628 = qcdr(v_628);
    v_628 = qcdr(v_628);
    v_628 = qcar(v_628);
    goto v_537;
v_538:
    goto v_534;
v_535:
    goto v_536;
v_537:
    v_628 = cons(v_629, v_628);
    env = stack[-11];
    goto v_519;
v_520:
    goto v_516;
v_517:
    goto v_518;
v_519:
    v_628 = list2(stack[0], v_628);
    env = stack[-11];
    goto v_484;
v_485:
    goto v_479;
v_480:
    goto v_481;
v_482:
    goto v_483;
v_484:
    v_628 = list2star(stack[-2], stack[-1], v_628);
    env = stack[-11];
    stack[0] = v_628;
    v_628 = qcar(v_628);
    if (v_628 == nil) goto v_477;
    goto v_560;
v_556:
    v_629 = stack[0];
    goto v_557;
v_558:
    v_628 = stack[-4];
    goto v_559;
v_560:
    goto v_556;
v_557:
    goto v_558;
v_559:
    v_628 = cons(v_629, v_628);
    env = stack[-11];
    stack[-4] = v_628;
    v_628 = stack[-3];
    if (v_628 == nil) goto v_565;
    else goto v_566;
v_565:
    v_628 = stack[-4];
    stack[-3] = v_628;
    goto v_564;
v_566:
v_564:
    goto v_472;
v_477:
    goto v_577;
v_573:
    v_628 = stack[-5];
    v_629 = qcar(v_628);
    goto v_574;
v_575:
    v_628 = stack[-7];
    v_628 = qcdr(v_628);
    v_628 = qcar(v_628);
    v_628 = qcdr(v_628);
    goto v_576;
v_577:
    goto v_573;
v_574:
    goto v_575;
v_576:
    v_628 = Lsubla(nil, v_629, v_628);
    env = stack[-11];
    fn = elt(env, 4); // lispeval
    v_628 = (*qfn1(fn))(fn, v_628);
    env = stack[-11];
    if (v_628 == nil) goto v_570;
    v_628 = stack[0];
    return ncons(v_628);
v_570:
v_472:
    v_628 = stack[-5];
    v_628 = qcdr(v_628);
    stack[-5] = v_628;
    goto v_427;
v_428:
    v_628 = stack[-10];
    if (v_628 == nil) goto v_590;
    else goto v_591;
v_590:
    v_628 = stack[-6];
    v_628 = qcdr(v_628);
    stack[-6] = v_628;
    goto v_426;
v_591:
    v_628 = stack[-7];
    v_628 = qcdr(v_628);
    v_628 = qcdr(v_628);
    v_628 = qcdr(v_628);
    v_628 = qcar(v_628);
    if (v_628 == nil) goto v_596;
    v_628 = stack[-6];
    fn = elt(env, 5); // nocp
    v_628 = (*qfn1(fn))(fn, v_628);
    env = stack[-11];
    if (v_628 == nil) goto v_596;
    goto v_430;
v_596:
v_429:
    v_628 = stack[-4];
    if (v_628 == nil) goto v_608;
    else goto v_609;
v_608:
    v_628 = stack[-7];
    v_628 = ncons(v_628);
    env = stack[-11];
    stack[-3] = v_628;
    stack[-4] = v_628;
    goto v_607;
v_609:
    goto v_620;
v_616:
    stack[0] = stack[-3];
    goto v_617;
v_618:
    v_628 = stack[-7];
    v_628 = ncons(v_628);
    env = stack[-11];
    goto v_619;
v_620:
    goto v_616;
v_617:
    goto v_618;
v_619:
    v_628 = Lrplacd(nil, stack[0], v_628);
    env = stack[-11];
    v_628 = stack[-3];
    v_628 = qcdr(v_628);
    stack[-3] = v_628;
    goto v_607;
v_607:
v_430:
    v_628 = stack[-8];
    v_628 = qcdr(v_628);
    stack[-8] = v_628;
    goto v_425;
v_424:
    return onevalue(v_628);
}



// Code for sfp

static LispObject CC_sfp(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_427, v_428;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_427 = v_413;
// end of prologue
    v_428 = v_427;
    if (!consp(v_428)) goto v_418;
    v_427 = qcar(v_427);
    v_427 = (consp(v_427) ? nil : lisp_true);
    v_427 = (v_427 == nil ? lisp_true : nil);
    goto v_416;
v_418:
    v_427 = nil;
    goto v_416;
    v_427 = nil;
v_416:
    return onevalue(v_427);
}



// Code for tayexp!-lessp

static LispObject CC_tayexpKlessp(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_449, v_450, v_451;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_450 = v_414;
    v_451 = v_413;
// end of prologue
    v_449 = v_451;
    if (!consp(v_449)) goto v_422;
    else goto v_423;
v_422:
    v_449 = v_450;
    v_449 = (consp(v_449) ? nil : lisp_true);
    goto v_421;
v_423:
    v_449 = nil;
    goto v_421;
    v_449 = nil;
v_421:
    if (v_449 == nil) goto v_419;
    goto v_435;
v_431:
    v_449 = v_451;
    goto v_432;
v_433:
    goto v_434;
v_435:
    goto v_431;
v_432:
    goto v_433;
v_434:
        return Llessp(nil, v_449, v_450);
v_419:
    goto v_446;
v_442:
    v_449 = v_451;
    goto v_443;
v_444:
    goto v_445;
v_446:
    goto v_442;
v_443:
    goto v_444;
v_445:
    fn = elt(env, 1); // tayexp!-difference
    v_449 = (*qfn2(fn))(fn, v_449, v_450);
    env = stack[0];
    {
        fn = elt(env, 2); // !:minusp
        return (*qfn1(fn))(fn, v_449);
    }
    v_449 = nil;
    return onevalue(v_449);
}



// Code for exptchksq

static LispObject CC_exptchksq(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_436;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_413;
// end of prologue
    v_436 = qvalue(elt(env, 1)); // !*combineexpt
    if (v_436 == nil) goto v_417;
    else goto v_418;
v_417:
    v_436 = stack[0];
    goto v_416;
v_418:
    goto v_428;
v_424:
    v_436 = stack[0];
    v_436 = qcar(v_436);
    fn = elt(env, 2); // exptchk
    stack[-1] = (*qfn1(fn))(fn, v_436);
    env = stack[-2];
    goto v_425;
v_426:
    v_436 = stack[0];
    v_436 = qcdr(v_436);
    fn = elt(env, 2); // exptchk
    v_436 = (*qfn1(fn))(fn, v_436);
    env = stack[-2];
    fn = elt(env, 3); // invsq
    v_436 = (*qfn1(fn))(fn, v_436);
    env = stack[-2];
    goto v_427;
v_428:
    goto v_424;
v_425:
    goto v_426;
v_427:
    {
        LispObject v_439 = stack[-1];
        fn = elt(env, 4); // multsq
        return (*qfn2(fn))(fn, v_439, v_436);
    }
    v_436 = nil;
v_416:
    return onevalue(v_436);
}



// Code for talp_varlt

static LispObject CC_talp_varlt(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_423, v_424;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_423 = v_413;
// end of prologue
    goto v_420;
v_416:
    v_424 = v_423;
    goto v_417;
v_418:
    v_423 = nil;
    goto v_419;
v_420:
    goto v_416;
v_417:
    goto v_418;
v_419:
    {
        fn = elt(env, 1); // talp_varlt1
        return (*qfn2(fn))(fn, v_424, v_423);
    }
}



// Code for ibalp_cec

static LispObject CC_ibalp_cec(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_435;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_413;
// end of prologue
v_417:
    v_435 = stack[0];
    if (v_435 == nil) goto v_420;
    else goto v_421;
v_420:
    v_435 = nil;
    goto v_416;
v_421:
    v_435 = stack[0];
    v_435 = qcar(v_435);
    fn = elt(env, 1); // ibalp_emptyclausep
    v_435 = (*qfn1(fn))(fn, v_435);
    env = stack[-1];
    if (v_435 == nil) goto v_425;
    v_435 = stack[0];
    v_435 = qcar(v_435);
    goto v_416;
v_425:
    v_435 = stack[0];
    v_435 = qcdr(v_435);
    stack[0] = v_435;
    goto v_417;
    v_435 = nil;
v_416:
    return onevalue(v_435);
}



// Code for get_token

static LispObject CC_get_token(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_450, v_451;
    argcheck(nargs, 0, "get_token");
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
    v_450 = nil;
    stack[0] = v_450;
v_421:
    goto v_430;
v_426:
    v_451 = Lreadch(nil, 0);
    env = stack[-1];
    qvalue(elt(env, 2)) = v_451; // ch
    goto v_427;
v_428:
    v_450 = elt(env, 3); // !>
    goto v_429;
v_430:
    goto v_426;
v_427:
    goto v_428;
v_429:
    if (v_451 == v_450) goto v_424;
    else goto v_425;
v_424:
    goto v_420;
v_425:
    goto v_439;
v_435:
    v_451 = qvalue(elt(env, 2)); // ch
    goto v_436;
v_437:
    v_450 = stack[0];
    goto v_438;
v_439:
    goto v_435;
v_436:
    goto v_437;
v_438:
    v_450 = cons(v_451, v_450);
    env = stack[-1];
    stack[0] = v_450;
    goto v_421;
v_420:
    goto v_447;
v_443:
    v_451 = elt(env, 4); // !$
    goto v_444;
v_445:
    v_450 = stack[0];
    goto v_446;
v_447:
    goto v_443;
v_444:
    goto v_445;
v_446:
    return cons(v_451, v_450);
    return onevalue(v_450);
}



// Code for c!:ordexn

static LispObject CC_cTordexn(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_522, v_523;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_414;
    stack[-2] = v_413;
// end of prologue
    stack[0] = nil;
    stack[-3] = nil;
v_420:
    v_522 = stack[-1];
    if (v_522 == nil) goto v_424;
    else goto v_425;
v_424:
    goto v_432;
v_428:
    goto v_429;
v_430:
    goto v_440;
v_436:
    v_523 = stack[-2];
    goto v_437;
v_438:
    v_522 = stack[-3];
    goto v_439;
v_440:
    goto v_436;
v_437:
    goto v_438;
v_439:
    v_522 = cons(v_523, v_522);
    env = stack[-4];
    v_522 = Lreverse(nil, v_522);
    goto v_431;
v_432:
    goto v_428;
v_429:
    goto v_430;
v_431:
    {
        LispObject v_528 = stack[0];
        return cons(v_528, v_522);
    }
v_425:
    goto v_453;
v_449:
    v_523 = stack[-2];
    goto v_450;
v_451:
    v_522 = stack[-1];
    v_522 = qcar(v_522);
    goto v_452;
v_453:
    goto v_449;
v_450:
    goto v_451;
v_452:
    if (equal(v_523, v_522)) goto v_447;
    else goto v_448;
v_447:
    v_522 = lisp_true;
    goto v_446;
v_448:
    v_522 = stack[-2];
    v_522 = Lconsp(nil, v_522);
    env = stack[-4];
    if (v_522 == nil) goto v_462;
    else goto v_463;
v_462:
    v_522 = nil;
    goto v_461;
v_463:
    v_522 = stack[-1];
    v_522 = qcar(v_522);
    v_522 = Lconsp(nil, v_522);
    env = stack[-4];
    goto v_461;
    v_522 = nil;
v_461:
    goto v_446;
    v_522 = nil;
v_446:
    if (v_522 == nil) goto v_444;
    v_522 = nil;
    goto v_419;
v_444:
    goto v_480;
v_476:
    v_523 = stack[-2];
    goto v_477;
v_478:
    v_522 = stack[-1];
    v_522 = qcar(v_522);
    goto v_479;
v_480:
    goto v_476;
v_477:
    goto v_478;
v_479:
    fn = elt(env, 2); // c!:ordxp
    v_522 = (*qfn2(fn))(fn, v_523, v_522);
    env = stack[-4];
    if (v_522 == nil) goto v_474;
    goto v_489;
v_485:
    goto v_486;
v_487:
    goto v_496;
v_492:
    goto v_503;
v_499:
    v_523 = stack[-2];
    goto v_500;
v_501:
    v_522 = stack[-3];
    goto v_502;
v_503:
    goto v_499;
v_500:
    goto v_501;
v_502:
    v_522 = cons(v_523, v_522);
    env = stack[-4];
    v_523 = Lreverse(nil, v_522);
    env = stack[-4];
    goto v_493;
v_494:
    v_522 = stack[-1];
    goto v_495;
v_496:
    goto v_492;
v_493:
    goto v_494;
v_495:
    v_522 = Lappend(nil, v_523, v_522);
    goto v_488;
v_489:
    goto v_485;
v_486:
    goto v_487;
v_488:
    {
        LispObject v_529 = stack[0];
        return cons(v_529, v_522);
    }
v_474:
    goto v_514;
v_510:
    v_522 = stack[-1];
    v_523 = qcar(v_522);
    goto v_511;
v_512:
    v_522 = stack[-3];
    goto v_513;
v_514:
    goto v_510;
v_511:
    goto v_512;
v_513:
    v_522 = cons(v_523, v_522);
    env = stack[-4];
    stack[-3] = v_522;
    v_522 = stack[-1];
    v_522 = qcdr(v_522);
    stack[-1] = v_522;
    v_522 = stack[0];
    v_522 = (v_522 == nil ? lisp_true : nil);
    stack[0] = v_522;
    goto v_423;
v_423:
    goto v_420;
v_419:
    return onevalue(v_522);
}



// Code for bczero!?

static LispObject CC_bczeroW(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_433, v_434;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_433 = v_413;
// end of prologue
    v_434 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_434 == nil) goto v_418;
    goto v_425;
v_421:
    v_434 = v_433;
    goto v_422;
v_423:
    v_433 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_424;
v_425:
    goto v_421;
v_422:
    goto v_423;
v_424:
        return Leqn(nil, v_434, v_433);
v_418:
    v_433 = qcar(v_433);
    v_433 = (v_433 == nil ? lisp_true : nil);
    goto v_416;
    v_433 = nil;
v_416:
    return onevalue(v_433);
}



// Code for prepsqxx

static LispObject CC_prepsqxx(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_418;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_418 = v_413;
// end of prologue
    fn = elt(env, 1); // prepsqx
    v_418 = (*qfn1(fn))(fn, v_418);
    env = stack[0];
    {
        fn = elt(env, 2); // negnumberchk
        return (*qfn1(fn))(fn, v_418);
    }
}



// Code for order!:

static LispObject CC_orderT(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_446, v_447;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_413;
// end of prologue
    goto v_423;
v_419:
    v_446 = stack[0];
    v_446 = qcdr(v_446);
    v_447 = qcar(v_446);
    goto v_420;
v_421:
    v_446 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_422;
v_423:
    goto v_419;
v_420:
    goto v_421;
v_422:
    if (v_447 == v_446) goto v_417;
    else goto v_418;
v_417:
    v_446 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_416;
v_418:
    goto v_436;
v_432:
    v_446 = stack[0];
    v_446 = qcdr(v_446);
    v_446 = qcar(v_446);
    v_446 = Labsval(nil, v_446);
    env = stack[-2];
    fn = elt(env, 1); // msd
    stack[-1] = (*qfn1(fn))(fn, v_446);
    env = stack[-2];
    goto v_433;
v_434:
    v_446 = stack[0];
    v_446 = qcdr(v_446);
    v_446 = qcdr(v_446);
    v_446 = sub1(v_446);
    goto v_435;
v_436:
    goto v_432;
v_433:
    goto v_434;
v_435:
    {
        LispObject v_450 = stack[-1];
        return plus2(v_450, v_446);
    }
    v_446 = nil;
v_416:
    return onevalue(v_446);
}



// Code for smemqlp

static LispObject CC_smemqlp(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_476, v_477;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_414;
    stack[-1] = v_413;
// end of prologue
v_412:
    v_476 = stack[0];
    if (v_476 == nil) goto v_422;
    else goto v_423;
v_422:
    v_476 = lisp_true;
    goto v_421;
v_423:
    v_476 = stack[0];
    v_476 = (is_number(v_476) ? lisp_true : nil);
    goto v_421;
    v_476 = nil;
v_421:
    if (v_476 == nil) goto v_419;
    v_476 = nil;
    goto v_417;
v_419:
    v_476 = stack[0];
    if (!consp(v_476)) goto v_431;
    else goto v_432;
v_431:
    goto v_438;
v_434:
    v_477 = stack[0];
    goto v_435;
v_436:
    v_476 = stack[-1];
    goto v_437;
v_438:
    goto v_434;
v_435:
    goto v_436;
v_437:
    v_476 = Lmemq(nil, v_477, v_476);
    goto v_417;
v_432:
    goto v_448;
v_444:
    v_476 = stack[0];
    v_477 = qcar(v_476);
    goto v_445;
v_446:
    v_476 = elt(env, 1); // quote
    goto v_447;
v_448:
    goto v_444;
v_445:
    goto v_446;
v_447:
    if (v_477 == v_476) goto v_442;
    else goto v_443;
v_442:
    v_476 = nil;
    goto v_417;
v_443:
    goto v_463;
v_459:
    v_477 = stack[-1];
    goto v_460;
v_461:
    v_476 = stack[0];
    v_476 = qcar(v_476);
    goto v_462;
v_463:
    goto v_459;
v_460:
    goto v_461;
v_462:
    v_476 = CC_smemqlp(elt(env, 0), v_477, v_476);
    env = stack[-2];
    if (v_476 == nil) goto v_457;
    else goto v_456;
v_457:
    goto v_472;
v_468:
    v_477 = stack[-1];
    goto v_469;
v_470:
    v_476 = stack[0];
    v_476 = qcdr(v_476);
    goto v_471;
v_472:
    goto v_468;
v_469:
    goto v_470;
v_471:
    stack[-1] = v_477;
    stack[0] = v_476;
    goto v_412;
v_456:
    goto v_417;
    v_476 = nil;
v_417:
    return onevalue(v_476);
}



// Code for adddm

static LispObject CC_adddm(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_481, v_482, v_483;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_482 = v_414;
    v_483 = v_413;
// end of prologue
    v_481 = v_483;
    if (!consp(v_481)) goto v_422;
    else goto v_423;
v_422:
    v_481 = v_482;
    v_481 = (consp(v_481) ? nil : lisp_true);
    goto v_421;
v_423:
    v_481 = nil;
    goto v_421;
    v_481 = nil;
v_421:
    if (v_481 == nil) goto v_419;
    goto v_435;
v_431:
    v_481 = v_483;
    goto v_432;
v_433:
    goto v_434;
v_435:
    goto v_431;
v_432:
    goto v_433;
v_434:
    v_481 = plus2(v_481, v_482);
    env = stack[0];
    v_482 = qvalue(elt(env, 1)); // dmode!*
    if (v_482 == nil) goto v_445;
    else goto v_446;
v_445:
    v_482 = lisp_true;
    goto v_444;
v_446:
    v_482 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_482)) v_482 = nil;
    else { v_482 = qfastgets(v_482);
           if (v_482 != nil) { v_482 = elt(v_482, 5); // convert
#ifdef RECORD_GET
             if (v_482 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v_482 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v_482 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v_482 == SPID_NOPROP) v_482 = nil; else v_482 = lisp_true; }}
#endif
    v_482 = (v_482 == nil ? lisp_true : nil);
    goto v_444;
    v_482 = nil;
v_444:
    if (v_482 == nil) goto v_442;
    {
        fn = elt(env, 3); // !*n2f
        return (*qfn1(fn))(fn, v_481);
    }
v_442:
    goto v_464;
v_460:
    v_482 = qvalue(elt(env, 1)); // dmode!*
    if (!symbolp(v_482)) v_482 = nil;
    else { v_482 = qfastgets(v_482);
           if (v_482 != nil) { v_482 = elt(v_482, 34); // i2d
#ifdef RECORD_GET
             if (v_482 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_482 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_482 == SPID_NOPROP) v_482 = nil; }}
#endif
    goto v_461;
v_462:
    goto v_463;
v_464:
    goto v_460;
v_461:
    goto v_462;
v_463:
    v_481 = Lapply1(nil, v_482, v_481);
    env = stack[0];
    {
        fn = elt(env, 4); // int!-equiv!-chk
        return (*qfn1(fn))(fn, v_481);
    }
    v_481 = nil;
    goto v_417;
v_419:
    goto v_477;
v_471:
    goto v_472;
v_473:
    goto v_474;
v_475:
    v_481 = elt(env, 2); // plus
    goto v_476;
v_477:
    goto v_471;
v_472:
    goto v_473;
v_474:
    goto v_475;
v_476:
    {
        fn = elt(env, 5); // dcombine
        return (*qfnn(fn))(fn, 3, v_483, v_482, v_481);
    }
    v_481 = nil;
v_417:
    return onevalue(v_481);
}



// Code for negnumberchk

static LispObject CC_negnumberchk(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_445, v_446, v_447;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_446 = v_413;
// end of prologue
    goto v_428;
v_424:
    v_445 = v_446;
    goto v_425;
v_426:
    v_447 = elt(env, 1); // minus
    goto v_427;
v_428:
    goto v_424;
v_425:
    goto v_426;
v_427:
    if (!consp(v_445)) goto v_422;
    v_445 = qcar(v_445);
    if (v_445 == v_447) goto v_421;
    else goto v_422;
v_421:
    v_445 = v_446;
    v_445 = qcdr(v_445);
    v_445 = qcar(v_445);
    v_445 = (is_number(v_445) ? lisp_true : nil);
    goto v_420;
v_422:
    v_445 = nil;
    goto v_420;
    v_445 = nil;
v_420:
    if (v_445 == nil) goto v_418;
    v_445 = v_446;
    v_445 = qcdr(v_445);
    v_445 = qcar(v_445);
    return negate(v_445);
v_418:
    v_445 = v_446;
    goto v_416;
    v_445 = nil;
v_416:
    return onevalue(v_445);
}



// Code for pappl0

static LispObject CC_pappl0(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_426, v_427;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_426 = v_414;
    v_427 = v_413;
// end of prologue
    goto v_422;
v_418:
    stack[0] = v_427;
    goto v_419;
v_420:
    fn = elt(env, 1); // unpkp
    v_426 = (*qfn1(fn))(fn, v_426);
    env = stack[-1];
    goto v_421;
v_422:
    goto v_418;
v_419:
    goto v_420;
v_421:
    fn = elt(env, 2); // pappl
    v_426 = (*qfn2(fn))(fn, stack[0], v_426);
    env = stack[-1];
    {
        fn = elt(env, 3); // pkp
        return (*qfn1(fn))(fn, v_426);
    }
}



// Code for rnonep!:

static LispObject CC_rnonepT(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_441, v_442, v_443;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_442 = v_413;
// end of prologue
    goto v_423;
v_419:
    v_441 = v_442;
    v_441 = qcdr(v_441);
    v_443 = qcar(v_441);
    goto v_420;
v_421:
    v_441 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_422;
v_423:
    goto v_419;
v_420:
    goto v_421;
v_422:
    if (v_443 == v_441) goto v_417;
    else goto v_418;
v_417:
    goto v_432;
v_428:
    v_441 = v_442;
    v_441 = qcdr(v_441);
    v_442 = qcdr(v_441);
    goto v_429;
v_430:
    v_441 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_431;
v_432:
    goto v_428;
v_429:
    goto v_430;
v_431:
    v_441 = (v_442 == v_441 ? lisp_true : nil);
    goto v_416;
v_418:
    v_441 = nil;
    goto v_416;
    v_441 = nil;
v_416:
    return onevalue(v_441);
}



// Code for multiply!-by!-constant!-mod!-p

static LispObject CC_multiplyKbyKconstantKmodKp(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_522, v_523, v_524;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_414;
    stack[-2] = v_413;
// end of prologue
    stack[-3] = nil;
    v_522 = stack[-2];
    if (v_522 == nil) goto v_423;
    else goto v_424;
v_423:
    v_522 = nil;
    goto v_419;
v_424:
    goto v_433;
v_429:
    v_523 = stack[-1];
    goto v_430;
v_431:
    v_522 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_432;
v_433:
    goto v_429;
v_430:
    goto v_431;
v_432:
    if (v_523 == v_522) goto v_427;
    else goto v_428;
v_427:
    v_522 = stack[-2];
    goto v_419;
v_428:
v_439:
    v_522 = stack[-2];
    if (!consp(v_522)) goto v_446;
    else goto v_447;
v_446:
    v_522 = lisp_true;
    goto v_445;
v_447:
    v_522 = stack[-2];
    v_522 = qcar(v_522);
    v_522 = (consp(v_522) ? nil : lisp_true);
    goto v_445;
    v_522 = nil;
v_445:
    if (v_522 == nil) goto v_443;
    goto v_438;
v_443:
    goto v_461;
v_457:
    v_522 = stack[-2];
    v_522 = qcar(v_522);
    v_523 = qcdr(v_522);
    goto v_458;
v_459:
    v_522 = stack[-1];
    goto v_460;
v_461:
    goto v_457;
v_458:
    goto v_459;
v_460:
    v_522 = CC_multiplyKbyKconstantKmodKp(elt(env, 0), v_523, v_522);
    env = stack[-4];
    stack[0] = v_522;
    v_522 = stack[0];
    if (v_522 == nil) goto v_469;
    goto v_478;
v_472:
    v_522 = stack[-2];
    v_522 = qcar(v_522);
    v_524 = qcar(v_522);
    goto v_473;
v_474:
    v_523 = stack[0];
    goto v_475;
v_476:
    v_522 = stack[-3];
    goto v_477;
v_478:
    goto v_472;
v_473:
    goto v_474;
v_475:
    goto v_476;
v_477:
    v_522 = acons(v_524, v_523, v_522);
    env = stack[-4];
    stack[-3] = v_522;
    goto v_467;
v_469:
v_467:
    v_522 = stack[-2];
    v_522 = qcdr(v_522);
    stack[-2] = v_522;
    goto v_439;
v_438:
    v_522 = stack[-2];
    if (v_522 == nil) goto v_489;
    goto v_497;
v_493:
    v_523 = stack[-2];
    goto v_494;
v_495:
    v_522 = stack[-1];
    goto v_496;
v_497:
    goto v_493;
v_494:
    goto v_495;
v_496:
    v_522 = Lmodular_times(nil, v_523, v_522);
    env = stack[-4];
    fn = elt(env, 2); // !*n2f
    v_522 = (*qfn1(fn))(fn, v_522);
    env = stack[-4];
    stack[-2] = v_522;
    goto v_487;
v_489:
v_487:
v_502:
    v_522 = stack[-3];
    if (v_522 == nil) goto v_505;
    else goto v_506;
v_505:
    goto v_501;
v_506:
    v_522 = stack[-3];
    v_522 = qcdr(v_522);
    stack[0] = v_522;
    goto v_516;
v_512:
    v_523 = stack[-3];
    goto v_513;
v_514:
    v_522 = stack[-2];
    goto v_515;
v_516:
    goto v_512;
v_513:
    goto v_514;
v_515:
    v_522 = Lrplacd(nil, v_523, v_522);
    env = stack[-4];
    v_522 = stack[-3];
    stack[-2] = v_522;
    v_522 = stack[0];
    stack[-3] = v_522;
    goto v_502;
v_501:
    v_522 = stack[-2];
v_419:
    return onevalue(v_522);
}



// Code for lalr_prin_symbol

static LispObject CC_lalr_prin_symbol(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_478, v_479, v_480;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_480 = v_413;
// end of prologue
    goto v_423;
v_419:
    v_479 = v_480;
    goto v_420;
v_421:
    v_478 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_422;
v_423:
    goto v_419;
v_420:
    goto v_421;
v_422:
    if (v_479 == v_478) goto v_417;
    else goto v_418;
v_417:
    v_478 = elt(env, 1); // "$"
        return Lprinc(nil, v_478);
v_418:
    v_478 = v_480;
    if (is_number(v_478)) goto v_428;
    else goto v_429;
v_428:
    goto v_441;
v_437:
    v_479 = v_480;
    goto v_438;
v_439:
    v_478 = qvalue(elt(env, 2)); // terminal_codes
    goto v_440;
v_441:
    goto v_437;
v_438:
    goto v_439;
v_440:
    fn = elt(env, 3); // cdrassoc
    v_478 = (*qfn2(fn))(fn, v_479, v_478);
    env = stack[-1];
    v_478 = Lexplodec(nil, v_478);
    env = stack[-1];
    stack[0] = v_478;
v_434:
    v_478 = stack[0];
    if (v_478 == nil) goto v_446;
    else goto v_447;
v_446:
    v_478 = nil;
    goto v_433;
v_447:
    v_478 = stack[0];
    v_478 = qcar(v_478);
    v_478 = Lprinc(nil, v_478);
    env = stack[-1];
    v_478 = stack[0];
    v_478 = qcdr(v_478);
    stack[0] = v_478;
    goto v_434;
v_433:
    goto v_416;
v_429:
    v_478 = v_480;
    fn = elt(env, 4); // explode2uc
    v_478 = (*qfn1(fn))(fn, v_478);
    env = stack[-1];
    stack[0] = v_478;
v_462:
    v_478 = stack[0];
    if (v_478 == nil) goto v_467;
    else goto v_468;
v_467:
    v_478 = nil;
    goto v_461;
v_468:
    v_478 = stack[0];
    v_478 = qcar(v_478);
    v_478 = Lprinc(nil, v_478);
    env = stack[-1];
    v_478 = stack[0];
    v_478 = qcdr(v_478);
    stack[0] = v_478;
    goto v_462;
v_461:
    goto v_416;
    v_478 = nil;
v_416:
    return onevalue(v_478);
}



// Code for monomclone

static LispObject CC_monomclone(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_489, v_490, v_491, v_492;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_413;
// end of prologue
    v_489 = stack[0];
    if (v_489 == nil) goto v_417;
    else goto v_418;
v_417:
    v_489 = nil;
    goto v_416;
v_418:
    stack[-2] = nil;
    v_489 = (LispObject)16+TAG_FIXNUM; // 1
    v_489 = Lmkvect(nil, v_489);
    env = stack[-4];
    stack[-3] = v_489;
    goto v_437;
v_431:
    v_492 = stack[-3];
    goto v_432;
v_433:
    v_491 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_434;
v_435:
    goto v_444;
v_440:
    v_490 = stack[0];
    goto v_441;
v_442:
    v_489 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_443;
v_444:
    goto v_440;
v_441:
    goto v_442;
v_443:
    v_489 = *(LispObject *)((char *)v_490 + (CELL-TAG_VECTOR) + (((intptr_t)v_489-TAG_FIXNUM)/(16/CELL)));
    goto v_436;
v_437:
    goto v_431;
v_432:
    goto v_433;
v_434:
    goto v_435;
v_436:
    *(LispObject *)((char *)v_492 + (CELL-TAG_VECTOR) + (((intptr_t)v_491-TAG_FIXNUM)/(16/CELL))) = v_489;
    goto v_452;
v_448:
    v_490 = stack[0];
    goto v_449;
v_450:
    v_489 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_451;
v_452:
    goto v_448;
v_449:
    goto v_450;
v_451:
    v_489 = *(LispObject *)((char *)v_490 + (CELL-TAG_VECTOR) + (((intptr_t)v_489-TAG_FIXNUM)/(16/CELL)));
    stack[0] = v_489;
v_458:
    v_489 = stack[0];
    if (v_489 == nil) goto v_461;
    else goto v_462;
v_461:
    goto v_457;
v_462:
    goto v_470;
v_466:
    v_489 = stack[0];
    v_490 = qcar(v_489);
    goto v_467;
v_468:
    v_489 = stack[-2];
    goto v_469;
v_470:
    goto v_466;
v_467:
    goto v_468;
v_469:
    v_489 = cons(v_490, v_489);
    env = stack[-4];
    stack[-2] = v_489;
    v_489 = stack[0];
    v_489 = qcdr(v_489);
    stack[0] = v_489;
    goto v_458;
v_457:
    goto v_483;
v_477:
    stack[-1] = stack[-3];
    goto v_478;
v_479:
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    goto v_480;
v_481:
    v_489 = stack[-2];
    v_489 = Lreverse(nil, v_489);
    goto v_482;
v_483:
    goto v_477;
v_478:
    goto v_479;
v_480:
    goto v_481;
v_482:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_489;
    v_489 = stack[-3];
    goto v_416;
    v_489 = nil;
v_416:
    return onevalue(v_489);
}



// Code for remove!-free!-vars!-l

static LispObject CC_removeKfreeKvarsKl(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_520, v_521;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_413;
// end of prologue
    stack[-3] = nil;
    stack[-1] = nil;
    stack[0] = nil;
v_420:
    v_520 = stack[-2];
    if (!consp(v_520)) goto v_424;
    else goto v_425;
v_424:
v_429:
    v_520 = stack[-3];
    if (v_520 == nil) goto v_432;
    else goto v_433;
v_432:
    goto v_428;
v_433:
    v_520 = stack[0];
    if (v_520 == nil) goto v_438;
    else goto v_439;
v_438:
    goto v_449;
v_445:
    v_520 = stack[-1];
    v_520 = qcar(v_520);
    v_521 = qcar(v_520);
    goto v_446;
v_447:
    v_520 = stack[-3];
    v_520 = qcar(v_520);
    goto v_448;
v_449:
    goto v_445;
v_446:
    goto v_447;
v_448:
    if (equal(v_521, v_520)) goto v_443;
    else goto v_444;
v_443:
    v_520 = stack[-1];
    v_520 = qcar(v_520);
    stack[-2] = v_520;
    goto v_442;
v_444:
    goto v_464;
v_460:
    v_520 = stack[-3];
    v_521 = qcar(v_520);
    goto v_461;
v_462:
    v_520 = stack[-2];
    goto v_463;
v_464:
    goto v_460;
v_461:
    goto v_462;
v_463:
    v_520 = cons(v_521, v_520);
    env = stack[-4];
    stack[-2] = v_520;
    v_520 = lisp_true;
    stack[0] = v_520;
    goto v_442;
v_442:
    goto v_437;
v_439:
    goto v_476;
v_472:
    v_520 = stack[-3];
    v_521 = qcar(v_520);
    goto v_473;
v_474:
    v_520 = stack[-2];
    goto v_475;
v_476:
    goto v_472;
v_473:
    goto v_474;
v_475:
    v_520 = cons(v_521, v_520);
    env = stack[-4];
    stack[-2] = v_520;
    goto v_437;
v_437:
    v_520 = stack[-1];
    v_520 = qcdr(v_520);
    stack[-1] = v_520;
    v_520 = stack[-3];
    v_520 = qcdr(v_520);
    stack[-3] = v_520;
    goto v_429;
v_428:
    v_520 = stack[-2];
    goto v_419;
v_425:
    goto v_491;
v_487:
    v_520 = stack[-2];
    v_521 = qcar(v_520);
    goto v_488;
v_489:
    v_520 = elt(env, 2); // !*sq
    goto v_490;
v_491:
    goto v_487;
v_488:
    goto v_489;
v_490:
    if (v_521 == v_520) goto v_485;
    else goto v_486;
v_485:
    v_520 = stack[-2];
    v_520 = qcdr(v_520);
    v_520 = qcar(v_520);
    fn = elt(env, 3); // prepsq!*
    v_520 = (*qfn1(fn))(fn, v_520);
    env = stack[-4];
    stack[-2] = v_520;
    v_520 = lisp_true;
    stack[0] = v_520;
    goto v_420;
v_486:
    goto v_505;
v_501:
    v_521 = stack[-2];
    goto v_502;
v_503:
    v_520 = stack[-1];
    goto v_504;
v_505:
    goto v_501;
v_502:
    goto v_503;
v_504:
    v_520 = cons(v_521, v_520);
    env = stack[-4];
    stack[-1] = v_520;
    goto v_513;
v_509:
    v_520 = stack[-2];
    v_520 = qcar(v_520);
    fn = elt(env, 4); // remove!-free!-vars
    v_521 = (*qfn1(fn))(fn, v_520);
    env = stack[-4];
    goto v_510;
v_511:
    v_520 = stack[-3];
    goto v_512;
v_513:
    goto v_509;
v_510:
    goto v_511;
v_512:
    v_520 = cons(v_521, v_520);
    env = stack[-4];
    stack[-3] = v_520;
    v_520 = stack[-2];
    v_520 = qcdr(v_520);
    stack[-2] = v_520;
    goto v_420;
v_419:
    return onevalue(v_520);
}



// Code for get!+vec!+dim

static LispObject CC_getLvecLdim(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_420;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_420 = v_413;
// end of prologue
        return Llength(nil, v_420);
    return onevalue(v_420);
}



// Code for rl_ordatp

static LispObject CC_rl_ordatp(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_431, v_432;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_431 = v_414;
    v_432 = v_413;
// end of prologue
    goto v_421;
v_417:
    stack[0] = qvalue(elt(env, 1)); // rl_ordatp!*
    goto v_418;
v_419:
    goto v_428;
v_424:
    goto v_425;
v_426:
    goto v_427;
v_428:
    goto v_424;
v_425:
    goto v_426;
v_427:
    v_431 = list2(v_432, v_431);
    env = stack[-1];
    goto v_420;
v_421:
    goto v_417;
v_418:
    goto v_419;
v_420:
    {
        LispObject v_434 = stack[0];
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_434, v_431);
    }
}



// Code for mri_floorkernelp

static LispObject CC_mri_floorkernelp(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_418;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_418 = v_413;
// end of prologue
    fn = elt(env, 1); // kernels
    v_418 = (*qfn1(fn))(fn, v_418);
    env = stack[0];
    {
        fn = elt(env, 2); // mri_floorp
        return (*qfn1(fn))(fn, v_418);
    }
}



// Code for attributes

static LispObject CC_attributes(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_475, v_476;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_414;
    v_475 = v_413;
// end of prologue
    v_475 = Llength(nil, v_475);
    env = stack[-3];
    stack[-2] = v_475;
    v_475 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_475;
v_425:
    goto v_437;
v_433:
    v_476 = stack[-2];
    goto v_434;
v_435:
    v_475 = stack[0];
    goto v_436;
v_437:
    goto v_433;
v_434:
    goto v_435;
v_436:
    v_475 = difference2(v_476, v_475);
    env = stack[-3];
    v_475 = Lminusp(nil, v_475);
    env = stack[-3];
    if (v_475 == nil) goto v_430;
    goto v_424;
v_430:
    v_475 = stack[-1];
    v_475 = qcdr(v_475);
    stack[-1] = v_475;
    v_475 = stack[0];
    v_475 = add1(v_475);
    env = stack[-3];
    stack[0] = v_475;
    goto v_425;
v_424:
v_447:
    goto v_456;
v_452:
    v_475 = stack[-1];
    v_476 = qcar(v_475);
    goto v_453;
v_454:
    v_475 = elt(env, 2); // ! 
    goto v_455;
v_456:
    goto v_452;
v_453:
    goto v_454;
v_455:
    if (v_476 == v_475) goto v_451;
    goto v_446;
v_451:
    v_475 = stack[-1];
    v_475 = qcdr(v_475);
    stack[-1] = v_475;
    goto v_447;
v_446:
    goto v_471;
v_467:
    v_476 = stack[-1];
    goto v_468;
v_469:
    v_475 = elt(env, 3); // (!$)
    goto v_470;
v_471:
    goto v_467;
v_468:
    goto v_469;
v_470:
    if (equal(v_476, v_475)) goto v_466;
    v_475 = stack[-1];
    qvalue(elt(env, 4)) = v_475; // atts
    goto v_464;
v_466:
v_464:
    v_475 = nil;
    return onevalue(v_475);
}



// Code for constp

static LispObject CC_constp(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_438, v_439;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_438 = v_413;
// end of prologue
    v_439 = v_438;
    v_439 = (is_number(v_439) ? lisp_true : nil);
    if (v_439 == nil) goto v_417;
    else goto v_416;
v_417:
    v_439 = v_438;
    v_439 = Lconsp(nil, v_439);
    env = stack[0];
    if (v_439 == nil) goto v_422;
    else goto v_423;
v_422:
    v_438 = nil;
    goto v_421;
v_423:
    goto v_433;
v_429:
    v_438 = qcar(v_438);
    goto v_430;
v_431:
    v_439 = qvalue(elt(env, 1)); // domainlist!*
    goto v_432;
v_433:
    goto v_429;
v_430:
    goto v_431;
v_432:
    v_438 = Lmemq(nil, v_438, v_439);
    goto v_421;
    v_438 = nil;
v_421:
    v_439 = v_438;
v_416:
    return onevalue(v_439);
}



// Code for bcprod

static LispObject CC_bcprod(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_455, v_456, v_457;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_414;
    stack[-1] = v_413;
// end of prologue
    v_455 = qvalue(elt(env, 1)); // !*grmod!*
    if (v_455 == nil) goto v_419;
    goto v_427;
v_423:
    v_456 = stack[-1];
    goto v_424;
v_425:
    v_455 = stack[0];
    goto v_426;
v_427:
    goto v_423;
v_424:
    goto v_425;
v_426:
    v_455 = times2(v_456, v_455);
    env = stack[-2];
    {
        fn = elt(env, 3); // bcfi
        return (*qfn1(fn))(fn, v_455);
    }
v_419:
    goto v_442;
v_436:
    v_457 = stack[-1];
    goto v_437;
v_438:
    v_456 = stack[0];
    goto v_439;
v_440:
    v_455 = elt(env, 2); // times
    goto v_441;
v_442:
    goto v_436;
v_437:
    goto v_438;
v_439:
    goto v_440;
v_441:
    fn = elt(env, 4); // bcint2op
    v_455 = (*qfnn(fn))(fn, 3, v_457, v_456, v_455);
    env = stack[-2];
    if (v_455 == nil) goto v_434;
    else goto v_433;
v_434:
    goto v_452;
v_448:
    v_456 = stack[-1];
    goto v_449;
v_450:
    v_455 = stack[0];
    goto v_451;
v_452:
    goto v_448;
v_449:
    goto v_450;
v_451:
    fn = elt(env, 5); // multsq
    v_455 = (*qfn2(fn))(fn, v_456, v_455);
    env = stack[-2];
    {
        fn = elt(env, 6); // bccheckz
        return (*qfn1(fn))(fn, v_455);
    }
v_433:
    goto v_417;
    v_455 = nil;
v_417:
    return onevalue(v_455);
}



// Code for evmatrixcomp1

static LispObject CC_evmatrixcomp1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_488, v_489, v_490;
    LispObject fn;
    LispObject v_415, v_414, v_413;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evmatrixcomp1");
    va_start(aa, nargs);
    v_413 = va_arg(aa, LispObject);
    v_414 = va_arg(aa, LispObject);
    v_415 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_415,v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_413,v_414,v_415);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_415;
    stack[-2] = v_414;
    stack[-3] = v_413;
// end of prologue
v_412:
    v_488 = stack[-1];
    if (v_488 == nil) goto v_419;
    else goto v_420;
v_419:
    v_488 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_418;
v_420:
    goto v_432;
v_426:
    v_490 = stack[-3];
    goto v_427;
v_428:
    v_488 = stack[-1];
    v_489 = qcar(v_488);
    goto v_429;
v_430:
    v_488 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_431;
v_432:
    goto v_426;
v_427:
    goto v_428;
v_429:
    goto v_430;
v_431:
    fn = elt(env, 1); // evmatrixcomp2
    stack[0] = (*qfnn(fn))(fn, 3, v_490, v_489, v_488);
    env = stack[-5];
    goto v_444;
v_438:
    v_490 = stack[-2];
    goto v_439;
v_440:
    v_488 = stack[-1];
    v_489 = qcar(v_488);
    goto v_441;
v_442:
    v_488 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_443;
v_444:
    goto v_438;
v_439:
    goto v_440;
v_441:
    goto v_442;
v_443:
    fn = elt(env, 1); // evmatrixcomp2
    v_488 = (*qfnn(fn))(fn, 3, v_490, v_489, v_488);
    env = stack[-5];
    stack[-4] = stack[0];
    stack[0] = v_488;
    goto v_460;
v_456:
    v_489 = stack[-4];
    goto v_457;
v_458:
    v_488 = stack[0];
    goto v_459;
v_460:
    goto v_456;
v_457:
    goto v_458;
v_459:
    fn = elt(env, 2); // iequal
    v_488 = (*qfn2(fn))(fn, v_489, v_488);
    env = stack[-5];
    if (v_488 == nil) goto v_454;
    goto v_470;
v_464:
    v_490 = stack[-3];
    goto v_465;
v_466:
    v_489 = stack[-2];
    goto v_467;
v_468:
    v_488 = stack[-1];
    v_488 = qcdr(v_488);
    goto v_469;
v_470:
    goto v_464;
v_465:
    goto v_466;
v_467:
    goto v_468;
v_469:
    stack[-3] = v_490;
    stack[-2] = v_489;
    stack[-1] = v_488;
    goto v_412;
v_454:
    goto v_481;
v_477:
    v_489 = stack[-4];
    goto v_478;
v_479:
    v_488 = stack[0];
    goto v_480;
v_481:
    goto v_477;
v_478:
    goto v_479;
v_480:
    if (((intptr_t)(v_489)) > ((intptr_t)(v_488))) goto v_475;
    else goto v_476;
v_475:
    v_488 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_452;
v_476:
    v_488 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_452;
    v_488 = nil;
v_452:
    goto v_418;
    v_488 = nil;
v_418:
    return onevalue(v_488);
}



// Code for multpfsq

static LispObject CC_multpfsq(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_463, v_464;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_414;
    stack[-2] = v_413;
// end of prologue
    stack[-3] = nil;
v_419:
    v_463 = stack[-2];
    if (v_463 == nil) goto v_426;
    else goto v_427;
v_426:
    v_463 = lisp_true;
    goto v_425;
v_427:
    v_463 = stack[-1];
    v_463 = qcar(v_463);
    v_463 = (v_463 == nil ? lisp_true : nil);
    goto v_425;
    v_463 = nil;
v_425:
    if (v_463 == nil) goto v_423;
    v_463 = stack[-3];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_463);
    }
v_423:
    goto v_446;
v_440:
    v_463 = stack[-2];
    v_463 = qcar(v_463);
    stack[0] = qcar(v_463);
    goto v_441;
v_442:
    goto v_455;
v_451:
    v_463 = stack[-2];
    v_463 = qcar(v_463);
    v_464 = qcdr(v_463);
    goto v_452;
v_453:
    v_463 = stack[-1];
    goto v_454;
v_455:
    goto v_451;
v_452:
    goto v_453;
v_454:
    fn = elt(env, 2); // multsq
    v_464 = (*qfn2(fn))(fn, v_464, v_463);
    env = stack[-4];
    goto v_443;
v_444:
    v_463 = stack[-3];
    goto v_445;
v_446:
    goto v_440;
v_441:
    goto v_442;
v_443:
    goto v_444;
v_445:
    v_463 = acons(stack[0], v_464, v_463);
    env = stack[-4];
    stack[-3] = v_463;
    v_463 = stack[-2];
    v_463 = qcdr(v_463);
    stack[-2] = v_463;
    goto v_419;
    v_463 = nil;
    return onevalue(v_463);
}



// Code for collectindices_reversed

static LispObject CC_collectindices_reversed(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_462, v_463;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_414;
    stack[-1] = v_413;
// end of prologue
    v_462 = stack[-1];
    if (!consp(v_462)) goto v_421;
    else goto v_422;
v_421:
    v_462 = stack[-1];
    fn = elt(env, 1); // isanindex
    v_462 = (*qfn1(fn))(fn, v_462);
    if (v_462 == nil) goto v_427;
    goto v_435;
v_431:
    v_463 = stack[-1];
    goto v_432;
v_433:
    v_462 = stack[0];
    goto v_434;
v_435:
    goto v_431;
v_432:
    goto v_433;
v_434:
    return cons(v_463, v_462);
v_427:
    v_462 = stack[0];
    goto v_417;
    goto v_420;
v_422:
v_420:
v_443:
    v_462 = stack[-1];
    if (v_462 == nil) goto v_446;
    else goto v_447;
v_446:
    goto v_442;
v_447:
    goto v_455;
v_451:
    v_462 = stack[-1];
    v_463 = qcar(v_462);
    goto v_452;
v_453:
    v_462 = stack[0];
    goto v_454;
v_455:
    goto v_451;
v_452:
    goto v_453;
v_454:
    v_462 = CC_collectindices_reversed(elt(env, 0), v_463, v_462);
    env = stack[-2];
    stack[0] = v_462;
    v_462 = stack[-1];
    v_462 = qcdr(v_462);
    stack[-1] = v_462;
    goto v_443;
v_442:
    v_462 = stack[0];
v_417:
    return onevalue(v_462);
}



// Code for mo!=modiv1

static LispObject CC_moMmodiv1(LispObject env,
                         LispObject v_413, LispObject v_414)
{
    env = qenv(env);
    LispObject v_452, v_453;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_413,v_414);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_414;
    stack[-1] = v_413;
// end of prologue
v_418:
    v_452 = stack[-1];
    if (v_452 == nil) goto v_421;
    else goto v_422;
v_421:
    v_452 = lisp_true;
    goto v_417;
v_422:
    v_452 = stack[0];
    if (v_452 == nil) goto v_425;
    else goto v_426;
v_425:
    v_452 = nil;
    goto v_417;
v_426:
    goto v_440;
v_436:
    v_452 = stack[-1];
    v_453 = qcar(v_452);
    goto v_437;
v_438:
    v_452 = stack[0];
    v_452 = qcar(v_452);
    goto v_439;
v_440:
    goto v_436;
v_437:
    goto v_438;
v_439:
    v_452 = (LispObject)lesseq2(v_453, v_452);
    v_452 = v_452 ? lisp_true : nil;
    env = stack[-2];
    if (v_452 == nil) goto v_434;
    v_452 = stack[-1];
    v_452 = qcdr(v_452);
    stack[-1] = v_452;
    v_452 = stack[0];
    v_452 = qcdr(v_452);
    stack[0] = v_452;
    goto v_418;
v_434:
    v_452 = nil;
    goto v_417;
    goto v_420;
v_420:
    v_452 = nil;
v_417:
    return onevalue(v_452);
}



// Code for unpkp

static LispObject CC_unpkp(LispObject env,
                         LispObject v_413)
{
    env = qenv(env);
    LispObject v_538, v_539, v_540;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_413);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_413;
// end of prologue
    stack[-2] = nil;
    v_538 = stack[-1];
    if (!consp(v_538)) goto v_424;
    v_538 = stack[-1];
    goto v_419;
v_424:
    v_538 = stack[-1];
    v_538 = Lexplode(nil, v_538);
    env = stack[-3];
    stack[-1] = v_538;
    goto v_434;
v_430:
    v_538 = stack[-1];
    v_539 = Llength(nil, v_538);
    env = stack[-3];
    goto v_431;
v_432:
    v_538 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_433;
v_434:
    goto v_430;
v_431:
    goto v_432;
v_433:
    v_538 = (LispObject)geq2(v_539, v_538);
    v_538 = v_538 ? lisp_true : nil;
    env = stack[-3];
    stack[0] = v_538;
    v_538 = stack[0];
    if (v_538 == nil) goto v_441;
    v_538 = stack[-1];
    v_538 = Llength(nil, v_538);
    env = stack[-3];
    v_538 = Levenp(nil, v_538);
    env = stack[-3];
    if (v_538 == nil) goto v_444;
    else goto v_441;
v_444:
    goto v_453;
v_449:
    v_539 = elt(env, 2); // !0
    goto v_450;
v_451:
    v_538 = stack[-1];
    goto v_452;
v_453:
    goto v_449;
v_450:
    goto v_451;
v_452:
    v_538 = cons(v_539, v_538);
    env = stack[-3];
    stack[-1] = v_538;
    goto v_439;
v_441:
v_439:
v_458:
    v_538 = stack[-1];
    if (v_538 == nil) goto v_461;
    else goto v_462;
v_461:
    goto v_457;
v_462:
    v_538 = stack[0];
    if (v_538 == nil) goto v_468;
    goto v_474;
v_470:
    v_538 = stack[-1];
    v_539 = qcar(v_538);
    goto v_471;
v_472:
    v_538 = qvalue(elt(env, 3)); // diglist!*
    goto v_473;
v_474:
    goto v_470;
v_471:
    goto v_472;
v_473:
    v_538 = Lassoc(nil, v_539, v_538);
    v_538 = qcdr(v_538);
    v_539 = v_538;
    v_538 = stack[-1];
    v_538 = qcdr(v_538);
    stack[-1] = v_538;
    goto v_487;
v_483:
    goto v_493;
v_489:
    goto v_499;
v_495:
    goto v_496;
v_497:
    v_538 = (LispObject)160+TAG_FIXNUM; // 10
    goto v_498;
v_499:
    goto v_495;
v_496:
    goto v_497;
v_498:
    v_540 = times2(v_539, v_538);
    env = stack[-3];
    goto v_490;
v_491:
    goto v_506;
v_502:
    v_538 = stack[-1];
    v_539 = qcar(v_538);
    goto v_503;
v_504:
    v_538 = qvalue(elt(env, 3)); // diglist!*
    goto v_505;
v_506:
    goto v_502;
v_503:
    goto v_504;
v_505:
    v_538 = Lassoc(nil, v_539, v_538);
    v_538 = qcdr(v_538);
    goto v_492;
v_493:
    goto v_489;
v_490:
    goto v_491;
v_492:
    v_539 = plus2(v_540, v_538);
    env = stack[-3];
    goto v_484;
v_485:
    v_538 = stack[-2];
    goto v_486;
v_487:
    goto v_483;
v_484:
    goto v_485;
v_486:
    v_538 = cons(v_539, v_538);
    env = stack[-3];
    stack[-2] = v_538;
    goto v_466;
v_468:
    goto v_521;
v_517:
    goto v_526;
v_522:
    v_538 = stack[-1];
    v_539 = qcar(v_538);
    goto v_523;
v_524:
    v_538 = qvalue(elt(env, 3)); // diglist!*
    goto v_525;
v_526:
    goto v_522;
v_523:
    goto v_524;
v_525:
    v_538 = Lassoc(nil, v_539, v_538);
    v_539 = qcdr(v_538);
    goto v_518;
v_519:
    v_538 = stack[-2];
    goto v_520;
v_521:
    goto v_517;
v_518:
    goto v_519;
v_520:
    v_538 = cons(v_539, v_538);
    env = stack[-3];
    stack[-2] = v_538;
    goto v_466;
v_466:
    v_538 = stack[-1];
    v_538 = qcdr(v_538);
    stack[-1] = v_538;
    goto v_458;
v_457:
    v_538 = stack[-2];
        return Lnreverse(nil, v_538);
v_419:
    return onevalue(v_538);
}



// Code for times!-in!-vector

static LispObject CC_timesKinKvector(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_582, v_583, v_584, v_585, v_586, v_587, v_588, v_589, v_590, v_591, v_592, v_593, v_594, v_595, v_596;
    LispObject v_417, v_416, v_415, v_414, v_413;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 5, "times-in-vector");
    va_start(aa, nargs);
    v_413 = va_arg(aa, LispObject);
    v_414 = va_arg(aa, LispObject);
    v_415 = va_arg(aa, LispObject);
    v_416 = va_arg(aa, LispObject);
    v_417 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push5(v_417,v_416,v_415,v_414,v_413);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v_413,v_414,v_415,v_416,v_417);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_591 = v_417;
    v_592 = v_416;
    v_593 = v_415;
    v_594 = v_414;
    v_595 = v_413;
// end of prologue
    goto v_434;
v_430:
    v_583 = v_594;
    goto v_431;
v_432:
    v_582 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_433;
v_434:
    goto v_430;
v_431:
    goto v_432;
v_433:
    if (((intptr_t)(v_583)) < ((intptr_t)(v_582))) goto v_427;
    goto v_442;
v_438:
    v_583 = v_592;
    goto v_439;
v_440:
    v_582 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_441;
v_442:
    goto v_438;
v_439:
    goto v_440;
v_441:
    if (((intptr_t)(v_583)) < ((intptr_t)(v_582))) goto v_427;
    goto v_428;
v_427:
    v_582 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_423;
v_428:
    goto v_450;
v_446:
    v_583 = v_594;
    goto v_447;
v_448:
    v_582 = v_592;
    goto v_449;
v_450:
    goto v_446;
v_447:
    goto v_448;
v_449:
    v_582 = (LispObject)(intptr_t)((intptr_t)v_583 + (intptr_t)v_582 - TAG_FIXNUM);
    v_596 = v_582;
    v_582 = (LispObject)0+TAG_FIXNUM; // 0
    v_585 = v_582;
v_457:
    goto v_467;
v_463:
    v_583 = v_596;
    goto v_464;
v_465:
    v_582 = v_585;
    goto v_466;
v_467:
    goto v_463;
v_464:
    goto v_465;
v_466:
    v_582 = (LispObject)(intptr_t)((intptr_t)v_583 - (intptr_t)v_582 + TAG_FIXNUM);
    v_582 = ((intptr_t)(v_582) < 0 ? lisp_true : nil);
    if (v_582 == nil) goto v_462;
    goto v_456;
v_462:
    goto v_479;
v_473:
    v_584 = v_591;
    goto v_474;
v_475:
    v_583 = v_585;
    goto v_476;
v_477:
    v_582 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_478;
v_479:
    goto v_473;
v_474:
    goto v_475;
v_476:
    goto v_477;
v_478:
    *(LispObject *)((char *)v_584 + (CELL-TAG_VECTOR) + (((intptr_t)v_583-TAG_FIXNUM)/(16/CELL))) = v_582;
    v_582 = v_585;
    v_582 = (LispObject)((intptr_t)(v_582) + 0x10);
    v_585 = v_582;
    goto v_457;
v_456:
    v_582 = (LispObject)0+TAG_FIXNUM; // 0
    v_589 = v_582;
v_488:
    goto v_498;
v_494:
    v_583 = v_594;
    goto v_495;
v_496:
    v_582 = v_589;
    goto v_497;
v_498:
    goto v_494;
v_495:
    goto v_496;
v_497:
    v_582 = (LispObject)(intptr_t)((intptr_t)v_583 - (intptr_t)v_582 + TAG_FIXNUM);
    v_582 = ((intptr_t)(v_582) < 0 ? lisp_true : nil);
    if (v_582 == nil) goto v_493;
    goto v_487;
v_493:
    goto v_508;
v_504:
    v_583 = v_595;
    goto v_505;
v_506:
    v_582 = v_589;
    goto v_507;
v_508:
    goto v_504;
v_505:
    goto v_506;
v_507:
    v_582 = *(LispObject *)((char *)v_583 + (CELL-TAG_VECTOR) + (((intptr_t)v_582-TAG_FIXNUM)/(16/CELL)));
    v_590 = v_582;
    v_582 = (LispObject)0+TAG_FIXNUM; // 0
    v_588 = v_582;
v_515:
    goto v_525;
v_521:
    v_583 = v_592;
    goto v_522;
v_523:
    v_582 = v_588;
    goto v_524;
v_525:
    goto v_521;
v_522:
    goto v_523;
v_524:
    v_582 = (LispObject)(intptr_t)((intptr_t)v_583 - (intptr_t)v_582 + TAG_FIXNUM);
    v_582 = ((intptr_t)(v_582) < 0 ? lisp_true : nil);
    if (v_582 == nil) goto v_520;
    goto v_514;
v_520:
    goto v_535;
v_531:
    v_583 = v_589;
    goto v_532;
v_533:
    v_582 = v_588;
    goto v_534;
v_535:
    goto v_531;
v_532:
    goto v_533;
v_534:
    v_582 = (LispObject)(intptr_t)((intptr_t)v_583 + (intptr_t)v_582 - TAG_FIXNUM);
    goto v_545;
v_539:
    v_587 = v_591;
    goto v_540;
v_541:
    v_586 = v_582;
    goto v_542;
v_543:
    goto v_552;
v_548:
    goto v_557;
v_553:
    v_583 = v_591;
    goto v_554;
v_555:
    goto v_556;
v_557:
    goto v_553;
v_554:
    goto v_555;
v_556:
    v_585 = *(LispObject *)((char *)v_583 + (CELL-TAG_VECTOR) + (((intptr_t)v_582-TAG_FIXNUM)/(16/CELL)));
    goto v_549;
v_550:
    goto v_566;
v_562:
    v_584 = v_590;
    goto v_563;
v_564:
    goto v_572;
v_568:
    v_583 = v_593;
    goto v_569;
v_570:
    v_582 = v_588;
    goto v_571;
v_572:
    goto v_568;
v_569:
    goto v_570;
v_571:
    v_582 = *(LispObject *)((char *)v_583 + (CELL-TAG_VECTOR) + (((intptr_t)v_582-TAG_FIXNUM)/(16/CELL)));
    goto v_565;
v_566:
    goto v_562;
v_563:
    goto v_564;
v_565:
    v_582 = Lmodular_times(nil, v_584, v_582);
    env = stack[0];
    goto v_551;
v_552:
    goto v_548;
v_549:
    goto v_550;
v_551:
    {   intptr_t w = int_of_fixnum(v_585) + int_of_fixnum(v_582);
        if (w >= current_modulus) w -= current_modulus;
        v_582 = fixnum_of_int(w);
    }
    goto v_544;
v_545:
    goto v_539;
v_540:
    goto v_541;
v_542:
    goto v_543;
v_544:
    *(LispObject *)((char *)v_587 + (CELL-TAG_VECTOR) + (((intptr_t)v_586-TAG_FIXNUM)/(16/CELL))) = v_582;
    v_582 = v_588;
    v_582 = (LispObject)((intptr_t)(v_582) + 0x10);
    v_588 = v_582;
    goto v_515;
v_514:
    v_582 = v_589;
    v_582 = (LispObject)((intptr_t)(v_582) + 0x10);
    v_589 = v_582;
    goto v_488;
v_487:
    v_582 = v_596;
v_423:
    return onevalue(v_582);
}



setup_type const u02_setup[] =
{
    {"general-modular-times",   TOO_FEW_2,      CC_generalKmodularKtimes,WRONG_NO_2},
    {"multd",                   TOO_FEW_2,      CC_multd,      WRONG_NO_2},
    {"lalr_lr0_move_dot",       TOO_FEW_2,      CC_lalr_lr0_move_dot,WRONG_NO_2},
    {"reorder",                 CC_reorder,     TOO_MANY_1,    WRONG_NO_1},
    {"aconc*",                  TOO_FEW_2,      CC_aconcH,     WRONG_NO_2},
    {"tayexp-greaterp",         TOO_FEW_2,      CC_tayexpKgreaterp,WRONG_NO_2},
    {"*d2q",                    CC_Hd2q,        TOO_MANY_1,    WRONG_NO_1},
    {"talp_simplt",             CC_talp_simplt, TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_emptyclausep",      CC_ibalp_emptyclausep,TOO_MANY_1,WRONG_NO_1},
    {"compress*",               CC_compressH,   TOO_MANY_1,    WRONG_NO_1},
    {"noncomfp1",               CC_noncomfp1,   TOO_MANY_1,    WRONG_NO_1},
    {"*q2a",                    CC_Hq2a,        TOO_MANY_1,    WRONG_NO_1},
    {":minusp",                 CC_Tminusp,     TOO_MANY_1,    WRONG_NO_1},
    {"buchvevdivides?",         TOO_FEW_2,      CC_buchvevdividesW,WRONG_NO_2},
    {"vevmtest?",               TOO_FEW_2,      CC_vevmtestW,  WRONG_NO_2},
    {"ordpp",                   TOO_FEW_2,      CC_ordpp,      WRONG_NO_2},
    {"factorordp",              TOO_FEW_2,      CC_factorordp, WRONG_NO_2},
    {"csl_normbf",              CC_csl_normbf,  TOO_MANY_1,    WRONG_NO_1},
    {"collectindices",          CC_collectindices,TOO_MANY_1,  WRONG_NO_1},
    {"reval_without_mod",       CC_reval_without_mod,TOO_MANY_1,WRONG_NO_1},
    {"mo=sprod",                TOO_FEW_2,      CC_moMsprod,   WRONG_NO_2},
    {"mtp",                     CC_mtp,         TOO_MANY_1,    WRONG_NO_1},
    {"reduce_pv",               TOO_FEW_2,      CC_reduce_pv,  WRONG_NO_2},
    {"general-modular-plus",    TOO_FEW_2,      CC_generalKmodularKplus,WRONG_NO_2},
    {"*d2n",                    CC_Hd2n,        TOO_MANY_1,    WRONG_NO_1},
    {"aex_ctx",                 CC_aex_ctx,     TOO_MANY_1,    WRONG_NO_1},
    {"finde",                   TOO_FEW_2,      CC_finde,      WRONG_NO_2},
    {"mchk",                    TOO_FEW_2,      CC_mchk,       WRONG_NO_2},
    {"quotsq",                  TOO_FEW_2,      CC_quotsq,     WRONG_NO_2},
    {"get+vec+entry",           TOO_FEW_2,      CC_getLvecLentry,WRONG_NO_2},
    {"rl_simplat1",             TOO_FEW_2,      CC_rl_simplat1,WRONG_NO_2},
    {"qqe_qoptailp",            CC_qqe_qoptailp,TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_cequal",            TOO_FEW_2,      CC_ibalp_cequal,WRONG_NO_2},
    {"xsimp",                   CC_xsimp,       TOO_MANY_1,    WRONG_NO_1},
    {":onep",                   CC_Tonep,       TOO_MANY_1,    WRONG_NO_1},
    {"sublistp",                TOO_FEW_2,      CC_sublistp,   WRONG_NO_2},
    {"i2rd*",                   CC_i2rdH,       TOO_MANY_1,    WRONG_NO_1},
    {"aeval*",                  CC_aevalH,      TOO_MANY_1,    WRONG_NO_1},
    {"angles-equal",            TOO_FEW_2,      CC_anglesKequal,WRONG_NO_2},
    {"cali_bc_prod",            TOO_FEW_2,      CC_cali_bc_prod,WRONG_NO_2},
    {"sieve_pv",                TOO_FEW_2,      CC_sieve_pv,   WRONG_NO_2},
    {"*i2mod",                  CC_Hi2mod,      TOO_MANY_1,    WRONG_NO_1},
    {"getpower",                TOO_FEW_2,      CC_getpower,   WRONG_NO_2},
    {"delcp",                   CC_delcp,       TOO_MANY_1,    WRONG_NO_1},
    {"lalr_closure",            CC_lalr_closure,TOO_MANY_1,    WRONG_NO_1},
    {"rl_varlat",               CC_rl_varlat,   TOO_MANY_1,    WRONG_NO_1},
    {"sort",                    TOO_FEW_2,      CC_sort,       WRONG_NO_2},
    {"comfac-to-poly",          CC_comfacKtoKpoly,TOO_MANY_1,  WRONG_NO_1},
    {"mtchk",                   TOO_FEW_2,      CC_mtchk,      WRONG_NO_2},
    {"sfp",                     CC_sfp,         TOO_MANY_1,    WRONG_NO_1},
    {"tayexp-lessp",            TOO_FEW_2,      CC_tayexpKlessp,WRONG_NO_2},
    {"exptchksq",               CC_exptchksq,   TOO_MANY_1,    WRONG_NO_1},
    {"talp_varlt",              CC_talp_varlt,  TOO_MANY_1,    WRONG_NO_1},
    {"ibalp_cec",               CC_ibalp_cec,   TOO_MANY_1,    WRONG_NO_1},
    {"get_token",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_get_token},
    {"c:ordexn",                TOO_FEW_2,      CC_cTordexn,   WRONG_NO_2},
    {"bczero?",                 CC_bczeroW,     TOO_MANY_1,    WRONG_NO_1},
    {"prepsqxx",                CC_prepsqxx,    TOO_MANY_1,    WRONG_NO_1},
    {"order:",                  CC_orderT,      TOO_MANY_1,    WRONG_NO_1},
    {"smemqlp",                 TOO_FEW_2,      CC_smemqlp,    WRONG_NO_2},
    {"adddm",                   TOO_FEW_2,      CC_adddm,      WRONG_NO_2},
    {"negnumberchk",            CC_negnumberchk,TOO_MANY_1,    WRONG_NO_1},
    {"pappl0",                  TOO_FEW_2,      CC_pappl0,     WRONG_NO_2},
    {"rnonep:",                 CC_rnonepT,     TOO_MANY_1,    WRONG_NO_1},
    {"multiply-by-constant-mod-p",TOO_FEW_2,    CC_multiplyKbyKconstantKmodKp,WRONG_NO_2},
    {"lalr_prin_symbol",        CC_lalr_prin_symbol,TOO_MANY_1,WRONG_NO_1},
    {"monomclone",              CC_monomclone,  TOO_MANY_1,    WRONG_NO_1},
    {"remove-free-vars-l",      CC_removeKfreeKvarsKl,TOO_MANY_1,WRONG_NO_1},
    {"get+vec+dim",             CC_getLvecLdim, TOO_MANY_1,    WRONG_NO_1},
    {"rl_ordatp",               TOO_FEW_2,      CC_rl_ordatp,  WRONG_NO_2},
    {"mri_floorkernelp",        CC_mri_floorkernelp,TOO_MANY_1,WRONG_NO_1},
    {"attributes",              TOO_FEW_2,      CC_attributes, WRONG_NO_2},
    {"constp",                  CC_constp,      TOO_MANY_1,    WRONG_NO_1},
    {"bcprod",                  TOO_FEW_2,      CC_bcprod,     WRONG_NO_2},
    {"evmatrixcomp1",           WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_evmatrixcomp1},
    {"multpfsq",                TOO_FEW_2,      CC_multpfsq,   WRONG_NO_2},
    {"collectindices_reversed", TOO_FEW_2,      CC_collectindices_reversed,WRONG_NO_2},
    {"mo=modiv1",               TOO_FEW_2,      CC_moMmodiv1,  WRONG_NO_2},
    {"unpkp",                   CC_unpkp,       TOO_MANY_1,    WRONG_NO_1},
    {"times-in-vector",         WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_timesKinKvector},
    {NULL, (one_args *)"u02", (two_args *)"50248 5390434 3965084", 0}
};

// end of generated code
