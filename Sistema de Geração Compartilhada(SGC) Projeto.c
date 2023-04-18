#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<locale.h>
#define Nnome 40

// Aluno: Felipe Fernandes Brandim - 202016201
//  Objetivo:
// Entrada:
//  Sa�da :

typedef struct{
    char identificacao[14];
    char nome[Nnome];

}Consumidor;
typedef struct{
int dia,mes,ano;

}Data;
typedef struct{
    char cnpj[14];
    char nomeU[40];
    Data data_inicio_operacao;
    double potencia_estimada;
}Usina;

typedef struct{
    char cnpj_usina[14];
    Consumidor Id_consumidor;
    double potencia_contratada;
    Data data_inicio_contrato;
}Contrato;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int opcao,n;
    opcao=0;

    while(opcao!=8){
    Menu();
    scanf("%d",&opcao);
    switch(opcao)
    {
    case 1:
        //Cadastrar usina
        system("cls");
        CadUsina();
        getch();
        break;
    case 2:
        //cadastrar consumidor
         system("cls");
         CadConsumidor();
        getch();
        break;
    case 3:
        //cadastrar contrato entre consumidor e usina
         system("cls");
        CadContrato();
        getch();
        break;
    case 4:
        //consultar usina cadastrada
         system("cls");
        ConsUsina();
        getch();
        break;
    case 5:
        //consultar consumidor cadastrado
         system("cls");
        printf("Opcao indisponivel\n");

        getch();
        break;
    case 6:
        //Excluir usina
         system("cls");
        printf("Opcao indisponivel\n");

        getch();
        break;
    case 7:
        //Excluir consumidor
         system("cls");
        printf("Opcao indisponivel\n\n");

        getch();
        break;
    case 8:
        //Encerrar programa
         system("cls");
        printf("Obrigado, e ate a proxima!");

        getch();
        break;
    default:
         system("cls");
        printf("Erro,o menu so atende os numeros de 1 a 8. \n");
       getch();
    }

    }
    return 0;
}

