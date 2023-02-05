#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "../include/BPS/types.hpp"
#include "../include/BPS/object_headers/object_defines.hpp"
#include "../include/BPS/object_headers/tileblock_defines.hpp"
#include "../include/BPS/object_headers/palette_defines.hpp"
#include "../include/BPS/mathematics.hpp"

class Sprite
{
    public:
        Sprite(u32 tilePosition, 
                const void* spriteTiles, 
                u32 spriteTilesLength,
                u32 paletteBankPosition,
                const void* spritePal, 
                u32 spritePalLength);

        u16 tileStartPos = 0;
        u16 paletteBankPos = 0;

        void SetPosition(u32 x, u32 y);
        void SetSize(u32 width, u32 height);

        Vector2Int GetPosition();
        Size2D GetSize();

        void Render();
    private:
        Vector2Int position = {0, 0};
        Size2D size = {0, 0};
        
        


};

#endif // SPRITE_HPP