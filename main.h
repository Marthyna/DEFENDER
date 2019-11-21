#ifndef MAIN_H
    #define MAIN_H
    #include <stdio.h>
    #include <locale.h>
    #include <conio2.h>
    #include <windows.h>

    #define LINHAS 35
    #define COLUNAS 415
    #define COLUNAS_TELA 105
    #define MAXNAVES 21
    #define VIDAS 3
    #define NOMEMAX 10
    #define FILE_MAPA "mapa.txt"
    #define FILE_SALVOS "salvos.bin"

    typedef struct
    {
        int linha;
        int coluna;
    } COORDENADA;

    typedef struct
    {
        int vidas;
        int escore;
        int velocidade;
        char nome[NOMEMAX];
        COORDENADA posicao_t;
    } JOGADOR;

    typedef struct
    {
        JOGADOR jogador_t;
        int delay;
        char mapa[LINHAS][COLUNAS];
    } JOGO;

#endif
