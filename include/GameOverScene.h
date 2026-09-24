#ifndef GAMEOVER_SCENE_H
#define GAMEOVER_SCENE_H
#include "scene_manager.hpp"
#include "EventBus.hpp"
#include "resources_manager.h"

using namespace kai;

namespace kai
{
	class GameOverScene : public Scene
	{
	public:
		GameOverScene();
		~GameOverScene();

		// Heredado vía Scene
		void OnInit() override;

		void OnEnter() override;

		void Update() override;

		void Draw() override;

		void OnExit() override;


		Font font;
		Sound buttonSound;
		Music bg_music;
		Texture2D textureBG;
		kai::ResourcesManager& assets = kai::ResourcesManager::get();


	};
}
#endif // !GAMEOVER_SCENE_H
