#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Funcao exercicio 2
void troca(int *p1, int *p2){

    int aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;

}

int crescente(int *num[]){

    int aux;
    for(int i = 0; i < 3; i++){

        if(*num[i] < *num[i + 1]){
            aux = *num[i];
            *num[i] = *num[i + 1];
            *num[i + 1] = aux;
            i = -1;
        }
        
        if(i == 2){
            printf("Operacao feita.\n");
            printf("num = [");
            for(int i = 0; i < 3; i++){
                printf("%i", *num[i]);
                if(i != 2){
                    printf(",");
                }
            }
            printf("]\n");
            return 0;
        }

    }

}

int decrescente(int *num[]){

    int aux;

    for(int i = 0; i < 3; i++){

        if(*num[i] > *num[i + 1]){
            aux = *num[i];
            *num[i] = *num[i + 1];
            *num[i + 1] = aux;
            i = -1;
        }
        
        if(i == 2){
            printf("Operacao feita.\n");
            printf("num = [");
            for(int i = 0; i < 3; i++){
                printf("%i", *num[i]);
                if(i != 2){
                    printf(",");
                }
            }
            printf("]\n");
            return 0;
        }

    }
    
}

int main(){
    /*
    //Exercicio 2
    int num1, num2;

    printf("Digite 2 valores.\n");
    scanf("%i %i", &num1, &num2);

    printf("Os valores digitados sao: %i e %i\n", num1, num2);

    troca(&num1, &num2);

    printf("Os valores invertidos sao: %i e %i\n", num1,  num2);
    */

   
   //Exercicio 3
    int num[3];

    printf("Digite tres valores a seguir.\n");
    for(int i = 0; i < 3; i++){
        scanf("%i", &num[i]);
    }

    char option;

    do{

        printf("Como deseja ordenar?\nC - Crescente\nD - Decrescente\n");
        scanf("%c", &option);

    }while(option != 'D' && option != 'd' && option != 'C' && option != 'c');

    tolower(option);

    if(option == 'c'){
        crescente(&num);
    }else if(option == 'd'){
        decrescente(&num);
    }

}