#include <stdlib.h>
#include "equipe.h"

int inicializa_equipe(Equipe* e, int capacidade) {
    if (e == NULL) {
        return 0;
    }
    e->indices = NULL;
    e->capacidade = 0;
    zera_equipe(e);

    if (capacidade < 0) {
        return 0;
    }
    if (capacidade == 0) {
        return 1; // A equipe vazia nao precisa de um vetor.
    }

    e->indices = (int*) malloc((size_t) capacidade * sizeof(int));
    if (e->indices == NULL) {
        return 0;
    }
    e->capacidade = capacidade;
    return 1;
}

void zera_equipe(Equipe* e) {
    if (e != NULL) {
        e->quantidade = 0;
        e->poder_total = 0;
        e->energia_total = 0;
    }
}

int guarda_equipe(Equipe* e, int indices[], int quantidade,
                  long long poder_total, long long energia_total) {
    if (e == NULL || quantidade < 0 || quantidade > e->capacidade
        || poder_total < 0 || energia_total < 0) {
        return 0;
    }
    if (quantidade > 0 && (indices == NULL || e->indices == NULL)) {
        return 0;
    }
    for (int i = 0; i < quantidade; i++) {
        e->indices[i] = indices[i]; // Copia o valor, nao o endereco do vetor.
    }
    e->quantidade = quantidade;
    e->poder_total = poder_total;
    e->energia_total = energia_total;
    return 1;
}

int equipe_get_quantidade(Equipe* e) {
    return e->quantidade;
}

long long equipe_get_poder_total(Equipe* e) {
    return e->poder_total;
}

long long equipe_get_energia_total(Equipe* e) {
    return e->energia_total;
}

int equipe_get_indice(Equipe* e, int posicao) {
    if (e == NULL || posicao < 0 || posicao >= e->quantidade) {
        return -1;
    }
    return e->indices[posicao];
}

void libera_equipe(Equipe* e) {
    if (e != NULL) {
        free(e->indices);
        e->indices = NULL;
        e->capacidade = 0;
        zera_equipe(e);
    }
}
