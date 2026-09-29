#include "CardManager.h"
#include<cstdlib>
#include<ctime>
using namespace std;

CardManager::CardManager()
{
	cardCount = DECK;
}

void CardManager::CreateCards()
{
	//カードを生成
	int index = 0;
	for (int number = MIN_CARD; number < MAX_CARD; number++)
	{
		for (int i = 0; i < SAME_CARD; i++)
		{
			deck[index] = number;
			index++;
		}
	}
	cardCount = DECK;
	
}

void CardManager::Shuffle()
{
	//シャッフル
	for (int i = DECK - 1; i > 0; i--)
	{
		int shuffle = i + rand() % (DECK - i);
		int temp = deck[i];
		deck[i] = deck[shuffle];
		deck[shuffle] = temp;

	}

}
int CardManager::DrawCard()
{
	int card = deck[0];
	//残りのカードを前に詰める
	for (int i = 0; i < cardCount - 1; i++)
	{
		deck[i] = deck[i + 1];
	}

	cardCount--;

	return card;
}

int CardManager::GetCardCount()
{
	return cardCount;
}
