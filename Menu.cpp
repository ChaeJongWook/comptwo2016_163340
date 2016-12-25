#include "MyHeader.h"

int Menu::Main() // 메인메뉴 
{
	system("cls");
	gotoxy(titlexpos,titleypos); cout << "|내 카드를 찾아줘!|";
	gotoxy(buttonxpos,buttonypos); cout << "게임시작";
	gotoxy(buttonxpos,buttonypos+2); cout << "게임방법";
	gotoxy(buttonxpos,buttonypos+4); cout << "순위";
	gotoxy(buttonxpos,buttonypos+6); cout << "제작자";
	gotoxy(buttonxpos,buttonypos+8); cout << "게임종료";
	return 5;
}

int Menu::GameStart()
{
	system("cls");
	gotoxy(titlexpos+4,titleypos); cout << "게임모드";
	gotoxy(buttonxpos,buttonypos); cout << "1인(싱글)";
	gotoxy(buttonxpos,buttonypos+2); cout << "2인";
	gotoxy(buttonxpos,buttonypos+4); cout << "3인";
	gotoxy(buttonxpos,buttonypos+6); cout << "4인";
	gotoxy(buttonxpos,buttonypos+8); cout << "뒤로가기";
	return 5;	
}

void Menu::HowToPlay()
{
	system("cls");
	gotoxy(titlexpos,titleypos); cout << "게임방법";
	gotoxy(15,12); cout << "① 52장의 카드가 랜덤으로 나타난다.";
	gotoxy(15,13); cout << "② 몇초간 카드의 모습을 보여주고 플레이어는 카드의 모양과 숫자, 위치를 기억한다.";
	gotoxy(15,14); cout << "③ 시간이 지나면 카드의 정보는 감춰지고 플레이어는 기억한 카드의 정보를 토대로 카드를 수집한다.";
	gotoxy(15,15); cout << "④ A~K까지의 모든 카드를 수집하면 승리하게된다.";
	gotoxy(40,20); cout << "SPACE입력 시, 뒤로 이동합니다.";
}

void Menu::Rank()
{
	system("cls");
	gotoxy(titlexpos,titleypos); cout << "순위";
	gotoxy(30,10); cout << "싱글";
	gotoxy(30,15); cout << "멀티";
	gotoxy(40,20); cout << "SPACE입력 시, 뒤로 이동합니다.";	
}

void Menu::GameCreator()
{
	system("cls");
	gotoxy(titlexpos,titleypos); cout << "제작자";
	gotoxy(15,12); cout << "163340 채종욱입니다.";
	gotoxy(40,20); cout << "SPACE입력 시, 뒤로 이동합니다.";
}

int Menu::GameExit()
{
	char choice;
	system("cls");
	gotoxy(45,13); cout << "게임을 종료하시겠습니까?";
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

