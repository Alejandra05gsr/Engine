#pragma once
#include "Entity.h"
#include "resources_manager.h"

using namespace kai;

class PowerUp : public Entity
{
public:
	float speed = 2.0f;

	PowerUp()
	{
		name = "PowerUp";
		active = false;
		position = { 400.0f, 500.0f };
		texture = kai::ResourcesManager::get().getTexture("PowerUp.png");
		collider.radius = texture.width / 2.0f;
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
		if (isActive() || texture.id != 0)
		{
			Vector2 pos = { position.x - texture.width / 2, position.y - texture.height / 2 };
			DrawTextureEx(texture, pos, 0.0f, 1.0, WHITE);
		}

	}


};