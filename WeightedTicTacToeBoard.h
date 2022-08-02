/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
* Board class for weighted tic tac toe game								*
* Holds an array of pointers to game pieces.							*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __WEIGHTEDTICTACTOEBOARD_H_JAM__
#define __WEIGHTEDTICTACTOEBOARD_H_JAM__

#include "WeightedTicTacToePiece.h"

class WeightedTicTacToeBoard
{
private:
	WeightedTicTacToePiece* _board[3][3];

public:
	WeightedTicTacToeBoard();
	~WeightedTicTacToeBoard();


	bool isPieceAt(int x, int y);
	// these do not check to make sure there is a piece there first.
	// use isPieceAt first.
	WeightedTicTacToePiece getPieceAt(int x, int y);
	char getSymbolAt(int x, int y); 
	int getWeightAt(int x, int y);

	// returns false if the move is invalid
	bool setPiece(int x, int y, WeightedTicTacToePiece piece); // all functions reroute here for code maintenance 
	bool placePiece(int x, int y, WeightedTicTacToePiece piece);
	bool setPiece(int x, int y, char symbol, int weight = 1);
	bool placePiece(int x, int y, char symbol, int weight = 1);

	bool canPlaceAt(int x, int y, WeightedTicTacToePiece piece) const;
	bool canPlaceAt(int x, int y, int weight = 0) const;
};

#endif