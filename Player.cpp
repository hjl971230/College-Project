#include "Player.h"

Player::Player()
{
	m_strPlayerskin = "��";
}
void Player::setm_strPlayerskin(string str)
{
	m_strPlayerskin = str;
}
string Player::getm_strPlayerskin()
{
	return m_strPlayerskin;
}
void Player::Move(int* x, int* y, int* Width, int* Height, bool* ft)
{
	int ch;
	if (*ft) 
	{
		m_ix = *Width;
		m_iy = *Height - 2;
		*x = m_ix;
		*y = m_iy;
	}
	m_MapDrawManager.TextDraw(getm_strPlayerskin(),*x, *y);
	
	ch = _getch();
	m_MapDrawManager.ErasePoint(m_ix, m_iy);
	switch (ch)
	{
	case DIRECTION_LEFT:
		if (*x > 2)
		{
			(*x)--;
		}
		break;
	case DIRECTION_RIGHT:
		if (*x < (*Width * 2) - 3)
		{
			(*x)++;
		}
		break;

	case _INTERFACE_ESC:
		*ft = true;

		return;
	case _INTERFACE_OPTION:

		return;
	}
		
	m_MapDrawManager.TextDraw(getm_strPlayerskin(),*x, *y);
	*ft = false;
		
}