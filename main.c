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

int estado = 0;
int a_jogar = 1;
int opcao;
while (a_jogar == 1)
{
    if (estado == 0)
    {
        opcao = show_menu();
        if (opcao == 1)
        {
            estado = 1;
        }
        else if (opcao == 3)
        {
            a_jogar = 0;
        }
    }
    else if (estado == 1)
    {
        opcao = start_game(parent);
        if (opcao == 2)
        {
            estado = 0;
        }
        else if (opcao == 3)
        {
            a_jogar = 0;
        }
    }
}

    endwin();
    return 0;
}