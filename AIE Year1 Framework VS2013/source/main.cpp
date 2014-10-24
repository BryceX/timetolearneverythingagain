#include "AIE.h"
#include <iostream>
#include <cstdlib> 
const int iScreenWidth = 672;
const int iScreenHeight = 780;
const char* pInvadersFont = "./fonts/invaders.fnt";
char score1[10] = "00000";
char highScore[10] = "00000";
char score2[10] = "00000";
char credit[10] = "99";
char insertCoins[20] = "Insert Coins";

unsigned int iArcadeMarquee;


unsigned int alienShips[18];

struct PlayerCannon
{
	unsigned int iSpriteID;
	float fWidth;
	float fHeight;
	void SetSize(float a_fWidth, float a_fHeight)
	{
		fWidth = a_fWidth;
		fHeight = a_fHeight;
	}

	float x;
	float y;
	void SetPosition(float a_x, float a_y)
	{
		x = a_x;
		y = a_y;
	}

	unsigned int iMoveLeftKey;
	unsigned int iMoveRightKey;
	void SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight)
	{
		iMoveLeftKey = a_moveLeft;
		iMoveRightKey = a_moveRight;
	}
	unsigned int iLeftMovementExtreme;
	unsigned int iRightMovementExtreme;
	void SetMovementExtremes(unsigned int a_leftExtreme, unsigned int a_RightExtreme)
	{
		iLeftMovementExtreme = a_leftExtreme;
		iRightMovementExtreme = a_RightExtreme;
	}

	void Move(float a_fTimeStep, float a_fSpeed)
	{
		if (IsKeyDown(iMoveLeftKey))
		{
			x -= a_fTimeStep * a_fSpeed;
			if (x < (iLeftMovementExtreme + fWidth*.5f))
			{
				x = (iLeftMovementExtreme + fWidth*.5f);
			}
		}
		if (IsKeyDown(iMoveRightKey))
		{
			x += a_fTimeStep * a_fSpeed;
			if (x >(iRightMovementExtreme - fWidth*.5f))
			{
				x = (iRightMovementExtreme - fWidth*.5f);
			}
		}
		MoveSprite(iSpriteID, x, y);
	}
};
struct Enemy
{
	int eLeft;
	int eRight;
	int eDown;
	int fEnemyX = iScreenWidth * 0.2;
	int fEnemyY = iScreenHeight * 0.7;
	int enemyWidth = 64;
	int enemyHeight = 32;
	void CreateEnemies()
	{
		
		for (int i = 0; i < 18; ++i)
		{
			alienShips[i] = CreateSprite("./images/invaders/invaders_1_00.png", enemyWidth, enemyHeight, true);
			MoveSprite(alienShips[i], fEnemyX, fEnemyY);
			fEnemyX += 0.12 * iScreenWidth;
			if (fEnemyX > iScreenWidth * 0.8f)
			{
				fEnemyX = iScreenWidth * 0.2f;
				fEnemyY -= 0.08 * iScreenHeight;
			}
		}

	}
		bool Move(float a_fDeltaTime, int a_Direction)
		{
			if (a_Direction == eLeft)
			{
				fEnemyX -= GetDeltaTime()*.1;
				if ( fEnemyX < enemyWidth*.5)
				{
					fEnemyX = enemyWidth*.5;
					fEnemyY -= iScreenHeight*.05;
					a_Direction = eRight;
					return true;
				}
			}
			if (a_Direction == eRight)
			{
				fEnemyX += GetDeltaTime()*.1;
				if ( fEnemyX >iScreenWidth - enemyWidth)
				{
					fEnemyX = iScreenWidth - enemyWidth;
					fEnemyY -= iScreenHeight*.05;
					return true;
				}
			}
			
	}
};


enum GAMESTATES{
	MAINMENU,
	GAMEPLAY,
	GAMEOVER
};
void UpdateMainMenu()
{
	MoveSprite(iArcadeMarquee, iScreenWidth*.5, iScreenHeight*.5);
	DrawSprite(iArcadeMarquee);
	DrawString(insertCoins, iScreenWidth * 0.37, iScreenHeight * 0.5);
	DrawString(credit, iScreenWidth * 0.25, iScreenHeight * 0.4);
}
void UpdateGameState()
{
	
	
	for (int i = 0; i < 18; ++i)
	{
		DrawSprite(alienShips[i]);
	}
	DrawLine(0, 40, iScreenWidth, 40, SColour(0x00, 0xFC, 0x00, 0xFF));
	SetFont(pInvadersFont);
	DrawString(score1, iScreenWidth * 0.025f, iScreenHeight - 2);
	DrawString(highScore, iScreenWidth * 0.425f, iScreenHeight - 2);
	DrawString(score2, iScreenWidth * 0.8f, iScreenHeight - 2);
}

int main( int argc, char* argv[] )
{	
    Initialise(672, 780, false, "My Awesome Game");
	AddFont(pInvadersFont);
	SetFont(pInvadersFont);
	
	iArcadeMarquee = CreateSprite("./images/Space-Invaders-Marquee.png", iScreenWidth, iScreenHeight, true);
	

	PlayerCannon player;
	player.fHeight = 32.f;
	player.fWidth = 64.f;
	player.iSpriteID = CreateSprite("./images/cannon.png", player.fWidth, player.fHeight, true);
	player.x = iScreenWidth * 0.5;
	player.y = 80;
	player.SetSize(64, 32);
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
			system("CLS");
			AddFont(pInvadersFont);
			SetFont(pInvadersFont);
			UpdateMainMenu();
			
			
			if (IsKeyDown(GLFW_KEY_ENTER))
			{
				currentState = GAMEPLAY;
			}
			system("CLS");
			
			
			break;



		case GAMEPLAY:
			system("CLS");
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
