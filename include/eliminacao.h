#ifndef ELIMINACAO_H
#define ELIMINACAO_H

#include <stdio.h>

// Def de Erro: Valores com módulo abaixo disso são tratados como zero
#define EPS 1e-9

// Transforma M (n x n+1) em forma triangular superior
void eliminar(double **M, int n);

// Imprime a matriz M (n x n+1) triangularizada
void mostrar_matriz_eliminacao(double **M, int n, FILE *out);

#endif
