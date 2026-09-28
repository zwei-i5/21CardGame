#pragma once
#include"Config.h"
class CardManager
{
private:
	int deck[44];
	int top;
public:
	//コンストラクタ
	CardManager();
	//カード生成
	void CreateCards();
	
	//カードを引く
	int DrawCard();
	//残りのカード枚数
	int GetCardCount();

};

