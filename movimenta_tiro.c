#include "movimenta_tiro.h"
// Fun��o que movimenta o tiro do Jogador.
void movimenta_tiro(JOGO *jogo_t) {
    int i, j; // i = linhas, j = colunas.
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            if(j + 1 == COLUNAS_TELA)
                (*jogo_t).mapa[i][j] = ' ';
            if((*jogo_t).mapa[i][j] == '-') {
                if((*jogo_t).mapa[i][j+1] != 'C' &&
                    (*jogo_t).mapa[i][j+1] != 'X') {// checagem de colis�o.
                    (*jogo_t).mapa[i][j] = ' ';
                    (*jogo_t).mapa[i][j + 1] = ' ';
                    (*jogo_t).mapa[i][j + 3] = '-';
                    (*jogo_t).mapa[i][j + 4] = '-';
                    j = j + 4;
                }
            }
        }
    }
}
