#ifndef GBA_HPP
#define GBA_HPP

#include "../BPS/types.hpp"

    // --- Read and write ---
#define EWRAM           0x02000000  //!< Address of gba's External Work RAM
#define IWRAM           0x03000000  //!< Address of gba's Internal Work RAM 
#define IORAM           0x04000000  //!< Address of gba's hardware registers
#define PRAM            0x05000000  //!< Address of gba's Palette RAM
#define VRAM            0x06000000  //!< Address of gba's Video RAM
#define OAM             0x07000000  //!< Address of gba's Object Attribute Memory

    // --- Readable only! ---
#define ROM             0x08000000  //!< Address of the cardrigde ROM
#define SRAM            0x0E000000  //!< Address of the save data of a cardrigde ROM 
#define BIOS            0x00000000  //!< Address of the executable ROM
    // ---      ---       ---

#if defined (__thumb__)
#define SystemCall(Number)  __asm("SWI  "#Number"\n" ::: "r0", "r1", "r2", "r3")
#else
#define SystemCall(Number)  __asm("SWI  "#Number" << 16\n" ::: "r0", "r1", "r2", "r3")
#endif // __thumb__ SystemCall()

#endif // GBA_HPP