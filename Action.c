#include "header.h"
void select_wall(Player player)
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
            case 'c':
                clear();
                draw_board();
                break;
            case KEY_UP:
                if (player.x > 0 ) player.x -= 1;
                break;
            case KEY_DOWN:
                if (player.x < BOARD_SIZE * 2 + 1 - 2) player.x += 1;
                break;
            case KEY_LEFT:
                if (player.y > 0) player.y -= 1;
                break;
            case KEY_RIGHT:
                if (player.y < BOARD_SIZE * 4 + 1 - 4) player.y += 1;
                break;
            case ' ':
                player.axes = !player.axes;
                break;
            case '\n':
                // Restaurer l'état du tableau sauvegardé
                for (int i = 0; i < LINES; i++) {
                    for (int j = 0; j < COLS; j++) {
                        mvaddch(i, j, board_backup[i][j]);
                    }
                }

                refresh();
                draw_wall(player);
                return;
        }
        // Restaurer l'état du tableau sauvegardé
        for (int i = 0; i < LINES; i++) {
            for (int j = 0; j < COLS; j++) {
                mvaddch(i, j, board_backup[i][j]);
            }
        }

        refresh();
        timed_wall(player);
        printf("Wall created on: %d : %d\n", player.x, player.y);
    }
}