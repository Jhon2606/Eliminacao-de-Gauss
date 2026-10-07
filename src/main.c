#include <stdio.h>
#include <stdlib.h>
#include "leitura.h"
#include "eliminacao.h"
#include "substituicao.h"

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

    eliminar(M, n);

    FILE *arq_matriz = fopen("output/matriz_triangularizada.txt", "w");
    if (arq_matriz == NULL)
    {
        perror("Erro ao abrir output/matriz_triangularizada.txt");
        free(X);
        liberar(M, n);
        return 1;
    }
    mostrar_matriz_eliminacao(M, n, stdout);
    mostrar_matriz_eliminacao(M, n, arq_matriz);
    fclose(arq_matriz);

    retro_substituir(M, X, n);

    FILE *arq_solucao = fopen("output/saida.txt", "w");
    if (arq_solucao == NULL)
    {
        perror("Erro ao abrir output/saida.txt");
        free(X);
        liberar(M, n);
        return 1;
    }
    mostrar_solucao(X, n, stdout);
    mostrar_solucao(X, n, arq_solucao);
    fclose(arq_solucao);

    free(X);
    liberar(M, n);
    return 0;
}
