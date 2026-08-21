#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "board.h"
#include "game.h"

void start_game(void)
{
    int yMax, xMax;
    int height = 18;
    int width = 36;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *game_win = derwin(stdscr, height, width, (yMax - height) / 2, (xMax - width) / 2);
    if (game_win == NULL)
        return;

    box(game_win, 0, 0);
    mvwprintw(game_win, 1, 2, "Usa as setas para controlar o jogo!");
    wrefresh(game_win);

    keypad(game_win, TRUE);

    int ch;
    while ((ch = wgetch(game_win)) != 'q') {

    }

    delwin(game_win);
}    