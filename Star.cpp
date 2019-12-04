#include "Star.h"

using namespace std;

Star::Star(int x, int y)
{
	m_iX = x;
	m_iY = y;
	pos = new Starpos;
	use_length = 0;//��� ���̸� 0���� �ʱ�ȭ
}
void Star::setSpeed(int speed)
{
	m_iSpeed = speed;
}
void Star::StarFall() // �Ķ���ʹ� x��ǥ
{
	pos->s_iY = 1;
	// ���� ó������ �������� ���� ����(������ġ)
	for(pos->s_iY; pos->s_iY < m_iY-1; pos->s_iY++)
	{		
		gotoxy(pos->s_iX, pos->s_iY);
		cout << "��" << endl;
		StarErase();
		Sleep(m_iSpeed); //���� �ӵ�
	}
} //y = 1 ���� y = 15 ���� (���������� 1)
void Star::MakeStar() 
{
	int x = rand() % (m_iX - 2) * 2 + 1;
	pos->s_iX = x + 1;
} //�� ���� ��, ���� ��ġ�� ���(���� ���κ�)
void Star::StarErase()
{
	if (pos->s_iY != 1)
	{
		gotoxy(pos->s_iX, pos->s_iY - 1);
		cout << " " << endl;

		gotoxy(pos->s_iX, pos->s_iY - 1);
		cout << "\0" << endl; //������ �ڸ��� �ι��� ����
	}
	//������1 : ���� ������ ��ġ���� �������� ����
	if (pos->s_iY == m_iY - 1)
	{
		gotoxy(pos->s_iX, pos->s_iY - 1);
		cout << " " << endl;

		gotoxy(pos->s_iX, pos->s_iY - 1);
		cout << "\0" << endl;

		/*gotoxy(pos->s_iX, pos->s_iY);
		cout << " " << endl;

		gotoxy(pos->s_iX, pos->s_iY);
		cout << "\0" << endl;*/
	}
}
Star::~Star()
{
	delete pos;
}
/*
������2 :
����ü�� �̿��Ͽ� ���� ��ǥ�� ����ؾ� ��
���� ������ �� �����Ҵ��ϰ� �Ҹ��� �� �Ҵ����� �ҷ���?
������3 :
�� �������� ����߸��� �����?
���� �� �ϳ��� ������ �������߸� ���� ���� ������
*/