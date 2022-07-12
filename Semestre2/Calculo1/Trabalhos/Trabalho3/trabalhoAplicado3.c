#include <stdio.h>
#include <math.h>

int main() {

    int N;
    float A, B, i, Rn, Ln, larg, alt, Dx, X, media;
    double e;
    e = 2.7182818284590452353602874;

    for(;;) {
        printf("O valor de A nao pode ser maior que de B!\n");
        printf("----------------------------\n");
        printf("Digite o valor de A: ");
        scanf("%f", &A);
        printf("Digite o valor de B: ");
        scanf("%f", &B);
        printf("Digite o valor n de subintervalos: ");
        scanf("%d", &N);
        printf("----------------------------\n");
        if (A < B){
            break;
        }
    }
    
    Dx = (B-A)/N;

    for (i=B; i>A; i-=Dx) {
        larg = Dx * (pow(e, i) + 2);
        Rn = larg + Rn;
    }

    for (i=A; i<B; i+=Dx) {
        alt = Dx * (pow(e, i) + 2);
        Ln = alt + Ln;
    }
    printf("\n");
    printf("A aproximacao da regiao plana: \n");
    printf("%f < A < %f \n", Ln,Rn);
    media = (Rn+Ln)/2;
    printf("A aproximacao media: ");
    printf("%f\n", media);
    printf("\n");
    printf("----------------------------\n");

    return 0;
}
