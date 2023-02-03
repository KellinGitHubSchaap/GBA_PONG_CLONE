#ifndef EMULATOR_HPP
#define EMULATOR_HPP

#include <iostream>
#include "../include/BPS/types.hpp"

#define NOCASH_SIG      ((char*)0x04FFFA00)
#define REG_NOCASH_LOG  VOLADDR(0x04FFFA1C, u8)
#define VOLADDR(a, t)   (*(t volatile*)(a))

extern bool logInitNocash(void);
extern void logOutputNocash(u8 level, const char* message);

#endif // EMULATOR_HPP