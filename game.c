#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include "board.h"
#include "game.h"
#include "block.h"

static void add_random_block(int board[4][4])
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

static void draw_blocks(WINDOW *win, const int board[4][4])
{
    int row, col;
    int cell_height = getmaxy(win) / 4;
    int cell_width = getmaxx(win) / 4;

    for (row = 0; row < 4; ++row) {
        for (col = 0; col < 4; ++col) {
            if (board[row][col] != 0) {
                int pair = 1;

                if (board[row][col] >= 8)
                    pair = 2;
                if (board[row][col] >= 32)
                    pair = 3;

                wattron(win, COLOR_PAIR(pair) | A_BOLD);
                mvwprintw(win,
                          row * cell_height + cell_height / 2,
                          col * cell_width + cell_width / 2 - 2,
                          "%4d", board[row][col]);
                wattroff(win, COLOR_PAIR(pair) | A_BOLD);
            }
        }
    }
}

void start_game(WINDOW *parent)
{
    int pYMAX, pXMAX;
    getmaxyx(parent, pYMAX, pXMAX);

    int margin = 6;
    int side = (pYMAX - margin * 2);
    if (side > pXMAX - margin * 2)
        side = pXMAX - margin * 2;

    int height = side;
    int width = side * 2;
    if (width > pXMAX - margin * 2)
        width = pXMAX - margin * 2;

    width -= width % 4;

    int starty = (pYMAX - height) / 2;
    int startx = (pXMAX - width) / 2;

    WINDOW *game_win = derwin(parent, height, width, starty, startx);
    if (game_win == NULL)
        return;

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_RED);
        init_pair(2, COLOR_BLACK, COLOR_YELLOW);
        init_pair(3, COLOR_WHITE, COLOR_BLUE);
    }

    int board[4][4] = {{0}};
    srand((unsigned int)time(NULL));
    add_random_block(board);
    add_random_block(board);

    draw_board(game_win, 4, 4);
    draw_blocks(game_win, board);

    touchwin(parent);
    
    wnoutrefresh(parent);
    wnoutrefresh(game_win);
    doupdate();

    keypad(game_win, TRUE);

    int ch;
    while ((ch = wgetch(game_win)) != 'q') {

    }

    delwin(game_win);
}    