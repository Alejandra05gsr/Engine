#ifndef MENU_HPP
#define MENU_HPP
#include "Scene.hpp"
#include "Circle.hpp"
#include "kai_gui.hpp"
#include "EventBus.hpp"
#include "resources_manager.h"

namespace kai 
{
	class Menu : public Scene, public EventListener 
	{
		MenuGUI menuGUI;
		int playEventId;

	public:

		Circle circles;
		Menu();
		~Menu();

		void OnInit() override;
		void OnEnter() override;
		void Update() override;
		void Draw() override;
		void OnExit() override;
		void onEvent(EventData data) override;

		Font font;
		Sound sound;
		Music bg_music;
		kai::ResourcesManager& assets = kai::ResourcesManager::get();

		Texture2D textureBG;





	};
}
#endif // !MENU_HPP

