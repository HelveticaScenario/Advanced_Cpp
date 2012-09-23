#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe() : _rulesSet(false){
	_rulesSet = setRules();
	// printVals();
	// cout << endl << endl;
	// if (_rulesSet)
	// {
	// 	// cout << _board[0];
	// 	displayBoard();
	// } 
}

TicTacToe::TicTacToe( int rows,  int cols,  int numPlayers, char* players,  int howManyToWin) : _rulesSet(false){
	_rulesSet = setRules(rows, cols, numPlayers, players, howManyToWin);
	// printVals();
	// displayBoard();
}

TicTacToe::TicTacToe( int sideLength,  int numPlayers, char* players,  int howManyToWin) : _rulesSet(false){
	_rulesSet = setRules(sideLength, sideLength, numPlayers, players, howManyToWin); //calls the above constructor and passes in sideLength for cols and rows
	// printVals();
	// displayBoard();
}

TicTacToe::~TicTacToe(){
	delete _players;
	for (int i = 0; i < _cols; ++i)
	{
		delete[] _board[i];
	}
	delete[] _board;


}

bool TicTacToe::getYesOrNo(){ // just gets yes or no and returns bools
	string str;
	getline(cin, str);
	if (toupper(str[0]) == 'Y')
	{
		return true;
	}
	else if (toupper(str[0]) == 'N')
	{
		return false;
	}
	return getYesOrNo(); //RECURSION!!!
}

bool TicTacToe::getYesOrNo(bool defaultChoice){ // just gets yes or no and returns bools, has default choice
	string str;
	getline(cin, str);
	if (str == "")
	{
		return defaultChoice;
	}
	else if (toupper(str[0]) == 'Y')
	{
		return true;
	}
	else if (toupper(str[0]) == 'N')
	{
		return false;
	}
	return getYesOrNo(defaultChoice); //RECURSION!!!
}

bool TicTacToe::getYesOrNo(string message){
	cout << message;
	string str;
	getline(cin, str);
	if (toupper(str[0]) == 'Y')
	{
		return true;
	}
	else if (toupper(str[0]) == 'N')
	{
		return false;
	}
	return getYesOrNo(message); //RECURSION!!!
}

bool TicTacToe::getYesOrNo(string message, bool defaultChoice){ //this method is pretty nifty if I do say so
	cout << message;
	string str;
	getline(cin, str);
	if (str == "")
	{
		return defaultChoice;
	}
	else if (toupper(str[0]) == 'Y')
	{
		return true;
	}
	else if (toupper(str[0]) == 'N')
	{
		return false;
	}
	return getYesOrNo(message, defaultChoice); //RECURSION!!!
}

bool TicTacToe::getYesOrNo(string* message){
	return getYesOrNo(*message);
}

bool TicTacToe::getYesOrNo(string* message, bool defaultChoice){ //this method is pretty nifty if I do say so
	return getYesOrNo(*message, defaultChoice);
}

 int TicTacToe::getInt(string message){ 
	cout << message;
	 int val;
	cin >> val;
	// cout << "You entered " << val << endl << "Is that correct? : ";
	// if (getYesOrNo())
	// {
	// 	return val;
	// }
	// return getInt(message);
	if (cin.fail()){
		cin.clear();
		cin.ignore(256);
		return getInt(message);
	}
	return val;
}

 int TicTacToe::getInt(string* message){
	return getInt(*message);
}
//  int TicTacToe::getInt(string message,  int defaultChoice){

// }

void TicTacToe::setPlayers(string message){
	_numPlayers = getInt(message);
	_players = new char[_numPlayers];
	for (int i = 0; i < _numPlayers; ++i)
	{
		cout << "Please type the SINGLE CHARACTER you would like\nto represent player " << i+1 << ": ";
		cin >> _players[i];
	}
}

void TicTacToe::setPlayers(string* message){
	setPlayers(*message);
}

bool TicTacToe::setDefaultRules(){
	_rows = 3;
	_cols = 3;
	_maxTurns = 9;
	_numPlayers = 2;
	_players = new char[_numPlayers];
	_players[0] = 'X';
	_players[1] = 'O';
	_howManyToWin = 3;
	createBoard();
	return true;
}

