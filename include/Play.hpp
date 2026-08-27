#ifndef PLAY_HPP
#define PLAY_HPP
#include "Scene.hpp"
#include "EventBus.hpp"
#include "player.hpp"
#include "Ship.h"
#include "EntityManager.h"
#include "Bullet.h"
#include "resources_manager.h"

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

		Player player;
		Ship* ship;
		Ship* ship2;
		Bullet* bullet;


		EntityManager entityMgr;

		int eventId_01;
		int eventId_02;
		int playerScore;
		int grabCoinEvId;
		
		
		Font font;
		Sound sound;
		Music bg_music;
		kai::ResourcesManager& assets = kai::ResourcesManager::get();


		//Prueba
		Texture2D textureBG;

	};
}
#endif // !PLAY_HPP