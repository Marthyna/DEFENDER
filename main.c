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

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    FILE *arq;

    JOGO jogo_t;

    char opcao;
    char mapa[LINHAS][COLUNAS];
    char tela[LINHAS][COLUNAS_TELA];

    COORDENADA naves[MAXNAVES];

    int flag_repetir_menu = 0;
    int coluna_atual = 0;
    int inimigos_lidos;

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
            jogo_t.vidas = VIDAS; // pra controlar o while

            COORDENADA nave_pos;

            inimigos_lidos = le_mapa(arq, mapa, naves);
            nave_pos = naves[0]; // pega a posicao inicial da nave de dentro do arquivo texto
            imprime_nave(mapa, nave_pos); // imprime na matriz mapa os @ ao redor dessa posicao inicial
            // percorre o array da posicoes lidas no le_mapa
            imprime_inimigo(mapa, naves, inimigos_lidos);

            while(jogo_t.vidas > 0)
            {
                gera_tela(mapa, tela, coluna_atual); // gera o recorte da tela através do mapa (coluna_atual começa em 0)
                imprime_tela(tela); // imprime o recorte
                Sleep(100);
                clrscr();
                coluna_atual++;

                nave_pos = movimenta_nave(nave_pos); // atualiza a posição da nave
                imprime_nave(mapa, nave_pos); // imprime de novo no mapa
            }
            break;
        case '2':
            le_mapa(arq, mapa, naves);
            for(int t = 0; t < MAXNAVES; t++)
                printf("%d %d\n", naves[t].linha, naves[t].coluna);
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
