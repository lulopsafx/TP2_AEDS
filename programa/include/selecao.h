/* Modulo da selecao por forca bruta do TP2.
   Gera todas as combinacoes de tamanho 1 ate N, sem repeticao.
   A energia e uma restricao; o objetivo e o maior poder total. */
#ifndef SELECAO_H
#define SELECAO_H
#include "pokemon.h"
#include "equipe.h"

/* Antes da chamada:
   - vetor tem N ponteiros validos, na ordem original dos registros;
   - poder, energia, N e limite_energia sao nao negativos;
   - melhor foi inicializada com capacidade de pelo menos N indices.

   Retorna 1 no sucesso, inclusive quando a melhor equipe e vazia.
   Retorna 0 em erro de parametros ou de alocacao. Confira esse retorno antes
   de apresentar um resultado. Cada chamada recomeca a busca do zero.

   A busca nao altera os Pokemon, o vetor de consulta ou as listas.
   Empates de poder conservam a primeira equipe encontrada.
   A distribuicao entre treinadores fica para depois, no programa principal. */
int seleciona_melhor_equipe(Pokemon* vetor[], int n, int limite_energia,
                            Equipe* melhor);
#endif
