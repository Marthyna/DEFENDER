#include "pede_nome.h"
#include "nome_repetido.h"
void pede_nome(JOGO jogo_t) {

    int flag_nome_repetido = 0;

    gotoxy((COLUNAS_TELA-4)/2, LINHAS/3);
    printf("NOME");
    gotoxy((COLUNAS_TELA-22)/2, LINHAS/3+1);
    printf("(maximo 10 caracteres)");

    gotoxy((COLUNAS_TELA-12)/2, LINHAS/3+3);
    printf("            ");

    gotoxy((COLUNAS_TELA-10)/2, LINHAS/3+3);
    scanf("%10s", jogo_t.jogador_t.nome);

    flag_nome_repetido = nome_repetido(jogo_t.jogador_t.nome);
    while(flag_nome_repetido)
    {
        flag_nome_repetido = 0;
        clrscr();
        gotoxy((COLUNAS_TELA-20)/2, LINHAS/3);
        printf("NOME JA UTILIZADO");
        gotoxy((COLUNAS_TELA-22)/2, LINHAS/3+1);
        printf("Informe outro nome: ");

        gotoxy((COLUNAS_TELA-12)/2, LINHAS/3+3);
        printf("            ");

        gotoxy((COLUNAS_TELA-10)/2, LINHAS/3+3);
        scanf("%10s", jogo_t.jogador_t.nome);
        flag_nome_repetido = nome_repetido(jogo_t.jogador_t.nome);
    }
}
