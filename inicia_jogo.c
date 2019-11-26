#include "inicia_jogo.h"
void inicia_jogo(JOGO *jogo_t) {
    COORDENADA nave_pos;// Coordenadas da nave.
    char tela[LINHAS][COLUNAS_TELA];// Matriz da tela do jogo.
    char tecla = '0'; // Inicializa a variável com um valor inútil para evitar geração randômica.
    int flag_colisao; // Flag que verifica as colisões dentro do jogo.
    int coluna_atual = 0; // Variável que atualiza a coluna da nave a cada ciclo para estabilizar o movimento perante o decorrer do mapa.
    int velocidade = 0;// Variável que representa a velocidade do jogo.
    int i;// Variável auxiliar para varredura do mapa.
    int fase = 1; // Variavel que indica a fase corrente do jogo.
    int cadencia = 1; // // Variável que controla a cadência dos tiros do inimigo.
    int qt_inimigos; // Variável que indica quantos inimigos existem no momento.
    nave_pos = (*jogo_t).jogador_t.posicao_t;
    imprime_nave((*jogo_t).mapa, nave_pos); // Chama a função que imprime a nave dentro do mapa.
    imprime_inimigo(jogo_t, (*jogo_t).qt_inimigos); // Chama a função que imprime os inimigos dentro do mapa.
    qt_inimigos = (*jogo_t).qt_inimigos;
    while((*jogo_t).jogador_t.vidas > 0) {
        tecla = '0';
        flag_colisao = 0;
        imprime_escore((*jogo_t).jogador_t);// Chama a função que imprime o escore.
        gera_tela((*jogo_t), tela, coluna_atual); // Chama a função que gera a tela.
        imprime_tela(tela); // Chama a função que imprime a tela.
        Sleep((*jogo_t).delay);
        clrscr();
        coluna_atual++; // Atualiza a coluna da nave fixar sua posição com o movimento da tela
        if(kbhit( )) {
            tecla = getch(); // Recebe a tecla pressionada pelo Jogador.
        }
        if(tecla == 'g')
            salva_jogo((*jogo_t)); // Chama a função que salva o jogo.
        if(tecla == ' ') {
            gera_tiro(nave_pos, (*jogo_t).mapa); // Chama a função que gera o tiro do inimigo.
        }
        if (tecla == 'd') {
            velocidade++;
            for(i = 0; i < velocidade; i++)
                nave_pos = movimenta_nave(nave_pos, tecla);
        } else
            nave_pos = movimenta_nave(nave_pos, tecla); // Chama a função que movimenta a nave.
        decide_tiro_inimigo(jogo_t, cadencia, qt_inimigos); // Chama a função que gerencia a cadência dos tiros inimigos.
        movimenta_tiro_inimigo(jogo_t, coluna_atual); // Chama a função que movimenta o tiro inimigo.
        qt_inimigos = movimenta_inimigos(jogo_t, qt_inimigos); // Chama a função que movimenta os inimigos de acordo com a quantidade deles.
        (*jogo_t).qt_inimigos = qt_inimigos; // Atualiza o número de inimigos dentro do jogo.
        imprime_inimigo(jogo_t, qt_inimigos); // Chama a função que imprime inimigos.
        movimenta_tiro(jogo_t); // Chama a função que movimenta o tiro.
        flag_colisao = imprime_nave((*jogo_t).mapa, nave_pos); // Verificação da flag de Colisão da nave do jogador.
        if(flag_colisao) {
            (*jogo_t).jogador_t.vidas--; // Diminui uma vida do jogador.
            (*jogo_t).jogador_t.escore = 0; // Reseta o escore do jogador.
            coluna_atual = 0; // Coloca a nave na posição inicial do mapa.
            nave_pos = (*jogo_t).jogador_t.posicao_t; // Iguala a posição da nave do jogador à sua nova posição após a colisão.
            velocidade = 0; // Reseta a velocidade do jogo
        }
        if((*jogo_t).qt_inimigos == 0) {
            fase++;
            if(fase == 2)
                //arq_abre = fopen("mapa.txt", "r");
            if(fase == 3)
                game_over(); // Chama a função Game Over.
            coluna_atual = 0;
            nave_pos = (*jogo_t).jogador_t.posicao_t;
            velocidade = 0;
        }
        cadencia++;// aumenta a cadência dos tiros inimigos.
    }
    game_over();// Chama a função game over.
}
