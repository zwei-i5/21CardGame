#pragma once
#include"CPU.h"
#include"Player.h"
#include"CardManager.h"
class Turn
{
public:
	//playerTurn
	bool playerTurn(Player* playe,CardManager*cardManager);
	//CPUTurn
	void CPUTurn(Player*player,CPU* cpu, CardManager* cardManager);
};

