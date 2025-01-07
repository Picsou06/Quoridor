#include "quoridor.h"

void draw_board() {
    /*
    Fonction: draw_board
    Auteur:Evan
    Paramètres: void
    Traitement : Dessine le tableau de format 9*9 dans la Console
    Retour: void
    */
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                mvprintw(start_row + i * 2, start_col + j * MY_CELL_WIDTH, "+---");
                mvprintw(start_row + i * 2 + 1, start_col + j * MY_CELL_WIDTH, "|   ");
            }
            mvprintw(start_row + i * 2, start_col + BOARD_SIZE * MY_CELL_WIDTH, "+\n");
            mvprintw(start_row + i * 2 + 1, start_col + BOARD_SIZE * MY_CELL_WIDTH, "|\n");
        }

        for (int j = 0; j < BOARD_SIZE; j++) {
            mvprintw(start_row + BOARD_SIZE * 2, start_col + j * MY_CELL_WIDTH, "+---");
        }
        mvprintw(start_row + BOARD_SIZE * 2, start_col + BOARD_SIZE * MY_CELL_WIDTH, "+\n");
}