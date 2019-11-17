#include "main.h"
#include "menu_inicial.h"
#include "le_mapa.h"
#include "gera_tela.h"
#include "imprime_tela.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    FILE *arq;

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
                //printf("Você escolheu a opção 'Novo Jogo'.\n");
                le_mapa(arq, mapa);
                gera_tela(mapa, tela, coluna_atual);
                imprime_tela(tela);
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
