#ifndef TYPES_H

#define TYPES_H

#include <limits.h>

typedef unsigned char u8;
typedef signed char s8;
#define U8_MIN ((u8)0x00)
#define U8_MAX ((u8)0xFF)
#define S8_MIN ((s8)0x80)
#define S8_MAX ((s8)0x7F)

typedef unsigned short u16;
typedef signed short s16;
#define U16_MIN ((u16)0x0000)
#define U16_MAX ((u16)0xFFFF)
#define S16_MIN ((s16)0x8000)
#define S16_MAX ((s16)0x7FFF)

typedef unsigned long u32;
typedef signed long s32;
#define U32_MIN ((u32)0x00000000)
#define U32_MAX ((u32)0xFFFFFFFF)
#define S32_MIN ((s32)0x80000000)
#define S32_MAX ((s32)0x7FFFFFFF)

typedef unsigned long long u64;
typedef signed long long s64;
#define U64_MIN ((u64)0x0000000000000000)
#define U64_MAX ((u64)0xFFFFFFFFFFFFFFFF)
#define S64_MIN ((s64)0x8000000000000000)
#define S64_MAX ((s64)0x7FFFFFFFFFFFFFFF)

typedef double f32;
typedef long double f64;

#endif
