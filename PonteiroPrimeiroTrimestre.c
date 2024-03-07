#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Funcao exercicio 2
void troca(int *p1, int *p2){

    int aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;

}

//Funcao exercicio 3
int crescente(int *num1, int *num2, int *num3){

    int aux;
    for(int i = 0; i < 3; i++){

        if(*num1 > *num2){
            aux = *num1;
            *num1 = *num2;
            *num2 = aux;
            i = -1;
        }else if(*num2 > *num3){
            aux = *num2;
            *num2 = *num3;
            *num3 = aux;
            i = -1;
        }

        int vet[3];
        vet[0] = *num1;
        vet[1] = *num2;
        vet[2] = *num3;

        if(i == 2){
            printf("Operacao feita.\n");
            printf("num = [");
            for(int j = 0; j < 3; j++){
                printf("%i", vet[j]);
                if(j != 2){
                    printf(",");
                }
            }
            printf("]\n");
            return 0;
        }

    }

}

//Funcao exercicio 3
int decrescente(int *num1, int *num2, int *num3){

    int aux;
    for(int i = 0; i < 3; i++){

        if(*num1 < *num2){
            aux = *num1;
            *num1 = *num2;
            *num2 = aux;
            i = -1;
        }else if(*num2 < *num3){
            aux = *num2;
            *num2 = *num3;
            *num3 = aux;
            i = -1;
        }

        int vet[3];
        vet[0] = *num1;
        vet[1] = *num2;
        vet[2] = *num3;

        if(i == 2){
            printf("Operacao feita.\n");
            printf("num = [");
            for(int j = 0; j < 3; j++){
                printf("%i", vet[j]);
                if(j != 2){
                    printf(",");
                }
            }
            printf("]\n");
            return 0;
        }
    }
    
}

//Funcao exercicio 4
int calcTouF(float *frequencia, float *periodo){
    if(*frequencia == 0 && *periodo == 0){
        printf("Erro de parametro.");
        return -1;
    }else if(*frequencia == 0){
        *frequencia = 1 / *periodo;
        printf("A frequencia e: %.2f", *frequencia);
        return 0;
    }else if(*periodo == 0){
        *periodo = 1 / *frequencia;
        printf("O periodo e: %.2f", *periodo);
        return 0;
    }
}

int trianguloretangulo(float *oposto, float *adjacente, float *hipotenusa){

    float resultado;

    if(*oposto == 0 && *adjacente == 0 && *hipotenusa == 0){
        printf("Erro de paramentro.");
        return -1;
    }else if(*hipotenusa == 0){
        resultado = (*oposto * *oposto) + (*adjacente * *adjacente);
        resultado = sqrt(resultado);
        printf("A hipotenusa e: %.2f", resultado);
        return 0;
    }else if(*adjacente == 0){
        resultado = (*hipotenusa * *hipotenusa) - (*oposto * *oposto);
        resultado = sqrt(resultado);
        printf("A adjacente e: %.2f", resultado);
        return 0;
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
   /*
    int num1, num2, num3;

    printf("Digite tres valores a seguir.\n");
    scanf("%i %i %i", &num1, &num2, &num3);

    char option;

    do{

        printf("Como deseja ordenar?\nC - Crescente\nD - Decrescente\n");
        scanf("%c", &option);

    }while(option != 'D' && option != 'd' && option != 'C' && option != 'c');

    tolower(option);

    if(option == 'c'){
        crescente(&num1, &num2, &num3);
    }else if(option == 'd'){
        decrescente(&num1, &num2, &num3);
    }else{
        return -1;
    }
    */

   //Exercicio 4
    /*
   float frequencia, periodo;

   printf("Digite o valor da frequencia(0 para nao especificar).\n");
   scanf("%f", &frequencia);

   printf("Digite o valor do periodo(0 para nao especificar).\n");
   scanf("%f", &periodo);

   calcTouF(&frequencia, &periodo);
   */

  //Exercicio 5
  
    float oposto, adjacente, hipotenusa;

    printf("Insira o tamanho do cateto oposto(0 caso o valor seja desconhecido): \n");
    scanf("%f", &oposto);

    printf("Insira o tamanho do cateto adjacente(0 caso o valor seja desconhecido): \n");
    scanf("%f", &adjacente);

    printf("Insira o tamanho da hipotenusa(0 caso o valor seja desconhecido): \n");
    scanf("%f", &hipotenusa);

    trianguloretangulo(&oposto, &adjacente, &hipotenusa);

}