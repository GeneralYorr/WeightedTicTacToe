/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
* Player class for weighted tic tac toe game							*
* Holds symbol used by the player (traditionally 'x' or 'o')			*
* and how many pieces of each weight it has.							*
*																		*
* Needs to know the max weight of the pieces to create the array		*
* that holds how many pieces of each weight they have, but does			*
* not check weights for validity.										*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __WEIGHTEDTICTACTOEPLAYER_H_JAM__
#define __WEIGHTEDTICTACTOEPLAYER_H_JAM__

class WeightedTicTacToePlayer {
private:
	char _symbol;
	int _maxPieceWeight;
	int* _numPiecesOfWeight;

public:
	WeightedTicTacToePlayer(char symbol='x', int maxPieceWeight = 1);
	~WeightedTicTacToePlayer();


	// this should be set by the constructor and not changed, but the potential is there.
	// need to find a better way. probably recode with the board having an array of pointers
	// instead of an array of players to allow for proper constructor use
	void _changeMaxPiecesWeight(int newMaxWeight);
	// should only be called to see if the above function needs to be called
	int _getMaxPiecesWeight() const;


	void setSymbol(char symbol);
	char getSymbol() const;

	void addPiece(int weight = 1); // Give the player a piece
	void addPieces(int weights[], int numPieces); // give the player multiple pieces

	bool hasPiece(int weight = 1);
	int howManyPiecesOfWeight(int weight = 1);
	int howManyPieces();

	bool usePiece(int weight = 1); // returns false if player doesn't have a piece of that weight
};


#endif