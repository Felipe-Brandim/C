#include <stdio.h>
#include <stdlib.h>

int main()
{   //###.###.###-##
    printf("Digite os numeros do Cpf : \n");
     char cpf[11];
     fflush(stdin);
    scanf("%[^\n]",cpf);
    printf("O cpf digitado foi: %c%c%c.%c%c%c.%c%c%c-%c%c\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],cpf[6],cpf[7],cpf[8],cpf[9],cpf[10]);

    if (validarCPF(cpf)== 1)
        printf("O CPF e valido");
    else
         printf("O Cpf e invalido");

}


int validarCPF(char *cpf)
//Retorno: [1] - Se for válido | [0] - Se for inválido
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11) // lê o comprimento da string para validá-la
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro do digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}
