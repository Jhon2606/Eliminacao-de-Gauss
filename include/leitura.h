#ifndef LEITURA_H
#define LEITURA_H

// Lê o sistema linear de `nome` em uma matriz aumentada [A|B]
double **ler_sistema(const char *nome, int *n);

// Libera a memória alocada por ler_sistema.
void liberar(double **M, int n);

#endif
