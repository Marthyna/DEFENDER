#include "imprime_escore.h"
/*Função que imprime o escore do Jogador na Primeira linha da Tela. */
void imprime_escore(JOGADOR jogador_t) {
    delline();
    gotoxy(0,0);
    printf("PONTOS: %d      VIDAS: %d\n", jogador_t.escore, jogador_t.vidas);
}
