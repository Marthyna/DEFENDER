/*
    Trabalho final de Introdução a Algoritmos e Programação
    DEFENDER - Versão adaptada
    Por Henrique Bernardes e Marthyna Weber
*/
/*Bibliotecas utilizadas*/
#include "main.h"
#include "menu_inicial.h"
#include "le_mapa.h"
#include "gotoxy.h"
#include "clrscr.h"
#include "kbhit.h"
#include "tiro_inimigo.h"
#include "inicia_jogo.h"
int main() {
    FILE *arq_abre;
    JOGO jogo_t;
    char opcao;
    int flag_repetir_menu = 0;
    int qt_inimigos;
    do {
        opcao = menu_inicial();
        switch(opcao) {
        case '1':
            arq_abre = fopen("mapa.txt", "r");
            if(!arq_abre) {
                printf("Erro ao abrir o arquivo do mapa.");
                return 0;
            }
            jogo_t.jogador_t.vidas = VIDAS;
            jogo_t.jogador_t.escore = 0;
            jogo_t.delay = DELAY_INICIAL;
            qt_inimigos = le_mapa(arq_abre, &jogo_t);
            jogo_t.qt_inimigos = qt_inimigos;
            inicia_jogo(&jogo_t);
            break;
        case '2':
            arq_abre = fopen("salvos.bin", "r");
            if(!arq_abre)
                printf("Não foi possivel abrir o aquivo de jogos salvos.");
            else {
                if(fread(&jogo_t, sizeof(jogo_t), 1, arq_abre) != 1)
                    printf("Não foi possivel abrir o jogo salvo no arquivo.");
                else {
                    inicia_jogo(&jogo_t);
                }
            }
            break;
        case '3':
            return 0;
            break;
        default:
            printf("Opcao invalida.");
            flag_repetir_menu = 1;
            break;
        }
    }
    while (flag_repetir_menu);
    return 0;
}
