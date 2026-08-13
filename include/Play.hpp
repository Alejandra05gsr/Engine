#ifndef PLAY_HPP
#define PLAY_HPP
#include "Scene.hpp"
#include "EventBus.hpp"
#include "player.hpp"

namespace kai {
	class Play : public Scene, EventListener {
	private:

	public:
		Play() = default;
		~Play() = default;

		void OnInit() override;
		void OnEnter() override;
		void Update() override;
		void Draw() override;
		void OnExit() override;
		void onEvent(EventData data) override; 

		Player player;


		int eventId_01;
		int eventId_02;
		int playerScore;
		int grabCoinEvId;

	};
}
#endif // !PLAY_HPP