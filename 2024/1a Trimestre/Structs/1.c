#include <stdio.h>
#include <stdlib.h>

typedef struct chamada{
    int matricula;
    char nome[100];
    float notas[3];
    float resultado;
    char conceito;
}chamada;

void verificaConceito(chamada *aluno){

        if(aluno->resultado >= 9){
        aluno->conceito = 'A';
    }else if(aluno->resultado >= 7.5){
        aluno->conceito = 'B';
    }else if(aluno->resultado >= 6){
        aluno->conceito = 'C';
    }else if(aluno->resultado < 6){
        aluno->conceito = 'R';
    }else{
        printf("Erro na inserção de dados.\n");
    }

}

void dadosAluno(chamada *aluno){

    printf("Digite o nome do aluno: \n");
    gets(aluno->nome);
    printf("Digite a matricula do aluno: \n");
    scanf("%i", &aluno->matricula);
    for(int i = 0; i < 3; i++){
        printf("Digite a nota %i: \n", i + 1);
        scanf("%f", &aluno->notas[i]);
    }
    aluno->resultado = (aluno->notas[0] * 25 + aluno->notas[1] * 35 + aluno->notas[2] * 40) / 100;
    
}

int main()
{
    
    chamada aluno;
    dadosAluno(&aluno);
    verificaConceito(&aluno);
    system("clear");
    printf("\n| INFORMACOES DO ALUNO |\n\nAluno: %s\n\nMatricula: %i\n\nNotas: \n Nota 1: %.1f\n Nota 2: %.1f\n Nota 3: %.1f\n\nResultado Anual: %.1f\n\nConceito: %c\n", aluno.nome, aluno.matricula, aluno.notas[0], aluno.notas[1], aluno.notas[2], aluno.resultado, aluno.conceito);
} 