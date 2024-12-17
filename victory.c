#include "quoridor.h"

void checkvictory(Game *game)
{
    /*
    Fonction: checkvictory
    Auteur: Evan
    Paramètres: Game game
    Traitement : Vérifie si un joueur a gagné
    Retour: void
    */
    if (game->listOfPlayers[0]->y == victoryPlayer1)
    {
        endwin();
        printf("Player 1 wins\n");
        exit(0);
    }
    else if (game->listOfPlayers[1]->y == victoryPlayer2)
    {
        endwin();
        printf("Player 2 wins\n");
        exit(0);
    }
}


GROSSE PUTE
