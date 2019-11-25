#include "tiro_inimigo.h"
void tiro_inimigo(INIMIGO inimigo, char mapa[LINHAS][COLUNAS])
{
    int linha, coluna;
    int flag_atira = inimigo.flag_atira;
    COORDENADA posicao_tiro_t;
    if(mapa[inimigo.posicao_t.linha][(inimigo.posicao_t.coluna)] == 'X' && flag_atira == 1) //gera o tiro
    {
        linha = inimigo.posicao_tiro_t.linha;
        coluna = inimigo.posicao_tiro_t.coluna;

        switch(inimigo.direcao)
        {
        case 1: // norte
        {
            linha = inimigo.posicao_t.linha - 2;
            coluna = inimigo.posicao_t.coluna;
            break;
        }
        case 2: // sul
        {
            linha = inimigo.posicao_t.linha + 1;
            coluna = inimigo.posicao_t.coluna;
            break;
        }
        case 3: // leste
        {
            linha = inimigo.posicao_t.linha;
            coluna = inimigo.posicao_t.coluna + 2;
            break;
        }
        case 4: // oeste
        {
            linha = inimigo.posicao_t.linha;
            coluna = inimigo.posicao_t.coluna - 1;
            break;
        }
        case 5: // nordeste
        {
            linha = inimigo.posicao_t.linha - 2;
            coluna = inimigo.posicao_t.coluna + 2;
            break;
        }
        case 6: // noroeste
        {
            linha = inimigo.posicao_t.linha - 2;
            coluna = inimigo.posicao_t.coluna - 1;
            break;
        }
        case 7: // sudeste
        {
            linha = inimigo.posicao_t.linha + 1;
            coluna = inimigo.posicao_t.coluna + 2;
            break;
        }
        case 8: // sudoeste
        {
            linha = inimigo.posicao_t.linha + 1;
            coluna = inimigo.posicao_t.coluna - 1;
            break;
        }
        }
        mapa[linha][coluna] = '.';
        posicao_tiro_t.linha = linha;
        posicao_tiro_t.coluna = coluna;
        inimigo.posicao_tiro_t = posicao_tiro_t;
    }
}
