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

int merge_line(int linha[4])
{
    int write_pos = 0;
    int merged[4] = {0};
    int pontos = 0;

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
            pontos = pontos + linha[write_pos - 1];
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
    return pontos;
}

int move_left(int board [4][4])
{
    int pontos = 0;
    for (int row = 0; row < 4; row++)
    {
        pontos = pontos + merge_line(board[row]);
    }
    return pontos
}

void invert_line(int linha [4])
{
  int temp = linha[0];  
  linha[0] = linha [3]; 
  linha [3] = temp;

  int temp2 = linha[1];
  linha[1] = linha[2];
  linha[2] = temp2;
}

int move_right(int board [4][4])
{
    int pontos = 0;
    for (int row = 0; row < 4; row++)
    {
        invert_line(board[row]);
        pontos = pontos + merge_line(board[row]);
        invert_line(board[row]);
    }
    return pontos;
}

int move_up(int board [4][4])
{
    int pontos = 0;
    for (int col = 0; col < 4; col++)
    {
        int coluna_temp[4];
        for (int i = 0; i < 4; i++)
        {
            coluna_temp[i] = board[i][col];
        }
        pontos = pontos + merge_line(coluna_temp);
        for (int i = 0; i < 4; i++)
        {
            board[i][col] = coluna_temp[i];
        }
    }
    return pontos;
}

int move_down(int board [4][4])
{
    int pontos = 0;
    for (int col = 0; col < 4; col++)
    {
        int coluna_temp[4];
        for (int i = 0; i < 4; i++)
        {
            coluna_temp[i] = board[i][col];
        }
        invert_line(coluna_temp);
        pontos = pontos + merge_line(coluna_temp);
        invert_line(coluna_temp);
        for (int i = 0; i < 4; i++)
        {
            board[i][col] = coluna_temp[i];
        }
    }
    return pontos;
}