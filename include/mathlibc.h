#ifndef MATHLIBC_H
#define MATHLIBC_H

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>

#define API_LOGGING 0
#define MLC_DEBUG   // for debugging purposes

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#define BUILD_API_DLL

#ifdef BUILD_API_DLL
	#define API __declspec(dllexport)
#else
	#define API __declspec(dllimport)
#endif

#define MATHCALL __cdecl

#elif __linux__

#define API
#define MATHCALL

#endif

typedef void*				any, any_t;				// Generic pointer type
typedef unsigned int		uint, uint_t;			// Unsigned int
typedef unsigned long		ulong, ulong_t;			// Unsigned long
typedef unsigned short		ushort, ushort_t;		// Unsigned short
typedef unsigned char		uchar, uchar_t;			// Unsigned char
typedef unsigned long long	ulonglong, ulonglong_t;	// Unsigned long long

typedef int					sint, sint_t;			// Signed int
typedef long				slong, slong_t;			// Signed long
typedef short				sshort, sshort_t;		// Signed short
typedef char				schar, schar_t;			// Signed char
typedef long long			slonglong, slonglong_t;	// Signed long long

typedef float				f32, f32_t;				// Float
typedef double				f64, f64_t;				// Double
typedef long double			f80, f80_t;				// Long double

typedef unsigned char		u8, u8_t;				// Unsigned 8-bit
typedef unsigned short		u16, u16_t;				// Unsigned 16-bit
typedef unsigned int		u32, u32_t;				// Unsigned 32-bit
typedef unsigned long long	u64, u64_t;				// Unsigned 64-bit

typedef char				i8, i8_t;				// Signed 8-bit
typedef short				i16, i16_t;				// Signed 16-bit
typedef int					i32, i32_t;				// Signed 32-bit
typedef long long			i64, i64_t;				// Signed 64-bit

typedef char*				cstr, cstr_t;			// C-string (pointer to char)
typedef const char*			ccstr, ccstr_t;			// Const C-string (pointer to const char)

#define NULL_VAL 0xDEADBEEF
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

// compiler-specific macro for type comparison
#ifdef _MSC_VER
	#define IS_POINTER(x) (sizeof(x) == sizeof(void*))
#else
	#define IS_POINTER(x) __builtin_types_compatible_p(__typeof__(x), __typeof__(&*(x)))
#endif

#endif MATHLIBC_H