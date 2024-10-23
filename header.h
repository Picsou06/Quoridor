#ifndef HEADER_H
#define HEADER_H
#include <ncursesw/curses.h>

#define BOARD_SIZE 9
#define MY_CELL_WIDTH 4
#define Player1axes 0
#define Player1x 5
#define Player1y 5
#define Player2axes 0
#define Player2x 5
#define Player2y 5

void draw_board();
void draw_wall(int row, int col, int color, int angle);
void select_wall();

#endif
