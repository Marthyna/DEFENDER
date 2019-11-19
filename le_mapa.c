#include "le_mapa.h"

COORDENADA le_mapa(FILE *arq, char mapa[LINHAS][COLUNAS], COORDENADA naves[21])
{
    int i, j, x, y, a;
    char c, z;
    COORDENADA nave_pos_inicial;
    COORDENADA inimigo_pos_inicial;

    for(a = 0; a < 21; a++) // inicialização do array de coordenadas
    {
        naves[a].linha = 0;
        naves[a].coluna = 0;
    }


    for(i = 0; i < LINHAS; i++) //varredura do mapa para encontrar a nave do jogador
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
                naves[0] = nave_pos_inicial;

            }
        }
    }
    for (x = 0; x < LINHAS; x++)// varredura do mapa para encontrar a nave inimiga
    {
        for(y = 0, a = 1; y < COLUNAS; y++, a++)
        {
            z = fgetc(arq);
            mapa[x][y] = z;
            //completa a nave inimiga
            if(z == 'X')
            {
                inimigo_pos_inicial.linha = x;
                inimigo_pos_inicial.coluna = y;
                while (a < 21)
                {
                    naves[a] = inimigo_pos_inicial;
                }
            }
        }
    }
    return naves[21];
}
