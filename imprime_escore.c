#include "imprime_escore.h"

void imprime_escore(JOGO jogo_t)
{
    delline();
    gotoxy(0,0);
    printf("PONTOS: %d      VIDAS: %d\n", jogo_t.escore, jogo_t.vidas);
}
