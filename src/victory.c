#include "quoridor.h"

void checkvictory(Game *game)
{
    /*
    Fonction: checkvictory
    Auteur: Evan , thomas
    Paramètres: Game game
    Traitement : Vérifie si un joueur a gagné
    Retour: void
    */
    int start_row = LINES / 2 - 5;
    int start_col = COLS / 2 - strlen("::::::::::. :::      :::.  .-:.     ::-..,:::::: :::::::..       .-:.     ::-.    .::    .   .:::    :::    :::.    :::.") / 2;
    if (game->listOfPlayers[0]->y == victoryPlayer1)
    {
        clear();
        mvprintw(start_row, start_col, "::::::::::. :::      :::.  .-:.     ::-..,:::::: :::::::..         .,::      .:    .::    .   .:::    :::    :::.    :::.");
        mvprintw(start_row + 1, start_col, " `;;;```.;;;;;;      ;;`;;  ';;.   ;;;;';;;;'''' ;;;;``;;;;        `;;;,  .,;;     ';;,  ;;  ;;;'     ;;;    `;;;;,  `;;;");
        mvprintw(start_row + 2, start_col, "  `]]nnn]]' [[[     ,[[ '[[,  '[[,[[['   [[cccc   [[[,/[[['          '[[,,[['       '[[, [[, [['      [[[      [[[[[. '[[");
        mvprintw(start_row + 3, start_col, "   $$$\"\"    $$'    c$$$cc$$$c   c$$\"     $$\"\"\"\"   $$$$$$c             Y$$$P           Y$c$$$c$P       $$$      $$$ \"Y$c$$");
        mvprintw(start_row + 4, start_col, "   888o    o88oo,.__888   888,,8P\"`      888oo,__ 888b \"88bo,       oP\"``\"Yo,          \"88\"888        888      888    Y88");
        mvprintw(start_row + 5, start_col, "   YMMMb   \"\"\"\"YUMMMYMM   \"\"`mM\"         \"\"\"\"YUMMMMMMM   \"W\"     ,m\"       \"Mm,         \"M \"M\"        MMM      MMM     Y");
        refresh();
        sleep(5);
        remove("saved_game.txt");
        clear();
        chooseOptions();
    }
    else if (game->listOfPlayers[1]->y == victoryPlayer2)
    {
        clear();
        mvprintw(start_row, start_col, "::::::::::. :::      :::.  .-:.     ::-..,:::::: :::::::..       .-:.     ::-.    .::    .   .:::    :::    :::.    :::.");
        mvprintw(start_row + 1, start_col, " `;;;```.;;;;;;      ;;`;;  ';;.   ;;;;';;;;'''' ;;;;``;;;;       ';;.   ;;;;'    ';;,  ;;  ;;;'     ;;;    `;;;;,  `;;;");
        mvprintw(start_row + 2, start_col, "  `]]nnn]]' [[[     ,[[ '[[,  '[[,[[['   [[cccc   [[[,/[[['         '[[,[[['       '[[, [[, [['      [[[      [[[[[. '[[");
        mvprintw(start_row + 3, start_col, "   $$$\"\"    $$'    c$$$cc$$$c   c$$\"     $$\"\"\"\"   $$$$$$c             c$$\"           Y$c$$$c$P       $$$      $$$ \"Y$c$$");
        mvprintw(start_row + 4, start_col, "   888o    o88oo,.__888   888,,8P\"`      888oo,__ 888b \"88bo,       ,8P\"`             \"88\"888        888      888    Y88");
        mvprintw(start_row + 5, start_col, "   YMMMb   \"\"\"\"YUMMMYMM   \"\"`mM\"         \"\"\"\"YUMMMMMMM   \"W\"       mM\"                 \"M \"M\"        MMM      MMM     Y");
        refresh();
        sleep(5);
        remove("saved_game.txt");
        clear();
        chooseOptions();
    }
}