#include <stdio.h>
#include <stdlib.h>
#include<math.h>
/*
*Aluno:Felipe Fernandes Brandim - 202016201
*objetivo: Leia um valor inteiro, que é o tempo de duração em segundos de um determinado evento e informe-o no formato horas:minutos:segundos.
*entrada: valor inteiro N (segundos)
*saída: Segundos, convertido para horas:minutos:segundo.
*/
int main()
{
    int N, H, M;

    scanf("%i", &N);

    H = N / 3600;
    N -= H * 3600;
    M = N / 60;
    N -= M * 60;

    printf("%i:%i:%i\n", H, M, N);

    return 0;
}

