# Listas Encadeadas (simples, duplas e circulares)

## Motivação e contexto histórico
- Estruturas fixas (vetores e matrizes): coleção de dados do mesmo tipo
    - Desvantagens: restrições de tamanho da estrutura e seus dados, inserção e exclusão

## Listas encadeadas
- As listas encadeadas são estruturas dinâmicas (tamanho flexível) composta por nós, que armazenam um valor e um ponteiro pro próximo nó.
- Diferentemente dos vetores e matrizes, os elementos da lista não estão necessariamente em regiões contíguas da memória.
    - O índice de um vetor/matriz indica a posição a partir do ponteiro dele
    - Nas listas encadeadas, o índice indica a posição do nó a partir da cabeça da lista (ou, quantos nós o programa precisa "andar" para alcançar o índice)
- As listas encadeadas facilitam a variação de tamanho da estrutura durante a execução; elementos podem ser inseridos e removidos sem mover os outros elementos ou desperdiçar memória

### Lista simplesmente encadeada
Cada nó possui um ponteiro que aponta pro próximo nó da lista. O último nó possui um ponteiro nulo, indicando o fim da estrutura.

### Lista duplamente encadeada
Cada nó possui dois ponteiros para o nó antecedente e consequente, permitindo que o programa percorra em ambas as direções da lista.

### Lista circular
Ao invés do último nó ter um ponteiro nulo, ele aponta pro nó inicial (a cabeça), criando um círculo. Pode ser simples ou duplo.