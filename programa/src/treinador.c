#include <stdio.h>
#include <string.h>
#include "treinador.h"

void inicializa_treinador(Treinador* t, int id, const char* nome) {
    if (t != NULL) {
        t->id = id;
        strncpy(t->nome, nome, MAX_NOME_TREINADOR - 1);
        t->nome[MAX_NOME_TREINADOR - 1] = '\0';
        inicializa_lista(&t->lista);
    }
}

int treinador_recebe_pokemon(Treinador* t, Pokemon* p) {
    if (t == NULL) {
        return 0;
    }
    return insere_pokemon(&t->lista, p);
}

Pokemon* treinador_retira_pokemon(Treinador* t, int id) {
    return remove_pokemon(&t->lista, id);
}

long long treinador_get_poder_total(Treinador* t) {
    return lista_soma_poder(&t->lista);
}

long long treinador_get_energia_total(Treinador* t) {
    return lista_soma_energia(&t->lista);
}

void imprime_treinador(Treinador* t) {
    printf("Treinador(a) %s | Quantidade: %d\n", t->nome, t->lista.quantidade);
    imprime_lista(&t->lista);
}

void libera_treinador(Treinador* t) {
    libera_lista(&t->lista);
}
