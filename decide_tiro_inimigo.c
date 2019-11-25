#include "decide_tiro_inimigo.h"
#include "tiro_inimigo.h"
void decide_tiro_inimigo(JOGO *jogo_t, int inimigos, int iteracao)
{
    int i;
    if(iteracao % 5 == 0)
    {
        for(i = 0; i < inimigos; i++)
        {
            (*jogo_t).inimigos[i].flag_atira = rand() % 2;
            if((*jogo_t).inimigos[i].flag_atira)
                tiro_inimigo((*jogo_t).inimigos[i], (*jogo_t).mapa);
        }

    }
}
