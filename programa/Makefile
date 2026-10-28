# Execute dentro de programa.
# Windows: mingw32-make; .\tp2.exe testes/mini.txt; mingw32-make clean
# Linux: make; ./tp2 testes/mini.txt; make clean

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g -Iinclude
FONTES = main.c $(wildcard src/*.c)
OBJETOS = $(FONTES:.c=.o)
MODULOS = $(filter-out main.o,$(OBJETOS))
PASTA_TESTES = ../programa/teste
ENTRADA ?= $(PASTA_TESTES)/teste2.txt

ifeq ($(OS),Windows_NT)
# Usa o cmd diretamente, preservando as barras dos caminhos no clean.
SHELL := cmd.exe
.SHELLFLAGS := /C
EXT = .exe
COMANDO = .\tp2$(EXT)
else
EXT =
COMANDO = ./tp2$(EXT)
endif

.PHONY: all modulos demo executar teste1 teste2 clean
all: tp2$(EXT)

tp2$(EXT): $(OBJETOS)
	$(CC) $(CFLAGS) $^ -o $@

ifeq ($(OS),Windows_NT)
.PHONY: tp2
tp2: tp2.exe
endif

executar: tp2$(EXT)
	$(COMANDO) "$(ENTRADA)"

teste1 teste2: tp2$(EXT)
	$(COMANDO) "$(PASTA_TESTES)/$@.txt"

modulos: $(MODULOS)

%.o: %.c $(wildcard include/*.h)
	$(CC) $(CFLAGS) -c $< -o $@

demo_tads$(EXT): ../orientacao_tp2/exemplos/01_usa_tads.c $(MODULOS)
	$(CC) $(CFLAGS) $^ -o $@

demo: demo_tads$(EXT)
ifeq ($(OS),Windows_NT)
	.\demo_tads$(EXT)
else
	./demo_tads$(EXT)
endif

clean:
ifeq ($(OS),Windows_NT)
	@if exist "src\*.o" del /Q "src\*.o"
	@if exist "*.o" del /Q "*.o"
	@if exist "tp2.exe" del /Q "tp2.exe"
	@if exist "demo_tads.exe" del /Q "demo_tads.exe"
else
	rm -f *.o src/*.o tp2 demo_tads
endif
