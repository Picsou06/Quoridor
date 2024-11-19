#include "quoridor.h"

Game createGame(int nbOfPlayer) {
    Game game;
    Player Player1 = createPlayer('X', 0, 4, 0, 1, 0, 9, 0, 9);
    Player Player2 = createPlayer('O', 1, 4, 9, -1, 0, 9, 0, 9);
    
    // Allocate memory for the list of players
    game.listOfPlayers = (Player*)malloc(nbOfPlayer * sizeof(Player));
    if (game.listOfPlayers == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    // Add Player1 and Player2 to the list
    game.listOfPlayers[0] = Player1;
    game.listOfPlayers[1] = Player2;
    game.nbPlayers = nbOfPlayer;
    game.listOfWalls = (Wall*)malloc(MAXWALL * nbOfPlayer * sizeof(Wall));
    game.nbWalls = 0;
    game.board = createBoard();
    
    return game;
}

Player createPlayer(char icon, int color, int x, int y, int team, int limitRight, int limitLeft, int limitUp, int limitDown) {
    /*
    Fonction: createPlayer
    Auteur: Evan
    Paramètres: void
    Traitement : Crée un joueur avec des valeurs par défaut
    Retour: Player
    */
    Player* player;
    player.icon = icon;
    player.color = color;
    player.x = x;
    player.y = y;
    player.MovementX = x;
    player.MovementY = y;
    player.team = team;
    player.xWall = 5;
    player.yWall = 5;
    player.nbWall = MAXWALL;
    player.axes = 0;
    player.limitRight = limitRight;
    player.limitLeft = limitLeft;
    player.limitUp = limitUp;
    player.limitDown = limitDown;
    printf("%i, %i, %i, %i debug\n", player.limitRight, player.limitLeft, player.limitUp, player.limitDown);
    return player;
}

Board createBoard() {
    Board board;
    for (int i = 0; i < BOARD_SIZE * 2; i++) {
        for (int j = 0; j < BOARD_SIZE * 4; j++) {
            if (i % 2 == 0 && j % MY_CELL_WIDTH == 0) {
                board.board[i][j] = '+';
                board.color[i][j] = 0;
            } else if (i % 2 == 0) {
                board.board[i][j] = '-';
                board.color[i][j] = 0;
            } else if (j % MY_CELL_WIDTH == 0) {
                board.board[i][j] = '|';
                board.color[i][j] = 0;
            } else {
                board.board[i][j] = ' ';
                board.color[i][j] = 0;
            }
        }
    }
    // Add the final row and column
    for (int j = 0; j < BOARD_SIZE * 4; j++) {
        if (j % MY_CELL_WIDTH == 0) {
            board.board[BOARD_SIZE * 2][j] = '+';
            board.color[BOARD_SIZE * 2][j] = 0;
        } else {
            board.board[BOARD_SIZE * 2][j] = '-';
            board.color[BOARD_SIZE * 2][j] = 0;
        }
    }
    for (int i = 0; i < BOARD_SIZE * 2 + 1; i++) {
        if (i % 2 == 0) {
            board.board[i][BOARD_SIZE * 4] = '+';
            board.color[i][BOARD_SIZE * 4] = 0;
        } else {
            board.board[i][BOARD_SIZE * 4] = '|';
            board.color[i][BOARD_SIZE * 4] = 0;
        }
    }
    return board;
}