//----------------------------------------------------------------
void Menu()
{
    printf("-----------------------------------\n");
    printf("Menu de opcoes:\n");
    printf("1) Cadastrar Usina\n");
    printf("2) Cadastrar Consumidor\n");
    printf("3) Cadastrar Contrato entre Consumidor e Usina\n");
    printf("4) Consultar Usina Cadastrada\n");
    printf("5) Consultar Consumidor Cadastrado\n");
    printf("6) Excluir Usina\n");
    printf("7) Excluir Consumidor\n");
    printf("8) Encerrar Programa\n");
    printf("-----------------------------------\n");

}
//-----------------------------------------------------------------(revisado livre de erros)
void CadContrato()
{
    Contrato caContrato;

    printf("Digite o CNPJ da Usina\n");
    fflush(stdin);
  scanf("%[^\n]",caContrato.cnpj_usina);
     if(strlen(caContrato.cnpj_usina) == 14)
    {
           if (ValidarCnpj(caContrato.cnpj_usina)==1) // Se for validado o cnpj  ele printa e pede id do consumidor/ se for inv�lido ele cai no else
            {
                  printf("Cnpj aceito!\n");
                  printf("Digite a identifica��o do consumidor (Cpf ou Cnpj)\n");
                fflush(stdin);
                scanf("%[^\n]",caContrato.Id_consumidor.identificacao);
                    if(strlen(caContrato.Id_consumidor.identificacao) == 14) // v� se � um cnpj
                    {
                        if (ValidarCnpj(caContrato.Id_consumidor.identificacao)==1) // valida o cnpj do consumidor
                        {
                            printf("Cnpj aceito!\n");
                            printf("Cadastre agora um nome: \n");
                            fflush(stdin);
                            scanf("%[^\n]",caContrato.Id_consumidor.nome); // Nome cadastrado
                            // Processamento da data
                            printf("Digite a data de �nicio da contrato dia/m�s/ano: ");
                            fflush(stdin);
                            scanf("%d/%d/%d",&caContrato.data_inicio_contrato.dia,&caContrato.data_inicio_contrato.mes,&caContrato.data_inicio_contrato.ano);

                            if (ValidarData (caContrato.data_inicio_contrato.dia,caContrato.data_inicio_contrato.mes, caContrato.data_inicio_contrato.ano)==0)
                            {
                               printf("Data aceita!\n");
                               printf("Cadastre agora a pot�ncia contratada da Usina: \n");
                                fflush(stdin);
                                scanf("%lf",&caContrato.potencia_contratada);
                                if(caContrato.potencia_contratada>0)
                                {
                                //---------------- Abrindo para gravar no arquivo----
                                                      FILE*fc;
                                                fc=fopen("Contrato.txt","ab");
                                                if(fc==NULL){
                                                    printf("Erro na abertura do arquivo!\n");
                                                    system("pause");
                                                    exit(1);
                                                }else{
                                                    fwrite(&caContrato,sizeof(Contrato),1,fc);
                                                }fclose(fc);
                                //-----------------------Confirma��o de grava��o---------
                                      system("cls");

                                    printf("---CADASTRADO!---\n");
                                //----------------------------------------------------
                                }else{system("cls");
                                    printf("---N�O CADASTRADO!---\n");
                                    printf("Pot�ncia Inv�lida!\n");
                                        }
                                //------------------------------------------------------
                            }else{system("cls");
                                printf("---N�O CADASTRADO!---\n");
                                printf("Data inv�lida!\n");
                                }

                         }else{printf("CNPJ inv�lido");}
                        // Caso CPF
                    } else if (strlen(caContrato.Id_consumidor.identificacao)==11) // v� se � um cpf
                        {
                            if (ValidarCPF(caContrato.Id_consumidor.identificacao)==1)
                               {
                                printf("Cpf aceito!\n");
                                printf("Cadastre agora um nome: \n");
                                fflush(stdin);
                                 scanf("%[^\n]",caContrato.Id_consumidor.nome);

                            // Processamento da data
                            printf("Digite a data de �nicio da contrato dia/m�s/ano: ");
                            fflush(stdin);
                            scanf("%d/%d/%d",&caContrato.data_inicio_contrato.dia,&caContrato.data_inicio_contrato.mes,&caContrato.data_inicio_contrato.ano);

                            if (ValidarData (caContrato.data_inicio_contrato.dia,caContrato.data_inicio_contrato.mes, caContrato.data_inicio_contrato.ano)==0)
                            {
                               printf("Data aceita!\n");
                               printf("Cadastre agora a pot�ncia contratada da Usina: \n");
                                fflush(stdin);
                                scanf("%lf",&caContrato.potencia_contratada);
                                if(caContrato.potencia_contratada>0)
                                {
                                //---------------- Abrindo para gravar no arquivo----
                                                      FILE*fc;
                                                fc=fopen("Contrato.txt","ab");
                                                if(fc==NULL){
                                                    printf("Erro na abertura do arquivo!\n");
                                                    system("pause");
                                                    exit(1);
                                                }else{
                                                    fwrite(&caContrato,sizeof(Contrato),1,fc);
                                                }fclose(fc);
                                //-----------------------Confirma��o de grava��o---------
                                      system("cls");

                                    printf("---CADASTRADO!---\n");
                                //----------------------------------------------------
                                }else{system("cls");
                                    printf("---N�O CADASTRADO!---\n");
                                    printf("Pot�ncia Inv�lida!\n");
                                        }
                                //------------------------------------------------------
                            }else{system("cls");
                                printf("---N�O CADASTRADO!---\n");
                                printf("Data inv�lida!\n");
                                }

                                } else {printf("CPF inv�lido!");}
                        }else{system("cls");
                                printf("---N�O CADASTRADO!---\n");
                                printf("Identifica��o de consumidor inv�lida,s� s�o aceitos CPF ou CNPJ\n");
                                }

            }else{
            system("cls");
            printf("---N�O CADASTRADO!---\n");
            printf("CNPJ inv�lido!\n");
                }

    }else {system("cls");
            printf("---N�O CADASTRADO!---\n");
            printf("CNPJ inv�lido pelo n�mero de caracteres\n");
            }

}
//------------------------------------------------------------------(revisado livre de erros)
void CadUsina()

