#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
#include<time.h>
using namespace std;

#define RESETMAX 10
enum DIRECTION
{
	DIRECTION_LEFT = 'a',
	DIRECTION_RIGHT = 'd',
	DIRECTION_CAPS_LEFT = 'A',
	DIRECTION_CAPS_RIGHT = 'D'
};
enum _INTERFACE
{
	_INTERFACE_ESC = 27,
	_INTERFACE_OPTION = 112
};

inline void gotoxy(int x, int y)//�ܼ�â���� Ư�� ��ġ�� �̵��ϱ� ���� ����ϴ� �Լ�
{
	COORD Pos = { x, y };//�̵��� ��ǥ�� �����ϱ� ���� ����ü, short���� x,y �� ����� ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	//�ش� �Լ��� �ܼ� â���� Ư�� ��ġ�� Ŀ���� �̵��� �� ����
	//(�ڵ鰪, �̵��� ��ġ�� �����ϰ� �ִ� COORD�� ����ü)
}
