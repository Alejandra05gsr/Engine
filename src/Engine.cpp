#include "Engine.hpp"
#include "raylib.h"
#include "resource_dir.h"	

namespace kai {

	//enum gameState
	//{
	//	Menu, Play, Pause, GameOver, Win
	//};


	Engine::Engine()
	{
		// Load a texture from the resources directory
		//Texture wabbit = LoadTexture("wabbit_alpha.png");
		//SearchAndSetResourceDir("resources");
	}

	Engine::~Engine()
	{

	}

	void Engine::Init()
	{
		SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
		InitWindow(800, 600, "Hello Raylib");

		menu.OnEnter();

		//sceneManager.ChangeScene(&menu); //Copia la direccion de memoria, no el objeto
	}


	void Engine::Update()
	{
		//Switch del enum, si el current state: caso Menu...

		menu.Update();

		sceneManager.Update();
		if (IsKeyPressed(KEY_P))
		{
			//sceneManager.ChangeScene(&play);
		}
		if (IsKeyPressed(KEY_M))
		{
			//sceneManager.ChangeScene(&menu);
		}


	}

	void Engine::Draw()
	{
		BeginDrawing();
		//Switch. Si el currentstate case Menu...
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);
		menu.Draw();

		sceneManager.Draw();
		EndDrawing();


	}


	void Engine::Run() //Update y Draw
	{
		while (!WindowShouldClose())
		{
			Update();
			Draw();
		}
	}

	void Engine::Shutdown() //Finalizar la aplicación
	{
		//menu.OnExit();
		CloseWindow();
	}
}