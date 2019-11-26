#include "inicia_jogo.h"
void inicia_jogo(JOGO *jogo_t) {
    COORDENADA nave_pos;
    char tela[LINHAS][COLUNAS_TELA];
    char c = '0';
    int flag_colisao;
    int coluna_atual = 0;
    int velocidade = 0;
    int i;
    int fase = 1;
    int iteracao = 1;
    int qt_inimigos;
    nave_pos = (*jogo_t).jogador_t.posicao_t;
    imprime_nave((*jogo_t).mapa, nave_pos);
    imprime_inimigo(jogo_t, (*jogo_t).qt_inimigos);
    qt_inimigos = (*jogo_t).qt_inimigos;
    while((*jogo_t).jogador_t.vidas > 0) {
        c = '0';
        flag_colisao = 0;
        imprime_escore((*jogo_t).jogador_t);
        gera_tela((*jogo_t), tela, coluna_atual);
        imprime_tela(tela);
        Sleep((*jogo_t).delay);
        clrscr();
        coluna_atual++;
        if(kbhit( )) {
            c = getch();
        }
        if(c == 'g')
            salva_jogo((*jogo_t));
        if(c == ' ') {
            gera_tiro(nave_pos, (*jogo_t).mapa);
        }
        if (c == 'd') {
            velocidade++;
            for(i = 0; i < velocidade; i++)
                nave_pos = movimenta_nave(nave_pos, c);
        } else
            nave_pos = movimenta_nave(nave_pos, c);
        decide_tiro_inimigo(jogo_t, iteracao, qt_inimigos);
        movimenta_tiro_inimigo(jogo_t, coluna_atual);
        qt_inimigos = movimenta_inimigos(jogo_t, qt_inimigos);
        (*jogo_t).qt_inimigos = qt_inimigos;
        imprime_inimigo(jogo_t, qt_inimigos);
        movimenta_tiro(jogo_t);
        flag_colisao = imprime_nave((*jogo_t).mapa, nave_pos);
        if(flag_colisao) {
            (*jogo_t).jogador_t.vidas--;
            (*jogo_t).jogador_t.escore = 0;
            coluna_atual = 0;
            nave_pos = (*jogo_t).jogador_t.posicao_t;
            velocidade = 0;
        }
        if((*jogo_t).qt_inimigos == 0) {
            fase++;
            if(fase == 2)
                //arq_abre = fopen("mapa.txt", "r");
            if(fase == 3)
                game_over();
            coluna_atual = 0;
            nave_pos = (*jogo_t).jogador_t.posicao_t;
            velocidade = 0;
        }
        iteracao++;
    }
    game_over();
}
