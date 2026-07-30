#pragma once
#include "Circle.hpp"
#include "Menu.hpp"
#include "Play.hpp"
#include "scene_manager.hpp"

namespace kai{
	class Engine {
	private:


	public:
		Engine();
		~Engine();

		SceneManager sceneManager;
		Menu menu;
		Play play;

		void Update(); //Hace el update
		void Draw();  //Dibuja
		void Init(); //Inicializa
		void Run(); //Update y draw
		void Shutdown();

	};

}