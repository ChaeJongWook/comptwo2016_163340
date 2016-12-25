#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <string>
#include <sstream>


#define UP 72
#define DOWN 80
#define ENTER 13
#define SPACE 32
#define NUMBER 13
#define TYPE 4
#define MAX 52
using namespace std; 

const int titlexpos = 52;
const int titleypos = 5;
const int buttonxpos = 56;
const int buttonypos = 12;


class Utility {
	public:
		void CursorVisible(bool blnCursorVisible);
		void TimeCalc();
		float PlayTime(int i);
		void PushSpace();
	protected:
		void gotoxy(int x ,int y);
};

class Menu : public Utility {
	public:
		int Main();
		int GameStart();
		void HowToPlay();
		void Rank();
		void GameCreator();
		int GameExit();		
};

class Arrow : protected Utility {
	public:
		int ArrowControl(int Num)
		{
			
			char Arrow;
			int ypos = buttonypos;
			while(1)
			{
				gotoxy(buttonxpos-4,ypos); cout<<"¢º";
				Arrow = getch();
				if( Arrow == UP && ypos > 12)
				{
					gotoxy(buttonxpos-4,ypos); cout << " ";
					ypos = ypos - 2;
					gotoxy(buttonxpos-4,ypos); cout << "¢º";
				}
				else if( Arrow == DOWN && ypos < 12+(Num-1)*2)
				{
					gotoxy(buttonxpos-4,ypos); cout << " ";
					ypos = ypos + 2;
					gotoxy(buttonxpos-4,ypos); cout << "¢º";					
				}
				else if( Arrow == ENTER )
				{
					return ypos/2-5;
				}
			}
		};
};

class Pcard : protected Utility {
		public:
		char Name[7];
		Pcard() { Name[0] = 0; }
		Pcard(const char *Pname)
		{
			strcpy(Name,Pname);
		}
		
		int GetNumber() const
		{
			if( isdigit(Name[3]) && Name[3] != '1' && Name[4] != '0' )
			{
				return Name[3] - '0';
			}
			else if( Name[3] == 'J')
			{
				return 11;
			}
			else if( Name[3] == 'Q')
			{
				return 12;
			}
			else if( Name[3] == 'K')
			{
				return 13;
			}
			else if( Name[3] == 'A')
			{
				return 1;
			}
			if( Name[3] == '1' && Name[4] == '0')
			{
				return 10;
			}
		}

		int Exist;

};

class Board : public Pcard {
	public:
		void Shuffle(Pcard *realcard, Pcard *fakecard) 
		{
			int overlap[MAX];
			int i,j;
			for( i = 0 ; i < MAX; i++)
			{
				overlap[i] = rand() % MAX;
				for( j = 0 ; j < i ; j++)
				{
					if( overlap[j] == overlap[i] )
					{
						i--;
						break;
					}
				}
			}
			for( i = 0 ; i < MAX ; i++)
			{
				realcard[i] = fakecard[overlap[i]];
			}
			for( i = 0 ; i < MAX ; i++)
			{
				realcard[i].Exist = 1;
			}
			
		}
		void ShowBoard(Pcard *realcard)
		{
			int x = 0;
			int y = 10;
			int a = 22,b = 8;
			system("cls");
			for( x = 0 ; x < MAX ; x++)
			{
				gotoxy(a,b); cout << realcard[x].Name;
				gotoxy(a+1,b+1); cout << "[" << x << "]";
				a = a + 7;
				if((x+1) % 11 == 0 )
				{
					b = b+3;
					a = 22;
				}
			}
		}
		void HideCard()
		{
			int x = 0;
			int a = 22, b = 8;

			for ( x = 0 ; x < MAX ; x++)
			{
				gotoxy(a,b); cout << "|???|";
				gotoxy(a+1,b+1); cout << "[" << x << "]";
				a = a + 7;
				if((x+1) % 11 == 0 )
				{
					b = b+3;
					a = 22;
				}
			}				
		}
		void SelectCard(Pcard *realcard, int Select)
		{
			int x = 0;
			int a = 22, b = 8;

			for ( x = 0 ; x < MAX ; x++)
			{
				if( realcard[x].Exist != -1)
				{
				gotoxy(a,b); cout << "|???|";
				gotoxy(a+1,b+1); cout << "[" << x << "]";
				
				}
				
				if( x == Select)
				{
					gotoxy(a,b); cout << realcard[x].Name;
				}
				a = a + 7;				
				if((x+1) % 11 == 0 )
				{
					b = b+3;
					a = 22;
				}
			}
		}
		void DeleteCard(Pcard *realcard,int Select)
		{
			int x = 0;
			int a = 22, b = 8;

			for ( x = 0 ; x < MAX ; x++)
			{
				if( realcard[x].Exist == -1)
				{
				gotoxy(a,b); cout << "| X |";
				gotoxy(a+1,b+1); cout << "    ";
				}
				a = a + 7;				
				if((x+1) % 11 == 0 )
				{
					b = b+3;
					a = 22;
				}
			}
		}
};

