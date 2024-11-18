#include "quoridor.h"

void draw_wall(Game game) {
    /*
    Fonction: draw_wall
    Auteur: Evan
    Paramètres: void
    Traitement : Dessine les murs dans la Console
    Retour: void
    */
    int row = game.playerPlaying.yWall * 2;
    int col = game.playerPlaying.xWall * 4;

    if (game.playerPlaying.axes == 0) {
        if (game.playerPlaying.xWall > 0) {
            game.board.board[row][col - 4] = '#';
            game.board.board[row][col - 3] = '#';
            game.board.board[row][col - 2] = '#';
            game.board.board[row][col - 1] = '#';
            printf("WALL CREATION 1\n");
        }
        if (game.playerPlaying.xWall < BOARD_SIZE) {
            game.board.board[row][col + 1] = '#';
            game.board.board[row][col + 2] = '#';
            game.board.board[row][col + 3] = '#';
            game.board.board[row][col + 4] = '#';
            printf("WALL CREATION 2\n");
        }
        game.board.board[row][col] = '#';
    } else {
        if (game.playerPlaying.yWall > 0) {
            game.board.board[row - 2][col] = '#';
            game.board.board[row - 1][col] = '#';
            printf("WALL CREATION 3\n");
        }
        if (game.playerPlaying.yWall < BOARD_SIZE) {
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
    mvprintw(row, col, "%c", game.listOfPlayers[0].icon);
    attroff(COLOR_PAIR(game.listOfPlayers[0].color));

    row = start_row + game.listOfPlayers[1].y * 2 + game.listOfPlayers[1].team;
    col = start_col + game.listOfPlayers[1].x * MY_CELL_WIDTH + MY_CELL_WIDTH / 2;

    attron(COLOR_PAIR(game.listOfPlayers[1].color));
    mvprintw(row, col, "%c", game.listOfPlayers[1].icon);
    attroff(COLOR_PAIR(game.listOfPlayers[1].color));
    refresh();
}

void displayTempPlayer(Game game) {
    draw_board(game);
    // Calculate the starting position to center the board
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * MY_CELL_WIDTH)) / 2;

    // Calculate the position to display the player
    int row = start_row + game.listOfPlayers[0].MovementY * 2 + game.listOfPlayers[0].team;
    int col = start_col + game.listOfPlayers[0].MovementX * MY_CELL_WIDTH + MY_CELL_WIDTH / 2;

    // Apply the player's color
    attron(COLOR_PAIR(game.listOfPlayers[0].color));
    mvprintw(row, col, "%c", game.listOfPlayers[0].icon);
    attroff(COLOR_PAIR(game.listOfPlayers[0].color));

    row = start_row + game.listOfPlayers[1].MovementY * 2 + game.listOfPlayers[1].team;
    col = start_col + game.listOfPlayers[1].MovementX * MY_CELL_WIDTH + MY_CELL_WIDTH / 2;

    attron(COLOR_PAIR(game.listOfPlayers[1].color));
    mvprintw(row, col, "%c", game.listOfPlayers[1].icon);
    attroff(COLOR_PAIR(game.listOfPlayers[1].color));
    refresh();
}

void redraw(Game game) {
    clear();
    draw_board(game);
    displayPlayer(game);
    refresh();
}