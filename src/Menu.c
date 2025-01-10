#include "quoridor.h"

void showOptions(int option){
    /*
    Fonction: showOptions
    Auteur:Evan et Wylan
    Paramètres: void
    Traitement : Affiche les options du menu
    Retour: void
    */
    char* options[] = {
        "Mode 2 Joueurs",
        "Charger une partie",
        "Aide",
        "Quitter"
    };
    int x = LINES / 2 - (sizeof(options)/sizeof(char*)) / 2;
    int y = COLS / 2 - sizeof(options)/2;
    int title_cols = COLS / 2 - strlen(" .d88b.  db    db  .d88b.  d8888b. d8888b. d888888b d8888b.  .d88b.  d8888b. ") / 2;
    int title_row = x - 11;
    mvprintw(title_row++,title_cols," .d88b.  db    db  .d88b.  d8888b. d8888b. d888888b d8888b.  .d88b.  d8888b. ");
    mvprintw(title_row++,title_cols,".8P  Y8. 88    88 .8P  Y8. 88  `8D 88  `8D   `88'   88  `8D .8P  Y8. 88  `8D ");
    mvprintw(title_row++,title_cols,"88    88 88    88 88    88 88oobY' 88oobY'    88    88   88 88    88 88oobY' ");
    mvprintw(title_row++,title_cols,"88    88 88    88 88    88 88`8b   88`8b      88    88   88 88    88 88`8b   ");
    mvprintw(title_row++,title_cols,"`8P  d8' 88b  d88 `8b  d8' 88 `88. 88 `88.   .88.   88  .8D `8b  d8' 88 `88. ");
    mvprintw(title_row++,title_cols," `Y88'Y8 ~Y8888P'  `Y88P'  88   YD 88   YD Y888888P Y8888D'  `Y88P'  88   YD ");
    int n_choices = sizeof(options) / sizeof(char*);

    mvprintw(x - 3, y - 3, "###################################");
    mvprintw(x + (sizeof(options)/sizeof(char*)) + 3, y - 3, "###################################");
    for (int i = x - 3; i < x + (sizeof(options)/sizeof(char*)) + 3; i++)
    {
        mvprintw(i, y - 3, "#");
        mvprintw(i, y + 31, "#");
    }

    for (int i = 0; i < n_choices; i++) {
        if (i == option)
            attron(A_REVERSE);
        mvprintw(x++, y, options[i]);
        attroff(A_REVERSE);
    }
}

void chooseOptions(){
    /*
    Fonction: chooseOptions
    Auteur:Evan
    Paramètres: void
    Traitement : Permet de choisir une option
    Retour: void
    */
    clear();
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
                if (choix < 3)
                    choix++;
                showOptions(choix);
                break;
            case '\n':
                if (choix == 0) {
                    Game* game = createGame(2);
                    redraw(game);
                    select_player(game);
                } else if (choix == 1) {
                    menu_save();
                } else if (choix == 2) {
                    showButton(0);
                    chooseOptions();
                } else if (choix == 3) {
                    endwin();
                    exit(0);
                }
                break;
        }
    }
}

