#include "../include/BPS/physics.hpp"

// If a given position "A" overlaps with the position of position "B", a collision has occured and this function shall return true
bool Collision::OnBoxCollision(const u32 posXA, const u32 posYA, const u32 widthA, const u32 heightA, const u32 posXB, const u32 posYB, const u32 widthB, const u32 heightB)
{
    if(posXA < posXB + widthB && posXA + widthA > posXB && posYA < posYB + heightB && posYA + heightA > posYB)
    {
        return true;
    }

    return false;
}
