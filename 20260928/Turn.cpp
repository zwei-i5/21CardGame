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

void Turn::CPUTurn(Player* player, CPU* cpu, CardManager* cardManager)
{
	cout << "\n=========================\n";
	cout << "\nCPU Turn\n";
	cout << "\n=========================\n";
	player->ShowPoint();
	cpu->ShowPoint();

	while (true)
	{
		if (cpu->SumPoint() == WINPOINT)
		{
			cout << "CPU Total: 21\n";
			break;
		}
		if (cpu->SumPoint() >= BURST)
		{
			cout << "\nCPUはバーストしました\n";
			break;
		}

		if (cpu->SumPoint() >= LIMIT)
		{
			cout << "\n15以下なのでカードを引きます\n";
		}
		else if (cpu->SumPoint() < player->SumPoint())
		{
			cout << "\nplayerより小さいのでカードを引きます。\n" << endl;
		}
		else
		{
			cout << "CPUはPlayer以上になりました。" << endl;
			cout << "CPUはカードを引きません。" << endl;

			break;
		}
		//カードを取得
		int card = cardManager->DrawCard();
		cout << "\nCPUがカードを引きました。\n";
		cout << "引いたカード：" << card << endl;
		//CPUに引いたカードを追加
		cpu->AddCard(card);
		cpu->ShowPoint();
	}
}
