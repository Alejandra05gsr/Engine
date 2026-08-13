#pragma once
#include <string>
#include <unordered_map>
#include "Scene.hpp"
namespace kai {
	class SceneManager 
	{
		std::unordered_map<std::string, Scene*> scenes;
		Scene* currentScene = nullptr;
		Scene* next = nullptr;

	public:
		static SceneManager& get()
		{
			static SceneManager instance;
			return instance;
		}
		SceneManager(const SceneManager&) = delete; //Constructor copia
		void operator=(const SceneManager&) = delete;

		void addScene(const std::string& name, Scene* scene)
		{
			scenes[name] = scene;
		}

		void changeScene(const std::string& name)
		{
			auto it = scenes.find(name);
			if (it == scenes.end())
				return;
			next = it->second;
		}

		void Update()
		{
			if (currentScene)
			{
				currentScene->Update();
			}
			processChange();
		}

		void Draw()
		{
			if (currentScene)
			{
				currentScene->Draw();
			}
		}

	private:
		void processChange()
		{
			if (!next)
				return;
			if (currentScene)
				currentScene->OnExit();
			currentScene = next;
			next = nullptr;
			currentScene->OnInit();
		}
		SceneManager() = default;
		
	};
}