{
 Usina caUsina;
   printf("Digite o CNPJ:\n");
    fflush(stdin);
  scanf("%[^\n]",caUsina.cnpj);
     if(strlen(caUsina.cnpj) == 14)
    {
           if (ValidarCnpj(caUsina.cnpj)==1) // Se for validado o cnpj ele printa e pede o nome da usina
            {
                  printf("Cnpj aceito!\n");
                  printf("Digite o nome da Usina:\n");
                fflush(stdin);
                scanf("%[^\n]",caUsina.nomeU);

                // Processamento da data
                            printf("Digite a data de �nicio da opera��o dia/m�s/ano: ");
                            fflush(stdin);
                            scanf("%d/%d/%d",&caUsina.data_inicio_operacao.dia,&caUsina.data_inicio_operacao.mes,&caUsina.data_inicio_operacao.ano);

                            if (ValidarData(caUsina.data_inicio_operacao.dia,caUsina.data_inicio_operacao.mes,caUsina.data_inicio_operacao.ano)==0)
                            {
                               printf("Data aceita!\n");
                               printf("Cadastre agora a pot�ncia estimada da Usina: \n");
                                fflush(stdin);
                                scanf("%lf",&caUsina.potencia_estimada);
                                if(caUsina.potencia_estimada>0)
                                {
                                //---------------- Abrindo para gravar no arquivo----
                                                      FILE*fc;
                                                fc=fopen("Usina.txt","ab");
                                                if(fc==NULL){
                                                    printf("Erro na abertura do arquivo!\n");
                                                    system("pause");
                                                    exit(1);
                                                }else{
                                                    fwrite(&caUsina,sizeof(Usina),1,fc);
                                                }fclose(fc);
                                //-----------------------Confirma��o de grava��o---------
                                      system("cls");

                                    printf("---CADASTRADO!---\n");
                                //----------------------------------------------------
                                }else{system("cls");
                                    printf("---N�O CADASTRADO!---\n");
                                    printf("Pot�ncia Inv�lida!\n");
                                        }
                                //------------------------------------------------------
                            }else{system("cls");
                                printf("---N�O CADASTRADO!---\n");
                                printf("Data inv�lida!\n");
                                }

                         }else{printf("---N�O CADASTRADO!---\n");
                                printf("CNPJ inv�lido\n");}


    }else{system("cls");
            printf("---N�O CADASTRADO!---\n");
            printf("CNPJ inv�lido pelo n�mero de caracteres\n");
            }
}


