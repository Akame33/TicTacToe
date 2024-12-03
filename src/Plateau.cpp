#include "Plateau.h"
#include <iostream>

void draw_game_board(const char board[])
{
    std::cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " | " << std::endl;
    std::cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " | " << std::endl;
    std::cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " | " << std::endl;
}

bool victory(const char board[9], char symbol)
{
    if ((board[0] == board[1] && board[1] == board[2] && board[2] == symbol) 
        || (board[3] == board[4] && board[4] == board[5] && board[5] == symbol ) 
        || (board[6] == board[7] && board[7] == board[8] && board[8] == symbol ))
    {
        return true;
    }

    if ((board[0] == board[3] && board[3] == board[6] && board[6] == symbol)
        ||(board[1] == board[4] && board[4] == board[7] && board[7] == symbol)
        ||(board[2] == board[5] && board[5] == board[8] && board[8] == symbol))
    {
        return true;
    }

    if ((board[0] == board[4] && board[4] == board[8] && board[8] == symbol) 
       || (board[2] == board[4] && board[4] == board[6] && board[6] == symbol))
    {
        return true;
    }

    return false;
}