#include "CardManager.h"
#include<cstdlib>
#include<ctime>
using namespace std;

CardManager::CardManager()
{
	top = 0;
}

void CardManager::CreateCards()
{
	//カードを生成
	int index = 0;
	for (int i = MIN_CARD; i < MAX_CARD; i++)
	{
		for (int j = 0; j < SAME_CARD; j++)
		{
			deck[index] = i;
			index;
		}
	}
	
	//シャッフル
	for (int i = DECK - 1; i > 0; i--)
	{
		int shuffle = rand() % (i + 1);
		int temp = deck[i];
		deck[i] = deck[shuffle];
		deck[shuffle] = temp;

	}
}
int CardManager::DrawCard()
{
	int card = deck[top];
	top++;

	return card;
}
