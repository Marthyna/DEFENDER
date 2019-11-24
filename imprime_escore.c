#include "imprime_escore.h"

void imprime_escore(JOGADOR jogador_t)
{
    delline();
    gotoxy(0,0);
    printf("PONTOS: %d      VIDAS: %d\n", jogador_t.escore, jogador_t.vidas);
}
