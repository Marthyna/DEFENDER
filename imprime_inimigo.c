#include "imprime_inimigo.h"

void imprime_inimigo(JOGO *jogo_t)
{
    int i, j, z;

    for(z = 0; z < (*jogo_t).qt_inimigos; z++)
    {
        if(!(*jogo_t).inimigos[z].flag_morto)
        {
            i = (*jogo_t).inimigos[z].posicao_t.linha;
            j = (*jogo_t).inimigos[z].posicao_t.coluna;

            (*jogo_t).mapa[i][j] = 'X';
            (*jogo_t).mapa[i-1][j] = 'X';
            (*jogo_t).mapa[i-1][j+1] = 'X';
            (*jogo_t).mapa[i][j+1] = 'X';

        }
    }
}
