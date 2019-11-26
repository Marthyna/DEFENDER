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
    } COORDENADA; // Tipo definido que serve para guardar as posi��es de certos objetos em um s� lugar.
    typedef struct {
        int direcao; // Vari�vel que serve para guardar o numero correspondente ao movimento a ser executado pelo inimigo.
        int flag_atira; // Flag para sinalizar quando o inimigo atira.
        int flag_morto; // Flag para sinalizar quando o inimigo morre.
        int flag_continua_tiro; // Flag que sinaliza se o tiro precisa continuar a se movimentar ou se ele chocou com alguma parede.
        COORDENADA posicao_tiro_t; // Guarda as posi��es dos tiros do inimigo.
        COORDENADA posicao_t;// Guarda a posi��o do inimigo.
    } INIMIGO;
    typedef struct {
        int vidas;// Guarda a quantidade de vidas do Jogador.
        int escore;// Guarda a pontua��o do jogador.
        int velocidade;// Guarda a velocidade do Jogador.
        int flag_atira;// Flag para verifica��o de tiro do Jogador.
        COORDENADA posicao_t;// Guarda a posi��o do Jogador.
    } JOGADOR;
    typedef struct {
        JOGADOR jogador_t; // Vari�vel que guarda as informa��es do jogador atual.
        INIMIGO inimigos[MAXINIMIGOS];// Vari�vel que guarda as informa��es de todos os inimigos correntes no mapa.
        int qt_inimigos;// Vari�vel que guarda a quantidade de inimigos que se encontram no mapa durante o jogo.
        int delay;
        char mapa[LINHAS][COLUNAS];// Matriz do mapa.
    } JOGO;
#endif
