#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    char nome[51];
    float n1, n2;
} Aluno;

int main()
{
//arquivo 1 =========================
    FILE *fp;
    fp = fopen("dados.txt","rt");

    if(!fp) {
        printf("Erro na abertura do arquivo");
        exit(0);
    }
    Aluno a[51];
    int quantidade_alunos=0;
    int cont=0;
    int total=0;

    while (!feof(fp)) {

        if (quantidade_alunos==0) {
            fscanf(fp, "%d\n", &total);
            quantidade_alunos=1;
        }
        else {
            fscanf(fp, "%[A-Z ]\n%f\n%f\n", a[cont].nome, &a[cont].n1, &a[cont].n2);
            cont++;
        }
    }
    fclose(fp);
//arquivo 2 =========================
    FILE *fp2;
    fp2 = fopen("dados1.Dat","wb");

    if(!fp2) {
        printf("Erro na abertura do arquivo");
        exit(0);
    }

    fwrite(a, sizeof(Aluno), total, fp2);
    fclose(fp2);
    
    Aluno nomes[20];

//arquivo 3 =========================
    FILE *fp3;
    fp3 = fopen("dados1.dat", "rb");

    if(!fp3) {
        printf("Erro na abertura do arquivo");
        exit(0);
    }
    while (!feof(fp3)) {
        fread(nomes, sizeof(Aluno), total, fp3);
    }
    for (int i = 0; i < total; i++) {
        printf("%s\n", nomes[i].nome);
    }
    return 0;
}
