#include "le_mapa.h"
#include "tiro_inimigo.h"
/*Fun��o que varre o mapa inteiro e procura os s�mbolos correspondentes
aos inimigos e ao jogador. */
int le_mapa(FILE *arq, JOGO *jogo_t) {
    int i, j;//Vari�veis auxiliares.
    int inimigos = 0;// Vari�vel correspondente ao n�mero do inimigo.
    char c;// Vari�vel auxiliar para achar os s�mbolos.
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            c = fgetc(arq);
            (*jogo_t).mapa[i][j] = c;
            if(c == '@') {
                (*jogo_t).jogador_t.posicao_t.linha = i;
                (*jogo_t).jogador_t.posicao_t.coluna = j;
            } else if(c == 'X') {
                (*jogo_t).inimigos[inimigos].posicao_t.linha = i;
                (*jogo_t).inimigos[inimigos].posicao_t.coluna = j;
                srand(time(NULL));
                (*jogo_t).inimigos[inimigos].direcao = rand() % 5;
                (*jogo_t).inimigos[inimigos].flag_atira = rand() % 2;
                (*jogo_t).inimigos[inimigos].flag_continua_tiro = 1;
                if((*jogo_t).inimigos[inimigos].flag_atira) // Verifica a condi��o da flag que sinaliiza o tiro inimigo.
                    tiro_inimigo((*jogo_t).inimigos[inimigos], (*jogo_t).mapa); // Chama a fun��o que controla a gera��o do tiro inimigo.
                inimigos++;
            }
        }
    }
    return inimigos;
}
