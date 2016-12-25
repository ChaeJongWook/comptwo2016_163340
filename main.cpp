#include "MyHeader.h"


void gotoXY( int x, int y) // 콘솔창 내에 x좌표와 y좌표 이동
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int main()
{
	int Main, Single;
	int Select,num,tern = 1,playtern = 1;

	Menu menu;
	Arrow arrow;
	Erase erase;
	Utility util;
	srand((unsigned)time(NULL));
	menu.CursorVisible(false);
	while(1)
	{
		Main = 0;
		Main = arrow.ArrowControl(menu.Main());      
		switch(Main)
		{
			case 1:
			{
					Single = arrow.ArrowControl(menu.GameStart());				
					switch(Single)
					{
						case 1:
							{
							num = 1;
							cout << "싱글모드를 시작합니다.";
							Pcard fakecard[MAX] = {"|◆A|","|◆2|","|◆3|","|◆4|","|◆5|","|◆6|","|◆7|","|◆8|","|◆9|","|◆10|","|◆J|","|◆Q|","|◆K|",
											"|♠A|","|♠2|","|♠3|","|♠4|","|♠5|","|♠6|","|♠7|","|♠8|","|♠9|","|♠10|","|♠J|","|♠Q|","|♠K|",
											"|♥A|","|♥2|","|♥3|","|♥4|","|♥5|","|♥6|","|♥7|","|♥8|","|♥9|","|♥10|","|♥J|","|♥Q|","|♥K|",
											"|♣A|","|♣2|","|♣3|","|♣4|","|♣5|","|♣6|","|♣7|","|♣8|","|♣9|","|♣10|","|♣J|","|♣Q|","|♣K|"};	
							Pcard realcard[MAX];	
	
							Board board;
							Player player;					
							board.Shuffle(realcard, fakecard);
							board.ShowBoard(realcard);
						    gotoXY(50,1); cout << "싱글모드";
							util.TimeCalc();
							util.PlayTime(0);						
							board.HideCard(); 
							player.PlayerCollectionBoard(num);
						    gotoXY(50,1); cout << "싱글모드";
							while(1)
						    {
						    	while(1)
						    	{													
							    gotoXY(5,3); cout << "0~51사이의 숫자를 입력해주세요:";							
							    erase.erase(36,3);
							    fflush(stdin);
							    gotoXY(36,3); cin >> Select;
								erase.erase(5,5);	
								if(Select < 52)
								    {
								    	break;
									}
									else
									{
										gotoXY(5,4); cout << "다시 입력해주세요";
									}
									getch();
									erase.erase(5,4);
								}
								board.SelectCard(realcard, Select);
								if ( player.CardMove(realcard, Select, 1) == 1 )
								{
									gotoXY(5,5); cout << "중복입니다.";
								}
								board.DeleteCard(realcard, Select);
								if(player.winnerJudge() == 1)
								{
									system("cls");
									gotoXY(50,14); cout << "클리어하셨습니다!!"; 
									gotoXY(48,15); cout << "클리어타임은 " << util.PlayTime(1) << "초 입니다.";
									getch();
									break;
								}
							}

						}
						
							break;					
						case 2:
							{
							num = 2;
							tern = 1; 
							playtern = 1;
							gotoXY(50,15); cout << "멀티모드(2인)을 시작합니다.";
							Pcard fakecard[MAX] = {"|◆A|","|◆2|","|◆3|","|◆4|","|◆5|","|◆6|","|◆7|","|◆8|","|◆9|","|◆10|","|◆J|","|◆Q|","|◆K|",
											"|♠A|","|♠2|","|♠3|","|♠4|","|♠5|","|♠6|","|♠7|","|♠8|","|♠9|","|♠10|","|♠J|","|♠Q|","|♠K|",
											"|♥A|","|♥2|","|♥3|","|♥4|","|♥5|","|♥6|","|♥7|","|♥8|","|♥9|","|♥10|","|♥J|","|♥Q|","|♥K|",
											"|♣A|","|♣2|","|♣3|","|♣4|","|♣5|","|♣6|","|♣7|","|♣8|","|♣9|","|♣10|","|♣J|","|♣Q|","|♣K|"};	
							Pcard realcard[MAX];
							
							Board board;
							Player player[2];
							board.Shuffle(realcard, fakecard);
							board.ShowBoard(realcard);
							util.TimeCalc();
							
							board.HideCard();
							player[0].PlayerCollectionBoard(2);						
							while(1)
							{				
								if( tern == 3)
								{
									tern = 1;
								}
								gotoXY(0,0); cout << "총 진행턴 : " << playtern << " 플레이어 턴 : " << tern << " player";
								while(1)
								{
								gotoXY(45,27); cout << "0~51사이의 숫자를 입력해주세요:";
							    erase.erase(76,27);
								fflush(stdin);
								gotoXY(76,27); cin >> Select;					
								erase.erase(45,28);						
								if(Select < 52 && realcard[Select].Exist != -1)
								    {
								    	break;
									}
									else
									{
										gotoXY(45,28); cout << "다시 입력해주세요";
									}
								}
								board.SelectCard(realcard, Select);
								if ( player[tern-1].CardMove(realcard, Select, tern) == 1 )
								{
									gotoXY(45,28); cout << "중복입니다.";
								}
								board.DeleteCard(realcard, Select);
								if(player[tern-1].winnerJudge() == 1)
								{
									system("cls");
									gotoXY(50,14); cout << "클리어하셨습니다!!"; 
									gotoXY(48,15); cout << "승자는 Player" << tern << "님 입니다."; 
									getch();
									break;
								}
								tern++;
								playtern++;																			
							}	
							}																
							break;
						case 3:
							{
							num = 3;
							tern = 1;
							playtern = 1;
							gotoXY(50,15); cout << "멀티모드(3인)을 시작합니다.";
							Pcard fakecard[MAX] = {"|◆A|","|◆2|","|◆3|","|◆4|","|◆5|","|◆6|","|◆7|","|◆8|","|◆9|","|◆10|","|◆J|","|◆Q|","|◆K|",
											"|♠A|","|♠2|","|♠3|","|♠4|","|♠5|","|♠6|","|♠7|","|♠8|","|♠9|","|♠10|","|♠J|","|♠Q|","|♠K|",
											"|♥A|","|♥2|","|♥3|","|♥4|","|♥5|","|♥6|","|♥7|","|♥8|","|♥9|","|♥10|","|♥J|","|♥Q|","|♥K|",
											"|♣A|","|♣2|","|♣3|","|♣4|","|♣5|","|♣6|","|♣7|","|♣8|","|♣9|","|♣10|","|♣J|","|♣Q|","|♣K|"};	
							Pcard realcard[MAX];
							
							Board board;
							Player player[3];
							board.Shuffle(realcard, fakecard);
							board.ShowBoard(realcard);
							util.TimeCalc();
							
							board.HideCard();
							player[0].PlayerCollectionBoard(3);						
							while(1)
							{				
								if( tern == 4)
								{
									tern = 1;
								}
								gotoXY(0,0); cout << "총 진행턴 : " << playtern << " 플레이어 턴 : " << tern << " player";
								while(1)
								{
								gotoXY(45,27); cout << "0~51사이의 숫자를 입력해주세요:";
							    erase.erase(76,27);
								fflush(stdin);
								gotoXY(76,27); cin >> Select;					
								erase.erase(45,28);						
								if(Select < 52 && realcard[Select].Exist != -1)
								    {
								    	break;
									}
									else
									{
										gotoXY(45,28); cout << "다시 입력해주세요";
									}
								}
								board.SelectCard(realcard, Select);
								if ( player[tern-1].CardMove(realcard, Select, tern) == 1 )
								{
									gotoXY(45,28); cout << "중복입니다.";
								}
								board.DeleteCard(realcard, Select);
								if(player[tern-1].winnerJudge() == 1)
								{
									system("cls");
									gotoXY(50,14); cout << "클리어하셨습니다!!"; 
									gotoXY(48,15); cout << "승자는 Player" << tern << "님 입니다."; 
									getch();
									break;
								}
								tern++;
								playtern++;																			
							}	
							}																
						break;
						case 4:
							{
							num = 4;
							tern = 1;
							playtern = 1;							
							gotoXY(50,15); cout << "멀티모드(3인)을 시작합니다.";
							Pcard fakecard[MAX] = {"|◆A|","|◆2|","|◆3|","|◆4|","|◆5|","|◆6|","|◆7|","|◆8|","|◆9|","|◆10|","|◆J|","|◆Q|","|◆K|",
											"|♠A|","|♠2|","|♠3|","|♠4|","|♠5|","|♠6|","|♠7|","|♠8|","|♠9|","|♠10|","|♠J|","|♠Q|","|♠K|",
											"|♥A|","|♥2|","|♥3|","|♥4|","|♥5|","|♥6|","|♥7|","|♥8|","|♥9|","|♥10|","|♥J|","|♥Q|","|♥K|",
											"|♣A|","|♣2|","|♣3|","|♣4|","|♣5|","|♣6|","|♣7|","|♣8|","|♣9|","|♣10|","|♣J|","|♣Q|","|♣K|"};	
							Pcard realcard[MAX];
							
							Board board;
							Player player[4];
							board.Shuffle(realcard, fakecard);
							board.ShowBoard(realcard);
							util.TimeCalc();
							
							board.HideCard();
							player[0].PlayerCollectionBoard(4);						
							while(1)
							{				
								if( tern == 5)
								{
									tern = 1;
								}
								gotoXY(0,0); cout << "총 진행턴 : " << playtern << " 플레이어 턴 : " << tern << " player";
								while(1)
								{
								gotoXY(45,27); cout << "0~51사이의 숫자를 입력해주세요:";
							    erase.erase(76,27);
								fflush(stdin);
								gotoXY(76,27); cin >> Select;					
								erase.erase(45,28);						
								if(Select < 52 && realcard[Select].Exist != -1)
								    {
								    	break;
									}
									else
									{
										gotoXY(45,28); cout << "다시 입력해주세요";
									}
								}
								board.SelectCard(realcard, Select);
								if ( player[tern-1].CardMove(realcard, Select, tern) == 1 )
								{
									gotoXY(45,28); cout << "중복입니다.";
								}
								board.DeleteCard(realcard, Select);
								if(player[tern-1].winnerJudge() == 1)
								{
									system("cls");
									gotoXY(50,14); cout << "클리어하셨습니다!!"; 
									gotoXY(48,15); cout << "승자는 Player" << tern << "님 입니다."; 
									getch();
									break;
								}
								tern++;
								playtern++;																			
							}	
							}																
						break;	
						case 5:
							break;									
					}
					break;
			}
			case 2:
				menu.HowToPlay();
				util.PushSpace();
				break;
			case 3:
				menu.Rank();
				util.PushSpace();
				break;
			case 4:
				menu.GameCreator();
				util.PushSpace();
				break;
			case 5:
				if(menu.GameExit() == 1 )
				{
					return 0;
				}
				else if(menu.GameExit() == 0)
					break;
		}
	}	
}

