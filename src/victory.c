#include "quoridor.h"
void checkvictory(Game *game)
{
    /*
    Fonction: checkvictory
    Auteur: Evan , thomas
    Paramètres: Game game
    Traitement : Vérifie si un joueur a gagné
    Retour: void
    */
    int start_row = LINES / 2 - 3;
    int start_col = COLS / 2 - strlen("| |__) | | |         /  \\     \\ \\_/ /  | |__    | |__) |    \\ V /     \\ \\  /\\  / /    | |   |  \\| |\n") / 2;

    if (game->listOfPlayers[1]->y == victoryPlayer2)
    {
        clear();
        char *victory1 = "   _____    _                  __     __  ______   _____       ___     __          __  _____   _   _\n";
        char *victory2 = "  |  __ \\  | |          /\\     \\ \\   / / |  ____| |  __ \\     / _ \\    \\ \\        / / |_   _| | \\ | |\n";
        char *victory3 = "  | |__) | | |         /  \\     \\ \\_/ /  | |__    | |__) |   | | | |    \\ \\  /\\  / /    | |   |  \\| |\n";
        char *victory4 = "  |  ___/  | |        / /\\ \\     \\   /   |  __|   |  _  /    | | | |     \\ \\/  \\/ /     | |   | . ` |\n";
        char *victory5 = "  | |      | |____   / ____ \\     | |    | |____  | | \\ \\    | |_| |      \\  /\\  /     _| |_  | |\\  |\n";
        char *victory6 = "  |_|      |______| /_/    \\_\\    |_|    |______| |_|  \\_\\    \\___/        \\/  \\/     |_____| |_| \\_|\n";
        mvprintw(start_row, start_col, "%s", victory1);
        mvprintw(start_row + 1, start_col, "%s", victory2);
        mvprintw(start_row + 2, start_col, "%s", victory3);
        mvprintw(start_row + 3, start_col, "%s", victory4);
        mvprintw(start_row + 4, start_col, "%s", victory5);
        mvprintw(start_row + 5, start_col, "%s", victory6);
        refresh();
        char filename[100];
        sprintf(filename, "./saved_game/%s.txt", game->name);
        remove(filename);
        clear();
        sleep(5);
        int nb_files = 0;
        char **files = NULL;
        get_files(&files, &nb_files);
        chooseOptions(nb_files, files);
    }
    else if (game->listOfPlayers[0]->y == victoryPlayer1)
    {
        clear();
        char *victory1 = "  _____    _                  __     __  ______   _____     __   __   __          __  _____   _   _\n";
        char *victory2 = " |  __ \\  | |          /\\     \\ \\   / / |  ____| |  __ \\    \\ \\ / /   \\ \\        / / |_   _| | \\ | |\n";
        char *victory3 = " | |__) | | |         /  \\     \\ \\_/ /  | |__    | |__) |    \\ V /     \\ \\  /\\  / /    | |   |  \\| |  \n";
        char *victory4 = " |  ___/  | |        / /\\ \\     \\   /   |  __|   |  _  /      > <       \\ \\/  \\/ /     | |   | . ` |    \n";
        char *victory5 = " | |      | |____   / ____ \\     | |    | |____  | | \\ \\     / . \\       \\  /\\  /     _| |_  | |\\  |   \n";
        char *victory6 = " |_|      |______| /_/    \\_\\    |_|    |______| |_|  \\_\\   /_/ \\_\\       \\/  \\/     |_____| |_| \\_| \n";
        mvprintw(start_row, start_col, "%s", victory1);
        mvprintw(start_row + 1, start_col, "%s", victory2);
        mvprintw(start_row + 2, start_col, "%s", victory3);
        mvprintw(start_row + 3, start_col, "%s", victory4);
        mvprintw(start_row + 4, start_col, "%s", victory5);
        mvprintw(start_row + 5, start_col, "%s", victory6);
        refresh();
        char filename[100];
        sprintf(filename, "./saved_game/%s.txt", game->name);
        remove(filename);
        free(game->name);
        sleep(5);
        clear();
        int nb_files = 0;
        char **files = NULL;
        get_files(&files, &nb_files);
        chooseOptions(nb_files, files);
    }
}