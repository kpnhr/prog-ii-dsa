#include <stddef.h>

// O primeiro Node é pra declarar o nome "Node"
// Sem ele, o gcc mostra avisos de tipos de ptr incompatível
typedef struct Node {
    int valor;
    struct Node* prev;
    struct Node* next;
} Node;