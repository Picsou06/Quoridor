#include "quoridor.h"
int main() {
    /*
    Fonction: main
    Auteur:Evan
    Paramètres: void
    Traitement : Permet de lancer le jeu
    Retour: int
    */
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);

    if (COLS < BOARD_SIZE * MY_CELL_WIDTH || LINES < BOARD_SIZE * 3) {
        endwin();
        printf("The terminal is too small to display the game.\n");
        return 1;
    }

    chooseOptions();

    endwin();

    return 0;
}
