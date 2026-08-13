#pragma once
#include "EventBus.hpp"


class Player
{
public:
	void GrabCoin()
	{
		EventData data;
		data.type = "grab_coin";
		EventBus::get().fire("grab_coin", data);
	}

	void EnemyHit()
	{
		EventData data;
		data.type = "enemy_hit";
		EventBus::get().fire("enemy_hit", data);
	}

	void PlayerHit()
	{
		EventData data;
		data.type = "player_hit";
		EventBus::get().fire("player_hit", data);

	}

};