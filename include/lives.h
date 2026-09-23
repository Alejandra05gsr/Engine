#pragma once
#include "Entity.h"

using namespace kai;

class Lives : public Entity
{
public:
	float speed = 2.0f;
	//float radius = 10.0f;

	Lives()
	{
		name = "Lives";
		active = false;
		position = { 300.0f, 400.0f };
		texture = kai::ResourcesManager::get().getTexture("Life.png");
		collider.radius = texture.width / 2.0f;
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
		Vector2 pos = { position.x - texture.width / 2, position.y - texture.height / 2 };
		DrawTextureEx(texture, pos, 0.0f, 1.0, WHITE);
		//DrawCircleV(position, radius, RED);
	}





};