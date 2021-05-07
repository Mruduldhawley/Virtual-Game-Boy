#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
int u;
static int d1,d2;
using namespace std;
void infer();
void infer()
{
		
cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
cout<<"                                        player 1 win the game\n\n";
cout<<"_________________________________________________________________________________________________________________\n";
cout<<"                                                 WINNER  \n";
cout<<"_________________________________________________________________________________________________________________\n";
cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
u=0;

}
void battle();
void hang();
void reveal(int, int); 
void create_mine_positions(); 
void cell_number(); 
void create_table(); 
void open_cell(); 
void game(); 
void print_table(char); 

char table[10][10]; 
char table_mine_positions[10][10]; 
char symbol;
int flag_counter=0;
int mines_flagged_counter=0;
bool end_game_lose=false;
time_t time_since_epoch = time(0);
time_t game_time;

void cell_number(int i1,int j2)
{
if(i1>=0&&i1<10&&j2>=0&&j2<10&&table_mine_positions[i1][j2]!='X')
table_mine_positions[i1][j2]++;
}

void create_mine_positions()
{
int counter=0;
srand(time(NULL));

for(int i1=0;i1<10;i1++)
        for(int j2=0;j2<10;j2++)
            table_mine_positions[i1][j2]='0';

        int i1=0;
        int j2=0;
 while(counter<10)
    {
        int i1=rand()%10;
        int j2=rand()%10;
        if(table_mine_positions[i1][j2]=='0'){
            table_mine_positions[i1][j2]='X';

            cell_number(i1-1,j2);
            cell_number(i1+1,j2);
            cell_number(i1,j2-1);
            cell_number(i1,j2+1);
            cell_number(i1-1,j2-1);
            cell_number(i1-1,j2+1);
            cell_number(i1+1,j2-1);
            cell_number(i1+1,j2+1);
            counter++;
        }
    }
}

void create_table()
{
    for(int i1=0;i1<10;i1++)
        for(int j2=0;j2<10;j2++)
            table[i1][j2]='*';
}

void print_table(char arr[10][10])
{
    cout<<"    ";
    for(int i1=0;i1<10;i1++)
        cout<<setw(3)<<i1;

    cout<<endl<<"  ";
    for(int i1=0;i1<32;i1++)
        cout<<"_";
        cout<<endl;

    for(int i1=0;i1<10;i1++){
            cout<<setw(3)<<i1<<"|";
        for(int j2=0;j2<10;j2++)
            cout<<setw(3)<<arr[i1][j2];
            cout<<endl;
    }
}

void open_cell()
{
int i1,j2;

do
cin>>i1>>j2;
while(i1<0||i1>9||j2<0||j2>9);

if(table_mine_positions[i1][j2]=='X')
    {
        table[i1][j2]='X';
        end_game_lose=true;

        for(int i1=0;i1<10;i1++)
            for(int j2=0;j2<10;j2++)
                if(table_mine_positions[i1][j2]=='X')
                    table[i1][j2]='X';
    }
    else
        reveal(i1,j2);
}

void place_or_remove_flag()
{
int i1,j2;
do
cin>>i1>>j2;
while(i1<0||i1>9||j2<0||j2>9);

if (table[i1][j2]=='*')
    {
    table[i1][j2]='F';
    flag_counter++;

    if(table_mine_positions[i1][j2]=='X')
        mines_flagged_counter++;
    }

else if (table[i1][j2]=='F')
    {
    table[i1][j2]='*';
    flag_counter--;
    if(table_mine_positions[i1][j2]=='X')
        mines_flagged_counter--;
    }
}

void input_symbol()
{
   cin>>symbol;
    switch (symbol){
    case 'o' : open_cell(); break;
    case 'f' : place_or_remove_flag(); break;
    default  : input_symbol();
    }
}

void reveal(int i1,int j2)
{
if (table[i1][j2]=='*'&&table_mine_positions[i1][j2]!='X'&&i1>=0&&i1<10&&j2>=0&&j2<10)
    {
    table[i1][j2]=table_mine_positions[i1][j2];

    if(table_mine_positions[i1][j2]=='0')
        {
        reveal(i1,j2-1);
        reveal(i1,j2+1);
        reveal(i1-1,j2-1);
        reveal(i1+1,j2-1);
        reveal(i1+1,j2+1);
        reveal(i1-1,j2+1);
        reveal(i1-1,j2);
        reveal(i1+1,j2);
        }
    }
}

