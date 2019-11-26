#include "movimenta_inimigos.h"
int movimenta_inimigos (JOGO *jogo_t, int qt_inimigos)
{
    int i, a, b;
    int flag_colisao;

    for(i = 0; i < qt_inimigos; i++)
    {
        a = (*jogo_t).inimigos[i].posicao_t.linha;
        b = (*jogo_t).inimigos[i].posicao_t.coluna;

        (*jogo_t).mapa[a][b] = ' ';
        (*jogo_t).mapa[a][b+1] = ' ';
        (*jogo_t).mapa[a-1][b] = ' ';
        (*jogo_t).mapa[a-1][b+1] = ' ';

        do
        {
            flag_colisao = 0;
            switch((*jogo_t).inimigos[i].direcao)
            {
                case 0: // cima
                {
                    (*jogo_t).inimigos[i].posicao_t.linha--;
                    (*jogo_t).inimigos[i].posicao_t.coluna++;
                    break;
                }
                case 1: // baixo
                {
                    (*jogo_t).inimigos[i].posicao_t.linha++;
                    (*jogo_t).inimigos[i].posicao_t.coluna++;
                    break;
                }
                case 2: // direita
                {
                    (*jogo_t).inimigos[i].posicao_t.coluna+=2;
                    break;
                }
                case 3: // esquerda
                {
                    (*jogo_t).inimigos[i].posicao_t.coluna--;
                    break;
                }
                case 4: // cima + direita
                {
                    (*jogo_t).inimigos[i].posicao_t.linha--;
                    (*jogo_t).inimigos[i].posicao_t.coluna+=2;
                    break;
                }
                case 5: // cima + esquerda
                {
                    (*jogo_t).inimigos[i].posicao_t.linha--;
                    (*jogo_t).inimigos[i].posicao_t.coluna--;
                    break;
                }
                case 6: // baixo + direita
                {
                    (*jogo_t).inimigos[i].posicao_t.linha++;
                    (*jogo_t).inimigos[i].posicao_t.coluna+=2;
                    break;
                }
                case 7: // baixo + esquerda
                {
                    (*jogo_t).inimigos[i].posicao_t.linha++;
                    (*jogo_t).inimigos[i].posicao_t.coluna--;
                    break;
                }
            }

            a = (*jogo_t).inimigos[i].posicao_t.linha;
            b = (*jogo_t).inimigos[i].posicao_t.coluna;

            if(a < 0) a++;
            else if(a >= LINHAS) a--;
            if(b < 0)
            {
                (*jogo_t).inimigos[i].posicao_t.coluna += COLUNAS;
                b = (*jogo_t).inimigos[i].posicao_t.coluna;
            }
            else if(b > COLUNAS)
            {
                (*jogo_t).inimigos[i].posicao_t.coluna -= COLUNAS;
                b = (*jogo_t).inimigos[i].posicao_t.coluna;
            }
            else if((*jogo_t).mapa[a][b-1] == 'C' ||
                    (*jogo_t).mapa[a+1][b] == 'C' ||
                    (*jogo_t).mapa[a+1][b-1] == 'C' ||
                    (*jogo_t).mapa[a-1][b-1] == 'C' ||
                    (*jogo_t).mapa[a-2][b-1] == 'C' ||
                    (*jogo_t).mapa[a-2][b] == 'C' ||
                    (*jogo_t).mapa[a-2][b+1] == 'C' ||
                    (*jogo_t).mapa[a-2][b+2] == 'C' ||
                    (*jogo_t).mapa[a-1][b+2] == 'C' ||
                    (*jogo_t).mapa[a][b+2] == 'C' ||
                    (*jogo_t).mapa[a+1][b+2] == 'C' ||
                    (*jogo_t).mapa[a+1][b+1] == 'C')
                flag_colisao = 1;
            else if((*jogo_t).mapa[a][b] == 'X' ||
                    (*jogo_t).mapa[a][b+1] == 'X' ||
                    (*jogo_t).mapa[a-1][b] == 'X' ||
                    (*jogo_t).mapa[a-1][b+1] == 'X')
                flag_colisao = 1;
            else if((*jogo_t).mapa[a][b-2] == '-' ||
                    (*jogo_t).mapa[a-1][b-2] == '-')
            {
                (*jogo_t).mapa[a][b] = ' ';
                (*jogo_t).mapa[a][b+1] = ' ';
                (*jogo_t).mapa[a-1][b] = ' ';
                (*jogo_t).mapa[a-1][b+1] = ' ';
                (*jogo_t).inimigos[i].flag_morto = 1;
                (*jogo_t).jogador_t.escore += 10;
                qt_inimigos--;
            }

            if (flag_colisao)
            {
                if((*jogo_t).inimigos[i].direcao == 0 ||
                   (*jogo_t).inimigos[i].direcao == 4 ||
                   (*jogo_t).inimigos[i].direcao == 5)
                    (*jogo_t).inimigos[i].direcao = 7;
                else if((*jogo_t).inimigos[i].direcao == 1 ||
                        (*jogo_t).inimigos[i].direcao == 6 ||
                        (*jogo_t).inimigos[i].direcao == 7)
                        (*jogo_t).inimigos[i].direcao = 4;
                else
                    (*jogo_t).inimigos[i].direcao = MIN_DIRECAO + (rand() % (MAX_DIRECAO - MIN_DIRECAO + 1));
            }


        } while(flag_colisao);
    }
    return qt_inimigos;
}
