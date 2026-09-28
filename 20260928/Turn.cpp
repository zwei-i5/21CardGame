#include "Turn.h"
#include<iostream>
#include"Config.h"

using namespace std;

bool Turn::playerTurn(Player* player, CardManager* cardManager)
{
	while (true)
	{
		cout << "\n==============================\n";
		cout << "Player Turn\n";
		cout << "\n==============================\n";

		player->ShowPoint();
		if (player->SumPoint() == WINPOINT)
		{
			cout << "\nPlayer's Total : 21\n";
			return true;
		}
		cout << "カードを引きますか？\n";
		cout << YES << ":Yes\n";
		cout << NO << ":No\n";

		int input;
		
		cin >> input;
		//カードを引かない
		if (input == NO)
		{
			cout << "\nカードを引きません\n";
			return true;
		}

		if (input == YES)
		{
			//カードを取得
			int card = cardManager->DrawCard();

			cout << "Playerがカードを引きました\n";
			cout << "引いたカード:" << card << endl;

			//playerが引いたカードを追加
			player->AddCard(card);

			player->ShowPoint();
		}
		if (player->SumPoint() >= BURST)
		{
			cout << "\nplayerがバーストしました\n";
				return false;
		}
	}
}
