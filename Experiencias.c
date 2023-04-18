#include <stdio.h>
// Aluno: Felipe Fernandes Brandim - 202016201
//Objetivo:
//Entrada: Número inteiro de experiências, número inteiro de animais utilizados e o respectivo caracter que representa cada animal.
//Saída: Total de animais em inteiro e percentuais em real.



int main(){
    int n, ratos, sapos, coelhos, qtdcobaias, total;
    char tipo;
    double pratos, psapos, pcoelhos;


    scanf("%d", &n);

	ratos = 0;
	sapos = 0;
	coelhos = 0;

    for (int i=0; i<n; i++) {

        scanf("%d", &qtdcobaias);

        scanf(" %c", &tipo);

        if (tipo == 'R') {
            ratos = ratos + qtdcobaias;
        }
        else if (tipo == 'S') {
            sapos = sapos + qtdcobaias;
        }
        else {
            coelhos = coelhos + qtdcobaias;
        }
    }

    total = ratos + sapos + coelhos;
    pcoelhos = ((double)coelhos / total) * 100.0;
    pratos = ((double)ratos / total) * 100.0;
    psapos = ((double)sapos / total) * 100.0;

	printf("Total: %d cobaias\n", total);
	total_experiencias(coelhos,ratos,sapos);
    printf("Percentual de coelhos: %.2lf %%\n", pcoelhos);
    printf("Percentual de ratos: %.2lf %%\n", pratos);
    printf("Percentual de sapos: %.2lf %%\n", psapos);

    return 0;
}

void total_experiencias(int coelhos,int ratos,int sapos)
{
	printf("Total de coelhos: %d\n", coelhos);
	printf("Total de ratos: %d\n", ratos);
	printf("Total de sapos: %d\n", sapos);
}
