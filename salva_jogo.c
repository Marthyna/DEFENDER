#include "salva_jogo.h"
#include "nome_repetido.h"
int salva_jogo(JOGO jogo_t)
{
    FILE *arq_salva;

    arq_salva = fopen(FILE_SALVOS, "a+");
    if (!arq_salva)
    {
        printf("Erro ao abrir o arquivo de jogos salvos\n");
        return 0;
    }
    else
    {
        if(fwrite(&jogo_t, sizeof(JOGO), 1, arq_salva) != 1)
        {
            printf("Erro ao escrever o jogo no arquivo.");
            return 0;
        }
        else
            return 1;
        fclose(arq_salva);
    }
}
