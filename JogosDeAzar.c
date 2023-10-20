#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int qtdDozens, values[11], drawValues[7], cont = 0, correctValues[7];
bool right;

bool setQtdDozens(){

    scanf("%i", &qtdDozens);
    if(qtdDozens < 6 || qtdDozens > 10){
        printf("Quantidade de dezenas invalidas, tente novamente digitando um numero valido.\n");
        return false;
    }

    return true;
}

int setDozens(){

    for(int i = 1; i <= qtdDozens; i++){
        printf("Digite seu %iº numero: ", i);
        scanf("%i", &values[i]);
        for(int x = 1; x <= i; x++){
            if(values[x] == values[i] && x != i){
                printf("Numero repetido, digite novamente.\n");
                i = i - 1;
            }else if(values[i] < 1 || values[i]> 60){
                printf("Valor fora dos parametros permitidos, tente novamente.\n");
                i = i - 1;
            }
        }
    }

}

void showDozens(){
    for(int p = 1; p <= qtdDozens; p++){
        if(values[p] > values[p + 1]){
            int trade = values[p];
            values[p] = values[p + 1];
            values[p + 1] = trade;
            p = 0;
        }
    }

    for(int c = 1; c <= qtdDozens; c++){
        printf("%iº | %i\n", c, values[c + 1]);
    }

}

void draw(){
    srand(time(NULL));

    for(int v = 1; v <= 6; v++){
        printf("\nSorteando o %iº...\n", v);
        drawValues[v] = rand() % 60;
        sleep(2);
        printf("O %iº numero foi: %i", v, drawValues[v]);
    }

}

void compareValues(){
    for(int h = 1; h <= qtdDozens; h++){
        for(int a = 1; a <= 6; h++){
            if(values[h] == drawValues[a]){
                correctValues[cont] = values[h];
                cont++;
            }
        }
    }

    printf("Os numeros escolhidos foram:\n");
    for(int r = 0; r < qtdDozens; r++){
        printf("%iº | %i ", r, values[r]);
    }

    printf("Os numeros sorteados foram:\n");
    for(int f = 0; f < qtdDozens; f++){
        printf("%iº | %i ", f, values[f]);
    }

    if(cont == 4){
        printf("\nParabens! Voce acertou 4 e foi um Quadra-Tro!");
    }else if(cont == 5){
        printf("\nParabens! Voce acertou 5 e foi um Quina-Tro!");
    }else if(cont == 6){
        printf("\nParabens! Voce acertou 6 e foi um Sena-Tro!");
    }else{
        printf("\nInfelizmente você acertou apenas %i numeros e nao ganhou nada! Faltou apenas %i para voce ser um Quadra-Tro. Tente novamente!", cont, (6 - cont));
    }

}

int main(){
    char name[100];

    printf("---------------Seja bem-vindo ao Mega-Tro---------------\n\n");
    printf("Digite seu nome: ");
    gets(name);

    printf("\nOla %s, seja bem-vindo a nossa casa de aposta.\nQuantas dezenas voce gostaria de apostar? Escolha um número entre 6 e 10!\n", name);
    do{

        right = setQtdDozens();

    }while(right == false);

    printf("Perfeito %s! Agora voce devera digitar as dezenas desejadas! Lembrando, elas devem ir de 1 a 60.\n", name);
    setDozens();

    printf("Finalizado! As dezenas digitadas foram: \n");
    showDozens();

    printf("Agora realizaremos o sorteio de 6 numeros! Acompanhe com a gente!");
    draw();

    printf("Agora vamos comparar os valores! Sera que teremos um novo milinario hoje?");
    compareValues();

}