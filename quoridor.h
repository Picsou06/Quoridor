#ifndef HEADER_H
#define HEADER_H
#include <ncursesw/curses.h>
#include <stdlib.h>

#define BOARD_SIZE 9
#define MY_CELL_WIDTH 4
#define MAXWALL 10
#define legroscraneABassem 50

typedef struct {
    char icon;
    int color;
    int x;
    int y;
    int MovementX;
    int MovementY;
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
   Player *listOfPlayers;
   int nbPlayers;
   Wall *listOfWalls;
   int nbWalls;
   Player playerPlaying;
 } Game;

Game* createGame(int nbOfPlayer);
Player* createPlayer(char icon, int color, int x, int y);
void draw_board();
void draw_wall(int x, int y, int axe, int color);
void create_wall(Game* game, int x, int y, int axe, Player player);
void draw_all_wall(Game* game);
void displayPlayer(Game* game);
void select_player(Game* game);
void switch_player(Game* game);
void displayTempPlayer(Game* game);
#endif