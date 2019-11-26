#include "inicia_jogo.h"
void inicia_jogo(JOGO *jogo_t) {
    COORDENADA nave_pos;// Coordenadas da nave.
    char tela[LINHAS][COLUNAS_TELA];// Matriz da tela do jogo.
    char tecla = '0'; // Inicializa a vari�vel com um valor in�til para evitar gera��o rand�mica.
    int flag_colisao; // Flag que verifica as colis�es dentro do jogo.
    int coluna_atual = 0; // Vari�vel que atualiza a coluna da nave a cada ciclo para estabilizar o movimento perante o decorrer do mapa.
    int velocidade = 0;// Vari�vel que representa a velocidade do jogo.
    int i;// Vari�vel auxiliar para varredura do mapa.
    int fase = 1; // Variavel que indica a fase corrente do jogo.
    int cadencia = 1; // // Vari�vel que controla a cad�ncia dos tiros do inimigo.
    int qt_inimigos; // Vari�vel que indica quantos inimigos existem no momento.
    nave_pos = (*jogo_t).jogador_t.posicao_t;
    imprime_nave((*jogo_t).mapa, nave_pos); // Chama a fun��o que imprime a nave dentro do mapa.
    imprime_inimigo(jogo_t, (*jogo_t).qt_inimigos); // Chama a fun��o que imprime os inimigos dentro do mapa.
    qt_inimigos = (*jogo_t).qt_inimigos;
    while((*jogo_t).jogador_t.vidas > 0) {
        tecla = '0';
        flag_colisao = 0;
        imprime_escore((*jogo_t).jogador_t);// Chama a fun��o que imprime o escore.
        gera_tela((*jogo_t), tela, coluna_atual); // Chama a fun��o que gera a tela.
        imprime_tela(tela); // Chama a fun��o que imprime a tela.
        Sleep((*jogo_t).delay);
        clrscr();
        coluna_atual++; // Atualiza a coluna da nave fixar sua posi��o com o movimento da tela
        if(kbhit( )) {
            tecla = getch(); // Recebe a tecla pressionada pelo Jogador.
        }
        if(tecla == 'g')
            salva_jogo((*jogo_t)); // Chama a fun��o que salva o jogo.
        if(tecla == ' ') {
            gera_tiro(nave_pos, (*jogo_t).mapa); // Chama a fun��o que gera o tiro do inimigo.
        }
        if (tecla == 'd') {
            velocidade++;
            for(i = 0; i < velocidade; i++)
                nave_pos = movimenta_nave(nave_pos, tecla);
        } else
            nave_pos = movimenta_nave(nave_pos, tecla); // Chama a fun��o que movimenta a nave.
        decide_tiro_inimigo(jogo_t, cadencia, qt_inimigos); // Chama a fun��o que gerencia a cad�ncia dos tiros inimigos.
        movimenta_tiro_inimigo(jogo_t, coluna_atual); // Chama a fun��o que movimenta o tiro inimigo.
        qt_inimigos = movimenta_inimigos(jogo_t, qt_inimigos); // Chama a fun��o que movimenta os inimigos de acordo com a quantidade deles.
        (*jogo_t).qt_inimigos = qt_inimigos; // Atualiza o n�mero de inimigos dentro do jogo.
        imprime_inimigo(jogo_t, qt_inimigos); // Chama a fun��o que imprime inimigos.
        movimenta_tiro(jogo_t); // Chama a fun��o que movimenta o tiro.
        flag_colisao = imprime_nave((*jogo_t).mapa, nave_pos); // Verifica��o da flag de Colis�o da nave do jogador.
        if(flag_colisao) {
            (*jogo_t).jogador_t.vidas--; // Diminui uma vida do jogador.
            (*jogo_t).jogador_t.escore = 0; // Reseta o escore do jogador.
            coluna_atual = 0; // Coloca a nave na posi��o inicial do mapa.
            nave_pos = (*jogo_t).jogador_t.posicao_t; // Iguala a posi��o da nave do jogador � sua nova posi��o ap�s a colis�o.
            velocidade = 0; // Reseta a velocidade do jogo
        }
        if((*jogo_t).qt_inimigos == 0) {
            fase++;
            if(fase == 2)
                //arq_abre = fopen("mapa.txt", "r");
            if(fase == 3)
                game_over(); // Chama a fun��o Game Over.
            coluna_atual = 0;
            nave_pos = (*jogo_t).jogador_t.posicao_t;
            velocidade = 0;
        }
        cadencia++;// aumenta a cad�ncia dos tiros inimigos.
    }
    game_over();// Chama a fun��o game over.
}
