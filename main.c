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

    draw_wall(Player1x, Player1y, 1, Player1axes);
    refresh();

    select_wall(1);
    refresh();
    select_wall();

    // Clean up ncurses
    endwin();

    return 0;
}
