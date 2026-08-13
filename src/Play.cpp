#include "Play.hpp"
#include "raylib.h"

namespace kai {
	void Play::OnInit()
	{
		listen("grab_coin");
		listen("enemy_hit");
		listen("player_hit");

	}
	void Play::OnEnter()
	{
	}
	void Play::Update()
	{
		if (IsKeyPressed(KEY_C))
		{
			player.GrabCoin();
		}
		if (IsKeyPressed(KEY_E))
		{
			player.EnemyHit();
		}
		if (IsKeyPressed(KEY_P))
		{
			player.PlayerHit();
		}

	}
	void Play::Draw()
	{
		DrawText("Play", 200, 200, 20, WHITE);
	}
	void Play::OnExit()
	{
	}
	void Play::onEvent(EventData data)
	{
		if (data.type == "grab_coin")
		{
			TraceLog(LOG_INFO, "Se agarro una moneda");
		}
		else if (data.type == "enemy_hit")
		{
			TraceLog(LOG_INFO, "Enemigo golpeado");
		}
		else if (data.type == "player_hit")
		{
			TraceLog(LOG_INFO, "El jugador fue golpeado");
		}
	}
}