#include "quoridor.h"

void displayPlayer(Player player) {
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;
    int row = start_row + (player.y) * 2 + 1;
    int col = start_col + (player.x) * MY_CELL_WIDTH + 2;
    mvprintw(row, 5, "%d", player.color);
    attron(COLOR_PAIR(player.color));
    mvprintw(row, col, "%c", player.icon);
    attroff(COLOR_PAIR(player.color));
    refresh();
}

void displayAllPlayer(Game* game) {
    for (int i = 0; i < game->nbPlayers; i++) {
        displayPlayer(*game->listOfPlayers[i]);
    }
}

void displayTempPlayer(Game* game, Player currentPlayer) {
    displayPlayer(currentPlayer);
    

    int i = 0;
    while (i < game->nbPlayers) {
        if (game->listOfPlayers[i]->icon != currentPlayer.icon) {
            displayPlayer(*game->listOfPlayers[i]);
            return;
        }
        i++;
    }
}

Player* createPlayer(char icon, int color, int x, int y) {
    Player* player = (Player*)malloc(sizeof(Player));
    if (player == NULL) {
        fprintf(stderr, "Memory allocation for Player failed\n");
        exit(1);
    }

    player->icon = icon;
    player->color = color;
    player->x = x;
    player->y = y;
    player->nbWall = MAXWALL;

    return player;
}