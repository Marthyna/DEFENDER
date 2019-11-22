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
#include "tiro_usuario.h"

int main() {
    FILE *arq_abre;                      // ponteiro para o arquivo do mapa
    COORDENADA nave_pos;            // posição x,y da nave (será atualizada ao longo do jogo)
    JOGO jogo_t;                    // struct que guarda as informações do jogo
    COORDENADA naves[MAXNAVES];     // array de posições x,y de cada nave no jogo

    char opcao;                     // opção do usuário no menu inicial
    char c = NULL;                   // char que guarda a tecla teclada pelo usuário
    char mapa[LINHAS][COLUNAS];     // matriz do mapa inteiro
    char tela[LINHAS][COLUNAS_TELA];// matriz do recorte do mapa (que cabe na tela)

    int flag_repetir_menu = 0;      // flag para repetir o menu
    int flag_colisao;               // flag para verificar colisão
    int coluna_atual = 0;           // coluna do mapa a ser impressa na iteração atual
    int inimigos_lidos;             // quantidade de inimigos lidos do arquivo mapa

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

            inimigos_lidos = le_mapa(arq_abre, mapa, naves);
            jogo_t.jogador_t.posicao_t = naves[0];
            nave_pos = jogo_t.jogador_t.posicao_t;
            imprime_nave(mapa, jogo_t.jogador_t.posicao_t);

            imprime_inimigo(mapa, naves, inimigos_lidos);

            while(jogo_t.jogador_t.vidas > 0) {
                c = NULL;
                flag_colisao = 0;

                imprime_escore(jogo_t.jogador_t);
                gera_tela(mapa, tela, coluna_atual);
                imprime_tela(tela);
                Sleep(100);
                clrscr();
                coluna_atual++;

                if( kbhit( ) ) {
                    c = getch( );
                }
                if(c == ' '){
                    tiro_usuario(nave_pos, mapa);
                }
                if(c == 'g') {
                    pede_nome(jogo_t);
                    salva_jogo(jogo_t);
                }
                nave_pos = movimenta_nave(nave_pos, c);
                flag_colisao = imprime_nave(mapa, nave_pos);

                if(flag_colisao) {
                    jogo_t.jogador_t.vidas--;
                    jogo_t.jogador_t.escore = 0;
                    coluna_atual = 0;
                    nave_pos = jogo_t.jogador_t.posicao_t;
                }
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
