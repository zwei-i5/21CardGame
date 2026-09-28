#pragma once
class CPU
{
private:
	int CPUPoint;
public:
	//コンストラクタ
	CPU();
	//カードを追加
	void AddCard(int card);
	//合計点数
	int SumPoint();
	//現在の点数
	void ShowPoint();

};

