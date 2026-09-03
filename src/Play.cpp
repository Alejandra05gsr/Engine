#include "Play.hpp"
#include "raylib.h"
#include "Entity.h"
#include <iostream>
#include "resources_manager.h"



namespace kai {
	void Play::OnInit()
	{
		LoadTexture("textures/Space.png");

		//listen("grab_coin");
		//listen("enemy_hit");
		//listen("player_hit");

		ship = new Ship();
		enemies = new Enemy[MAX_ENEMIES];
		bullets = new Bullet[MAX_BULLETS];
		score = new Score();

		ship->setPosition(300, 550);
		//ship2->setPosition(320, 550);
		bullets->setPosition(300, 500);


		entityMgr.add(ship);

		for (int i = 0; i < MAX_BULLETS; i++)
		{
			entityMgr.add(&bullets[i]);
		}

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			entityMgr.add(&enemies[i]);
		}

		//entityMgr.add(ship2);

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



		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			TraceLog(LOG_INFO, "Mouse Left Button Pressed");
			EventData data;
			data.type = "onclick";
			EventBus::get().fire("onclick", data); 
			PlaySound(sound);
		}


		//if (IsKeyPressed(KEY_C))
		//{
		//	player.GrabCoin();
		//}
		//if (IsKeyPressed(KEY_E))
		//{
		//	player.EnemyHit();
		//}
		//if (IsKeyPressed(KEY_P))
		//{
		//	player.PlayerHit();
		//}

		//Prueba
		DrawTextureEx(textureBG,{0.0f,0.0f}, 0.0f, 1.0, WHITE);

		if (IsKeyPressed(KEY_SPACE))
		{
			shoot();
		}

		/*if (IsKeyPressed(KEY_E))
		{
			spawnEnemies();
		}*/

		spawnTimer += GetFrameTime();
		if (spawnTimer >= SPAWN_INTERVAL)
		{
			spawnTimer = 0.0f;
			spawnEnemies();
		}


		checkCollitions();
		entityMgr.update();

	}


	void Play::Draw()
	{

		entityMgr.draw();
		//DrawText("Space Game", 100, 100, 40, WHITE);
		DrawTextEx(font, "Space Game", {100, 100}, 40, 0, WHITE);
		score->draw();

	}


	void Play::shoot()
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (!bullets[i].active)
			{
				bullets[i].position = ship->position;
				bullets[i].active = true;
				break;
			}
		}
	}

	void Play::checkCollitions()
	{
		for (int i= 0; i < MAX_BULLETS; i++)
		{
			if (bullets[i].active)
			{
				for (int j = 0; j < MAX_ENEMIES; j++)
				{
					if (enemies[i].active)
					{
						if (bullets[i].colldiesWith(enemies[i]))
						{
							bullets[i].active = false;
							enemies[i].active = false;
							score->addPoints();
							//Se podria poner el score o sonido

						}
					}
				}
			}
		}
	}


	void Play::spawnEnemies()
	{
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			if (!enemies[i].active)
			{
				enemies[i].position = Vector2{(float)GetRandomValue(0,GetScreenWidth()), 20.0f};
				enemies[i].active = true;
				break;
			}
		}
		//TraceLog(LOG_WARNING, "Enemies no funciona");
	}


	void Play::OnExit()
	{
		//stopListening();
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