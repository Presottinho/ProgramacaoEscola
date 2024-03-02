#include <stdlib.h>
#include <stdio.h>

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
    // }else{
    //     printf("O numero nao e positivo\n");
    // }

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
    //     break;
    // }   

    //Exercicio 3
    int num[3];

    printf("Digite tres valores: \n");
    for(int i = 0; i < 3; i++){ //for para preencher o array
        printf("Digite o valor de numero %i: ", i + 1);
        scanf("%i", &num[i]); //define o array na posicao i com o valor digitado pelo usuario
    }

    if(num[0] > num[1] && num[0] > num[2]){ //verifica qual o maior numero
        printf("O primeiro numero digitado e o maior de todos. O numero %i", num[0]);
    }else if(num[1] > num[0] && num[1] > num[2]){
        printf("O segundo numero digitado e o maior de todos. O numero %i", num[1]);
    }else if(num[2] > num[1] && num[2] > num[0]){
        printf("O terceiro numero digitado e o maior de todos. O numero %i", num[2]);
    }else{
        printf("Dois maiores numeros sao iguais ou ha valores invalidos.");
    }
}