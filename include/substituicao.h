#ifndef SUBSTITUICAO_H
#define SUBSTITUICAO_H

#include <stdio.h>

// Calcula X (tamanho n) a partir de M (n x n+1) já triangularizada
void retro_substituir(double **M, double *X, int n);

// Imprime o vetor solução X em out
void mostrar_solucao(double *X, int n, FILE *out);

#endif
