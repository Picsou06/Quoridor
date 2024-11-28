
#include "quoridor.h"

void select_wall(Game* game) {
/*
    Fonction: select_wall
    Auteur:Evan et Wylan
    Paramètres: void
    Traitement : Permet de déplacer le mur
    Retour: void
*/
    int ch = 0;

    while (ch != '\n') {
        ch = getch(); // Lire l'entrée utilisateur
        draw_wall(5, 5, 0, 1); // Afficher position mur
        switch (ch) {
            case 's':
                draw_board();
                select_player(game);
                printf("switch player\n");
                return;
            case KEY_UP:
                if (game->playerPlaying.yWall > 0 ) game->playerPlaying.yWall -= 1;
                break;
            case KEY_DOWN:
                if (game->playerPlaying.yWall < 9) game->playerPlaying.yWall += 1;
                break;
            case KEY_LEFT:
                if (game->playerPlaying.xWall > 0) game->playerPlaying.xWall -= 1;
                break;
            case KEY_RIGHT:
                if (game->playerPlaying.xWall < 9) game->playerPlaying.xWall += 1;
                break;
            case ' ':
                game->playerPlaying.axes = !game->playerPlaying.axes;
                break;
            case '\n':
                draw_wall(5, 5, 0, 1);(game);
                draw_board();
                switch_player(game);
                select_player(game);
        }
    }
}

void select_player(Game* game)
/*
    Fonction: select_player
    Auteur:Evan et Wylan et thomas
    Paramètres: void
    Traitement : Permet de déplacer le joueur 
    Retour: void
*/
{
    int ch = 0;
    while (ch != '\n') {
        ch = getch(); // Lire l'entrée utilisateur
        switch (ch) {
            case 's':
                draw_board();
                displayPlayer(game);
                select_wall(game);
                printf("switch wall\n");
            case KEY_UP:
                if (game->playerPlaying.MovementY > game->playerPlaying.limitDown )
                {
                    game->playerPlaying.MovementY -= 1;
                    displayTempPlayer(game);
                    printf("up\n");
                } else {
                    printf("%i, %i, %i, %i up impossible\n", game->playerPlaying.limitRight, game->playerPlaying.limitLeft, game->playerPlaying.limitUp, game->playerPlaying.limitDown);
                }
                break;
            case KEY_DOWN:
                if (game->playerPlaying.MovementY < game->playerPlaying.limitUp )
                {
                    game->playerPlaying.MovementY += 1;
                    displayTempPlayer(game);
                    printf("down\n");
                } else {
                    printf("%i, %i, %i, %i down impossible\n", game->playerPlaying.MovementY, game->playerPlaying.MovementX, game->playerPlaying.limitDown, game->playerPlaying.limitUp);
                }
                break;
            case KEY_LEFT:
                if (game->playerPlaying.MovementX > game->playerPlaying.limitLeft)
                {
                    game->playerPlaying.MovementX -= 1;
                    displayTempPlayer(game);
                    printf("left\n");
                } else {
                    printf("%i, %i, %i, %i left impossible\n", game->playerPlaying.MovementY, game->playerPlaying.MovementX, game->playerPlaying.limitRight, game->playerPlaying.limitLeft);
                }
                break;
            case KEY_RIGHT:
                if (game->playerPlaying.MovementX < game->playerPlaying.limitRight ) 
                {
                    game->playerPlaying.MovementX += 1;
                    displayTempPlayer(game);
                    printf("right\n");
                } else {
                    printf("%i, %i, %i, %i right impossible\n", game->playerPlaying.MovementY, game->playerPlaying.MovementX, game->playerPlaying.limitRight, game->playerPlaying.limitLeft);
                }
                break;
            case '\n':
                draw_board();
                game->playerPlaying.x = game->playerPlaying.MovementX;
                game->playerPlaying.y = game->playerPlaying.MovementY;
                displayPlayer(game);
                switch_player(game);
                select_player(game);
        }
    }
}

void switch_player(Game* game){
/*
    Fonction: switch_player
    Auteur:Thomas et Evan
    Paramètres: void
    Traitement : Permet de changer de joueur
    Retour: void
*/
    Player player = game->playerPlaying;
    int emplacement = 0;

    while (game->listOfPlayers[emplacement].icon != game->playerPlaying.icon)
        emplacement++;
    emplacement++;
    if(emplacement>game->nbPlayers)
        emplacement=0;
    game->playerPlaying=game->listOfPlayers[emplacement];
    game->playerPlaying.MovementX=game->playerPlaying.x;
    game->playerPlaying.MovementY=game->playerPlaying.y;

    select_player(game);
}