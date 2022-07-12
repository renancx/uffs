#include <stdio.h>
#include <math.h>

double velocidade_barca; //X
double velocidade_carro; //Y

double tempo_A; //a
double tempo_B; //b 
double tempo_total; //c

double a,b,c;

double x;

int main(void) {
  
printf("Digite a velocidade da barca em quilometros por hora: ");
scanf("%lf", &velocidade_barca);
printf("Digite a velocidade do carro em quilometros por hora: ");
scanf("%lf", &velocidade_carro);

while (velocidade_barca>velocidade_carro){
  printf("\n\nA velocidade da barca não pode ser maior que a do carro!\n\n");
  printf("Digite a velocidade da barca em quilometros por hora: ");
  scanf("%lf", &velocidade_barca);
  printf("Digite a velocidade do carro em quilometros por hora: ");
  scanf("%lf", &velocidade_carro);
}

a=velocidade_barca;
b=velocidade_carro;
c=-40;

//fórmula (velocidade_barca*x^2)-(velocidade_carro*x^2)-40
float r1=(-b+(sqrt((b*b)-(4*a*c))))/(2*a);
float r2=(-b-(sqrt((b*b)-(4*a*c))))/(2*a);

double distB = sqrt(1600+((r1*r1)*10000));
double distA = 100-r1*100;

if(distA<0){
  distA = distA*-1;
}

printf("--------------------------------------------------------");
printf("\nDistância percorrida de barca: %.2f Km", distB);
printf("\nDistância percorrida de carro: %.2f Km\n", distA);

printf("\n~~Distância da estação até a cidade %.2f Km\n", distA);
printf("~~Distância total percorrida que torna a viagem o mais rápido possível: %.2f Km\n", distA+distB);

}