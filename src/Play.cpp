#include "Play.hpp"
#include "raylib.h"

namespace kai {
	void Play::OnInit()
	{
		listen("grab_coin");
		listen("enemy_hit");
		listen("player_hit");

		ship = new Ship();
		ship2 = new Ship();
		bullet = new Bullet();

		ship->setPosition(10, 20);
		ship2->setPosition(20, 40);
		bullet->setPosition(400, 550);


		entityMgr.add(bullet);
		entityMgr.add(ship);
		entityMgr.add(ship2);


	}
	void Play::OnEnter()
	{
	}
	void Play::Update()
	{
		entityMgr.update();


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
		entityMgr.draw();

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