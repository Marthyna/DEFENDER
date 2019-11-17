#include <stdio.h>
#define LINHAS 35
#define COLUNAS 415
#define COLUNAS_TELA 105
#define FILE_MAPA "mapa.txt"

typedef struct
{
    int linha, coluna;
} POSICAO;

POSICAO le_mapa(FILE *arq, char mapa[][COLUNAS])
{
    int i, j;
    char c;
    POSICAO posicao_t;
    for(i = 0; i < LINHAS; i++)
    {
        for(j = 0; j < COLUNAS; j++)
        {
           c = fgetc(arq);
           if (c == '@')
           {
               posicao_t.linha = i;
               posicao_t.coluna = j;
           }
           mapa[i][j] = c;
        }
        c = fgetc(arq);
    }
    return posicao_t;
}

void gera_tela(char tela[][COLUNAS_TELA], char mapa[][COLUNAS], int coluna)
{
    int i, j;
    for(i = 0; i < LINHAS; i++)
        for(j = 0; j < COLUNAS_TELA; j++)
            if((j + coluna) >= COLUNAS)
                tela[i][j] = mapa[i][(j + coluna) - COLUNAS];
            else
                tela[i][j] = mapa[i][j + coluna];
}

void imprime_tela(char tela[][COLUNAS_TELA])
{
    int i, j;
    for(i = 0; i < LINHAS; i++)
    {
        for(j = 0; j < COLUNAS_TELA; j++)
        {
            printf("%c", tela[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    FILE *arq;
    POSICAO nave_pos_inicial;
    char mapa[LINHAS][COLUNAS];
    char tela[LINHAS][COLUNAS_TELA];
    int coluna;
    arq = fopen(FILE_MAPA, "r");
    if(!arq)
    {
        printf("Erro ao abrir o arquivo.");
        return 0;
    }
    nave_pos_inicial = le_mapa(arq, mapa);
    printf("Posicao inicial da nave: linha %d, coluna %d\n", nave_pos_inicial.linha, nave_pos_inicial.coluna);
    printf("Informe a coluna: ");
    scanf(" %d", &coluna);
    gera_tela(tela, mapa, coluna);
    imprime_tela(tela);
    fclose(arq);
    return 0;
}
