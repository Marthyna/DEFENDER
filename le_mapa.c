#include "le_mapa.h"

int le_mapa(FILE *arq, char mapa[LINHAS][COLUNAS], COORDENADA naves[MAXNAVES])
{
    int i, j;
    int a = 1;
    char c;
    COORDENADA nave_pos_inicial;
    COORDENADA inimigo_pos_inicial;

    for(i = 0; i < LINHAS; i++) //varredura do mapa para encontrar as naves
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
            } else if(c == 'X')
            {
                inimigo_pos_inicial.linha = i;
                inimigo_pos_inicial.coluna = j;
                naves[a] = inimigo_pos_inicial;
                a++;
            }
        }
    }
    return a;
}
