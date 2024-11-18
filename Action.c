
#include "quoridor.h"

void select_wall(Game game) {
/*
    Fonction: select_wall
    Auteur:Evan et Wylan
    Paramètres: void
    Traitement : Permet de déplacer le mur
    Retour: void
*/
    int ch = 0;

    save_board(game);

    while (ch != '\n') {
        ch = getch(); // Lire l'entrée utilisateur
        draw_wall(game); // Afficher position mur
        switch (ch) {
            case 's':
                draw_board(game);
                select_player(game);
                printf("switch player\n");
                return;
            case KEY_UP:
                if (game.playerPlaying.yWall > 0 ) game.playerPlaying.yWall -= 1;
                break;
            case KEY_DOWN:
                if (game.playerPlaying.yWall < 9) game.playerPlaying.yWall += 1;
                break;
            case KEY_LEFT:
                if (game.playerPlaying.xWall > 0) game.playerPlaying.xWall -= 1;
                break;
            case KEY_RIGHT:
                if (game.playerPlaying.xWall < 9) game.playerPlaying.xWall += 1;
                break;
            case ' ':
                game.playerPlaying.axes = !game.playerPlaying.axes;
                break;
            case '\n':
                draw_wall(game);
                draw_board(game);
                switch_player(game);
                select_player(game);
        }
    }
}

void select_player(Game game)
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
                draw_board(game);
                displayPlayer(game);
                select_wall(game);
                printf("switch wall\n");
            case KEY_UP:
                if (game.playerPlaying.y > game.playerPlaying.limitUp )
                {
                    game.playerPlaying.MovementY -= 1;
                    displayTempPlayer(game);
                }
                break;
            case KEY_DOWN:
                if (game.playerPlaying.y < game.playerPlaying.limitDown )
                {
                    game.playerPlaying.MovementY += 1;
                    displayTempPlayer(game);
                }
                break;
            case KEY_LEFT:
                if (game.playerPlaying.x > game.playerPlaying.limitLeft)
                {
                    game.playerPlaying.MovementX -= 1;
                    displayTempPlayer(game);
                }
                break;
            case KEY_RIGHT:
                if (game.playerPlaying.x < game.playerPlaying.limitRight ) 
                {
                    game.playerPlaying.MovementX += 1;
                    displayTempPlayer(game);
                }
                break;
            case '\n':
                draw_board(game);
                game.playerPlaying.x = game.playerPlaying.MovementX;
                game.playerPlaying.y = game.playerPlaying.MovementY;
                displayPlayer(game);
                switch_player(game);
                select_player(game);
        }
    }
}

void switch_player(Game game){
/*
    Fonction: switch_player
    Auteur: Thomas et Evan 
    Paramètres: void
    Traitement : Permet de changer de joueur
    Retour: void
*/
    Player player = game.playerPlaying;
    int emplacement = 0;

    while (game.listOfPlayers[emplacement].icon != game.playerPlaying.icon)
        emplacement++;
    emplacement++;
    if(emplacement>game.nbPlayers)
        emplacement=0;
    game.playerPlaying=game.listOfPlayers[emplacement];
    game.playerPlaying.MovementX=game.playerPlaying.x;
    game.playerPlaying.MovementY=game.playerPlaying.y;

    select_player(game);
}