#include "nome_repetido.h"
int nome_repetido(char nome[NOMEMAX])
{
    FILE *arq;
    JOGO jogo_t;
    int flag_achou = 0;

    arq = fopen(FILE_SALVOS, "r");

    if(!arq)
        printf("Erro ao abrir o arquivo.");
    else
        while(!feof(arq) && !flag_achou)
            if(fread(&jogo_t, sizeof(JOGO), 1, arq) == 1)
                if(strcmp(nome, jogo_t.jogador_t.nome) == 0)
                    flag_achou = 1;
    if(flag_achou)
        return 1;

    return 0;
}
