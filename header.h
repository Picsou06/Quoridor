#ifndef HEADER_H
#define HEADER_H
#include <ncursesw/curses.h>

#define BOARD_SIZE 9
#define MY_CELL_WIDTH 4
#define MAXWALL 10

typedef struct {
    char icon;
    int color;
    int x;
    int y;
    int nbWall;
    int xWall;
    int yWall;
    int axes;
 } Player;

void draw_board();

void draw_wall(Player player);
void timed_wall(Player player);
void select_wall();
Player createPlayer(char icon, int color);

#endif
