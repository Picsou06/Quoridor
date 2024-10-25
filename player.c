#include "header.h"

Player createPlayer(char icon, int color) {
    /*
    Fonction: createPlayer
    Auteur: Evan
    Paramètres: void
    Traitement : Crée un joueur avec des valeurs par défaut
    Retour: Player
    */
    Player player;
    player.icon = icon;
    player.color = color;
    player.x = 0;
    player.y = 0;
    player.xWall = 5;
    player.yWall = 5;
    player.nbWall = MAXWALL;
    player.axes = 0;
    return player;
}