#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n;
    if (argc != 2)
    {
        fprintf(stderr, "Insira apenas um arquivo de entrada\n");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    fscanf(f, "%d", &n);
    
    double **M = malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
        M[i] = malloc((n + 1) * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
            printf("%8.3f ", M[i][j]);
        printf("\n");
    }
    return 0;
}