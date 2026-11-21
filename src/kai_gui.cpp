#include "kai_gui.hpp"
#include "raylib.h"
#include "raygui.h"
#include "EventBus.hpp"
#include "scene_manager.hpp"

namespace kai
{
	MenuGUI::MenuGUI()
	{
		position = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
		buttonSound = kai::ResourcesManager::get().getSound("Button.mp3");
		//size = { 200, 300 };
		//active = true;

	}
	void MenuGUI::drawGUI()
	{
		if (isActive)
		{

			if (GuiButton(Rectangle{ 300, 200, 200, 50 }, "Play"))
			{
				PlaySound(buttonSound);
				SceneManager::get().changeScene("play");
				EventBus::get().fire("start_game");
			}

			if (GuiButton(Rectangle{ 300, 300, 200, 50 }, "Instructions"))
			{
				PlaySound(buttonSound);
				SceneManager::get().changeScene("instructions");
			}
			if (GuiButton(Rectangle{ 300, 400, 200, 50 }, "Exit"))
			{
				PlaySound(buttonSound);
				CloseWindow();
			}
		}
	}

	PlayGUI::PlayGUI()
	{
	}

	void PlayGUI::drawGUI()
	{
	}
}
