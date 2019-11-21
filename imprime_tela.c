#include "imprime_tela.h"

void imprime_tela(char tela[LINHAS][COLUNAS_TELA])
{
    int i, j, k;
    for(i = 0, k = 2; i < LINHAS; i++, k++)
        for(j = 0; j < COLUNAS_TELA; j++)
            putchxy(j, k, tela[i][j]);
}
