#ifndef PLAYER_SETUP_HPP
#define PLAYER_SETUP_HPP

#include "../include/BPS/types.hpp"
#include "../include/BPS/object_headers/object_defines.hpp"

class Player
{
    public:
        Player();

        s32 posX = 20;
        s32 posY = 80;

        u32 tile = 0;
        u32 paletteBank = 0;

        u32 objBufferSpot = 0;

        OBJ_ATTR* mainCharAttr;

        s32 width = 16;
        s32 height = 32;

        u32 movementSpeed = 2;

        void Render();
};


#endif // PLAYER_SETUP_HPP