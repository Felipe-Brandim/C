#include <stdio.h>
// Aluno: Felipe Fernandes Brandim - 202016201
//  Objetivo: escrever um programa que imprima se um determinado n�mero � perfeito ou n�o.
//  Entrada : N inteiro de numeros a serem digitados, X numero inteiro que ser� testado
//  Sa�da   : texto dizendo se X � perfeito ou n�o

int main()
{
  int N, X, a, b, c, d=0;
    scanf("%d", &N);
    for(a=1; a<=N; a++){
        scanf("%d", &X);
   if (perfeito(X)==1)
            printf("%d eh perfeito\n",X);
        else
            printf("%d nao eh perfeito\n",X);
    }

    return 0;
}

int perfeito(int X)
{
   int a, b, c, d=0;
        c=X/2;
        d=0;
        for(b=1; b<=c; b++)
        {
            if(X%b==0)
                d+=b;
        }
        if(d==X)
            return 1;
        else
            return 0;
}
