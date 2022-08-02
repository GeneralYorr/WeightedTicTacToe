/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **
* Board class for weighted tic tac toe game	definitions					*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "WeightedTicTacToeBoard.h"

WeightedTicTacToeBoard::WeightedTicTacToeBoard()
{
    for (int i{ 0 }; i < 3; ++i)
        for (int j{ 0 }; j < 3; ++j)
            _board[i][j] = nullptr;
}

WeightedTicTacToeBoard::~WeightedTicTacToeBoard()
{
    for (int i{ 0 }; i < 3; ++i)
        for (int j{ 0 }; j < 3; ++j)
            if (_board[i][j] != nullptr)
                delete _board[i][j];
}

WeightedTicTacToePiece WeightedTicTacToeBoard::getPieceAt(int x, int y)
{
    return *_board[x][y];
}

char WeightedTicTacToeBoard::getSymbolAt(int x, int y)
{
    return _board[x][y]->getSymbol();
}

int WeightedTicTacToeBoard::getWeightAt(int x, int y)
{
    return _board[x][y]->getWeight();
}

bool WeightedTicTacToeBoard::isPieceAt(int x, int y)
{
    return _board[x][y] != nullptr;
}

// bottom 3 functions reformat and call setPiece for updating purposes 
bool WeightedTicTacToeBoard::setPiece(int x, int y, WeightedTicTacToePiece piece)
{
    if (!canPlaceAt(x, y, piece))
        return false;

    if (_board[x][y] != nullptr)
        delete _board[x][y];

    _board[x][y] = new WeightedTicTacToePiece(piece);

    return true;
}
bool WeightedTicTacToeBoard::placePiece(int x, int y, WeightedTicTacToePiece piece)
{
    return setPiece(x, y, piece);
}
bool WeightedTicTacToeBoard::setPiece(int x, int y, char symbol, int weight)
{
    return setPiece(x, y, WeightedTicTacToePiece(symbol, weight));
}
bool WeightedTicTacToeBoard::placePiece(int x, int y, char symbol, int weight)
{
    return setPiece(x, y, WeightedTicTacToePiece(symbol, weight));;
}

// by default only calls canPlaceAt with weight. Can be altered to disallow replacing your own piece
bool WeightedTicTacToeBoard::canPlaceAt(int x, int y, WeightedTicTacToePiece piece) const
{
    return canPlaceAt(x, y, piece.getWeight());
}

bool WeightedTicTacToeBoard::canPlaceAt(int x, int y, int weight) const
{
    if (_board[x][y] == nullptr)
        return true;

    return _board[x][y]->getWeight() < weight; // can place iff the weight of the piece of the board is smaller than the piece you want to place
}
