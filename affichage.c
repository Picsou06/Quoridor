#include "quoridor.h"

void draw_board(Game game) {
    /*
    Fonction: draw_board
    Auteur:Evan
    Paramètres: void
    Traitement : Dessine le tableau de format 9*9 dans la Console
    Retour: void
    */
   // Calculate the starting position to center the board
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;

    // Draw the board
    for (int i = 0; i < BOARD_SIZE * 3; i++) {
        for (int j = 0; j < BOARD_SIZE * 5; j++) {
            int row = start_row + i;
            int col = start_col + j;
            attron(COLOR_PAIR(game.board.color[i][j]));
            mvprintw(row, col, "%c", game.board.board[i][j]);
            attroff(COLOR_PAIR(game.board.color[i][j]));
        }
    }
    refresh();
}


void draw_wall(Game game) {
    /*
    Fonction: draw_wall
    Auteur: Evan
    Paramètres: void
    Traitement : Dessine les murs dans la Console
    Retour: void
    */
    int row = game.listOfPlayers[game.playerPlaying].yWall * 2;
    int col = game.listOfPlayers[game.playerPlaying].xWall * 4;

    if (game.listOfPlayers[game.playerPlaying].axes == 0) {
        if (game.listOfPlayers[game.playerPlaying].xWall > 0) {
            game.board.board[row][col - 4] = '#';
            game.board.board[row][col - 3] = '#';
            game.board.board[row][col - 2] = '#';
            game.board.board[row][col - 1] = '#';
            printf("WALL CREATION 1\n");
        }
        if (game.listOfPlayers[game.playerPlaying].xWall < BOARD_SIZE) {
            game.board.board[row][col + 1] = '#';
            game.board.board[row][col + 2] = '#';
            game.board.board[row][col + 3] = '#';
            game.board.board[row][col + 4] = '#';
            printf("WALL CREATION 2\n");
        }
        game.board.board[row][col] = '#';
    } else {
        if (game.listOfPlayers[game.playerPlaying].yWall > 0) {
            game.board.board[row - 2][col] = '#';
            game.board.board[row - 1][col] = '#';
            printf("WALL CREATION 3\n");
        }
        if (game.listOfPlayers[game.playerPlaying].yWall < BOARD_SIZE) {
            game.board.board[row + 1][col] = '#';
            game.board.board[row + 2][col] = '#';
            printf("WALL CREATION 4\n");
        }
        game.board.board[row][col] = '#';
    }

    // Call draw_board and displayPlayer
    clear();
    draw_board(game);
    displayPlayer(game);
    printf("WALL CREATION END");
}

void displayPlayer(Game game) {
    // Calculate the starting position to center the board
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;

    // Calculate the position to display the player
    int row = start_row + game.listOfPlayers[0].y * 2 + game.listOfPlayers[0].team;
    int col = start_col + game.listOfPlayers[0].x * MY_CELL_WIDTH + MY_CELL_WIDTH / 2;

    // Apply the player's color
    attron(COLOR_PAIR(game.listOfPlayers[0].color));
    mvprintw(row, col, "%c", game.listOfPlayers[game.playerPlaying].icon);
    attroff(COLOR_PAIR(game.listOfPlayers[0].color));

    row = start_row + game.listOfPlayers[1].y * 2 + game.listOfPlayers[1].team;
    col = start_col + game.listOfPlayers[1].x * MY_CELL_WIDTH + MY_CELL_WIDTH / 2;

    attron(COLOR_PAIR(game.listOfPlayers[1].color));
    mvprintw(row, col, "%c", game.listOfPlayers[1].icon);
    attroff(COLOR_PAIR(game.listOfPlayers[1].color));
    refresh();
}

void displayTempPlayer(Game game) {
    // Calculate the starting position to center the board
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;

    // Calculate the position to display the player
    int row = start_row + game.listOfPlayers[game.playerPlaying].MovementY * 2 + game.listOfPlayers[0].team;
    int col = start_col + game.listOfPlayers[game.playerPlaying].MovementX * MY_CELL_WIDTH + MY_CELL_WIDTH / 2;
    int Initialrow = start_row + game.listOfPlayers[game.playerPlaying].y * 2 + game.listOfPlayers[0].team;
    int Initialcol = start_col + game.listOfPlayers[game.playerPlaying].x * MY_CELL_WIDTH + MY_CELL_WIDTH / 2;

    // Apply the player's color
    attron(COLOR_PAIR(game.listOfPlayers[game.playerPlaying].color));
    mvprintw(row, col, "%c", game.listOfPlayers[game.playerPlaying].icon);
    attroff(COLOR_PAIR(game.listOfPlayers[game.playerPlaying].color));
    attron(COLOR_PAIR(0));
    mvprintw(row, col, "%c", game.listOfPlayers[game.playerPlaying].icon);
    attroff(COLOR_PAIR(0));
    refresh();
}

void redraw(Game game) {
    clear();
    draw_board(game);
    displayPlayer(game);
    refresh();
}