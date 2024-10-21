#ifndef JMENFOU_H
#define JMENFOU_H
#include <ncursesw/curses.h>

#define BOARD_SIZE 9

void draw_board();
void draw_wall(int row, int col, int color, int angle);

#endif // JMENFOU_H
