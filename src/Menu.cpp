#include "Menu.hpp"
#include "EventBus.hpp"
#include <iostream>

namespace kai {
	Menu::Menu()
	{
		listen("start_game");
	}

	Menu::~Menu()
	{
	}

	void Menu::OnEnter()
	{
	}
	void Menu::OnInit() 
	{
		// Code to execute when initializing the menu scene
		textureBG = kai::ResourcesManager::get().getTexture("FondoMarino.png");
		menuGUI.show(); // Show the menu GUI when the menu scene is initialized
	}

	void Menu::Update()
	{
		DrawTextureEx(textureBG, { 0.0f,0.0f }, 0.0f, 1.0, WHITE);
		circles.MoveCircle(GetScreenWidth(), GetScreenHeight());
		if (IsKeyPressed(KEY_M))
		{
			menuGUI.toggle();
		}
	}

	void Menu::Draw()
	{

		// draw some text using the default font
		DrawText("Clean the Ocean", 100, 50, 50, WHITE);
		//menu_gui.draw();

		// draw our texture to the screen
		//DrawTexture(wabbit, 400, 200, WHITE);

		//UnloadTexture(wabbit);


		menuGUI.draw();

		//GuiMessageBox((Rectangle{ 100, 200, 300, 150 }, "Message", "This is a message box!", "Ok;Cancel", &btnActive));

		circles.DrawCircle();

	}

	void Menu::OnExit()
	{
	}

	void Menu::onEvent(EventData e) {
		if (e.type == "start_game") {
			std::cout << "Start2 Game event received!" << std::endl;
			// Transition to the play scene
		}
	}

}