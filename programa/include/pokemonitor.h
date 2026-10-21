/* O PokeMonitor guarda o consumo de energia de um Pokemon no TP2.
   O limite total da equipe sera controlado pelo algoritmo de selecao. */
#ifndef POKEMONITOR_H
#define POKEMONITOR_H

typedef struct pokemonitor {
    int energia;
} PokeMonitor;

void inicializa_pokemonitor(PokeMonitor* monitor, int energia);
int pokemonitor_get_energia(PokeMonitor* monitor);
void pokemonitor_set_energia(PokeMonitor* monitor, int energia);
void imprime_pokemonitor(PokeMonitor* monitor);
#endif
