#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
    int valor;
    struct Node* next;
} Node;

typedef struct Fila {
    Node* primeiro;
    Node* ultimo;
} Fila;

void print_fila(Fila* p) {
    Node* node_ptr = p->primeiro;
    printf("(Início) ");
    while(node_ptr != NULL) {
        printf("%d --> ", node_ptr->valor);
        node_ptr = node_ptr->next;
    }
    printf("NULL (Fim)\n");
}

int main() {
    // Em uma fila, as operações de inserção (enqueue) são feitas no último item
    // da fila, e as operações de remoção (dequeue) são feitas no primeiro item
    // da fila.

    printf("Fila c/ lista encadeada\n");
    Node* no = malloc(sizeof(Node));
    no->valor = 10;
    no->next = NULL;

    Fila* fila = malloc(sizeof(Fila));
    fila->primeiro = no;
    fila->ultimo = no;

    printf("Fila inicial: ");
    print_fila(fila);
    
    // Enfileirando (enqueue) alguns itens
    for(int i = 2; i <= 10; i++) {
        // Criando um novo nó...
        Node* novo_no = malloc(sizeof(Node));
        novo_no->valor = i*10;
        // e definindo ele como o último item. O antigo último irá apontar para o
        // novo nó.
        fila->ultimo->next = novo_no;
        fila->ultimo = novo_no;
    }

    printf("Fila c/ itens a mais: ");
    print_fila(fila);

    // Retirando (dequeue) alguns itens
    for(int i = 0; i < 3; i++) {
        // TODO
    }

    return 0;
}