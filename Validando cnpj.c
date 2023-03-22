#include <stdio.h>
#include <stdlib.h>

int main()
{   //##.###.###/####-##.
    printf("Digite os numeros do Cnpj da empresa : \n");
     char cnpj[14];
     fflush(stdin);
    scanf("%[^\n]",cnpj);
    printf("O cnpj digitado foi: %c%c.%c%c%c.%c%c%c/%c%c%c%c-%c%c\n",cnpj[0],cnpj[1],cnpj[2],cnpj[3],cnpj[4],cnpj[5],cnpj[6],cnpj[7],cnpj[8],cnpj[9],cnpj[10],cnpj[11],cnpj[12],cnpj[13]);

    if (ValidarCnpj(cnpj)== 1)
        printf("Cnpj valido");
    else
         printf("Cnpj invalido");


}

int ValidarCnpj(char *cnpj)
//Retorno: [1] - Se for válido | [0] - Se for inválido
{
      int somaMult, i, resto, numInt, PxN; //PxN É o peso que irá multiplicar o número. //SomaMult é o resultado do somatório dos números multiplicados pelo peso //numInt são os caracteres convertidos pra inteiro.
  char digitoV1, digitoV2;    //Digitos verificadores do cnpj
    if(strlen(cnpj) != 14) //lê o comprimento da string
        return 0;
    else if ((strcmp(cnpj,"00000000000000") == 0) || (strcmp(cnpj,"11111111111111") == 0) || (strcmp(cnpj,"22222222222222") == 0) ||
            (strcmp(cnpj,"33333333333333") == 0) || (strcmp(cnpj,"44444444444444") == 0) || (strcmp(cnpj,"55555555555555") == 0) ||
            (strcmp(cnpj,"66666666666666") == 0) || (strcmp(cnpj,"77777777777777") == 0) || (strcmp(cnpj,"88888888888888") == 0) ||
            (strcmp(cnpj,"99999999999999") == 0)) // Descartando alguns cnpjs inválidos
        return 0;
   else{

    // Calculando o digito verificador 1 ----------------------------------------------------------
        somaMult = 0; PxN = 2;
  for (i=11; i>=0; i--) {  // aqui ele vai percorrer todo o vetor cnpj
    numInt = cnpj[i] - 48;	// transforma o caracter cnpj em inteiro
                        // (48 eh a posição de '0' na tabela ASCII)
    somaMult = somaMult + (numInt * PxN); // somatório
    PxN = PxN + 1; // PxN é incrementado a cada rodagem pra aumentar e diminuir o peso
    if (PxN == 10) // quando o peso chega a 10 ele volta a valer 2
       PxN = 2;
  }
  resto = somaMult % 11; // fórmula pra descobrir o digito, resultado do somatório dividido por 11, com base no resto é decidido o número que virá
  if ((resto == 0) || (resto == 1))
     digitoV1 = '0';
  else
     digitoV1 = (11 - resto) + 48;

// calculando o digito verificador 2 ----------------------------------------------------------------
  somaMult = 0; PxN = 2;
  for (i=12; i>=0; i--) { //Mesma lógica do anterior, a única diferença é que tem um número a mais na sequência
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
