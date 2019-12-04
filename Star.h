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
	Starpos *pos;// ���� ��ġ�� ������ �迭 ������
	int m_iX; //������ ����
	int m_iY; //������ ����
	int m_iSpeed; //���� �������� �ӵ�
	int use_length;//����ϴ� ������ ����
public:
	Star(int x, int y);
	
	void StarPosX(int x, int y);
	void setSpeed(int speed);
	void StarFall();
	void MakeStar();
	void StarErase();
	~Star();
};

