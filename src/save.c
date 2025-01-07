#include "quoridor.h"

int get_player_index(Game* game, char icon) {
    /*
    Fonction: get_player_index
    Auteur:Evan
    Paramètres: Game* game, char icon
    Traitement : Retourne l'index du joueur
    Retour: int
    */
    for (int i = 0; i < game->nbPlayers; i++) {
        if (game->listOfPlayers[i]->icon == icon) {
            return i;
        }
    }
    return -1;
}

void save_game(Game game) {
    /*
    Fonction: save_game
    Auteur:Evan
    Paramètres: Game game
    Traitement : Sauvegarde la partie
    Retour: void
    */
    FILE *file = fopen("saved_game.txt", "w");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }
    fprintf(file, "%d\n", game.nbPlayers);
    for (int i = 0; i < game.nbPlayers; i++) {
        fprintf(file, "%c %d %d %d\n", game.listOfPlayers[i]->icon, game.listOfPlayers[i]->color, game.listOfPlayers[i]->x, game.listOfPlayers[i]->y);
    }
    
    fprintf(file, "%d\n", game.nbWalls);
    for (int i = 0; i < game.nbWalls; i++) {
        fprintf(file, "%d %d %d %c\n", game.listOfWalls[i].x, game.listOfWalls[i].y, game.listOfWalls[i].axes, game.listOfWalls[i].player.icon);
    }

    fprintf(file, "%c\n", game.playerPlaying->icon);

    fclose(file);
}

void load_game(){
    /*
    Fonction: load_game
    Auteur:Evan
    Paramètres: void
    Traitement : Charge la partie
    Retour: void
    */
    FILE *file = fopen("saved_game.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file for reading.\n");
        return;
    }
    int nbPlayers;
    fscanf(file, "%d", &nbPlayers);

    Game* game = createGame(nbPlayers);
    char icon; // Declare icon here
    for (int i = 0; i < nbPlayers; i++) {
        int color, x, y;
        fscanf(file, " %c %d %d %d", &icon, &color, &x, &y);
        game->listOfPlayers[i] = createPlayer(icon, color, x, y);
    }
    game->nbPlayers = nbPlayers;
    game->playerPlaying = game->listOfPlayers[get_player_index(game, icon)];

    int nbWalls;
    fscanf(file, "%d", &nbWalls);

    for (int i = 0; i < nbWalls; i++) {
        int x, y, axes;
        fscanf(file, "%d %d %d %c", &x, &y, &axes, &icon);
        game->listOfWalls[i] = create_wall(x, y, axes, *game->listOfPlayers[get_player_index(game, icon)]);
    }

    game->nbWalls = nbWalls;
    fclose(file);

    redraw(game);
    select_player(game);
}