#include "movimenta_inimigos.h"
void movimenta_inimigos (INIMIGO inimigos[MAXINIMIGOS], char mapa[LINHAS][COLUNAS], int qt_inimigos)
{
    int i, linha, coluna; // i = aux, a = linhas, b = colunas
    int flag_colisao;

    for(i = 0; i < qt_inimigos; i++)
    {
        linha = inimigos[i].posicao_t.linha;
        coluna = inimigos[i].posicao_t.coluna;

        mapa[linha][coluna] = ' ';
        mapa[linha][coluna+1] = ' ';
        mapa[linha-1][coluna] = ' ';
        mapa[linha-1][coluna+1] = ' ';

        //usando a direção do inimigo, calcular se o movimento é uma colisão ou não
        //se não, realiza o movimento e passa pro próximo inimigo
        //se sim,
        //se direção for 0, ele se move na direção contraria
        do
        {
            flag_colisao = 0;
            switch(inimigos[i].direcao)
            {
            case 0: // cima
            {
                inimigos[i].posicao_t.linha--;
                inimigos[i].posicao_t.coluna++;
                break;
            }
            case 1: // baixo
            {
                inimigos[i].posicao_t.linha++;
                inimigos[i].posicao_t.coluna++;
                break;
            }
            //case 2: // direita
            //{
            //    inimigos[i].posicao_t.coluna+=2;
            //    break;
            //}
            case 2: // esquerda
            {
                inimigos[i].posicao_t.coluna--;
                break;
            }
            //case 4: // cima + direita
            //{
            //    inimigos[i].posicao_t.linha--;
            //    inimigos[i].posicao_t.coluna+=2;
            //    break;
            //}
            case 3: // cima + esquerda
            {
                inimigos[i].posicao_t.linha--;
                inimigos[i].posicao_t.coluna--;
                break;
            }
            //case 6: // baixo + direita
            //{
            //    inimigos[i].posicao_t.linha++;
            //    inimigos[i].posicao_t.coluna+=2;
            //    break;
            //}
            case 4: // baixo + esquerda
            {
                inimigos[i].posicao_t.linha++;
                inimigos[i].posicao_t.coluna--;
                break;
            }
            }

            linha = inimigos[i].posicao_t.linha;
            coluna = inimigos[i].posicao_t.coluna;

            if(coluna < 0)
                inimigos[i].posicao_t.coluna += COLUNAS;
            else if(coluna > COLUNAS)
                inimigos[i].posicao_t.coluna -= COLUNAS;
            else if(mapa[linha][coluna] == 'C' ||
                    mapa[linha][coluna+1] == 'C' ||
                    mapa[linha-1][coluna] == 'C' ||
                    mapa[linha-1][coluna+1] == 'C')
                flag_colisao = 1;
            else if(mapa[linha][coluna] == 'X' ||
                    mapa[linha][coluna+1] == 'X' ||
                    mapa[linha-1][coluna] == 'X' ||
                    mapa[linha-1][coluna+1] == 'X')
                flag_colisao = 1;
            else if(mapa[linha][coluna] == '-' ||
                    mapa[linha][coluna+1] == '-' ||
                    mapa[linha-1][coluna] == '-' ||
                    mapa[linha-1][coluna+1] == '-')
            {
                if(i + 1 == qt_inimigos)
                    inimigos[i] = inimigos[0];
                else
                    inimigos[i] = inimigos[i+1];
            }


            if (flag_colisao)
            {
                srand(time(NULL));
                inimigos[i].direcao = rand () % 5;
            }
        } while(flag_colisao);
    }
}
