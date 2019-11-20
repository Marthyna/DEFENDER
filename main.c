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

int main()
{
    FILE *arq;                  // ponteiro para o arquivo do mapa
    COORDENADA nave_pos_inicial;// posição x,y inicial da nave
    COORDENADA nave_pos;        // posição x,y da nave
    JOGO jogo_t;                //

    char opcao;
    char c = ' ';
    char mapa[LINHAS][COLUNAS];
    char tela[LINHAS][COLUNAS_TELA];

    COORDENADA naves[MAXNAVES];

    int flag_repetir_menu = 0;
    int coluna_atual = 0;
    int inimigos_lidos;
    int flag_colisao;

    arq = fopen(FILE_MAPA, "r");
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
            jogo_t.vidas = VIDAS;
            jogo_t.escore = 0;

            inimigos_lidos = le_mapa(arq, mapa, naves);
            nave_pos_inicial = naves[0];
            nave_pos = nave_pos_inicial;
            imprime_nave(mapa, nave_pos_inicial);

            imprime_inimigo(mapa, naves, inimigos_lidos);

            while(jogo_t.vidas > 0)
            {
                if( kbhit( ) ) c = getch( );

                flag_colisao = 0;
                imprime_escore(jogo_t);
                gera_tela(mapa, tela, coluna_atual);
                imprime_tela(tela);
                Sleep(100);
                clrscr();
                coluna_atual++;

                nave_pos = movimenta_nave(nave_pos, c);
                flag_colisao = imprime_nave(mapa, nave_pos);

                if(flag_colisao)
                {
                    jogo_t.vidas--;
                    jogo_t.escore = 0;
                    coluna_atual = 0;
                    nave_pos = nave_pos_inicial;
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
