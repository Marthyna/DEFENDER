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
#include "tiro_usuario.h"
#include "gotoxy.h"
#include "clrscr.h"
#include "movimenta_nave.h"
#include "imprime_escore.h"
#include "kbhit.h"
#include "game_over.h"

int main()
{
    FILE *arq;                      // ponteiro para o arquivo do mapa
    COORDENADA nave_pos;            // posição x,y da nave (será atualizada ao longo do jogo)
    //JOGO jogo_t;                    // struct que guarda as informações do jogo
    JOGADOR jogador_t;
    COORDENADA naves[MAXNAVES];     // array de posições x,y de cada nave no jogo

    char opcao;                     // opção do usuário no menu inicial
    char c = NULL;                   // char que guarda a tecla pressionada pelo usuário
    char mapa[LINHAS][COLUNAS];     // matriz do mapa inteiro
    char tela[LINHAS][COLUNAS_TELA];// matriz do recorte do mapa (que cabe na tela)

    int flag_repetir_menu = 0;      // flag para repetir o menu
    int flag_colisao;               // flag para verificar colisão
    int coluna_atual = 0;           // coluna do mapa a ser impressa na iteração atual
    int inimigos_lidos;             // quantidade de inimigos lidos do arquivo mapa

    arq = fopen(FILE_MAPA, "r");    // abre o arquivo mapa para leitura
    // testa se há problema na abertura do arquivo
    if(!arq)
    {
        printf("Erro ao abrir o arquivo do mapa.");
        return 0;
    }

    do
    {
        opcao = menu_inicial();
        switch(opcao)
        {
        case '1':
            jogador_t.vidas = VIDAS;
            jogador_t.escore = 0;

            inimigos_lidos = le_mapa(arq, mapa, naves);
            jogador_t.posicao_t = naves[0];
            nave_pos = jogador_t.posicao_t;
            imprime_nave(mapa, jogador_t.posicao_t);

            imprime_inimigo(mapa, naves, inimigos_lidos);

            while(jogador_t.vidas > 0)
            {
                if( kbhit( ) ) c = getch( );

                flag_colisao = 0;
                imprime_escore(jogador_t);
                gera_tela(mapa, tela, coluna_atual);
                imprime_tela(tela);
                Sleep(100);
                clrscr();
                coluna_atual++;

                nave_pos = movimenta_nave(nave_pos, c);
                flag_colisao = imprime_nave(mapa, nave_pos);
                if( c == ' ' )
                    tiro_usuario(nave_pos, mapa);

                if(flag_colisao)
                {
                    jogador_t.vidas--;
                    jogador_t.escore = 0;
                    coluna_atual = 0;
                    nave_pos = jogador_t.posicao_t;
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
