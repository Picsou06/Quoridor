#include "quoridor.h"

void checkvictory(Game *game)
{
    /*
    Fonction: checkvictory
    Auteur: Evan
    Paramètres: Game game
    Traitement : Vérifie si un joueur a gagné
    Retour: void
    */
    int start_row = LINES / 2;
    int start_col = COLS / 2;
    if (game->listOfPlayers[0]->y == victoryPlayer1)
    {
        mvprintw(start_row, start_col, " ____  _     ____ ___  _ _____ ____   ___  _   _      _  _     ");
        mvprintw(start_row + 1, start_col, "/  __\\/ \\   /  _ \\\\  \\\\\\///  __//  __\\  \\  \\//  / \\  /|/ \\/ \\  /|");
        mvprintw(start_row + 2, start_col, "|  \\/|| |   | / \\| \\  / |  \\  |  \\/|   \\  /   | |  ||| || |\\ ||");
        mvprintw(start_row + 3, start_col, "|  __/| |_/\\| |-|| / /  |  /_ |    /   /  \\   | |\\||| || | \\||");
        mvprintw(start_row + 4, start_col, "\\_/   \\____/\\_/ \\|/_/   \\____\\\\_/\\_\\  /__/\\\\  \\_/  \\|\\_/\\_/ \\|");
        sleep(5);
        remove("saved_game.txt");
        chooseOptions();
    }
    else if (game->listOfPlayers[1]->y == victoryPlayer2)
    {
        mvprintw(start_row, start_col, " ____  _     ____ ___  _ _____ ____    ____    _      _  _     ");
        mvprintw(start_row + 1, start_col, "/  __\\/ \\   /  _ \\\\  \\\\\\\\///  __//  __\\  /  _ \\  / \\  /|/ \\/ \\  /|");
        mvprintw(start_row + 2, start_col, "|  \\/|| |   | / \\| \\  / |  \\  |  \\/|  | / \\|  | |  ||| || |\\ ||");
        mvprintw(start_row + 3, start_col, "|  __/| |_/\\| |-|| / /  |  /_ |    /  | \\_/|  | |/\\||| || | \\||");
        mvprintw(start_row + 4, start_col, "\\_/   \\____/\\_/ \\|/_/   \\____\\_/\\_\\  \\____/  \\_/  \\|\\_/\\_/  \\|");
        // sleep(5);
        remove("saved_game.txt");
        chooseOptions();
    }
}