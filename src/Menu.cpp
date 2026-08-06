#include "Menu.hpp"


namespace kai {
	//Menu::Menu()
	//{
	//}

	//Menu::~Menu()
	//{
	//}

	void Menu::OnEnter()
	{
	}

	void Menu::Update()
	{
		circles.MoveCircle(GetScreenWidth(), GetScreenHeight());
		if (IsKeyPressed(KEY_M))
		{
			menuGUI.toggle();
		}
	}

	void Menu::Draw()
	{

		// draw some text using the default font
		DrawText("Hello Raylib", 200, 200, 20, WHITE);

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

}