#ifndef TILEBLOCK_DEFINES_HPP
#define TILEBLOCK_DEFINES_HPP

#include "../include/BPS/types.hpp"

typedef struct {u32 data[8];}TILE, TILE4;   //! 8x8 tiles using 4bpp

typedef TILE CHARBLOCK[512];    //! Block of tiles fit for 32 x 16 s-tiles

#define tile_mem ((CHARBLOCK*) 0x06000000)

#endif // TILEBLOCK_DEFINES_HPP