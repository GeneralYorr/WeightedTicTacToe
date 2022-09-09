/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
* Game class for weighted tic tac toe game definitions					*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "WeightedTicTacToeGame.h"
#include<string>

void WeightedTicTacToeGame::_clearScreen()
{
	system("cls");
}

void WeightedTicTacToeGame::_printBoard()
{
	bool showWeights = _maxWeight > 1;
	for (int y = 0; y < _DIMENSIONS; ++y) {
		for (int x = 0; x < _DIMENSIONS; ++x) {

			_output << " ";

			if (_board.isPieceAt(x, y))
			{
				_output << _board.getPieceAt(x, y).getSymbol();
				if(showWeights)
					_output << "(" << _board.getPieceAt(x, y).getWeight() << ")";
			}
			else
			{
				_output << " ";
				if (showWeights)
					_output << "   ";
			}
			_output << " ";

			if (x != _DIMENSIONS - 1)
				_output << "|";
		}
		_output << "\n";
		if (y != _DIMENSIONS - 1)
		{
			_output << "-----------";
			if (showWeights)
				_output << "---------";

			_output << "\n";
		}
	}
}

bool WeightedTicTacToeGame::_playPiece()
{
	std::string userInput;
	bool validInput;
	int row, col, weight{ 1 };

	do { // loop while input
		// get row
		do {
			_output << "Player " << _players[_playersTurn].getSymbol()
				<< ": What row would you like to play a piece on? (1-" << _DIMENSIONS
				<< ")\n";

			std::getline(_input, userInput);
			row = userInput[0] - '0';

			validInput = true;
			if (userInput.size() > 1) // assuming _DIMENTIONS is a single digit
			{
				validInput = false;
				_output << "Invalid input. Please input a single digit.\n\n";// assuming _DIMENTIONS is a single digit
			}
			else if (row > _DIMENSIONS || row < 1)
			{
				validInput = false;
				_output << "Invalid input. Please choose a valid row.\n\n";
			}

		} while (!validInput);

		// get col
		do {
			_output << "Player " << _players[_playersTurn].getSymbol()
				<< ": What column would you like to play a piece on? (1-" << _DIMENSIONS
				<< ")\n";

			std::getline(_input, userInput);
			col = userInput[0] - '0';

			validInput = true;
			if (userInput.size() > 1) // assuming _DIMENTIONS is a single digit
			{
				validInput = false;
				_output << "Invalid input. Please input a single digit.\n\n";// assuming _DIMENTIONS is a single digit
			}
			else if (col > _DIMENSIONS || col < 1)
			{
				validInput = false;
				_output << "Invalid input. Please choose a valid column.\n\n";
			}

		} while (!validInput);

		// get weight if maxWeight is more than 1 (otherwise, it's pointless)
		if (_maxWeight > 1) {

			do {
				_output << "Player " << _players[_playersTurn].getSymbol()
					<< ": What size piece would you like to play(1-" << _maxWeight
					<< ")\n";

				std::getline(_input, userInput);
				weight = userInput[0] - '0';

				validInput = true;
				if (userInput.size() > 1) // assuming _maxWeight is a single digit
				{
					validInput = false;
					_output << "Invalid input. Please input a single digit.\n\n";// assuming _maxWeight is a single digit
				}
				else if (weight > _maxWeight || weight < 1)
				{
					validInput = false;
					_output << "Invalid input. Please choose a valid weight.\n\n";
				}if (!_players[_playersTurn].usePiece(weight)) {
					validInput = false;
					_output << "You do not have a piece of that weight. Please choose a valid weight.\n\n";
					// prints this line before crashing
					// but doesn't usually crash after printing this line
					// not sure of the nuance yet.
				}

			} while (!validInput);

		}


		if (!_board.canPlaceAt(col - 1, row - 1, weight)) {
			_players[_playersTurn].addPiece(weight); // because used the piece earlier. sloppy. needs work.
			validInput = false;
			_output << "You cannot place that piece there. \n\n";
		}
		else {
			_board.placePiece(col - 1, row - 1, _players[_playersTurn].getSymbol(), weight);
		}
	} while (!validInput);

	++_playersTurn; // next player's turn
	_playersTurn %= _NUMPLAYERS;

	return true;
}

