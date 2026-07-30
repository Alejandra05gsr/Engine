#include "Menu.hpp"
#include "raylib.h"

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
	}

	void Menu::Draw()
	{

		// draw some text using the default font
		DrawText("Hello Raylib", 200, 200, 20, WHITE);

		// draw our texture to the screen
		//DrawTexture(wabbit, 400, 200, WHITE);

		//UnloadTexture(wabbit);

		circles.DrawCircle();

	}

	void Menu::OnExit()
	{
	}

}