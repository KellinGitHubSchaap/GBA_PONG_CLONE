#ifndef INTERRUPT_HPP
#define INTERRUPT_HPP

#ifdef __cplusplus
extern "C" {
#endif

#include "../include/BPS/gba.hpp"
#include "../include/BPS/types.hpp"

#define REG_IE      *(vu16*)(IORAM + 0x200)
#define REG_IME     *(vu16*)(IORAM + 0x208)

typedef enum irqMASKS
{
    IRQ_VBLANK  =   (1<<0)
}irqMASK;

[[deprecated]]
void InitInterrupt(void);
void irqInit();             //!< Initialize Interrupt ReQuest

[[deprecated]]
void EnableInterrupt(irqMASK mask);
void irqEnable(int mask);

#ifdef __cplusplus
}
#endif

#endif // INTERRUPT_HPP