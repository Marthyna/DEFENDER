#include "movimenta_nave.h"
COORDENADA movimenta_nave(char mapa[LINHAS][COLUNAS])
{
    COORDENADA nave_pos_atualizada;
    int i, j;
    for(i = 0; i < LINHAS; i++)
        for(j = 0; j < COLUNAS; j++)
            if(mapa[i][j] == '@')
            {
                nave_pos_atualizada.linha = i;
                nave_pos_atualizada.coluna = j;
            }
    return nave_pos_atualizada;
}
