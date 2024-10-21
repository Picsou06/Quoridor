


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
    int x = 0;
    int y = 0;
    int axes = 1;

    

    // Wait for user input
    getch();

    // Clean up ncurses
    endwin();

    return 0;
}
