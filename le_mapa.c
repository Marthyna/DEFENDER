#include "le_mapa.h"
#include "tiro_inimigo.h"
int le_mapa(FILE *arq, JOGO *jogo_t) {
    int i, j;
    int a = 0;
    char c;
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            c = fgetc(arq);
            (*jogo_t).mapa[i][j] = c;
            if(c == '@') {
                (*jogo_t).jogador_t.posicao_t.linha = i;
                (*jogo_t).jogador_t.posicao_t.coluna = j;
            } else if(c == 'X') {
                (*jogo_t).inimigos[a].posicao_t.linha = i;
                (*jogo_t).inimigos[a].posicao_t.coluna = j;
                srand(time(NULL));
                (*jogo_t).inimigos[a].direcao = rand() % 5;
                (*jogo_t).inimigos[a].flag_atira = rand() % 2;
                (*jogo_t).inimigos[a].flag_continua_tiro = 1;
                if((*jogo_t).inimigos[a].flag_atira)
                    tiro_inimigo((*jogo_t).inimigos[a], (*jogo_t).mapa);
                a++;
            }
        }
    }
    return a;
}
