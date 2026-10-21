#include <stdio.h>
#include "pokemonitor.h"

void inicializa_pokemonitor(PokeMonitor* monitor, int energia) {
    if (monitor != NULL) {
        monitor->energia = energia;
    }
}

int pokemonitor_get_energia(PokeMonitor* monitor) {
    return monitor->energia;
}

void pokemonitor_set_energia(PokeMonitor* monitor, int energia) {
    monitor->energia = energia;
}

void imprime_pokemonitor(PokeMonitor* monitor) {
    printf("Energia do PokeMonitor: %d\n", monitor->energia);
}
