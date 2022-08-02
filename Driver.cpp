

#include "WeightedTicTacToeGame.h"

int main()
{
    WeightedTicTacToeGame game(3,2); // make a game with a max weight of 3 and 2 pieces of each weight

    game.choosePlayerSymbols(); // let players choose their own characters instead of using the defaults of x and o

    return game.playGame();
}
