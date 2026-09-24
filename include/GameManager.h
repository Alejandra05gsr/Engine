#pragma once
#include "EventBus.hpp"
#include "scene_manager.hpp"
#include "raylib.h"


class GameManager : public EventListener
{
public:
	int max_kills = 20;
	int current_kills = 0;
	int max_player_lives = 5;
	int player_lives = 5;

	static inline int last_final_score = 0;

	int getLives() const { return player_lives; }


	void init() {
		reset();
		listen("player_kill");
		listen("enemy_kill");
		listen("gain_life");
	}

	void exit() {
		//EventBus::get().unbind("player_kill", 0);
		//EventBus::get().unbind("enemy_kill", 0);
		//EventBus::get().unbind("gain_life", 0);
	}

	void onEnemyHit() {
		current_kills++;
		last_final_score = current_kills;
		TraceLog(LOG_INFO, "Enemy killed. Current kills: %i", current_kills);
		if (current_kills >= max_kills) {
			kai::SceneManager::get().changeScene("win");
		}

	}

	void onPlayerHit() {
		player_lives--;
		TraceLog(LOG_INFO, "Player hit. Remaining lives: %i", player_lives);
		if (player_lives <= 0) {
			kai::SceneManager::get().changeScene("gameover");
		}
	}

	void onGainLife() {
		if (player_lives < max_player_lives) { 
			player_lives++;
			TraceLog(LOG_INFO, "Life gained! Current lives: %i", player_lives);
		}
	}




	void onEvent(EventData data) override {
		if (data.type == "player_kill") {
			onPlayerHit();
		}

		if (data.type == "enemy_kill") {
			onEnemyHit();
		}
		if (data.type == "gain_life") { 
			onGainLife();
		}
	}

	void reset() {
		current_kills = 0;
		player_lives = max_player_lives;
	}
};
