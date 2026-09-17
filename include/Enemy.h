#pragma once
#include "Entity.h"
#include "raylib.h"
#include "resources_manager.h"

using namespace kai;

class Enemy : public Entity
{
public:

	float speed = 1.5f;
	int radius = 3.0f;

	Enemy()
	{
		active = false;
		texture = ResourcesManager::get().getTexture("Bottle2.png");
		collider.radius = texture.width / 2;
	}

	void update() override
	{
		if (!active) return;
		position.y += speed;

		if (position.y >= GetScreenHeight())
		{
			active = false;
		}

	}

	void draw() override
	{
		if (isActive() && texture.id != 0)
		{
			Vector2 pos = { position.x - texture.width / 2, position.y - texture.height / 2 };
			DrawTextureEx(texture, pos, 0.0f, 1.0, WHITE);
		}
	}

};