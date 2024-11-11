Main c 

#include<stdio.h>
#include"nascimento.h"
#include"nascimento.c"


int main(void) {
    data_t data;
    int dias = 0;

    printf("Digite seu aniversario [Dia/Mes/Ano]:\n");
    scanf("%d%d%d", &data.dia, &data.mes, &data.ano);

    printf("Seu aniversario eh [%d/%d/%d]:\n", data.dia, data.mes, data.ano);

    dias = dias_de_vida(data);
    
    printf("Levando em consideracao todos os anos com 365 dias!\n Voce tem aproximadamente %d dias de vida.", dias);

    return 0;
}

Nascimento.c 

#include<stdio.h>
#include"nascimento.h"

int dias_de_vida(data_t nasc) {
    int dias = 0;
    int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i;

    dias = nasc.dia + (2024 - nasc.ano) * 365;
        
    for (i = 1; i < nasc.mes; i++) {
        dias += dias_por_mes[i];
    }

    return dias;
    
}

Nascimento H 

#ifndef NASCIMENTO_H
#define NASCIMENTO_H

typedef struct {
    int dia;
    int mes;
    int ano;
} data_t;

int dias_de_vida(data_t nasc);

#endif
