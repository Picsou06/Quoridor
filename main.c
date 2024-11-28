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
    Game* game = createGame(2);
    draw_board();
    create_wall(game, 5, 5, 1, game->listOfPlayers[0]);
    create_wall(game, 1, 1, 0, game->listOfPlayers[1]);
    create_wall(game, 2, 4, 0, game->listOfPlayers[0]);
    draw_all_wall(game);
    refresh();

    int ch = 0;

    while (ch != '\n') 
    {
        ch = getch();
    }

    endwin();

    return 0;
}
