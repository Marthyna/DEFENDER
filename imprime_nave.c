#include "imprime_nave.h"

void imprime_nave(char mapa[LINHAS][COLUNAS], COORDENADA nave_posicao)
{
    int i, j, x, y;
    i = nave_posicao.linha;
    j = nave_posicao.coluna;

    for(x = 0; x < LINHAS; x++)
        for(y = 0; y < COLUNAS; y++)
            if((x != i || y != j) && (mapa[x][y] == '@'))
                mapa[x][y] = ' ';

    mapa[i][j] = '@';
    mapa[i-1][j] = '@';
    mapa[i][j+1] = '@';
    mapa[i][j+2] = '@';
    mapa[i][j+3] = '@';
}
