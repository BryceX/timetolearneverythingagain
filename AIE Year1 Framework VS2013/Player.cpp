#include "Player.h"
#include "AIE.h"

Player::Player()
{
}
void Player::SetSpriteID(unsigned int iSpriteID)
{
	this->iSpriteID = iSpriteID;
}
unsigned int Player::GetSpriteID()
{
	return iSpriteID;
}

void Player::SetSize(float a_fWidth, float a_fHeight)
{
	this->fWidth = a_fWidth;
	this->fHeight = a_fHeight;
}
float Player::GetWidth()
{
	return fWidth;
}
float Player::GetHeight()
{
	return fHeight;
}
void Player::SetPosition(float a_x, float a_y)
{
	this->x = a_x;
	this->y = a_y;
}
float Player::GetX()
{
	return x;
}
float Player::GetY()
{
	return y;
}


void Player::SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight)
{
	this->iMoveLeftKey = a_moveLeft;
	this->iMoveRightKey = a_moveRight;
}


void Player::SetMovementExtremes(unsigned int a_leftExtreme, unsigned int a_RightExtreme)
{
	iLeftMovementExtreme = a_leftExtreme;
	iRightMovementExtreme = a_RightExtreme;
}

void Player::Move(float a_fTimeStep, float a_fSpeed)
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
}

Player::~Player()
{
}
