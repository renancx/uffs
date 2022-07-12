#include <stdio.h>
#include <math.h>

int main() {
    float A, B, res1, res2;
    scanf("%f %f", &A, &B);
    res1 = (5*A) - (A*A) - (2 * pow(A, 1/3));
    res2 = (5*B) - (B*B) - (2 * pow(B, 1/3));
    
    if (res1 > 0 && res2 < 0){
        printf("A equação tem pelo menos uma solução neste intervalo!\n");
    }
    else if (res2 > 0 && res1 < 0){
        printf("A equação tem pelo menos uma solução neste intervalo!\n");
    }
    else{
        printf("Não é possível afirmar que existe solução neste intervalo, tente outros dois números!\n");
    }
    
    return 0;
}
