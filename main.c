#include "header.h"

int main() {
    /*
    Fonction: main
    Auteur:
    Paramètres: 
    Traitement :
    Retour: 
    */
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    // Draw the board
    draw_board();

    int x = 0;
    int y = 0;
    int axes = 1;

    select_wall();

    // Clean up ncurses
    endwin();

    return 0;
}
