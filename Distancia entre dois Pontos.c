#include <stdio.h>
#include <stdlib.h>
#include<math.h>
/*
*Aluno:Felipe Fernandes Brandim - 202016201
*S�ntese: Escreva um algoritmo para calcular e mostrar a dist�ncia entre dois pontos p1 (x1, y1) e p2 (x2, y2) no plano.
*objetivo: Receber coordenadas de dois pontos e retornar a dist�ncia
*entrada: quatro valores reais correspondentes as coordenadas de dois pontos
*sa�da: Distancia
*/
int main()
{
    //declara��es
    //1- Leitura de Dados

   double x1,y1,x2,y2,distancia;


   //instru��es
   scanf("%lf",&x1);
   scanf("%lf",&y1);
   scanf("%lf",&x2);
    scanf("%lf",&y2);
   // 2- calcular a distancia
   distancia= sqrt(pow((x2-x1),2)+ pow( (y2-y1),2));
   //3- Mostrar os dados solicitados

   printf("%.4lf\n",distancia);
    return 0;
}
