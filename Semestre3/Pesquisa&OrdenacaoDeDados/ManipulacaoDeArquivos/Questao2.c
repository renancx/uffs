#include <stdio.h>
#include <stdlib.h>

void swap(int *num, int *num2) {

    int aux;
    aux = *num;
    *num = *num2;
    *num2 = aux;
}

void selectionSort(int vet[], int TAM) {
    int i, x, menor;
    for (i = 0; i < TAM-1; i++) {
        menor = i;
        for (x = i+1; x < TAM; x++) {
            if (vet[menor] > vet[x]) {
                menor = x;
            }
        }
        swap(&vet[i], &vet[menor]);
    }   
}

int main()
{
    int aux = 0;
    int numero = 0;
    int vetor[20];

    FILE *fp= fopen("numeros.txt","rt");

    if(!fp) {
        printf("Erro na abertura do arquivo 1");
        exit(1);
    }
    while(!feof(fp)) {
        fscanf(fp, "%d,", &numero);
        vetor[aux] = numero;
        aux++;
    }

    selectionSort(vetor, 20);
    fclose(fp);

    FILE *fp2 = fopen("numeros_ord.txt", "wt");

    if(!fp2) {
        printf("Erro na abertura do arquivo 2");
        exit(1);
    }
    
    for(int i=0; i<20; i++) {
        fprintf(fp2, "%d\n", vetor[i]);
    }
    fclose(fp2);
    return 0;
}