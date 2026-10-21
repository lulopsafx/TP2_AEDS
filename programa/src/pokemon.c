#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pokemon.h"

void inicializa_pokemon(Pokemon* p, int id, int num_pokedex, const char* nome,
                        const char* tipo, int poder, int energia) {
    if (p != NULL) {
        p->id = id;
        p->num_pokedex = num_pokedex;
        // Reserva a ultima posicao para o terminador da string.
        strncpy(p->nome, nome, MAX_STR - 1);
        p->nome[MAX_STR - 1] = '\0';
        strncpy(p->tipo, tipo, MAX_STR - 1);
        p->tipo[MAX_STR - 1] = '\0';
        p->poder = poder;
        inicializa_pokemonitor(&p->monitor, energia);
    }
}

int pokemon_get_id(Pokemon* p) {
    return p->id;
}

int pokemon_get_num_pokedex(Pokemon* p) {
    return p->num_pokedex;
}

void pokemon_get_nome(Pokemon* p, char* nome_out) {
    strcpy(nome_out, p->nome);
}

void pokemon_get_tipo(Pokemon* p, char* tipo_out) {
    strcpy(tipo_out, p->tipo);
}

int pokemon_get_poder(Pokemon* p) {
    return p->poder;
}

int pokemon_get_energia(Pokemon* p) {
    return pokemonitor_get_energia(&p->monitor);
}

void pokemon_set_poder(Pokemon* p, int poder) {
    p->poder = poder;
}

void pokemon_set_energia(Pokemon* p, int energia) {
    pokemonitor_set_energia(&p->monitor, energia);
}

void imprime_pokemon(Pokemon* p) {
    printf("ID: %d | Pokedex: %d | Nome: %s | Tipo: %s | Poder: %d | Energia: %d\n",
           p->id, p->num_pokedex, p->nome, p->tipo, p->poder, pokemon_get_energia(p));
}

void libera_pokemon(Pokemon* p) {
    // O monitor esta dentro de Pokemon, por isso nao precisa de outro free.
    free(p);
}
