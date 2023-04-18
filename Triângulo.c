#include <stdio.h>
#include <stdlib.h>
/*
*Aluno:Felipe Fernandes Brandim - 202016201
*objetivo: Leia 3 valores reais (A, B e C) e verifique se eles formam ou não um triângulo. Em caso positivo, calcule o perímetro do triângulo e apresente a mensagem
*entrada: 3 valores reais (A, B e C)
*saída: Perimetro ou Area
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
