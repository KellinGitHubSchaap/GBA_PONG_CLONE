#include "../include/player_setup.hpp"
#include "../include/main.hpp"

Player::Player()
: mainCharAttr{&_objBuffer[objBufferSpot]}
{}

void Player::Render()
{
    SetObjectAttributes(&_objBuffer[_oamIndex], ATTR0_SHAPE_TALL, ATTR1_SIZE_32, ATTR2_PALETTE_BANK(paletteBank) | tile);
    SetObjectPosition(&_objBuffer[_oamIndex], posX, posY);
    _oamIndex++;
} 