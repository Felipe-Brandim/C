#include <stdio.h>
// Aluno: Felipe Fernandes Brandim - 202016201
//  Objetivo: Escreva um programa para ler as coordenadas (X,Y) de uma quantidade indeterminada de pontos no sistema cartesiano.
//  Entrada : números inteiros representando coordenadas
//  Saída   : texto informando qual o quadrante.
int main()
{
    int x, y;

    scanf("%d %d", &x, &y);
    while (x != 0 && y != 0)
    {
        if (Quadrante(x,y)==1)
        {
            printf("primeiro\n");
        }
        else if (Quadrante(x,y)==2)
        {
            printf("segundo\n");
        }
        else if (Quadrante(x,y)==3)
        {
            printf("terceiro\n");
        }
        else
        {
            printf("quarto\n");
        }
        scanf("%d %d", &x, &y);
    }


    return 0;
}

int Quadrante(int x,int y)
{
    while (x != 0 && y != 0)
    {
        if (x > 0 && y > 0)
        {

            return 1;
        }
        else if (x < 0 && y > 0)
        {

            return 2;
        }
        else if (x < 0 && y < 0)
        {

            return 3;
        }
        else
        {

            return 4;
        }

    }

}
