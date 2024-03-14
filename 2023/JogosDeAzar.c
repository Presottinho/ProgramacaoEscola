#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int qtdDozens, values[11], drawValues[7], cont = 1, correctValues[7], rep = 0, balance = 0, bet = 0, approve = 0;
bool right, oldPlayer = false, game = true;
int option;

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

void organizeDozens(int table[], int qtd){
    for(int p = 1; p <= qtd - 1; p++){
        if(table[p] > table[p + 1]){
            int trade = table[p];
            table[p] = table[p + 1];
            table[p + 1] = trade;
            p = 0;
        }
    }
}

void draw(){
    srand(time(NULL));

    for(int v = 1; v <= 6; v++){
        drawValues[v] = rand() % 59 + 1;
        if(drawValues[v] != 0){
            for(int o = 1; o <= v; o++){
                if(drawValues[v] == drawValues[o] && v != o){
                    v = v - 1;
                    break;
                }
            }
            printf("\nSorteando o %iº...\n", v);
            sleep(2);
            printf("O %iº numero sorteado foi: %i", v, drawValues[v]);
        }else{
            v = v - 1;
        }
    }

    organizeDozens(drawValues, 6);

}

void showResults(bool al){
    if(al == true){
        printf("\nOs numeros escolhidos foram:\n");
        for(int r = 1; r <= qtdDozens; r++){
        printf("%iº | %i \n", r, values[r]);
        sleep(1);
    }
    }else{
        printf("Infelizmente voce nao apostou na ultima jogada.\n");
        draw();
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
        bet = bet * 2;
    }else if(cont == 5){
        printf("\nParabens! Voce acertou 5 e foi um Quina-Tro!");
        bet = bet * 5;
    }else if(cont == 6){
        printf("\nParabens! Voce acertou 6 e foi um Sena-Tro!");
        bet = bet * 10;
    }else if(oldPlayer == true){
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

    showResults(oldPlayer);
}

void mainMenu(){

    printf("\n+------------Opcoes------------+\n");
    printf("|1 - Iniciar apostas.          |\n");
    printf("|2 - Mostrar ultimo resultado. |\n");
    printf("|3 - Saldo                     |\n");
    printf("|4 - Sair.                     |\n");
    printf("+------------------------------+\n");


}

void withdraw(){
    do{

        printf("Quantos dolares voce deseja depositar? ");
        if(oldPlayer == true){
            printf("\n-1 - Menu Principal.\n");
        }
        scanf("%i", &balance);

        if(balance == 0){
            printf("Para entrar na casa de apostar voce precisar depositar algo. Tente novamente.");
        }else if(balance == -1){
            balance = 0;
            return;
        }

    }while(balance == 0);
}

int main(){
    char name[100];

    printf("---------------Seja bem-vindo ao Mega-Tro---------------\n\n");
    printf("Digite seu nome: ");
    gets(name);

    withdraw();

    do{

        mainMenu();
        scanf("%i", &option);

        switch(option){
            case 1:
                if(balance == 0){
                    printf("\nNotamos que seu saldo esta zerado.\n");
                    withdraw();
                    break;
                }
                if(oldPlayer == false){
                    printf("\nOla %s, seja bem-vindo a nossa casa de aposta.\n", name);
                    oldPlayer = true;
                }else{
                    printf("\nOla %s, seja bem-vindo novamente a nossa casa de aposta.\n", name);
                    rep = 1;
                }

                do{
                    printf("Quanto voce gostaria de apostar? ");
                    scanf("%i", &bet);
                    if(bet > balance){
                        printf("\nAposta invalida, quantidade excede seu saldo. Tente novamente\n");
                        bet = 0;
                    }else if(bet == 0){
                        printf("Para jogar voce precisa apostar algo.\n");
                    }else if(bet < 0){
                        printf("Aposta invalida, tente novamente.\n");
                    }else{
                        balance = balance - bet;
                    }
                }while(bet == 0);

                printf("Quantas dezenas voce gostaria de apostar? Escolha um número entre 6 e 10!\n");

                do{

                    right = setQtdDozens();

                }while(right == false);

                printf("Perfeito %s! Agora voce devera digitar as dezenas desejadas! Lembrando, elas devem ir de 1 a 60.\n", name);
                setDozens();

                printf("Finalizado!\n");
                organizeDozens(values, qtdDozens);

                printf("Agora realizaremos o sorteio de 6 numeros! Acompanhe com a gente!\n");
                draw();

                printf("\nAgora vamos comparar os valores! Sera que teremos um novo milinario hoje?\n");
                compareValues();
            break;

            case 2:
                showResults(oldPlayer);
            break;

            case 3:
                printf("Seu saldo e: %i", balance);
            break;

            case 4:
                printf("Tem certeza que deseja sair? Caso tenho certeza, pressione ESC, se não pressione qualquer tecla.\n");
                char exit = getchar();
                exit = getchar();
                printf("%c", exit);
                if(exit == 27){
                    printf("VVolte sempre, %s!", name);
                    game = false;
                }
            break;

            default:
                printf("Caracter invalido, tente novamente.\n");
            break;

        }
    }while(game == true);

}
