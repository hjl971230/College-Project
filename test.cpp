
#include "Star.h"

using namespace std;
int main()
{
	srand(time(NULL));
	Star a(20, 20);
	a.setSpeed(100);
	//for (int i = 0; i < 20; i++)
	//{
	//	cout << "¦¡";
	//} //¸ÊÀÇ À­ Ä­. º°°Å¾Æ´Ô
	for (int y = 0; y < 20; y++)
	{
		gotoxy(0, 0 + y);
		if (y == 0)
		{
			cout << "";
			for (int x = 1; x < 39; x++)
				cout << "";
			cout << "";
		}
		else if (y == 20-1)
		{
			cout << "";
			for (int x = 1; x < 39; x++)
				cout << "";
			cout << "";
		}
		else
		{
			cout << "";
			for (int x = 1; x < 20; x++)
				cout << "  ";
			cout << "";
		}
	}
	
	///*int i;
	//int x = 0;
	//int y = 0;
	//
	//int width = 20;
	//int height = 20;

	//cout << "";

	//for (i = 0; i < width*2; i++)
	//{
	//	cout << "";
	//}
	//cout << "";

	//for (i = 0; i < height; i++)
	//{
	//	y++;
	//	a.gotoxy(x, y);
	//	cout << "";

	//	x += width + 1;
	//	a.gotoxy(x, y);
	//	cout << "";
	//	x = 0;
	//}
	//a.gotoxy(x, y);

	//cout << "";
	//for (i = 0; i < width*2; i++)
	//{
	//	cout << "";
	//}
	//cout << "";*/
	while (1)
	{
		a.MakeStar();
		a.StarFall();
		a.StarErase();
	}
}