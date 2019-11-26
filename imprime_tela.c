#include "imprime_tela.h"
// Função que imprime a tela do jogo.
void imprime_tela(char tela[LINHAS][COLUNAS_TELA]) {
    int i, j;
    int k; // Variável que permite a impressao do mapa a partir da segunda linha, já que a primeira está reservada para o escore.
    for(i = 0, k = 2; i < LINHAS; i++, k++)
        for(j = 0; j < COLUNAS_TELA; j++)
            putchxy(j, k, tela[i][j]);
}
