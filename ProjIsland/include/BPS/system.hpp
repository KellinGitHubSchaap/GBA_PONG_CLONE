#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "../include/BPS/types.hpp"
#include "../include/BPS/gba.hpp"

INLINE void VBlankIntrWait() { SystemCall(5); }

#endif // SYSTEM_HPP
