#include "GameOverScene.h"
#include "raylib.h"
#include "EventBus.hpp"
#include <iostream>

namespace kai 
{
	GameOverScene::GameOverScene()
	{
	}

	GameOverScene::~GameOverScene()
	{
	}

    void GameOverScene::OnInit()
    {
        textureBG = kai::ResourcesManager::get().getTexture("Oceano2.png");
        buttonSound = kai::ResourcesManager::get().getSound("Button.mp3");
        bg_music = kai::ResourcesManager::get().getMusic("GameOverMusic.mp3");
        PlayMusicStream(bg_music);
        font = assets.getFont("SpaceFont3.ttf");
    }

    void GameOverScene::OnEnter()
    {
        PlayMusicStream(bg_music);
    }

    void GameOverScene::Update()
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

    void GameOverScene::Draw()
    {
        DrawTextEx(font, "GAME OVER", { 110.0f, 200.0f }, 70, 2, RED);
        DrawTextEx(font, "Presiona [M] para volver al menu", { 180.0f, 450.0f }, 15, 2, YELLOW);
        DrawTextEx(font, "Presiona [R] para jugar de nuevo", { 180.0f, 500.0f }, 15, 2, YELLOW);
    }

    void GameOverScene::OnExit()
    {
        StopMusicStream(bg_music);
    }

}

