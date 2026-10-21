/* TAD Equipe: guarda o resultado da selecao por indices.
   Nao guarda copias dos Pokemon e nao e dona dos objetos apontados pelo vetor
   de consulta. Os indices continuam se referindo a ordem original desse vetor. */
#ifndef EQUIPE_H
#define EQUIPE_H

typedef struct equipe {
    int* indices;
    int capacidade;          // espaco reservado no vetor de indices
    int quantidade;          // quantos indices estao preenchidos
    long long poder_total;
    long long energia_total;
} Equipe;

/* Inicializa uma equipe nova ou ja liberada, com espaco para capacidade indices.
   Retorna 1 no sucesso e 0 em erro. Capacidade zero e permitida.
   Nao chame novamente em uma equipe que ainda possui um vetor alocado. */
int inicializa_equipe(Equipe* e, int capacidade);

// Zera o resultado, conservando o vetor para uma nova busca.
void zera_equipe(Equipe* e);

/* Copia os valores dos indices e guarda os totais calculados para eles.
   Os indices recebidos devem representar uma combinacao valida.
   Retorna 1 se guardou e 0 se os parametros nao cabem na equipe. */
int guarda_equipe(Equipe* e, int indices[], int quantidade,
                  long long poder_total, long long energia_total);

int equipe_get_quantidade(Equipe* e);
long long equipe_get_poder_total(Equipe* e);
long long equipe_get_energia_total(Equipe* e);
// Retorna o indice na posicao pedida, ou -1 se a posicao nao existe.
int equipe_get_indice(Equipe* e, int posicao);

// Libera somente o vetor de indices e deixa a equipe vazia.
void libera_equipe(Equipe* e);
#endif
