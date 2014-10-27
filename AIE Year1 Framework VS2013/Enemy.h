#pragma once
class Enemy
{
public:
	
	unsigned int enemySpriteID;
	bool Moveleft = true;
	bool Moveright = false;
	int eLeft;
	int eRight;
	int eDown;
	
	void SetSize(float e_width, float e_height);
	float GetWidth();
	float GetHeight();
	float enemyWidth;
	float enemyHeight;
	void Movement(float iScreenWidth, float iScreenHeight);
	void SetPosition(float e_x, float e_y);
	float fEnemyX;
	float fEnemyY;
	float GetX();
	float GetY();

	Enemy();
	~Enemy();

private:

};

