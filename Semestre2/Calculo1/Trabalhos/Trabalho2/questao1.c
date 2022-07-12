#include <stdio.h>
#include <math.h>

int main() {
  double V, X, Y;
  double pi = 3.14;

  double raio;
  double altura;

  double area_lateral;
  double area_base;
  double area_total;

  double custo_base;
  double custo_lateral;
  double custo_total;

//Pedir o V, X e Y
  printf("Digite o valor do Volume(V) do cilindro em centimetros cubicos: "); //centimetros cubicos
  scanf("%lf", &V);
  printf("Digite o custo por metro quadrado do material do topo e base da lata : R$ ");
  scanf("%lf", &X);
  printf("Digite o custo por metro quadrado do material do lado da lata : R$ ");
  scanf("%lf", &Y);

//Printar a altura e o raio
  raio = pow(V/(2*pi), 1.0/3.0);
  altura = pow(4*V/pi, 1.0/3.0);

  printf("\n---------------------------------------------------\n");
  printf("Valores foram aproximados para duas casas decimais\n");
  printf("---------------------------------------------------\n\n");
  printf("Raio: %.5f centimetros\n", raio);
  printf("Altura: %.5f centimetros\n", altura);

//Printar a area total
  area_base = (raio*raio*pi); 
  area_lateral = 2*pi*raio*altura;
  area_total = (2*area_base) + (area_lateral);

  printf("\nÁrea de uma das bases: %.5f centimetros quadrados\n", area_base);
  printf("Área da lateral: %.5f centimetros quadrados\n", area_lateral);
  printf("Área total: %.5f centimetros quadrados\n", area_total);

//Printar os custos do material
  custo_base = ((area_base/10000)*2*X); 
  custo_lateral = ((area_lateral/10000)*Y);
  custo_total = (custo_base)+(custo_lateral);

  printf("\nCusto lateral: R$ %.5f\n", custo_lateral);
  printf("Custo das bases: R$ %.5f\n", custo_base);
  printf("Custo total: R$ %.5f\n", custo_total);

}