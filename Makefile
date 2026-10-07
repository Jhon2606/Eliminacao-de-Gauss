# Makefile - Eliminacao de Gauss
# Descomente APENAS o bloco do seu sistema operacional abaixo

# ---------------- macOS ----------------
CC = clang
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lm
TARGET = Gauss
CLEAN = rm -f $(TARGET) output/*.txt

# ---------------- Linux ----------------
# CC = gcc
# CFLAGS = -Wall -Wextra -Iinclude
# LDFLAGS = -lm
# TARGET = Gauss
# CLEAN = rm -f $(TARGET) output/*.txt

# ---------------- Windows (MinGW) ----------------
# CC = gcc
# CFLAGS = -Wall -Wextra -Iinclude
# LDFLAGS = -lm
# TARGET = Gauss.exe
# CLEAN = del /Q $(TARGET) output\*.txt

# ============================================================

SRC = $(wildcard src/*.c)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	$(CLEAN)

.PHONY: clean
