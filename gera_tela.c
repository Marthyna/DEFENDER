#include "gera_tela.h"

void gera_tela(char mapa[LINHAS][COLUNAS], char tela[LINHAS][COLUNAS_TELA], int coluna_atual)
{
    int i, j;
    for(i = 0; i < LINHAS; i++)
        for(j = 0; j < COLUNAS_TELA; j++)
            if((j + coluna_atual) >= COLUNAS)
                tela[i][j] = mapa[i][(j + coluna_atual) - COLUNAS];
            else
                tela[i][j] = mapa[i][j + coluna_atual];
}
