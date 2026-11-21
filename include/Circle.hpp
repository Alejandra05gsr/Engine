#pragma once
#include "raylib.h"
#include "resources_manager.h"

class Circle
{

private:


public:
	Circle();

	~Circle();
	void DrawCircle();
	void MoveCircle(int screenWidth, int screenHeight);
	void ChangeColor();


	Vector2 position;
	Vector2 vel;
	float rad;
	Color color;

	kai::ResourcesManager& assets = kai::ResourcesManager::get();
	Texture2D textureBubble;


};