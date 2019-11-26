#include "gera_tela.h"
/* Função que gera a tela do jogo e define um recorte circular para o mapa continuar imprimindo
quando houver o alcance do final da matriz. */
void gera_tela(JOGO jogo_t, char tela[LINHAS][COLUNAS_TELA], int coluna_atual) {
    int i, j; // Auxiliares para varredura.
    int fim; // Variável que guarda o final do mapa.
    for(i = 0; i < LINHAS; i++)
        for(j = 0, fim = coluna_atual; j < COLUNAS_TELA; j++, fim++) {
            if(fim == COLUNAS)
                fim = 0;
            tela[i][j] = jogo_t.mapa[i][fim];
        }
}
