# WeightedTicTacToe

Player 1 places weight 3 piece at 1,1

Player 2 attempts to place weight 1 piece at 3, 1 -> crash

A tic tac toe game with weighted pieces where a larger weight can cover a smaller piece.

Currently has a bug where *occasionally* it will crash when a player tries to replace a piece with a smaller piece. Usually it correctly messages the error and asks for a valid input, but something causes it to occasionally crash. Still digging into the details.
