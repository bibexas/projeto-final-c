#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include "board.h"
#include "game.h"
#include "block.h"
#include "grid.h"
#include "end.h"

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

    width -= (width - 1) % 4;
    height -= (height - 1) % 4;

    int starty = (pYMAX - height) / 2;
    int startx = (pXMAX - width) / 2;

    WINDOW *game_win = derwin(parent, height, width, starty, startx);
    if (game_win == NULL)
        return;

    int board[4][4] = {{0}};
    int score = 0;
    srand((unsigned int)time(NULL));
    add_random_block(board);
    add_random_block(board);

    draw_board(game_win, 4, 4);
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (board[row][col] != 0)
                block_draw(game_win, row, col, board[row][col]);
        }
    }

    touchwin(parent);

    wnoutrefresh(parent);
    wnoutrefresh(game_win);
    doupdate();

    keypad(game_win, TRUE);

    int ch;
    while ((ch = wgetch(game_win)) != 'q')
    {
        int board_antes[4][4];
        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                board_antes[row][col] = board[row][col];
            }
        }
        if (ch == KEY_LEFT)
        {
            score = score + move_left(board);
        }
        else if (ch == KEY_RIGHT)
        {
            score = score + move_right(board);
        }
        else if (ch == KEY_UP)
        {
            score = score + move_up(board);
        }
        else if (ch == KEY_DOWN)
        {
            score = score + move_down(board);
        }

        int mudou = 0;
        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                if (board[row][col] != board_antes[row][col])
                {
                    mudou = 1;
                }
            }
        }

        if (mudou == 1)
        {
            add_random_block(board);
        }

        werase(game_win);
        draw_board(game_win, 4, 4);

        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                if (board[row][col] != 0)
                {
                    block_draw(game_win, row, col, board[row][col]);
                }
            }
        }

        char text[15];
        snprintf(text, sizeof text, "Score: %d", score);
        int x = pXMAX - strlen(text);
        mvwprintw(parent, 0, x, "%s", text);
        wnoutrefresh(parent);
        wnoutrefresh(game_win);
        doupdate();

        if (is_game_over(board) == 1)
        {
            break;
        }
    }

    const char *game_over_art[] =  
    {
    " ___   _   __  __ ___    _____   _____ ___ ",
    "/ __| /_\\ |  \\/  | __|  / _ \\ \\ / / __| _ \\",
    "| (_ |/ _ \\| |\\/| | _|  | (_) \\ V /| _||   /",
    " \\___/_/ \\_\\_|  |_|___|  \\___/ \\_/ |___|_|_\\"
    };
    for (int i = 0; i < 4; i++)
    {
        int x = (pXMAX - strlen(game_over_art[i])) / 2;
        mvwprintw(parent, i, x, "%s", game_over_art[i]);
    }
    wnoutrefresh(parent);
    wnoutrefresh(game_win);
    doupdate();

    wgetch(game_win);
    delwin(game_win);
}