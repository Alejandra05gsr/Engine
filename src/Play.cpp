#include "Play.hpp"
#include "raylib.h"
#include "Entity.h"
#include "resources_manager.h"


namespace kai {
	void Play::OnInit()
	{
		LoadTexture("textures/Space.png");

		listen("grab_coin");
		listen("enemy_hit");
		listen("player_hit");

		ship = new Ship();
		ship2 = new Ship();
		bullet = new Bullet();

		ship->setPosition(300, 550);
		ship2->setPosition(320, 550);
		bullet->setPosition(300, 500);


		entityMgr.add(bullet);
		entityMgr.add(ship);
		entityMgr.add(ship2);

		//font = kai::ResourcesManager::get().getFont("SpaceFont3.ttf");

		font = assets.getFont("SpaceFont3.ttf");

		sound = kai::ResourcesManager::get().getSound("Pew.wav");
		bg_music = kai::ResourcesManager::get().getMusic("SpaceMusic.mp3");
		PlayMusicStream(bg_music);


		//Prueba
		textureBG = kai::ResourcesManager::get().getTexture("SpaceBG.png");


	}


	void Play::OnEnter()
	{

	}


	void Play::Update()
	{

		UpdateMusicStream(bg_music);

		entityMgr.update();

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			TraceLog(LOG_INFO, "Mouse Left Button Pressed");
			EventData data;
			data.type = "onclick";
			EventBus::get().fire("onclick", data); 
			PlaySound(sound);
		}


		if (IsKeyPressed(KEY_C))
		{
			player.GrabCoin();
		}
		if (IsKeyPressed(KEY_E))
		{
			player.EnemyHit();
		}
		if (IsKeyPressed(KEY_P))
		{
			player.PlayerHit();
		}

		//Prueba
		DrawTextureEx(textureBG,{0.0f,0.0f}, 0.0f, 1.0, WHITE);


	}


	void Play::Draw()
	{

		entityMgr.draw();
		//DrawText("Space Game", 100, 100, 40, WHITE);
		DrawTextEx(font, "Space Game", {100, 100}, 40, 0, WHITE);

	}


	void Play::OnExit()
	{

	}


	void Play::onEvent(EventData data)
	{
		if (data.type == "grab_coin")
		{
			TraceLog(LOG_INFO, "Se agarro una moneda");
		}
		else if (data.type == "enemy_hit")
		{
			TraceLog(LOG_INFO, "Enemigo golpeado");
		}
		else if (data.type == "player_hit")
		{
			TraceLog(LOG_INFO, "El jugador fue golpeado");
		}
	}
}