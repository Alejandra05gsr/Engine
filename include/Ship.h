#pragma once
#include "Entity.h"
#include "resources_manager.h"
#include "SpriteAnimator.h"

namespace kai {
	class Ship : public Entity
	{
	public:
		float speed = 3.0f;
		Sound movementSound;
		SpriteAnimator animator;

		Ship()
		{
			name = "Turtle";
			active = true;
			position = { 400.0f, 300.0f };
			texture = kai::ResourcesManager::get().getTexture("AnimacionTortuga.png");
			movementSound = kai::ResourcesManager::get().getSound("Movement.wav");
			animator.init(texture, 3, 4);
			collider.radius = animator.getFrameWidth() / 2.0f;
		}

		~Ship()
		{

		}


		void update() override
		{
			bool isMoving = false;

			if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
			{
				position.x += speed;
				isMoving = true;
			}
			if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
			{
				position.x -= speed;
				isMoving = true;
			}
			if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
			{
				position.y -= speed;
				isMoving = true;
			}
			if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
			{
				position.y += speed;
				isMoving = true;
			}

			if (isMoving)
			{
				if (!IsSoundPlaying(movementSound))
				{
					PlaySound(movementSound);
				}
				animator.update(); 
			}
			else
			{
				StopSound(movementSound);
			}

			float halfWidth = animator.getFrameWidth() / 2.0f;
			float halfHeight = animator.getFrameHeight() / 2.0f;


			if (position.x - halfWidth < 0.0f)
			{
				position.x = halfWidth;
			}
			if (position.x + halfWidth > (float)GetScreenWidth())
			{
				position.x = (float)GetScreenWidth() - halfWidth;
			}
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
			if (isActive())
			{
				animator.draw(position);
			}

		}

	};
}