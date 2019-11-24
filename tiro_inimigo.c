#include "tiro_inimigo.h"
void tiro_inimigo(INIMIGO inimigo, char mapa[LINHAS][COLUNAS])
{
    int l, cl;
    COORDENADA posicao_tiro_t;
    if(mapa[inimigo.posicao_t.linha][(inimigo.posicao_t.coluna)] == 'X') //gera o tiro
    {
        switch(inimigo.direcao)
        {
        case 1: // norte
        {
            l = inimigo.posicao_t.linha - 2;
            cl = inimigo.posicao_t.coluna;
            break;
        }
        case 2: // sul
        {
            l = inimigo.posicao_t.linha + 1;
            cl = inimigo.posicao_t.coluna;
            break;
        }
        case 3: // leste
        {
            l = inimigo.posicao_t.linha;
            cl = inimigo.posicao_t.coluna + 2;
            break;
        }
        case 4: // oeste
        {
            l = inimigo.posicao_t.linha;
            cl = inimigo.posicao_t.coluna - 1;
            break;
        }
        case 5: // nordeste
        {
            l = inimigo.posicao_t.linha - 2;
            cl = inimigo.posicao_t.coluna + 2;
            break;
        }
        case 6: // noroeste
        {
            l = inimigo.posicao_t.linha - 2;
            cl = inimigo.posicao_t.coluna - 1;
            break;
        }
        case 7: // sudeste
        {
            l = inimigo.posicao_t.linha + 1;
            cl = inimigo.posicao_t.coluna + 2;
            break;
        }
        case 8: // sudoeste
        {
            l = inimigo.posicao_t.linha + 1;
            cl = inimigo.posicao_t.coluna - 1;
            break;
        }
        }
        mapa[l][cl] = '.';
        posicao_tiro_t.linha = l;
        posicao_tiro_t.coluna = cl;
        inimigo.posicao_tiro_t = posicao_tiro_t;

    }
}
