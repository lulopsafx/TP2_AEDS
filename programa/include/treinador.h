/* No TP2, o treinador guarda seu nome e a parte da equipe escolhida.
   Movimento e pokebolas eram regras da missao do TP1. */
#ifndef TREINADOR_H
#define TREINADOR_H
#include "pokelista.h"
#define MAX_NOME_TREINADOR 50

typedef struct treinador {
    int id;
    char nome[MAX_NOME_TREINADOR];
    PokeLista lista;
} Treinador;

void inicializa_treinador(Treinador* t, int id, const char* nome);
// 1 sucesso, 0 falha de alocacao. p deve ter sido retirado da lista anterior.
int treinador_recebe_pokemon(Treinador* t, Pokemon* p);
Pokemon* treinador_retira_pokemon(Treinador* t, int id);
// Totais da parte da equipe que foi distribuida para este treinador.
long long treinador_get_poder_total(Treinador* t);
long long treinador_get_energia_total(Treinador* t);
void imprime_treinador(Treinador* t);
void libera_treinador(Treinador* t);
#endif
