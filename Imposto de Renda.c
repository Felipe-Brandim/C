#include <stdio.h>
/*
*Aluno:Felipe Fernandes Brandim - 202016201
*objetivo: Informe o sal�rio de uma pessoa de Lisarb. Em seguida, calcule e mostre o valor que esta pessoa deve pagar de Imposto de Renda.
*entrada: A entrada cont�m apenas um valor de ponto flutuante, com duas casas decimais.
*sa�da: Imprima o texto "R$" seguido de um espa�o e do valor total devido de Imposto de Renda, com duas casas ap�s o ponto. Se o valor de entrada for menor ou igual a 2000, dever� ser impressa a mensagem "Isento".
*/

int main()
{
    float salario;
    scanf("%f", &salario);
    if (salario <= 2000.0)
        printf("Isento\n");
    else if (salario <= 3000.0)
        printf("R$ %.2f\n", (salario - 2000.0) * 0.08);
    else if (salario <= 4500.0)
        printf("R$ %.2f\n", 1000.0 * 0.08 + (salario - 3000.0) * 0.18);
    else
        printf("R$ %.2f\n", 1000.0 * 0.08 + 1500.0 * 0.18 + (salario - 4500.0) * 0.28);
    return 0;
}
