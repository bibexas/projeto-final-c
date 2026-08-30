#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "scores.h"

void save_score(const char *username, int score)
{
    FILE *f = fopen("scores.txt", "a");
    if (f == NULL)
    {
        return;
    }
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(f, "%s %d %02d/%02d/%04d %02d:%02d\n",
            username, score, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
            t->tm_hour, t->tm_min);

    fclose(f);
}

typedef struct
{
    char nome[50];
    int score;
    char data[20];
    char hora[20];
} Entrada;

void show_leaderboard(WINDOW *win)
{
    FILE *f = fopen("scores.txt", "r");
    Entrada entradas[100];
    int count = 0;

    if (f != NULL)
    {
        while (count < 100 &&
                fscanf(f, "%49s %d %19s %19s",
                entradas[count].nome, &entradas[count].score, entradas[count].data, entradas[count].hora) == 4)
        {
            count++;
        }
        fclose(f);
    }
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (entradas[j].score < entradas[j + 1].score)
            {
                Entrada temp = entradas[j];
                entradas[j] = entradas[j + 1];
                entradas[j + 1] = temp;
            }
        }
    }

    werase(win);
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "LEADERBOARD - TOP 10");

    int limite = count < 10 ? count : 10;
    for (int i = 0; i < limite; i++)
    {
        mvwprintw(win, 3 + i, 2, "%2d. %-10s %6d %s %s",
                i + 1, entradas[i].nome, entradas[i].score, entradas[i].data, entradas[i].hora);
    }

    mvwprintw(win, 15, 2, "Prime qualquer tecla para voltar");
    wrefresh(win);
    wgetch(win);
}

void ask_username(WINDOW *parent, char *username, int max_len)
{
    echo();
    curs_set(1);
    mvwprintw(parent, 1, 2, "Nome: ");
    wrefresh(parent);
    wgetnstr(parent, username, max_len - 1);
    noecho();
    curs_set(0);
}

int get_highscore(void)
{
    FILE *f = fopen("scores.txt", "r");
    if (f == NULL)
    {
        return 0;
    }
    char nome[50], data[20], hora[20];
    int score, maior = 0;

    while(fscanf(f, "%49s %d %19s %19s", nome, &score, data, hora) == 4)
    {
        if (score > maior)
        {
            maior = score;
        }
    }
    fclose(f);
    return maior;
}