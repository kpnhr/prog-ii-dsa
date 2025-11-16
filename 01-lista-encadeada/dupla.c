#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "node.h"

void print_elementos(Node cabeca, int dir) {
    Node* node_ptr = &cabeca;
    while(node_ptr != NULL) {
        printf("%d <--> ", node_ptr->valor);
        if(dir) {
            // Quando dir=1, a lista será percorrida de trás pra frente.
            node_ptr = node_ptr->prev;
        } else {
            node_ptr = node_ptr->next;
        }
    }
    printf("NULL\n");
}

Node* indice_lista(Node cabeca, int idx, int dir) {
    Node* node_ptr = &cabeca;
    if(idx == 0) return node_ptr;
    for(int i = 0; i < idx; i++) {
        if(dir) {
            // Igual ao print_elementos().
            node_ptr = node_ptr->prev;
        } else {
            node_ptr = node_ptr->next;
        }
        if(node_ptr == NULL) break;
    }
    return node_ptr;
}


int main() {
    // Uma lista duplamente encadeada é diferente da simplesmente encadeada pela
    // existência de um ponteiro de nó antecessor, além do ponteiro sucessor.
    // Apesar de complicar mais a modificação da lista, esse tipo permite
    // a busca bidirecional de elementos.
    Node cabeca;
    Node* rabo = &cabeca;
    cabeca.valor = 1;
    for(int i = 2; i <= 10; i++) {
        Node* novo_node = malloc(sizeof(Node));
        novo_node->valor = i;
        // O novo nó irá apontar para o antigo rabo da lista como seu nó anterior,
        // e o antigo rabo irá apontar para o novo nó como seu nó sucessor.
        rabo->next = novo_node;
        novo_node->prev = rabo;
        rabo = novo_node;
    }
    print_elementos(cabeca, 0);
    print_elementos(*rabo, 1);

    Node* pos4_norm = indice_lista(cabeca, 3, 0);
    Node* pos4_inv = indice_lista(*rabo, 3, 1);

    printf("Posição #4, direção normal: %d\n", pos4_norm->valor);
    printf("    - Nós próximos de #4: %d <--> %d <--> %d\n", 
        pos4_norm->prev->valor, pos4_norm->valor, pos4_norm->next->valor);

    printf("Posição #4, direção invertida: %d\n", pos4_inv->valor);
    printf("    - Nós próximos de #4: %d <--> %d <--> %d\n", 
        pos4_inv->prev->valor, pos4_inv->valor, pos4_inv->next->valor);

    printf("Inserindo um nó em #4: ");
    // Para inserir o novo nó, precisamos fazer o 3º nó apontar pro novo nó
    // como seu sucessor, e o antigo 4º nó para ele como seu antecessor.
    // Antes:  ... <--> 2 <--> 3 <--> 4 <--> 5 <--> ...
    // Depois: ... <--> 2 <--> 3 <--> *1337* <--> 4 <--> 5 <--> ...
    // De modo geral, para inserir um nó na posição n, o nó n-1 deverá apontar
    // para n como seu sucessor e n para n-1 como antecessor; o mesmo deverá ser
    // feito entre n+1 e n, invertendo o antecessor e sucessor.
    Node* novo_node = malloc(sizeof(Node));
    novo_node->valor = 1337;

    novo_node->prev = pos4_norm->prev;  // 3 <-- 1337
    pos4_norm->prev->next = novo_node;  // 3 --> 1337
    novo_node->next = pos4_norm;        // 1337 --> 4
    pos4_norm->prev = novo_node;        // 1337 <-- 4
    
    print_elementos(cabeca, 0);
    print_elementos(*rabo, 1);

    printf("Removendo #4: ");
    pos4_norm = indice_lista(cabeca, 3, 0); // atualizando com o novo #4
    // Remover um nó é mais simples: precisamos apenas alterar o ponteiro
    // sucessor do 3º nó para o 5º e o ponteiro antecessor do 5º para o 3º.
    // Antes:  ... <--> 2 <--> 3 <--> *1337* <--> 4 <--> 5 <--> ...
    // Depois: ... <--> 2 <--> 3 <--> 4 <--> 5 <--> ...
    pos4_norm->prev->next = pos4_norm->next;
    pos4_norm->next->prev = pos4_norm->prev;
    free(pos4_norm);
    print_elementos(cabeca, 0);
    print_elementos(*rabo, 1);

    return 0;
}