bool end_game_win_check()
{
    if(flag_counter==10&&mines_flagged_counter==10)
    return 1;
    else
    return 0;
}

void game()
{
    create_table();
    create_mine_positions();

    while(!end_game_lose&&!end_game_win_check())
    {
    game_time=time(0);
    print_table(table);
    cout<<endl<<"Flags:"<<flag_counter<<endl;
    cout<<"Time:"<<game_time-time_since_epoch<<endl;
    input_symbol();
    }

    if(end_game_lose){
    print_table(table);
    cout<<endl<<"GAME OVER"<<endl;
    }

    if(end_game_win_check())
    cout<<"Time to complete:"<<game_time-time_since_epoch<<endl;
    cout<<endl<<"YOU WIN!"<<endl;
}
int main()
{
	cout<<"\n\n\n\n\n\n";
	cout<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
	cout<<"III*IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
	cout<<"IIII * IIIIIIIIIIII * III * * * * * *III * * * *IIIII * * * * *III * III * IIIIIII * IIIIIIII * IIIIIIIIIII\n";
	cout<<"IIIII * IIIIIIIII * IIIIIIIIII * IIIIIII * III * IIIIIIII * IIIIII * III * IIIIII * * IIIIIII * IIIIIIIIIII\n";
	cout<<"IIIIII * IIIIII * IIIIIIIIIIII * IIIIIII * * * IIIIIIIIII * IIIIII * III * IIII  * ** * IIIII * IIIIIIIIIII\n";
	cout<<"IIIIIIII * II * IIIIIIIIIIIIII * IIIIIII * II* IIIIIIIIII * IIIIII * III * III  * IIIII* IIII * IIIIIIIIIII\n";
	cout<<"IIIIIIIIII * IIIIIIIIIIIII * * * * * III * II * IIIIIIIII * IIIIII * * * * III * IIIIIII* III * * * * *IIII\n";
	cout<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
	cout<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
	cout<<"                                                 GAME-BOY                                                  \n";
    cout<<"\n\n\n";

    cout<<"ENTER THE GAME YOU WANT TO PLAY\n\n";
	cout<<"1.BOATSINK\n";
	cout<<"2.MINESWEEPER\n";
	cout<<"3.HANGMAN\n\n\n\n";
	cout<<"                                                 PRESS 4 TO EXIT\n\n\n";	
	
	int num;
	int loop=1;
while(loop)

{
	
	cout<<"\n\n\n\n\n\n";
	cout<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
	cout<<"III*IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
	cout<<"IIII * IIIIIIIIIIII * III * * * * * *III * * * *IIIII * * * * *III * III * IIIIIII * IIIIIIII * IIIIIIIIIII\n";
	cout<<"IIIII * IIIIIIIII * IIIIIIIIII * IIIIIII * III * IIIIIIII * IIIIII * III * IIIIII * * IIIIIII * IIIIIIIIIII\n";
	cout<<"IIIIII * IIIIII * IIIIIIIIIIII * IIIIIII * * * IIIIIIIIII * IIIIII * III * IIII  * ** * IIIII * IIIIIIIIIII\n";
	cout<<"IIIIIIII * II * IIIIIIIIIIIIII * IIIIIII * II* IIIIIIIIII * IIIIII * III * III  * IIIII* IIII * IIIIIIIIIII\n";
	cout<<"IIIIIIIIII * IIIIIIIIIIIII * * * * * III * II * IIIIIIIII * IIIIII * * * * III * IIIIIII* III * * * * *IIII\n";
	cout<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
	cout<<"IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n";
	cout<<"                                                 GAME-BOY                                                  \n";
    cout<<"\n\n\n";

    cout<<"ENTER THE GAME YOU WANT TO PLAY\n\n";
	cout<<"1.BOATSINK\n";
	cout<<"2.MINESWEEPER\n";
	cout<<"3.HANGMAN\n\n\n\n";
	cout<<"                                                 PRESS 4 TO EXIT\n\n\n";	
	
	cout<<"enter your choise\n";
	cin>>num;
	system("CLS");
	switch (num)
	{
	case 2:
	{
cout
<<"Rules:"
<<endl<<"Enter 'o' , then enter value of i and j to open cell[i][j]."
<<endl<<"Enter 'f' ,then enter value of i and j to place "
<<"or remove flag on cell [i][j]."
<<endl<<endl;

game();
    break;
    }
    case 3:
    {
	hang();
	break;
			}
	case 1:
	{
	battle();
	break;	
				}
	case 4:
	{
		loop=0;
							}						
return 0;
}
}
}
void hang()
{
 
    const int MAX_WRONG = 8;  
    vector<string> words; 
    words.push_back("pizza");
    words.push_back("pikachu");
    words.push_back("awkward");
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];            
    int wrong = 0;                               
    string soFar(THE_WORD.size(), '-');          
    string used = "";                            
    cout << "\t\t\tWelcome to Hangman!";
	cout<<"\n\t\t\t-------------------\n\n";
	cout<<"You have exactly " <<(MAX_WRONG - wrong)<< " guesses, goodluck!";
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "So far, the word is: " << soFar << endl;
        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        used += guess;
        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "That's right! " << guess << " is in the word.\n";
            for (unsigned int i3 = 0; i3 < THE_WORD.length(); ++i3)
			{
                if (THE_WORD[i3] == guess)
				{
                    soFar[i3] = guess;
				}
			}
        }
        else
        {
			++wrong;
            cout << "Sorry, " << guess << " isn't in the word.\n";
			cout<<"You have " <<(MAX_WRONG - wrong)<< " guesses left.\n";
     
        }
    }
    if (wrong == MAX_WRONG)
	{
        cout << "Game over, you've been hanged!";
		
	}
    else
	{
        cout << "Congratulation! You've successfully guessed the secret word!";
	}
    cout << "\nThe word was " << THE_WORD<<"\n\n";
	int rate;
	cout<<"Please take a moment of your time and rate the game\n";
	cout<<"1 - It was fun!\n";
	cout<<"2 - It was ok\n";
	cout<<"3 - It was bad\n";
	cin>>rate;
	switch (rate)
	{
	case 1: cout<<"We are so glad to hear that! thanks for the positive feedback!\n"; break;
	case 2: cout<<"We'll do better next time, thanks for your feedback!\n"; break;
	case 3: cout<<"We are terribly sorry about that, we'll do better next time\n"; break;
	default: cout<<"Good-bye\n"; break; 
	}
	system("pause");
    
}

