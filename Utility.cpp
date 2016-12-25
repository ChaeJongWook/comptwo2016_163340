#include "MyHeader.h"


void Utility::gotoxy( int x, int y) // 콘솔창 내에 x좌표와 y좌표 이동
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void Utility::CursorVisible(bool blnCursorVisible)    // 커서 없애는 기 능
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = blnCursorVisible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void Utility::TimeCalc()
{
	clock_t st,et;
	st = clock(); //시작시간
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
	st = clock(); //시작시간
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
