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

void save_game(Game game, char *filename) {
    /*
    Fonction: save_game
    Auteur:Evan
    Paramètres: Game game
    Traitement : Sauvegarde la partie
    Retour: void
    */
    char filepath[100];
    strcpy(filepath, "./saved_game/");
    strcat(filepath, filename);
    strcat(filepath, ".txt");
    FILE *file = fopen(filepath, "w");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }
    fprintf(file, "%s\n", game.name);
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
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Failed to open the file for reading.\n");
        return;
    }
    char *name;
    fscanf(file, "%s", &name);
    int nbPlayers;
    fscanf(file, "%d", &nbPlayers);

    Game* game = createGame(nbPlayers, name);
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


    mvprintw(0, 0, "###################################");
    mvprintw(1, 1, "Select a save to load: %d", selected);
    for (int i = pages * 8; i <= pages * 8 + 7 && i < numFiles; i++) {
        if (i == selected)
            attron(A_REVERSE);
        mvprintw(i + 1 - pages * 8, 1, files[i]);
        if (i == selected)
            attroff(A_REVERSE);
    }
    refresh();
}

void menu_save() {
    int selected = 0;
    int pages = 0;
    char** files = NULL;
    int nb_files = 0;
    get_files(&files, &nb_files);
    int ch;
    printf("nb_files: %d\n", nb_files);
    while (1) {
        show_options(pages, selected, nb_files);
        printf("Options Showed");
        refresh();
        ch = getch();
        switch (ch) {
            case KEY_DOWN:
                if (selected < nb_files - 1)
                    selected++;
                if (selected > pages * 8 + 7 && pages * 8 + 7 < nb_files)
                    pages++;
                refresh();
                break;
            case KEY_UP:
                if (selected > 0)
                    selected--;
                if (selected < pages * 8 && pages > 0)
                    pages--;
                refresh();
                break;
            case '\n':
                load_game(files[selected]);
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

