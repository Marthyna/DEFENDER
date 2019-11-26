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
    FILE *arq_abre; // Declaração da variável que abre o arquivo.
    JOGO jogo_t; // Declaração da variavel jogo atual.
    char opcao; // Variável que verifica a opção escolhida pelo jogador dentro do menu.
    int flag_repetir_menu = 0; // Flag que sinaliza a necessidade de repetição do menu.
    int qt_inimigos; // Variável que conta a quantidade de inimigos presentes no mapa.
    do {
        opcao = menu_inicial(); // inicia o menu inicial.
        switch(opcao) {
        case '1':// NOVO JOGO
            arq_abre = fopen("mapa.txt", "r"); // abre o mapa da fase 1.
            if(!arq_abre) {
                printf("Erro ao abrir o arquivo do mapa.");
                return 0;
            }
            jogo_t.jogador_t.vidas = VIDAS;
            jogo_t.jogador_t.escore = 0;
            jogo_t.delay = DELAY_INICIAL;
            qt_inimigos = le_mapa(arq_abre, &jogo_t); //Chama a Função que faz a leitura do mapa.
            jogo_t.qt_inimigos = qt_inimigos;
            inicia_jogo(&jogo_t); // Chama a função que inicia o jogo.
            break;
        case '2': // CARREGA JOGO
            arq_abre = fopen("salvos.bin", "r");// Abre o arquivo dos jogos salvos.
            if(!arq_abre)
                printf("Não foi possivel abrir o aquivo de jogos salvos.");
            else {
                if(fread(&jogo_t, sizeof(jogo_t), 1, arq_abre) != 1)
                    printf("Não foi possivel abrir o jogo salvo no arquivo.");
                else {
                    inicia_jogo(&jogo_t);// Chama a função que inicia o jogo com os dados salvos.
                }
            }
            break;
        case '3': // SAIR
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