void TicTacToe::printVals() const{
	cout << "_rows " << _rows << endl;
	cout << "_cols " << _cols << endl;
	cout << "_maxTurns " << _maxTurns << endl;
	cout << "_numPlayers " << _numPlayers << endl;
	for (int i = 0; i < _numPlayers; ++i)
	{
		cout << "_players[" << i << "] " << _players[i] << endl;
	
	}
	cout << "_howManyToWin " << _howManyToWin << endl;
}

void TicTacToe::returnRules( int & rows,  int & cols,  int & numPlayers, char* & players,  int & howManyToWin){
	if (_rulesSet)
	{
		rows = _rows;
		cols = _cols;
		howManyToWin = _howManyToWin;
		numPlayers = _numPlayers;
		players = new char[numPlayers];
		for (int i = 0; i < numPlayers; ++i)
		{
			players[i] = _players[i];
		}
	}
	else cout << "Attempted to extract rule-set without having set rules." << endl;
}

bool TicTacToe::setRules( int rows,  int cols,  int numPlayers, char* players,  int howManyToWin){
	_rows = rows;
	_cols = cols;
	_maxTurns = _rows*_cols;
	_howManyToWin = howManyToWin;
	_numPlayers = numPlayers;
	_players = new char[_numPlayers];
	for (int i = 0; i < _numPlayers; ++i)
	{
		_players[i] = players[i];
	}
	createBoard();
	return true;
}

bool TicTacToe::setRules(){
	string* prompt = new string("Would you like to play an ordinary 3x3 game, yes or no?\nIf you would like to set your own rules then type no. [Default = no]: ");
	if (getYesOrNo(prompt, false))
	{
		setDefaultRules();
		delete prompt;
		return true;
	}
	delete prompt;

	prompt = new string("How many rows would you like? ONLY ENTER INTEGERS! : ");
	_rows = getInt(prompt);
	delete prompt;

	prompt = new string("How many columns would you like? ONLY ENTER INTEGERS! : ");
	_cols = getInt(prompt);
	delete prompt;

	_maxTurns = _cols*_rows;
	prompt = new string("How many players would you like? ONLY ENTER INTEGERS! : ");
	setPlayers(prompt);
	delete prompt;

	prompt = new string("How many in a row would you like it to take to win? ONLY ENTER INTEGERS! : ");
	_howManyToWin = getInt(prompt);
	delete prompt;

	return isWinnable();
}

bool TicTacToe::isWinnable(){
	 int larger;
	 int smaller;		

	if (_cols <= _rows){
		larger = _rows;
		smaller = _cols;		
	}
	else{
		larger = _cols;
		smaller = _rows;		
	}

	if (larger < _howManyToWin){
		cout << "The game you described is unwinnable." << endl
			 << "Please describe a winnable game." << endl << endl;
		return setRules();
	}
	else if (isBoring(smaller, larger)){
		return setRules();		
	}

	return createBoard();
}

bool TicTacToe::isBoring( int smaller,  int larger){
	if (smaller < _howManyToWin){		
		string str = "You've described a game that is only winnable in one direction,\nwhich might it a tad boring. Care to change it? : ";
		if (getYesOrNo(str))
			return true;
	}
	return false;
}

bool TicTacToe::createBoard(){
	_board = new char*[_cols];
	for (int i = 0; i < _cols; ++i)
	{
		_board[i] = new char[_rows];
		for (int j = 0; j < _rows; ++j)
		{
			_board[i][j] = ' ';
		}
	}
	return true;
}

void TicTacToe::displayBoard(){
	system("clear");
	cout << " ";
	for (int i = 0; i < _cols; ++i)
	{
		cout << " " << i << "  ";
	}
	cout << endl;
	for (int j = 0; j < _rows; ++j)
	{
		cout << j;
		for (int i = 0; i < _cols; ++i)
		{
			cout << " " << _board[i][j] << " ";
			if (i<(_cols-1))
			{
				cout << "|";
			}
		}

		cout << endl << " ";
		if (j<(_rows-1)) //in order to seperate with lines but not the far right and bottom
		{
			for (int i = 0; i < _cols; ++i)
			{
				cout << "---";
				if (i<(_cols-1))
				{
					cout << "+";
				}
			}
			cout << endl;
		}
	}
}

