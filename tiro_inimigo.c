#include "tiro_inimigo.h"
/* Função que controla a geração do tiro inimigo */
void tiro_inimigo(INIMIGO inimigo, char mapa[LINHAS][COLUNAS]) {
    int linha, coluna;
    int flag_atira = inimigo.flag_atira;
    COORDENADA posicao_tiro_t;
    if(mapa[inimigo.posicao_t.linha][(inimigo.posicao_t.coluna)] == 'X' && flag_atira == 1) { // Verifica a posição do inimigo dentro do mapa para gerar o tiro no lugar correto.
        linha = inimigo.posicao_tiro_t.linha;
        coluna = inimigo.posicao_tiro_t.coluna;
        switch(inimigo.direcao) {
            case 0: { // norte
                linha = inimigo.posicao_t.linha - 2;
                coluna = inimigo.posicao_t.coluna;
                break;
            }
            case 1: { // sul
                linha = inimigo.posicao_t.linha + 1;
                coluna = inimigo.posicao_t.coluna;
                break;
            }
            case 2: { // leste
                linha = inimigo.posicao_t.linha;
                coluna = inimigo.posicao_t.coluna + 2;
                break;
            }
            case 3: { // oeste
                linha = inimigo.posicao_t.linha;
                coluna = inimigo.posicao_t.coluna - 1;
                break;
            }
            case 4: { // nordeste
                linha = inimigo.posicao_t.linha - 2;
                coluna = inimigo.posicao_t.coluna + 2;
                break;
            }
            case 5: {// noroeste
                linha = inimigo.posicao_t.linha - 2;
                coluna = inimigo.posicao_t.coluna - 1;
                break;
            }
            case 6: { // sudeste
                linha = inimigo.posicao_t.linha + 1;
                coluna = inimigo.posicao_t.coluna + 2;
                break;
            }
            case 7: { // sudoeste
                linha = inimigo.posicao_t.linha + 1;
                coluna = inimigo.posicao_t.coluna - 1;
                break;
            }
        }
        mapa[linha][coluna] = '.';// Gera o tiro na devida posição do mapa.
        posicao_tiro_t.linha = linha;//Atualiza a linha do tiro do inimigo para evitar colisões com os próprios.
        posicao_tiro_t.coluna = coluna;//Atualiza a coluna do tiro do inimigo para evitar colisões com os próprios.
        inimigo.posicao_tiro_t = posicao_tiro_t;
    }
}
