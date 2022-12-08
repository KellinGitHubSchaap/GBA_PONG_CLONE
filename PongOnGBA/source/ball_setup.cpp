#include "../include/ball_setup.hpp"
#include "../include/main.hpp"

Ball::Ball()
: mainCharAttr{&_objBuffer[objBufferSpot]}{}

void Ball::Render()
{
    SetObjectAttributes(&_objBuffer[_oamIndex], ATTR0_SHAPE_TALL, ATTR1_SIZE_8, ATTR2_PALETTE_BANK(paletteBank) | tile);
    SetObjectPosition(&_objBuffer[_oamIndex], posX, posY);
    _oamIndex++;
}
