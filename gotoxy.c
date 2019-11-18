#include "gotoxy.h"
void gotoxy (int x, int y)
    {
     COORD coord = {0, 0};
     coord.X = x; coord.Y = y; // X and Y coordinates
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
