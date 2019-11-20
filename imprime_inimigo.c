#include "imprime_inimigo.h"

void imprime_inimigo(char mapa[LINHAS][COLUNAS], COORDENADA naves[MAXNAVES], int inimigos_lidos)
{
    int i, j, z;

    for(z = 1; z < inimigos_lidos; z++)
    {
        i = naves[z].linha;
        j = naves[z].coluna;

        mapa[i][j] = 'X';
        mapa[i-1][j] = 'X';
        mapa[i-1][j+1] = 'X';
        mapa[i][j+1] = 'X';
    }
}
