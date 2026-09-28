#pragma once
class Player
{
private:
	int PlayerPoint;
public:
	//コンストラクタ
	Player();
	//カードを追加
	void AddCard(int card);
	//合計点数
	int SumPoint();
	//現在の点数
	void ShowPoint();

};

