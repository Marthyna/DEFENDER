#include "movimenta_nave.h"
//Fun��o que movimenta a nave do jogador.
COORDENADA movimenta_nave(COORDENADA nave_pos_inicial, char movimento) {
    COORDENADA nave_pos_atualizada; // vari�vel que guarda a posi��o da nave atualizada.
    switch(movimento) {
        case 'w': // CIMA
            nave_pos_atualizada.linha = nave_pos_inicial.linha - 1;
            break;
        case 's': // BAIXO
            nave_pos_atualizada.linha = nave_pos_inicial.linha + 1;
            break;
        default:
            nave_pos_atualizada.linha = nave_pos_inicial.linha;
            break;
    }
    if(nave_pos_inicial.coluna == COLUNAS)// Condi��o de a nave chegar ao limite do mapa.
        nave_pos_inicial.coluna -= COLUNAS;
    nave_pos_atualizada.coluna = (nave_pos_inicial.coluna) + 1;
    return nave_pos_atualizada;
}
