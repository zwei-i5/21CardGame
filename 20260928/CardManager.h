#pragma once
#include"Config.h"
class CardManager
{
private:
	int deck[DECK];
	int cardCount;
public:
	//コンストラクタ
	CardManager();
	//カード生成
	void CreateCards();
	//シャッフル
	void Shuffle();
	//カードを引く
	int DrawCard();
	//残りのカード枚数
	int GetCardCount();

};

