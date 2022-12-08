#include "../include/BPS/emulator.hpp"

extern bool logInitNocash(void)
{
    for (u32 i = 0; i < 6; i++ )
    {
        if("no$gba"[i] != NOCASH_SIG[i])
        {
            return false;
        }
    }
    return true;
}

extern void logOutputNocash(u8 level, const char* message)
{
    (void)level;

    while(*message)
    {
        REG_NOCASH_LOG =  *message++;
    }

    REG_NOCASH_LOG = '\n';
}


// To Set up a logable text do the following
// 1. new char debugText[value];
// 2. fill debugText[value] with text value -> snprintf(debugText, sizeof(debugText), text);
// 3. check if logInitNocash = true
// 4. output text logOutputNocash(0, debugText[value])
