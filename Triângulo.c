#include <stdio.h>
#include <stdlib.h>
/*
*Aluno:Felipe Fernandes Brandim - 202016201
*objetivo: Leia 3 valores reais (A, B e C) e verifique se eles formam ou n�o um tri�ngulo. Em caso positivo, calcule o per�metro do tri�ngulo e apresente a mensagem
*entrada: 3 valores reais (A, B e C)
*sa�da: Perimetro ou Area
*/
int main()
{
    double A, B, C;

    scanf("%lf %lf %lf", &A, &B, &C);

    if (A < B+C && B < A+C && C < A+B)
        printf("Perimetro = %.1lf\n", A+B+C);

    else
        printf("Area = %.1lf\n", (A+B)*C/2.0);

    return 0;
}
