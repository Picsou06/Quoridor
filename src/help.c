#include "quoridor.h"

void showPageOne(int part) {
    /*
    Fonction: showPageOne
    Auteur: Evan et Thomas
    Paramètres: void
    Traitement : Permet d'afficher les règles du jeu 
    Retour: void
    */
    clear();
    int x = 5;
    int y = 2;
    mvprintw(y, x, "Guide Quoridor");
    mvprintw(y+3, x, "MATERIEL");
    mvprintw(y+4, x, "Un plateau de 9x9 cases.");
    mvprintw(y+6, x, "Chaque joueur dispose :");
    mvprintw(y+7, x, "1 pion.");
    mvprintw(y+8, x, "%d murs.", MAXWALL);
    mvprintw(y+10, x, "OBJECTIF");
    mvprintw(y+11, x, "Etre le premier joueur a atteindre la rangee opposee du plateau avec son pion.");
    mvprintw(y+13, x, "PREPARATION");
    mvprintw(y+14, x, "Chaque joueur recoit 10 murs.");
    mvprintw(y+16, x, "DEROULEMENT DU JEU");
    mvprintw(y+17, x, "Le jeu se deroule a tour de role. A chaque tour, un joueur a deux choix :");
    mvprintw(y+19, x, "Deplacer son pion.");
    mvprintw(y+20, x, "Placer un mur.");
    if (LINES > BOARD_SIZE * 3+10 || part == 1)
    {
        if (part == 1)
        {
            y = -20;
            clear();
            mvprintw(LINES - 4, COLS - 16,"######");
            mvprintw(LINES - 3, COLS - 16,"# /\\ #");
            mvprintw(LINES - 2, COLS - 16,"######");
        }
        mvprintw(y+22, x, "1. Deplacement du pion");
        mvprintw(y+23, x, "Un pion peut se deplacer d'une case a la fois dans une des quatre directions :");
        mvprintw(y+24, x, "haut, bas, gauche ou droite.");
        mvprintw(y+25, x, "Un pion ne peut pas traverser un mur.");
        mvprintw(y+26, x, "Si les deux pions sont face a face sur des cases adjacentes et qu'il n'y a pas de mur derriere,");
        mvprintw(y+27, x, "un joueur peut sauter par-dessus l'autre pion.");
        mvprintw(y+28, x, "Si un mur bloque le saut direct, le joueur peut contourner l'autre pion en se deplacant sur une case diagonale.");
        mvprintw(y+30, x, "2. Placement du mur");
        mvprintw(y+31, x, "Un joueur peut placer un mur pour gener la traverser de l'adversaire.");
        mvprintw(y+32, x, "Les murs doivent etre poses entre deux cases, horizontalement ou verticalement.");
        mvprintw(y+33, x, "Il est interdit de poser un mur qui rend le chemin de l'adversaire totalement bloque.");
        mvprintw(y+34, x, "Chaque joueur doit toujours avoir un chemin possible vers la rangee opposee (meme s'il est plus long ou complexe).");
        mvprintw(y+36, x, "FIN DE LA PARTIE");
        mvprintw(y+37, x, "Le premier joueur a atteindre n'importe quelle case de la derniere rangee opposee gagne la partie.");
        mvprintw(y+39, x, "ASTUCES ET STRATEGIE");
        mvprintw(y+40, x, "Utilisez vos murs pour ralentir votre adversaire, mais gardez-en pour proteger votre propre chemin.");
        mvprintw(y+41, x, "Soyez attentif aux possibilites de saut pour avancer plus vite.");
        mvprintw(y+42, x, "Ne gaspillez pas vos murs : leur nombre est limite !");
    }
    else {
        mvprintw(LINES - 4, COLS - 16,"######");
        mvprintw(LINES - 3, COLS - 16,"# \\/ #");
        mvprintw(LINES - 2, COLS - 16,"######");
    }
    attron(A_REVERSE);
        mvprintw(LINES - 1, x, "Pour revenir au menu principal press Escape");
    attroff(A_REVERSE);
    mvprintw(LINES - 4, COLS - 8,"######");
    mvprintw(LINES - 3, COLS - 8,"# -> #");
    mvprintw(LINES - 2, COLS - 8,"######");
    mvprintw(LINES - 1, COLS - 8," 1/2 ");
    refresh();
}

