#include "Enemy.h"
#include "AIE.h"

Enemy::Enemy()
{
}


	
	void Enemy::Movement(float iScreenWidth, float iScreenHeight)
	{
		if (Moveleft)
		{

			fEnemyX -= iScreenWidth*GetDeltaTime()*.2;
			if (fEnemyX < enemyWidth*.5)
			{
				fEnemyX = enemyWidth*.5;
				fEnemyY -= iScreenHeight*.005;
				Moveleft = false;
				Moveright = true;

			}
		}
		if (Moveright)
		{
			fEnemyX += iScreenWidth*GetDeltaTime()*.2;
			if (fEnemyX > iScreenWidth - enemyWidth*.5)
			{
				fEnemyX = iScreenWidth - enemyWidth*.5;
				fEnemyY -= iScreenHeight*.005;
				Moveleft = true;
				Moveright = false;
			}
		}
	}
	void Enemy::SetPosition(float e_x, float e_y)
	{
		this->fEnemyX = e_x;
		this->fEnemyY = e_y;
	}
	float Enemy::GetX()
	{
		return fEnemyX;
	}
	float Enemy::GetY()
	{
		return fEnemyY;
	}
	void Enemy::SetSize(float e_width, float e_height)
	{
		this->enemyWidth = e_width;
		this->enemyHeight = e_height;
	}
	float Enemy::GetWidth()
	{
		return enemyWidth;
	}
	float Enemy::GetHeight()
	{
		return enemyHeight;
	}

Enemy::~Enemy()
{
}
