//aluno: Renan Carlos Loewenstein
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int ano;
   char modelo[10];
} Carro;

//getMax
Carro getMax(Carro *A, int n) {
   Carro max = A[0];
   for (int i=1; i<n; i++) {
      if (A[i].ano > max.ano)
         max=A[i];
   }
   return max;
}

//countingSort
void countingSort(Carro *A, int n, int pos) {
   Carro output[n];
   int i, gg;
   int count[10] = {0};
 
   for (i=0; i<n; i++) {
     gg=(A[i].ano/pos)%10;
     count[gg]++;
   }
   for (i=1; i<10; i++) {
       count[i]+=count[i-1];
   }
   for (i=n-1; i>=0; i--) {
       gg=(A[i].ano/pos)%10;
       count[gg]--;
       output[count[gg]]=A[i];
   }
   for (i=0; i<n; i++) {
       A[i]=output[i];
   }
}

//radixSort
void radixSort(Carro *A, int n) {
   Carro max = getMax(A, n);
   
   for(int pos=1; max.ano/pos>0; pos*=10) {
      countingSort(A, n, pos);
   }
}

//main
int main() {
   
   Carro c[15] = {
      {2017, "Parati"},
      {2021, "Corolla"},
      {2006, "Uno"},
      {2015, "Fiesta"},
      {2013, "Parati"},
      {1987, "Brasilia"},
      {2003, "Celta"},
      {2018, "Fiesta"},
      {2003, "Chevette"},
      {1991, "Corsa"},
      {2006, "Peugeot"},
      {2009, "Fox"},
      {2011, "Corolla"},
      {1969, "Fusca"},
      {1974, "Kombi"},
   };

   //antes do RadixSort
   printf("\n\n");
   printf("Antes da Ordenacao: \n");
   for (int i=0; i<15; i++) {
     printf("\nAno: %d - Modelo: %s" , c[i].ano, c[i].modelo);
   }
   printf("\n\n");

   int n = sizeof(c)/sizeof(c[0]);
   radixSort(&c, n);

   //depois do RadixSort
   printf("Depois da Ordenacao: \n");
   for (int i=0; i<15; i++) {
       printf("\nAno: %d - Modelo: %s" , c[i].ano, c[i].modelo);
   }
   return 0;
}