#include <stdio.h>
#include <iostream>
using namespace std;


// Create the board
char board[3][3] = {{'1','2', '3'},{'4','5','6'}, {'7','8','9'}}; 

void drawBoard()
{ 
	// Create the vertical and horizontal lines
	cout << " " << board[0][0] << " | " << board[0][1] <<  " | " << board[0][2] << endl;
	cout << "-----------\n";
	cout << " " << board[1][0] << " | " << board[1][1] <<  " | " << board[1][2] << endl;
	cout << "-----------\n";
	cout << " " << board[2][0] << " | " << board[2][1] <<  " | " << board[2][2] << endl;
	cout << "-----------\n";

}

int main () {
	cout << "Hello World \n";
	drawBoard();

  return 0;
}
