#include "quoridor.h"

void showOptions(int option){
    int x = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int y = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;
    char* options[] = {
        "Mode 2 Joueurs",
        "Charger une partie",
        "Quitter"
    };
    int n_choices = sizeof(options) / sizeof(char*);

    for (int i = 0; i < n_choices; i++) {
        if (i == option)
            attron(A_REVERSE);
        mvprintw(x++, y, options[i]);
        attroff(A_REVERSE);
    }
}

void chooseOptions(){
    int choix = 0;
    showOptions(0);
    int ch = 0;
    while (ch != '\n') {
        ch = getch();
        switch (ch) {
            case KEY_UP:
                if (choix > 0)
                    choix--;
                showOptions(choix);
                break;
            case KEY_DOWN:
                if (choix < 2)
                    choix++;
                showOptions(choix);
                break;
            case '\n':
                if (choix == 0) {
                    Game* game = createGame(2);
                    redraw(game);
                    select_player(game);
                } else if (choix == 1) {
                    // do something
                } else if (choix == 2) {
                    endwin();
                    exit(0);
                }
                break;
        }
    }
}
