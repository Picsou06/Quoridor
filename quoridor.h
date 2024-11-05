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
    int movementx;
    int movementy;
    int team;
    int nbWall;
    int xWall;
    int yWall;
    int axes;
    int limitRight;
    int limitLeft;
    int limitUp;
    int limitDown;
 } Player;

 typedef struct {
   int x;
   int y;
   int axes;
   Player player;
 } Wall;

  typedef struct {
      char board[BOARD_SIZE*5][BOARD_SIZE*3];
      char color[BOARD_SIZE*5][BOARD_SIZE*3];
 } Board;

 typedef stuct {
   *Player listOfPlayers;
   int nbPlayers;
   *Wall listOfWalls;
   int nbWalls;
   Board board;
 } Game;

void draw_board();
void draw_wall(Player player);
void select_wall(Player player, Player PlayerNotPlaying);
void select_player(Player player, Player PlayerNotPlaying);
Player createPlayer(char icon, int color, int x, int y, int team);
void displayPlayer(Player player);
void redraw(Player Player1, Player Player2);

#endif