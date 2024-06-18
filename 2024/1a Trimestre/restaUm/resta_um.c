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

void transformadorColuna(char aux, int *jogada){ //funcao que classifica as colunas em numeros

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

        case 'A':
            *jogada = 0;
            break;

        case 'B':
            *jogada = 1;
            break;

        case 'C':
            *jogada = 2;
            break;

        case 'D':
            *jogada = 3;
            break;

        case 'E':
            *jogada = 4;
            break;

        case 'F':
            *jogada = 5;
            break;

        case 'G':
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

    printf("Qual a linha de origem?(Digite 997 para desistir): ");//solicita a linha de origem e da a possibilidade do jogador desistir
    scanf("%i", &jog->origem.lin);//coleta a linha de origem

    fflush(stdin);//limpa a entrada do teclado

    printf("Qual a coluna de origem?: ");//solicita a coluna de origem
    scanf("%c", &aux);//coleta a coluna de origem
    transformadorColuna(aux, &jog->origem.col);//transforma a letra em int

    fflush(stdin);//limpa a entrada do teclado

    printf("Qual a linha de destino?: ");//solicita a linha de destino
    scanf("%i", &jog->destino.lin);//coleta a linha de destino

    fflush(stdin);//limpa a entrada do teclado

    printf("Qual a coluna de destino?: ");//solicita a coluna de destino
    scanf("%c", &aux);//coleta a coluna de destino
    transformadorColuna(aux, &jog->destino.col);//transforma a letra em int

    fflush(stdin);//limpa a entrada do teclado

    if(jog->origem.lin == 997){//verifica se o jogador desistiu
        return DERROTA;
    }else{
        return OK;
    }

}

status_t movimenta(char* tab, movimento_t jog){
    int ordenaCol[2];//array para ordernar colunas por ordem decrescente
    int ordenaLin[2];//array para ordenar linhas por ordem decrescente

    if(jog.destino.col >= jog.origem.col){//ordena as colunas em ordem decrescente dentro do array
        ordenaCol[0] = jog.origem.col;
        ordenaCol[1] = jog.destino.col;
    }else{
        ordenaCol[0] = jog.destino.col;
        ordenaCol[1] = jog.origem.col;
    }

    if(jog.destino.lin >= jog.origem.lin){//ordena as linhas em ordem decrescente dentro do array
        ordenaLin[0] = jog.origem.lin;
        ordenaLin[1] = jog.destino.lin;
    }else{
        ordenaLin[0] = jog.destino.lin;
        ordenaLin[1] = jog.origem.lin;
    }

    if(ordenaLin[1] - ordenaLin[0] <= 2 && ordenaLin[1] - ordenaLin[0] >= 0 && ordenaLin[1] - ordenaLin[0] != 1 && ordenaCol[1] - ordenaCol[0] <= 2 && ordenaCol[1] - ordenaCol[0] >= 0 && ordenaCol[1] - ordenaCol[0] != 1){ //verifica se a jogada do jogador e valida
        if(ordenaLin[1] - ordenaLin[0] == 2 && ordenaCol[1] - ordenaCol[0] == 2){//verifica se esta tentando comer na diagonal
            return INVALIDO;
        }else{
            switch(*(tab + (NCOL * jog.origem.lin) + jog.origem.col)){//verifica se o local de origem tem alguma peca

                case 'O'://caso origem esteja vazio
                    return VAZIO;
                    break;

                case 'X'://caso origem seja invalido
                    return INVALIDO;
                    break;

            }

            switch(*(tab + (NCOL * jog.destino.lin) + jog.destino.col)){//verifica se a coordenada de destino pode ser utilizada(comer na mesma linha)

                case 'O'://caso destino esteja vazio
                    switch(jog.destino.lin - jog.origem.lin){//verifica se a jogada e para direita ou para esquerda

                        case 2:
                            if(*(tab + (NCOL * (jog.destino.lin - 1)) + jog.destino.col) == '*'){//verifica se a peca que vai ser comida e valida
                                *(tab + (NCOL * (jog.destino.lin - 1)) + jog.destino.col) = 'O';//mata a peca entre origem e destino
                                *(tab + (NCOL * jog.origem.lin) + jog.origem.col) = 'O';//esvazia o local de origem
                                *(tab + (NCOL * jog.destino.lin) + jog.destino.col) = '*';//ocupa o espaco de destino
                                return OK;//continua o jogo
                            }else if(*(tab + (NCOL * jog.origem.lin) + jog.origem.col) == 'O'){
                                return VAZIO;
                            }else{
                                return INVALIDO;
                            }
                            break;

                        case -2:
                            if(*(tab + (NCOL * (jog.destino.lin + 1)) + jog.destino.col) == '*'){//verifica se a peca que vai ser comida existe
                                *(tab + (NCOL * (jog.destino.lin + 1)) + jog.destino.col) = 'O';//mata a peca que esta entre o destino e a origem
                                *(tab + (NCOL * jog.origem.lin) + jog.origem.col) = 'O';//esvazia o local de origem
                                *(tab + (NCOL * jog.destino.lin) + jog.destino.col) = '*';//ocupa o espaco de destino
                                return OK;
                            }else if(*(tab + (NCOL * jog.origem.lin) + jog.origem.col) == 'O'){//caso a peca nao existe, vazio
                                return VAZIO;
                            }else{
                                return INVALIDO;
                            }
                            break;

                        default:
                            break;

                    }

                    switch(jog.destino.col - jog.origem.col){//verifica se a coordenada de destino e valida(comer na mesma coluna)

                        case 2://para esquerda
                            if(*(tab + (NCOL * jog.destino.lin) + (jog.destino.col - 1)) == '*'){//identifica se ha peca para ser comida
                                *(tab + (NCOL * jog.destino.lin) + (jog.destino.col - 1)) = 'O';//mata a peca
                                *(tab + (NCOL * jog.origem.lin) + jog.origem.col) = 'O';//esvazia a origem
                                *(tab + (NCOL * jog.destino.lin) + jog.destino.col) = '*';//ocupa o destino
                                return OK;
                            }else if(*(tab + (NCOL * jog.origem.lin) + jog.origem.col) == 'O'){//caso nao haja peca para matar, vazio
                                return VAZIO;
                            }else{
                                return INVALIDO;
                            }
                            break;

                        case -2://para direita
                            if(*(tab + (NCOL * jog.destino.lin) + (jog.destino.col + 1)) == '*'){//identifica se ha peca para ser comida
                                *(tab + (NCOL * jog.destino.lin) + (jog.destino.col + 1)) = 'O';//mata a peca
                                *(tab + (NCOL * jog.origem.lin) + jog.origem.col) = 'O';//esvazia a origem
                                *(tab + (NCOL * jog.destino.lin) + jog.destino.col) = '*';//ocupa o destino
                                return OK;
                            }else if(*(tab + (NCOL * jog.origem.lin) + jog.origem.col) == 'O'){//caso nao haja peca para ser comida, vazio
                                return VAZIO;
                            }else{
                                return INVALIDO;
                            }
                            break;

                    }
                    break;

                case '*'://caso destino esteja ocupado, ocupado
                    return OCUPADO;
                    break;
            }

        }

    }else{
        return INVALIDO;
    }

}

