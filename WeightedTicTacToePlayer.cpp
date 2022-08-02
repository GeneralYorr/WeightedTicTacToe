/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                   WeightedTicTacToePlayer Definitions                                 *
*  Does not check all weights for validity. Only uses max weight to    *
*  create an appropriate size array for how many of each weight they   *
*  have.                                                               *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "WeightedTicTacToePlayer.h"

WeightedTicTacToePlayer::WeightedTicTacToePlayer(char symbol, int maxPieceWeight)
{
    _symbol = symbol;

    _maxPieceWeight = maxPieceWeight;
    _numPiecesOfWeight = new int[maxPieceWeight];

    for (int i = 0; i < _maxPieceWeight; ++i)
        _numPiecesOfWeight[i] = 0;


}

WeightedTicTacToePlayer::~WeightedTicTacToePlayer()
{
    delete[] _numPiecesOfWeight;
}

void WeightedTicTacToePlayer::setSymbol(char symbol)
{
    _symbol = symbol;
}

char WeightedTicTacToePlayer::getSymbol() const
{
    return _symbol;
}

void WeightedTicTacToePlayer::_changeMaxPiecesWeight(int newMaxWeight)
{
    int* old = _numPiecesOfWeight;// hold old set of pieces

    // make new set of pieces
    _numPiecesOfWeight = new int[newMaxWeight];

    // copy the old set to the new set
    int min{ newMaxWeight };
    if (_maxPieceWeight < min)
        min = _maxPieceWeight;

    for (int i = 0; i < min; ++i)
        _numPiecesOfWeight[i] = old[i];

    // if the new max weight is larger, set the number of each of the new sizes to 0
    for (int i = min; i < newMaxWeight; ++i)
        _numPiecesOfWeight[i] = 0;

    // update max weight
    _maxPieceWeight = newMaxWeight;

    delete[] old; // remove the old set from memory

}

// should only be called to see if it needs updating.
int WeightedTicTacToePlayer::_getMaxPiecesWeight() const
{
    return _maxPieceWeight;
}


void WeightedTicTacToePlayer::addPiece(int weight)
{
    ++_numPiecesOfWeight[weight - 1];
}

void WeightedTicTacToePlayer::addPieces(int weights[], int numPieces)
{

    for (int i = 0; i < numPieces; ++i)
    {

        ++_numPiecesOfWeight[weights[i] - 1];

    }

}

bool WeightedTicTacToePlayer::hasPiece(int weight)
{
    return _numPiecesOfWeight[weight - 1] > 0;
}

int WeightedTicTacToePlayer::howManyPiecesOfWeight(int weight)
{
    return _numPiecesOfWeight[weight - 1];
}

int WeightedTicTacToePlayer::howManyPieces()
{
    int sum{ _numPiecesOfWeight[0] };
    for (int i = 1; i < _maxPieceWeight; ++i)
        sum += _numPiecesOfWeight[i];

    return sum;
}

bool WeightedTicTacToePlayer::usePiece(int weight)
{
    if (!hasPiece(weight))
        return false;

    --_numPiecesOfWeight[weight - 1];
    return true;
}
