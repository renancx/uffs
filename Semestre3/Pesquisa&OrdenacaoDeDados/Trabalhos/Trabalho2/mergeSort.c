#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala (int p, int q, int r, int v[])  {

    int *w;                           
    w = malloc ((r-p) * sizeof (int));
        
    int i = p;
    int j = q;                       
    int k = 0;                        
    while (i < q && j < r) {          
        if (v[i] <= v[j]) {
            w[k++] = v[i++]; 
        } //  6
        else {
            w[k++] = v[j++];          
        }
    }                                 
    while (i < q) {
        w[k++] = v[i++];
    }         
    while (j < r) {
        w[k++] = v[j++];   
    }    
    for (i = p; i < r; ++i) {
        v[i] = w[i-p]; 
    }
   free (w);
}

 void mergeSort(int p, int r, int v[]) {
    if (p < r-1) {                
        int q = (p + r)/2;        
        mergeSort (p, q, v);      
        mergeSort (q, r, v);      
        intercala (p, q, r, v);   
    }
}


void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 

int main()
{
    int op = 0, tam=0, x = 0;

    printf("Defina o tamanho do vetor:\n");
    printf("-10000\n-50000\n-100000\n");
    printf("Digite o numero: ");
    scanf("%d", &tam);

    int *vetor;                                 
    vetor = malloc ((tam) * sizeof (int));   

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
    mergeSort(0, tam, vetor);
    end = clock();
    
    double difTempo = ((double) end - start)/CLOCKS_PER_SEC;

    printf("\n -> Tempo em s: %lf, Tempo em ms: %lf", difTempo, difTempo*1000);
    return 0;

}