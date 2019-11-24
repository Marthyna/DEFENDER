#ifndef MAIN_H
    #define MAIN_H
    #include <stdio.h>
    #include <locale.h>
    #include <conio2.h>
    #include <windows.h>

    #define LINHAS 35
    #define COLUNAS 415
    #define COLUNAS_TELA 105
    #define MAXINIMIGOS 20
    #define MIN_DIRECAO 1
    #define MAX_DIRECAO 9
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
        int direcao;
        int velocidade;
        int sentido;
        int flag_atira;
        COORDENADA posicao_tiro_t;
        COORDENADA posicao_t;
    } INIMIGO;

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
        INIMIGO inimigos[MAXINIMIGOS];
        int delay;
        char mapa[LINHAS][COLUNAS];
    } JOGO;

#endif
