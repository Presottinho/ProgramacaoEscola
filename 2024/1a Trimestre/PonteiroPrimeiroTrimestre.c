#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

//Funcao exercicio 2
void troca(int *p1, int *p2){

    int aux;//variavel auxiliar para ajudar na troca
    aux = *p1;//adiciona p1 na auxiliar
    *p1 = *p2;//adicionar p2 na p1
    *p2 = aux;//adicionar o valor da auxiliar na p2

}

//Funcao exercicio 3
int crescente(int *num1, int *num2, int *num3){

    int aux;//variavel auxiliar para ajudar na ordenacao
    for(int i = 0; i < 3; i++){

        if(*num1 > *num2){//verificar o primeiro e maior que o segundo
            aux = *num1;//caso seja verdadeiro
            *num1 = *num2;//adicionar o valor da num2 na num1
            *num2 = aux;//adiciona o valor da auxiliar na num2
            i = -1;//reinicia o for
        }else if(*num2 > *num3){//verifica se o num2 e maior que o num3
            aux = *num2;//adiciona o valor de num2 na variavel auxiliar
            *num2 = *num3;//adiciona o valor de num3 na num2
            *num3 = aux;//adiciona o valor da variavel auxiliar na num3
            i = -1;//reinicia o for
        }

        int vet[3];//cria uma array e adiciona todos os numeros ordenamente na array
        vet[0] = *num1;
        vet[1] = *num2;
        vet[2] = *num3;

        if(i == 2){//caso ja tenha sido ordenado, ele apresenta os numeros para o usuario
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

    int aux;//cria uma variavel auxiliar
    for(int i = 0; i < 3; i++){

        if(*num1 < *num2){//verifica se o num1 e menor que o num2
            aux = *num1;//caso seja verdade, ele adicionar o valor de num1 na variavel auxiliar
            *num1 = *num2;//adiciona o valor de num2 na variavel num1
            *num2 = aux;//adicionar o valor da variavel auxliar na num2
            i = -1;//reinicia o for
        }else if(*num2 < *num3){//verifica o num2 e menor que o num3
            aux = *num2;//caso seja verdade, ele adicionar o valor de num2 na variavel auxiliar
            *num2 = *num3;//adicionar o valor de num3 na num2
            *num3 = aux;//adicionar o valor da variavel auxiliar na num3
            i = -1;//reinicia o for
        }

        int vet[3];//cria uma array e adiciona os valores ordenamente nela
        vet[0] = *num1;
        vet[1] = *num2;
        vet[2] = *num3;

        if(i == 2){//caso ja tenham sido todos ordenados, ele apresenta os numeros para o usuario
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
    if(*frequencia == 0 && *periodo == 0){//verifica se o usuario inseriu algum dos valores
        printf("Erro de parametro.");
        return -1;
    }else if(*frequencia == 0){//verifica se o valor faltando e a frequencia
        *frequencia = 1 / *periodo;//caso seja, ele calcula a frequencia utilizando o periodo
        printf("A frequencia e: %.2f", *frequencia);
        return 0;
    }else if(*periodo == 0){//verifica se o valor faltando e o periodo
        *periodo = 1 / *frequencia;//caso seja ele calcula utilizando a frequencia
        printf("O periodo e: %.2f", *periodo);
        return 0;
    }else{//caso o usuario tenha digitado os dois valores, ele apenas apresenta os valores
        printf("O valores digitados foram: Periodo = %.2f e Frequencia = %.2f", *periodo, *frequencia);
    }
}

//Funcao da questao 5
int trianguloretangulo(float *oposto, float *adjacente, float *hipotenusa){

    float resultado;

    if(*oposto == 0 && *adjacente == 0 && *hipotenusa == 0){ //verifica se todos os parametros estao faltando
        printf("Erro de paramentro.");
        return -1;
    }else if(*hipotenusa == 0){//verifica se e a hipotenusa que esta faltando
        resultado = (*oposto * *oposto) + (*adjacente * *adjacente);//calcula o teorema de pitagoras faltando a hipotenusa
        resultado = sqrt(resultado);//tira a raiz quadrada da soma dos catetos ao quadrado
        printf("A hipotenusa e: %.2f", resultado);//mostra o resultado
        return 0;
    }else if(*adjacente == 0){//verifica se e o cateto adjacente que esta faltando
        resultado = (*hipotenusa * *hipotenusa) - (*oposto * *oposto);//calcula o lado adjacente subtraindo o quadrado do cateto oposto do quadrado da hipotenusa
        resultado = sqrt(resultado);//tira raiz quadrada da subtracao
        printf("O cateto adjacente e: %.2f", resultado);//apresenta o resultado do cateto adjacente calculado
        return 0;
    }else if(*oposto == 0){//verifica se e o cateto oposto que ta faltando
        resultado = (*hipotenusa * *hipotenusa) - (*adjacente * *adjacente);//calcula o cateto oposto subtraindo o quadrado do cateto adjacente da hipotenusa
        resultado = sqrt(resultado);//tira raiz quadrada da subtracao
        printf("O cateto oposto e: %.2f", resultado);//apresenta o resultado
        return 0;
    }else{
        printf("Erro de parametro.");//caso caia em outra excecao, apresenta esta mensagem
        return -1;
    }

}

//Funcao da questao 5.2
/*
int calcResis(float *ve, float *vs, int *r1, int *r2){
    
    if(*vs > *ve){
        printf("Voltagem de saida maior que de entrada. Erro de parametro.");
        return -2;
    }else if(r1 == 0 && r2 == 0){
        printf("Erro de parametro.");
        return -1;
    }else if(*r2 == 0){
        int aux;
        
    }
    
}
*/

int ordenadordepalavras(char palavra1[], char palavra2[]){

    bool palavra1maiuscula;
    bool palavra2maiuscula;

    if(palavra1[0] >= 97 && palavra1[0] <= 122){
        palavra1maiuscula = false;
    }else if(palavra1[0] >= 65 && palavra1[0] <= 90){
        palavra1maiuscula = true;
    }else{
        printf("Caracter Invalido.");
        return 0;
    }

    if(palavra2[0] >= 97 && palavra2[0] <= 122){    
        palavra2maiuscula = false;
    }else if(palavra2[0] >= 65 && palavra2[0] <= 90){
        palavra2maiuscula = true;
    }else{
        printf("Caracter Invalido.");
        return 0;
    }

    tolower(palavra1[0]);
    tolower(palavra2[0]);

    for(int i = 0; i < 20; i++){

        if(palavra1[i] < palavra2[i]){
            if(palavra1maiuscula == true){
                palavra1[0] = palavra1[0] - 32;
            }
                printf("Primeiramente: %s\nSecundamente: %s\n", palavra1, palavra2);
        }else if(palavra2[i] < palavra1[i]){
            if(palavra2maiuscula == true){
            palavra2[0] = palavra2[0] - 32;
            }
            printf("Primeiramente: %s\nSecundamente: %s\n", palavra2, palavra1);
        }else{
            i = i;
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
    /*
    float oposto, adjacente, hipotenusa;

    printf("Insira o tamanho do cateto oposto(0 caso o valor seja desconhecido): \n");
    scanf("%f", &oposto);

    printf("Insira o tamanho do cateto adjacente(0 caso o valor seja desconhecido): \n");
    scanf("%f", &adjacente);

    printf("Insira o tamanho da hipotenusa(0 caso o valor seja desconhecido): \n");
    scanf("%f", &hipotenusa);

    trianguloretangulo(&oposto, &adjacente, &hipotenusa);
    */
    
    //Exercicio 5.2
    /*
    float ve, vs;
    int r1, r2;
    
    printf("Digite a voltagem da fonte de entrada: ");
    scanf("%f", &ve);
    
    printf("Agora digite o valor medido na saida: ");
    scanf("%f", &vs);
    
    printf("Digite o valor do resistor R1: (em ohms): ");
    scanf("%i", &r1);
    
    printf("Digite o valor do resistor R2: (em ohms): ");
    scanf("%i", &r2);
    
    calcResis(&ve, &vs, &r1, &r2);
    */

   //Exercicio 6

    char palavra1[20], palavra2[20];
    
    printf("Você devera digitar duas palavras.\n");

    printf("Digite a primeira palavra: ");
    gets(palavra1);

    printf("Digite a segunda palavra: ");
    gets(palavra2);

    ordenadordepalavras(palavra1, palavra2);
    
}