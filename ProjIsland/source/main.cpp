#include "../include/BPS/main_include.hpp"
#include "../assets/player/player.h"
#include "../assets/player/player.c"

char debugText[200];

OBJ_ATTR _objBuffer[128];
u32 _oamIndex;

void ResetOAM()
{
    memset(_objBuffer, 0, sizeof(_objBuffer));
    _oamIndex = 0;
}

int main()
{
    irqInit();
    irqEnable(IRQ_VBLANK);

    DISPLAY_REGISTER = SCRN_LAYER_OBJ | OBJ_1D_MAPPING | DISPLAY_MODE0 | SCRN_LAYER_BG0;
    
    Sprite* spr = new Sprite(0, playerTiles, playerTilesLen, 0, playerPal, playerPalLen);
    
    OAMInit(_objBuffer, 128);

    spr->SetPosition(0, 15);

    while(1)
    {
        VBlankIntrWait();
        ResetOAM();

        spr->Render();

        OAMCopy(OAM_REGISTER, _objBuffer, _oamIndex);
    }

    return 0;
}
