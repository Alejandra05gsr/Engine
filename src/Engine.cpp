#include "Engine.hpp"
#include "raylib.h"
#include "resource_dir.h"	

namespace kai 
{


	void Engine::Init()
	{
		SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
		InitWindow(screenWidth, screenHeight, "Hello Raylib");
		InitAudioDevice();


		//menu.OnEnter();
		SearchAndSetResourceDir("resources");
		
		sceneMgr.addScene("menu", new Menu()); // Register the menu scene
		sceneMgr.addScene("play", new Play()); // Register the play scene
		//sceneMgr.addScene("win", new WinScene());
		//sceneMgr.addScene ( "gameover", new GameOverScene());
		sceneMgr.changeScene("menu"); // Set the initial scene to the menu

		//sceneManager.ChangeScene(&menu); //Copia la direccion de memoria, no el objeto
	}


	void Engine::Update()
	{
		//Switch del enum, si el current state: caso Menu...

		//menu.Update();

		sceneMgr.Update();
		//if (IsKeyPressed(KEY_P))
		//{
		//	//sceneManager.ChangeScene(&play);
		//}
		//if (IsKeyPressed(KEY_M))
		//{
		//	//sceneManager.ChangeScene(&menu);
		//}


	}

	void Engine::Draw()
	{
		BeginDrawing();
		//Switch. Si el currentstate case Menu...
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);
		//menu.Draw();

		sceneMgr.Draw();
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
		//sceneMgr.shutdown();
		//assets.shutdown();

		CloseWindow();
	}
}