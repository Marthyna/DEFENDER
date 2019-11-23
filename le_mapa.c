#include "le_mapa.h"

int le_mapa(FILE *arq, JOGO *jogo_t)
{
    int i, j;
    int a = 0;
    char c;

    for(i = 0; i < LINHAS; i++) //varredura do mapa para encontrar as naves
    {
        for(j = 0; j < COLUNAS; j++)
        {
            c = fgetc(arq);
            (*jogo_t).mapa[i][j] = c;
            // completa a nave do jogador
            if(c == '@')
            {
                (*jogo_t).jogador_t.posicao_t.linha = i;
                (*jogo_t).jogador_t.posicao_t.coluna = j;
            }
            else if(c == 'X')
            {
                srand(0);
                (*jogo_t).inimigos[a].posicao_t.linha = i;
                (*jogo_t).inimigos[a].posicao_t.coluna = j;
                (*jogo_t).inimigos[a].direcao = MIN_DIRECAO + (rand() % (MAX_DIRECAO - MIN_DIRECAO + 1));
                a++;
            }
        }
    }
    return a;
}
