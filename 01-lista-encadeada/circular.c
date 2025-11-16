#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "node.h"

void print_elementos(Node cabeca) {
    Node* node_ptr = &cabeca;
    int i = 0;
    while(node_ptr != NULL && i <= 30) {
        printf("%d --> ", node_ptr->valor);
        node_ptr = node_ptr->next;
        i++;
    }
    printf("...\n");
}

int main() {
    // Uma lista circular pode ser ou não ser considerada um tipo independente,
    // já que uma lista simples ou duplamente encadeada pode também ser
    // circular. Esse código demonstra a lista circular simples.
    Node cabeca;
    Node* rabo = &cabeca;
    cabeca.valor = 1;
    for(int i = 2; i <= 10; i++) {
        // Repetindo o que foi feito acima algumas vezes
        Node* novo_node = malloc(sizeof(Node));
        novo_node->valor = i;
        rabo->next = novo_node;
        rabo = novo_node;
    }

    // Isso torna a lista circular. O rabo aponta para o começo da lista.
    rabo->next = &cabeca;
    print_elementos(cabeca);
}