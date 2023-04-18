#include <stdio.h>
#include <math.h>
// Aluno: Felipe Fernandes Brandim - 202016201
//  Objetivo: Fazer um programa que diga qual aluno ganhou a competicao
//  Entrada : Numeros inteiros pra especificar a quantidade de casos e os valores de x e y adotados na funcao
//  Saída   : texto informando o vencedor da competicao

void main ()
{

	int x, y, rafael, beto, carlos;
	int casos;
	scanf("%d", &casos);
	while (casos--)
	{
		scanf("%d %d", &x, &y);

		if (funcaoRafael(x,y) > funcaoBeto(x,y) && funcaoRafael(x,y) > funcaoCarlos(x,y))
			printf("Rafael ganhou\n");
		else if (funcaoBeto(x,y) > funcaoRafael(x,y) && funcaoBeto(x,y) > funcaoCarlos(x,y))
			printf("Beto ganhou\n");
		else
			printf("Carlos ganhou\n");
	}
}

int funcaoRafael(int x,int y)
{   int rafael;
    rafael = pow(3*x, 2) + pow(y, 2);
            return rafael;
}

int funcaoCarlos(int x,int y)
{   int carlos;
    carlos = -100*x + pow(y, 3);
            return carlos;
}

int funcaoBeto (int x,int y)
{   int beto;
    beto = 2*(pow(x, 2)) + pow(5*y, 2);
            return beto;
}




