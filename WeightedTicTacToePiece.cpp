/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*           Board Pieces Definitions                                   *
*  Nothing fancy. Getters, Setters, and Constructor                    *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "WeightedTicTacToePiece.h"

WeightedTicTacToePiece::WeightedTicTacToePiece(char symbol, int weight):
    _symbol{ symbol },
    _weight{ weight }
{
}

void WeightedTicTacToePiece::setSymbol(char symbol)
{
    _symbol = symbol;
}

void WeightedTicTacToePiece::setWeight(int weight)
{
    _weight = weight;
}

char WeightedTicTacToePiece::getSymbol() const
{
    return _symbol;
}

int WeightedTicTacToePiece::getWeight() const
{
    return _weight;
}