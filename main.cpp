#include <iostream>
#include <conio.h>
#include <Windows.h>
#define SPACE 32
using namespace std;

void gotoxy( int x, int y) // ��ǥ�̵� 
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

class Menu { // �޴����� 
	public:
		void MainMenu();
		void AdviceMenu();
		void RankMenu();
		void CreatorMenu();
};

void Menu::MainMenu() { // ���θ޴� 
	cout << "�� ī�带 ã����!\n\n\n\n\n";
	cout << "���ӽ���" << endl << endl;
	cout << "���ӹ��" << endl << endl;
	cout << "����" << endl << endl;
	cout << "������" << endl << endl;
	cout << "����" << endl << endl; 
}

void Menu::AdviceMenu() { // ���� 
	cout << "���ӹ��\n\n\n\n\n";
	cout << "���ӿ� ���� ���� ���� ���� �߰�" << endl << endl;
	cout << "SPACE�Է� �� �ڷΰ���";
}

void Menu::RankMenu() { // �����޴� 
	cout << "����\n\n\n\n\n";
	cout << "�̱�" << endl;
	cout << "��Ƽ" << endl;
	cout << "SPACE�Է� �� �ڷΰ���";
}

void Menu::CreatorMenu() {
	cout << "������\n\n\n\n\n";
	cout << "���߿� �߰� ���߿� �߰�" << endl;
	cout << "SPACE�Է� �� �ڷΰ���";
}


class Events { // �����̽� �� ���� �̺� Ʈ 
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
				cout << "���ӽ���" << endl;
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
