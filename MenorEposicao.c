#include <stdio.h>

// Aluno: Felipe Fernandes Brandim - 202016201
//  Objetivo: Fazer um programa que receba uma sequencia numerica e diga ao final qual é o menor numero e qual sua posicao no vetor.
//  Entrada : inteiro com a quantidade de números que serao inserido e inteiros a serem comparados.
//  Saída   : Menor valor e a posicao.

int main()
{
    int N,i,posicao,menor;

    scanf("%d", &N);
    int x[N];
    for(i=0; i<N; i++)
        scanf("%d", &x[i]);
    menor=x[0];
    for(i=1; i<N; i++)
    {
        if(menor>x[i])
        {
            menor=x[i];
            posicao=i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", menor, posicao);
    return 0;
}
