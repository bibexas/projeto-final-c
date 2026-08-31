#include <stdio.h>

int is_game_over(int board[4][4])
{
    int movimento = 0;
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (col + 1 < 4 && board[row][col] == board[row][col + 1])
            {
                movimento = 1;
            }
            if (row + 1 < 4 && board[row][col] == board[row + 1][col])
            {
                movimento = 1;
            }
            if (board [row][col] == 0)
            {
                movimento = 1;
            }
        }
    }
     if (movimento == 1)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

int check_win_rec(int board[4][4], int row, int col)
{
    if (row == 4)
    {
        return 0;
    }
    if (col == 4)
    {
        return check_win_rec(board, row + 1, 0);
    }
    if (board[row][col] == 2048)
    {
        return 1;
    }
    return check_win_rec(board, row, col + 1);
}

int check_win(int board[4][4])
{
    return check_win_rec(board, 0, 0);
}