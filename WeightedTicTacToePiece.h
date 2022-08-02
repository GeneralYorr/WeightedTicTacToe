/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
* Piece class for weighted tic tac toe game								*
* Holds weight and symbol of the piece.									*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __WEIGHTEDTICTACTOEPIECE_H_JAM__
#define __WEIGHTEDTICTACTOEPIECE_H_JAM__

// default to a weight of 1. Leaving all weights the same is a normal game of tic tac toe
class WeightedTicTacToePiece
{
private:
	int _weight;
	char _symbol;
public:
	WeightedTicTacToePiece(char symbol, int weight = 1);

	void setSymbol(char symbol);
	void setWeight(int weight);

	char getSymbol() const;
	int getWeight() const;
};

#endif
