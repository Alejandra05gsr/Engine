#pragma once
#include "Entity.h"
#include "resources_manager.h"

using namespace kai;

enum class BulletType {
	NORMAL,
	POWERUP,
};

class Bullet : public Entity
{
public:
	float speed = 3.0f;
	float speedX = 0.0f;
	BulletType type = BulletType::NORMAL;

	Bullet()
	{
		name = "Bullet";
		active = false;
		position = { 300.0f, 400.0f };
		setType(BulletType::NORMAL);
	}


	void setType(BulletType newType, float dirX = 0.0f)
	{
		type = newType;
		speedX = dirX;

		if (type == BulletType::POWERUP)
		{
			texture = kai::ResourcesManager::get().getTexture("Star.png");
		}
		else
		{
			texture = kai::ResourcesManager::get().getTexture("Bubble.png");
		}

		if (texture.id != 0)
		{
			collider.radius = texture.width / 2.0f;
		}
	}


	void update() override
	{
		if (!active) return;

		position.y -= speed;
		position.x += speedX;

		if (position.y <= 0.0f || position.x <= 0.0f || position.x >= GetScreenWidth())
		{
			active = false;
		}
	}


	void draw() override
	{
		if (!active) return;

		Vector2 pos = { position.x - texture.width / 2, position.y - texture.height / 2 };
		DrawTextureEx(texture, pos, 0.0f, 1.0, WHITE);
	}


};
