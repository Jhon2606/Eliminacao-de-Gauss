# Eliminacao-de-Gauss
Este trabalho contempla o assunto Sistemas Lineares da disciplina Algoritmos Numéricos. O trabalho é em grupo 3 pessoas e  deve implementar o método de Eliminação de Gauss para a solução de Sistemas Lineares apresentado na disciplina.

**Alunos:**
- Danilo Martins Gazzoli
- Jhonatas Vinicius Neri Dos Santos
- Lara Tidesco Zumerle

## Estrutura

- `src/` — código fonte (`main.c`, `leitura.c`, `eliminacao.c`, `substituicao.c`)
- `include/` — headers (`leitura.h`, `eliminacao.h`, `substituicao.h`)
- `data/` — arquivos de sistemas lineares de exemplo (`.dat`)
- `output/` — arquivos gerados pela execução do programa

## Compilar e executar

Antes de compilar, abra o `Makefile` e descomente (remova o `#` do início das linhas) o bloco do seu sistema operacional — macOS, Linux ou Windows. Deixe só um bloco descomentado.

**macOS / Linux**
```
make
./Gauss data/sistema3x3.dat
```

**Windows** (via MinGW/mingw32-make)
```
mingw32-make
Gauss.exe data\sistema3x3.dat
```

Para limpar os arquivos gerados: `make clean` (ou `mingw32-make clean` no Windows).
