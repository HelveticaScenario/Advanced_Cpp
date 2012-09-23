#include <iostream>
using namespace std;

	class TicTacToe
	{
	private:
		 int _rows;
		 int _cols;
		 int _maxTurns; //gets generated automatically, _rows*_cols
		 int _numPlayers;
		char * _players; //stores the symbol of each player
		 int _howManyToWin;
		bool _rulesSet; //cant play unless this is true

		char ** _board; 

		bool isWinnable();
		bool isBoring( int smaller,  int larger);		
		bool createBoard();
		void returnRules( int & rows,  int & cols,  int & numPlayers, char* & players,  int & toWin);
		void printVals() const;
		void displayBoard();
		bool setDefaultRules();
		bool getYesOrNo();
		bool getYesOrNo(bool defaultChoice);
		bool getYesOrNo(string message);
		bool getYesOrNo(string message, bool defaultChoice);
		bool getYesOrNo(string* message);
		bool getYesOrNo(string* message, bool defaultChoice);
		//getInt Segfaults when you enter letters instead of numbers. dont do that
		 int getInt(string message);
		 int getInt(string* message);
		void setPlayers(string* message);
		void setPlayers(string message);
		bool makeMove(int turn);
		bool isWin(int x, int y);

	public:
		TicTacToe();
		TicTacToe( int rows,  int cols,  int numPlayers, char* players,  int toWin);
		TicTacToe( int sideLength,  int numPlayers, char* players,  int toWin);
		~TicTacToe();		
		void play();		
		bool setRules();
		bool setRules( int rows,  int cols,  int numPlayers, char* players,  int toWin);

	};
