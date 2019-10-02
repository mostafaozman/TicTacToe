#include <iostream>
#include <cstdlib>

using namespace std;

void draw(char* Ptr[3][3]); 
void clear(char* Ptr[3][3]);
bool checktie(char* Ptr[3][3]); 
int Xwins = 0; 
int Owins = 0; 

int main ()
{
  char board[3][3];
  char* boardPtr[3][3]; 
  char pos[2]; 
  char playx = 'X';
  char playo = 'O';
  bool playing = true; 

  for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
	{
	  boardPtr[x][y] = &board[x][y];
	}
    }


  cout << "Welcome to TicTacToe, this is a two player game. Please take turns inputting a position" << endl; 
  
  while (playing == true)
    {
      cout << "Please enter a character followed by a number to place your character" <<endl;
      cin.get(pos, 3);
      
      while ((pos[0] == 'a' || pos[0] == 'b' || pos[0] == 'c') || 
	     (pos[1] == '1' || pos[1] == '2' || pos[1] == '3') ||
	     !(board[(int)pos[1] - 'a'][(int)pos[0] - '1'] == ' '))
	{
	  playing = true; 
	  board[(int)pos[1] - 'a'][(int)pos[0] -'1'] = playx; 
	  draw(boardPtr); 
	}
      
    }

  clear(boardPtr);
  draw(boardPtr);

  return 0; 
}

void draw(char* Ptr[3][3])
{
  cout << " 1 2 3" << endl;
  cout << 'a'; 
  for (int i = 0; i < 3; i++)
    {
      cout << ' ' << *Ptr[0][i];
    }   
      cout << endl; 

      cout << 'b'; 
      for (int i = 0; i < 3; i++)
	{
	  cout << ' ' << *Ptr[1][i];
	}
      cout << endl; 

      cout << 'c'; 
      for (int i = 0; i < 3; i++)
	{
	  cout << ' ' << *Ptr[2][i];
	}
      cout << endl; 
}

void clear (char* Ptr[3][3])
{
  for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
	{
	  *Ptr[x][y] = ' '; 
	}
    }
}
  bool checktie (char* Ptr[3][3])
  {
    for (int x = 0; x < 3; x++)
      {
	for (int y = 0; y < 3; y++)
	  {
	    if( *Ptr[x][y] == ' ')
	      {
		return false;
	      }
	  }
      }
    return true; 
}
