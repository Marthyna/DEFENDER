#include "le_mapa.h"

COORDENADA le_mapa(FILE *arq, char mapa[LINHAS][COLUNAS])
{
    int i, j;
    char c;
    COORDENADA nave_pos_inicial;

    for(i = 0; i < LINHAS; i++)
    {
        for(j = 0; j < COLUNAS; j++)
        {
            c = fgetc(arq);
            mapa[i][j] = c;
            // completa a nave do jogador
            if(c == '@')
            {
                nave_pos_inicial.linha = i;
                nave_pos_inicial.coluna = j;
            }
        }
    }
    return nave_pos_inicial;
}
