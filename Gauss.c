#include <stdio.h>
#include <stdlib.h>

double **ler_sistema(const char *nome, int *n);
void liberar(double **M, int n);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    int n;
    double **M = ler_sistema(argv[1], &n);
    if (M == NULL)
        return 1;
    double *X = malloc(n * sizeof(double)); // vetor solução

    // TESTE TEMPORÁRIO
    printf("N = %d\n", n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j == n)
                printf("| "); // separa o B
            printf("%8.3f ", M[i][j]);
        }
        printf("\n");
    }
    // ===================

    free(X);
    liberar(M, n);
    return 0;
}

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