/**********************************************************
* @file     resta_um.h
* @brief    Resta Um - defines, tipos dados e prototipos
* @author   Gabriel Presotto e Vinicius Donini
* @date     jun/2024
* @version  1.1
*
*
**********************************************************/

#ifndef _RESTA_UM_H_   // Declaracao de guarda
#define _RESTA_UM_H_

// Dimensoes da matriz que guarda o tabuleiro
#define NCOL 7
#define NLIN 7

// Marcadores do tabuleiro
#define  NU 'X'  // Ponto invalido/proibido
#define  OC '*'  // Ponto ocupado
#define  VZ 'O'  // Ponto livre/vazio

/* Tipos de dados */

// Posicao peca no tabuleiro
typedef struct{
    int lin; // Posicao linha
    int col; // Posicao coluna
}posTab_t;
// Movimento a ser realizado
typedef struct{
        posTab_t origem;   // Posicao inicio/origem
        posTab_t destino; // Posicao fim
}movimento_t;

typedef enum { OK = 0 , // movimento executado, segue o jogo
               INVALIDO, // n�o existe peca a pular sobre/retira
                         // fora tabuleiro
                         // movimento longo, curto ou em diagonal
               OCUPADO,  // posicao destino ocupada
               VAZIO,    // posicao origem vazia
               VITORIA,  // vitoria - fim jogo
               DERROTA   // nao tem mais o que fazer
             } status_t;
/* Prototipos */

/**
@brief Inicializa tabuleiro
@param tabuleiro
@retval none
*/
void inicTab(char* tab) {
    for (int i = 0; i < NLIN; i++) {
        for (int j = 0; j < NCOL; j++) {
            *(tab + i * NLIN + j) = OC;

            if (i == 0 || i == 1 || i == 5 || i == 6) {
                if (j == 0 || j == 1 || j == 5 || j == 6) {
                    *(tab + i * NLIN + j) = NU;
                }
            }
        }
    }
    *(tab + 3 * NLIN + 3) = VZ;
}
/**
@brief Exibe o tabuleiro
@param tabuleiro
@retval none
*/
void showTab(char* tab){
    printf("  A B C D E F G");
    printf("\n");
    for (int i = 0; i < NLIN; i++) {
        printf("%i ", i);
        for (int j = 0; j < NCOL; j++) {
            printf("%c ", *(tab + i * NLIN + j));
        }
        printf("\n");
    }
    printf("\n");
}

/**
@brief Entrada dados da jogada
@param movimentacao a realizar
@retval OK - jogador definiu a movimentacao
        DERROTA - jogador desistiu do jogo
*/
status_t qualJogada(movimento_t* jog);

/**
@brief Executa a movimentacao solicitada
@param tabuleiro
@param movimentacao a realizar
@retval OK - movimento executado, segue o jogo
        INVALIDO - movimento invalido
        OCUPADO - posicao destino ocupada
        VAZIO - posicao destino ocupada
*/
status_t movimenta(char* tab, movimento_t jog);

/**
@brief Confere possibilidades de continuacao
@param tabuleiro
@retval OK -  segue o jogo
        VITORIA - restou um, acabou
        DERROTA - nada mais a fazer, fim de jogo
*/
status_t confereJogo(char* tab);

#endif // _RESTA_UM_H_