void shadowLetter(int x, int y, char letter, char *explanation){
    /*
    Fonction: shadowLetter
    Auteur:Evan
    Paramètres: int x, int y, char letter, char *explanation
    Traitement : Permet d'afficher une lettre en surbrillance
    Retour: void
    */
    attron(A_REVERSE);
    mvprintw(y, x,"#####");
    mvprintw(y+1, x,"# %c #", letter);
    mvprintw(y+2, x,"#####");
    attroff(A_REVERSE);
    mvprintw(y+3, x, explanation);
    refresh();
}

void showPageTwo()
{
    /*
    Fonction: showPageTwo
    Auteur: Evan et Thomas
    Paramètres: void
    Traitement : Permet d'afficher les commandes du jeu
    Retour: void
    */
    clear();
    int x = COLS / 2 - 11;
    int y = LINES / 2 - 11;
    attron(A_BOLD);
    attron(COLOR_PAIR(5));
    mvprintw(y - 2, x + 9 - (strlen("Appuyez sur une touches pour connaitre sa fonction")/2), "Appuyez sur une touches pour connaitre sa fonction");
    attroff(A_BOLD);
    attroff(COLOR_PAIR(5));
    mvprintw(y, x,"#####");
    mvprintw(y+1, x,"# 7 #");
    mvprintw(y+2, x,"#####");

    mvprintw(y, x+7,"#####");
    mvprintw(y+1, x+7,"# 8 #");
    mvprintw(y+2, x+7,"#####");

    mvprintw(y+0, x+14,"#####");
    mvprintw(y+1, x+14,"# 9 #");
    mvprintw(y+2, x+14,"#####");

    y = y + 4;
    mvprintw(y, x,"#####");
    mvprintw(y+1, x,"# 4 #");
    mvprintw(y+2, x,"#####");

    mvprintw(y, x+7,"#####");
    mvprintw(y+1, x+7,"# 5 #");
    mvprintw(y+2, x+7,"#####");

    mvprintw(y, x+14,"#####");
    mvprintw(y+1, x+14,"# 6 #");
    mvprintw(y+2, x+14,"#####");
    
    y = y + 4;
    mvprintw(y, x,"#####");
    mvprintw(y+1, x,"# 1 #");
    mvprintw(y+2, x,"#####");

    mvprintw(y, x+7,"#####");
    mvprintw(y+1, x+7,"# 2 #");
    mvprintw(y+2, x+7,"#####");

    mvprintw(y, x+14,"#####");
    mvprintw(y+1, x+14,"# 3 #");
    mvprintw(y+2, x+14,"#####");

    y = y + 4;
    mvprintw(y, x, "############");
    mvprintw(y+1, x,"#     0    #");
    mvprintw(y+2, x,"############");

    y = y - 4;
    mvprintw(y++, x+21,"#####");
    mvprintw(y++, x+21,"# E #");
    mvprintw(y++, x+21,"# N #");
    mvprintw(y++, x+21,"# T #");
    mvprintw(y++, x+21,"# E #");
    mvprintw(y++, x+21,"# R #");
    mvprintw(y++, x+21,"#####");

    attron(A_REVERSE);
        mvprintw(LINES - 1, 5, "Pour revenir au menu principal press Escape");
    attroff(A_REVERSE);
    mvprintw(LINES - 4, COLS - 8,"######");
    mvprintw(LINES - 3, COLS - 8,"# <- #");
    mvprintw(LINES - 2, COLS - 8,"######");
    mvprintw(LINES - 1, COLS - 8," 2/2 ");
    refresh();
}

