#ifndef PLAY_HPP
#define PLAY_HPP
#include "Scene.hpp"
#include "EventBus.hpp"
#include "player.hpp"
#include "Ship.h"
#include "EntityManager.h"
#include "Bullet.h"
#include "resources_manager.h"
#include "Enemy.h"
#include "Score.h"
#include "lives.h"
#include "PowerUps.h"

#define MAX_BULLETS 30
#define MAX_ENEMIES 20
#define MAX_POWERUPS 5
#define MAX_LIVES 3


namespace kai {
	class Play : public Scene, EventListener {
	private:

	public:
		Play() = default;
		~Play() = default;

		void OnInit() override;
		void OnEnter() override;
		void Update() override;
		void Draw() override;
		void OnExit() override;
		void onEvent(EventData data) override; 
		void shoot();
		void spawnEnemies();
		void checkCollitions();
		void spawnPowerUp(Vector2 position);
		void spawnLives(Vector2 position);


		EntityManager entityMgr;
		Ship* ship;
		Bullet* bullets;
		Enemy* enemies;
		Score* score;
		Lives* lives;
		PowerUp* powerups;
	

		float spawnTimer = 0.0f;
		const float SPAWN_INTERVAL = 2.0f;



		//int eventId_01;
		//int eventId_02;
		//int playerScore;
		//int grabCoinEvId;
		
		
		//Resources
		Font font;
		Sound sound;
		Music bg_music;
		kai::ResourcesManager& assets = kai::ResourcesManager::get();


		//Prueba
		Texture2D textureBG;

	};
}
#endif // !PLAY_HPP