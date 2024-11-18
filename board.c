#include "quoridor.h"


void save_board(Game game)
{
    for (int i = 0; i < LINES; i++) {
        for (int j = 0; j < COLS; j++) {
            game.board.board[i][j] = mvinch(i, j) & A_CHARTEXT;
            game.board.color[i][j] = mvinch(i, j) & A_COLOR;
        }
    }
}

void draw_board(Game game) {
    /*
    Fonction: draw_board
    Auteur:Evan et Wylan
    Paramètres: void
    Traitement : Dessine le tableau de format 9*9 dans la Console
    Retour: void
    */
   // Calculate the starting position to center the board
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;

    // Draw the board
    for (int i = 0; i < BOARD_SIZE * 3; i++) {
        for (int j = 0; j < BOARD_SIZE * 5; j++) {
            int row = start_row + i;
            int col = start_col + j;
            attron(COLOR_PAIR(game.board.color[i][j]));
            mvprintw(row, col, "%c", game.board.board[i][j]);
            attroff(COLOR_PAIR(game.board.color[i][j]));
        }
    }
    refresh();
}