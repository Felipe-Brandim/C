#include <stdio.h>
#include <stdlib.h>
/*
*Aluno:Felipe Fernandes Brandim - 202016201
*objetivo: calcular o salário de um funcionário
*entrada: código do funcionário, quantidade de horas trabalhadas e o valor ganho por hora
*saída: mostrar o código do funcionário e o salário
*/
int main()
{
    //declarações
    //1- Leitura de Dados
   int codigo;
   int qtdHoras;
   float valorHoras;
   float salario;

   //instruções
   scanf("%d",&codigo);
   scanf("%d",&qtdHoras);
   scanf("%f",&valorHoras);

   // 2- calcular o salário dos Funcionários
   salario = qtdHoras*valorHoras;
   //3- Mostrar os dados solicitados
   printf("NUMBER = %d\n",codigo);
   printf("SALARY = U$ %.2f\n", salario);
    return 0;
}