//------------------------------------------------------------------(revisado livre de erros)

 void CadConsumidor()
{
  Consumidor CaConsumidor;

  printf("Digite a identifica��o do consumidor (Cpf ou Cnpj)\n");
  fflush(stdin);
  scanf("%[^\n]",CaConsumidor.identificacao);
    if(strlen(CaConsumidor.identificacao) == 14) // v� se tem comprimento de um cnpj

          if (ValidarCnpj(CaConsumidor.identificacao)==1) // valida o cnpj do consumidor
                {
                    printf("Cnpj aceito!\n");
                    printf("Cadastre agora um nome: \n");
                    fflush(stdin);
                    scanf("%[^\n]",CaConsumidor.nome); // Nome cadastrado

                     //---------------- Abrindo para gravar no arquivo----
                      FILE*f;
                f=fopen("consumidor.txt","ab");
                if(f==NULL){
                    printf("Erro na abertura do arquivo!\n");
                    system("pause");
                    exit(1);
                }else{
                    fwrite(&CaConsumidor,sizeof(Consumidor),1,f);
                }fclose(f);
                    //----------------- Gravado no arquivo----
                      system("cls");
                      printf("---CADASTRADO!---\n");
                      printf("O cnpj digitado foi: %c%c.%c%c%c.%c%c%c/%c%c%c%c-%c%c\n",CaConsumidor.identificacao[0],CaConsumidor.identificacao[1],CaConsumidor.identificacao[2],CaConsumidor.identificacao[3],CaConsumidor.identificacao[4],CaConsumidor.identificacao[5],CaConsumidor.identificacao[6],CaConsumidor.identificacao[7],CaConsumidor.identificacao[8],CaConsumidor.identificacao[9],CaConsumidor.identificacao[10],CaConsumidor.identificacao[11],CaConsumidor.identificacao[12],CaConsumidor.identificacao[13]);
                    printf("O Nome digitado foi: %s\n",CaConsumidor.nome);
                            }else{system("cls");
                                printf("---N�O CADASTRADO!---\n");
                            printf("CNPJ Inv�lido\n");}


   else if(strlen(CaConsumidor.identificacao) == 11) // v� se tem comprimento de um cpf
        {
          if (ValidarCPF(CaConsumidor.identificacao)==1) // valida o cpf do consumidor
                {
                    printf("Cpf aceito!\n");
                    printf("Cadastre agora um nome: \n");
                    fflush(stdin);
                    scanf("%[^\n]",CaConsumidor.nome); // Nome cadastrado
         //---------------- Abrindo para gravar no arquivo----
                      FILE*f;
                f=fopen("Consumidor.txt","ab");
                if(f==NULL){
                    printf("Erro na abertura do arquivo!\n");
                    system("pause");
                    exit(1);
                }else{
                    fwrite(&CaConsumidor,sizeof(Consumidor),1,f);
                }fclose(f);
                    //----------------- Gravado no arquivo----
                      system("cls");
                      printf("---CADASTRADO!---\n");
                     printf("O cpf digitado foi: %c%c%c.%c%c%c.%c%c%c-%c%c\n",CaConsumidor.identificacao[0],CaConsumidor.identificacao[1],CaConsumidor.identificacao[2],CaConsumidor.identificacao[3],CaConsumidor.identificacao[4],CaConsumidor.identificacao[5],CaConsumidor.identificacao[6],CaConsumidor.identificacao[7],CaConsumidor.identificacao[8],CaConsumidor.identificacao[9],CaConsumidor.identificacao[10]);
                    printf("O nome digitado foi: %s\n",CaConsumidor.nome);
                }
               else
               {
                    system("cls");
                    printf("---N�O CADASTRADO!---\n");
                printf("CPF Inv�lido!\n");
               }
        }else {system("cls");
        printf("---N�O CADASTRADO!---\n");
    printf("Identifica��o de consumidor inv�lida,s� s�o aceitos CPF ou CNPJ!\n");}

}


//---------------------------------------------------------------------(funcionando a leitura)
void ConsUsina()
{
    FILE*fcu;
    Usina caUsina;

    fcu = fopen("Usina.txt","rb"); // R- Read binary
    system("cls");
    if (fcu == NULL){
        printf("Problemas na abertura do arquivo!\n");
    }else{
        while(fread(&caUsina,sizeof(Usina),1,fcu)==1){
            printf("CNPJ da Usina: %c%c.%c%c%c.%c%c%c/%c%c%c%c-%c%c\n",caUsina.cnpj[0],caUsina.cnpj[1],caUsina.cnpj[2],caUsina.cnpj[3],caUsina.cnpj[4],caUsina.cnpj[5],caUsina.cnpj[6],caUsina.cnpj[7],caUsina.cnpj[8],caUsina.cnpj[9],caUsina.cnpj[10],caUsina.cnpj[11],caUsina.cnpj[12],caUsina.cnpj[13]);
            printf("Nome da Usina: %s\n",caUsina.nomeU);
            printf("Data de in�cio da Opera��o: %d/%d/%d\n",caUsina.data_inicio_operacao.dia,caUsina.data_inicio_operacao.mes,caUsina.data_inicio_operacao.ano);
            printf("Pot�ncia estimada da Usina: %.2lf\n",caUsina.potencia_estimada);
            printf("------------------------------------------------------------\n\n");
        }
    }
    fclose(fcu);
    getch();

}

//-----------------------------------------------------------------------

