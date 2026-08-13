#ifndef MENU_HPP
#define MENU_HPP
#include "Scene.hpp"
#include "Circle.hpp"
#include "kai_gui.hpp"
#include "EventBus.hpp"

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



	};
}
#endif // !MENU_HPP