#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "../include/BPS/types.hpp"
#include "../include/BPS/gba.hpp"

#define DISPLAY_REGISTER        *((vu16*)(IORAM + 0x0000))  //!< This register controls the GBA display
#define DISPLAY_STAT_REGISTER   *((vu16*)(IORAM + 0x0004))  //!< This register holds the LCD interrupts

#define SCREEN_WIDTH    240
#define SCREEN_HEIGHT   160

// --- "text" Modes ---
#define DISPLAY_MODE0       0x0000  //!< 4 tiled background layers | can't be scaled nor rotated | move only
#define DISPLAY_MODE1       0x0001  //!< 3 tiled background layers | 0 & 1 can't be scaled nor rotated | 2 can be scaled, rotated, and moved
#define DISPLAY_MODE2       0x0002  //!< 2 tiled background layers | full scaling, rotating and movement

// --- Screen Layers ---
#define SCRN_LAYER_BG0       0x0100  //!< can't be rotated/scaled | allows movement
#define SCRN_LAYER_BG1       0x0200  //!< can't be rotated/scaled | allows movement
#define SCRN_LAYER_BG2       0x0400  //!< can be rotated/scaled and allows movement
#define SCRN_LAYER_BG3       0x0800  //!< can be rotated/scaled and allows movement
#define SCRN_LAYER_OBJ       0x1000  //!< sprite object layer

// --- Sprite Mapping Mode --- 
#define OBJ_2D_MAPPING      0x0000  //!< In 2D mapping, the sprite is one big bitmap 
#define OBJ_1D_MAPPING      0x0040  //!< In 1D mapping, the sprite is an array of tiles

#endif // DISPLAY_HPP