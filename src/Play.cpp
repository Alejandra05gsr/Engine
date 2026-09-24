#include "Play.hpp"
#include "raylib.h"
#include "Entity.h"
#include "resources_manager.h"



namespace kai {
	void Play::OnInit()
	{
		gameManager.init();

		ship = new Ship();
		enemies = new Enemy[MAX_ENEMIES];
		bullets = new Bullet[MAX_BULLETS];
		powerups = new PowerUp[MAX_POWERUPS];
		lives = new Lives[MAX_LIVES];
		coins = new Coins[MAX_COINS];
		score = new Score();

		hudCanvas.init(&gameManager);

		ship->setPosition(300, 550);
		bullets->setPosition(300, 500);

		entityMgr.clear();

		entityMgr.add(ship);

		for (int i = 0; i < MAX_BULLETS; i++)
		{
			entityMgr.add(&bullets[i]);
		}

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			entityMgr.add(&enemies[i]);
		}

		for (int i = 0; i < MAX_LIVES; i++)
		{
			entityMgr.add(&lives[i]);
		}

		for (int i = 0; i < MAX_POWERUPS; i++)
		{
			entityMgr.add(&powerups[i]); 
		}

		for (int i = 0; i < MAX_COINS; i++)
		{
			entityMgr.add(&coins[i]);
		}



		//Resources
		font = assets.getFont("SpaceFont3.ttf");

		damageSound = kai::ResourcesManager::get().getSound("Damage.wav");
		powerUpSound = kai::ResourcesManager::get().getSound("PowerUp.wav");
		lifeSound = kai::ResourcesManager::get().getSound("Life.wav");
		coinsSound = kai::ResourcesManager::get().getSound("Coin.wav");
		enemySound = kai::ResourcesManager::get().getSound("DestroyGarbage.wav");

		normalShootSound = kai::ResourcesManager::get().getSound("NormalShoot.wav");
		powerUpShootSound = kai::ResourcesManager::get().getSound("PowerUpShoot.wav");

		bg_music = kai::ResourcesManager::get().getMusic("GameMusic.mp3");
		PlayMusicStream(bg_music);

		textureBG = kai::ResourcesManager::get().getTexture("Oceano.png");
		lifeTexture = kai::ResourcesManager::get().getTexture("Life.png");



