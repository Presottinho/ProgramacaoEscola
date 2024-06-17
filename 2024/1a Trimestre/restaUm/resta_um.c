/**********************************************************
* @brief    Trabalho trimestral - Resta Um
* @author   Gabriel Presotto e Vinicius Donini
* @date     jun/2024
* @version  1.1
*
* Fundacao Liberato - Curso de Eletronica
* Elementos de programacao  - prof. Marcos Zuccolotto
*
* Trabalho trimestral - Struct / enum / ponteiros
*
* Implemente as funcoes abaixo comforme especificacao,
*  respeitando os parâmetros e tipos de dados definidos,
*  seguindo as orientacoes dadas
* - qualJogada()
* - movimenta()
* - confereJogo()
*
* Equipe : Bancada (2 alunos)
*
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "resta_um.h"

#define MAXMSG 100  //tamanho maximo mensagens

unsigned int numJogadas = 0;  // Numero de jogadas realizadas

void transformadorColuna(char aux, int *jogada){

    tolower(aux);

    switch(aux){

        case 'a':
            *jogada = 0;
            break;

        case 'b':
            *jogada = 1;
            break;

        case 'c':
            *jogada = 2;
            break;

        case 'd':
            *jogada = 3;
            break;

        case 'e':
            *jogada = 4;
            break;

        case 'f':
            *jogada = 5;
            break;

        case 'g':
            *jogada = 6;
            break;

    }

}

int main()
{
 // Variaveis
    char tabRestaUm[NLIN][NCOL]; // tabuleiro
    status_t estado = OK;         // resultado da função
    movimento_t jogada;         // movimento a realizar
    char msg[MAXMSG];           // mensagem para usuario

// Inicializacao
    setlocale(LC_ALL, "");        // caracteres da lingua portuguesa
    inicTab(tabRestaUm);        // Preenche tabuleiro inicial
    showTab(tabRestaUm);        // Exibe o tabulero
// Laco principal
    do{
      estado = qualJogada(&jogada);
      if(estado != DERROTA){ // Se não pedir para sair, segue o jogo
        estado = movimenta(tabRestaUm, jogada);
        switch(estado)
        {
        case   INVALIDO:
                strncpy(msg, "Movimento invalido\n", MAXMSG);
                break;
        case    VAZIO:
                strncpy(msg, "Sem pecas a mover\n", MAXMSG);
                break;
        case    OCUPADO:
                strncpy(msg, "Posicao destino ocupada\n", MAXMSG);
                break;

        default:
            showTab(tabRestaUm);
            numJogadas++;
            estado = confereJogo(tabRestaUm);
            switch(estado)
            {
            case VITORIA:
                strncpy(msg, "Parabéns, sobrou só um !\n", MAXMSG);
                break;
            case DERROTA:
                strncpy(msg, "Acabaram as jogadas !\n", MAXMSG);
                break;
            default:
                strncpy(msg, "jogo continua...\n", MAXMSG);
            }
        }
        printf(msg);
     }// fim if derrota

    }while(estado != VITORIA && estado != DERROTA);

    printf("Fim de jogo com %d rodadas!\n", numJogadas);


}// fim main

status_t qualJogada(movimento_t* jog){

    char aux;

    printf("Qual a linha de origem?(Digite 997 para desistir): ");
    scanf("%i", &jog->origem.lin);

    fflush(stdin);

    printf("Qual a coluna de origem?: ");
    scanf("%c", &aux);
    transformadorColuna(aux, &jog->origem.col);

    fflush(stdin);

    printf("Qual a linha de destino?: ");
    scanf("%i", &jog->destino.lin);

    fflush(stdin);

    printf("Qual a coluna de destino?: ");
    scanf("%c", &aux);
    transformadorColuna(aux, &jog->destino.col);

    fflush(stdin);

    if(jog->origem.lin == 997){
        return DERROTA;
    }else{
        return OK;
    }

}

status_t movimenta(char* tab, movimento_t jog){
    int ordenaCol[2];
    int ordenaLin[2];

    if(jog.destino.col >= jog.origem.col){
        ordenaCol[0] = jog.origem.col;
        ordenaCol[1] = jog.destino.col;
    }else{
        ordenaCol[0] = jog.destino.col;
        ordenaCol[1] = jog.origem.col;
    }

    if(jog.destino.lin >= jog.origem.lin){
        ordenaLin[0] = jog.origem.lin;
        ordenaLin[1] = jog.destino.lin;
    }else{
        ordenaLin[0] = jog.destino.lin;
        ordenaLin[1] = jog.origem.lin;
    }

    if(ordenaLin[1] - ordenaLin[0] <= 2 && ordenaLin[1] - ordenaLin[0] >= 0 && ordenaLin[1] - ordenaLin[0] != 1 && ordenaCol[1] - ordenaCol[0] <= 2 && ordenaCol[1] - ordenaCol[0] >= 0 && ordenaCol[1] - ordenaCol[0] != 1){
        if(ordenaLin[1] - ordenaLin[0] == 2 && ordenaCol[1] - ordenaCol[0] == 2){
            return INVALIDO;
        }else{
            switch(*(tab + (NCOL * jog.origem.lin) + jog.origem.col)){

                case 'O':
                    return VAZIO;
                    break;

                case 'X':
                    return INVALIDO;
                    break;

            }

            switch(*(tab + (NCOL * jog.destino.lin) + jog.destino.col)){

                case 'O':
                    switch(jog.destino.lin - jog.origem.lin){

                        case 2:
                            if(*(tab + (NCOL * (jog.destino.lin - 1)) + jog.destino.col) == '*'){
                                *(tab + (NCOL * (jog.destino.lin - 1)) + jog.destino.col) = 'O';
                                *(tab + (NCOL * jog.origem.lin) + jog.origem.col) = 'O';
                                *(tab + (NCOL * jog.destino.lin) + jog.destino.col) = '*';
                                return OK;
                            }else if(*(tab + (NCOL * jog.origem.lin) + jog.origem.col) == 'O'){
                                return VAZIO;
                            }else{
                                return INVALIDO;
                            }
                            break;

                        case -2:
                            if(*(tab + (NCOL * (jog.destino.lin + 1)) + jog.destino.col) == '*'){
                                *(tab + (NCOL * (jog.destino.lin + 1)) + jog.destino.col) = 'O';
                                *(tab + (NCOL * jog.origem.lin) + jog.origem.col) = 'O';
                                *(tab + (NCOL * jog.destino.lin) + jog.destino.col) = '*';
                                return OK;
                            }else if(*(tab + (NCOL * jog.origem.lin) + jog.origem.col) == 'O'){
                                return VAZIO;
                            }else{
                                return INVALIDO;
                            }
                            break;

                        default:
                            break;

                    }

                    switch(jog.destino.col - jog.origem.col){

                        case 2:
                            if(*(tab + (NCOL * jog.destino.lin) + (jog.destino.col - 1)) == '*'){
                                *(tab + (NCOL * jog.destino.lin) + (jog.destino.col - 1)) = 'O';
                                *(tab + (NCOL * jog.origem.lin) + jog.origem.col) = 'O';
                                *(tab + (NCOL * jog.destino.lin) + jog.destino.col) = '*';
                                return OK;
                            }else if(*(tab + (NCOL * jog.origem.lin) + jog.origem.col) == 'O'){
                                return VAZIO;
                            }else{
                                return INVALIDO;
                            }
                            break;

                        case -2:
                            if(*(tab + (NCOL * jog.destino.lin) + (jog.destino.col + 1)) == '*'){
                                *(tab + (NCOL * jog.destino.lin) + (jog.destino.col + 1)) = 'O';
                                *(tab + (NCOL * jog.origem.lin) + jog.origem.col) = 'O';
                                *(tab + (NCOL * jog.destino.lin) + jog.destino.col) = '*';
                                return OK;
                            }else if(*(tab + (NCOL * jog.origem.lin) + jog.origem.col) == 'O'){
                                return VAZIO;
                            }else{
                                return INVALIDO;
                            }
                            break;

                    }
                    break;

                case '*':
                    return OCUPADO;
                    break;
            }

        }

    }else{
        return INVALIDO;
    }

}

status_t confereJogo(char* tab){
    int h = 0;

    for(int i = 0; i < NLIN; i++){
        for(int j = 0; j < NCOL; j++){
            if(*(tab + (NLIN * i) + j) == '*'){
                if(*(tab + (NLIN * (i - 1)) + j) == '*'|| *(tab + (NLIN * (i + 1)) + j) == '*'|| *(tab + (NLIN * i) + (j - 1)) == '*'|| *(tab + (NLIN * i) + (j + 1)) == '*'){
                    if(*(tab + (NLIN * i) + (j - 1)) != 'X' || *(tab + (NLIN * i) + (j + 1)) != 'X'){
                        h++;
                    }
                }
            }
        }
    }

    if(h >= 1){
        return OK;
    }else if(h <= 1 && numJogadas == 31){
        return VITORIA;
    }else{
        return DERROTA;
    }

}
