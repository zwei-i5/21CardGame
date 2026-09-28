#include "CPU.h"
#include<iostream>
using namespace std;

CPU::CPU()
{
	CPUPoint = 0;
}

void CPU::AddCard(int card)
{
	CPUPoint += card;
}

int CPU::SumPoint()
{
	return CPUPoint;
}

void CPU::ShowPoint()
{
	cout << "CPU‚Ì‡Œv" << CPUPoint << endl;
}
