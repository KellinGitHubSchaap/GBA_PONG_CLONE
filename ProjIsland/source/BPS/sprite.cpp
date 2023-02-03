#include <cstring>
#include "../include/BPS/sprite.hpp"
#include "../include/main.hpp"

Sprite::Sprite(u32 tilePosition, 
                const u16 spriteTiles[], 
                u32 spriteTilesLength,
                u32 paletteBankPosition,
                const u16 spritePal[], 
                u32 spritePalLength)
{
    tileStartPos = tilePosition;
    paletteBankPos = paletteBankPosition;
    memcpy(&tile_mem[4][tilePosition], spriteTiles, spriteTilesLength);
    memcpy(&REG_OBJ_PAL4[paletteBankPosition], spritePal, spritePalLength);
};

void Sprite::Render()
{
    SetObjectAttributes(&_objBuffer[_oamIndex], ATTR0_SHAPE_SQUARE, ATTR1_SIZE_16, ATTR2_PALETTE_BANK(paletteBankPos) | tileStartPos);
    SetObjectPosition(&_objBuffer[_oamIndex], position.x, position.y);
    _oamIndex++;
};

void Sprite::SetPosition(u32 x, u32 y)
{
    position = {x, y};
};

void Sprite::SetSize(u32 width, u32 height)
{
    size = {width, height};
};

Vector2Int Sprite::GetPosition()
{
    return position;
};

Size2D Sprite::GetSize()
{
    return size;
};