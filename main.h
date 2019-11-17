#ifndef MAIN_H
    #define MAIN_H
    #include <stdio.h>
    #include <conio2.h>
    #include <locale.h>
    #include <windows.h>

    #define LINHAS 35
    #define COLUNAS 415
    #define COLUNAS_TELA 105
    #define FILE_MAPA "mapa.txt"

    typedef struct
    {
        int linha;
        int coluna;
    } COORDENADA;

    typedef struct
    {
        int vidas;
        int escore;
        int delay;
        char mapa[LINHAS][COLUNAS];
    } JOGO;

#endif
