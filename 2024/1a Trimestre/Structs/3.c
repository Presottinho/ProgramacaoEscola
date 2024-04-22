#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct dma{
    int dia; // dia do mes
    int mes; // mes
    int ano; // ano
    int feriado; // 0 – não é feriado, 1 - feriado
    char efemeride[50]; // qual motivo do feriado
}dma;

void inserirData(dma *calendar, int *maxDia){

    printf("Insira o ano: ");
    calendar->ano = 0;
    while(calendar->ano <= 1900 || calendar->ano >= 2101){
        scanf("%i", &calendar->ano);    
    }
    printf("Insira o mes: ");
    calendar->mes = 0;
    while(calendar->mes <= 0 || calendar->mes >= 13){
        scanf("%i", &calendar->mes);
    }
    printf("Insira o dia: ");
    calendar->dia = 0; 
    while(calendar->dia < 1 || calendar->dia > maxDia + (calendar->mes - 1)){
        scanf("%i", &calendar->dia); 
    }
    printf("E feriado(0 para nao e 1 para sim): ");
    calendar->feriado = -1;
    while(calendar->feriado < 0 || calendar->feriado > 1){
        scanf("%i", &calendar->feriado);
    }
    if(calendar->feriado == 1){
        printf("Qual o motivo do feriado? ");
        scanf("%s", &calendar->efemeride);
    }

}

void comparadorDatas(dma *data1, dma *data2){
    
}

int main(){
    char meses[12][3] = {"jan", "fev", "mar", "abr", "mai", "jun", "jul", "ago", "set", "out", "nov", "dez"};
    int maxDia[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Primeira data\n");
    dma data1;
    inserirData(&data1, &maxDia); 

    printf("Segunda data\n");
    dma data2;
    inserirData(&data2, &maxDia);

    comparadorDatas(&data1, &data2);

}