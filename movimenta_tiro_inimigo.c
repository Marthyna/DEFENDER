#include "movimenta_tiro_inimigo.h"
void movimenta_tiro_inimigo(JOGO *jogo_t, int coluna_atual)
{
    int l, cl, i;
    for(i = 0; i < (*jogo_t).qt_inimigos; i++)
    {
        l = (*jogo_t).inimigos[i].posicao_tiro_t.linha;
        cl = (*jogo_t).inimigos[i].posicao_tiro_t.coluna;

        (*jogo_t).mapa[l][cl] = ' ';
        if((*jogo_t).inimigos[i].flag_continua_tiro)
        {
            switch((*jogo_t).inimigos[i].direcao)
            {
            case 0: // norte
            {
                l--;
                break;
            }
            case 1: // sul
            {
                l++;
                break;
            }
            case 2: // leste
            {
                cl++;
                break;
            }
            case 3: // oeste
            {
                cl--;
                break;
            }
            case 4: // nordeste
            {
                l--;
                cl++;
                break;
            }
            case 5: // noroeste
            {
                l--;
                cl--;
                break;
            }
            case 6: // sudeste
            {
                l++;
                cl++;
                break;
            }
            case 7: // sudoeste
            {
                l++;
                cl--;
                break;
            }
            }

            if(l < 0) l++;
            else if(l >= LINHAS) l--;
            if((*jogo_t).mapa[l][cl] == 'C')
            {
                l = 0;
                cl = 0;
                (*jogo_t).inimigos[i].flag_continua_tiro = 0;
            }
            else if(cl <= coluna_atual)
            {
                l = 0;
                cl = 0;
                (*jogo_t).inimigos[i].flag_continua_tiro = 0;
            }
            else if (cl >= COLUNAS_TELA)
            {
                l = 0;
                cl = 0;
                (*jogo_t).inimigos[i].flag_continua_tiro = 0;
            }

            if((*jogo_t).inimigos[i].flag_continua_tiro)
                (*jogo_t).mapa[l][cl] = '.';
            else
                (*jogo_t).mapa[l][cl] = ' ';
        }
    }
}
