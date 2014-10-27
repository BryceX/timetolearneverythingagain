#pragma once
class Player
{
public:

	unsigned int iSpriteID;
	
	
	
	unsigned int iLeftMovementExtreme;
	unsigned int iRightMovementExtreme;
	void SetSize(float a_fWidth, float a_fHeight);
	float fWidth;
	float fHeight;
	float GetWidth();
	float GetHeight();
	void SetPosition(float a_x, float a_y);


	void SetMovementKeys(unsigned int iMoveLeftKey, unsigned int iMoveRightKey);
	unsigned int iMoveLeftKey;
	unsigned int iMoveRightKey;
	void SetMovementExtremes(unsigned int a_leftExtreme, unsigned int a_RightExtreme);
	void Move(float a_fTimeStep, float a_fSpeed);


	void SetSpriteID(unsigned int iSpriteID);
	unsigned int GetSpriteID();

	

	void SetX(float x);
	void SetY(float y);
	float x;
	float y;
	float GetX();
	float GetY();

	Player();
	~Player();
};

