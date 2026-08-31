#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "menu.h"
#include "board.h"

int show_menu(void)
{
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *win = newwin(BOARD_ROWS, BOARD_COLS, (yMax / 2) - (BOARD_ROWS / 2), (xMax / 2) - (BOARD_COLS / 2));

    box(win, 0, 0);
    mvwprintw(win, 1, 2, "2048");
    mvwprintw(win, 8, 2, "1. Jogar");
    mvwprintw(win, 14, 2, "2. Leaderboard");
    mvwprintw(win, 20, 2, "3. Sair");
    wrefresh(win);

    int choice = 0;
    while (1)
    {
        int ch = wgetch(win);

        if (ch == '1')
        {
            choice = 1; break;
        }
        else if (ch == '2')
        {
            choice = 2; break;
        }
        else if (ch == '3' || ch == 'q' || ch == 'Q')
        {
            choice = 3; break;
        }
    }
    wclear(win);
    wrefresh(win);
    delwin(win);
    return choice;
}


