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
      char board[BOARD_SIZE*3][BOARD_SIZE*5];
      int color[BOARD_SIZE*3][BOARD_SIZE*5];
 } Board;

typedef struct {
   Player *listOfPlayers;
   int nbPlayers;
   Wall *listOfWalls;
   int nbWalls;
   Board board;
   Player playerPlaying;
 } Game;

Game createGame(int nbOfPlayer);
Player createPlayer(char icon, int color, int x, int y, int team, int limitRight, int limitLeft, int limitUp, int limitDown);
Board createBoard();
void save_board(Game game);
void draw_board(Game game);
void draw_wall(Game game);
void displayPlayer(Game game);
void select_player(Game game);
void switch_player(Game game);
void displayTempPlayer(Game game);
#endif