class Player : public Pcard {
	private:
		int Collection[13];
	public:
		Player()
		{
			int i;
			for(i = 0 ; i < 13 ; i++)
			{
				Collection[i] = 0;
			}
		}
		void PlayerCollectionBoard(int Player)
		{
			int i,j,count = 0;
			if(Player == 1 )
			{
				gotoxy(20,24); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
				for( i = 20; i < 99 ; i = i+6)
				{
					gotoxy(i,25); cout << "|";
				}
				gotoxy(20,26); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á1P";
			}
			else if( Player == 2)
			{
				gotoxy(20,24); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
				for( i = 20; i < 99 ; i = i+6)
				{
					gotoxy(i,25); cout << "|";
				}
				gotoxy(20,26); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á1P";
				
				gotoxy(20,2); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
				for( i = 20; i < 99 ; i = i+6)
				{
					gotoxy(i,3); cout << "|";
				}
				gotoxy(20,4); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á2P";								
			}
			else if( Player == 3)
			{
				i = 2;
				j = 7;
				while( count < 75)
				{
					if( i == 12)
					{
						i = 2;
						j++;
					}
					if( j == 7 || j == 21)
					{
					gotoxy(i,j); cout << "¡á";
					}
					else if( i == 2 || i == 10)
					{
						gotoxy(i,j); cout << "¡á";
					}
					i = i+2;
					count++;
				}
				gotoxy(20,24); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
				for( i = 20; i < 99 ; i = i+6)
				{
					gotoxy(i,25); cout << "|";
				}
				gotoxy(20,26); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
				
				gotoxy(20,2); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
				for( i = 20; i < 99 ; i = i+6)
				{
					gotoxy(i,3); cout << "|";
				}
				gotoxy(20,4); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";						
			}
			else if( Player == 4)
			{
				i = 2;
				j = 7;
				while( count < 75)
				{
					if( i == 12)
					{
						i = 2;
						j++;
					}
					if( j == 7 || j == 21)
					{
					gotoxy(i,j); cout << "¡á";
					}
					else if( i == 2 || i == 10)
					{
						gotoxy(i,j); cout << "¡á";
					}
					i = i+2;
					count++;
				}
				i = 110;
				j = 7;
				count = 0;
				while( count < 75)
				{
					if( i == 120)
					{
						i = 110;
						j++;
					}
					if( j == 7 || j == 21)
					{
					gotoxy(i,j); cout << "¡á";
					}
					else if( i == 110 || i == 118)
					{
						gotoxy(i,j); cout << "¡á";
					}
					i = i+2;
					count++;
				}				
				gotoxy(20,24); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
				
				for( i = 20; i < 99 ; i = i+6)
				{
					gotoxy(i,25); cout << "|";
				}
				gotoxy(20,26); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
				gotoxy(20,2); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";
				
				for( i = 20; i < 99 ; i = i+6)
				{
					gotoxy(i,3); cout << "|";
				}
				gotoxy(20,4); cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á";						
			}
		}
		int CardMove(Pcard *realcard, int Select, int tern)
		{
			int i;
			for(i = 0 ; i < 13 ; i++)
			{
				if( Collection[i] == realcard[Select].GetNumber())
				{
					return 1;
				}
			}
			if( realcard[Select].GetNumber() == 1)
			{
				Collection[0] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
				gotoxy(21,25); cout << realcard[Select].Name;		
				}
				else if( tern == 2)
				{
				gotoxy(21,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,8); cout << realcard[Select].Name;
				}
				else if( tern == 4)
				{
				gotoxy(112,8); cout << realcard[Select].Name;
				}				
				return 0;
			}
			else if( realcard[Select].GetNumber() == 2)
			{
				Collection[1] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
					gotoxy(27,25); cout << realcard[Select].Name;
				}
				else if( tern == 2)
				{
					gotoxy(27,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,9); cout << realcard[Select].Name;
				}	
				else if( tern == 4)
				{
				gotoxy(112,9); cout << realcard[Select].Name;
				}						
				return 0;	
			}
			else if( realcard[Select].GetNumber() == 3)
			{
				Collection[2] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
				gotoxy(33,25); cout << realcard[Select].Name;
				}
				else if( tern == 2)
				{
				gotoxy(33,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,10); cout << realcard[Select].Name;
				}	
				else if( tern == 4)
				{
				gotoxy(112,10); cout << realcard[Select].Name;
				}									
				return 0;	
			}
			else if( realcard[Select].GetNumber() == 4)
			{
				Collection[3] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
				gotoxy(39,25); cout << realcard[Select].Name;
				}
				else if( tern == 2)
				{
				gotoxy(39,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,11); cout << realcard[Select].Name;
				}				
				else if( tern == 4)
				{
				gotoxy(112,11); cout << realcard[Select].Name;
				}		
				return 0;	
			}
			else if( realcard[Select].GetNumber() == 5)
			{
				Collection[4] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
				gotoxy(45,25); cout << realcard[Select].Name;
				}
				else if( tern == 2)
				{
				gotoxy(45,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,12); cout << realcard[Select].Name;
				}			
				else if( tern == 4)
				{
				gotoxy(112,12); cout << realcard[Select].Name;
				}							
				return 0;	
			}
			else if( realcard[Select].GetNumber() == 6)
			{
				Collection[5] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
				gotoxy(51,25); cout << realcard[Select].Name;
				}
				else if( tern == 2)
				{
				gotoxy(51,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,13); cout << realcard[Select].Name;
				}			
				else if( tern == 4)
				{
				gotoxy(112,13); cout << realcard[Select].Name;
				}							
				return 0;	
			}
			else if( realcard[Select].GetNumber() == 7)
			{
				Collection[6] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
				gotoxy(57,25); cout << realcard[Select].Name;
				}
				else if( tern == 2)
				{
				gotoxy(57,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,14); cout << realcard[Select].Name;
				}			
				else if( tern == 4)
				{
				gotoxy(112,14); cout << realcard[Select].Name;
				}							
				return 0;	
			}
			else if( realcard[Select].GetNumber() == 8)
			{
				Collection[7] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
				gotoxy(63,25); cout << realcard[Select].Name;
				}
				else if( tern == 2)
				{
				gotoxy(63,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,15); cout << realcard[Select].Name;
				}			
				else if( tern == 4)
				{
				gotoxy(112,15); cout << realcard[Select].Name;
				}							
				return 0;	
			}
			else if( realcard[Select].GetNumber() == 9)
			{
				Collection[8] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
				gotoxy(69,25); cout << realcard[Select].Name;
				}
				else if( tern == 2)
				{
				gotoxy(69,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,16); cout << realcard[Select].Name;
				}			
				else if( tern == 4)
				{
				gotoxy(112,16); cout << realcard[Select].Name;
				}							
				return 0;	
			}
			else if( realcard[Select].GetNumber() == 10)
			{
				Collection[9] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
				gotoxy(75,25); cout << realcard[Select].Name;
				}
				else if( tern == 2)
				{
				gotoxy(75,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,17); cout << realcard[Select].Name;
				}			
				else if( tern == 4)
				{
				gotoxy(112,17); cout << realcard[Select].Name;
				}							
				return 0;	
			}
			else if( realcard[Select].GetNumber() == 11)
			{
				Collection[10] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
				gotoxy(81,25); cout << realcard[Select].Name;
				}
				else if( tern == 2)
				{
				gotoxy(81,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,18); cout << realcard[Select].Name;
				}			
				else if( tern == 4)
				{
				gotoxy(112,18); cout << realcard[Select].Name;
				}							
				return 0;	
			}
			else if( realcard[Select].GetNumber() == 12)
			{
				Collection[11] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
				gotoxy(87,25); cout << realcard[Select].Name;
				}
				else if( tern == 2)
				{
				gotoxy(87,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,19); cout << realcard[Select].Name;
				}
				else if( tern == 4)
				{
				gotoxy(112,19); cout << realcard[Select].Name;
				}						
				return 0;	
			}
			else if( realcard[Select].GetNumber() == 13)
			{
				Collection[12] = realcard[Select].GetNumber();
				realcard[Select].Exist = -1;
				if( tern == 1)
				{
				gotoxy(93,25); cout << realcard[Select].Name;
				}
				else if( tern == 2)
				{
				gotoxy(93,3); cout << realcard[Select].Name;
				}
				else if( tern == 3)
				{
				gotoxy(4,20); cout << realcard[Select].Name;
				}			
				else if( tern == 4)
				{
				gotoxy(112,20); cout << realcard[Select].Name;
				}							
				return 0;	
			}	
		}
		int winnerJudge()
		{
			int i,j;
			for(i = 0; i < 13 ;i++)
			{
				for( j = 0 ; j < 13 ; j ++)
				{
					if( Collection[i] == 0)
					{
						return 0;
					}
				}
			}
			return 1;
		}		
};

class Erase : protected Utility {
	public:
		void erase(int x, int y)
		{
			gotoxy(x,y); cout << "                ";
		}
};

