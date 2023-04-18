#include <stdio.h>

// Aluno: Felipe Fernandes Brandim - 202016201
//  Objetivo:
//  Entrada : Numero inteiro representando a quantidade de casos, inteiro de pessoas na turma, inteiro representado as médias
//  Saída   : Percentual de estudantes acima da media

int main()
{

    int C, N, mediaEstudante;
    double media;

    scanf("%i", &C);

    while (C--)
    {

        scanf("%i", &N);

        int alunos[N];
        int i = 0;
        media = 0;
        mediaEstudante = 0;

        while (i < N)
        {
            scanf("%d", &alunos[i]);
            media += alunos[i++];
        }

        media /= N;
        i = 0;

        while (i < N)
        {

            if (alunos[i] > media)
                mediaEstudante++;

            i++;
        }

        printf("%.3lf%c\n", 100 * mediaEstudante / (double) N,'%');

    }

    return 0;
}
