#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *dir, *esq;
} Node;

Node* mknode(int valor) {
    Node* novo_no = malloc(sizeof(Node));
    novo_no->dir = NULL;
    novo_no->esq = NULL;
    novo_no->valor = valor;
    return novo_no;
}

Node* inserir(Node* no, int valor) {
    if(valor > no->valor) {
        if(no->dir != NULL) return inserir(no->dir, valor); // a direita já está ocupada
        
        // novo nó tem um valor maior que o pai -> novo nó vai pra direita
        Node* n = mknode(valor);
        no->dir = n;
        return n;
    } else if(valor < no->valor) {
        if(no->esq != NULL) return inserir(no->esq, valor); // a esquerda já está ocupada

        // novo nó tem um valor menor que o pai -> novo nó vai pra esquerda
        Node* n = mknode(valor);
        no->esq = n;
        return n;
    }

    return NULL;
}

void print_preordem(Node* no) {
    // ordem: raíz, esquerda, direita
    printf("%d ", no->valor);
    if(no->esq != NULL) print_preordem(no->esq);
    if(no->dir != NULL) print_preordem(no->dir);
}

void print_ordem(Node* no) {
    // ordem: esquerda, raíz, direita
    if(no->esq != NULL) print_ordem(no->esq);
    printf("%d ", no->valor);
    if(no->dir != NULL) print_ordem(no->dir);
}

void print_posordem(Node* no) {
    // ordem: esquerda, direita, raíz
    if(no->esq != NULL) print_posordem(no->esq);
    if(no->dir != NULL) print_posordem(no->dir);
    printf("%d ", no->valor);
}

Node* buscar(int valor) {
    return NULL;
}

void apagar(Node* no) {
    // ...
}

int main() {
    Node raiz;
    raiz.dir = NULL;
    raiz.esq = NULL;
    printf("Insira o valor da raíz: ");
    scanf("%d", &raiz.valor);

    while(1) {
        int temp;
        printf("Insira um valor: ");
        scanf("%d", &temp);
        inserir(&raiz, temp);
        
        printf("Visualização em ordem: ");
        print_ordem(&raiz);
        printf("\nVisualização em pré-ordem: ");
        print_preordem(&raiz);
        printf("\nVisualização em pós-ordem: ");
        print_posordem(&raiz);
        printf("\n");
    }
    return 0;
}