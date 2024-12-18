#include "quoridor.h"

void displayPlayer(Player player) {
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;
    int row = start_row + (player.y) * 2 + 1;
    int col = start_col + (player.x) * MY_CELL_WIDTH + 2;
    attron(COLOR_PAIR(player.color));
    mvprintw(row, col, "%c", player.icon);
    attroff(COLOR_PAIR(player.color));
    refresh();
}

void displayNbWall(Game* game) {
    int x = (LINES - (BOARD_SIZE * 2 + 1)) / 2 - 1;
    int y = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;
    int number_of_wall;
    for (int i = 0; i < game->nbPlayers; i++)
    {
        number_of_wall = 0;
        for (int j = 0; j < game->nbWalls; j++)
        {
            if (game->listOfWalls[j].player.icon == game->listOfPlayers[i]->icon)
                number_of_wall++;
        }
        mvprintw(x, y, "%c Walls: %d", game->listOfPlayers[i]->icon, MAXWALL-number_of_wall);
        char number_of_wall_str[100];
        itoa(MAXWALL-number_of_wall, number_of_wall_str, 10);
        y+=BOARD_SIZE*MY_CELL_WIDTH-strlen("x Walls: ")-strlen(number_of_wall_str)+1;
    }
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

    return player;
}
