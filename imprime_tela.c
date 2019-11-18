#include "imprime_tela.h"

void imprime_tela(char tela[LINHAS][COLUNAS_TELA])
{
    int i, j;
    for(i = 0; i < LINHAS; i++)
    {
        for(j = 0; j < COLUNAS_TELA; j++)
        {
            printf("%c", tela[i][j]);
        }
    }
}
