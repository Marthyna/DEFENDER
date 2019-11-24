#include "movimenta_tiro.h"

void movimenta_tiro(char mapa[LINHAS][COLUNAS])
{
    int i, j;
    for(i = 0; i < LINHAS; i++)
    {
        for(j = 0; j < COLUNAS; j++)
        {
            if(mapa[i][j] == '-')
            {
                mapa[i][j] = ' ';
                mapa[i][j + 1] = ' ';
                mapa[i][j + 3] = '-';
                mapa[i][j + 4] = '-';
                break;
            }
        }
    }
}
