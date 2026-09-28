#include "Player.h"
#include<iostream>
using namespace std;

Player::Player()
{
	PlayerPoint = 0;
}

void Player::AddCard(int card)
{
	PlayerPoint += card;
}

int Player::SumPoint()
{
	return PlayerPoint;
}

void Player::ShowPoint()
{
	cout << "Player‚Ì‡ŒvF" << PlayerPoint << endl;
}