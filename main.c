#include "main.h"
#include "menu_inicial.h"
#include "le_mapa.h"
#include "gera_tela.h"
#include "imprime_tela.h"
#include "imprime_nave.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    FILE *arq;

    JOGO jogo_t;

    char opcao;
    char mapa[LINHAS][COLUNAS];
    char tela[LINHAS][COLUNAS_TELA];

    int flag_repetir_menu = 0;
    int coluna_atual = 0;

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
                jogo_t.vidas = 3;
                COORDENADA nave_pos_inicial;
                nave_pos_inicial = le_mapa(arq, mapa);
                imprime_nave(mapa, nave_pos_inicial);
                while(jogo_t.vidas > 0)
                {
                    gotoxy(1, 0);
                    gera_tela(mapa, tela, coluna_atual);
                    imprime_tela(tela);
                    clrscr();
                    coluna_atual++;
                }
                break;
            case '2':
                printf("Você escolheu a opção 'Carregar Jogo'.");
                break;
            case '3':
                printf("Você escolheu a opção 'Sair'.");
                break;
            default:
                printf("Opção inválida.");
                flag_repetir_menu = 1;
                break;
        }
    } while (flag_repetir_menu);

    return 0;
}
