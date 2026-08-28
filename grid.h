#ifndef GRID_H
#define GRID_H

void add_random_block(int board[4][4]);
void merge_line(int linha[4]);
void invert_line(int linha[4]);
int move_left(int board[4][4]);
int move_right(int board[4][4]);
int move_up(int board[4][4]);
int move_down(int board[4][4]);

#endif