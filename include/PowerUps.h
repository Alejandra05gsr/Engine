#pragma once
#include "Entity.h"

using namespace kai;

class PowerUp : public Entity
{
public:
	float speed = 5.0f;
	float radius = 10.0f;

	PowerUp()
	{
		active = false;
		collider.radius = radius;
	}

	void update() override
	{
		position.y -= speed;
		if (position.y >= 600.0f) 
		{
			active = false;
		}
	}

	void draw() override
	{
		DrawCircleV(position, radius, YELLOW);
	}


};