#pragma once
#pragma once
#include "Canvas.hpp"
#include "resources_manager.h"
#include "GameManager.h"

namespace kai {
	class HUDCanvas : public Canvas
	{
	private:
		Font font;
		Texture2D lifeTexture;
		GameManager* gameManager = nullptr;

	public:
		HUDCanvas() = default;

		void init(GameManager* gm)
		{
			gameManager = gm;
			font = kai::ResourcesManager::get().getFont("SpaceFont3.ttf");
			lifeTexture = kai::ResourcesManager::get().getTexture("Life.png");
			show(); 
		}

		void drawGUI() override
		{
			//Objetivo
			DrawTextEx(font, "Clean the garbage", { 50, 50 }, 30, 0, WHITE);

			//Vidas
			if (gameManager != nullptr)
			{
				int currentLives = gameManager->getLives();
				float spacing = 10.0f;
				float iconWidth = (float)lifeTexture.width;
				float iconHeight = (float)lifeTexture.height;

				float startX = (float)GetScreenWidth() - 20.0f - iconWidth;
				float startY = (float)GetScreenHeight() - 20.0f - iconHeight;

				for (int i = 0; i < currentLives; i++)
				{
					Vector2 pos = { startX - (i * (iconWidth + spacing)), startY };
					DrawTextureEx(lifeTexture, pos, 0.0f, 1.0f, WHITE);
				}
			}
		}
	};
}