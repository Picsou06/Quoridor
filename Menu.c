#include "quoridor.h"
//attron(COLOR_PAIR(color)); 
//attroff(COLOR_PAIR(color));
// 1, COLOR_BLUE
// 2, COLOR_GREEN
// 3, COLOR_YELLOW
// 4, COLOR_MAGENTA
void Nouvelle_Partie();
void Chargez();
void Options();

void afficheMenu(){
    attron(COLOR_PAIR(1));
    mvprintw(0, 0, "=== Menu de Quoridor===\n"); //ici on change les option plus tard et on va mettre jouer ,charger un partie sauvegarde et quitter
    mvprintw(1, 0, "1. Nouvelle partie\n");
    mvprintw(2, 0, "2. Chargez une sauvegarde 1\n");
    mvprintw(3, 0, "3. Option \n");
    mvprintw(4, 0, "3. Quittez le jeux 1\n");
    mvprintw(5, 0, "Choisissez une option: ");
}    
void Nouvelle_Partie() {
    Game* game = createGame(2);
    if (game == NULL) {
        mvprintw(6, 0, "Erreur lors de la création du jeu.\n");
        return;
    }
}

void Chargez() {
    mvprintw(6, 0, "Vous avez choisi de charger une sauvegarde.\n");
    
}

void Options() {
    mvprintw(6, 0,  "Vous avez choisi les options.\n");

}
