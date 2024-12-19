#ifndef HEADER_H
#define HEADER_H
#include <ncursesw/curses.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"

#define BOARD_SIZE 9
#define MY_CELL_WIDTH 4
#define MAXWALL 10
#define victoryPlayer1 8
#define victoryPlayer2 0


typedef struct {
   char icon;
   int color;
   int x;
   int y;
} Player;

typedef struct {
   int x;
   int y;
   int axes;
   Player player;
} Wall;

typedef struct {
   Player **listOfPlayers;
   int nbPlayers;
   Wall *listOfWalls;
   int nbWalls;
   Player *playerPlaying;
} Game;

// Function declarations for Game
Game* createGame(int nbOfPlayer);
void checkvictory(Game *game);
void chooseOptions();
void save_game(Game game);
void load_game();

// Function declarations for Player
Player* createPlayer(char icon, int color, int x, int y);
void displayPlayer(Player Player);
void displayNbWall(Game* game);
void displayTempPlayer(Game* game, Player currentPlayer);
void displayAllPlayer(Game* game);
void select_player(Game* game);
void switch_player(Game* game);
bool check_player_mouvement(Game *game, int x, int y);
bool check_player_superposition(Game *game, int x, int y);
bool check_player_passwall(Game *game, char mouvement, int x, int y);

// Function declarations for Wall
Wall create_wall(int x, int y, int axes, Player player);
void add_wall(Game* game, Wall wall);
void draw_wall(int x, int y, int axe, int color);
void draw_all_wall(Game* game);
bool can_place_wall(Game* game, Wall wall);
bool is_path_possible(Game* game, Player* player, int target_y);
bool is_wall_at_placement(Game* game, int x, int y, int axes);

// Function declarations for drawing
void draw_board();
void redraw(Game* game);


#endif