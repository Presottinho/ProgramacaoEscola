#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

int main(){
    //Exercicio 1
    // int num;

    // printf("Digite um numero qualquer: ");
    // scanf("%i", &num); //insere o numero digitado pelo usuario na variavel num

    // if(num >= 0){ //verifica se e positivo
    //     if(num % 2 == 0){ //verifica se e par ou impar
    //         printf("O numero e par\n");
    //     }else{
    //         printf("O numero e impar\n");
    //     }
    // }else if(num < 0){
    //     printf("O numero nao e positivo\n");
    // }else{
    //     printf("Caracter invalido.");
    //     return 0;
    //}

    //Exercicio2
    // int nota;

    // printf("Digite a nota do aluno: ");
    // scanf("%i", &nota); //adicionando o numero digitado pelo usuario na variavel nota

    // //utilizando if else
    // if(nota >= 0 && nota < 3){ // verifica em qual conceito o aluno se encaixa
    //     printf("O aluno foi conceito E.\n");
    // }else if(nota >= 3 && nota <= 5){
    //     printf("O aluno foi conceito D.\n");
    // }else if(nota >= 6 && nota <= 7){
    //     printf("O aluno fo conceito C.\n");
    // }else if(nota == 8 || nota == 9){
    //     printf("O aluno foi conceito B.\n");
    // }else if(nota == 10){
    //     printf("O aluno foi conceito A.\n");
    // }else{
    //     printf("Nota invalida.\n");
    //     return 0;
    // }

    // //utilizando switch
    // switch(nota){ //Define qual variavel sera utilizada dentro do switch
    //     case 0:
    //     case 1:
    //     case 2:
    //         printf("O aluno e conceito E.\n");
    //     break;

    //     case 3:
    //     case 4:
    //     case 5:
    //         printf("O aluno e conceito D.\n");
    //     break;

    //     case 6:
    //     case 7:
    //         printf("O aluno e conceito C.\n");
    //     break;

    //     case 8:
    //     case 9:
    //         printf("O aluno e conceito B.\n");
    //     break;

    //     case 10:
    //         printf("O aluno e conceito A.\n");
    //     break;

    //     default:
    //         printf("Nota invalida.\n");
    //         return 0;
    //     break;
    // }   

    //Exercicio 3
    // int num[3];

    // printf("Digite tres valores: \n");
    // for(int i = 0; i < 3; i++){ //for para preencher o array
    //     printf("Digite o valor de numero %i: ", i + 1);
    //     scanf("%i", &num[i]); //define o array na posicao i com o valor digitado pelo usuario
    // }

    // if(num[0] > num[1] && num[0] > num[2]){ //verifica qual o maior numero
    //     printf("O primeiro numero digitado e o maior de todos. O numero %i", num[0]);
    // }else if(num[1] > num[0] && num[1] > num[2]){
    //     printf("O segundo numero digitado e o maior de todos. O numero %i", num[1]);
    // }else if(num[2] > num[1] && num[2] > num[0]){
    //     printf("O terceiro numero digitado e o maior de todos. O numero %i", num[2]);
    // }else{
    //     printf("Dois maiores numeros sao iguais ou ha valores invalidos.");
    //     return 0;
    // }

    //Exercicio 4
    // int num[3];

    // printf("Digite tres valores: ");
    // for(int i = 0; i < 3; i++){ //for para preencher o array
    //     printf("Digite o valor de numero %i: ", i + 1);
    //     scanf("%i", &num[i]); //define o array na posicao i com o valor digitado pelo usuario
    // }
    
    // for(int i = 0; i < 3; i++){//for responsavel por ordenar os numeros
    //     int aux; //variavel auxiliar para ajudar na ordenacao
    //     if(num[i] < num[i + 1] && i > 0){ //verifica se o atual numero e maior ou menor que o numero digitado anteriormente
    //         aux = num[i];
    //         num[i] = num[i + 1];
    //         num[i + 1] = aux;
    //         i = -1;
    //     }
    // }

    // for(int i = 0; i < 3; i++){
    //     printf("O valor de numero %i e: %i\n", i + 1, num[i]);//exibe os numeros em ordem crescente
    // }

    //Desafio 01

    // int i, a, b, c, num[3];

    // printf("Digite 4 valores.\n");
    // printf("Defina o valor de I(1, 2 ou 3): ");
    // scanf("%i", &i);
    // printf("\nDefina o valor de A(Qualquer numero real): ");
    // scanf("%i", &a);
    // printf("\nDefina o valor de B(Qualquer numero real): ");
    // scanf("%i", &b);
    // printf("\nDefina o valor de C(Qualquer numero real): ");
    // scanf("%i", &c);

    // num[0] = a;
    // num[1] = b;
    // num[2] = c;

    // switch(i){
    //     case 1:
    //         for(int i = 0; i < 3; i++){//for responsavel por ordenar os numeros
    //             int aux; //variavel auxiliar para ajudar na ordenacao
    //             if(num[i] < num[i + 1] && i > 0){ //verifica se o atual numero e maior ou menor que o numero digitado anteriormente
    //             aux = num[i];
    //             num[i] = num[i + 1];
    //             num[i + 1] = aux;
    //             i = -1;
    //             }   
    //         } 
            
    //         for(int i = 0; i < 3; i++){
    //             printf("O valor de numero %i e: %i\n", i + 1, num[i]);//exibe os numeros em ordem crescente
    //         }
    //     break;
        
    //     case 2:
    //         for(int i = 0; i < 3; i++){//for responsavel por ordenar os numeros
    //             int aux; //variavel auxiliar para ajudar na ordenacao
    //             if(num[i] < num[i + 1] && i > 0){ //verifica se o atual numero e maior ou menor que o numero digitado anteriormente
    //             aux = num[i];
    //             num[i] = num[i + 1];
    //             num[i + 1] = aux;
    //             i = -1;
    //             }   
    //         } 
            
    //         for(int i = 3; i >= 0; i--){
    //             printf("O valor de numero %i e: %i\n", i + 1, num[i]);//exibe os numeros em ordem decrescente
    //         }
    //     break;
        
    //     case 3:
    //         int aux2;
    //         for(int i = 0; i < 3; i++){//for responsavel por ordenar os numeros
    //             int aux; //variavel auxiliar para ajudar na ordenacao
    //             if(num[i] < num[i + 1] && i > 0){ //verifica se o atual numero e maior ou menor que o numero digitado anteriormente
    //             aux = num[i];
    //             num[i] = num[i + 1];
    //             num[i + 1] = aux;
    //             i = -1;
    //             }   
    //         } 
            
    //         aux2 = num[2];
    //         num[2] = num[1];
    //         num[1] = aux2;
            
    //         for(int i = 0; i < 3; i++){
    //             printf("O valor de numero %i e: %i\n", i + 1, num[i]);//exibe os numeros em ordem decrescente
    //         }
    //     break;
        
    //     default:
    //         printf("I nao e 1, 2 ou 3.");
    //     break;
    // }

    //Desafio 2
    float nota[3];

    printf("Digite tres notas: ");
    for(int i = 0; i < 3; i++){
        scanf("%f", &nota[i]);
    }

    int option;
    printf("Agora escolha qual tipo de media deseja: \n1)Aritmetica \n2)Ponderada(pesos 3, 3, 4(para maior nota))\n3)Harmonica\n4)geometrica\n");
    scanf("%i", &option);

    for(int i = 0; i < 3; i++){//for responsavel por ordenar os numeros
        float aux; //variavel auxiliar para ajudar na ordenacao
        if(nota[i] < nota[i + 1]){ //verifica se o atual numero e maior ou menor que o numero digitado anteriormente
            aux = nota[i];
            nota[i] = nota[i + 1];
            nota[i + 1] = aux;
            i = -1;
        }   
    } 

    switch(option){
        case 1:
            float resultado;
            resultado = (nota[0] + nota[1] + nota[2])/3;
            printf("A media e: %f", resultado);
        break;

        case 2:
            float resultado2;
            resultado2 = ((nota[0] * 3) +  (nota[1] * 3) + (nota[2] * 4)) / (10);
            printf("A media e: %.2f", resultado2);
        break;

        case 3:
            float resultado3;
            resultado3 = 3 / (1 / nota[0] + 1 / nota[1] + 1 / nota[2]);
            printf("A media e: %.2f", resultado3);
        break;

        case 4:
            float resultado4;
            resultado4 = nota[0] * nota[1] * nota[2];
            resultado4 = pow(resultado4, 1.0/3.0);
            printf("A media e: %.2f", resultado4);
        break;

        default:
            printf("Valores invalidos.");
        break;
    }

}