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
    init_pair(0, COLOR_RED, COLOR_BLACK);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    Player Player1 = createPlayer('X', 0, 4, 0, 1);
    Player Player2 = createPlayer('O', 1, 4, 9, -1);

    // Draw the board
    redraw(Player1, Player2);
    draw_wall(Player2);
    draw_wall(Player1);
    while (true)
    {
        select_wall(Player1, Player2);
    }

    // Clean up ncurses
    endwin();

    return 0;
}
