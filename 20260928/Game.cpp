#include "Game.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include"Config.h"
using namespace std;

Game::Game()
{
	cardManager.CreateCards();
	cardManager.Shuffle();
}

void Game::Start()
{
	//カードを配布
	DealInitialCards();
	//プレイヤーのターン
	bool playerTurnResult = turn.playerTurn(&player, &cardManager);
	//CPUのターン
	if (playerTurnResult)
	{
		turn.CPUTurn(&player, &CPU, &cardManager);
	}
	else
	{
		cout << "\nプレイヤーの負けです。\n";

		return;
	}
	//勝敗判定
	ShowResult();
}

void Game::DealInitialCards()
{
	//プレイヤーとCPUに初期カードを配る
	for (int i = 0; i < GIVE_CARD; i++)
	{
		int playerCard = cardManager.DrawCard();
		player.AddCard(playerCard);
		int cpuCard = cardManager.DrawCard();
		CPU.AddCard(cpuCard);
	}
}

void Game::ShowResult()
{
	cout << "\n=============================\n";
	cout << "ゲーム結果";
	cout << "\n=============================\n";
	player.ShowPoint();
	CPU.ShowPoint();

	int playertotal = player.SumPoint();
	int cputotal = CPU.SumPoint();

	if (cputotal >= BURST || playertotal == WINPOINT)
	{
		cout << "\nPlayer's Winner!!\n";
		return;
	}
	if (cputotal == WINPOINT)
	{
		cout << "\nCPU's Winner\n";
		return;
	}

	int playerDistance = WINPOINT - playertotal;

	int cpuDistance = WINPOINT - cputotal;

	if (playerDistance > cpuDistance)
	{
		cout << "\nPlayerの勝ちです。\n";
	}
	else if(playerDistance < cpuDistance)
	{
		cout << "\nCPUの勝ちです\n";
	}
	else
	{
		cout << "\n引き分けです\n";
	}
}

