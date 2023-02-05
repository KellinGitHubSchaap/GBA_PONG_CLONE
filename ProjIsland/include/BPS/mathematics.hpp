#ifndef BASE_MATHEMATICS_HPP
#define BASE_MATHEMATICS_HPP

#include <iostream>
#include <math.h>

#include "../include/BPS/types.hpp"

typedef s32 FIXED_POINT;

#define FIX_SCALE      1<<8
#define FIX_SHIFT      8

INLINE FIXED_POINT multiplyFixed(FIXED_POINT valueA, FIXED_POINT valueB);
INLINE FIXED_POINT multiplyFixed(FIXED_POINT valueA, FIXED_POINT valueB)
{
    return (valueA*valueB) >> FIX_SHIFT;

    // -- EXAMPLE --
    // FIXED_POINT valueA = 0x007; // 7
    // FIXED_POINT valueB = 0x008; // 8
    // FIXED_POINT valueC = multiplyFixed(valueA << 4, valueB << 4);
}

INLINE FIXED_POINT divideFixed(FIXED_POINT valueA, FIXED_POINT valueB);
INLINE FIXED_POINT divideFixed(FIXED_POINT valueA, FIXED_POINT valueB)
{
    return ((valueA)*FIX_SCALE)/(valueB);

    // -- EXAMPLE --
    // FIXED_POINT valueA = 0x002A; // 42
    // FIXED_POINT valueB = 0x0007; // 7
    // FIXED_POINT valueC = divedFixed(valueA, valueB) >> SCALE_BACK;
}

struct Vector2Int
{
    u32 x;
    u32 y;
};

struct Size2D
{
    u32 width;
    u32 height;
};

#endif // BASE_MATHEMATICS_HPP