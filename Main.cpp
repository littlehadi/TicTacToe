#include <stdio.h>
#include <iostream>
using namespace std;



char board[3][3] = {{'1','2', '3'},{'4','5','6'}, {'7','8','9'}}; // Create the board

void drawBoard()
{ 
	cout << " " << board[0][0] << " | " << board[0][1] <<  " | " << board[0][2] << endl;// Create the first row with the bar

}

int main () {
	cout << "Hello World \n";

  return 0;
}
