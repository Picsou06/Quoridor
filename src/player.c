#include "quoridor.h"

void displayPlayer(Player player) {
    /*
    Fonction: displayPlayer
    Auteur:Evan
    Paramètres: Player player
    Traitement : Permet d'afficher le joueur
    Retour: void
    */
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
    /*
    Fonction: displayNbWall
    Auteur:Evan
    Paramètres: Game* game
    Traitement : Dessine le tableau de format 9*9 dans la Console
    Retour: void
    */
    int x = (LINES - (BOARD_SIZE * 2 + 1)) / 2 - 1;
    int y = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;
    int number_of_wall;
    char number_of_wall_str[100]; // Move the declaration here
    for (int i = 0; i < game->nbPlayers; i++)
    {
        number_of_wall = 0;
        for (int j = 0; j < game->nbWalls; j++)
        {
            if (game->listOfWalls[j].player.icon == game->listOfPlayers[i]->icon)
                number_of_wall++;
        }
        
        if (game->listOfPlayers[i]->icon == game->playerPlaying->icon)
        {
            attron(COLOR_PAIR(game->listOfPlayers[i]->color));
            attron(A_BOLD);
        }
        mvprintw(x, y, "%c Walls: %d", game->listOfPlayers[i]->icon, MAXWALL-number_of_wall);
        attroff(COLOR_PAIR(game->listOfPlayers[i]->color));
        attroff(A_BOLD);
        sprintf(number_of_wall_str, "%d", MAXWALL-number_of_wall);
        y+=BOARD_SIZE*MY_CELL_WIDTH-strlen("X Walls: ")-strlen(number_of_wall_str)+1;
    }
}

void displayAllPlayer(Game* game) {
    /*
    Fonction: displayAllPlayer
    Auteur:Evan
    Paramètres: Game* game
    Traitement : Permet d'afficher tous les joueurs
    Retour: void
    */
    for (int i = 0; i < game->nbPlayers; i++) {
        displayPlayer(*game->listOfPlayers[i]);
    }
}

void displayTempPlayer(Game* game, Player currentPlayer) {
    /*
    Fonction: displayTempPlayer
    Auteur:Evan
    Paramètres: Game* game, Player currentPlayer
    Traitement : Permet d'afficher le joueur temporaire
    Retour: void
    */
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
    /*
    Fonction: createPlayer
    Auteur:Evan
    Paramètres: char icon, int color, int x, int y
    Traitement : Crée et initialise un joueur
    Retour: void
    */
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
