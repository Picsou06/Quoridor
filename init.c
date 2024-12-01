#include "quoridor.h"

Game* createGame(int nbOfPlayer) {
    Game* game = (Game*)malloc(sizeof(Game));
    if (game == NULL) {
        fprintf(stderr, "Memory allocation for Game failed\n");
        exit(1);
    }

    // Alloue de la mémoire pour le tableau de structures Player
    game->listOfPlayers = (Player**)malloc(nbOfPlayer * sizeof(Player));
    if (game->listOfPlayers == NULL) {
        fprintf(stderr, "Memory allocation for players failed\n");
        free(game);
        exit(1);
    }

    // Crée et initialise les joueurs dynamiquement
    game->listOfPlayers[0] = createPlayer('X', 0, 4, 0);
    if (nbOfPlayer > 1) {
        game->listOfPlayers[1] = createPlayer('O', 1, 4, 8);
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