		isPowerUpActive = false;
		powerUpTimer = 0.0f;

	}


	void Play::OnEnter()
	{

		PlayMusicStream(bg_music);

		gameManager.reset();
		isPowerUpActive = false;
		powerUpTimer = 0.0f;
		spawnTimer = 0.0f;

		if (ship != nullptr) {
			ship->setPosition(300, 550);
		}

		for (int i = 0; i < MAX_BULLETS; i++) bullets[i].active = false;
		for (int i = 0; i < MAX_ENEMIES; i++) enemies[i].active = false;
		for (int i = 0; i < MAX_POWERUPS; i++) powerups[i].active = false;
		for (int i = 0; i < MAX_LIVES; i++) lives[i].active = false;
		for (int i = 0; i < MAX_COINS; i++) coins[i].active = false;
	}


	void Play::Update()
	{
		UpdateMusicStream(bg_music);



		//PowerUp 
		if (isPowerUpActive)
		{
			powerUpTimer -= GetFrameTime();
			if (powerUpTimer <= 0.0f)
			{
				isPowerUpActive = false; 
			}
		}

		//Disparo
		if (IsKeyPressed(KEY_SPACE))
		{
			shoot();
		}


		//Spawn de enemigos
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
		DrawTextureEx(textureBG, { 0.0f,0.0f }, 0.0f, 1.0, WHITE);
		entityMgr.draw();
		score->draw();

		hudCanvas.draw();
	}


	void Play::shoot()
	{
		if (isPowerUpActive)
		{
			float dirX[3] = { -2.0f, 0.0f, 2.0f };
			int spawned = 0;

			for (int i = 0; i < MAX_BULLETS && spawned < 3; i++)
			{
				if (!bullets[i].active)
				{
					bullets[i].position = ship->position;
					bullets[i].setType(BulletType::POWERUP, dirX[spawned]);
					bullets[i].active = true;
					PlaySound(powerUpShootSound);
					spawned++;
				}
			}
		}
		else
		{
			for (int i = 0; i < MAX_BULLETS; i++)
			{
				if (!bullets[i].active)
				{
					bullets[i].position = ship->position;
					bullets[i].setType(BulletType::NORMAL, 0.0f);
					bullets[i].active = true;
					PlaySound(normalShootSound);
					break;
				}
			}
		}
	}


	void Play::checkCollitions()
	{
		//Balas y enemigos
		for (int i= 0; i < MAX_BULLETS; i++)
		{
			if (bullets[i].active)
			{
				for (int j = 0; j < MAX_ENEMIES; j++)
				{
					if (enemies[j].active)
					{
						if (bullets[i].colldiesWith(enemies[j]))
						{
							bullets[i].active = false;
							enemies[j].active = false;

							int randomValue = GetRandomValue(1, 100);

							if (randomValue <= 20)
							{
								spawnPowerUp(enemies[j].position);
							} 
							else if (randomValue <= 40 && randomValue > 20)
							{
								spawnLives(enemies[j].position);
							} 
							else if (randomValue <= 70 && randomValue > 40)
							{
								spawnCoins(enemies[j].position);
							}

							score->addPoints();
							PlaySound(enemySound);

							EventData data;
							data.type = "enemy_kill";
							EventBus::get().fire("enemy_kill");
							break;

						}
					}
				}
			}
		}

		//Jugador y enemigos
		for (int j = 0; j < MAX_ENEMIES; j++)
		{
			if (enemies[j].active)
			{
				if (enemies[j].colldiesWith(*ship))
				{
					enemies[j].active = false; 

					PlaySound(damageSound);

					EventData data;
					data.type = "player_kill";
					EventBus::get().fire("player_kill", data);
				}
			}
		}

		//Jugador y vidas
		for (int i = 0; i < MAX_LIVES; i++)
		{
			if (lives[i].active)
			{
				if (lives[i].colldiesWith(*ship))
				{
					lives[i].active = false;

					PlaySound(lifeSound);

					EventData data;
					data.type = "gain_life";
					EventBus::get().fire("gain_life", data);
				}
			}
		}

		//Jugador y PowerUps
		for (int i = 0; i < MAX_POWERUPS; i++)
		{
			if (powerups[i].active)
			{
				if (powerups[i].colldiesWith(*ship))
				{
					powerups[i].active = false; 

					isPowerUpActive = true;
					powerUpTimer = POWER_UP_DURATION;

					PlaySound(powerUpSound);
				}
			}
		}

		//Jugador y monedas
		for (int i = 0; i < MAX_COINS; i++)
		{
			if (coins[i].active)
			{
				if (coins[i].colldiesWith(*ship))
				{
					coins[i].active = false; 
					score->addPoints();
					PlaySound(coinsSound);
				}
			}
		}

	}



	//Spawners

	void Play::spawnEnemies()
	{
		for (int i = 0; i < MAX_ENEMIES; i++)

		{
			if (!enemies[i].active)
			{
				Vector2 spawnPos = { (float)GetRandomValue(0, GetScreenWidth()), 20.0f };

				enemies[i].spawn(spawnPos);
				break;
			}
		}
	}

	void Play::spawnPowerUp(Vector2 position)
	{
		for (int i = 0; i < MAX_POWERUPS; i++)
		{
			if (!powerups[i].active)
			{
				powerups[i].position = position;
				powerups[i].active = true;
				break; 
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
				break; 
			}
		}
	}

	void Play::spawnCoins(Vector2 position)
	{
		for (int i = 0; i < MAX_COINS; i++)
		{
			if (!coins[i].active)
			{
				coins[i].position = position;
				coins[i].active = true;
				break; 
			}
		}
	}




	void Play::OnExit()
	{
		//stopListening();
		gameManager.exit();
		entityMgr.clear();
		delete ship;
		ship = nullptr;

		delete[] enemies;
		enemies = nullptr;

		delete[] bullets;
		bullets = nullptr;

		delete[] powerups;
		powerups = nullptr;

		delete[] lives;
		lives = nullptr;

		delete score;
		score = nullptr;

		delete[] coins;
		coins = nullptr;

		StopMusicStream(bg_music);

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