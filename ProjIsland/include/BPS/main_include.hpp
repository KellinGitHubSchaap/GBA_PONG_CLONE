#ifndef MAIN_INCLUDE_HPP
#define MAIN_INCLUDE_HPP

#include <array>
#include <typeinfo>
#include <cstdio>
#include <iostream>
#include <cstring>

#include "../include/BPS/types.hpp"
#include "../include/BPS/gba.hpp"

#include "../include/BPS/display.hpp"
#include "../include/BPS/key_inputs.hpp"
#include "../include/BPS/interrupt.hpp"
#include "../include/BPS/system.hpp"

#include "../include/BPS/object_headers/object_attributes.hpp"
#include "../include/BPS/object_headers/tileblock_defines.hpp"
#include "../include/BPS/object_headers/palette_defines.hpp"
#include "../include/BPS/object_headers/object_defines.hpp"
#include "../include/BPS/object_headers/object_defines.cpp"

#include "../include/BPS/background_headers/bg_defines.hpp"
#include "../include/BPS/background_headers/bg_attributes.hpp"

#include "../include/BPS/physics.hpp"
#include "../source/BPS/physics.cpp"

#include "../include/BPS/sprite.hpp"
#include "../source/BPS/sprite.cpp"

#include "../include/BPS/emulator.hpp"
#include "../source/BPS/emulator.cpp"


#endif // MAIN_INCLUDE_HPP
