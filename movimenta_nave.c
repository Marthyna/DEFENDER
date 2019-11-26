#include "movimenta_nave.h"
COORDENADA movimenta_nave(COORDENADA nave_pos_inicial, char movimento)
{
    COORDENADA nave_pos_atualizada;

    switch(movimento){
        case 'w':
            nave_pos_atualizada.linha = nave_pos_inicial.linha - 1;
            break;
        case 's':
            nave_pos_atualizada.linha = nave_pos_inicial.linha + 1;
            break;
        default:
            nave_pos_atualizada.linha = nave_pos_inicial.linha;
            break;
    }

    if(nave_pos_inicial.coluna == COLUNAS)
        nave_pos_inicial.coluna -= COLUNAS;
    nave_pos_atualizada.coluna = (nave_pos_inicial.coluna) + 1;

    return nave_pos_atualizada;
}
