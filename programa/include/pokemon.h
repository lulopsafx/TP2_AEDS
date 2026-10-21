/* TAD Pokemon adaptado para o TP2. Agora guardamos poder e PokeMonitor.
   O id identifica o registro; num_pokedex identifica a especie. */
#ifndef POKEMON_H
#define POKEMON_H
#include "pokemonitor.h"
#define MAX_STR 50

typedef struct pokemon {
    int id;
    int num_pokedex;
    char nome[MAX_STR];
    char tipo[MAX_STR];
    int poder;
    PokeMonitor monitor;
} Pokemon;

// Preenche um Pokemon ja alocado. Strings usam no maximo MAX_STR - 1 caracteres.
void inicializa_pokemon(Pokemon* p, int id, int num_pokedex, const char* nome,
       const char* tipo, int poder, int energia);
int pokemon_get_id(Pokemon* p);
int pokemon_get_num_pokedex(Pokemon* p);
// Os vetores de saida dos getters de string precisam ter MAX_STR posicoes.
void pokemon_get_nome(Pokemon* p, char* nome_out);
void pokemon_get_tipo(Pokemon* p, char* tipo_out);
int pokemon_get_poder(Pokemon* p);
int pokemon_get_energia(Pokemon* p);
void pokemon_set_poder(Pokemon* p, int poder);
void pokemon_set_energia(Pokemon* p, int energia);
void imprime_pokemon(Pokemon* p);
// Usar para Pokemon criado com malloc e que nao pertence mais a uma lista.
void libera_pokemon(Pokemon* p);
#endif
