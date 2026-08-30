#ifndef SCORES_H
#define SCORES_H

#include <ncurses.h>

void save_score(const char *username, int score);
void show_leaderboard(WINDOW *win);
void ask_username(WINDOW *parent, char *username, int max_len);


#endif