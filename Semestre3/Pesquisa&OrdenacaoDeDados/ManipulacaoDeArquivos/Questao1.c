#include <stdio.h>
#include <stdlib.h>

int main()
{
    int espaco_branco = 0;
    int quebra_linha = 0;
    int caracter_geral = 0;

    FILE *fp;
    char c;
    
    fp = fopen("frase.txt","r");
    if(!fp) {
        printf("Erro na abertura do arquivo");
        exit(0);
    }

    while(!feof(fp)) {
        c = fgetc(fp);

        if (c == ' ') 
            espaco_branco++;

        else if(c == '\n') 
            quebra_linha++;
        
        else 
            caracter_geral++;
    }
    
    printf("\nEspacos em branco: %d", espaco_branco);
    printf("\nQuebras de linha: %d", quebra_linha);
    printf("\nCaracteres em geral: %d", caracter_geral);

    fclose(fp);
    return 0;
}