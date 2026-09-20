#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usando: %s ", argv[0]);
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    return 0;
}