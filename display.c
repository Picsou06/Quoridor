#include "quoridor.h"

void redraw(Game* game) {
    clear();
    draw_board();
    draw_all_wall(game);
    displayAllPlayer(game);
    displayNbWall(game);
    refresh();
}