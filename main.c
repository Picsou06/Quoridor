#include "quoridor.h"
int main() {
    /*
    Fonction: main
    Auteur: Evan
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
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);

    // Game* game = createGame(2);
    // redraw(game);
    // select_player(game);
    

    endwin();

    return 0;
}
