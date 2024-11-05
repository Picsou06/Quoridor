#include "quoridor.h"
void select_wall(Player player, Player PlayerNotPlaying) {
/*
    Fonction: select_wall
    Auteur:Evan et Wylan
    Paramètres: void
    Traitement : Permet de déplacer le mur
    Retour: void
*/
    int ch = 0;
    
    // Sauvegarder l'état actuel du tableau
    char board_backup[LINES][COLS];
    int color_backup[LINES][COLS];
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLS; j++) {
            board_backup[i][j] = mvinch(i, j) & A_CHARTEXT;
            color_backup[i][j] = mvinch(i, j) & A_COLOR;
        }
    }

    while (ch != '\n') {
        ch = getch(); // Lire l'entrée utilisateur
        draw_wall(player); // Afficher position mur
        switch (ch) {
            case 's':
                // Restaurer l'état du tableau sauvegardé
                for (int i = 0; i < LINES; i++) {
                    for (int j = 0; j < COLS; j++) {
                        mvaddch(i, j, board_backup[i][j]);
                    }
                }
                select_player(player, PlayerNotPlaying);
                printf("switch player\n");
                return;
            case KEY_UP:
                if (player.yWall > 0 ) player.yWall -= 1;
                break;
            case KEY_DOWN:
                if (player.yWall < 9) player.yWall += 1;
                break;
            case KEY_LEFT:
                if (player.xWall > 0) player.xWall -= 1;
                break;
            case KEY_RIGHT:
                if (player.xWall < 9) player.xWall += 1;
                break;
            case ' ':
                player.axes = !player.axes;
                break;
            case '\n':
                // Restaurer l'état du tableau sauvegardé
                for (int i = 0; i < LINES; i++) {
                    for (int j = 0; j < COLS; j++) {
                        attron(COLOR_PAIR(color_backup[i][j]));
                        mvaddch(i, j, board_backup[i][j]);
                        attroff(COLOR_PAIR(color_backup[i][j]));
                    }
                }

                refresh();
                draw_wall(player);
                return;
        }
        // Restaurer l'état du tableau sauvegardé
                for (int i = 0; i < LINES; i++) {
                    for (int j = 0; j < COLS; j++) {
                        attron(COLOR_PAIR(color_backup[i][j]));
                        mvaddch(i, j, board_backup[i][j]);
                        attroff(COLOR_PAIR(color_backup[i][j]));
                    }
                }

        refresh();
        draw_wall(player);
        printf("Wall created on: %d : %d\n", player.x, player.y);
    }
}

void select_player(Player player, Player PlayerNotPlaying)
/*
    Fonction: select_player
    Auteur:Evan 
    Paramètres: void
    Traitement : Permet de déplacer le joueur 
    Retour: void
*/
{
    int ch = 0;
    
    // Sauvegarder l'état actuel du tableau
    char board_backup[LINES][COLS];
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLS; j++) {
            board_backup[i][j] = mvinch(i, j);
        }
    }

    while (ch != '\n') {
        ch = getch(); // Lire l'entrée utilisateur
        switch (ch) {
            case 's':
                // Restaurer l'état du tableau sauvegardé
                for (int i = 0; i < LINES; i++) {
                    for (int j = 0; j < COLS; j++) {
                        mvaddch(i, j, board_backup[i][j]);
                    }
                }
                select_wall(player, PlayerNotPlaying);
                printf("switch wall\n");
                return;
            case KEY_UP:
                if (player.y > player.limitUp ) player.movementy -= 1;
                break;
            case KEY_DOWN:
                if (player.y < player.limitDown ) player.movementy += 1;
                break;
            case KEY_LEFT:
                if (player.x > player.limitLeft) player.movementx -= 1;
                break;
            case KEY_RIGHT:
                if (player.x < player.limitRight ) player.movementx += 1;
                break;
            case '\n':

        
                // Restaurer l'état du tableau sauvegardé
                for (int i = 0; i < LINES; i++) {
                    for (int j = 0; j < COLS; j++) {
                        mvaddch(i, j, board_backup[i][j]);
                    }
                }
                refresh();
                select_player(PlayerNotPlaying, player);
                return;
        }
        // Restaurer l'état du tableau sauvegardé
        for (int i = 0; i < LINES; i++) {
            for (int j = 0; j < COLS; j++) {
                mvaddch(i, j, board_backup[i][j]);
            }
        }
        
        redraw(player, PlayerNotPlaying);
        refresh();
    }
}