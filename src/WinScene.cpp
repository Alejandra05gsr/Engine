#include "WinScene.h"
#include "raylib.h"
#include "EventBus.hpp"
#include <iostream>

namespace kai
{
	WinScene::WinScene()
	{

	}

	WinScene::~WinScene()
	{

	}


	void WinScene::OnEnter()
	{
		PlayMusicStream(bg_music);
	}

	void WinScene::OnInit()
	{
		textureBG = kai::ResourcesManager::get().getTexture("Oceano3.png");
		buttonSound = kai::ResourcesManager::get().getSound("Button.mp3");
		bg_music = kai::ResourcesManager::get().getMusic("WinMusic.mp3");
		PlayMusicStream(bg_music);
		font = assets.getFont("SpaceFont3.ttf");
	}


	void WinScene::Update()
	{
		UpdateMusicStream(bg_music);
		DrawTextureEx(textureBG, { 0.0f,0.0f }, 0.0f, 1.0, WHITE);

		if (IsKeyPressed(KEY_M))
		{
			PlaySound(buttonSound);
			kai::SceneManager::get().changeScene("menu");
		} 
		else if (IsKeyPressed(KEY_R))
		{
			PlaySound(buttonSound);
			kai::SceneManager::get().changeScene("play");
		}
	}

	void WinScene::Draw()
	{
		DrawTextEx(font, "¡MAR LIMPIO! ", { 110.0f, 200.0f }, 60, 2, GREEN);
		DrawTextEx(font, "Presiona [M] para volver al menu", { 180.0f, 450.0f }, 15, 2, YELLOW);
		DrawTextEx(font, "Presiona [R] para jugar de nuevo", { 180.0f, 500.0f }, 15, 2, YELLOW);
	}

	void WinScene::OnExit()
	{
		StopMusicStream(bg_music);
	}
}