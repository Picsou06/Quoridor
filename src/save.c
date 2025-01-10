#include "quoridor.h"
#include <stdio.h>

int get_player_index(Game* game, char icon) {
    /*
    Fonction: get_player_index
    Auteur:Evan
    Paramètres: Game* game, char icon
    Traitement : Retourne l'index du joueur
    Retour: int
    */
    for (int i = 0; i < game->nbPlayers; i++) {
        if (game->listOfPlayers[i]->icon == icon) {
            return i;
        }
    }
    return -1;
}

void save_game(Game game) {
    /*
    Fonction: save_game
    Auteur:Evan
    Paramètres: Game game
    Traitement : Sauvegarde la partie
    Retour: void
    */
    char filepath[100];
    strcpy(filepath, "./saved_game/");
    strcat(filepath, game.name);
    strcat(filepath, ".txt");
    FILE *file = fopen(filepath, "w");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }
    fprintf(file, "%d\n", game.nbPlayers);
    for (int i = 0; i < game.nbPlayers; i++) {
        fprintf(file, "%c %d %d %d\n", game.listOfPlayers[i]->icon, game.listOfPlayers[i]->color, game.listOfPlayers[i]->x, game.listOfPlayers[i]->y);
    }
    
    fprintf(file, "%d\n", game.nbWalls);
    for (int i = 0; i < game.nbWalls; i++) {
        fprintf(file, "%d %d %d %c\n", game.listOfWalls[i].x, game.listOfWalls[i].y, game.listOfWalls[i].axes, game.listOfWalls[i].player.icon);
    }

    fprintf(file, "%c\n", game.playerPlaying->icon);

    fclose(file);
}

void load_game(char *filename) {
    /*
    Fonction: load_game
    Auteur:Evan
    Paramètres: void
    Traitement : Charge la partie
    Retour: void
    */
    char filepath[100];
    strcpy(filepath, "./saved_game/");
    strcat(filepath, filename);
    strcat(filepath, ".txt");
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Failed to open the file for reading.\n");
        return;
    }
    int nbPlayers;
    fscanf(file, "%d", &nbPlayers);

    Game* game = createGame(nbPlayers, filename);
    char icon; // Declare icon here
    for (int i = 0; i < nbPlayers; i++) {
        int color, x, y;
        fscanf(file, " %c %d %d %d", &icon, &color, &x, &y);
        game->listOfPlayers[i] = createPlayer(icon, color, x, y);
    }
    game->nbPlayers = nbPlayers;
    game->playerPlaying = game->listOfPlayers[get_player_index(game, icon)];

    int nbWalls;
    fscanf(file, "%d", &nbWalls);

    for (int i = 0; i < nbWalls; i++) {
        int x, y, axes;
        fscanf(file, "%d %d %d %c", &x, &y, &axes, &icon);
        game->listOfWalls[i] = create_wall(x, y, axes, *game->listOfPlayers[get_player_index(game, icon)]);
    }

    game->nbWalls = nbWalls;
    fclose(file);

    redraw(game);
    select_player(game);
}

void get_files(char ***files, int *count) {
    DIR *dir;
    *count = 0;
    struct dirent *ent;

    dir = opendir("./saved_game");
    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strstr(ent->d_name, ".txt") != NULL) {
                *files = realloc(*files, (*count + 1) * sizeof(char*));
                (*files)[*count] = malloc(strlen(ent->d_name) + 1);
                strcpy((char *)(*files)[*count], ent->d_name);
                char *dot = strrchr((char *)(*files)[*count], '.');
                if (dot) {
                    *dot = '\0';
                }
                (*count)++;
            }
        }
        closedir(dir);
        return;
    }
    *files = NULL;
}

void show_options(int pages, int selected, int numFiles) {
    clear();
    char** files = NULL;
    get_files(&files, &numFiles);

    int x = COLS / 2 - (strlen("##############################") / 2);
    int y = LINES / 2 - 5;

    mvprintw(y++, x, "##############################");
    mvprintw(y++, x, "#                            #");
    mvprintw(y++, x, "#       Choose a save!       #");
    mvprintw(y++, x, "#                            #");
    mvprintw(y++, x, "##############################");
    if (pages != 0) {
        mvprintw(y++, x, "#             ^              #");
    }
    else
        mvprintw(y++, x, "#                            #");
    for (int i = pages * 10; i <= pages * 10 + 9 && i < numFiles; i++) {
        if (i == selected)
            attron(A_REVERSE);
        char filename[31];
        if (strlen(files[i]) % 2 == 0)
            sprintf(filename, "# %*s%s%*s #", (27 - strlen(files[i])) / 2, "", files[i], (27 - strlen(files[i])) / 2, "");
        else
            sprintf(filename, "# %*s%s%*s #", (26 - strlen(files[i])) / 2, "", files[i], (27 - strlen(files[i])) / 2, "");
        mvprintw(y++, x, filename);
        if (i == selected)
            attroff(A_REVERSE);
    }
    if (numFiles > pages * 10 + 9)
        mvprintw(y++, x, "#             v              #");
    else
        mvprintw(y++, x, "#                            #");
    mvprintw(y++, x, "##############################");
    attron(A_REVERSE);
        mvprintw(LINES - 1, COLS / 3, "Pour revenir au menu principal press Escape");
    attroff(A_REVERSE);
    refresh();
}

void menu_save() {
    int selected = 0;
    int pages = 0;
    char** files = NULL;
    int nb_files = 0;
    get_files(&files, &nb_files);
    int ch;
    while (1) {
        show_options(pages, selected, nb_files);
        refresh();
        ch = getch();
        switch (ch) {
            case '2':
            case KEY_DOWN:
                if (selected < nb_files - 1)
                    selected++;
                if (selected > pages * 10 + 9 && pages * 10 + 9 < nb_files)
                    pages++;
                refresh();
                break;
            case '8':
            case KEY_UP:
                if (selected > 0)
                    selected--;
                if (selected < pages * 10 && pages > 0)
                    pages--;
                refresh();
                break;
            case '\n':
                load_game(files[selected]);
                return;
            case KEY_LEFT:
            case '4':
            case 27:
                chooseOptions(nb_files, files);
                return;
        }
    }
    refresh();
}

// touche sur le côté
//verifie qu'un joueur a fait son action
//affiche le tour du joueur en mode
//change le message de victoire
//nom deja utiloise pour lesq sauvegardes 
//si pas de partie cacher l'option 
//crée des partie ou y'a plus que 1 ou 2 coups pour gagner
//indique e nombre de caractere max pour un nom de partie et contraite aec les signes

