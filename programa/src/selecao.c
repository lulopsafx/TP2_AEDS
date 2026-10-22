#include <stdlib.h>
#include "selecao.h"

/* Helpers usados somente neste arquivo.
   A logica de indices crescentes foi adaptada para C da receita combinations:
   https://docs.python.org/3/library/itertools.html#itertools.combinations
   A contagem de combinacoes esta em Cormen, secao C.1, PDF local 951-952. */
static void primeira_combinacao(int indices[], int x) {
    for (int i = 0; i < x; i++) {
        indices[i] = i;
    }
}

static int proxima_combinacao(int indices[], int x, int n) {
    int pos = x - 1;
    // Procura da direita para a esquerda um indice que pode aumentar.
    while (pos >= 0 && indices[pos] == n - x + pos) {
        pos--;
    }
    if (pos < 0) {
        return 0; // Terminamos todas as combinacoes deste tamanho.
    }
    indices[pos]++;
    // Os indices seguintes recebem os menores valores crescentes possiveis.
    for (int i = pos + 1; i < x; i++) {
        indices[i] = indices[i - 1] + 1;
    }
    return 1;
}

static void soma_candidata(Pokemon* vetor[], int indices[], int x,
                           long long* poder, long long* energia) {
    *poder = 0;
    *energia = 0;
    for (int i = 0; i < x; i++) {
        Pokemon* p = vetor[indices[i]];
        *poder += pokemon_get_poder(p);
        *energia += pokemon_get_energia(p);
    }
}

int seleciona_melhor_equipe(Pokemon* vetor[], int n, int limite_energia,
                            Equipe* melhor) {
    if (melhor == NULL || n < 0 || limite_energia < 0
        || melhor->capacidade < n) {
        return 0;
    }
    if (n > 0 && (vetor == NULL || melhor->indices == NULL)) {
        return 0;
    }
    // Valida os registros uma vez, antes de iniciar a enumeracao.
    for (int i = 0; i < n; i++) {
        if (vetor[i] == NULL || pokemon_get_poder(vetor[i]) < 0
            || pokemon_get_energia(vetor[i]) < 0) {
            return 0;
        }
    }
    zera_equipe(melhor);
    if (n == 0) {
        return 1;
    }

    int* candidata = (int*) malloc((size_t) n * sizeof(int));
    if (candidata == NULL) {
        return 0;
    }

    for (int x = 1; x <= n; x++) {
        primeira_combinacao(candidata, x);
        int tem_combinacao = 1;
        while (tem_combinacao) {
            long long poder, energia;
            soma_candidata(vetor, candidata, x, &poder, &energia);
            if (energia <= limite_energia && poder > melhor->poder_total) {
                if (guarda_equipe(melhor, candidata, x, poder, energia) == 0) {
                    free(candidata);
                    zera_equipe(melhor);
                    return 0;
                }
            }
            tem_combinacao = proxima_combinacao(candidata, x, n);
        }
    }
    free(candidata);
    return 1;
}
