/**********************************************************
* @file     resta_um.h
* @brief    Resta Um - defines, tipos dados e prototipos
* @author   Marcos Zuccolotto
* @date     abr/2024
* @version  1.0
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
void inicTab(char *tab);
/**
@brief Exibe o tabuleiro
@param tabuleiro
@retval none
*/
void showTab(char *tab);

/**
@brief Entrada dados da jogada
@param movimentacao a realizar
@retval OK - jogador definiu a movimentacao
        DERROTA - jogador desistiu do jogo
*/
status_t qualJogada(movimento_t *jog){

        printf("Qual a linha de origem?(Digite 997 para desistir)");
        scanf("%i", &jog->origem.lin);

        printf("Qual a coluna de origem?(Digite 997 para desistir)");
        scanf("%i", &jog->origem.col);

        printf("Qual a linha de destino?(Digite 997 para desistir)");
        scanf("%i", &jog->destino.lin);

        printf("Qual a coluna de destino?(Digite 997 para desistir.)");
        scanf("%i", &jog->destino.col);

}

/**
@brief Executa a movimentacao solicitada
@param tabuleiro
@param movimentacao a realizar
@retval OK - movimento executado, segue o jogo
        INVALIDO - movimento invalido
        OCUPADO - posicao destino ocupada
        VAZIO  posicao destino ocupada
*/
status_t movimenta(char *tab, movimento_t jog){

        do{

                if(jog.destino.col - jog.destino.col < 2 && jog.origem.col - jog.destino.col > -2 && jog.origem.lin - jog.destino.lin < 2 && jog.origem.lin - jog.destino.lin > -2){
                        return OK;
                }else if(jog.origem.col == 997 || jog.origem.lin == 997 || jog.destino.col == 997 || jog.destino.lin == 997){
                        return DERROTA;
                }

        }while(jog.origem.col - jog.destino.col < -2 && jog.origem.col - jog.destino.col > 2 && jog.origem.lin - jog.destino.lin < -2 && jog.origem.lin - jog.destino.lin > 2);


};

/**
@brief Confere possibilidades de continuacao
@param tabuleiro
@retval OK -  segue o jogo
        VITORIA - restou um, acabou
        DERROTA - nada mais a fazer, fim de jogo
*/
status_t confereJogo(char *tab);

#endif // _RESTA_UM_H_
