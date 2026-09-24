#pragma once
#include "Entity.h"
#include "raylib.h"
#include "resources_manager.h"


namespace kai
{
	class Enemy : public Entity
	{
	public:
		float speed = 0.7f;

		Enemy()
		{
			active = false;
			texture = ResourcesManager::get().getTexture("Basura1.png");
			collider.radius = texture.width / 2.0f;
		}


		void spawn(Vector2 pos)
		{
			position = pos;
			active = true;

			int randomType = GetRandomValue(1, 3);

			if (randomType == 1)
			{
				texture = ResourcesManager::get().getTexture("Basura1.png");
			}
			else if (randomType == 2)
			{
				texture = ResourcesManager::get().getTexture("Basura2.png");
			}
			else
			{
				texture = ResourcesManager::get().getTexture("Basura3.png");
			}

			collider.radius = texture.width / 2.0f;
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
			if (active && texture.id != 0)
			{
				Vector2 pos = { position.x - texture.width / 2, position.y - texture.height / 2 };
				DrawTextureEx(texture, pos, 0.0f, 1.0, WHITE);
			}
		}

	};
}