bool TicTacToe::makeMove(int turn){
	cout << _players[turn % _numPlayers] << "'s turn. Where to? ENTER YOUR HORIZONAL VALUE, THEN A SPACE,\nTHEN YOUR VERTICAL VALUE. ONLY NUMBERS : ";
	int x, y;
	cin >> x >> y;
	if (cin.fail()){
		cin.clear();
		cin.ignore(256);
		return makeMove(turn);
	}
	else if (x < 0 || x >= _cols || y < 0 || y >= _rows)
	{
		cout << "Invalid move." << endl;
		return makeMove(turn);
	}
	else if (_board[x][y] != ' ')
	{
		cout << "That place is already taken." << endl;
		return makeMove(turn);
	}
	_board[x][y] = _players[turn % _numPlayers];
	return isWin(x,y);
}

bool TicTacToe::isWin(int x, int y){
	int inRow = 1;
	int lookX, lookY;

	//checks horizontally
	for (lookX = x-1; lookX >=0 ; --lookX)
	{
		if (_board[lookX][y] != _board[x][y])
		{
			break;
		}
		else if (++inRow >= _howManyToWin)
		{
			return true;
		}
	}
	for (lookX = x+1; lookX < _cols; ++lookX)
	{
		if (_board[lookX][y] != _board[x][y])
		{
			break;
		}
		else if (++inRow >= _howManyToWin)
		{
			return true;
		}
	}

	//checks vertically
	inRow = 1;
	for (lookY = y-1; lookY >=0 ; --lookY)
	{
		if (_board[x][lookY] != _board[x][y])
		{
			break;
		}
		else if (++inRow >= _howManyToWin)
		{
			return true;
		}
	}
	for (lookY = y+1; lookY < _rows; ++lookY)
	{
		if (_board[x][lookY] != _board[x][y])
		{
			break;
		}
		else if (++inRow >= _howManyToWin)
		{
			return true;
		}
	}

	// checks diagonally '\' with top left, bottom right
	inRow = 1;
	if (x > 0 && y > 0)
	{
		lookX = x-1;
		lookY = y-1;
		for (; lookY >= 0 && lookX >= 0 ; --lookY, --lookX)
		{
			if (_board[lookX][lookY] != _board[x][y])
			{
				break;
			}
			else if (++inRow >= _howManyToWin)
			{
				return true;
			}
		}
	}
	if (x < (_cols-1) && y < (_rows-1))
	{
		lookX = x+1;
		lookY = y+1;
		for (; lookY < _cols && lookX < _rows ; ++lookY, ++lookX)
		{
			if (_board[lookX][lookY] != _board[x][y])
			{
				break;
			}
			else if (++inRow >= _howManyToWin)
			{
				return true;
			}
		}
	}

	//checks diagonally '/' with bottom left, top right
	inRow = 1;
	if (x > 0 && y < (_rows-1))
	{
		lookX = x-1;
		lookY = y+1;
		for (; lookY >= 0 && lookX < _cols ; ++lookY, --lookX)
		{
			if (_board[lookX][lookY] != _board[x][y])
			{
				break;
			}
			else if (++inRow >= _howManyToWin)
			{
				return true;
			}
		}
	}
	if (x < (_cols-1) && y > 0)
	{
		lookX = x+1;
		lookY = y-1;
		for (; lookY < _rows && lookX >=0 ; --lookY, ++lookX)
		{
			if (_board[lookX][lookY] != _board[x][y])
			{
				break;
			}
			else if (++inRow >= _howManyToWin)
			{
				return true;
			}
		}
	}


	return false;
}

void TicTacToe::play(){	
	if (!_rulesSet)
	{
		cout << "Game rules not set." << endl;
		return;
	}
	// _maxTurns = 1;
	for ( int i = 0; i < _maxTurns; ++i)
	{
		displayBoard();
		if(makeMove(i)){
			displayBoard();
			cout << "player " << _players[i % _numPlayers] << " wins." << endl;
			system("read -p 'Press [Enter] key to continue...'");
			return;
		}	
	}
	cout << "Nobody wins." << endl;
	system("read -p 'Press [Enter] key to continue...'");
	return;
}
