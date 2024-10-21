void draw_board() {
    int i, j;
    int cell_width = 4;

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Calculate the starting position to center the board
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * cell_width)) / 2;

    // Draw the board
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            // Draw horizontal lines
            mvprintw(start_row + i * 2, start_col + j * cell_width, "+---");
            // Draw vertical lines
            mvprintw(start_row + i * 2 + 1, start_col + j * cell_width, "|   ");
        }
        // Draw the rightmost vertical line
        mvprintw(start_row + i * 2, start_col + BOARD_SIZE * cell_width, "+\n");
        mvprintw(start_row + i * 2 + 1, start_col + BOARD_SIZE * cell_width, "|\n");
    }

    // Draw the bottom horizontal line
    for (j = 0; j < BOARD_SIZE; j++) {
        mvprintw(start_row + BOARD_SIZE * 2, start_col + j * cell_width, "+---");
    }
    mvprintw(start_row + BOARD_SIZE * 2, start_col + BOARD_SIZE * cell_width, "+\n");

    // Refresh the screen
    refresh();
}

void draw_wall(int grid_row, int grid_col, int color, int angle) {
    int cell_width = 4;

    // Calculate the starting position to center the board
    int start_row = (LINES - (BOARD_SIZE * 2 + 1)) / 2;
    int start_col = (COLS - (BOARD_SIZE * cell_width)) / 2;

    // Calculate the screen coordinates for the top-left corner of the cell
    int row = start_row + grid_row * 2;
    int col = start_col + grid_col * cell_width;

    if (angle == 0) {
        attron(COLOR_PAIR(color));

        // Draw the horizontal wall
        mvprintw(row, col + 2, "####");
        mvprintw(row, col - 2, "#####");

        attroff(COLOR_PAIR(color));
    } else {
        // Set the color
        attron(COLOR_PAIR(color));

        // Draw the vertical wall
        mvprintw(row + 2, col, "#");
        mvprintw(row + 1, col, "#");
        mvprintw(row, col, "#");
        mvprintw(row - 1, col, "#");
        mvprintw(row - 2, col, "#");

        // Reset the color
        attroff(COLOR_PAIR(color));
    }

    // Refresh the screen
    refresh();
}
