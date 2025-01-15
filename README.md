# Projeto ArrayList/Linked_List

Criei minha própria implementação de um Array List com alocação dinâmica e uma Lista Duplamente Ligada que simulam estruturas de dados como a lista do Python e o ArrayList do Java.

## Objetivo

O objetivo deste projeto é desenvolver habilidades com:

- Estruturas de dados complexas.
- Interação com a memória do computador.
- Análise de algoritmos.

## Pré-requisitos

- Compilador **G++**.

## Estruturas Implementadas

### Array List

Estrutura de dados feita com alocação dinâmica. Nela:

- A memória precisa ser liberada manualmente.
- Operações de inserção e remoção em índices específicos são menos eficientes, pois é necessário percorrer a lista para reposicionar elementos.

### Linked List
Estrutura de dado feita com lista duplamente ligada, nela alocamos um novo espaço de memória para cada nó dinamicamente e cada nó aponta para o próximo e o anterior. Sendo assim, esta estrutura de dado é mais eficiente para operações de inserção e remoção, entretanto, quando temos que achar um valor específico temos que percorrer a lista, sendo menos eficiente que o ArrayList.

## Métodos Implementados 

- size() → Retorna a quantidade de elementos na lista.
- capacity() → Retorna a capacidade total da lista. (Apenas Array List)
- percent_occupied() → Retorna a porcentagem de ocupação da lista. (Apenas Array List)
- back() → Retorna o último elemento.
- front() → Retorna o primeiro elemento.
- sum() → Retorna a soma de todos os elementos.
- count(int value) → Retorna a quantidade de ocorrências de um valor.
- find_first(int value) → Retorna o menor índice de um valor ou -1 se não encontrado.
- find(int value) → Retorna todos os índices de um valor como Array List.
- get_at(unsigned int index) → Retorna o valor no índice especificado.
- push_back(int value) → Adiciona um valor no final.
- push_front(int value) → Adiciona um valor no início.
- insert_at(unsigned int index, int value) → Insere um valor no índice especificado.
- clear() → Remove todos os elementos.
- pop_back() → Remove o último elemento.
- pop_front() → Remove o primeiro elemento.
- remove_first(int value) → Remove a primeira ocorrência de um valor.
- remove_quantity(int value, unsigned int quantity) → Remove uma quantidade especificada de um valor.
- remove_at(unsigned int index) → Remove o valor no índice especificado.
