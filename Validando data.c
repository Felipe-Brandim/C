#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#define TAMData 10
typedef struct{
int dia,mes,ano;

}Data;

int main()
{
     setlocale(LC_ALL,"Portuguese");

    Data dataC;



    printf("Informe uma data dia/mes/ano\n");
    scanf("%d/%d/%d", &dataC.dia,&dataC.mes,&dataC.ano);

    if (ValidarData (dataC.dia, dataC.mes, dataC.ano)==0)
    {
        printf("Data valida\n");
        printf("Data Digitada: %d/%d/%d",dataC.dia,dataC.mes,dataC.ano);


    }
    else
    {
        printf("Data Invalida\n");
    }

    /*printf("Digite a data de ínicio da contrato dia/mês/ano: ");
                            fflush(stdin);
                            scanf("%[^\n]",caContrato.data_inicio_contrato);
                            if(ValidarData(caContrato.data_inicio_contrato)==1)
                            {
                               printf("Data aceita!\n");}*/
}


//Retorno: [1] - Se for válido | [0] - Se for inválido
int ValidarData (int dia, int mes, int ano)
{
    int resto;
     //invalidações comuns
        if ((dia>31) || (dia<1) || (ano>9999) || (ano<0000))
        {
            return 1;
        }
    //Verifica os meses que tem 31 dias
    if ((mes==01) || (mes==03) || (mes==05) || (mes==07) || (mes==8) || (mes==10) || (mes==12))
    {
        //invalidações comuns
        if ((dia>31) || (dia<1) || (ano>9999) || (ano<0000))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        //Verifica os meses que tem 30 dias
        if ((mes==04) || (mes==06) || (mes==9) || (mes==11))
        {
            //Se o dia for maior que 30 a data é inválida
            if ((dia>30))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (mes==2)
            {
                //Se o resto for 0, isso indica que o ano é bisexto, sendo assim o mês de Fevereiro terá 29 dias
                resto=(ano%4);
                if (resto==0)
                {
                    //Se o dia for maior que 29 a data é inválida
                    if ((dia>29))
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                //Se não for ano bisexto, o mês de Fevereiro terá 28 dias
                else
                {
                    //Se o dia for maior que 28 a data é inválida
                    if ((dia>28))
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            //Se o mês não estiver entre 1 e 12 a data é inválida
            else
            {
                return 1;
            }
        }
    }
}
