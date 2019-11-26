#include "decide_tiro_inimigo.h"
#include "tiro_inimigo.h"
// Fun��o que decide a gera��o do tiro inimigo.
void decide_tiro_inimigo(JOGO *jogo_t, int iteracao, int qt_inimigos) {
    int i;
    if(iteracao % 100 == 0) { // Cad�ncia do tiro
       for(i = 0; i < qt_inimigos; i++) {
            (*jogo_t).inimigos[i].flag_atira = rand() % 2;
            if((*jogo_t).inimigos[i].flag_atira)
                tiro_inimigo((*jogo_t).inimigos[i], (*jogo_t).mapa);
        }
    }
}
