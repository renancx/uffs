#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *num, int *num2) {
    int aux;
    aux = *num;
    *num = *num2;
    *num2 = aux;
}

int partitions (int vet[], int start, int end) {

    int i, k;
    int posPivo = end;
    k = start;
    for (i = start; i < end ; i++) {
        if (vet[i] <= vet[posPivo]) { ///
            swap(&vet[i], &vet[k]);
            k++;
        }
    }
    if (vet[k] > vet[posPivo]) {
        swap(&vet[k], &vet[posPivo]);
    }
    return k;   // fizemos essa alteração do pseudo código passado nos slides,
                // dessa forma funcionou corretamente.
}

void quickSort(int vet[], int start, int end) {

    int posPivo;
    if (start < end) {
        posPivo = partitions(vet, start, end);
        quickSort(vet, start, posPivo-1);
        quickSort(vet, posPivo+1, end);
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
    quickSort(vetor, 0, tam);
    end = clock();

    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("\n -> Tempo em s: %lf, Tempo em ms: %lf", difTempo, difTempo*1000);
    return 0;

}