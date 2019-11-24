#include "movimenta_tiro_inimigo.h"
void movimenta_tiro_inimigo(INIMIGO inimigos[MAXINIMIGOS], char mapa[LINHAS][COLUNAS], int inimigos_lidos)
{
    int l, cl, i;
    for(i = 0; i < inimigos_lidos; i++)
    {
        l = inimigos[i].posicao_tiro_t.linha;
        cl = inimigos[i].posicao_tiro_t.coluna;

        mapa[l][cl] = ' ';
        switch(inimigos[i].direcao)
        {
        case 1: // norte
        {
            l--;
            break;
        }
        case 2: // sul
        {
            l++;
            break;
        }
        case 3: // leste
        {
            cl++;
            break;
        }
        case 4: // oeste
        {
            cl--;
            break;
        }
        case 5: // nordeste
        {
            l--;
            cl++;
            break;
        }
        case 6: // noroeste
        {
            l--;
            cl--;
            break;
        }
        case 7: // sudeste
        {
            l++;
            cl++;
            break;
        }
        case 8: // sudoeste
        {
            l++;
            cl--;
            break;
        }
        }
        mapa[l][cl] = '.';
    }
}
