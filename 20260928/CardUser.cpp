#include "CardUser.h"
#include<iostream>

using namespace std;

CardUser::CardUser()
{
	total = 0;
}

void CardUser::AddCard(int card)
{
	total += card;
}

int CardUser::SumPoint()
{
	return total;
}

void CardUser::ShowPoint()
{
	cout << "‡Œv:" << total << endl;
}
