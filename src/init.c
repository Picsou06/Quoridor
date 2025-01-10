#include "quoridor.h"

static void choose_name(Game *game)
{
    char *name = NULL;
    free(game->name);
    game->name = NULL;
    int line = LINES / 2 - 1;
    int cols = COLS / 2 - sizeof("Name of the save: ") / 2;
    clear();
    mvprintw(line, 0, "Name of the save: ");
    echo();
    refresh();
    scanw("%ms", &name);
    noecho();
    if (name != NULL)
    {
        int valid = 1;
        for (int i = 0; i < strlen(name); i++)
        {
            if (!isalnum(name[i]) || !isprint(name[i]))
            {
                valid = 0;
                break;
            }
        }
        if (valid)
        {
            game->name = strdup(name);
            free(name);
            return;
        } else{
            mvprintw(line + 1, 0, "Name contains invalid characters or is too long");
            refresh();
            sleep(1);
            choose_name(game);
        }
    } else{
            mvprintw(line + 1, 0, "Name contains invalid characters or is too long");
            refresh();
            sleep(1);
            choose_name(game);
        }
}

Game* createGame(int nbOfPlayer) {
    /*
    Fonction: createGame
    Auteur:Evan
    Paramètres: int nbOfPlayer
    Traitement : Crée et initialise le jeu
    Retour: void
    */
    Game* game = (Game*)malloc(sizeof(Game));
    if (game == NULL) {
        fprintf(stderr, "Memory allocation for Game failed\n");
        exit(1);
    }

    choose_name(game);


    // Alloue de la mémoire pour le tableau de structures Player
    game->listOfPlayers = (Player**)malloc(nbOfPlayer * sizeof(Player));
    if (game->listOfPlayers == NULL) {
        fprintf(stderr, "Memory allocation for players failed\n");
        free(game);
        exit(1);
    }

    // Crée et initialise les joueurs dynamiquement
    game->listOfPlayers[0] = createPlayer('X', 1, 4, 0);
    if (nbOfPlayer > 1) {
        game->listOfPlayers[1] = createPlayer('O', 2, 4, 8);
    }
    game->nbPlayers = nbOfPlayer;

    // Alloue de la mémoire pour les murs
    game->listOfWalls = (Wall*)malloc(MAXWALL * nbOfPlayer * sizeof(Wall));
    if (game->listOfWalls == NULL) {
        fprintf(stderr, "Memory allocation for walls failed\n");
        free(game->listOfPlayers); // Libère le tableau de joueurs
        free(game);
        exit(1);
    }
    game->nbWalls = 0;

    // Initialise le joueur qui joue
    game->playerPlaying = game->listOfPlayers[0];

    return game;
}