status_t confereJogo(char* tab){
    int h = 0;//verificador de quantas jogadas ainda sao validas

    for(int i = 0; i < NLIN; i++){//for para analisar linha por linha
        for(int j = 0; j < NCOL; j++){//for para analisar coluna por coluna
            if(*(tab + (NLIN * i) + j) == '*'){//verifica se existe peca naquela parte do tabuleiro
                if(*(tab + (NLIN * (i + 1)) + j) == '*' && *(tab + (NLIN * (i + 2)) + j) == 'O'){//verifica se ha peca na linha de baixo e se duas linhas abaixo tem espaco vago
                    h++;//caso haja, e uma possibilidade de jogada
                }else if(*(tab + (NLIN * (i - 1)) + j) == '*' && *(tab + (NLIN * (i - 2)) + j) == 'O'){//verifica se ha peca na linha de cima e se duas linhas acima tem espaco vazio
                    h++;//caso haja, e uma possibilidade de jogada
                }else if(*(tab + (NLIN * i) + (j + 1)) == '*' && *(tab + (NLIN * i) + (j + 2)) == 'O'){//verifica se ha peca na coluna a direita e verifica se duas colunas a direita esta vazio
                    h++;//caso haja, e uma possibilidade de jogada
                }else if(*(tab + (NLIN * i) + (j - 1)) == '*' && *(tab + (NLIN * i) + (j - 2)) == 'O'){//verifica se ha peca na coluna a esquerda e verifica se duas colunas a esquerda esta vazio
                    h++;//caso haja, e uma possibilidade de jogada
                }
            }
        }
    }

    if(h >= 1){//caso haja mais de uma jogada possivel, jogo continuar
        return OK;
    }else if(h < 1 && numJogadas == 31){//caso ja tenha morrido 31 pecas, jogo ganho
        return VITORIA;
    }else{//caso contrario, derrota
        return DERROTA;
    }

}
