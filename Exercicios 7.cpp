#include<stdio.h>
#define NUM 10

int main(void) {
    int idade;
    float altura;
    char inicial;
    int *pi = &idade;
    float *pa = &altura;
    char *pin = &inicial;

    printf("Digite sua idade, sua altura e a inicial do seu nome :\n");
    scanf("%d %f %c", &idade, &altura, &inicial);

    printf("Digite sua idade alterada e [%d], sua altura altera e [%f] a inicial do seu nome alterada e [%c] :\n",*pi + NUM, *pa + NUM, *pin + NUM);

    return 0;
}

-

#include<stdio.h>

int main(void) {
    int a, b;
    if (&a > &b)
    {
        printf("O maior endereco pertence a vairiavel a i eh :%d \n", &a);
        return 0;
    }
    printf("O maior endereco pertence a vairiavel b i eh :%d \n", &b);
    


    return 0;
}

-

#include<stdio.h>

void troca(int *n1, int *n2) {
    int x;
    x = *n1;
    *n1 = *n2;
    *n2 = x;
}

int main(void) {
    
    int a, b;
    printf("Digite um valor para A: \n Digite um valor para B:\n");
    scanf("%d%d", &a, &b);

    troca(&a, &b);

    printf("Valores trocados por meio de uma funcao!");
    printf("O valor para A agr eh:%d \n Ovalor para B agr eh:%d\n", a, b);
    return 0;
}

-

#include<stdio.h>


int main(void) {
    

    double vetor[10] = {0,1,2,3,4,5,6,7,8,9,};
    int i;

    printf("A seguir o endereco dos 10 elemntos do vetor tipo float :\n");

    for (i = 0; i < 10; i++)
    {
        printf("%lf\n", &vetor[i]);
    }
    
    
    return 0;
}

-

#include<stdio.h>

int main(void) {

    float matirz [3] [3];
    int i, j;

    printf("A seguir o endereco dos 9 elemntos da matriz tipo float :\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Referente ao espaco [%d] [%d] o endereco :%f \n",i , j, &matirz[i][j]);
        }
        
    }
    



    return 0;
}

-

#include<stdio.h>
#include<stdlib.h>


void verificador(char v1[], char v2[], char v3[]) {
    int i, j, k = 0;
    for (i = 0; v1[i] != '\0'; i++)
    {
        for (j = 0; v2[j] != '\0'; j++)
        {
            if (v1[i] == v2[j])
            {
                v3[k++] = v2[j];
                v3[1] = '\0';
                return;
            }
            
        }
        
    }
    v3[k] = '\0';
}

int main(){

     char vetor1[101] = {0}, vetor2 [30] = {0}, vetor3 [30] = {0};

     printf("Digite uma frase maximo 100:\n");
     scanf("%100[^\n]", vetor1);

     while (getchar() != '\n');
     printf("Digite uma palavra : \n");
     scanf("%30[^\n]", vetor2);
     
     verificador(vetor1, vetor2, vetor3);

     printf("A frase eh : %s \n E a palavra eh :%s\n", vetor1, vetor2);
     printf("O que se repete eh : %s \n", vetor3);

    return 0;
}

-

#include<stdio.h>
#include<stdlib.h>

void verificador(float num, int* inteiro, float* frac){
*inteiro = num;
*frac = num - *inteiro;

}

int main(){
    float num, frac;
    int inteiro = 0;

    printf("Digite um numero real:\n");
    scanf("%f",&num);


    verificador(num, &inteiro, &frac);

    printf("A parte interia do numero eh:%d \n E a fracao eh:%f", inteiro, frac );





return 0;
}

-

Teste 
#include<stdio.h>
#include <conio.h>

int main(void){
    int n1 , n2, m;
    printf("Digite a nota 1 e 2:");
    scanf("%d%d", &n1, &n2);

    m = (n1+n2) / 2;

    if (m >= 7)
    {
    printf("Aprovado!");

    }else
    {printf("ReprovadO!");
    }


    return 0;
}
