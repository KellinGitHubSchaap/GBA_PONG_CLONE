#include "../include/BPS/main_include.hpp"

#include "../assets/playerpaddle.h"
#include "../assets/playerpaddle.c"

#include "../assets/ball.h"
#include "../assets/ball.c"

#include "../include/player_setup.hpp"
#include "../include/ball_setup.hpp"

char testText[200];

OBJ_ATTR _objBuffer[128];
u32 _oamIndex;

void SetUpSprite()
{
    memcpy(&tile_mem[4][0], playerpaddleTiles, playerpaddleTilesLen);
    memcpy(&REG_OBJ_PAL4[0], playerpaddlePal, playerpaddlePalLen);

    memcpy(&tile_mem[4][8], ballTiles, ballTilesLen);
    memcpy(&REG_OBJ_PAL4[1], ballPal, ballPalLen);
}
void ResetOAM()
{
    memset(_objBuffer, 0, sizeof(_objBuffer));
    _oamIndex = 0;
}

Player _player1;
Player _player2;

void InitPlayers();
void MovePlayer();

Ball _ball;
void InitBall();

enum GAMESTATE {MENU, PAUSE, PLAY, END} _gameStates;

int main()
{

    irqInit();
    irqEnable(IRQ_VBLANK);

    DISPLAY_REGISTER = SCRN_LAYER_OBJ | OBJ_1D_MAPPING | DISPLAY_MODE0 | SCRN_LAYER_BG0;

    SetUpSprite();
    OAMInit(_objBuffer, 128);

    InitPlayers();
    InitBall();

    while(1)
    {
        VBlankIntrWait();
        ResetOAM();

        ScanKeys();

        if(_gameStates == MENU || _gameStates == PAUSE) 
        {
            _player1.Render();
            _player2.Render();

            _ball.Render();

            if(GetKeyDown(KEY_START)) {_gameStates = PLAY;}
        }
        else if(_gameStates == PLAY)
        {
            MovePlayer();

            _ball.posX += _ball.moveDirX;
            _ball.posY += _ball.moveDirY;

            if(_ball.posX < 0 || _ball.posX > SCREEN_WIDTH) 
            {
                _ball.posX = 120; 
                _ball.posY = 80;

                _player1.posY = 80;
                _player2.posY = 80;

                _gameStates = PAUSE;
            }

            if(_ball.posY < 0 || _ball.posY > SCREEN_HEIGHT - _ball.height) { _ball.moveDirY *= -1; }

            _ball.Render();

            if(Collision::OnBoxCollision(_ball.posX + 6, _ball.posY, _ball.width, _ball.height, _player1.posX, _player1.posY, _player1.width, _player1.height))
            {
                _ball.moveDirX = 1;
            }
            else if(Collision::OnBoxCollision(_ball.posX, _ball.posY, _ball.width - 6, _ball.height, _player2.posX, _player2.posY, _player2.width, _player2.height))
            {
                _ball.moveDirX = -1; 
            }

            
        }

        OAMCopy(OAM_REGISTER, _objBuffer, _oamIndex);
    }

    return 0;
}

void InitPlayers()
{
    _player1.objBufferSpot = 0;
    _player2.objBufferSpot = 1;

    _player1.posX = 20;
    _player2.posX = 200;
}

void MovePlayer()
{
    if(GetKey(KEY_UP) && _player1.posY > 0) { _player1.posY -= _player1.movementSpeed; }
    else if(GetKey(KEY_DOWN) && _player1.posY + _player1.height < SCREEN_HEIGHT) { _player1.posY += _player1.movementSpeed; }
    _player1.Render();

    if(GetKey(KEY_A) && _player2.posY > 0) { _player2.posY -= _player2.movementSpeed;}
    else if(GetKey(KEY_B) && _player2.posY + _player2.height < SCREEN_HEIGHT) {_player2.posY += _player2.movementSpeed;}
    _player2.Render();
}

void InitBall()
{
    _ball.posX = 120;
    _ball.objBufferSpot = 2;
}

//TODO: Show 2 Sprites that will show the score