#include "Play.hpp"
#include "raylib.h"
#include "Entity.h"
#include <iostream>
#include "resources_manager.h"
#include <fstream>

#include "json.hpp"

using json = nlohmann::json;



namespace kai {
	void Play::OnInit()
	{

		//listen("grab_coin");
		//listen("enemy_hit");
		//listen("player_hit");

		ship = new Ship();
		enemies = new Enemy[MAX_ENEMIES];
		bullets = new Bullet[MAX_BULLETS];
		powerups = new PowerUp[MAX_POWERUPS];
		lives = new Lives[MAX_LIVES];
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

		lives = new Lives[MAX_LIVES];
		for (int i = 0; i < MAX_LIVES; i++)
		{
			entityMgr.add(&lives[i]);
		}

		//entityMgr.add(ship2);

		//font = kai::ResourcesManager::get().getFont("SpaceFont3.ttf");

		font = assets.getFont("SpaceFont3.ttf");

		sound = kai::ResourcesManager::get().getSound("Pew.wav");
		bg_music = kai::ResourcesManager::get().getMusic("SpaceMusic.mp3");
		PlayMusicStream(bg_music);


		//Prueba
		textureBG = kai::ResourcesManager::get().getTexture("Oceano.png");

		//gameManager.Init();
		std::ifstream file("resources/json/test.json");
		if (file.is_open())
		{
			TraceLog(LOG_INFO, "Se cargo el archivo json");
		}


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

		if (IsKeyPressed(KEY_E))
		{
			spawnPowerUp({300.0f,300.0f });
			//spawnLives({400.0f,300.0f });
		}

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
		DrawTextEx(font, "Clean the Ocean", {100, 100}, 40, 0, WHITE);
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
					if (enemies[j].active)
					{
						if (bullets[i].colldiesWith(enemies[i]))
						{
							bullets[i].active = false;
							enemies[j].active = false;
							//if (GetRandomValue(1, 100) <= 30)
							//{
							//	spawnPowerUp(enemies[j].position);
							//}

							//if (GetRandomValue(1, 100) <= 30)
							//{
							//	spawnLives(enemies[j].position);
							//	(enemies[j].position);
							//}

							score->addPoints();
							EventBus::get().fire("enemy_kill");
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
				if (enemies[i].colldiesWith(*ship))
				{
					//ship->setPosition(shipOrigin);

				}
				enemies[i].position = Vector2{(float)GetRandomValue(0,GetScreenWidth()), 20.0f};
				enemies[i].active = true;
				break;
			}
		}
		//TraceLog(LOG_WARNING, "Enemies no funciona");
	}

	void Play::spawnPowerUp(Vector2 position)
	{
		for (int i = 0; i < MAX_POWERUPS; i++)
		{
			if (!powerups[i].active)
			{
				powerups[i].position = position;
				powerups[i].active = true;
				break; // Activa solo uno y sale del bucle
			}
		}
	}

	void Play::spawnLives(Vector2 position)
	{
		for (int i = 0; i < MAX_LIVES; i++)
		{
			if (!lives[i].active)
			{
				lives[i].position = position;
				lives[i].active = true;
				break; // Activa solo uno y sale del bucle
			}
		}
	}

	void Play::OnExit()
	{
		//stopListening();
		//gamemanager
		entityMgr.clear();
		delete ship;
		ship = nullptr;


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