bool WeightedTicTacToeGame::_isGameOver()  // can improve by doing rows and columns in one loop, both diagonals in single loop
{
	int maxPlayerWeight = 0;
	bool canMove{ false };
	bool gameWon;
	char playerToken;

	// if current player has no pieces, the game is over
	if (_players[_playersTurn].howManyPieces() == 0) 
		return true;

	// find the largest size piece the current player has
	for (int i = _maxWeight; i > 0; --i) 
	{
		if (_players[_playersTurn].howManyPiecesOfWeight(i) > 0)
		{
			maxPlayerWeight = i; // store the largest piece size the player has
			break; //break the loop
		}
	}

	// is there anywhere the player can play their largest piece?
	for (int y = 0; y < _DIMENSIONS; ++y) {
		for (int x = 0; x < _DIMENSIONS; ++x) {
			if (_board.canPlaceAt(x, y, maxPlayerWeight)) {
				canMove = true;
				y = _DIMENSIONS; // break out of the loops
				break;
			}
		}
	}

	// if they can't move, the game is over
	if (!canMove)
		return true; 


	//has someone won?
	//check rows first
	for (int y = 0; y < _DIMENSIONS; ++y) {

		gameWon = true;
		if (!_board.isPieceAt(0, y)) // if there's not a piece there, then the row isn't all the same player's pieces
			continue;

		playerToken = _board.getSymbolAt(0, y);
		//std::cout <<"player token:"<< playerToken << std::endl; //HERE
		for (int x = 1; x < _DIMENSIONS; ++x) {
			if (!_board.isPieceAt(x,y) || _board.getSymbolAt(x, y) != playerToken) {
				gameWon = false; // the row isn't all the same so
				break; //break from the loop
			}
		}

		// someone won, so the game is over
		if (gameWon) 
			return true;
	}


	// check columns next
	for (int x = 0; x < _DIMENSIONS; ++x) {

		gameWon = true;
		if (!_board.isPieceAt(x, 0)) // if there's not a piece there, then the row isn't all the same player's pieces
			continue;
		playerToken = _board.getSymbolAt(x, 0);

		for (int y = 1; y < _DIMENSIONS; ++y) {
			if (!_board.isPieceAt(x,y) || _board.getSymbolAt(x, y) != playerToken) {
				gameWon = false; // the row isn't all the same so
				break; //break from the loop
			}
		}

		// someone won, so the game is over
		if (gameWon)
			return true;
	}


	// finally check diagnals. \ diagonal first
	if (_board.isPieceAt(0, 0)) {
		gameWon = true;
		playerToken = _board.getSymbolAt(0, 0);

		for (int i = 1; i < _DIMENSIONS; ++i) {
			if (!_board.isPieceAt(i,i) || _board.getSymbolAt(i, i) != playerToken) {
				gameWon = false; // the row isn't all the same so
					break; //break from the loop
			}
		}

		if (gameWon) return true;
	}


	// check the / diagonal
	if (_board.isPieceAt(0, _DIMENSIONS - 1)) {

		gameWon = true;
		playerToken = _board.getSymbolAt(0, _DIMENSIONS - 1);

		for (int i = 1; i < _DIMENSIONS; ++i) {
			if (!_board.isPieceAt(i, _DIMENSIONS - 1 - i) || _board.getSymbolAt(i, _DIMENSIONS - 1 - i) != playerToken) {
				gameWon = false; // the row isn't all the same so
				break; //break from the loop
			}
		}

		if (gameWon) return true;
	}

	return false;
}

WeightedTicTacToeGame::WeightedTicTacToeGame(int maxWeight, int numPiecesOfEachWeight, std::istream& input, std::ostream& output):
	_input(input),
	_output(output),
	_maxWeight(maxWeight),
	_numPiecesOfEachWeight(numPiecesOfEachWeight),
	_playersTurn(0)
{
	
	_players[1].setSymbol('o');

	if (_NUMPLAYERS > 2) // instead of 'x' and 'o' use numbers
	{
		for (int i = 0; i < _NUMPLAYERS; ++i)
			_players[i].setSymbol((char)(i+'1'));

	}

	int* tokenWeights = new int[maxWeight * numPiecesOfEachWeight];

	for (int i = 0; i < maxWeight * numPiecesOfEachWeight; ++i) {
		tokenWeights[i] = i % maxWeight + 1;
	}

	for (int i = 0; i < _NUMPLAYERS; ++i) {
		_players[i]._changeMaxPiecesWeight(maxWeight);
		_players[i].addPieces(tokenWeights, maxWeight * numPiecesOfEachWeight);

	}


	delete[] tokenWeights;
}

WeightedTicTacToeGame::~WeightedTicTacToeGame()
{

}

int WeightedTicTacToeGame::playGame()
{
	_clearScreen(); 
	// add welcome?

	while (!_isGameOver()) {
		_clearScreen(); 
		_printBoard(); 
		// get player input
		if (!_playPiece()) // if a piece isn't played (e.g. the player quits), game over
			break;
	}

	// announce the game is over and print the final board
	_clearScreen();
	_output << "Game Over!\n\n";
	_printBoard();

	return 0;
}

void WeightedTicTacToeGame::choosePlayerSymbols()
{
	std::string userInput;
	bool validInput;

	for (int i = 0; i < _NUMPLAYERS; ++i) {
		do {
			_output << "Player " << i + 1 << ": What character would you like to use?\n";
			std::getline(_input,userInput);

			validInput = userInput.size() == 1;
			if (!validInput) // if size isn't 1
				_output << "Invalid input. Please input a single character.\n\n";
			else// single character input, but is it different than the other player(s)?
				for (int j = 0; j < i; ++j)
					if (_players[j].getSymbol() == userInput[0]) {
						_output << "Character already in use by Player " << j + 1 << ". Please select a different character.\n\n";
						validInput = false;
					}
		} while (!validInput);
		
		_players[i].setSymbol(userInput[0]);
		

	}
}
