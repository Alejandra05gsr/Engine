#include "Scene.hpp"
#include "EventBus.hpp"
#include "Ship.h"
#include "EntityManager.h"
#include "Bullet.h"
#include "resources_manager.h"
#include "Enemy.h"
#include "Score.h"
#include "lives.h"
#include "Coins.h"
#include "PowerUps.h"
#include "GameManager.h"
#include "HUDCanvas.hpp"

#define MAX_BULLETS 30
#define MAX_ENEMIES 50
#define MAX_POWERUPS 5
#define MAX_LIVES 3
#define MAX_COINS 7

namespace kai {
	class Play : public Scene, EventListener {
	private:
		GameManager gameManager;
		HUDCanvas hudCanvas;

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
		void spawnCoins(Vector2 position);


		EntityManager entityMgr;
		Ship* ship = nullptr;
		Bullet* bullets = nullptr;
		Enemy* enemies = nullptr;
		Score* score = nullptr;
		Lives* lives = nullptr;
		PowerUp* powerups = nullptr;
		Coins* coins = nullptr;
	

		float spawnTimer = 0.0f;
		const float SPAWN_INTERVAL = 1.0f;


		bool isPowerUpActive = false;      
		float powerUpTimer = 0.0f;         
		const float POWER_UP_DURATION = 3.0f;
		
		//Resources
		Font font;

		Sound damageSound;
		Sound powerUpSound;
		Sound lifeSound;
		Sound coinsSound;
		Sound enemySound;

		Sound normalShootSound;
		Sound powerUpShootSound;

		Music bg_music;
		kai::ResourcesManager& assets = kai::ResourcesManager::get();


		Texture2D textureBG;
		Texture2D lifeTexture;

	};
} 
