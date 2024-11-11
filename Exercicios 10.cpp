Aquivo Binario Ex10

#include <limits.h>  //Para poder usar o LONG_MIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *arq;
    long numeros; 
    long nums = 0;
    long maior_num = LONG_MIN;

   

    arq = fopen("numeros.dat", "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    while (fread(&numeros, sizeof(long), 1, arq) > 0) { 
           nums++;  // conta quantos numeros
        if (numeros > maior_num)
        {
            maior_num = numeros;
        }
        }
    printf("O total de numeros eh:%ld \n E o maior e : %ld", nums, maior_num);

    fclose(arq);
    return 0;
}