// chama primeiro (string- limpeza de buffer)
void limpar_entrada()
{
     char c;
     while ((c = getchar()) != '\n' && c != EOF) {}
}
//----------------------------------------------------------------
int ValidarCnpj(char *cnpj)
//Retorno: [1] - Se for v�lido | [0] - Se for inv�lido
{
      int somaMult, i, resto, numInt, PxN; //PxN � o peso que ir� multiplicar o n�mero. //SomaMult � o resultado do somat�rio dos n�meros multiplicados pelo peso //numInt s�o os caracteres convertidos pra inteiro.
  char digitoV1, digitoV2;    //Digitos verificadores do cnpj
    if(strlen(cnpj) != 14) //l� o comprimento da string
        return 0;
    else if ((strcmp(cnpj,"00000000000000") == 0) || (strcmp(cnpj,"11111111111111") == 0) || (strcmp(cnpj,"22222222222222") == 0) ||
            (strcmp(cnpj,"33333333333333") == 0) || (strcmp(cnpj,"44444444444444") == 0) || (strcmp(cnpj,"55555555555555") == 0) ||
            (strcmp(cnpj,"66666666666666") == 0) || (strcmp(cnpj,"77777777777777") == 0) || (strcmp(cnpj,"88888888888888") == 0) ||
            (strcmp(cnpj,"99999999999999") == 0)) // Descartando alguns cnpjs inv�lidos
        return 0;
   else{

    // Calculando o digito verificador 1 ----------------------------------------------------------
        somaMult = 0; PxN = 2;
  for (i=11; i>=0; i--) {  // aqui ele vai percorrer todo o vetor cnpj
    numInt = cnpj[i] - 48;	// transforma o caracter cnpj em inteiro
                        // (48 eh a posi��o de '0' na tabela ASCII)
    somaMult = somaMult + (numInt * PxN); // somat�rio
    PxN = PxN + 1; // PxN � incrementado a cada rodagem pra aumentar e diminuir o peso
    if (PxN == 10) // quando o peso chega a 10 ele volta a valer 2
       PxN = 2;
  }
  resto = somaMult % 11; // f�rmula pra descobrir o digito, resultado do somat�rio dividido por 11, com base no resto � decidido o n�mero que vir�
  if ((resto == 0) || (resto == 1))
     digitoV1 = '0';
  else
     digitoV1 = (11 - resto) + 48;

// calculando o digito verificador 2 ----------------------------------------------------------------
  somaMult = 0; PxN = 2;
  for (i=12; i>=0; i--) { //Mesma l�gica do anterior, a �nica diferen�a � que tem um n�mero a mais na sequ�ncia
    numInt = cnpj[i] - 48;
    somaMult = somaMult + (numInt * PxN);
    PxN = PxN + 1;
    if (PxN == 10)
       PxN = 2;
  }
  resto = somaMult % 11;
  if ((resto == 0) || (resto == 1))
     digitoV2 = '0';
  else
     digitoV2 = (11 - resto) + 48; //Uma vez definido o digito V2

// Comparando os digitos informados com os digitos calculados --------------------------------------
  if ((digitoV1 == cnpj[12]) && (digitoV2 == cnpj[13]))
     return 1; //verdadeiro
  else
     return 0; // falso
}

}
//----------------------------------------------------------------------
int ValidarCPF(char *cpf)
//Retorno: [1] - Se for v�lido | [0] - Se for inv�lido
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11) // l� o comprimento da string para valid�-la
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os n�meros iguais ele � inv�lido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os n�meros de 10 a 2 e soma os resultados dentro do digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 n�o for o mesmo que o da valida��o CPF � inv�lido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os n�meros de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 n�o for o mesmo que o da valida��o CPF � inv�lido
        }
    }
    return 1;
}

//------------------------------------------------------------------------------------

//Retorno: [1] - Se for v�lido | [0] - Se for inv�lido
int ValidarData (int dia, int mes, int ano)

{
    int resto;
     //invalida��es comuns
        if ((dia>31) || (dia<1) || (ano>9999) || (ano<0000))
        {
            return 1;
        }
    //Verifica os meses que tem 31 dias
    if ((mes==01) || (mes==03) || (mes==05) || (mes==07) || (mes==8) || (mes==10) || (mes==12))
    {
        //invalida��es comuns
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
            //Se o dia for maior que 30 a data � inv�lida
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
                //Se o resto for 0, isso indica que o ano � bisexto, sendo assim o m�s de Fevereiro ter� 29 dias
                resto=(ano%4);
                if (resto==0)
                {
                    //Se o dia for maior que 29 a data � inv�lida
                    if ((dia>29))
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                //Se n�o for ano bisexto, o m�s de Fevereiro ter� 28 dias
                else
                {
                    //Se o dia for maior que 28 a data � inv�lida
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
            //Se o m�s n�o estiver entre 1 e 12 a data � inv�lida
            else
            {
                return 1;
            }
        }
    }
}
