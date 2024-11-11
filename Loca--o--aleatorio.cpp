Main c 

#include<stdio.h>
#include<stdlib.h>
#include "paciente.h"
#include"paciente.c"
#include<time.h>

int main(void) {
    
    srand(time(NULL));// Gera a semente  aleatoria baseada nas horas atuais 
    // gera a semente para a funcao paciente.c
    // srand tem q ser feita antes da funcao rand

    paciente_t paciente;

    alocacao_paciente(&paciente, "João Silva", 30);

    

    printf("Digite no nome do paciente :\n");
    fgets(paciente.nome, sizeof(paciente.nome), stdin);

    printf("Digite a idade do paciente : \n");
    scanf("%hd", &paciente.idade);


    printf("Exbindodo pacientes: \n Nome: %s  \n Idade :%hd anos \n.", paciente.nome, paciente.idade );

    printf(" leito:  %d\n",paciente.leito);
    printf("Presione enter para finalizar");

    return 0;
}   

Paciente C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "paciente.h"

#define andar 5
#define leitos 10
void alocacao_paciente(paciente_t *paciente, char *nome, short idade) {
    int a = 0, l = 0;
    
    strncpy(paciente->nome, nome, sizeof(paciente->nome) - 1);
    paciente->nome[ sizeof(paciente->nome) - 1] = '\0'; // acresenta o caractere nulo 
    paciente->idade = idade;

    a = 1+ rand() % andar; // cria um numero aletorio para o andar 1 a 5
    l = 1+ rand() % leitos; // cria o numero do leito  1 a 10

    paciente->leito = (a * 100) + l; // 100 a 500 + 1 a 10 = leito

    
    
}

Paciente H

#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    char nome[100];
    short idade;
    int leito;
} paciente_t;

void alocacao_paciente(paciente_t *paciente, char *nome, short idade);

#endif
