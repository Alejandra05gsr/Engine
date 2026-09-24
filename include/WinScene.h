#ifndef WIN_SCENE_H
#define WIN_SCENE_H
#include "scene_manager.hpp"
#include "EventBus.hpp"
#include "resources_manager.h"

using namespace kai;

namespace kai
{
	class WinScene : public Scene 
	{
	public:
		WinScene();
		~WinScene();

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
	};
}
#endif // !WIN_SCENE_H

