#include "menu_inicial.h"
char menu_inicial() {
    char opcao;
    gotoxy(30, 9);
    printf("DEFENDER");
    gotoxy(30, 11);
    printf("Por Henrique Bernardes e Marthyna Weber");
    Sleep(1000);
    gotoxy(30, 18);
    printf("SELECIONE UMA OPCAO:");
    gotoxy(30, 19);
    printf("1 - Novo Jogo");
    gotoxy(30, 20);
    printf("2 - Continuar Jogando");
    gotoxy(30, 21);
    printf("3 - Sair");
    gotoxy(30, 22);
    opcao = getch();
    clrscr();
    return opcao;
}
