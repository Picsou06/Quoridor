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

void draw_wall(Player player) {
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

    int row = start_row + player.x * 2;
    int col = start_col + player.y * MY_CELL_WIDTH;

    if (player.axes == 0) {
        attron(COLOR_PAIR(player.color));

        
        if (player.y>0)
            mvprintw(row, col - 4, "####");
        if (player.y<BOARD_SIZE)
            mvprintw(row, col + 1, "####");
        mvprintw(row, col, "#");

        attroff(COLOR_PAIR(player.color));
    } else {
        attron(COLOR_PAIR(player.color));
        if (player.x>0)
        {
            {
                mvprintw(row - 2, col, "#");
                mvprintw(row - 1, col, "#");
            }
            if (player.x<BOARD_SIZE)
            {
                mvprintw(row + 1, col, "#");
                mvprintw(row + 2, col, "#");
            }
            mvprintw(row, col, "#");

            attroff(COLOR_PAIR(player.color));
        }
    }

    refresh();
}

void timed_wall(Player player) {
    /*
    Fonction: timed_wall
    Auteur: Evan
    Paramètres: void
    Traitement : affiche le mur pendant une secondes avant de re afficher le tableau
    Retour: void
    */

    // Calculate the starting position to center the board
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;

    int row = start_row + player.x * 2;
    int col = start_col + player.y * MY_CELL_WIDTH;

    if (player.axes == 0) {
        attron(COLOR_PAIR(COLOR_YELLOW));

        if (player.y > 0)
            mvprintw(row, col - 4, "####");
        if (player.y < BOARD_SIZE)
            mvprintw(row, col + 1, "####");
        mvprintw(row, col, "#");

        attroff(COLOR_PAIR(COLOR_YELLOW));
    } else {
        attron(COLOR_PAIR(COLOR_YELLOW));

        if (player.x > 0) {
            mvprintw(row - 2, col, "#");
            mvprintw(row - 1, col, "#");
        }
        if (player.x < BOARD_SIZE) {
            mvprintw(row + 1, col, "#");
            mvprintw(row + 2, col, "#");
        }
        mvprintw(row, col, "#");

        attroff(COLOR_PAIR(COLOR_YELLOW));
    }
    refresh();
}
