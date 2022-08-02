/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
* Game class for weighted tic tac toe game								*
* Has a board and players												*
*																		*
* By default it runs a standard game of tic tac toe but you can			*
* tell the constructor to use a larger max weight and how many			*
* pieces of each weight the players should start with.					*
*																		*
* Allows for input and output streams to be passed to the constructor	*
* but defaults to std::cin and std::cout.								*
*																		*
* Have not tested with more than 2 players								*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Game assumes _DIMENSIONS is a single digit in:
// • _playPiece()

#ifndef __WEIGHTEDTICTACTOEGAME_J_JAM__
#define __WEIGHTEDTICTACTOEGAME_J_JAM__

#include<iostream> // needed to store istream and ostream
#include "WeightedTicTacToeBoard.h"
#include "WeightedTicTacToePlayer.h"

class WeightedTicTacToeGame
{
private:
	static const int _DIMENSIONS = 3; // hardcoded into the board
	static const int _NUMPLAYERS = 2; 
	std::istream& _input;
	std::ostream& _output;

	WeightedTicTacToeBoard _board;
	WeightedTicTacToePlayer _players[_NUMPLAYERS];
	int _playersTurn;
	int _maxWeight;
	int _numPiecesOfEachWeight;

	void _clearScreen(); // made for windows
	void _printBoard();

	bool _playPiece(); // returns false if a piece is NOT played (e.g. the player quits)
protected:
public:
	bool _isGameOver();
	// defaults to standard tic tac toe game with standard cin and cout
	WeightedTicTacToeGame(int maxWeight = 1, int numPiecesOfEachWeight = 5, std::istream& input = std::cin, std::ostream& output = std::cout);
	~WeightedTicTacToeGame();

	int playGame();


	void choosePlayerSymbols(); // called to let the players choose instead of using defaults.

};

#endif
