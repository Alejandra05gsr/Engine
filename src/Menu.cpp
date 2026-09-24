#include "Menu.hpp"
#include "EventBus.hpp"
#include <iostream>

namespace kai 
{
	Menu::Menu()
	{
		listen("start_game");
	}

	Menu::~Menu()
	{
	}

	void Menu::OnEnter()
	{
		PlayMusicStream(bg_music);
	}

	void Menu::OnInit() 
	{
		textureBG = kai::ResourcesManager::get().getTexture("FondoMarino1.png");
		bg_music = kai::ResourcesManager::get().getMusic("MenuMusic.mp3");
		PlayMusicStream(bg_music);
		font = assets.getFont("SpaceFont3.ttf");
		menuGUI.show(); 
	}

	void Menu::Update()
	{
		UpdateMusicStream(bg_music);

		DrawTextureEx(textureBG, { 0.0f,0.0f }, 0.0f, 1.0, WHITE);

		if (IsKeyPressed(KEY_M))
		{
			menuGUI.toggle();
		}
	}

	void Menu::Draw()
	{
		DrawTextEx(font, "Clean the Ocean", { 80, 60 }, 55, 0, WHITE);
		menuGUI.draw();
	}

	void Menu::OnExit()
	{
		StopMusicStream(bg_music);
	}

	void Menu::onEvent(EventData e) {
		if (e.type == "start_game") {
			std::cout << "Start2 Game event received!" << std::endl;
		}
	}

}