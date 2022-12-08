#ifndef BALL_SETUP_HPP
#define BALL_SETUP_HPP

#include "../include/BPS/types.hpp"
#include "../include/BPS/object_headers/object_defines.hpp"

class Ball
{
    public:
        Ball();

        s32 posX = 20;
        s32 posY = 80;

        u32 tile = 8;
        u32 paletteBank = 1;

        u32 objBufferSpot = 0;

        OBJ_ATTR* mainCharAttr;

        s32 width = 8;
        s32 height = 8;

        u32 movementSpeed = 2;
        u32 moveDirX = 1;
        u32 moveDirY = 1;

        void Render();
};


#endif // BALL_SETUP_HPP