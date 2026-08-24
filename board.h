#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>

#define BOARD_DIM 25
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2

WINDOW *init_board(void);
void draw_board(WINDOW *win, int rows, int cols);

#endif