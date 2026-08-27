#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add_random_block(int board[4][4])
{
    int empty[16][2];
    int count = 0;
    int row, col;

    for (row = 0; row < 4; ++row)
    {
        for (col = 0; col < 4; ++col)
        {
            if (board[row][col] == 0)
            {
                empty[count][0] = row;
                empty[count][1] = col;
                ++count;
            }
        }
    }

    if (count > 0)
    {
        int position = rand() % count;
        board[empty[position][0]][empty[position][1]] =
            (rand() % 10 == 0) ? 4 : 2;
    }
}

void merge_line(int linha[4])
{
    int write_pos = 0;
    int merged[4] = {0};

    for (int i = 0; i < 4; i++)
    {
        if (
            linha[i] == 0
        ) {
            continue;
        }
        if (
            write_pos > 0
            && merged[write_pos - 1] == 0
            && linha[i] == linha[write_pos - 1]
        )
        {
            linha[write_pos - 1] = linha[write_pos - 1] * 2;
            merged[write_pos - 1] = 1;
        }
        else {
            linha[write_pos] = linha[i];
            write_pos++;
        }
    }

    for (int j = write_pos; j < 4; j++)
    {
        linha[j] = 0;
    }
    
}
