#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pediatria.h"


paciente_t * primeiro_paciente(char *nome, int idade, float peso, float altura, char genero) {
    paciente_t *novo = (paciente_t *)malloc(sizeof(paciente_t));
    if (novo == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->peso = peso;
    novo->altura = altura;
    novo->genero = genero;
    novo->prox = NULL;
    return novo;
}


void novo_paciente(paciente_t *primeiro, char *nome, int idade, float peso, float altura, char genero) {
    paciente_t *novo = primeiro_paciente(nome, idade, peso, altura, genero);
    paciente_t *atual = primeiro;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
}


IMCInfantil calcula_imc(paciente_t *crianca) {
    float imc = crianca->peso / (crianca->altura * crianca->altura);
    IMCInfantil classificacao;

   
    if (crianca->genero == 'M') {  // Masculino
        if (crianca->idade == 6) {
            if (imc < 14.5) classificacao = ABAIXO;
            else if (imc < 17.5) classificacao = NORMAL;
            else if (imc < 19.5) classificacao = SOBREPESO;
            else classificacao = OBESIDADE;
        }
       
    } else if (crianca->genero == 'F') {  // Feminino
        if (crianca->idade == 6) {
            if (imc < 14.0) classificacao = ABAIXO;
            else if (imc < 17.0) classificacao = NORMAL;
            else if (imc < 19.0) classificacao = SOBREPESO;
            else classificacao = OBESIDADE;
        }
        // Outras idades para gênero feminino aqui...
    }
    
    return classificacao;
}


void exibir_classificacao(IMCInfantil classificacao) {
    switch (classificacao) {
        case ABAIXO:
            printf("Abaixo do peso\n");
            break;
        case NORMAL:
            printf("Peso normal\n");
            break;
        case SOBREPESO:
            printf("Sobrepeso\n");
            break;
        case OBESIDADE:
            printf("Obesidade\n");
            break;
    }
}

int main() {
    paciente_t *lista = primeiro_paciente("João", 6, 20.0, 1.10, 'M');
    novo_paciente(lista, "Ana", 6, 18.0, 1.05, 'F');
    
    paciente_t *atual = lista;
    while (atual != NULL) {
        printf("Paciente: %s, Idade: %d\n", atual->nome, atual->idade);
        IMCInfantil classificacao = calcula_imc(atual);
        exibir_classificacao(classificacao);
        atual = atual->prox;
    }

    return 0;
}
