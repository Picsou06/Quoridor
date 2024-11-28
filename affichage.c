#include "quoridor.h"

void draw_wall(int x, int y, int axe, int color) {
    /*
    Fonction: draw_wall(5, 5, 0, 1);
    Auteur: Evan
    Paramètres: void
    Traitement : Dessine les murs dans la Console
    Retour: void
    */
   printf("Couleur: %i", color);
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
    int i = 0;

    while(i < game->nbWalls)
    {
        draw_wall(game->listOfWalls[i].x, game->listOfWalls[i].y, game->listOfWalls[i].axes, game->listOfWalls[i].player.color);
        i++;
    }
    printf("Wall showed: %d, %d", game->nbWalls, i);
}

void create_wall(Game* game, int x, int y, int axes, Player player)
{
    game->listOfWalls[game->nbWalls].x = x;
    game->listOfWalls[game->nbWalls].y = y;
    game->listOfWalls[game->nbWalls].axes = axes;
    game->listOfWalls[game->nbWalls].player = player;
    game->nbWalls++;
    printf("Wall created: %d", game->nbWalls);
}

void displayPlayer(Game* game) {
    // Calculate the starting position to center the board
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;

    // Calculate the position to display the player
    int row = start_row + game->listOfPlayers[0].y * 2 + game->listOfPlayers[0].team;
    int col = start_col + game->listOfPlayers[0].x * MY_CELL_WIDTH + MY_CELL_WIDTH / 2;

    // Apply the player's color
    attron(COLOR_PAIR(game->listOfPlayers[0].color));
    mvprintw(row, col, "%c", game->listOfPlayers[0].icon);
    attroff(COLOR_PAIR(game->listOfPlayers[0].color));

    row = start_row + game->listOfPlayers[1].y * 2 + game->listOfPlayers[1].team;
    col = start_col + game->listOfPlayers[1].x * MY_CELL_WIDTH + MY_CELL_WIDTH / 2;

    attron(COLOR_PAIR(game->listOfPlayers[1].color));
    mvprintw(row, col, "%c", game->listOfPlayers[1].icon);
    attroff(COLOR_PAIR(game->listOfPlayers[1].color));
    refresh();
}

void displayTempPlayer(Game* game) {
    draw_board();
    // Calculate the starting position to center the board
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;

    // Calculate the position to display the player
    int row = start_row + game->listOfPlayers[0].MovementY * 2 + game->listOfPlayers[0].team;
    int col = start_col + game->listOfPlayers[0].MovementX * MY_CELL_WIDTH + MY_CELL_WIDTH / 2;

    // Apply the player's color
    attron(COLOR_PAIR(game->listOfPlayers[0].color));
    mvprintw(row, col, "%c", game->listOfPlayers[0].icon);
    attroff(COLOR_PAIR(game->listOfPlayers[0].color));

    row = start_row + game->listOfPlayers[1].MovementY * 2 + game->listOfPlayers[1].team;
    col = start_col + game->listOfPlayers[1].MovementX * MY_CELL_WIDTH + MY_CELL_WIDTH / 2;

    attron(COLOR_PAIR(game->listOfPlayers[1].color));
    mvprintw(row, col, "%c", game->listOfPlayers[1].icon);
    attroff(COLOR_PAIR(game->listOfPlayers[1].color));
    refresh();
}

void redraw(Game* game) {
    clear();
    draw_board();
    displayPlayer(game);
    refresh();
}