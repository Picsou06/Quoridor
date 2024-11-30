#include "quoridor.h"

void redraw(Game* game) {
    clear();
    draw_board();
    draw_all_wall(game);
    displayPlayer(game);
    refresh();
}