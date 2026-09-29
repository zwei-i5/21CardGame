#pragma once
class CardUser
{

protected:
	int total;
public:
	CardUser();

	//カードを追加
	void AddCard(int Card);
	//合計点を取得する
	int SumPoint();
	//現在の状態を表示
	void ShowPoint();
};

