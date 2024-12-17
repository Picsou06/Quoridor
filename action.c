
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
    redraw(game);
    draw_wall(currentWall.x, currentWall.y, currentWall.axes, game->playerPlaying->color);
    int ch = 0;

    while (ch != '\n') {
        ch = getch();
        draw_wall(5, 5, 0, 1);
        switch (ch) {
            case '5':
            case 's':
                redraw(game);
                select_player(game);
                return;
            case '8':
            case KEY_UP:
                if (currentWall.y > 0)
                {
                    redraw(game);
                    currentWall.y -= 1;
                    draw_wall(currentWall.x, currentWall.y, currentWall.axes, game->playerPlaying->color);
                }
                break;
            case '2':
            case KEY_DOWN:
                if (currentWall.y < 9) {
                    redraw(game);
                    currentWall.y += 1;
                    draw_wall(currentWall.x, currentWall.y, currentWall.axes, game->playerPlaying->color);
                }
                break;
            case '4':
            case KEY_LEFT:
                if (currentWall.x > 0) {
                    redraw(game);
                    currentWall.x -= 1;
                    draw_wall(currentWall.x, currentWall.y, currentWall.axes, game->playerPlaying->color);
                }
                break;
            case '6':
            case KEY_RIGHT:
                if (currentWall.x < 9) {
                    redraw(game);
                    currentWall.x += 1;
                    draw_wall(currentWall.x, currentWall.y, currentWall.axes, game->playerPlaying->color);
                }
                break;
            case '0':
            case ' ':
                redraw(game);
                currentWall.axes = !currentWall.axes;
                draw_wall(currentWall.x, currentWall.y, currentWall.axes, game->playerPlaying->color);
                break;
            case '\n':
                if (can_place_wall(game, currentWall))
                {
                    add_wall(game, currentWall);
                    redraw(game);
                    switch_player(game);
                    select_player(game);
                }
                else
                {
                    redraw(game);
                    select_wall(game);
                }
                break;
            default:
                break;
        }
    }
}

bool can_place_wall(Game* game, Wall wall) {
    // Vérifiez si tous les joueurs peuvent atteindre leur côté opposé
    bool path_possible = true;

    if (is_wall_at_placement(game, wall.x, wall.y, wall.axes))
        path_possible = false;

    // Ajoutez temporairement le mur
    game->listOfWalls[game->nbWalls] = wall;
    game->nbWalls++;

    for (int i = 0; i < game->nbPlayers; i++) {
        Player* player = game->listOfPlayers[i];
        int target_y = (player->icon == 'X') ? victoryPlayer1 : victoryPlayer2;
        if (!is_path_possible(game, player, target_y)) {
            path_possible = false;
            break;
        }

    }
    int number_of_wall = 0;
    for (int i = 0; i < game->nbWalls; i++)
    {
        if (game->listOfWalls[i].player.icon == game->playerPlaying->icon)
            number_of_wall++;
    }
    if (number_of_wall > MAXWALL)
        path_possible = false;
    game->nbWalls--;

    return path_possible;
}

