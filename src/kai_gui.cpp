#include "kai_gui.hpp"
#include "raylib.h"
#include "raygui.h"

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
		GuiButton(Rectangle{ 100, 100, 200, 50 }, "Play");
		GuiButton(Rectangle{ 100, 200, 200, 50 }, "Option");
		GuiButton(Rectangle{ 100, 300, 200, 50 }, "Exit");
		GuiButton(Rectangle{ 100, 400, 200, 50 }, "Credits");


		//if (isActive)
		//{

		//	if (GuiButton(Rectangle{ 100, 100, 200, 50 }, "Play"))
		//	{
		//		//Handle Play button active 
		//	}

		//	if (GuiButton(Rectangle{ 100, 200, 200, 50 }, "Option"))
		//	{
		//		//Options
		//	}
		//	if (GuiButton(Rectangle{ 100, 300, 200, 50 }, "Exit"))
		//	{
		//		//Exit
		//	}
		//	if (GuiButton(Rectangle{ 100, 400, 200, 50 }, "Credits"))
		//	{
		//		//Credits
		//	}


		//}
	}

	PlayGUI::PlayGUI()
	{
	}

	void PlayGUI::drawGUI()
	{
	}
}