static void handleKeyPress(int ch, int *pages) {
    switch (ch) {
        case KEY_RIGHT:
            if (*pages < 1)
                (*pages)++;
            selectPage(*pages);
            break;
        case KEY_LEFT:
            if (*pages > 0)
                (*pages)--;
            selectPage(*pages);
            break;
        case KEY_UP:
            if (*pages == 0 && !(LINES > BOARD_SIZE * 3 + 10))
                showPageOne(0);
            break;
        case KEY_DOWN:
            if (*pages == 0 && !(LINES > BOARD_SIZE * 3 + 10))
                showPageOne(1);
            break;
        case '1':
            selectPage(*pages);
            if (*pages == 1)
                shadowLetter(COLS / 2 - 11, LINES / 2 - 3, '1', "Deplacer le pion en diagonale bas gauche");
            break;
        case '2':
            selectPage(*pages);
            if (*pages == 1)
                shadowLetter(COLS / 2 - 4, LINES / 2 - 3, '2', "Deplacer le pion vers le bas");
            break;
        case '3':
            selectPage(*pages);
            if (*pages == 1)
                shadowLetter(COLS / 2 + 3, LINES / 2 - 3, '3', "Deplacer le pion en diagonale bas droite");
            break;
        case '4':
            selectPage(*pages);
            if (*pages == 1)
                shadowLetter(COLS / 2 - 11, LINES / 2 - 7, '4', "Deplacer le pion vers la gauche");
            break;
        case '5':
            selectPage(*pages);
            if (*pages == 1)
                shadowLetter(COLS / 2 - 4, LINES / 2 - 7, '5', "Changer le type d'action");
            break;
        case '6':
            selectPage(*pages);
            if (*pages == 1)
                shadowLetter(COLS / 2 + 3, LINES / 2 - 7, '6', "Deplacer le pion vers la droite");
            break;
        case '7':
            selectPage(*pages);
            if (*pages == 1)
                shadowLetter(COLS / 2 - 11, LINES / 2 - 11, '7', "Deplacer le pion en diagonale haut gauche");
            break;
        case '8':
            selectPage(*pages);
            if (*pages == 1)
                shadowLetter(COLS / 2 - 4, LINES / 2 - 11, '8', "Deplacer le pion vers le haut");
            break;
        case '9':
            selectPage(*pages);
            if (*pages == 1)
                shadowLetter(COLS / 2 + 3, LINES / 2 - 11, '9', "Deplacer le pion en diagonale haut droite");
            break;
        case '0':
            selectPage(*pages);
            if (*pages == 1) {
                attron(A_REVERSE);
                mvprintw(LINES / 2 + 1, COLS / 2 - 11, "############");
                mvprintw(LINES / 2 + 2, COLS / 2 - 11, "#     0    #");
                mvprintw(LINES / 2 + 3, COLS / 2 - 11, "############");
                attroff(A_REVERSE);
                mvprintw(LINES / 2 + 4, COLS / 2 - 11, "Changer la rotation du mur");
                refresh();
            }
            break;
        case '\n':
            selectPage(*pages);
            if (*pages == 1) {
                attron(A_REVERSE);
                mvprintw(LINES / 2 - 3, COLS / 2 + 10, "#####");
                mvprintw(LINES / 2 - 2, COLS / 2 + 10, "# E #");
                mvprintw(LINES / 2 - 1, COLS / 2 + 10, "# N #");
                mvprintw(LINES / 2 + 0, COLS / 2 + 10, "# T #");
                mvprintw(LINES / 2 + 1, COLS / 2 + 10, "# E #");
                mvprintw(LINES / 2 + 2, COLS / 2 + 10, "# R #");
                mvprintw(LINES / 2 + 3, COLS / 2 + 10, "#####");
                attroff(A_REVERSE);
                mvprintw(LINES / 2 + 4, COLS / 2 + 10, "Valider l'action");
                refresh();
            }
            break;
        case 27:
            return;
    }
}

void showButton(int pages) {
    /*
    Fonction: showButton
    Auteur:Evan et THomas
    Paramètres: int pages
    Traitement : 
    Retour: void
    */
    selectPage(pages);
    int ch = 0;
    while (ch != KEY_BACKSPACE) {
        ch = getch();
        handleKeyPress(ch, &pages);
    }
}

void selectPage(int pages) {
    /*
    Fonction: selectPage
    Auteur:Evan
    Paramètres: int pages
    Traitement : Permet de changer de page
    Retour: void
    */
    clear();
    if (pages == 0) {
            showPageOne(0);
    } else {
        showPageTwo();
    }
    refresh();
}
