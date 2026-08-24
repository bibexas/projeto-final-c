#include <ncurses.h>
#include <stddef.h>
#include <string.h>

#define BLOCK_ROWS 4
#define BLOCK_COLS 4

static const int block_values[] = {
    2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

static short block_colour(int value)
{
    switch (value)
    {
    case 2:
        return 1;
    case 4:
        return 2;
    case 8:
        return 3;
    case 16:
        return 4;
    case 32:
        return 5;
    case 64:
        return 6;
    case 128:
        return 7;
    case 256:
        return 8;
    case 512:
        return 9;
    case 1024:
        return 10;
    case 2048:
        return 11;
    default:
        return 0;
    }
}

void block_init_colours(void)
{
    if (!has_colors())
        return;

    start_color();
    use_default_colors();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    init_pair(3, COLOR_WHITE, COLOR_RED);
    init_pair(4, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(5, COLOR_WHITE, COLOR_BLUE);
    init_pair(6, COLOR_WHITE, COLOR_GREEN);
    init_pair(7, COLOR_BLACK, COLOR_CYAN);
    init_pair(8, COLOR_BLACK, COLOR_GREEN);
    init_pair(9, COLOR_WHITE, COLOR_RED);
    init_pair(10, COLOR_BLACK, COLOR_YELLOW);
    init_pair(11, COLOR_BLACK, COLOR_WHITE);
}

void block_draw(WINDOW *win, int row, int col, int value)
{
    int height, width, cell_height, cell_width;
    int y, x, text_y, text_x;
    char text[6];

    if (win == NULL || row < 0 || row >= BLOCK_ROWS ||
        col < 0 || col >= BLOCK_COLS)
        return;

    getmaxyx(win, height, width);
    y = row * height / BLOCK_ROWS;
    x = col * width / BLOCK_COLS;
    cell_height = (row + 1) * height / BLOCK_ROWS - y;
    cell_width = (col + 1) * width / BLOCK_COLS - x;
    if (cell_height < 1 || cell_width < 1)
        return;

    snprintf(text, sizeof text, "%d", value);

    if (has_colors())
        wattron(win, COLOR_PAIR(block_colour(value)));
    for (int yy = 0; yy < cell_height; ++yy)
        mvwhline(win, y + yy, x, ' ', cell_width);

    text_y = y + cell_height / 2;
    text_x = x + (cell_width - (int)strlen(text)) / 2;
    if (text_y < height && text_x >= x && text_x + (int)strlen(text) <= x + cell_width)
        mvwprintw(win, text_y, text_x, "%s", text);
    if (has_colors())
        wattroff(win, COLOR_PAIR(block_colour(value)));
}

const int *block_values_get(size_t *count)
{
    if (count != NULL)
        *count = sizeof block_values / sizeof block_values[0];
    return block_values;
}
