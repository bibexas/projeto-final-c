#include <ncurses.h>
#include <stdio.h>
#include "menu.h"
#include "board.h"
#include "game.h"
#include "block.h"

int main(void)
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    block_init_colours();

    WINDOW *parent = init_board();
    keypad(parent, TRUE);
    werase(parent);
    box(parent, 0, 0);
    wrefresh(parent);

    int opcao = show_menu();

    if (opcao == 1)
    {
        start_game(parent);
    }
    else if (opcao == 2)
    {
        endwin();
        return 0;
    }

    endwin();
    return 0;
}