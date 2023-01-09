#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *num, int *num2) {
    int aux;
    aux = *num;
    *num = *num2;
    *num2 = aux;
}

void createHeap(int vet[], int tam, int start) {

    int bigger, left, right;
    bigger = start;
    left = 2 * start + 1;
    right = 2 * start + 2;
    if (left < tam && vet[left]> vet[bigger]){ ///colocamos vet[bigger] para funcionar
        bigger = left;
    }
    if (right < tam && vet[right] > vet[bigger]){
        bigger = right;
    }
    if (bigger != start) {
        swap(&vet[start], &vet[bigger]);
        createHeap(vet, tam, bigger); 
    }
}

void heapSort(int vet[], int tam) {

    int k;
    for (k = tam / 2 - 1; k >= 0; k--) {
        createHeap(vet, tam, k);
    }
    for (k = tam - 1; k >= 0; k--){
        swap(&vet[0], &vet[k]);
        createHeap(vet, k, 0);
    }
}

int main() {

    int op = 0, tam=0, x = 0;

    printf("Defina o tamanho do vetor:\n");
    printf("-10000\n-50000\n-100000\n");
    printf("Digite o numero: ");
    scanf("%d", &tam);

    int vetor[tam];   

    clock_t start, end;
    srand(time(NULL));

    //preenche o vetor
    printf("Escolha a ordenacao:\n");
    printf("1 - aleatorio\n2 - crescente\n3 - decrescente\n");
    printf("Opcao: ");
    scanf("%d", &op);

    if (op == 1) {
        for (x = 0; x < tam; x++) {
            vetor[x] = rand();
        }
    }
    else if (op == 2) {
        for (x = 0;x < tam; x++) 
            vetor[x] = x;
    }
    else if (op == 3) {
        for (x = 0;x < tam;x++)
            vetor[x] = tam - x - 1;
    }

    printf("Calculando tempo de ordenacao...\n");

    start = clock();
    heapSort(vetor, tam);
    end = clock();


    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("\n -> Tempo em s: %lf, Tempo em ms: %lf", difTempo, difTempo*1000);
    return 0;

}