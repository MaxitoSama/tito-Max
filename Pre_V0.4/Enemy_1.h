#ifndef __ENEMY_1_H__
#define __ENEMY_1_H__

#include "Enemy.h"

class Enemy_1 : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_x = 0;
	Animation moveDown;

public:

	Enemy_1(int x, int y);

	void Move();
};

#endif // __ENEMY_1_H__