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
    Player Player1 = createPlayer('X', 1);
    Player Player2 = createPlayer('O', 2);

    // Draw the board
    draw_board();

    while (true)
    {
        select_wall(Player1);
    }

    // Clean up ncurses
    endwin();

    return 0;
}
