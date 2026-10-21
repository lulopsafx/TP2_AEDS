/* Mesma lista simplesmente encadeada do TP1, sem celula cabeca.
   Cada Pokemon alocado deve pertencer a apenas uma lista por vez. */
#ifndef POKELISTA_H
#define POKELISTA_H
#include "pokemon.h"

typedef struct celula {
    Pokemon* item;
    struct celula* prox;
} Celula;

typedef struct pokelista {
    Celula* primeiro;
    Celula* ultimo;
    int quantidade;
} PokeLista;

void inicializa_lista(PokeLista* lista);
// 1 se inseriu, 0 se malloc falhou. Em falha, p continua com o chamador.
int insere_pokemon(PokeLista* lista, Pokemon* p);
// Remove a celula e devolve o Pokemon, sem liberar o Pokemon.
Pokemon* remove_pokemon(PokeLista* lista, int id);
// Apenas consulta; o Pokemon continua pertencendo a lista.
Pokemon* busca_pokemon(PokeLista* lista, int id);
int lista_get_quantidade(PokeLista* lista);
/* Copia os enderecos dos itens para um vetor ja reservado pelo chamador.
   Retorna quantos copiou, ou -1 se os parametros forem invalidos.
   O vetor apenas consulta os objetos; a lista continua sendo dona deles. */
int lista_para_vetor(PokeLista* lista, Pokemon* vetor[], int capacidade);
// Consultas que percorrem a lista, sem alterar ou retirar os itens.
long long lista_soma_poder(PokeLista* lista);
long long lista_soma_energia(PokeLista* lista);
void imprime_lista(PokeLista* lista);
// Libera celulas e Pokemons que ainda pertencem a lista; deixa a lista vazia.
void libera_lista(PokeLista* lista);
#endif
