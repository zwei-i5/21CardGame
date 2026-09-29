#pragma once
#include"Player.h"
#include"CPU.h"
#include"CardManager.h"
#include"Turn.h"
class Game
{
private:
	Player player;
	CPU CPU;
	CardManager cardManager;
	Turn turn;

	//カードを配る
	void DealInitialCards();

	//勝敗判定
	void ShowResult();
public:
	//コンストラクタ
	Game();
	//ゲーム開始
	void Start();

};

