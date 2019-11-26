#include "imprime_nave.h"
/* Fun��o que varre a matriz do mapa procurando o s�mbolo correspondente � nave do jogador
e realiza a impress�o da figura da nave dentro do mapa. */
int imprime_nave(char mapa[LINHAS][COLUNAS], COORDENADA nave_posicao) {
    int i, j; // Vari�veis que ser�o usadas para guardar a posi��o da nave do jogador.
    int x, y; // Vari�veis auxiliares para varreduras.
    int flag_colisao = 0;
    i = nave_posicao.linha;
    j = nave_posicao.coluna;
    for(x = 0; x < LINHAS; x++)
        for(y = 0; y < COLUNAS; y++)
            if((x != i || y != j) && (mapa[x][y] == '@')) // Achou a nave.
                mapa[x][y] = ' ';
    mapa[i][j] = '@';
    mapa[i-1][j] = '@';
    mapa[i][j+1] = '@';
    mapa[i][j+2] = '@';
    mapa[i][j+3] = '@';
    if((mapa[i][j+4]   == 'C') ||
       (mapa[i-2][j]   == 'C') ||
       (mapa[i-1][j+1] == 'C') ||
       (mapa[i-1][j+2] == 'C') ||
       (mapa[i-1][j+3] == 'C') ||
       (mapa[i+1][j]   == 'C') ||
       (mapa[i+1][j+1] == 'C') ||
       (mapa[i+1][j+2] == 'C') ||
       (mapa[i+1][j+3] == 'C') ||
       (mapa[i][j+4]   == 'X') ||
       (mapa[i-2][j]   == 'X') ||
       (mapa[i-1][j+1] == 'X') ||
       (mapa[i-1][j+2] == 'X') ||
       (mapa[i-1][j+3] == 'X') ||
       (mapa[i+1][j]   == 'X') ||
       (mapa[i+1][j+1] == 'X') ||
       (mapa[i+1][j+2] == 'X') ||
       (mapa[i+1][j+3] == 'X') ||
       (mapa[i][j+4]   == '.') ||
       (mapa[i-2][j]   == '.') ||
       (mapa[i-1][j+1] == '.') ||
       (mapa[i-1][j+2] == '.') ||
       (mapa[i-1][j+3] == '.') ||
       (mapa[i+1][j]   == '.') ||
       (mapa[i+1][j+1] == '.') ||
       (mapa[i+1][j+2] == '.') ||
       (mapa[i+1][j+3] == '.'))
        flag_colisao = 1;
    return flag_colisao;
}
