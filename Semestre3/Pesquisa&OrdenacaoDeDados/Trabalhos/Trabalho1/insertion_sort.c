#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertionSort(int vet[], int TAM) {

    int i, x, aux;

    for (i = 1; i < TAM; i++) {
        aux = vet[i];
        for (x = i; x > 0 && aux < vet[x-1]; x--) {
            vet[x] = vet[x-1];
        }
        vet[x] = aux;
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
    insertionSort(vetor, tam);
    end = clock();

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("\n\n\n\t -> Tempo em s: %lf, Tempo em ms: %lf", difTempo, difTempo*1000);
    return 0;

}