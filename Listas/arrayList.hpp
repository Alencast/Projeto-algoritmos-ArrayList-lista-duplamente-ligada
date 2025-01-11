#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

#include <stdexcept>  // Inclui exceções para lidar com erros em tempo de execução.
#include <string>   

class ArrayList {
    private:
        // Campos privados para gerenciar os dados e o estado da lista.
        int* data;                // Ponteiro para armazenar os elementos dinamicamente.
        unsigned int size_;       // Quantidade de elementos atualmente armazenados.
        unsigned int capacity_;   // Capacidade máxima antes de precisar realocar memória.

        // Métodos auxiliares privados para manipulação interna.
        void increase_capacity(); // Aumenta a capacidade do array, realocando memória.
        void check_capacity();    // Verifica se a capacidade é suficiente antes de inserir.

    public:
        // **Construtor e Destrutor**
        ArrayList();              // Inicializa uma lista vazia.
        ~ArrayList();             // Libera os recursos alocados dinamicamente.

        // **Operações de consulta (Get operations)**
        unsigned int size();              // Retorna o número de elementos na lista.
        unsigned int capacity();          // Retorna a capacidade máxima atual da lista.
        int& operator[](int index);       // Permite acessar elementos por índice (com suporte a modificação).
        double percent_occupied();        // Retorna a porcentagem de ocupação da capacidade.
        int back();                       // Retorna o último elemento.
        int front();                      // Retorna o primeiro elemento.
        int find_first(int value);        // Retorna o índice da primeira ocorrência de um valor.
        ArrayList find_all(int value);    // Retorna uma nova lista com todas as ocorrências de um valor.
        int count(int value);             // Conta quantas vezes o valor aparece na lista.
        int sum();                        // Calcula a soma de todos os elementos.
        int get_at(unsigned int index);   // Retorna o valor no índice especificado.

        // **Operações de inserção (Push operations)**
        void push_back(int value);               // Insere um elemento no final.
        void push_front(int value);              // Insere um elemento no início.
        void insert_at(unsigned int index, int value); // Insere um elemento em uma posição específica.

        // **Operações de remoção (Remove operations)**
        void clear();                            // Remove todos os elementos da lista.
        bool pop_back();                         // Remove o último elemento (retorna sucesso ou falha).
        bool pop_front();                        // Remove o primeiro elemento (retorna sucesso ou falha).
        bool remove_first(int value);            // Remove a primeira ocorrência de um valor.
        bool remove_quantity(int value, unsigned int quantity); // Remove até uma quantidade específica de um valor.
        bool remove_at(unsigned int index);      // Remove o elemento no índice especificado.
};

#endif
