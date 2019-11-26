#include "movimenta_tiro_inimigo.h"
// Função que movimenta o tiro inimigo.
void movimenta_tiro_inimigo(JOGO *jogo_t, int coluna_atual) {
    int linha, coluna, i;
    for(i = 0; i < (*jogo_t).qt_inimigos; i++) {
        linha = (*jogo_t).inimigos[i].posicao_tiro_t.linha;
        coluna = (*jogo_t).inimigos[i].posicao_tiro_t.coluna;
        (*jogo_t).mapa[linha][coluna] = ' ';
        if((*jogo_t).inimigos[i].flag_continua_tiro) {
            switch((*jogo_t).inimigos[i].direcao) {
                case 0: // norte
                    linha--;
                    break;
                case 1: // sul
                    linha++;
                    break;
                case 2: // leste
                    coluna++;
                    break;
                case 3: // oeste
                    coluna--;
                    break;
                case 4: { // nordeste
                    linha--;
                    coluna++;
                    break;
                }
                case 5: { // noroeste
                    linha--;
                    coluna--;
                    break;
                }
                case 6: { // sudeste
                    linha++;
                    coluna++;
                    break;
                }
                case 7: {// sudoeste
                    linha++;
                    coluna--;
                    break;
                }
            }
            if(linha < 0) linha++;
            else if(linha >= LINHAS) linha--;
            if((*jogo_t).mapa[linha][coluna] == 'C') {
                linha = 0;
                coluna = 0;
                (*jogo_t).inimigos[i].flag_continua_tiro = 0;
            } else if(coluna <= coluna_atual) {
                linha = 0;
                coluna = 0;
                (*jogo_t).inimigos[i].flag_continua_tiro = 0;
            } else if (coluna >= COLUNAS_TELA) {
                linha = 0;
                coluna = 0;
                (*jogo_t).inimigos[i].flag_continua_tiro = 0;
            }
            if((*jogo_t).inimigos[i].flag_continua_tiro)
                (*jogo_t).mapa[linha][coluna] = '.';
            else
                (*jogo_t).mapa[linha][coluna] = ' ';
        }
    }
}
