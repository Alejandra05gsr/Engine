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
		//size = { 200, 300 };
		//active = true;

	}
	void MenuGUI::drawGUI()
	{
		/*GuiButton(Rectangle{ 100, 100, 200, 50 }, "Play");
		GuiButton(Rectangle{ 100, 200, 200, 50 }, "Option");
		GuiButton(Rectangle{ 100, 300, 200, 50 }, "Exit");
		GuiButton(Rectangle{ 100, 400, 200, 50 }, "Credits");*/


		if (isActive)
		{

			if (GuiButton(Rectangle{ 100, 100, 200, 50 }, "Play"))
			{
				//Handle Play button active 
				SceneManager::get().changeScene("play");
				EventBus::get().fire("start_game");
			}

			if (GuiButton(Rectangle{ 100, 200, 200, 50 }, "Option"))
			{
				//Options
				SceneManager::get().changeScene("options");
			}
			if (GuiButton(Rectangle{ 100, 300, 200, 50 }, "Exit"))
			{
				//Exit
				SceneManager::get().changeScene("exit");
			}
			if (GuiButton(Rectangle{ 100, 400, 200, 50 }, "Credits"))
			{
				//Credits
				SceneManager::get().changeScene("credits");
			}

			/*Rectangle startButtonRect = { 100, 100, 200, 50 };
			if (GuiButton(startButtonRect, "Start Game"))
			{
				SceneManager::get().changeScene("play");
				EventBus::get().fire("start_game");
			}*/
			//GuiButton((Rectangle) { 100, 200, 200, 50 }, "Options");
			//GuiButton((Rectangle) { 100, 300, 200, 50 }, "Exit");

		}
	}

	PlayGUI::PlayGUI()
	{
	}

	void PlayGUI::drawGUI()
	{
	}
}
