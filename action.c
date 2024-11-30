
#include "quoridor.h"

void select_wall(Game* game) {
/*
    Fonction: select_wall
    Auteur:Evan
    Paramètres: void
    Traitement : Permet de déplacer le mur
    Retour: void
*/
    Wall currentWall = create_wall(4, 4, 0, *game->playerPlaying);
    int ch = 0;

    while (ch != '\n') {
        ch = getch(); 
        draw_wall(5, 5, 0, 1);
        switch (ch) {
            case 's':
                redraw(game);
                select_player(game);
                return;
            case KEY_UP:
                if (currentWall.y > 0 )
                {
                    redraw(game);
                    currentWall.y -= 1;
                    draw_wall(currentWall.x, currentWall.y, currentWall.axes, game->playerPlaying->color);
                    break;
                }
            case KEY_DOWN:
                if (currentWall.y < 9) {
                    redraw(game);
                    currentWall.y += 1;
                    draw_wall(currentWall.x, currentWall.y, currentWall.axes, game->playerPlaying->color);
                    break;
                }
            case KEY_LEFT:
                if (currentWall.x > 0) {
                    redraw(game);
                    currentWall.x -= 1;
                    draw_wall(currentWall.x, currentWall.y, currentWall.axes, game->playerPlaying->color);
                    break;
                }
            case KEY_RIGHT:
                if (currentWall.x < 9) {
                    redraw(game);
                    currentWall.x += 1;
                    draw_wall(currentWall.x, currentWall.y, currentWall.axes, game->playerPlaying->color);
                    break;
                }
            case ' ':
                redraw(game);
                currentWall.axes = !currentWall.axes;
                draw_wall(currentWall.x, currentWall.y, currentWall.axes, game->playerPlaying->color);
                break;
            case '\n':
                add_wall(game, currentWall);
                redraw(game);
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
    Player* currentPlayer = createPlayer(game->playerPlaying->icon, game->playerPlaying->color, game->playerPlaying->x, game->playerPlaying->y, game->playerPlaying->PlacementDifference);
    int ch = 0;
    while (ch != '\n') {
        ch = getch(); // Lire l'entrée utilisateur
        switch (ch) {
            case 's':
                redraw(game);
                select_wall(game);
                return;
            case KEY_UP:
                if (currentPlayer->y > 0)
                {
                    currentPlayer->y -= 1;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                break;
            case KEY_DOWN:
                if (currentPlayer->y < 8)
                {
                    currentPlayer->y += 1;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                break;
            case KEY_LEFT:
                if (currentPlayer->x > 0) 
                {
                    currentPlayer->x -= 1;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                break;
            case KEY_RIGHT:
                if (currentPlayer->x < 8)
                {
                    currentPlayer->x += 1;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                break;
            case '\n':
                game->playerPlaying->x = currentPlayer->x;
                game->playerPlaying->y = currentPlayer->y;
                redraw(game);
                switch_player(game);
                select_player(game);
                break;
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
    int emplacement = 0;

    for (int i = 0; i < game->nbPlayers; i++)
    {
        if (game->playerPlaying->icon == game->listOfPlayers[i]->icon)
            emplacement = i;
    }
    emplacement++;
    if(emplacement >= game->nbPlayers)
        emplacement = 0;
    game->playerPlaying = game->listOfPlayers[emplacement];
}