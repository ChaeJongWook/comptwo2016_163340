#include <iostream>
#include <conio.h>
#include <Windows.h>
#define SPACE 32
using namespace std;

void gotoxy( int x, int y) // 좌표이동 
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

class Menu { // 메뉴구현 
	public:
		void MainMenu();
		void AdviceMenu();
		void RankMenu();
		void CreatorMenu();
};

void Menu::MainMenu() { // 메인메뉴 
	cout << "내 카드를 찾아줘!\n\n\n\n\n";
	cout << "게임시작" << endl << endl;
	cout << "게임방법" << endl << endl;
	cout << "순위" << endl << endl;
	cout << "제작자" << endl << endl;
	cout << "종료" << endl << endl; 
}

void Menu::AdviceMenu() { // 도움말 
	cout << "게임방법\n\n\n\n\n";
	cout << "게임에 대한 설명 이하 추후 추가" << endl << endl;
	cout << "SPACE입력 시 뒤로가기";
}

void Menu::RankMenu() { // 순위메뉴 
	cout << "순위\n\n\n\n\n";
	cout << "싱글" << endl;
	cout << "멀티" << endl;
	cout << "SPACE입력 시 뒤로가기";
}

void Menu::CreatorMenu() {
	cout << "제작자\n\n\n\n\n";
	cout << "나중에 추가 나중에 추가" << endl;
	cout << "SPACE입력 시 뒤로가기";
}


class Events { // 스페이스 및 엔터 이벤 트 
	public:
		int Escape();
};

int Events::Escape() {
	char key;
	key = getch();
	if( key == SPACE)
	{
		return 1;
	}
}





int main()
{
	int i;
	
	Menu menu;
	Events effect;
	
	while(1)
	{
		menu.MainMenu();
		i = getch();
		
		switch(i)
		{
			case '1':
				cout << "게임시작" << endl;
				break;
			case '2':
				while(1)
				{
					system("cls");
					menu.AdviceMenu();
					if( effect.Escape() == 1 )
					{
						break;
					}
				}
				system("cls");
				break;
			case '3':
				while(1)
				{
					system("cls");
					menu.RankMenu();
					if( effect.Escape() == 1 )
					{
						break;
					}
				}
				system("cls");
				break;
			case '4':
				while(1)
				{
					system("cls");
					menu.CreatorMenu();
					if( effect.Escape() == 1 )
					{
						break;
					}
				}
				system("cls");
				break;
			case '5':
				return 0;
				break;
		}
	}
}
