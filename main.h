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
    } COORDENADA; // Tipo definido que serve para guardar as posições de certos objetos em um só lugar.
    typedef struct {
        int direcao; // Variável que serve para guardar o numero correspondente ao movimento a ser executado pelo inimigo.
        int flag_atira; // Flag para sinalizar quando o inimigo atira.
        int flag_morto; // Flag para sinalizar quando o inimigo morre.
        int flag_continua_tiro; // Flag que sinaliza se o tiro precisa continuar a se movimentar ou se ele chocou com alguma parede.
        COORDENADA posicao_tiro_t; // Guarda as posições dos tiros do inimigo.
        COORDENADA posicao_t;// Guarda a posição do inimigo.
    } INIMIGO;
    typedef struct {
        int vidas;// Guarda a quantidade de vidas do Jogador.
        int escore;// Guarda a pontuação do jogador.
        int velocidade;// Guarda a velocidade do Jogador.
        int flag_atira;// Flag para verificação de tiro do Jogador.
        COORDENADA posicao_t;// Guarda a posição do Jogador.
    } JOGADOR;
    typedef struct {
        JOGADOR jogador_t; // Variável que guarda as informações do jogador atual.
        INIMIGO inimigos[MAXINIMIGOS];// Variável que guarda as informações de todos os inimigos correntes no mapa.
        int qt_inimigos;// Variável que guarda a quantidade de inimigos que se encontram no mapa durante o jogo.
        int delay;
        char mapa[LINHAS][COLUNAS];// Matriz do mapa.
    } JOGO;
#endif
