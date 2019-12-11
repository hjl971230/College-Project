#include "info.h"

info::info()
{
	ppos.p_iX = 0;
	ppos.p_iY = 0;
	for (int i = 0; i < 20; i++)
	{
		*(spos->s_iX + i) = 1;
		*(spos->s_iY + i) = 0;
	}
	m_iscore = 0;
	m_iSpeed = 100;
	m_iX = 20;
	m_iY = 20;
	m_strstarskin = "��";
}
void info::setSpeed(int speed)
{
	m_iSpeed = speed;
}
void info::StarFall(int& x, int& y) // x, y �� ���� ��ġ
{
	y++;
	gotoxy(x, y);
	cout << m_strstarskin << endl;

} //����� ������ ���� ��ǥ�� �̵�
void info::MakeStar(int& x, int& y)
{
	int rnum = rand() % 100;
	if (rnum <= 10)
	{
		int x1 = (rand() % (m_iX - 2) * 2) + 1;
		x = x1 + 1;  //ó�� �����Ǵ� x�� ��ġ
		y = 1;  //ó�� �����Ǵ� y�� ��ġ
	}

} //�� ���� ��, ���� ��ġ�� ���(���� ���κ�)

void info::StarErase(int& x, int& y) //x, y�� ���� ��ġ
{
	if (y > 1)
	{
		gotoxy(x, y - 1);
		cout << "  " << endl;

	}
	if (y == m_iY - 2)
	{
		//gotoxy(x, y-1);
		//cout << "  " << endl;

		gotoxy(x, y);
		cout << "  " << endl;
		m_iscore++;
	}
}//���� ��ġ�� �� �κ��� ����� �Լ�
void info::StarManager()
{
	for (int i = 0; i < 20; i++) //�迭�� ũ�� = 20
	{
		if (spos->s_iY[i] != 1 || spos->s_iY[i] == m_iY - 1)
		{
			MakeStar(spos->s_iX[i], spos->s_iY[i]);
		}
		for (int j = 0; j < m_iY - 1; j++)
		{
			if (/*pos->s_iY[j] >= 0 &&*/ spos->s_iY[j] < m_iY - 2)
			{
				StarFall(spos->s_iX[j], spos->s_iY[j]);
				StarErase(spos->s_iX[j], spos->s_iY[j]);
				gotoxy(0, 22);
				cout << "���� : " << m_iscore;
			}
		}
		
	}
	
}
void info::collidecheck()
{
	for (int i = 0; i < 20; i++)
	{
		if (*spos[i].s_iY == ppos.p_iY-1)
		{
			system("pause");
		}
	}
}
void info::setm_strstarskin(string str)
{
	m_strstarskin = str;
}
string info::getm_strstarskin()
{
	return m_strstarskin;
}
Playerpos& info::getppos()
{
	return ppos;
}
/*
���� �����Ǵ� ������ ������
�ð����� ���� ����
�ð����� ���� ��ġ���� ������
���� ������ ������ x��ǥ�� ���ϸ� �ȵ�
���� �����ϸ� y��ǥ �ʱ�ȭ, x��ǥ ����
*/
info::~info()
{
	delete[] spos;
}