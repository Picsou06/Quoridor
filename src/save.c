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
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file for reading.\n");
        return;
    }
    int nbPlayers;
    fscanf(file, "%d", &nbPlayers);

    Game* game = createGame(nbPlayers);
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

static char** get_files() {
    clear();
    DIR *dir;
    char** files;
    struct dirent *ent;
    int count = 0;

    dir = opendir("./saved_game");
    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strstr(ent->d_name, ".txt") != NULL) {
                files = realloc(files, (count + 1) * sizeof(char*));
                files[count] = malloc(strlen(ent->d_name) + 1);
                strcpy(files[count], ent->d_name);
                count++;
            }
        }
        closedir(dir);
        return files;
    }
}

void menu_save() {
    /*
    Fonction: menu_save
    Auteur:Evan
    Paramètres: void
    Traitement : Menu de sauvegarde
    Retour: void
    */
    char** files = get_files();
    int pages = 0;
    int selected = 0;
    int count = 0;
    int max = 0;
    int c;
    while (1) {
        clear();
        mvprintw(0, 0, "Select a save to load:");
        for (int i = 0; i < 5; i++) {
            if (count < max) {
                mvprintw(i + 1, 0, "%s", files[count]);
                count++;
            }
        }
        showButton(pages);
        refresh();
        c = getch();
        switch (c) {
            case KEY_UP:
                if (selected > 0) {
                    selected--;
                }
                if (selected < max - 5) {
                    max--;
                }
                break;
            case KEY_DOWN:
                if (selected < count - 1) {
                    selected++;
                }
                if (selected > max) {
                    max++;
                }
                break;
            case KEY_LEFT:
                if (pages > 0) {
                    pages--;
                }
                break;
            case KEY_RIGHT:
                if (pages < count / 5) {
                    pages++;
                }
                break;
            case 10:
                load_game(files[selected]);
                return;
            case 27:
                return;
        }
    }
}


//les murs nombre en couleurs
//une partie fini ° crash
// touche sur le côté
//verifie qu'un joueur a fait son action
//affiche le tour du joueur en mode
//change le message de victoire
//nom deja utiloise pour lesq sauvegardes 
//si pas de partie cacher l'option 
//crée des partie ou y'a plus que 1 ou 2 coups pour gagner

