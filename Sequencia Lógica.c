#include <stdio.h>
// Aluno: Felipe Fernandes Brandim - 202016201
//  Objetivo: Inserir um n�mero inteiro e apresentar na tela sua sequ�ncia l�gica
//  Entrada : N�mero inteiro
//  Sa�da   : Sequ�ncia l�gica respectiva
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
