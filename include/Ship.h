#pragma once
#include "Entity.h"
#include "resources_manager.h"
namespace kai {
	class Ship : public Entity
	{
	public:
		float speed = 10.0f;
		Sound movementSound;

		Ship()
		{
			name = "Turtle";
			active = true;
			position = { 400.0f, 300.0f };
			texture = kai::ResourcesManager::get().getTexture("Turtle.png");
			movementSound = kai::ResourcesManager::get().getSound("Movement.wav");
			collider.radius = texture.width / 2.0f;
		}

		~Ship()
		{

		}


		void update() override
		{

			if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
			{
				position.x += speed;
				PlaySound(movementSound);
			}
			if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
			{
				position.x -= speed;
				PlaySound(movementSound);
			}
			if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
			{
				position.y -= speed;
				PlaySound(movementSound);
			}
			if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
			{
				position.y += speed;
				PlaySound(movementSound);
			}

			// 2. Límites de la pantalla (Clamp)
			float halfWidth = texture.width / 2.0f;
			float halfHeight = texture.height / 2.0f;

			// Límite Izquierda y Derecha
			if (position.x - halfWidth < 0.0f)
			{
				position.x = halfWidth;
			}
			if (position.x + halfWidth > (float)GetScreenWidth())
			{
				position.x = (float)GetScreenWidth() - halfWidth;
			}

			// Límite Arriba y Abajo
			if (position.y - halfHeight < 0.0f)
			{
				position.y = halfHeight;
			}
			if (position.y + halfHeight > (float)GetScreenHeight())
			{
				position.y = (float)GetScreenHeight() - halfHeight;
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
}