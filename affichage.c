#include "header.h"

void draw_board() {
    /*
    Fonction: draw_board
    Auteur:Evan
    Paramètres: void
    Traitement : Dessine le tableau de format 9*9 dans la Console
    Retour: void
    */
    int i, j;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Calculer la position de départ pour centrer la grille
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;

    // dessin du tableau
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            // dessin des lignes horizontales
            mvprintw(start_row + i * 2, start_col + j * MY_CELL_WIDTH, "+---");
            // Draw vertical lines
            mvprintw(start_row + i * 2 + 1, start_col + j * MY_CELL_WIDTH, "|   ");
        }
        // Draw the rightmost vertical line
        mvprintw(start_row + i * 2, start_col + BOARD_SIZE * MY_CELL_WIDTH, "+\n");
        mvprintw(start_row + i * 2 + 1, start_col + BOARD_SIZE * MY_CELL_WIDTH, "|\n");
    }

    // Draw the bottom horizontal line
    for (j = 0; j < BOARD_SIZE; j++) {
        mvprintw(start_row + BOARD_SIZE * 2, start_col + j * MY_CELL_WIDTH, "+---");
    }
    mvprintw(start_row + BOARD_SIZE * 2, start_col + BOARD_SIZE * MY_CELL_WIDTH, "+\n");

    refresh();
}

void draw_wall(int grid_row, int grid_col, int color, int angle) {
    /*
    Fonction: draw_wall
    Auteur: Evan
    Paramètres: void
    Traitement : Dessine les murs dans la Console
    Retour: void
    */

    // Calculate the starting position to center the board
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;

    // Calculate the screen coordinates for the top-left corner of the cell
    int row = start_row + grid_row * 2;
    int col = start_col + grid_col * MY_CELL_WIDTH;

    if (angle == 0) {
        attron(COLOR_PAIR(color));

        // Draw the horizontal wall
        mvprintw(row, col + 2, "####");
        mvprintw(row, col - 2, "#####");

        attroff(COLOR_PAIR(color));
    } else {
        // Set the color
        attron(COLOR_PAIR(color));

        // Draw the vertical wall
        mvprintw(row + 2, col, "#");
        mvprintw(row + 1, col, "#");
        mvprintw(row, col, "#");
        mvprintw(row - 1, col, "#");
        mvprintw(row - 2, col, "#");

        // Reset the color
        attroff(COLOR_PAIR(color));
    }

    // Refresh the screen
    refresh();
}
