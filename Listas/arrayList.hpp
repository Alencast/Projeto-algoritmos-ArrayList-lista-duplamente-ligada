#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

#include <stdexcept> // Inclui exceções para lidar com erros em tempo de execução.
#include <string>

class ArrayList
{
private:
    // Campos privados para gerenciar os dados e o estado da lista.
    int *data;              // Ponteiro para armazenar os elementos dinamicamente, deve iniciar com o valor 8.
    unsigned int size_;     // Quantidade de elementos atualmente armazenados.
    unsigned int capacity_; // Capacidade máxima antes de precisar realocar memória.

    // Métodos auxiliares privados para manipulação interna

    void increase_capacity() // Aumenta a capacidade do array, realocando memória.
    {
        capacity_ = capacity_ * 2;
        int *new_node = new int[capacity_]; // criar nova memória com o dobro da capacidade.

        for (unsigned int i = 0; i < size_; i++)
        {
            new_node[i] = data[i];
        }

        int *old_data = data;
        data = new_node;
        delete[] old_data;
    }
    void check_capacity()
    { // Verifica se a capacidade é suficiente antes de inserir.
        if (size_ == capacity_)
        {
            increase_capacity();
        }
    }

public:
    // **Construtor e Destrutor**

    ArrayList()
    {
        this->size_ = 0;
        this->capacity_ = 8;
        this->data = new int[capacity_];
    }

    ~ArrayList()
    {
        delete[] data;
    }

    // **Operações de consulta (Get operations)**

    unsigned int size()
    { // Retorna o número de elementos na lista.
        return size_;
    }

    unsigned int capacity()
    { // Retorna a capacidade máxima atual da lista.
        return capacity_;
    }

    double percent_occupied()
    { // Retorna a porcentagem de ocupação da capacidade.
        return (static_cast<double>(size_) / static_cast<double>(capacity_));
    }

    void insert_at(unsigned int index, int value)
    { // Insere elemento no índice index
        check_capacity();

        if (index == 0)
        {
            push_front(value);
        }
        else if (index == size_)
        {
            push_back(value);
        }
        else
        {
            size_++;

            // Itera a lista de trás para frente, movendo os elementos para abrir espaço no índice desejado.
            for (unsigned int i = size_; i > index; i--)
            {
                data[i] = data[i - 1];
            }

            data[index] = value;
        }
    }

    bool remove_at(unsigned int index)
    {
        bool exc = false;

        if (index == 0)
        {
            exc = pop_front();
        }
        else if (index == (size_ - 1))
        {
            exc = pop_back();
        }
        else
        {
            for (unsigned int i = index; i < (size_ - 1); i++)
            {
                data[i] = data[i + 1];
            }
            exc = true;
            size_--;
        }

        return exc;
    }

    int get_at(unsigned int index)
    {
        return data[index];
    }

    void clear()
    {
        capacity_ = 8;
        size_ = 0;
        int *old_data = data;
        int *new_node = new int[capacity_];
        data = new_node;

        delete[] old_data;
    }

    // **Operações de inserção (Push operations)**
    void push_back(int value)
    { // Insere um elemento no final.
        check_capacity();

        data[size_] = value;
        size_++;
    }
    void push_front(int value)
    { // Insere um elemento no início.
        check_capacity();

        size_++;

        for (unsigned int i = size_; i > 0; i--)
        {
            data[i] = data[i - 1];
        }

        data[0] = value;
    }

    bool pop_back()
    { // Remove o último elemento (retorna true ou false).
        bool exc = false;

        if (size_ == 0)
        {
            throw std::runtime_error("Lista vazia, não foi possível remover o item desejado.");
        }
        else
        {
            exc = true;
            size_--;
        }

        return exc;
    }

    bool pop_front()
    { // Remove o primeiro elemento (retorna true ou false).
        bool exc = false;
        if (size_ == 0)
        {
            throw std::runtime_error("Lista vazia, não foi possível remover o primeiro elemento da lista.");
        }
        else
        {
            for (unsigned int i = 0; i < (size_ - 1); i++)
            {
                data[i] = data[i + 1];
            }
            size_--;
            exc = true;
        }
        return exc;
    }

    int back()
    { // Retorna o último elemento.
        if (size_ == 0)
        {
            throw std::out_of_range("Lista vazia, não foi possível retornar o último elemento.");
        }
        else if (size_ == 1)
        {
            return data[0];
        }
        else
        {
            return data[size_ - 1]; // Retorna o tamanho da lista -1, para pegar o index do último elemento.
        }
    }
    int front()
    { // Retorna o primeiro elemento.
        if (size_ == 0)
        {
            throw std::out_of_range("Lista vazia, não foi possível retornar o primeiro elemento.");
        }
        else
        {
            return data[0];
        }
    }

    int find(int value)
    {
        for (unsigned int i = 0; i < this->size_; i++)
        {
            if (data[i] == value)
            {
                return i; // Retorna o índice da primeira ocorrência do valor.
            }
        }
        return -1; // Retorna -1 se o valor não for encontrado.
    }

    int count(int value)
    {
        int score = 0;

        if (size_ == 1)
        {
            if (*data == value)
            {
                score++;
            }
        }
        else
        {
            int *start = data;
            int *end = (size_ - 1) + data;

            unsigned int halfsize = size_ / 2;

            if (size_ % 2 != 0)
            {
                halfsize++;
            }

            for (unsigned int i = 0; i < halfsize; i++)
            {
                if (*end == value)
                {
                    score++;
                }

                if (*start == value)
                {
                    score++;
                    break;
                }

                if (start == end)
                {
                    break;
                }

                start++;
                end--;
            }
        }

        return score;
    }

    int sum()
    {
        int result = data[0];

        for (unsigned int i = 1; i < size_; i++)
        {
            result += data[i];
        }

        return result;
    }
};

#endif // __ARRAY_LIST_IFRN__
