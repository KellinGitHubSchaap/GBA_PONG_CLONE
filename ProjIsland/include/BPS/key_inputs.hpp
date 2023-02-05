#ifndef KEY_INPUTS_HPP
#define KEY_INPUTS_HPP

#include "../include/BPS/types.hpp"
#include "../include/BPS/gba.hpp"

#define KEYINPUT_REG    *(vu16*)(IORAM + 0x0130)    //!< Key Input
#define KEYCONTROL_REG  *(vu16*)(IORAM + 0x0132)    //!< Key Control
#define KEY_MASK        0x03FF

typedef enum KEYPAD_BITS
{
    key_a = 0, key_b,
    key_right, key_left, key_up, key_down,
    key_r, key_l,
    key_select, key_start
}KEYPAD_BITS;

#define KEY_A           0x0001  //!< Button A
#define KEY_B           0x0002  //!< Button B
#define KEY_SELECT      0x0004  //!< Button Select
#define KEY_START       0x0008  //!< Button Start
#define KEY_RIGHT       0x0010  //!< Button Right
#define KEY_LEFT        0x0020  //!< Button Left
#define KEY_UP          0x0040  //!< Button Up
#define KEY_DOWN        0x0080  //!< Button Down
#define KEY_R           0x0100  //!< Trigger R
#define KEY_L           0x0200  //!< Trigger L

#define CURRENT_KEY_DOWN(key)   (~(KEYINPUT_REG) &key)
#define CURRENT_KEY_UP(key)     ((KEYINPUT_REG) &key)

u16 __current_key = 0;
u16 __previous_key = 0;

INLINE void ScanKeys();     //!< Check the status of every key

INLINE void ScanKeys()
{
    __previous_key = __current_key;
    __current_key = ~KEYINPUT_REG & KEY_MASK;
}

INLINE u32 GetKey(u32 key);     //!< Detect key every frame

INLINE u32 GetKey(u32 key)
{
    return (__current_key &__previous_key) &key;
}

INLINE u32 GetKeyDown(u32 key);     //!< Detect key once when pressed

INLINE u32 GetKeyDown(u32 key)
{
    return (__current_key &~__previous_key) &key;
}

INLINE u32 GetKeyUp(u32 key);      //!< Detect key once when released

INLINE u32 GetKeyUp(u32 key)
{
    return (~__current_key &__previous_key) &key;
}

#endif // KEY_INPUTS_HPP