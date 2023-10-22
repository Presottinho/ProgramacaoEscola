#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/*implementar: sistema de aposta, esc para fechar*/
/*resolver: ao jogar 2 vezes ele não salva a primeira dezena digitada, não aparecer sorteio*/

int qtdDozens, values[11], drawValues[7], cont = 1, correctValues[7];
bool right, oldPlayer = false, game = true;

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

void organizeDozens(){
    for(int p = 1; p <= qtdDozens; p++){
        if(values[p] > values[p + 1]){
            int trade = values[p];
            values[p] = values[p + 1];
            values[p + 1] = trade;
            p = 0;
        }
    }
}

void draw(){
    srand(time(NULL));

    for(int v = 1; v <= 6; v++){
        drawValues[v] = rand() % 60;
        for(int g = 1; g <= v; g++){
            if(drawValues[v] == drawValues[g] && g != v){
                if(drawValues[v] == 0){
                    v = v - 1;
                }else{
                    printf("\nSorteando o %iº...\n", v);
                    sleep(2);
                    printf("O %iº numero foi: %i", v, drawValues[v]);
                }
            }
        }
    }

}

void showResults(){
    printf("\nOs numeros escolhidos foram:\n");
    for(int r = 1; r <= qtdDozens; r++){
        printf("%iº | %i \n", r, values[r + 1]);
        sleep(1);
    }

    printf("\nOs numeros sorteados foram:\n");
    for(int f = 1; f <= 6; f++){
        printf("%iº | %i \n", f, drawValues[f]);
        sleep(1);
    }

    if(cont != 1){
        printf("\nOs numeros acertados foram: \n");
        for(int j = 1; j < cont; j++){
            printf("%iº | %i \n", j, correctValues[j]);
            sleep(1);
        }
    }

    if(cont == 4){
        printf("\nParabens! Voce acertou 4 e foi um Quadra-Tro!");
    }else if(cont == 5){
        printf("\nParabens! Voce acertou 5 e foi um Quina-Tro!");
    }else if(cont == 6){
        printf("\nParabens! Voce acertou 6 e foi um Sena-Tro!");
    }else{
        printf("\nInfelizmente você acertou apenas %i numeros e nao ganhou nada! Faltou apenas %i para voce ser um Quadra-Tro. Tente novamente! \n", cont - 1, (4 - cont + 1));
    }

}

void compareValues(){
    cont = 1;
    for(int h = 1; h <= qtdDozens + 1; h++){
        for(int a = 1; a <= 6; a++){
            if(values[h] == drawValues[a]){
                correctValues[cont] = drawValues[a];
                cont++;
            }
        }
    }

    showResults();
}

void mainMenu(){

    printf("\n------------Opcoes------------\n");
    printf("1 - Iniciar apostas.\n");
    printf("2 - Mostrar ultimo resultado.\n");
    printf("Esc - Sair.\n");
    printf("------------------------------\n");


}

int main(){
    char name[100];

    printf("---------------Seja bem-vindo ao Mega-Tro---------------\n\n");
    printf("Digite seu nome: ");
    gets(name);

    do{

        int option;

        mainMenu();
        scanf("%i", &option);

        switch(option){
            case 1:
                if(oldPlayer == false){
                    printf("\nOla %s, seja bem-vindo a nossa casa de aposta.\nQuantas dezenas voce gostaria de apostar? Escolha um número entre 6 e 10!\n", name);
                    oldPlayer = true;
                }else{
                    printf("\nOla %s, seja bem-vindo novamente a nossa casa de aposta.\nQuantas dezenas voce gostaria de apostar? Escolha um número entre 6 e 10!\n", name);
                }

                do{

                    right = setQtdDozens();

                }while(right == false);

                printf("Perfeito %s! Agora voce devera digitar as dezenas desejadas! Lembrando, elas devem ir de 1 a 60.\n", name);
                setDozens();

                printf("Finalizado!\n");
                organizeDozens();

                printf("Agora realizaremos o sorteio de 6 numeros! Acompanhe com a gente!\n");
                draw();

                printf("\nAgora vamos comparar os valores! Sera que teremos um novo milinario hoje?\n");
                compareValues();
            break;

            case 2:
                showResults();
            break;

            default:
                printf("Caracter invalido, tente novamente.\n");
            break;

        }
    }while(game == true);

}