#pragma once
#include "Entity.h"

using namespace kai;

class Lives : public Entity
{
public:
	float speed = 2.0f;
	float radius = 10.0f;

	Lives()
	{
		active = false;
		collider.radius = radius;
	}

	void update() override
	{
		position.y += speed;
		if (position.y >= 600.0f) 
		{
			active = false;
		}
	}

	void draw() override
	{
		DrawCircleV(position, radius, RED);
	}





};