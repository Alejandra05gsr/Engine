#pragma once
#include "Scene.hpp"
namespace kai {
	class SceneManager {
	private:
		Scene* currentScene = nullptr;

	public:
		SceneManager() = default;
		~SceneManager() = default;

		void ChangeScene(Scene* newScene)
		{
			if (currentScene)
			{
				currentScene->OnExit();
			}
			currentScene = newScene;
			if (currentScene)
			{
				currentScene->OnEnter();
			}
		}

		void Update()
		{
			if (currentScene)
			{
				currentScene->Update();
			}
		}

		void Draw()
		{
			if (currentScene)
			{
				currentScene->Draw();
			}
		}
		
	};
}