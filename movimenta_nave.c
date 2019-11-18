#include "movimenta_nave.h"
COORDENADA movimenta_nave(COORDENADA nave_pos_inicial)
{
    COORDENADA nave_pos_atualizada;

    nave_pos_atualizada.linha = nave_pos_inicial.linha;
    nave_pos_atualizada.coluna = (nave_pos_inicial.coluna)+1;

    return nave_pos_atualizada;
}
