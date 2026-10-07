#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eliminacao.h"

void eliminar(double **M, int n)
{
    for (int k = 0; k < n - 1; k++)
    {
        // Procura, na coluna k, a linha com maior valor absoluto a partir de k
        int pivo = k;
        double maior = fabs(M[k][k]);
        for (int i = k + 1; i < n; i++)
        {
            if (fabs(M[i][k]) > maior)
            {
                maior = fabs(M[i][k]);
                pivo = i;
            }
        }

        if (maior < EPS)
        {
            fprintf(stderr, "Sistema impossivel ou indeterminado (pivo nulo)\n");
            exit(1);
        }

        if (pivo != k)
        {
            double *tmp = M[k];
            M[k] = M[pivo];
            M[pivo] = tmp;
        }

        // Zera os elementos abaixo do pivô em cada linha i
        for (int i = k + 1; i < n; i++)
        {
            double fator = M[i][k] / M[k][k];
            for (int j = k; j <= n; j++)
                M[i][j] -= fator * M[k][j];
        }
    }
}

void mostrar_matriz_eliminacao(double **M, int n, FILE *out)
{
    fprintf(out, "N = %d\n", n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j == n)
                fprintf(out, "| "); // separa o B
            double v = M[i][j];
            fprintf(out, "%8.3f ", fabs(v) < EPS ? 0.0 : v);
        }
        fprintf(out, "\n");
    }
}
