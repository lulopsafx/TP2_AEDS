#include <stdio.h>
#include <stdlib.h>
#include "pokelista.h"

void inicializa_lista(PokeLista* lista) {
    if (lista != NULL) {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        lista->quantidade = 0;
    }
}

int insere_pokemon(PokeLista* lista, Pokemon* p) {
    if (lista == NULL || p == NULL) {
        return 0;
    }
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    if (nova == NULL) {
        return 0;
    }
    nova->item = p;
    nova->prox = NULL;
    if (lista->primeiro == NULL) {
        lista->primeiro = nova;
    } else {
        lista->ultimo->prox = nova;
    }
    lista->ultimo = nova;
    lista->quantidade++;
    return 1;
}

Pokemon* remove_pokemon(PokeLista* lista, int id) {
    Celula* atual = lista->primeiro;
    Celula* ant = NULL;
    while (atual != NULL && pokemon_get_id(atual->item) != id) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        return NULL;
    }
    Pokemon* p = atual->item; // Guarda o Pokemon antes de liberar a celula.
    if (ant == NULL) {
        lista->primeiro = atual->prox;
    } else {
        ant->prox = atual->prox;
    }
    if (atual == lista->ultimo) {
        lista->ultimo = ant;
    }
    free(atual);
    lista->quantidade--;
    return p;
}

Pokemon* busca_pokemon(PokeLista* lista, int id) {
    Celula* atual = lista->primeiro;
    while (atual != NULL) {
        if (pokemon_get_id(atual->item) == id) {
            return atual->item;
        }
        atual = atual->prox;
    }
    return NULL;
}

int lista_get_quantidade(PokeLista* lista) {
    return lista->quantidade;
}

int lista_para_vetor(PokeLista* lista, Pokemon* vetor[], int capacidade) {
    if (lista == NULL || capacidade < lista->quantidade || capacidade < 0
        || (lista->quantidade > 0 && vetor == NULL)) {
        return -1;
    }
    int i = 0;
    Celula* atual = lista->primeiro;
    while (atual != NULL) {
        vetor[i] = atual->item;
        i++;
        atual = atual->prox;
    }
    return i;
}

long long lista_soma_poder(PokeLista* lista) {
    long long total = 0;
    Celula* atual = lista->primeiro;
    while (atual != NULL) {
        total += pokemon_get_poder(atual->item);
        atual = atual->prox;
    }
    return total;
}

long long lista_soma_energia(PokeLista* lista) {
    long long total = 0;
    Celula* atual = lista->primeiro;
    while (atual != NULL) {
        total += pokemon_get_energia(atual->item);
        atual = atual->prox;
    }
    return total;
}

void imprime_lista(PokeLista* lista) {
    Celula* atual = lista->primeiro;
    while (atual != NULL) {
        imprime_pokemon(atual->item);
        atual = atual->prox;
    }
}

void libera_lista(PokeLista* lista) {
    Celula* atual = lista->primeiro;
    while (atual != NULL) {
        Celula* prox = atual->prox;
        libera_pokemon(atual->item);
        free(atual);
        atual = prox;
    }
    inicializa_lista(lista);
}
