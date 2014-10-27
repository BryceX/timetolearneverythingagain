#include "AIE.h"
#include <iostream>
#include <cstdlib> 
#include <Player.h>
#include <Enemy.h>
const int iScreenWidth = 672;
const int iScreenHeight = 780;
const char* pInvadersFont = "./fonts/invaders.fnt";
char score1[10] = "00000";
char highScore[10] = "00000";
char score2[10] = "00000";
char credit[10] = "99";
char insertCoins[20] = "Insert Coins";


struct Background
{
	unsigned int iArcadeMarquee;
	void UpdateMainMenu()
	{
		MoveSprite(iArcadeMarquee, iScreenWidth*.5, iScreenHeight*.5);
		DrawSprite(iArcadeMarquee);
		DrawString(insertCoins, iScreenWidth * 0.37, iScreenHeight * 0.5);
		DrawString(credit, iScreenWidth * 0.25, iScreenHeight * 0.4);
	}
};





enum GAMESTATES{
	MAINMENU,
	GAMEPLAY,
	GAMEOVER
};

void UpdateGameState()
{
	DrawLine(0, 40, iScreenWidth, 40, SColour(0x00, 0xFC, 0x00, 0xFF));
	SetFont(pInvadersFont);
	DrawString(score1, iScreenWidth * 0.025f, iScreenHeight - 2);
	DrawString(highScore, iScreenWidth * 0.425f, iScreenHeight - 2);
	DrawString(score2, iScreenWidth * 0.8f, iScreenHeight - 2);
}

int main( int argc, char* argv[] )
{	
    Initialise(672, 780, false, "Tutorial");
	AddFont(pInvadersFont);
	SetFont(pInvadersFont);
	
	Background mainMenu;
	mainMenu.iArcadeMarquee = CreateSprite("./images/Space-Invaders-Marquee.png", iScreenWidth, iScreenHeight, true);
	
	Enemy enemy1;
	enemy1.enemyWidth = 64;
	enemy1.enemyHeight = 32;
	enemy1.enemySpriteID = CreateSprite("./images/invaders/invaders_1_00.png", enemy1.enemyWidth, enemy1.enemyHeight, true);
	enemy1.SetPosition(iScreenWidth*.2, iScreenHeight*.7);

	/*
	for (int i = 0; i < 18; ++i)
	{
		
		
		
		enemy1.fEnemyX += 0.12 * iScreenWidth;
		if (enemy1.fEnemyX > iScreenWidth * 0.8f)
		{
			enemy1.fEnemyX = iScreenWidth * 0.2f;
			enemy1.fEnemyY -= 0.08 * iScreenHeight;
		}		
	}*/
	
	
	

	Player player;
	player.fWidth = 64;
	player.fHeight = 32;
	player.SetSpriteID(CreateSprite("./images/cannon.png", player.GetWidth(), player.GetHeight(), true));
	player.SetPosition(iScreenWidth*.5, 80);
	player.SetMovementExtremes(0, 672);
	player.SetMovementKeys('A', 'D');
	
	
	
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

    

    //Game Loop
	GAMESTATES currentState = MAINMENU;
    do
    {
		switch (currentState)
		{
		case MAINMENU:

			AddFont(pInvadersFont);
			SetFont(pInvadersFont);
			mainMenu.UpdateMainMenu();


			if (IsKeyDown(GLFW_KEY_ENTER))
			{
				currentState = GAMEPLAY;
			}
			ClearScreen();


			break;



		case GAMEPLAY:
			
			enemy1.Movement(iScreenWidth, iScreenHeight);
			
			MoveSprite(enemy1.enemySpriteID, enemy1.fEnemyX, enemy1.fEnemyY);
			DrawSprite(enemy1.enemySpriteID);
			
			
			UpdateGameState();
			player.Move(GetDeltaTime(), iScreenWidth*.2);
			MoveSprite(player.iSpriteID, player.x, player.y);
			DrawSprite(player.iSpriteID);
			
			if (IsKeyDown(GLFW_KEY_RIGHT_SHIFT))
			{
				currentState = GAMEOVER;
			}
			ClearScreen();
			break;

		case GAMEOVER:
			ClearScreen();
			if (IsKeyDown(GLFW_KEY_ENTER))
			{
				currentState = MAINMENU;
			}
			ClearScreen();
			break;
		}
		
       

	} while (FrameworkUpdate() == false);
	DestroySprite(player.iSpriteID);
	
    Shutdown();

    return 0;
}
