#include "TicTacToe.cpp"
#include <iostream>



using namespace std;

int main(int argc, char const *argv[])
{
	string message = "Please enter a number: ";


	
	// game = new TicTacToe();
	// cout << endl << "FUCK YEAH!!!" << endl;

	// cout << game->getYesOrNo(message) << endl;
	unsigned int rows = 9;
	// unsigned int cols = 5;
	unsigned int numPlayers = 2 ;
	char* players = new char[2];
	players[0] = 'a';
	players[1] = 's';
	unsigned int toWin = 3;
	cout << endl;
	// game->returnRules(rows, cols, numPlayers, players, toWin);
	// cout << "rows " << rows << endl;
	// cout << "cols " << cols << endl;
	// cout << "numPlayers " << numPlayers << endl;
	// cout << "players[0] " << players[0] << endl;
	// cout << "players[1] " << players[1] << endl;
	// cout << "toWin " << toWin << endl << endl;

	// game = new TicTacToe(rows, cols, numPlayers, players, toWin);

	// cout << endl;

	TicTacToe game(rows, numPlayers, players, toWin);
	unsigned a = game.getInt(message);
	game.play();
	// TicTacToe game;
	// game.play();
	// game.printVals();
	// game.displayBoard();


	// cout << game->getYesOrNo(message) << endl;
	// cout << "good" << endl;
	// cout << game->getYesOrNo(message, true) << endl;
	// cout << "good" << endl;	
}
/*
int main() {
    TicTacToe::TicTacToe game;
    char const answer = ’y’;
    bool firstGame = true;
    int cols = 3;
    int rows = 3;
    int howManyToWin = 3;
	int players
	char changeResponse;

    if (cols <= rows){

    }

    if (rows < howManyToWin){
		cout << "The game you described is unwinnable." << endl
			 << "Please describe a winnable game." << endl << endl;
		continue;
	}
	else if (cols < howManyToWin){
		cout << "You've described a game that is only" << endl
			 << "winnable in one direction, which might" << endl
			 << "it a tad boring. Care to change it? : ";
		
		do{
			changeResponse = NULL;
			cin >> changeResponse;
			changeResponse = toupper(changeResponse);
		}while(changeResponse != 'Y' && != 'N');
		
		if (changeResponse == 'Y')
			continue;
		break;

	}

    overloaded constructor to take desired rules, to assign normal ruleset (no args).
    method to pass in ref to local vars and return set rules for later reuse.
    method play to run game loop.


    do {
        game.play();
        cout << "Do you want to play again (y/n)? ";
        cin >> answer;
    } while(toupper(answer) == ’Y’);
	
	return 0; 
}
*/