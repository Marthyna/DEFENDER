#include "main.h"
#include "menu_inicial.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    char opcao;
    int flag_opcao_inexistente = 0;
    int flag_sair = 0;
    while(!flag_sair)
    {
        opcao = menu_inicial();
        switch(opcao)
        {
            case '1':
                printf("Você escolheu a opção 'Novo Jogo'.");
                break;
            case '2':
                printf("Você escolheu a opção 'Carregar Jogo'.");
                break;
            case '3':
                printf("Você escolheu a opção 'Sair'.");
                flag_sair = 1;
                break;
            default:
                printf("Opção inválida.");
        }
    }

    return 0;
}
