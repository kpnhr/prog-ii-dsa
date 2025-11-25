# Árvores: conceitos gerais
- Estrutura de dados hierárqica, composta por nós interligados
- Ideal para busca rápida de dados, por ter uma estrutura não linear
- Principais aplicações: sistemas de arquivos, bancos de dados, compiladores, IA, ...
- Meios de visualização:
    - Natural
    - Organograma
    - Estrutura de pastas

## Estrutura
- O topo da árvore é chamada de raíz. 
- Um nó ligado a outros nós é pai, e os nós ligados a ele são filhos
- Nós sem filhos são as folhas da árvore
- O nível de um nó é a sua distãncia da raíz - quantos nós precisam ser percorridos a partir da raíz para chegar a ele
- Nós pais formam subárvores (conceito similar a conjuntos e subconjuntos)

# BST: Árvore de busca binária
- Visualização: https://www.cs.usfca.edu/~galles/visualization/BST.html
- O valor *menor* que a raíz/o pai fica na esquerda, e o valor *maior* que a raíz/o pai fica na direita
- Inserção: se o lado já estiver ocupado por um nó, avalie ele (e os seus filhos, caso necessário) até encontrar um nó com o lado livre
- Remoção:
    - Folha: basta apagar o nó
    - Nó com 1 filho: o filho sobe na posição do pai
    - Nó com 2 filhos: encontrar o nó mais a direita ou mais a esquerda e mover para a posição do nó a ser removido
- Busca: ...
- Visualização: direções são em função das subárvores. O fim de uma subárvore determina o valor a ser exibido
    - Ordem: Esquerda, Raíz, Direita
    - Pré-ordem: Raíz, Esquerda, Direita
    - Pós-ordem: Esquerda, Direita, Raíz