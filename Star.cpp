#include "Star.h"

using namespace std;

Star::Star(int x, int y)
{
	m_iX = x;
	m_iY = y;
	pos = new Starpos;
	use_length = 0;//사용 길이를 0으로 초기화
}
void Star::setSpeed(int speed)
{
	m_iSpeed = speed;
}
void Star::StarFall() // 파라미터는 x좌표
{
	pos->s_iY = 1;
	// 별이 처음으로 떨어지는 세로 길이(시작위치)
	for(pos->s_iY; pos->s_iY < m_iY-1; pos->s_iY++)
	{		
		gotoxy(pos->s_iX, pos->s_iY);
		cout << "★" << endl;
		StarErase();
		Sleep(m_iSpeed); //낙하 속도
	}
} //y = 1 에서 y = 15 까지 (위에서부터 1)
void Star::MakeStar() 
{
	int x = rand() % (m_iX - 2) * 2 + 1;
	pos->s_iX = x + 1;
} //맵 기준 좌, 우의 위치를 비움(맵의 벽부분)
void Star::StarErase()
{
	if (pos->s_iY != 1)
	{
		gotoxy(pos->s_iX, pos->s_iY - 1);
		cout << " " << endl;

		gotoxy(pos->s_iX, pos->s_iY - 1);
		cout << "\0" << endl; //공백의 자리에 널문자 삽입
	}
	//문제점1 : 별의 마지막 위치에서 지워지지 않음
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
문제점2 :
구조체를 이용하여 별의 좌표를 기억해야 함
별이 생성될 때 동적할당하고 소멸할 때 할당해제 할려면?
문제점3 :
별 여러개를 떨어뜨리는 방법은?
현재 별 하나가 완전히 떨어져야만 다음 별이 떨어짐
*/