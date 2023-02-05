#ifndef BG_DEFINES_HPP
#define BG_DEFINES_HPP

#include "../include/BPS/types.hpp"
#include "../include/BPS/gba.hpp"

#define ALIGN4      alignas(4)

#define BG0_CONTROL_REGISTER    *(vu16*)(IORAM + 0x0008)    // Control over bg 0
#define BG0_HOR_OFFSET          *(vu16*)(IORAM + 0x0010)    // Horizontal offset 
#define BG0_VER_OFFSET          *(vu16*)(IORAM + 0x0012)    // Vertical offset

#define BG1_CONTROL_REGISTER    *(vu16*)(IORAM + 0x000A)    // Control over bg 1
#define BG1_HOR_OFFSET          *(vu16*)(IORAM + 0x0014)    // Horizontal offset 
#define BG1_VER_OFFSET          *(vu16*)(IORAM + 0x0016)    // Vertical offset

#define BG2_CONTROL_REGISTER    *(vu16*)(IORAM + 0x000C)    // Control over bg 2
#define BG2_HOR_OFFSET          *(vu16*)(IORAM + 0x0018)    // Horizontal offset 
#define BG2_VER_OFFSET          *(vu16*)(IORAM + 0x001A)    // Vertical offset

#define BG3_CONTROL_REGISTER    *(vu16*)(IORAM + 0x000E)    // Control over bg 3
#define BG3_HOR_OFFSET          *(vu16*)(IORAM + 0x001C)    // Horizontal offset 
#define BG3_VER_OFFSET          *(vu16*)(IORAM + 0x001E)    // Vertical offset

typedef u16 SCREEN_ENTRY;       
typedef SCREEN_ENTRY    SCREENBLOCK[1024]; //! stores the tilemap | Screenblock is a struct

typedef struct ALIGN4 BG_OFFSET
{
    s16 offsetX;
    s16 offsetY;
}BG_OFFSET;

#define screen_entry_memory    ((SCREENBLOCK*)VRAM)    //! SCREEN_ENTRY_MEMORY maps out the VRAM into SCREENBLOCK screen entries, making it easier to find a specific entries easier

#define BACKGROUND_PALETTE_MEMORY ((COLOR_VALUE*)PRAM)

#endif // BG_DEFINES_HPP