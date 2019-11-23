#include "movimenta_inimigos.h"
void movimenta_inimigos (INIMIGO inimigos[MAXINIMIGOS], char mapa[LINHAS][COLUNAS], int qt_inimigos)
{
    int i, a, b;
    int flag_colisao;

    srand(0);

    for(i = 0; i < qt_inimigos; i++)
    {
        a = inimigos[i].posicao_t.linha;
        b = inimigos[i].posicao_t.coluna;

        mapa[a][b] = ' ';
        mapa[a][b+1] = ' ';
        mapa[a-1][b] = ' ';
        mapa[a-1][b+1] = ' ';

        while(flag_colisao)
        {
            flag_colisao = 0;
            switch(inimigos[i].direcao)
            {
            case 1: // cima
            {
                inimigos[i].posicao_t.linha--;
                inimigos[i].posicao_t.coluna++;
                break;
            }
            case 2: // baixo
            {
                inimigos[i].posicao_t.linha++;
                inimigos[i].posicao_t.coluna++;
                break;
            }
            case 3: // direita
            {
                inimigos[i].posicao_t.coluna+=2;
                break;
            }
            case 4: // esquerda
            {
                inimigos[i].posicao_t.coluna--;
                break;
            }
            case 5: // cima + direita
            {
                inimigos[i].posicao_t.linha--;
                inimigos[i].posicao_t.coluna+=2;
                break;
            }
            case 6: // cima + esquerda
            {
                inimigos[i].posicao_t.linha--;
                inimigos[i].posicao_t.coluna--;
                break;
            }
            case 7: // baixo + direita
            {
                inimigos[i].posicao_t.linha++;
                inimigos[i].posicao_t.coluna+=2;
                break;
            }
            case 8: // baixo + esquerda
            {
                inimigos[i].posicao_t.linha++;
                inimigos[i].posicao_t.coluna--;
                break;
            }
            }

            a = inimigos[i].posicao_t.linha;
            b = inimigos[i].posicao_t.coluna;

            if(b < 0)
                inimigos[i].posicao_t.coluna += COLUNAS;
            else if(mapa[a][b] == 'C' ||
                    mapa[a][b+1] == 'C' ||
                    mapa[a-1][b] == 'C' ||
                    mapa[a-1][b+1] == 'C')
                flag_colisao = 1;
            else if(mapa[a][b] == 'X' ||
                    mapa[a][b+1] == 'X' ||
                    mapa[a-1][b] == 'X' ||
                    mapa[a-1][b+1] == 'X')
                flag_colisao = 1;

            if (flag_colisao)
            {
                if(inimigos[i].direcao == 1 ||
                   inimigos[i].direcao == 5 ||
                   inimigos[i].direcao == 6)
                    inimigos[i].direcao = 8;
                else if(inimigos[i].direcao == 2 ||
                        inimigos[i].direcao == 7 ||
                        inimigos[i].direcao == 8)
                        inimigos[i].direcao = 6;
                else
                    inimigos[i].direcao = MIN_DIRECAO + (rand() % (MAX_DIRECAO - MIN_DIRECAO + 1));
            }
        }
    }
}
