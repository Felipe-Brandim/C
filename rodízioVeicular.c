#include <stdio.h>

// Aluno: Felipe Fernandes Brandim - 202016201
//  Objetivo: Programa que recebe uma quantidade de placas a serem consultadas, suas informações, e diga o dia em que o veiculo pode circular.
//  Entrada : inteiro representando número de testes, em seguida as informações da placa a ser consultada
//  Saída   : texto dizendo se a consulta falhou ou qual dia o carro estará autorizado a circular.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{

    int n;
    char placa[110];
    scanf("%d ", &n);

    while (n--)
    {
        scanf ("%[^\n]%*c", placa);

        if (!(strlen(placa) == 8 && isupper(placa[0]) && isupper(placa[1])
                && isupper(placa[2]) && placa[3] == '-' && isdigit(placa[4])
                && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7])))
            printf("FAILURE\n");
        else
        {
            switch (placa[7])
            {
            case '1':
            case '2':
                printf("MONDAY\n");
                break;
            case '3':
            case '4':
                printf("TUESDAY\n");
                break;
            case '5':
            case '6':
                printf("WEDNESDAY\n");
                break;
            case '7':
            case '8':
                printf("THURSDAY\n");
                break;
            case '9':
            case '0':
                printf("FRIDAY\n");
                break;
            }
        }
    }

    return 0;
}
