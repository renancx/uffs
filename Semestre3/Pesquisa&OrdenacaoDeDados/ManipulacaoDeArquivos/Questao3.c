#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("dados.txt", "rt");

    if(!fp) {
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    
    int valor=0;
    char nome[50];
    float nota1=0; 
    float nota2=0; 
    int quantidade_alunos=0;

    printf("Alunos com a media abaixo de 7.0: \n\n");
    while(!feof(fp)) {
        if(quantidade_alunos==0) {
            fscanf(fp, "%d\n", &valor);
        }
        else {
            fscanf(fp, "%[A-Z ]\n%f\n%f\n", nome, &nota1, &nota2);
            float media=(nota1+nota2)/2;
            if(media<7) {
                printf("%s - %.2f\n", nome, media);
            }
        }
        quantidade_alunos=1;
    }
    printf("\n");
    fclose(fp);
    return 0;
}