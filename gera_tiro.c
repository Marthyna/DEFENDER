#include "gera_tiro.h"
//Função que gera o tiro do Jogador.
void gera_tiro(COORDENADA nave_pos, char mapa[LINHAS][COLUNAS]) {
    int i, j;
    i = nave_pos.linha;
    j = nave_pos.coluna + 4;// Coloca a variável "j" na frente da nave.
    mapa[i][j+1] = '-';
    mapa[i][j+2] = '-';
}
