#pragma once
#include "Scene.hpp"
#include "Circle.hpp"

namespace kai {
	class Menu : public Scene {
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
