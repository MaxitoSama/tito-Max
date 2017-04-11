#include "Application.h"
#include "Enemy_1.h"
#include "ModuleCollision.h"

Enemy_1::Enemy_1(int x, int y) : Enemy(x, y)
{
	moveDown.PushBack({ 91,1,13,23 });
	moveDown.PushBack({ 121, 1, 13, 23 });
	moveDown.PushBack({ 91,1,13,23 });
	moveDown.PushBack({ 151, 1, 13, 23 });

	moveDown.speed = 0.2f;

	animation = &moveDown;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_x = x;
}

void Enemy_1::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
		else
			wave += 0.05f;
	}
	else
	{
		if (wave < -1.0f)
			going_up = true;
		else
			wave -= 0.05f;
	}

	position.x = original_x + (25.0f * sinf(wave));
	position.x -= 1;
}
