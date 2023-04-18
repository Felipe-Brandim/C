#include <stdio.h>

// Aluno: Felipe Fernandes Brandim - 202016201
//  Objetivo: fazer um programa que receba datas e depois apresente elas em diferentes combinações
//  Entrada : datas
//  Saída   : sequencia de datas



int main() {

    char data[9];

    scanf("%s", data);

    printf("%c%c/%c%c/%c%c\n", data[3], data[4], data[0], data[1], data[6], data[7]);
    printf("%c%c/%c%c/%c%c\n", data[6], data[7], data[3], data[4], data[0], data[1]);
    printf("%c%c-%c%c-%c%c\n", data[0], data[1], data[3], data[4], data[6], data[7]);


    return 0;
}
