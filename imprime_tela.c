#include "imprime_tela.h"
// Fun��o que imprime a tela do jogo.
void imprime_tela(char tela[LINHAS][COLUNAS_TELA]) {
    int i, j;
    int k; // Vari�vel que permite a impressao do mapa a partir da segunda linha, j� que a primeira est� reservada para o escore.
    for(i = 0, k = 2; i < LINHAS; i++, k++)
        for(j = 0; j < COLUNAS_TELA; j++)
            putchxy(j, k, tela[i][j]);
}
