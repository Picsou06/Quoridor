
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
    Player* currentPlayer = createPlayer(game->playerPlaying->icon, game->playerPlaying->color, game->playerPlaying->x, game->playerPlaying->y);
    int ch = 0;
    while (ch != '\n') {
        ch = getch(); // Lire l'entrée utilisateur
        switch (ch) {
            case 's':
                redraw(game);
                select_wall(game);
                return;
            case KEY_UP:
                if (check_player_mouvement(game, currentPlayer->x, currentPlayer->y - 1))
                {
                    currentPlayer->y -= 1;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                else if (check_player_superposition(game, currentPlayer->x, currentPlayer->y - 1))
                {
                    currentPlayer->y -= 2;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                break;
            case KEY_DOWN:
                if (check_player_mouvement(game, currentPlayer->x, currentPlayer->y + 1))
                {
                    currentPlayer->y += 1;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                else if (check_player_superposition(game, currentPlayer->x, currentPlayer->y + 1))
                {
                    currentPlayer->y += 2;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                break;
            case KEY_LEFT:
                if (check_player_mouvement(game, currentPlayer->x - 1, currentPlayer->y))
                {
                    currentPlayer->x -= 1;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                else if (check_player_superposition(game, currentPlayer->x - 1, currentPlayer->y))
                {
                    currentPlayer->x -= 2;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                break;
            case KEY_RIGHT:
                if (check_player_mouvement(game, currentPlayer->x + 1, currentPlayer->y))
                {
                    currentPlayer->x += 1;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                else if (check_player_superposition(game, currentPlayer->x + 1, currentPlayer->y))
                {
                    currentPlayer->x += 2;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                break;
            case '\n':
                game->playerPlaying->x = currentPlayer->x;
                game->playerPlaying->y = currentPlayer->y;
                checkvictory(game);
                redraw(game);
                switch_player(game);
                select_player(game);
                break;
        }
    }
}

bool check_player_mouvement(Game *game, int x, int y)
{
    /*
    Fonction: check_player_mouvement
    Auteur: Evan
    Paramètres: Game game, Player currentPlayer, int x, int y
    Traitement : Vérifie si le joueur peut se déplacer
    Retour: bool
    */
    if (x < 0 || x > 8 || y < 0 || y > 8)
        return false;
    if ((abs(x - game->playerPlaying->x) > 1 || abs(y - game->playerPlaying->y) > 1) || (abs(x - game->playerPlaying->x) == 1 && abs(y - game->playerPlaying->y) == 1))
        return false;
    int opponent = 0;

    for (int i = 0; i < game->nbPlayers; i++)
    {
        if (game->playerPlaying->icon == game->listOfPlayers[i]->icon)
            opponent = i;
    }
    opponent++;
    if(opponent >= game->nbPlayers)
        opponent = 0;
    if (game->listOfPlayers[opponent]->x == x && game->listOfPlayers[opponent]->y == y)
        return false;
    if (!check_player_passwall)
        return false;
    return true;
}

bool check_player_superposition(Game *game, int x, int y)
{
    /*
    Fonction: check_player_superposition
    Auteur: Evan
    Paramètres: Game game, Player currentPlayer, int x, int y
    Traitement : Vérifie si le joueur peut se déplacer
    Retour: bool
    */
    int opponent = 0;

    for (int i = 0; i < game->nbPlayers; i++)
    {
        if (game->playerPlaying->icon == game->listOfPlayers[i]->icon)
            opponent = i;
    }
    opponent++;
    if(opponent >= game->nbPlayers)
        opponent = 0;
    if (game->listOfPlayers[opponent]->x != x || game->listOfPlayers[opponent]->y != y)
        return false;
    if (x < 0 || x > 8 || y < 0 || y > 8)
        return false;
    if (!check_player_passwall)
        return false;
    return true;
}

bool check_player_passwall(Game *game, int x, int y)
{
    return true;
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