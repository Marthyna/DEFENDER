#include "tiro_inimigo.h"
/* Fun��o que controla a gera��o do tiro inimigo */
void tiro_inimigo(INIMIGO inimigo, char mapa[LINHAS][COLUNAS]) {
    int linha, coluna;
    int flag_atira = inimigo.flag_atira;
    COORDENADA posicao_tiro_t;
    if(mapa[inimigo.posicao_t.linha][(inimigo.posicao_t.coluna)] == 'X' && flag_atira == 1) { // Verifica a posi��o do inimigo dentro do mapa para gerar o tiro no lugar correto.
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
        mapa[linha][coluna] = '.';// Gera o tiro na devida posi��o do mapa.
        posicao_tiro_t.linha = linha;//Atualiza a linha do tiro do inimigo para evitar colis�es com os pr�prios.
        posicao_tiro_t.coluna = coluna;//Atualiza a coluna do tiro do inimigo para evitar colis�es com os pr�prios.
        inimigo.posicao_tiro_t = posicao_tiro_t;
    }
}
