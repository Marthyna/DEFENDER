#ifndef MAIN_H
    #define MAIN_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <locale.h>
    #include <conio2.h>
    #include <windows.h>
    #define LINHAS 35
    #define COLUNAS 415
    #define COLUNAS_TELA 105
    #define MAXINIMIGOS 20
    #define MIN_DIRECAO 1
    #define MAX_DIRECAO 8
    #define VIDAS 3
    #define DELAY_INICIAL 100
    typedef struct {
        int linha;
        int coluna;
    } COORDENADA;
    typedef struct {
        int direcao;
        int flag_atira;
        int flag_morto;
        int flag_continua_tiro;
        COORDENADA posicao_tiro_t;
        COORDENADA posicao_t;
    } INIMIGO;
    typedef struct {
        int vidas;
        int escore;
        int velocidade;
        int flag_atira;
        COORDENADA posicao_t;
    } JOGADOR;
    typedef struct {
        JOGADOR jogador_t;
        INIMIGO inimigos[MAXINIMIGOS];
        int qt_inimigos;
        int delay;
        char mapa[LINHAS][COLUNAS];
    } JOGO;
#endif
