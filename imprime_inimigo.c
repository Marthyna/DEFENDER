#include "imprime_inimigo.h"
#include "tiro_inimigo.h"
#include "movimenta_tiro_inimigo.h"

void imprime_inimigo(JOGO *jogo_t, int inimigos_lidos)
{
    int i, j, z;

    for(z = 0; z < inimigos_lidos; z++)
    {
        i = (*jogo_t).inimigos[z].posicao_t.linha;
        j = (*jogo_t).inimigos[z].posicao_t.coluna;

        (*jogo_t).mapa[i][j] = 'X';
        (*jogo_t).mapa[i-1][j] = 'X';
        (*jogo_t).mapa[i-1][j+1] = 'X';
        (*jogo_t).mapa[i][j+1] = 'X';

        if((*jogo_t).inimigos[z].flag_atira)
        {
            tiro_inimigo((*jogo_t).inimigos[z], (*jogo_t).mapa, (*jogo_t).inimigos[z].flag_atira);
            movimenta_tiro_inimigo((*jogo_t).inimigos, (*jogo_t).mapa, inimigos_lidos);
        }
    }
}
