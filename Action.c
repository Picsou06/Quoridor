#include "header.h"

void select_wall()
{
    /*
    Fonction: select_wall
    Auteur: Evan
    Paramètres: void
    Traitement : Permet de selectionner un mur et de le déplacer
    Retour: void
    */
    int x = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int y = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;
    int axes = 1;
    int ch = 0;


    while (ch != KEY_ENTER) {
        ch = getch(); // Lire l'entrée utilisateur
        switch (ch) {
            case 'c':
                // Clear the screen
                clear();
                draw_board();
                break;
            case KEY_UP:
                // Move the wall up
                if (x > 0) {
                    x = x - 2;
                    draw_wall(x, y, 1, axes);
                }
                break;
            case KEY_DOWN:
                // Move the wall down
                if (x < BOARD_SIZE * 2 + 1 - 2) {
                    x = x + 2;
                    draw_wall(x, y, 1, axes);
                }
                break;
            case KEY_LEFT:
                // Move the wall left
                if (y > 0) {
                    y = y - 4;
                    draw_wall(x, y, 1, axes);
                }
                break;
            case KEY_RIGHT:
                // Move the wall right
                if (y < BOARD_SIZE * 4 + 1 - 4) {
                    y = y + 4;
                    draw_wall(x, y, 1, axes);
                }
                break;
            case ' ': // Touche espace
                // Change the axes
                if (axes == 0) {
                    axes = 1;
                } else {
                    axes = 0;
                }
                break;
        }
    }
}