bool is_wall_at_placement(Game* game, int x, int y, int axes) {
    for (int i = 0; i < game->nbWalls; i++) {
        Wall wall = game->listOfWalls[i];
        if (axes == 0) {
            if (wall.axes == 0) {
                if ((wall.x == x && wall.y == y) || (wall.x == x + 1 && wall.y == y) || (wall.x == x - 1 && wall.y == y)) {
                    return true;
                }
            } else { // Compare with a vertical wall
                if ((wall.x == x && wall.y == y) || (wall.x == x && wall.y == y + 1) || (wall.x == x && wall.y == y - 1)) {
                    return true;
                }
            }
        } else {
            if (wall.axes == 1) {
                if ((wall.x == x && wall.y == y) || (wall.x == x && wall.y == y + 1) || (wall.x == x && wall.y == y -1)) {
                    return true;
                }
            } else { // Compare with a horizontal wall
                if ((wall.x == x && wall.y == y)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool is_path_possible(Game* game, Player* player, int target_y) {
    int visited[BOARD_SIZE][BOARD_SIZE] = {0};
    Queue* q = createQueue();
    enqueue(q, (Point){player->x, player->y});
    visited[player->x][player->y] = 1;

    while (!isQueueEmpty(q)) {
        Point p = dequeue(q);
        int x = p.x;
        int y = p.y;

        if (y == target_y) {
            freeQueue(q);
            return true;
        }
        if (y > 0 && !visited[x][y - 1] && check_player_passwall(game, 'u', x, y - 1)) {
            enqueue(q, (Point){x, y - 1});
            visited[x][y - 1] = 1;
        }
        if (y < BOARD_SIZE - 1 && !visited[x][y + 1] && check_player_passwall(game, 'd', x, y + 1)) {
            enqueue(q, (Point){x, y + 1});
            visited[x][y + 1] = 1;
        }
        if (x > 0 && !visited[x - 1][y] && check_player_passwall(game, 'l', x - 1, y)) {
            enqueue(q, (Point){x - 1, y});
            visited[x - 1][y] = 1;
        }
        if (x < BOARD_SIZE - 1 && !visited[x + 1][y] && check_player_passwall(game, 'r', x + 1, y)) {
            enqueue(q, (Point){x + 1, y});
            visited[x + 1][y] = 1;
        }
    }

    freeQueue(q);
    return false;
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
    int number_of_wall = 0;
    while (ch != '\n') {
        ch = getch(); // Lire l'entrée utilisateur
        switch (ch) {
            case '5':
            case 's':
                number_of_wall = 0;
                for (int i = 0; i < game->nbWalls; i++)
                {
                    if (game->listOfWalls[i].player.icon == game->playerPlaying->icon)
                        number_of_wall++;
                }
                if (number_of_wall < MAXWALL)
                {
                    redraw(game);
                    select_wall(game);
                }
                break;
            case '8':
            case KEY_UP:
                if (check_player_mouvement(game, currentPlayer->x, currentPlayer->y - 1) && check_player_passwall(game, 'u', currentPlayer->x, currentPlayer->y - 1))
                {
                    currentPlayer->y -= 1;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                else if (check_player_superposition(game, currentPlayer->x, currentPlayer->y - 1) && check_player_passwall(game, 'u', currentPlayer->x, currentPlayer->y - 2))
                {
                    currentPlayer->y -= 2;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                break;
            case '2':
            case KEY_DOWN:
                if (check_player_mouvement(game, currentPlayer->x, currentPlayer->y + 1) && check_player_passwall(game, 'd', currentPlayer->x, currentPlayer->y +1))
                {
                    currentPlayer->y += 1;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                else if (check_player_superposition(game, currentPlayer->x, currentPlayer->y + 1) && check_player_passwall(game, 'u', currentPlayer->x, currentPlayer->y + 2))
                {
                    currentPlayer->y += 2;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                break;
            case '4':
            case KEY_LEFT:
                if (check_player_mouvement(game, currentPlayer->x - 1, currentPlayer->y) && check_player_passwall(game, 'l', currentPlayer->x - 1, currentPlayer->y))
                {
                    currentPlayer->x -= 1;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                else if (check_player_superposition(game, currentPlayer->x - 1, currentPlayer->y) && check_player_passwall(game, 'u', currentPlayer->x - 2, currentPlayer->y))
                {
                    currentPlayer->x -= 2;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                break;
            case '6':
            case KEY_RIGHT:
                if (check_player_mouvement(game, currentPlayer->x + 1, currentPlayer->y) && check_player_passwall(game, 'r', currentPlayer->x + 1, currentPlayer->y))
                {
                    currentPlayer->x += 1;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                else if (check_player_superposition(game, currentPlayer->x + 1, currentPlayer->y) && check_player_passwall(game, 'u', currentPlayer->x + 2, currentPlayer->y))
                {
                    currentPlayer->x += 2;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                }
                break;
           /*  case '9':
                if (check_player_superposition(game, currentPlayer->x, currentPlayer->y + 1) && check_player_passwall(game, 'u', currentPlayer->x, currentPlayer->y + 2))
                {
                    currentPlayer->y += 2;
                    draw_board();
                    draw_all_wall(game);
                    displayTempPlayer(game, *currentPlayer);
                } */
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
    return true;
}

bool check_player_passwall(Game *game, char mouvement, int x, int y)
{
    /*
    Fonction: check_player_passwall
    Auteur: Evan
    Paramètres: Game game, Player currentPlayer, int x, int y
    Traitement : Vérifie si le joueur peut se déplacer
    Retour: bool
    */
    int i = 0;

    while (i < game->nbWalls)
    {
        if (mouvement == 'r')
        {
            if (game->listOfWalls[i].axes == 1)
                if ((game->listOfWalls[i].x == x && game->listOfWalls[i].y == y) || (game->listOfWalls[i].x == x && game->listOfWalls[i].y - 1 == y))
                    return false;
        }
        else if (mouvement == 'l')
        {
            if (game->listOfWalls[i].axes == 1)
                if ((game->listOfWalls[i].x - 1 == x && game->listOfWalls[i].y == y) || (game->listOfWalls[i].x - 1 == x && game->listOfWalls[i].y - 1 == y))
                    return false;
        }
        else if (mouvement == 'd')
        {
            if (game->listOfWalls[i].axes == 0)
                if ((game->listOfWalls[i].x - 1 == x && game->listOfWalls[i].y == y) || (game->listOfWalls[i].x == x && game->listOfWalls[i].y == y))
                    return false;
        }
        else if (mouvement == 'u')
        {
            if (game->listOfWalls[i].axes == 0) {
                if ((game->listOfWalls[i].x - 1 == x && game->listOfWalls[i].y - 1 == y) || (game->listOfWalls[i].x == x && game->listOfWalls[i].y - 1 == y))
                    return false;
            }
        }
        i++;
    }
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
