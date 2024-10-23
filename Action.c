#include "header.h"
void select_wall(int player)
{
    int ch = 0;
    if (player==1)
    {
         int x = Player1x;
         int y = Player1y;
    }
    else
    {
         int x = Player2x;
         int y = Player2y;
    }


    while (ch != '\n') {
        ch = getch(); // Lire l'entrée utilisateur
        switch (ch) {
            case 'c':
                clear();
                draw_board();
                break;
            case KEY_UP:
                if (x > 0) x -= 1;
                break;
            case KEY_DOWN:
                if (x < BOARD_SIZE * 2 + 1 - 2) x += 1;
                break;
            case KEY_LEFT:
                if (y > 0) y -= 1;
                break;
            case KEY_RIGHT:
                if (y < BOARD_SIZE * 4 + 1 - 4) y += 1;
                break;
            case ' ':
                axes = !axes;
                break;
        }
        draw_wall(player, 1, axes);
        printf("Wall created on: %d : %d\n", x, y);
    }
}