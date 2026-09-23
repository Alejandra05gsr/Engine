#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP
#include "scene_manager.hpp"
#include "EventBus.hpp"
#include "resources_manager.h"

namespace kai
{
	class Instructions : public Scene
	{
	public:
		Instructions();
		~Instructions();

		// Heredado vía Scene
		void OnInit() override;
		void OnEnter() override;
		void Update() override;
		void Draw() override;
		void OnExit() override;


		Font font;
		Sound buttonSound;
		Music bg_music;
		kai::ResourcesManager& assets = kai::ResourcesManager::get();

		Texture2D textureBG;
		Texture2D texturePlayer;
		Texture2D textureBullet;
		Texture2D textureEnemy;
		Texture2D texturePowerUp;
		Texture2D textureLives;
		Texture2D textureCoin;

	};
} 
#endif // !INSTRUCTIONS_HPP