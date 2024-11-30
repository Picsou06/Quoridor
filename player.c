#include "quoridor.h"

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