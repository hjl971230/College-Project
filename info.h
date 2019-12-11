#pragma once
#include "Header.h"

struct Playerpos
{
	int p_iX;
	int p_iY;
};

struct Starpos
{
	int s_iX[20];
	int s_iY[20];
};

class info
{
	Playerpos ppos;
	Starpos* spos = new Starpos;// ���� ��ġ�� ������ �迭 ������
	int m_iX; //������ ����
	int m_iY; //������ ����
	int m_iSpeed; //���� �������� �ӵ�
	int m_iscore;
	string m_strstarskin;
public:
	info();
	void setSpeed(int speed);
	// x, y�� ��ġ�� ������������ �迭 ����
	Playerpos& getppos();
	void StarFall(int& x, int& y);
	void MakeStar(int& x, int& y);
	void StarErase(int& x, int& y);
	void StarManager();
	void setm_strstarskin(string);
	string getm_strstarskin();
	void collidecheck();
	~info();
};

