#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>

#define BOARD_DIM 17
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2

WINDOW *init_board(void);

#endif