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
    printmv("=== Menu ===\n");//ici on change les option plus tard et on va mettre jouer ,charger un partie sauvegarde et quitter//
    printmv("1. Nouvelle partie 1\n");
    printmv("2. Chargez une sauvegarde 1\n");
    printmv("3. Option \n");
    printmv("3. Quittez le jeux 1\n");
    printmv("Choisissez une option: ");
}    
void Nouvelle_Partie() {
    Game* game = createGame(2);
    if (game == NULL) {
        printmv(6, 0, "Erreur lors de la création du jeu.\n");
        return;
    }
}

void Chargez() {
    printmv(6, 0, "Vous avez choisi de charger une sauvegarde.\n");
    
}

void Options() {
    printmv(6, 0,,  "Vous avez choisi les options.\n");

}
