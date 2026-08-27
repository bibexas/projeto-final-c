#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add_random_block(int board[4][4])
{
    int empty[16][2];
    int count = 0;
    int row, col;

    for (row = 0; row < 4; ++row) {
        for (col = 0; col < 4; ++col) {
            if (board[row][col] == 0) {
                empty[count][0] = row;
                empty[count][1] = col;
                ++count;
            }
        }
    }

    if (count > 0) {
        int position = rand() % count;
        board[empty[position][0]][empty[position][1]] =
            (rand() % 10 == 0) ? 4 : 2;
    }
}

