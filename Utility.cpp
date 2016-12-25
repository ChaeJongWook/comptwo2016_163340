#include "MyHeader.h"


void Utility::gotoxy( int x, int y) // �ܼ�â ���� x��ǥ�� y��ǥ �̵�
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void Utility::CursorVisible(bool blnCursorVisible)    // Ŀ�� ���ִ� �� ��
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = blnCursorVisible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Utility::TimeCalc()
{
	clock_t st,et;
	st = clock(); //���۽ð�
	while((float)(et-st)/1000 < 2)
	{
	et = clock();
	}
}


float Utility::PlayTime(int i)
{
	clock_t st,et;
	if( i == 0 )
	{
	st = clock(); //���۽ð�
	}
	else if( i == 1)
	{
		et = clock();
		return (float)(et-st)/1000;
	}
}

void Utility::PushSpace()
{
	char key;
	while(1)
	{
		key = getch();
		if( key == SPACE)
		{
			break;
		}
	}
} 
