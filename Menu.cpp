#include "MyHeader.h"

int Menu::Main() // ���θ޴� 
{
	system("cls");
	gotoxy(titlexpos,titleypos); cout << "|�� ī�带 ã����!|";
	gotoxy(buttonxpos,buttonypos); cout << "���ӽ���";
	gotoxy(buttonxpos,buttonypos+2); cout << "���ӹ��";
	gotoxy(buttonxpos,buttonypos+4); cout << "����";
	gotoxy(buttonxpos,buttonypos+6); cout << "������";
	gotoxy(buttonxpos,buttonypos+8); cout << "��������";
	return 5;
}

int Menu::GameStart()
{
	system("cls");
	gotoxy(titlexpos+4,titleypos); cout << "���Ӹ��";
	gotoxy(buttonxpos,buttonypos); cout << "1��(�̱�)";
	gotoxy(buttonxpos,buttonypos+2); cout << "2��";
	gotoxy(buttonxpos,buttonypos+4); cout << "3��";
	gotoxy(buttonxpos,buttonypos+6); cout << "4��";
	gotoxy(buttonxpos,buttonypos+8); cout << "�ڷΰ���";
	return 5;	
}

void Menu::HowToPlay()
{
	system("cls");
	gotoxy(titlexpos,titleypos); cout << "���ӹ��";
	gotoxy(15,12); cout << "�� 52���� ī�尡 �������� ��Ÿ����.";
	gotoxy(15,13); cout << "�� ���ʰ� ī���� ����� �����ְ� �÷��̾�� ī���� ���� ����, ��ġ�� ����Ѵ�.";
	gotoxy(15,14); cout << "�� �ð��� ������ ī���� ������ �������� �÷��̾�� ����� ī���� ������ ���� ī�带 �����Ѵ�.";
	gotoxy(15,15); cout << "�� A~K������ ��� ī�带 �����ϸ� �¸��ϰԵȴ�.";
	gotoxy(40,20); cout << "SPACE�Է� ��, �ڷ� �̵��մϴ�.";
}

void Menu::Rank()
{
	system("cls");
	gotoxy(titlexpos,titleypos); cout << "����";
	gotoxy(30,10); cout << "�̱�";
	gotoxy(30,15); cout << "��Ƽ";
	gotoxy(40,20); cout << "SPACE�Է� ��, �ڷ� �̵��մϴ�.";	
}

void Menu::GameCreator()
{
	system("cls");
	gotoxy(titlexpos,titleypos); cout << "������";
	gotoxy(15,12); cout << "163340 ä�����Դϴ�.";
	gotoxy(40,20); cout << "SPACE�Է� ��, �ڷ� �̵��մϴ�.";
}

int Menu::GameExit()
{
	char choice;
	system("cls");
	gotoxy(45,13); cout << "������ �����Ͻðڽ��ϱ�?";
	gotoxy(55,14); cout << "Y/N";	
	while(1)
	{
		choice = getch();
		if( choice == 'Y' || choice == 'y')
		{
			return 1;
		}
		else if( choice == 'N' || choice == 'n')
		{
			return 0;
		}
	}
}