void battle()
{
	cout<<"RULES:\n\n\n";
	cout<<"  -It is a multiplayer game\nPlayer 1 have to first place his ship in zone 1 i.e from (0,0) to (1,3)\n\n";
	cout<<"  -Player 2 will now place his ship in zone 2 i.e from (2,0) to (3,3)\n\n";
	cout<<"  -Placing of the ships should be done under  _Privacy_ \n\n";
	cout<<"  -Now each player will get a turn to find opponents ship and to attack it\n\n";
	cout<<"  -The HP of the ship is 150\n\n";
	cout<<"  -Therefour, Damage of 150 or more will lead to -VICTORY-\n\n\n";
	system("pause");
	system("CLS");



	cout<<"_____________________________________________________________\n";
	cout<<"                       BOAT SINK\n";
	cout<<"_____________________________________________________________\n";
	
	cout<<"\n\n\n\n\n\n";
	
	
	
int i,j,a,b;	
	int att;
	
	cout<<"     * * * *\n";
cout<<"     * * * *\n";
cout<<"------------------\n";
cout<<"     * * * *\n";
cout<<"     * * * *\n";	

cout<<"\n\n";
cout<<"welecome Player 1 enter you boat between (0,0) to (1,4)\n";
cin>>i>>j; 
int pos1,pos2;
pos1=i;
pos2=j;
if(i>1 && j>4)
cout<<"invalid input\n";
system("CLS");





	cout<<"_____________________________________________________________\n";
	cout<<"                       BOAT SINK\n";
	cout<<"_____________________________________________________________\n";
	
	cout<<"\n\n\n\n\n\n";
	
	
	
	cout<<"     * * * *\n";
cout<<"     * * * *\n";
cout<<"------------------\n";
cout<<"     * * * *\n";
cout<<"     * * * *\n";	

	cout<<"\n\n";

cout<<"welecome Player 2 enter you boat between (2,0) to (3,4)\n";
cin>>a>>b;
if(a<2 && b>4)
cout<<"invalid input\n";

system("CLS");


int u=5;

while(u)
{




	cout<<"_____________________________________________________________\n";
	cout<<"                       BOAT SINK\n";
	cout<<"_____________________________________________________________\n";
	
	cout<<"\n\n\n\n\n\n";
	
	
	
	cout<<"     * * * *\n";
cout<<"     * * * *\n";
cout<<"------------------\n";
cout<<"     * * * *\n";
cout<<"     * * * *\n";	

int p,q,k,t,l;
cout<<"player 1 where you want to attack\n";
 cin>>p>>q;
 
 cout<<"\n\n";
 
 	cout<<"     * * * *\n";
cout<<"     * * * *\n";
cout<<"------------------\n";
cout<<"     * * * *\n";
cout<<"     * * * *\n";

cout<<"\n\n";
int r=2;


if(p==a && q==b)
{




	
cout<<"ship found\n\n";

cout<<"\n\n\n";
    for(k=0;k<4;k++)
    {
    			if(k==r)
		{
			cout<<"------------------\n";
		}
    
    	cout<<"    ";
    
    
    	for(l=0;l<4;l++)
    	{
    		if(k==a && l==b)
    		cout<<" $";
    		  		
    		else
    		cout<<" *";
    		
    		
		}
		
		cout<<"\n";
	
	}
cout<<"choose attack\n1.dark shot\n2.childs play\n3.dismantle\n";
cin>>att;

switch(att)
{
case 1:
          cout<<"sucessful hit damage inflicted 30HP\n\n\n";
           d1=30;
           break;


case 2:
            d1=75;
            cout<<"sucessful hit damage inflicted 75HP\n\n\n";
            break;

case 3:
            d1=60;
            cout<<"sucessful hit damage inflicted 60HP\n\n\n";
            break;   
}
}

if(p!=a)

{
      
cout<<"not found better luck next time\n\n\n\n\n\n";

}
if(q!=b)
{
      
cout<<"not found better luck next time\n\n\n\n\n\n";

}
int static gef;
gef+=d1;
int mat;
mat=gef;

if(mat>=150)
{
	cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
cout<<"                                        player 1 win the game\n\n";
cout<<"_________________________________________________________________________________________________________________\n";
cout<<"                                                 WINNER  \n";
cout<<"_________________________________________________________________________________________________________________\n";
cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
u=0;
}
if(u>1)
{



cout<<"                                                          $-player 2 ship\n\n";


    cout<<"________________________________________________________________________________________________________________________\n";
	cout<<"                                                 BOAT SINK\n";
	cout<<"________________________________________________________________________________________________________________________\n";
	
	cout<<"\n\n\n\n\n\n";
	
	
	
	cout<<"     * * * *\n";
cout<<"     * * * *\n";
cout<<"------------------\n";
cout<<"     * * * *\n";
cout<<"     * * * *\n";



int c1,c2;

cout<<"\n\n";

cout<<"Player 2 Lock and load on the location\n";

cin>>c1;

cin>>c2;

cout<<"\n\n\n\n";

int h;
if(c1==pos1 && c2==pos2)
{
	
	int g;
	
	int two=2;
	
	cout<<"ship found";
	
	cout<<"\n\n\n\n";
	
	for(g=0;g<4;g++)
	{
		
		if(g==two)
		{
			
			cout<<"------------------\n";
		}
		
		
		for(h=0;h<4;h++)
		{
			if(g==pos1 && h==pos2)
			{

			cout<<" &";
		    }
		    else
		    {
		    cout<<" *";	
			}
			
		}
		cout<<"\n";
	}
cout<<"choose attack\n1.dark shot\n2.childs play\n3.dismantle\n";
cin>>att;

switch(att)
{
case 1:
          cout<<"sucessful hit damage inflicted 30HP\n\n";
           d2=30;
           break;


case 2:
            d2=75;
            cout<<"sucessful hit damage inflicted 75HP\n\n";
            break;

case 3:
            d2=60;
            cout<<"sucessful hit damage inflicted 60HP\n\n";
            break;   
}
}
if(c1!=pos1)

{
      
cout<<"not found better luck next time\n\n\n\n\n\n";

}
if(c2!=pos2)
{
      
cout<<"not found better luck next time\n\n\n\n\n\n";

}

static int def;
def+=d2;
int gat;
gat=def;
if(gat>=150)
{
cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";		
cout<<"                                            player 2 win the game\n";
cout<<"________________________________________________________________________________________________________________________\n";
cout<<"                                                  WINNER  \n";
cout<<"________________________________________________________________________________________________________________________\n";
cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
u=0;
}
else
cout<<"\n";
}



}

system("pause");
system("CLS");
}







