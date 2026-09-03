#pragma once
#include "Entity.h"

using namespace kai;

class Bullet : public Entity
{
public:
	float speed = 20.0f;
	float radius = 3.0f;
	Bullet()
	{
		active = false;
		collider.radius = radius;
	}


	void update() override
	{
		//if (!isActive) return;

		position.y -= speed;

		if (position.y <= 0.0f)
		{
			active = false;
		}

	}


	void draw() override
	{
		DrawCircleV(position, 2.0f, WHITE);
	}


};
