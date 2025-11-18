#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
    int valor;
    struct Node* next;
} Node;

typedef struct Pilha {
    Node* topo;
    //int tamanho;
} Pilha;

void print_pilha(Pilha* p) {
    Node* node_ptr = p->topo;
    print("(Topo) ");
    while(node_ptr != NULL) {
        printf("%d --> ", node_ptr->valor);
        node_ptr = node_ptr->next;
    }
    printf("NULL\n");
}

int main() {
    // Uma pilha pode ser implementada com uma lista encadeada, onde todas as
    // operações de inserção (push) e remoção (pop) são feitas exclusivamente na
    // cabeça. As outras operações (peek) são praticamente as mesmas usadas em uma
    // lista encadeada.
    printf("Pilha c/ lista encadeada\n");
    Node* no = malloc(sizeof(Node));
    no->valor = 10;
    no->next = NULL;

    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->topo = no;

    printf("Pilha inicial: ");
    print_pilha(pilha);

    // Empurrando (push) alguns itens na pilha.
    for(int i = 2; i <= 10; i++) {
        // Criando um nó que aponta para a antiga cabeça...
        Node* novo_no = malloc(sizeof(Node));
        novo_no->valor = i*10;
        novo_no->next = pilha->topo;
        // e definindo ele como o topo da pilha.
        pilha->topo = novo_no;
    }
    
    printf("Pilha c/ itens a mais: ");
    print_pilha(pilha);

    // Retirando (pop) alguns itens
    for(int i = 0; i < 3; i++) {
        // Basta mover o topo da pilha para baixo. O topo da pilha é a cabeça
        // da lista encadeada, então tudo antes da cabeça efetivamente não existe.
        Node* antigo_topo = pilha->topo;
        pilha->topo = antigo_topo->next;
        free(antigo_topo);
    }

    printf("Pilha c/ itens a menos: ");
    print_pilha(pilha);

    // Vale ressaltar que todas as operações de *leitura* de uma lista simplesmente
    // encadeada também funcionam em uma pilha. Por definição, as operações de
    // *escrita* devem ocorrer apenas no topo. A leitura de um item abaixo do topo
    // da pilha é chamado de "peek".

    return 0;
}