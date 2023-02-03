#include "../include/BPS/object_headers/object_defines.hpp"

void OAMInit(OBJ_ATTR* obj, unsigned count)
{
    u32* destination = (u32*)obj;

    u32 iteration = count;
    while(iteration--)
    {
        *destination++ = ATTR0_OBJ_MODE_HIDE;
        *destination++ = 0;
    }

    OAMCopy(OAM_REGISTER, obj, count);

}

void OAMCopy(OBJ_ATTR* destination, const OBJ_ATTR* source, unsigned count)
{
    while(count--)
    {
        *destination++ = *source++;
    }
}