#include <stdio.h>
#include <stdlib.h>
#include "leitura.h"

double **ler_sistema(const char *nome, int *n)
{
    FILE *f = fopen(nome, "r");
    if (f == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    // Lê a dimensão N do sistema
    if (fscanf(f, "%d", n) != 1 || *n <= 0)
    {
        fprintf(stderr, "Erro: dimensao N invalida no arquivo\n");
        fclose(f);
        return NULL;
    }

    // Aloca N linhas, cada uma com N+1 colunas (A + coluna do B)
    double **M = malloc(*n * sizeof(double *));
    if (M == NULL)
    {
        fprintf(stderr, "Erro de memoria\n");
        fclose(f);
        return NULL;
    }
    for (int i = 0; i < *n; i++)
    {
        M[i] = malloc((*n + 1) * sizeof(double));
        if (M[i] == NULL)
        {
            fprintf(stderr, "Erro de memoria\n");
            fclose(f);
            return NULL;
        }
    }

    // Lê a matriz A: N linhas x N colunas
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *n; j++)
            if (fscanf(f, "%lf", &M[i][j]) != 1)
            {
                fprintf(stderr, "Erro ao ler a matriz A\n");
                fclose(f);
                return NULL;
            }

    // Lê o vetor B: vem numa linha só no arquivo mas guardamos na última coluna de cada linha
    for (int i = 0; i < *n; i++)
        if (fscanf(f, "%lf", &M[i][*n]) != 1)
        {
            fprintf(stderr, "Erro ao ler o vetor B\n");
            fclose(f);
            return NULL;
        }

    fclose(f);
    return M;
}

// Libera a memória: primeiro cada linha, depois o vetor de ponteiros
void liberar(double **M, int n)
{
    for (int i = 0; i < n; i++)
        free(M[i]);
    free(M);
}
