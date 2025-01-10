#include "quoridor.h"

static void choose_name(Game *game)
{
    char *name = NULL;
    free(game->name);
    game->name = NULL;
    char **files = NULL;
    int found = 0;
    int count = 0;
    get_files(&files, &count);
    int line = LINES / 2 - 2;
    int cols = COLS / 2 - strlen("#######################################################") / 2;
    clear();
    mvprintw(line - 2, cols - 2, "#######################################################");
    mvprintw(line - 1, cols - 2, "#           Maximum: 20, Alphanumerical only          #");
    mvprintw(line, cols - 2,     "#                                                     #");
    mvprintw(line + 1, cols - 2, "#                                                     #");
    mvprintw(line + 2, cols - 2, "#######################################################");
    mvprintw(line, cols,           "Name of the save: ");
    echo();
    refresh();
    scanw("%m[^\n]", &name);
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
        if (strlen(name) > 20)
            valid = 0;
        for (int i = 0; i < count; i++) {
            if (files != NULL && strcmp(name, files[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (valid)
        {
            game->name = strdup(name);
            free(name);
            return;
        } else{
            if (found)
                mvprintw(line + 1, cols, "Name already exists");
            else
                mvprintw(line + 1, cols, "Name contains invalid characters or is too long");
            refresh();
            sleep(1);
            choose_name(game);
        }
    } else {
            mvprintw(line + 1, cols, "Name contains invalid characters or is too long");
            refresh();
            sleep(1);
            choose_name(game);
        }
}

Game* createGame(int nbOfPlayer, char *name) {
    /*
    Fonction: createGame
    Auteur: Evan
    Paramètres: int nbOfPlayer
    Traitement : Crée et initialise le jeu
    Retour: void
    */
    Game* game = (Game*)malloc(sizeof(Game));
    if (game == NULL) {
        fprintf(stderr, "Memory allocation for Game failed\n");
        exit(1);
    }

    if (name != NULL)
        game->name = strdup(name);
    else
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

    game->playerPlaying = game->listOfPlayers[0];

    return game;
}
