#ifndef TYPES_HPP
#define TYPES_HPP

// --- (Un-)Signed Types ---
// Unsigned means that a value can only be a positive number
// --- 
// Signed means that a value can become positive and negative but compensates 
// by splitting itself in half

typedef signed char     s8;
typedef signed short    s16;
typedef signed int      s32;

typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;

// --- Const Types ---
// Const is a data declaration that specifies that the object or variable isn't modifiable,
// meaning you can't change its stored value after it's declared

typedef const s8        cs8;
typedef const s16       cs16;
typedef const s32       cs32;

typedef const u8        cu8;
typedef const u16       cu16;
typedef const u32       cu32;

// --- Volatile Types ---
// Volatile is a type qualifier that you can use to declare that an object can be modified
// in the program by the hardware. Meaning that this value could change without the source code 
// telling it to do so.

typedef volatile s8     vs8;
typedef volatile s16    vs16;
typedef volatile s32    vs32;

typedef volatile u8     vu8;
typedef volatile u16    vu16;
typedef volatile u32    vu32;

typedef u16 COLOR_VALUE;

#define INLINE static inline

INLINE COLOR_VALUE RGB8(u8 red, u8 green, u8 blue)
{
    return (red >> 3) + ((green >> 3) << 5) + ((blue >> 3) << 10);
}

INLINE COLOR_VALUE RGB15(u32 red, u32 green, u32 blue)
{
    return (red&31) + ((green&31) << 5) + ((blue&31) << 10);
}

void *memorycopy(void *dst, const void *src, u32 size);

#ifndef NULL
#define NULL (void*)0
#endif

#endif // TYPES_HPP