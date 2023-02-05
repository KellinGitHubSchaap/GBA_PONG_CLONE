#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "../include/BPS/types.hpp"
#include "../include/BPS/mathematics.hpp"

class Collision
{
    public:
     static bool OnBoxCollision(const u32 posXA, const u32 posYA, const u32 widthA, const u32 heightA, const u32 posXB, const u32 posYB, const u32 widthB, const u32 heightB);
};


#endif // PHYSICS_HPP