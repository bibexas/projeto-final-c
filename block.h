#ifndef BLOCK_H
#define BLOCK_H

#include <ncurses.h>

void block_draw(WINDOW *win, int row, int col, int value, int usar_cor);

#endif