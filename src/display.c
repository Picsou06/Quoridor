#include "quoridor.h"

void redraw(Game* game) {
    /*
    Fonction: redraw
    Auteur:Wylan
    Paramètres: void
    Traitement : Permet de rafraichir l'écran
    Retour: void
    */
    clear();
    draw_board();
    draw_all_wall(game);
    displayAllPlayer(game);
    displayNbWall(game);
    refresh();
    if (COLS > BOARD_SIZE * 4 + 30)
        displaykey(0);
}

void displaykey(int diagonal) {
    int x = (COLS / 2 - 19) / 2 - 25 / 2;
    int y = LINES / 2 - 18 / 2;
    mvprintw(y, x,"#####");
    mvprintw(y+1, x,"# 7 #");
    mvprintw(y+2, x,"#####");
    attron(COLOR_PAIR(5));
    mvprintw(y+3, x," UP L");
    attroff(COLOR_PAIR(5));

    mvprintw(y+0, x+14,"#####");
    mvprintw(y+1, x+14,"# 9 #");
    mvprintw(y+2, x+14,"#####");
    attron(COLOR_PAIR(5));
    mvprintw(y+3, x+14," UP R");
    attroff(COLOR_PAIR(5));

    mvprintw(y, x+7,"#####");
    mvprintw(y+1, x+7,"# 8 #");
    mvprintw(y+2, x+7,"#####");
    attron(COLOR_PAIR(5));
    mvprintw(y+3, x+7,"  UP ");
    attroff(COLOR_PAIR(5));

    y = y + 4;
    mvprintw(y, x,"#####");
    mvprintw(y+1, x,"# 4 #");
    mvprintw(y+2, x,"#####");
    attron(COLOR_PAIR(5));
    mvprintw(y+3, x," LEFT");
    attroff(COLOR_PAIR(5));

    mvprintw(y, x+7,"#####");
    mvprintw(y+1, x+7,"# 5 #");
    mvprintw(y+2, x+7,"#####");
    attron(COLOR_PAIR(5));
    mvprintw(y+3, x+7," swap");
    attroff(COLOR_PAIR(5));

    mvprintw(y, x+14,"#####");
    mvprintw(y+1, x+14,"# 6 #");
    mvprintw(y+2, x+14,"#####");
    attron(COLOR_PAIR(5));
    mvprintw(y+3, x+14,"RIGHT");
    attroff(COLOR_PAIR(5));

    y = y + 4;
    mvprintw(y, x,"#####");
    mvprintw(y+1, x,"# 1 #");
    mvprintw(y+2, x,"#####");
    attron(COLOR_PAIR(5));
    mvprintw(y+3, x,"DownL");
    attroff(COLOR_PAIR(5));

    mvprintw(y, x+14,"#####");
    mvprintw(y+1, x+14,"# 3 #");
    mvprintw(y+2, x+14,"#####");
    attron(COLOR_PAIR(5));
    mvprintw(y+3, x+14,"DownR");
    attroff(COLOR_PAIR(5));

    mvprintw(y, x+7,"#####");
    mvprintw(y+1, x+7,"# 2 #");
    mvprintw(y+2, x+7,"#####");
    attron(COLOR_PAIR(5));
    mvprintw(y+3, x+7," DOWN");
    attroff(COLOR_PAIR(5));

    y = y + 4;
    mvprintw(y, x, "############");
    mvprintw(y+1, x,"#     0    #");
    mvprintw(y+2, x,"############");
    attron(COLOR_PAIR(5));
    mvprintw(y+3, x,"   ROTATE   ");
    attroff(COLOR_PAIR(5));

    y = y - 4;
    mvprintw(y++, x+21,"#####");
    mvprintw(y++, x+21,"# E #");
    mvprintw(y++, x+21,"# N #");
    mvprintw(y++, x+21,"# T #");
    mvprintw(y++, x+21,"# E #");
    mvprintw(y++, x+21,"# R #");
    mvprintw(y++, x+21,"#####");
    attron(COLOR_PAIR(5));
    mvprintw(y++, x+21,"VALID");
    attroff(COLOR_PAIR(5));
}