#include "le_mapa.h"

void le_mapa(FILE *arq, char mapa[LINHAS][COLUNAS])
{
    int i, j;
    char c;

    for(i = 0; i < LINHAS; i++)
    {
        for(j = 0; j < COLUNAS; j++)
        {
            c = fgetc(arq);
            mapa[i][j] = c;

            // completa a nave do jogador
            if(c == '@')
            {
                mapa[i-1][j] = c;
                mapa[i][j+1] = c;
                mapa[i][j+2] = c;
                mapa[i][j+3] = c;
                j += 3;
            }
            // completa as naves dos inimigos
            if(c == 'X')
            {
                mapa[i-1][j] = c;
                mapa[i-1][j+1] = c;
                mapa[i][j+1] = c;
                j += 1;

            }
        }
        // captura o \n no fim de cada linha
        c = fgetc(arq);
    }
}
