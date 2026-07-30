#pragma once
#include "Scene.hpp"

namespace kai {
	class Play : public Scene {
	private:

	public:
		Play() = default;
		~Play() = default;


		void OnEnter() override;
		void Update() override;
		void Draw() override;
		void OnExit() override;

	};
}