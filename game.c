#include <stdio.h>
#include "menu.h"

int main ()
{
    show_menu();
    int opcao;
    scanf ("%d", &opcao);
    getchar();
    switch(opcao)
    {
        case 1:
            printf("Iniciando o jogo...\n");
            break;
        case 2:
            printf("Leaderboard\n");
            break;
        case 3:
            printf("Até logo!\n");
            return 0;
        default:
            printf("Opcao invalida");
            return 0;
        }
}