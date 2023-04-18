#include <stdio.h>
// Aluno: Felipe Fernandes Brandim - 202016201
//  Objetivo: Inserir um número inteiro e apresentar na tela sua sequência lógica
//  Entrada : Número inteiro
//  Saída   : Sequência lógica respectiva
int main()
{
    int N,b,c,d,e,f;
    scanf("%d", &N);
    Sequencia(N);

    return 0;
}

void Sequencia(int N)
{
	int b,c,d,e,f;
	  for(b=1; b<=N; b++)
    {
        c=b*b;
        d=b*b*b;
        printf("%d %d %d\n",b,c,d);
        e=c+1;
        f=d+1;
        printf("%d %d %d\n",b,e,f);
    }
}
