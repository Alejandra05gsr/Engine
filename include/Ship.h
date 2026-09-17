#pragma once
#include "Entity.h"
#include "Bullet.h"
#include "resources_manager.h"

class Ship : public Entity
{
public:
	float speed = 10.0f;
	//Bullet bullet[100];

	Ship()
	{
		name = "Ship";
		active = true;
		position = { 400.0f, 300.0f };
		//texture = LoadTexture("textures/Ship.png");
		texture = kai::ResourcesManager::get().getTexture("Turtle.png");
		collider.radius = texture.width / 2.0f;
	}

	~Ship()
	{

	}


	void update() override
	{

		if (IsKeyDown(KEY_RIGHT))
		{
			position.x += speed;
		}
		if (IsKeyDown(KEY_LEFT))
		{
			position.x -= speed;
		}
		if (IsKeyDown(KEY_UP))
		{
			position.y -= speed;
		}
		if (IsKeyDown(KEY_DOWN))
		{
			position.y += speed;
		}
	}


	void draw() override
	{
		if (isActive() || texture.id != 0)
		{
			Vector2 pos = { position.x - texture.width / 2, position.y - texture.height / 2 };
			DrawTextureEx(texture, pos,0.0f, 1.0, WHITE );
		}

	}

};
