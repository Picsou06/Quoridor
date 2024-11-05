#include "quoridor.h"

Player createPlayer(char icon, int color, int x, int y, int team) {
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
    player.x = x;
    player.y = y;
    player.team = team;
    player.xWall = 5;
    player.yWall = 5;
    player.nbWall = MAXWALL;
    player.axes = 0;
    return player;
}