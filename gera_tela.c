#include "gera_tela.h"
void gera_tela(JOGO jogo_t, char tela[LINHAS][COLUNAS_TELA], int coluna_atual) {
    int i, j;
    int fim;
    for(i = 0; i < LINHAS; i++)
        for(j = 0, fim = coluna_atual; j < COLUNAS_TELA; j++, fim++) {
            if(fim == COLUNAS)
                fim = 0;
            tela[i][j] = jogo_t.mapa[i][fim];
        }
}
