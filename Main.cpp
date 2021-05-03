#include <stdio.h>
#include <iostream>
using namespace std;


// Create the board
char board[3][3] = {{'1','2', '3'},{'4','5','6'}, {'7','8','9'}}; 

char current_marker;
int current_player;

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

bool placeMarker(int slot) {
	int row = slot / 3;
	int col;

	// If slot is a multiple of 3
	if (slot % 3 == 0) {
		row =row -1;
		col = 2;
	}
	else {
		col = (slot % 3) -1;
	}
	if (board[row][col] != 'X' && board[row][col] != 'O' ) {
		board[row][col] = current_marker;
		return true;
	}
	else return false;
	//board[row][col] = current_marker;

}

//Check if we have a winner
char winner() {
	for (int i =0; i< 3; i++) {
		// check the rows
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return current_player;
		}
		// check the col
		if (board[0][1] == board[1][i] && board[1][i] == board[2][i]) {
			return current_player;
		}
	}

	//check the diagonal
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return current_player;
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		return current_player;
	}
	// If no one wins, return 0
	return 0;

}
// A function that swap the player and the marker in the game
void swap_player_and_marker() {
	
	if (current_marker == 'X') current_marker = 'O';
	else current_marker = 'X';
	

	if (current_player == 1) {
		current_player = 2;
	}
	else {
		current_player = 1;
	}
}


// creating the interface for the game
void game () {
	cout << '\n';
	cout << "Player one, choose your marker : "; 
	char marker_p1;
	cin >> marker_p1;
	current_player = 1;
	current_marker = marker_p1;

	/*cout << "Player two, choose your marker : "; 
	char marker_p2;
	cin >> marker_p2;
	current_player = 2;
*/
	drawBoard();

	int player_won;

	for (int i = 0; i < 9; i++) {
		cout << "It's player " << current_player << "'s turn. Enter your slot : ";
		int slot;
		cin >> slot;

		if (slot < 1 || slot > 9){
			cout << "That slot is invalid! try another slot!";
			 i--; 
			 continue;
		}
		if (!placeMarker(slot)) {
			cout << "That slot is occupied! try another slot!";
			 i--; 
			 continue;
		}

		drawBoard();
		player_won = winner();

		if (player_won == 1) {
			cout << "Player one won! Congratulation!"; break;
		}
		if (player_won == 2) {
			cout << "Player two won! Congratulation!"; break;
		}
		swap_player_and_marker();
	}
	//If no one wins, then it's a tie
	if (player_won == 0) {
		cout << "That is a tie game!";
	}
}


int main () {
	game();

}
