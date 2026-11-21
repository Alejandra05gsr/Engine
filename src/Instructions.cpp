#include "Instructions.h"
#include "raylib.h"
#include "EventBus.hpp"
#include <iostream>

namespace kai
{
	Instructions::Instructions()
	{

	}

	Instructions::~Instructions()
	{

	}

	void Instructions::OnInit()
	{
		//Texturas
		textureBG = kai::ResourcesManager::get().getTexture("OceanoInstrucciones.png");
		texturePlayer = kai::ResourcesManager::get().getTexture("Turtle2.png");
		textureEnemy = kai::ResourcesManager::get().getTexture("Basura1.png");
		textureLives = kai::ResourcesManager::get().getTexture("Life.png");
		textureBullet = kai::ResourcesManager::get().getTexture("Bubble2.png");
		texturePowerUp = kai::ResourcesManager::get().getTexture("Star.png");
		textureCoin = kai::ResourcesManager::get().getTexture("Shell.png");

		buttonSound = kai::ResourcesManager::get().getSound("Button.mp3");
		bg_music = kai::ResourcesManager::get().getMusic("InstructionsMusic.mp3");
		PlayMusicStream(bg_music);

		font = assets.getFont("SpaceFont3.ttf");
	}

	void Instructions::OnEnter()
	{
		PlayMusicStream(bg_music);
	}

	void Instructions::Update()
	{
		DrawTextureEx(textureBG, { 0.0f,0.0f }, 0.0f, 1.0, WHITE);
		UpdateMusicStream(bg_music);
		if (IsKeyPressed(KEY_M))
		{
			PlaySound(buttonSound);
			kai::SceneManager::get().changeScene("menu");
		}
	}
	void Instructions::Draw()
	{
		DrawTextEx(font, "INSTRUCCIONES", { 140.0f, 30.0f }, 45, 2, WHITE);


		float startX = 50.0f;   
		float startY = 120.0f;   
		float rowSpacing = 65.0f; 
		float textOffset = 50.0f; 

		// Jugador 
		DrawTextureEx(texturePlayer, { startX, startY }, 0.0f, 1.0f, WHITE);
		DrawTextEx(font, "Usa las flechas o WASD para moverte", { startX + textOffset, startY + 10.0f }, 15, 2, RAYWHITE);

		// Disparo Normal 
		startY += rowSpacing;
		DrawTextureEx(textureBullet, { startX, startY }, 0.0f, 1.0f, WHITE);
		DrawTextEx(font, "Presiona [ESPACIO] para disparar burbujas", { startX + textOffset, startY + 10.0f }, 15, 2, RAYWHITE);

		//Enemigos 
		startY += rowSpacing;
		DrawTextureEx(textureEnemy, { startX, startY }, 0.0f, 1.0f, WHITE);
		DrawTextEx(font, "Limpia el oceano y evita que te toque la basura", { startX + textOffset, startY + 10.0f }, 15, 2, RAYWHITE);

		// PowerUp 
		startY += rowSpacing;
		DrawTextureEx(texturePowerUp, { startX, startY }, 0.0f, 1.0f, WHITE);
		DrawTextEx(font, "Agarra estrellas para disparo triple por 3s", { startX + textOffset, startY + 10.0f }, 15, 2, RAYWHITE);

		// Vidas 
		startY += rowSpacing;
		DrawTextureEx(textureLives, { startX, startY }, 0.0f, 1.0f, WHITE);
		DrawTextEx(font, "Agarra corazones para recuperar vidas", { startX + textOffset, startY + 10.0f }, 15, 2, RAYWHITE);

		// Monedas 
		startY += rowSpacing;
		DrawTextureEx(textureCoin, { startX, startY }, 0.0f, 1.0f, WHITE);
		DrawTextEx(font, "Agarra conchas para ganar puntos extra", { startX + textOffset, startY + 10.0f }, 15, 2, RAYWHITE);

		DrawTextEx(font, "Presiona [M] para volver al menu", { 180.0f, 550.0f }, 15, 2, YELLOW);
	}

	void Instructions::OnExit()
	{
		StopMusicStream(bg_music);
	}
}