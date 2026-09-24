#include "GameOverScene.h"
#include "GameManager.h"
#include "raylib.h"

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
        textureBG = kai::ResourcesManager::get().getTexture("OceanoSucio.png");
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
        DrawTextureEx(textureBG, { 0.0f,0.0f }, 0.0f, 1.0, WHITE);

        DrawTextEx(font, "GAME OVER", { 110.0f, 200.0f }, 70, 2, WHITE);

        const char* scoreText = TextFormat("Basura recolectada: %i de 20", GameManager::last_final_score);
        DrawTextEx(font, scoreText, { 110.0f, 300.0f }, 25, 2, YELLOW);

        DrawTextEx(font, "Presiona [M] para volver al menu", { 180.0f, 450.0f }, 15, 2, BLACK);
        DrawTextEx(font, "Presiona [R] para jugar de nuevo", { 180.0f, 500.0f }, 15, 2, BLACK);
    }

    void GameOverScene::OnExit()
    {
        StopMusicStream(bg_music);
    }

}

