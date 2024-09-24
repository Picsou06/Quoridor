#include <ncursesw/curses.h>

#define BOARD_SIZE 9

void draw_board() {
    int i, j;
    int cell_width = 4; // Width of each cell in characters

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Draw the board
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            // Draw horizontal lines
            mvprintw(i * 2, j * cell_width, "+---");
            // Draw vertical lines
            mvprintw(i * 2 + 1, j * cell_width, "|   ");
        }
        // Draw the rightmost vertical line
        mvprintw(i * 2, BOARD_SIZE * cell_width, "+\n");
        mvprintw(i * 2 + 1, BOARD_SIZE * cell_width, "|\n");
    }

    // Draw the bottom horizontal line
    for (j = 0; j < BOARD_SIZE; j++) {
        mvprintw(BOARD_SIZE * 2, j * cell_width, "+---");
    }
    mvprintw(BOARD_SIZE * 2, BOARD_SIZE * cell_width, "+\n");

    // Refresh the screen
    refresh();
}


//TODO Fonction qui crée un mur de la couleur passé en entrée (ROUGE, BLEU) avec des #. Il prend en parametre la position du centre et l angle de rotation (vertical/horizontal) c'est un mur de QUORIDOR donc un mur qui fait deux case de large (mais juste une ligne) avec comme centre notre position
void draw_wall(int row, int col, int color, int angle) {
    if (angle==0)
        {
                // Set the color
            attron(COLOR_PAIR(color));

            // Draw the wall
            mvprintw(row, col, "#####");
            mvprintw(row, col-4, "#####");

            // Reset the color
            attroff(COLOR_PAIR(color));
        }
    else
        {
            // Set the color
            attron(COLOR_PAIR(color));

            // Draw the wall
            mvprintw(row, col, "#");
            mvprintw(row-1, col, "#");
            mvprintw(row-2, col, "#");
            mvprintw(row+1, col, "#");
            mvprintw(row+2, col, "#");

            // Reset the color
            attroff(COLOR_PAIR(color));
        }


    // Refresh the screen
    refresh();
}


int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Enable color support
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    // Draw the board
    draw_board();

    // Draw a wall at row 2, column 4
    draw_wall(6, 4, 1, 1);

    // Wait for user input
    getch();

    // Clean up ncurses
    endwin();

    return 0;
}