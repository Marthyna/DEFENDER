#include "game_over.h"
void game_over() {
    Sleep(1000);
    gotoxy(14,10);
    printf("            ");
    gotoxy(14,10);
    printf("GAME OVER");
    Sleep(500);
    gotoxy(14,10);
    printf("           ");
    Sleep(500);
    gotoxy(14,10);
    printf("GAME OVER");
    Sleep(500);
    gotoxy(14,10);
    printf("           ");
    Sleep(500);
    gotoxy(14,10);
    printf("GAME OVER");
    Sleep(1000);
    clrscr();
}
