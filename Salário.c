#include <stdio.h>
#include <stdlib.h>
/*
*Aluno:Felipe Fernandes Brandim - 202016201
*objetivo: calcular o sal�rio de um funcion�rio
*entrada: c�digo do funcion�rio, quantidade de horas trabalhadas e o valor ganho por hora
*sa�da: mostrar o c�digo do funcion�rio e o sal�rio
*/
int main()
{
    //declara��es
    //1- Leitura de Dados
   int codigo;
   int qtdHoras;
   float valorHoras;
   float salario;

   //instru��es
   scanf("%d",&codigo);
   scanf("%d",&qtdHoras);
   scanf("%f",&valorHoras);

   // 2- calcular o sal�rio dos Funcion�rios
   salario = qtdHoras*valorHoras;
   //3- Mostrar os dados solicitados
   printf("NUMBER = %d\n",codigo);
   printf("SALARY = U$ %.2f\n", salario);
    return 0;
}
