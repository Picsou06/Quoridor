#include "quoridor.h"

void redraw(Game* game) {
    /*
    Fonction: redraw
    Auteur:Wylan
    Paramètres: void
    Traitement : Permet de rafraichir l'écran
    Retour: void
    */
    clear();
    draw_board();
    draw_all_wall(game);
    displayAllPlayer(game);
    displayNbWall(game);
    refresh();
}