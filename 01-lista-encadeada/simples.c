#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "node.h"

void print_elementos(Node cabeca) {
    Node* node_ptr = &cabeca;
    while(node_ptr != NULL) {
        printf("%d --> ", node_ptr->valor);
        node_ptr = node_ptr->next;
    }
    printf("NULL\n");
}

Node* indice_lista(Node cabeca, int idx) {
    Node* node_ptr = &cabeca;
    if(idx == 0) return node_ptr;
    for(int i = 0; i < idx; i++) {
        node_ptr = node_ptr->next;
        if(node_ptr == NULL) break;
    }
    return node_ptr;
}

int main() {
    // Uma lista encadeada é bem parecida com um vetor, exceto que cada elemento
    // (nó) aponta para os nós próximos. Em uma lista simples, cada nó aponta
    // para o elemento que vem depois dele (seu sucessor).
    //
    // A principal vantagem de uma lista encadeada é flexibilidade: ao invés de
    // alocar uma quantidade fixa de memória para um vetor e/ou usar malloc() 
    // e realloc() para expandí-la, é só adicionar um novo nó em qualquer ponto
    // da lista e ajustar os nós adjacentes adequadamente.
    Node cabeca;
    Node* rabo = &cabeca;
    cabeca.valor = 1;
    printf("Lista simplesmente encadeada\n");
    printf("Valor da cabeça: %d\n", cabeca.valor);
    
    printf("Inserindo um nó: ");
    Node* novo_node = malloc(sizeof(Node));
    novo_node->valor = 2;
    // O antigo rabo irá apontar para o novo nó como seu sucessor.
    // Como o novo nó não está apontando para algum outro nó, ele passa a ser
    // o novo rabo.
    rabo->next = novo_node;
    rabo = novo_node;
    printf("OK\n");
    print_elementos(cabeca);

    printf("Inserindo mais nós: ");
    for(int i = 3; i <= 10; i++) {
        // Repetindo o que foi feito acima algumas vezes
        Node* novo_node = malloc(sizeof(Node));
        novo_node->valor = i;
        rabo->next = novo_node;
        rabo = novo_node;
    }
    print_elementos(cabeca);

    printf("Inserindo um nó na posição 6: ");
    // Colocando o novo nó depois do 5º nó
    Node* pos5 = indice_lista(cabeca, 4);
    Node* n = malloc(sizeof(Node));
    n->valor = 1337;
    // Modificamos o 5º nó para apontar para o novo nó, e o novo nó para
    // apontar para o que antes era o 6º nó.
    // Antes:  ... > 4 > 5 > 6 > 7 > ...
    // Depois: ... > 4 > 5 > *1337* > 6 > 7 > ...
    // Generalizando: para inserir um nó na posição n, n-1 deve apontar
    // para n e n para n+1 como seus sucessores.
    n->next = pos5->next;   // 1337 --> 6
    pos5->next = n;         // 5 --> 1337
    print_elementos(cabeca);

    printf("Valor a partir do novo elemento: ");
    print_elementos(*n);

    printf("Apagando o nó na posicão 6: ");
    // Retornando o sucessor do 5º nó ao atual 7º nó, 
    // efetivamente apagando o 6º
    // Antes:  ... > 4 > 5 > *1337* > 6 > 7 > ...
    // Depois: ... > 4 > 5 > 6 > 7 > ...
    //         (1337 está fora da lista)
    // Isso é o inverso do processo para inserir um novo nó.
    Node* node_a_apagar = indice_lista(cabeca, 4);
    node_a_apagar->next = indice_lista(cabeca, 6);  // 5 --> 6
    free(n);
    print_elementos(cabeca);

    return 0;
}