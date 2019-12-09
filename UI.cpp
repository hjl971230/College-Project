#include "UI.h"
UI::UI()
{
	m_ifirstx = 20;
	m_ifirsty = 20;
	m_bfirsttime = true;
}

void UI::Maintitle()
{
	Menu(m_info.getppos().p_iX, m_info.getppos().p_iY, &m_ifirstx, &m_ifirsty);
}

void UI::Menu(int &x, int &y, int* Width, int* Height)
{
	int Select;
	while (1)
	{
		system("cls");
		BoxDraw(x, y, *Width, *Height);//���δ� ��ġ ���� ���Ƿ� �Ұ�(y+����/�׸� ��)?,���δ� �׸��� �Ѿ ���� 2�� ���̳���
		DrawMidText("�� �� �� �� ��", (x + *Width) - 1, ((*Height + 1) / 2) - 4);
		DrawMidText("1.���� ����", (x + *Width) - 1, ((*Height + 1) / 2)-2);
		DrawMidText("2.�ɼ� ����", (x + *Width) - 1, (*Height +1)/2);
		DrawMidText("3.���� ����", (x + *Width) - 1, ((*Height + 1) / 2) + 2);
		DrawMidText("�Է� : ", (x + *Width) - 1, ((*Height + 1) / 2) + 4);
		cin >> Select;
		switch (Select)
		{
		case 1:
			GamePlay(x, y, Width, Height);
			break;
		case 2:
			//option(x, y, Width, Height, true);
			break;
		case 3:
			//*Gmcheck = false;
			return;
		default:
			break;
		}
	}

}
void UI::GamePlay(int &x, int &y, int* Width, int* Height)
{
	int s_ix = *Width;
	int s_iy = *Height - 2;
	system("cls");
	BoxDraw(x, y, *Width, *Height);
	TextDraw(m_Player.getm_strPlayerskin(), s_ix, s_iy);
	while (1)
	{

		m_info.StarManager();

		if (_kbhit())
		{
			m_Player.Move(&x, &y, Width, Height, &m_bfirsttime);
		}
		
	}
}

void UI::SkinChange(int x, int y, int* Width, int* Height)
{
	int Select;
	BoxDraw(x, y, *Width, *Height);
	DrawMidText("=Set Player Skin=", (x + *Width) - 1, ((*Height + 1) / 2)-6);
	DrawMidText("1.��", (x + *Width) - 1, ((*Height + 1) / 2)-4);
	DrawMidText("2.��", (x + *Width) - 1, ((*Height + 1) / 2)-2);
	DrawMidText("3.��", (x + *Width) - 1, ((*Height + 1) / 2));
	DrawMidText("4.��", (x + *Width) - 1, ((*Height + 1) / 2)+2);
	DrawMidText("5.Return", (x + *Width) - 1, ((*Height + 1) / 2)+4);
	DrawMidText("�Է� : ", (x + *Width) - 1, ((*Height + 1) / 2)+6);
	cin >> Select;
	switch (Select)
	{
	case 1:
		m_Player.setm_strPlayerskin("��");
		break;
	case 2:
		m_Player.setm_strPlayerskin("��");
		break;
	case 3:
		m_Player.setm_strPlayerskin("��");
		break;
	case 4:
		m_Player.setm_strPlayerskin("��");
		break;
	case 5:
		return;
	default:
		break;
	}
}
