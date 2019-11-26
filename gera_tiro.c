#include "gera_tiro.h"
void gera_tiro(COORDENADA nave_pos, char mapa[LINHAS][COLUNAS])
{
    int i, j;
    i = nave_pos.linha;
    j = nave_pos.coluna + 4;

    //gera o tiro

    mapa[i][j+1] = '-';
    mapa[i][j+2] = '-';


}
