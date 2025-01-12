#include "quoridor.h"

void showOptions(int option, int nb_files, char **files) {
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
    int title_cols = COLS / 2 - strlen(" .d88b.  db    db  .d88b.  d8888b. d888888b d8888b.  .d88b.  d8888b. ") / 2;
    int title_row = x - 11;
    mvprintw(title_row++,title_cols," .d88b.  db    db  .d88b.  d8888b. d888888b d8888b.  .d88b.  d8888b. ");
    mvprintw(title_row++,title_cols,".8P  Y8. 88    88 .8P  Y8. 88  `8D   `88'   88  `8D .8P  Y8. 88  `8D ");
    mvprintw(title_row++,title_cols,"88    88 88    88 88    88 88oobY'    88    88   88 88    88 88oobY' ");
    mvprintw(title_row++,title_cols,"88    88 88    88 88    88 88`8b      88    88   88 88    88 88`8b   ");
    mvprintw(title_row++,title_cols,"`8P  d8' 88b  d88 `8b  d8' 88 `88.   .88.   88  .8D `8b  d8' 88 `88. ");
    mvprintw(title_row++,title_cols," `Y88'Y8 ~Y8888P'  `Y88P'  88   YD Y888888P Y8888D'  `Y88P'  88   YD ");
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

void chooseOptions(int nb_files, char **files) {
    /*
    Fonction: chooseOptions
    Auteur:Evan
    Paramètres: void
    Traitement : Permet de choisir une option
    Retour: void
    */
    int choix;
    clear();
    error:
    choix = 0;
    showOptions(0, nb_files, files);
    int ch = 0;
    while (ch != '\n') {
        ch = getch();
        mvprintw(LINES / 2 + 6, COLS/2 - strlen("###################################") / 2, "                                   ");
        switch (ch) {
            case '8':
            case KEY_UP:
                if (choix > 0)
                    choix--;
                showOptions(choix, nb_files, files);
                break;
            case '2':
            case KEY_DOWN:
                if (choix < 3)
                    choix++;
                showOptions(choix, nb_files, files);
                break;
            case '\n':
                if (choix == 0) {
                    Game* game = createGame(2, NULL);
                    redraw(game);
                    select_player(game);
                } else if (choix == 1 ) {
                    if (nb_files > 0)
                        menu_save();
                    else
                    {
                        attron(A_BOLD);
                        attron(COLOR_PAIR(6));
                        mvprintw(LINES / 2 + 6, COLS/2 - strlen("No save found") / 2 - 1, "No save found");
                        attroff(A_BOLD);
                        attroff(COLOR_PAIR(6));
                        refresh();
                        goto error;
                    }
                } else if (choix == 2) {
                    showButton(0);
                    chooseOptions(nb_files, files);
                } else if (choix == 3) {
                    endwin();
                    exit(0);
                }
                break;
        }
    }
}

