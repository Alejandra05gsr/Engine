#ifndef MENU_HPP
#define MENU_HPP
#include "Scene.hpp"
#include "Circle.hpp"
#include "kai_gui.hpp"
#include "Canvas.hpp"

namespace kai 
{
	class Menu : public Scene 
	{
		MenuGUI menuGUI;
		
	private:


	public:

		Circle circles;
		Menu() = default;
		~Menu() = default;

		void OnEnter() override;
		void Update() override;
		void Draw() override;
		void OnExit() override;


	};
}
#endif // !MENU_HPP