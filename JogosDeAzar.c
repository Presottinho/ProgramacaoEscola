#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int qtdDozens, values[10];
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
    for(int p = 1; p < qtdDozens; p++){
        printf("%iº | %i", p, values[p]);
    }
}

int main(){
    char name[100];

    printf("---------------Seja bem-vindo ao Mega-Tro---------------\n\n");
    printf("Digite seu nome: ");
    gets(name);

    printf("Ola %s, seja bem-vindo a nossa casa de aposta.\nQuantas dezenas voce gostaria de apostar? Escolha um número entre 6 e 10!\n", name);
    do{

        right = setQtdDozens();

    }while(right == false);

    printf("Perfeito %s! Agora voce devera digitar as dezenas desejadas! Lembrando, elas devem ir de 1 a 60.\n", name);
    setDozens();

    printf("Finalizado! As dezenas digitadas foram: \n");
    showDozens();

}