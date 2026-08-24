#include <stdio.h>
#include <ncurses.h>
#include "board.h"


WINDOW *init_board(void)
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *board_win = newwin(BOARD_ROWS, BOARD_COLS, (yMax / 2) - (BOARD_ROWS/2), (xMax / 2) - (BOARD_COLS/2));
    box(board_win, 0, 0);
    wrefresh(board_win);

    return board_win;
}

void draw_board(WINDOW *win, int rows, int cols)
{
    int height, width;
    getmaxyx(win, height, width);

    box(win, 0, 0);

    int inner_h = height - 1;
    int inner_w = width - 1;

    for (int r = 1; r < rows; r++)
    {
        int y = (inner_h * r) / rows;
        mvwhline(win, y, 1, ACS_HLINE, width - 2);
    }

    for (int c = 1; c < cols; c++)
    {
        int x = (inner_w * c) / cols;
        mvwvline(win, 1, x, ACS_VLINE, height - 2);
    }

    for (int r = 1; r < rows; r++)
    {
        int y = (inner_h * r) / rows;
        for (int c = 1; c < cols; c++)
        {
            int x = (inner_w * c) / cols;
            mvwaddch(win, y, x, ACS_PLUS);
        }
    }

    for (int r = 1; r < rows; r++)
    {
        int y = (inner_h * r) / rows;
        mvwaddch(win, y, 0, ACS_LTEE);
        mvwaddch(win, y, width - 1, ACS_RTEE);
    }
    for (int c = 1; c < cols; c++)
    {
        int x = (inner_w * c) / cols;
        mvwaddch(win, 0, x, ACS_TTEE);
        mvwaddch(win, height - 1, x, ACS_BTEE);
    }
}

