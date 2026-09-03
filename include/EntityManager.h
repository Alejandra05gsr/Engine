#pragma once
#include "Entity.h"
#include <vector>




namespace kai{
}
class EntityManager
{
public:
	std::vector<Entity*> entities;
	EntityManager() = default;


	void add(Entity* entity)
	{
		if (entity != nullptr)
		{
			entities.push_back(entity);
		}
	}

	void update()
	{
		for (Entity* entity : entities)
		{
			if (entity && entity->active)
			{
				entity->update();
				entity->collider.update(entity->position);

			}
		}
	}

	void draw()
	{
		for (Entity* entity : entities)
		{
			if (entity && entity->active)
			{
				entity->draw();
				if (entity->debugCollider)
				{
					entity->collider.debugDraw();
				}
			}
		}
	}

	void clear()
	{

	}

};