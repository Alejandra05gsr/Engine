#include "WinScene.h"
#include "GameManager.h"
#include "raylib.h"


namespace kai
{
	WinScene::WinScene()
	{

	}

	WinScene::~WinScene()
	{

	}


	void WinScene::OnInit()
	{
		textureBG = kai::ResourcesManager::get().getTexture("OceanoLimpio.png");
		buttonSound = kai::ResourcesManager::get().getSound("Button.mp3");
		bg_music = kai::ResourcesManager::get().getMusic("WinMusic.mp3");
		PlayMusicStream(bg_music);
		font = assets.getFont("SpaceFont3.ttf");
	}

	void WinScene::OnEnter()
	{
		PlayMusicStream(bg_music);
	}


	void WinScene::Update()
	{
		UpdateMusicStream(bg_music);

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
		DrawTextureEx(textureBG, { 0.0f,0.0f }, 0.0f, 1.0, WHITE);

		DrawTextEx(font, "¡MAR LIMPIO! ", { 110.0f, 200.0f }, 60, 2, DARKBLUE);

		const char* winText = TextFormat("Limpiaste %i basuras del oceano", GameManager::last_final_score);
		DrawTextEx(font, winText, { 120.0f, 280.0f }, 20, 2, GREEN);

		DrawTextEx(font, "Presiona [M] para volver al menu", { 180.0f, 450.0f }, 15, 2, BLACK);
		DrawTextEx(font, "Presiona [R] para jugar de nuevo", { 180.0f, 500.0f }, 15, 2, BLACK);
	}

	void WinScene::OnExit()
	{
		StopMusicStream(bg_music);
	}
}