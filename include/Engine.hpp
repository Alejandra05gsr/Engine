#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "Circle.hpp"
#include "Play.hpp"
#include "Menu.hpp"
#include "scene_manager.hpp"

namespace kai{
	class Engine {
	public:
		Engine() = default;
		~Engine() = default;

		//Play play;
		//Menu menu;

		void Init(); //Inicializa
		void Run(); //Update y draw
		void Update(); //Hace el update
		void Draw();  //Dibuja
		void Shutdown();

		SceneManager& sceneMgr = SceneManager::get();

		int screenWidth = 800;
		int screenHeight = 600;


	};

}
#endif // !ENGINE_HPP