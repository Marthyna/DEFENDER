#include "salva_jogo.h"
/*Função que salva o jogo dentro de um arquivo separado. */
int salva_jogo(JOGO jogo_t) {
    FILE *arq_salva;
    arq_salva = fopen("salvos.bin", "w");// Abre o arquivo que guarda as informações do jogo.
    if (!arq_salva) {
        printf("Erro ao abrir o arquivo de jogos salvos\n");
        return 0;
    } else {
        if(fwrite(&jogo_t, sizeof(JOGO), 1, arq_salva) != 1) { // Escreve dentro do arquivo do jogo.
            printf("Erro ao escrever o jogo no arquivo.");
            return 0;
        } else
            return 1;
        fclose(arq_salva); //Fecha o arquivo.
    }
}
