#include "imprime_nave.h"

void imprime_nave(char mapa[LINHAS][COLUNAS], COORDENADA nave_posicao)
{
    int i, j;
    int flag_achei_nave = 0;
    for(i = 0; i < LINHAS; i++)
        for(j = 0; j < COLUNAS && flag_achei_nave == 0; j++)
        {
            if(mapa[i][j] == '@')
            {
                mapa[i-1][j] = '@';
                mapa[i][j+1] = '@';
                mapa[i][j+2] = '@';
                mapa[i][j+3] = '@';
                flag_achei_nave = 1;
            }
        }
}
