#include "quoridor.h"

void draw_wall(int x, int y, int axe, int color) {
    /*
    Fonction: draw_wall;
    Auteur: Evan
    Paramètres: void
    Traitement : Dessine les murs dans la Console
    Retour: void
    */
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;
    int col = (x*4) + start_col;
    int row = (y*2) + start_row;
    attron(COLOR_PAIR(color));
    if (axe == 0) {
        if (x > 0) {
            mvprintw(row, col - 4, "#");
            mvprintw(row, col - 3, "#");
            mvprintw(row, col - 2, "#");
            mvprintw(row, col - 1, "#");
        }
        if (x < BOARD_SIZE) {
            mvprintw(row, col + 1, "#");
            mvprintw(row, col + 2, "#");
            mvprintw(row, col + 3, "#");
            mvprintw(row, col + 4, "#");
        }
        mvprintw(row, col, "#");
    } else {
        if (y > 0) {
            mvprintw(row - 2, col, "#");
            mvprintw(row - 1, col, "#");
        }
        if (y < BOARD_SIZE) {
            mvprintw(row + 1, col, "#");
            mvprintw(row + 2, col, "#");
        }
        mvprintw(row, col, "#");
    }
    attroff(COLOR_PAIR(color));
}

void draw_all_wall(Game* game)
{
    /*
    Fonction: draw_all_wall
    Auteur:Evan
    Paramètres: Game* game
    Traitement : Dessine tous les murs
    Retour: void
    */
    int i = 0;

    while(i < game->nbWalls)
    {
        draw_wall(game->listOfWalls[i].x, game->listOfWalls[i].y, game->listOfWalls[i].axes, game->listOfWalls[i].player.color);
        i++;
    }
}

Wall create_wall(int x, int y, int axes, Player player)
{
    /*
    Fonction: create_wall
    Auteur:Evan
    Paramètres: int x, int y, int axes, Player player
    Traitement : Crée un mur
    Retour: wall
    */
    Wall wall;
    wall.x = x;
    wall.y = y;
    wall.axes = axes;
    wall.player = player;
    return wall;
}

void add_wall(Game* game, Wall wall)
{
    /*
    Fonction: add_wall
    Auteur:Evan
    Paramètres: Game* game, Wall wall
    Traitement : Ajoute un mur
    Retour: void
    */
    game->listOfWalls[game->nbWalls] = wall;
    game->nbWalls++;
}