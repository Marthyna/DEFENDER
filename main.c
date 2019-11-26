/*
    Trabalho final de Introdução a Algoritmos e Programação
    DEFENDER - Versão adaptada
    Por Henrique Bernardes e Marthyna Weber
*/
/*Bibliotecas utilizadas*/
#include "main.h"
#include "menu_inicial.h"
#include "le_mapa.h"
#include "gera_tela.h"
#include "imprime_tela.h"
#include "imprime_nave.h"
#include "imprime_inimigo.h"
#include "gotoxy.h"
#include "clrscr.h"
#include "movimenta_nave.h"
#include "imprime_escore.h"
#include "kbhit.h"
#include "game_over.h"
#include "pede_nome.h"
#include "salva_jogo.h"
#include "movimenta_inimigos.h"
#include "tiro_inimigo.h"
#include "gera_tiro.h"
#include "movimenta_tiro.h"
#include "movimenta_tiro_inimigo.h"
#include "decide_tiro_inimigo.h"

int main() {
    FILE *arq_abre;                 // ponteiro para o arquivo do mapa
    COORDENADA nave_pos;            // posição x,y da nave (será atualizada ao longo do jogo)
    JOGO jogo_t;                    // struct que guarda as informações do jogo

    char opcao;                     // opção do usuário no menu inicial
    char c = '0';                         // char que guarda a tecla teclada pelo usuário
    char tela[LINHAS][COLUNAS_TELA];// matriz do recorte do mapa (que cabe na tela)

    int flag_repetir_menu = 0;      // flag para repetir o menu
    int flag_colisao;               // flag para verificar colisão
    int velocidade = 0;
    int i;
    int iteracao = 1;
    int fase = 0;

    arq_abre = fopen(FILE_MAPA, "r");    // abre o arquivo mapa para leitura

    // testa se há problema na abertura do arquivo
    if(!arq_abre) {
        printf("Erro ao abrir o arquivo do mapa.");
        return 0;
    }

    do {
        opcao = menu_inicial();
        switch(opcao) {
        case '1':
            jogo_t.jogador_t.vidas = VIDAS;
            jogo_t.jogador_t.escore = 0;
            jogo_t.delay = DELAY_INICIAL;
            jogo_t.coluna_atual = 0;

            le_mapa(arq_abre, &jogo_t);
            nave_pos = jogo_t.jogador_t.posicao_t;
            imprime_nave(jogo_t.mapa, nave_pos);

            imprime_inimigo(&jogo_t);

            while(jogo_t.jogador_t.vidas > 0) {
                c = '0';
                flag_colisao = 0;

                imprime_escore(jogo_t.jogador_t);
                gera_tela(jogo_t, tela, jogo_t.coluna_atual);
                imprime_tela(tela);
                Sleep(jogo_t.delay);
                clrscr();
                jogo_t.coluna_atual++;

                if(kbhit( )) {
                    c = getch( );
                }
                if(c == 'g') {
                    pede_nome(&jogo_t);
                    salva_jogo(jogo_t);
                }
                if(c == ' ') {
                    gera_tiro(nave_pos, jogo_t.mapa);
                }
                if (c == 'd') {
                    velocidade++;
                    for(i = 0; i < velocidade; i++) {
                        nave_pos = movimenta_nave(nave_pos, c);
                    }
                } else {
                    nave_pos = movimenta_nave(nave_pos, c);
                }

                decide_tiro_inimigo(&jogo_t, iteracao);
                movimenta_tiro_inimigo(&jogo_t);
                movimenta_inimigos(&jogo_t);
                imprime_inimigo(&jogo_t);
                movimenta_tiro(&jogo_t);
                flag_colisao = imprime_nave(jogo_t.mapa, nave_pos);

                if(flag_colisao) {
                    jogo_t.jogador_t.vidas--;
                    jogo_t.jogador_t.escore = 0;
                    jogo_t.coluna_atual = 0;
                    nave_pos = jogo_t.jogador_t.posicao_t;
                    velocidade = 0;
                }

                if(jogo_t.qt_inimigos == 0)
                {
                    fase++;

                }

                iteracao++;
            }
            game_over();
            break;
        case '2':

            break;
        case '3':

            break;
        default:
            printf("Opção inválida.");
            flag_repetir_menu = 1;
            break;
        }
    }
    while (flag_repetir_menu);

    return 0;
}
