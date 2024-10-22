#ifndef HEADER_H
#define HEADER_H
#include <ncursesw/curses.h>

#define BOARD_SIZE 9
#define MY_CELL_WIDTH 4

void draw_board();
void draw_wall(int row, int col, int color, int angle);
void select_wall();

#endif
