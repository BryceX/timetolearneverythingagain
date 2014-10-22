#include "AIE.h"
#include <iostream>

const int screenWidth = 672;
const int screenHeight = 780;
const char* pInvadersFont = "./fonts/invaders.fnt";
char score1[10] = "00000";
char highScore[10] = "00000";
char score2[10] = "00000";
char credit[10] = "99";
char insertCoins[20] = "Insert Coins";
int playerWidth = 64;
int playerHeight = 32;

enum GAMESTATES{
	MAINMENU,
	GAMEPLAY,
	GAMEOVER
};
int main( int argc, char* argv[] )
{	
    Initialise(672, 780, false, "My Awesome Game");
	
	unsigned int iPlayerCannon = CreateSprite("./images/cannon.png", 64, 32, true);
	unsigned int iArcadeMarquee = CreateSprite("./images/Space-Invaders-Marquee.png", screenWidth, screenHeight, true);
	
	float fPlayerX = screenWidth * 0.5f;
	float fPlayerY = 80.f;
	MoveSprite(iPlayerCannon, fPlayerX, fPlayerY);
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

    

    //Game Loop
	GAMESTATES currentState = MAINMENU;
    do
    {
		switch (currentState)
		{
		case MAINMENU:
			MoveSprite(iArcadeMarquee, screenWidth*.5, screenHeight*.5);
			DrawSprite(iArcadeMarquee);
			DrawString(insertCoins, screenWidth * 0.37, screenHeight * 0.5);
			DrawString(credit, screenWidth * 0.25, screenHeight * 0.4);
			ClearScreen();
			if (IsKeyDown(KEY_ENTER))
			{
				currentState = GAMEPLAY;
			}
			break;



		case GAMEPLAY:
			if (IsKeyDown('A'))
			{
				fPlayerX -= 2.f;
				if (fPlayerX < (playerWidth*.5f))
				{
					fPlayerX = (playerWidth*.5f);
				}
			}
			MoveSprite(iPlayerCannon, fPlayerX, fPlayerY);
			DrawSprite(iPlayerCannon);

			DrawLine(0, 40, screenWidth, 40, SColour(0x00, 0xFC, 0x00, 0xFF));

			SetFont(pInvadersFont);
			DrawString(score1, screenWidth * 0.025f, screenHeight - 2);
			DrawString(highScore, screenWidth * 0.425f, screenHeight - 2);
			DrawString(score2, screenWidth * 0.8f, screenHeight - 2);
			DrawString(credit, screenWidth * 0.7f, 38);
			break;

		case GAMEOVER:
			break;


		}
		
       

    } while(!FrameworkUpdate());
	DestroySprite(iPlayerCannon);
    Shutdown();

    return 0;
}
