#include "tiro_usuario.h"
void tiro_usuario(COORDENADA nave_pos, char mapa[LINHAS][COLUNAS])
{
    int i, j, x, y;
    i = nave_pos.linha + 1;
    j = nave_pos.coluna + 4;

    if(mapa[nave_pos.linha][nave_pos.coluna] == '@') //gera o tiro
    {
        mapa[i][j] = '-';
        mapa[i][j+1] = '-';
    }

    for(x = 0; x < LINHAS; x++)
    {
        for(y = 0; y < COLUNAS; y++)
        {
            if(mapa[i][j] == '-' && mapa[i][j+1] == '-')//movimenta o tiro
            {
                mapa[i][j] = ' ';
                mapa[i][j+2] = '-';
            }
        }
    }

}
