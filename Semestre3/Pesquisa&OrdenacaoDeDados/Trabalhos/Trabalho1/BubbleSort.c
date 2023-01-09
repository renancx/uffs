#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void swap(int *num, int *num2) {

    int aux;
    aux = *num;
    *num = *num2;
    *num2 = aux;

}

void bubbleSortDecrescente(int vet[], int TAM) {
    int i, x;
    bool flag;

    for (i = 0; i < TAM; i++) {
        flag = false;
        for (x = i + 1; x < TAM; x++) {
            if (vet[x] > vet[i]) {
                swap(&vet[x], &vet[i]);
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }   
}

void bubbleSort(int vet[], int TAM) {

    int i, x;
    bool flag;

    for (i = 0; i < TAM-1; i++) {
        flag = false;
        for (x = 0; x < TAM-i-1; x++) {
            if (vet[x] > vet[x+1]) {
                swap(&vet[x], &vet[x+1]);
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }   
}

int main() {

    int vetor[100000];
    clock_t start, end;

    srand(time(NULL));

    for (int i = 0; i < 100000; i++ ) {
        vetor[i] = rand();
    }
    /*
    for (int i = 0; i < 15; i++ ) {
        printf("%d, ", vetor[i]);
    }
    */
    bubbleSortDecrescente(vetor, 100000);
        
    printf("\n");
    printf("-----------\n");
    start = clock();
    bubbleSort(vetor, 100000);
    end = clock();
    /*
    for (int i = 0; i < 15; i++ ) {
        printf("%d, ", vetor[i]);
    }
    */

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("\n\n\n\t -> Tempo em s: %lf, Tempo em ms: %lf", difTempo, difTempo*1000);
    return 0;

}