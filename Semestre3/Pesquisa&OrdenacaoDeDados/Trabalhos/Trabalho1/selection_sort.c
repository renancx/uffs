#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

int main() {

    int op = 0, tam = 0;

    printf("Defina o tamanho do vetor:\n");
    printf("-10000\n-50000\n-100000\n");
    printf("Digite o numero: ");
    scanf("%d", &tam);

    int vetor[tam];

    clock_t start, end;
    srand(time(NULL));
    printf("\n");


    //preenche o vetor
    printf("Escolha a ordenacao:\n");
    printf("1 - aleatorio\n2 - crescente\n3 - decrescente\n");
    printf("Opcao: ");
    scanf("%d", &op);

    if (op == 1) {
        for (int i = 0; i < tam; i++) {
            vetor[i] = rand();
        }
    }
    else if (op == 2) {
        for (int i = 0;i < tam; i++) 
            vetor[i] = i;
    }
    else if (op == 3) {
        for (int i = 0;i < tam;i++)
            vetor[i] = tam - i - 1;
    }

    start = clock();
    selectionSort(vetor, tam);
    end = clock();

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("\n -> Tempo em s: %lf, Tempo em ms: %lf", difTempo, difTempo*1000);
    return 0;

}