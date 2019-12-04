#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

struct Starpos
{
	int s_iX;
	int s_iY;
};
inline void gotoxy(int x, int y)
{
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
class Star
{
	Starpos *pos;// 별의 위치를 저장할 배열 포인터
	int m_iX; //가로의 길이
	int m_iY; //세로의 길이
	int m_iSpeed; //별이 떨어지는 속도
	int use_length;//사용하는 데이터 길이
public:
	Star(int x, int y);
	
	void StarPosX(int x, int y);
	void setSpeed(int speed);
	void StarFall();
	void MakeStar();
	void StarErase();
	~Star();
};

