#include "imprime_inimigo.h"

void imprime_inimigo(char mapa[LINHAS][COLUNAS], COORDENADA inimigo_posicao)
{
    int i, j, x, y;
    i = inimigo_posicao.linha;
    j = inimigo_posicao.coluna;

    for(x = 0; x < LINHAS; x++)
        for(y = 0; y < COLUNAS; y++)
            if((x != i || y != j) && (mapa[x][y] == 'X'))
                mapa[x][y] = ' ';

    mapa[i][j] = 'X';
    mapa[i-1][j] = 'X';
    mapa[i-1][j-1] = 'X';
    mapa[i][j-1] = 'X';
}
