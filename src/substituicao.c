#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eliminacao.h"
#include "substituicao.h"

// Implementar a retro substituição.
void retro_substituir(double **M, double *X, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (fabs(M[i][i]) < EPS) {
            fprintf(stderr,
                    "Nao foi possivel calcular uma solucao unica: pivo nulo.\n");
            exit(1);
        }

        double soma = 0.0;
        for (int j = i + 1; j < n; j++) {
            soma += M[i][j] * X[j];
        }

        X[i] = (M[i][n] - soma) / M[i][i];
    }
}

// implementa a impressão do vetor solução.
void mostrar_solucao(double *X, int n, FILE *out) {
    fprintf(out, "Solução do sistema:\n");
    for (int i = 0; i < n; i++) {
        fprintf(out, "x[%d] = %.6f\n", i, X[i]);
    }
}
