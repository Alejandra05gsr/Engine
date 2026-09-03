#pragma once
#include "raylib.h"
#include "resources_manager.h"
#include <iostream>


class Score
{
public:
	int scorePoints = 0.0f;
	Vector2 position = { 10.0f, 20.0f };
	Font scoreFont;
	kai::ResourcesManager& assets = kai::ResourcesManager::get();

	Score()
	{
		scoreFont = assets.getFont("SpaceFont3.ttf");
	}

	void addPoints()
	{
		scorePoints++;
	}

	void draw()
	{
		std::string scoreTxt = "Puntos: " + std::to_string(scorePoints);
		//TraceLog(LOG_INFO, scoreTxt());
		DrawTextEx(scoreFont, scoreTxt.c_str(), {50, 550}, 16, 0, WHITE);

	}


};