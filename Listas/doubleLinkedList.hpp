#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__
#include <string>
#include <stdexcept>

class linked_list
{
private:
    struct int_node
    {
        int value;
        int_node *next, *prev;
    };
    int_node *head, *tail;
    unsigned int size_;

public:
    // **Construtor e Destrutor**
    linked_list()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }
    ~linked_list()
    {
        for (unsigned int i = 0; i < size_; i++)
        {
            if (i == (size_ - 1))

            {
                delete tail;
                head = nullptr;
                tail = nullptr;
                size_ = 0;
            }

            else
            {

                tail = tail->prev;
                delete tail->next;
            }
        }
    }
    unsigned int size()
    { // Retorna a quantidade de elementos armazenados
        return size_;
    }

    bool insert_at(unsigned int index, int value)
    {
        // Verificar se o índice é válido
        if (index > size_ || index < 0)
        {
            return false; // Índice inválido
        }

        // Criar um novo node
        int_node *new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = nullptr;

        if (index == 0)
        {
            // Inserção no início
            if (head == nullptr)
            {
                // Lista vazia
                head = tail = new_node;
            }
            else
            {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }
        else if (index == size_)
        {
            // Inserção no final
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
        else
        {
            // Inserção no meio
            int_node *current = head;
            for (unsigned int i = 0; i < index; i++)
            {
                current = current->next;
            }

            new_node->prev = current->prev;
            new_node->next = current;
            current->prev->next = new_node;
            current->prev = new_node;
        }

        // Atualizar o tamanho
        size_++;
        return true;
    }
    // Insere elemento no índice index
    bool insert_at(unsigned int index, int value)
    {
        // Verificar se o índice é válido
        if (index > size_ || index < 0)
        {
            return false; // Índice inválido
        }

        // Criar um novo nó
        int_node *new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = nullptr;

        if (index == 0)
        {
            // Inserção no início
            if (head == nullptr)
            {
                // Lista vazia
                head = tail = new_node;
            }
            else
            {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }
        else if (index == size_)
        {
            // Inserção no final
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
        else
        {
            // Inserção no meio
            int_node *current = head;
            for (unsigned int i = 0; i < index; i++)
            {
                current = current->next;
            }

            new_node->prev = current->prev;
            new_node->next = current;
            current->prev->next = new_node;
            current->prev = new_node;
        }

        // Atualizar o tamanho
        size_++;
        return true;
    }

    bool remove_at(unsigned int index)
    {
        // Verificar se o índice é válido
        if (index >= size_ || index < 0)
        {
            return false; // Índice inválido
        }

        int_node *to_delete = nullptr;

        if (index == 0)
        {
            // Remover do início
            to_delete = head;
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                // Lista ficou vazia
                tail = nullptr;
            }
        }
        else if (index == size_ - 1)
        {
            // Remover do final
            to_delete = tail;
            tail = tail->prev;
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {
                // Lista ficou vazia
                head = nullptr;
            }
        }
        else
        {
            // Remover do meio
            int_node *current = head;
            for (unsigned int i = 0; i < index; i++)
            {
                current = current->next;
            }
            to_delete = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        // Deletar o node
        delete to_delete;

        // Atualizar o tamanho
        size_--;
        return true;
    }

    int get_at(unsigned int index)
    {
        if (size_ <= 0 || index >= size_)
        {
            std::string error_msg = "Index inválido";
            throw std::out_of_range(error_msg);
        }

        int_node *current = head;
        for (unsigned int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->value;
    }
    // Retorna elemento no índice index,

    // −1 se índice inválido

    void clear()
    { // Remove todos os elementos, deixando o vetor no estado inicial
        for (unsigned int i = 0; i <= size_; i++)
        {
            if (i == (size_ - 1))
            {
                delete tail;
                size_ = 0;
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                tail = tail->prev;
                delete tail->next;
            }
        }
    }

    void push_back(int value)
    { // Adiciona um elemento no ``final'' do vetor
        // Criar um novo node
        int_node *new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = nullptr;

        if (head == nullptr)
        {
            // Lista vazia
            head = tail = new_node;
        }
        else
        {
            // Inserir no final
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }

        // Atualizar o tamanho
        size_++;
    }

    void push_front(int value)
    { // Adiciona um elemento no ``início'' do vetor
        // Criar um novo node
        int_node *new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = nullptr;

        if (head == nullptr)
        {
            // Lista vazia
            head = tail = new_node;
        }
        else
        {
            // Inserir no início
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }

        // Atualizar o tamanho
        size_++;
    }

    bool pop_back()
    { // Remove um elemento do ``final'' do vetor
        if (tail == nullptr)
        {
            // Lista vazia
            return false;
        }

        int_node *to_delete = tail;

        if (head == tail)
        {
            // Apenas um elemento na lista
            head = tail = nullptr;
        }
        else
        {
            // Remover o último elemento
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete to_delete;
        size_--;

        return true;
    }

    bool pop_front()
    { // Remove um elemento do ""início'' do vetor
        if (head == nullptr)
        {
            // Lista vazia
            return false;
        }

        int_node *to_delete = head;

        if (head == tail)
        {
            //  Caso tenha apenas um elemento na lista
            head = tail = nullptr;
        }
        else
        {
            // Remover o primeiro elemento
            head = head->next;
            head->prev = nullptr;
        }

        delete to_delete;
        size_--;

        return true;
    }

    int back()
    { // Retorna o elemento do "final" do vetor
        if (tail == nullptr)
        {
            // Lista vazia
            throw std::out_of_range("Lista vazia. Não foi possível retornar o elemento final.");
        }
        return tail->value;
    }
    int linked_list::front()
    { // Retorna o elemento do "final" do vetor
        if (head == nullptr)
        {
            throw std::out_of_range("Lista vazia. Não foi possíível retornar o elemento inicial.");
        }

        return head->value;
    }
    bool remove(int value)
    { // Remove value do vetor caso esteja presente
        if (head == nullptr)
        {
            // Lista vazia
            return false;
        }

        int_node *current = head;

        while (current != nullptr)
        {
            if (current->value == value)
            {
                // Encontrou o valor

                if (current == head)
                {
                    // Remover do inicio
                    head = head->next;
                    if (head != nullptr)
                    {
                        head->prev = nullptr;
                    }
                    else
                    {
                        // Se o novo head for nulo, significa que a lista ficou  vazia.
                        tail = nullptr;
                    }
                }
                else if (current == tail)
                {
                    // Remover do final
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                else
                {
                    // Remover do meio
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                delete current;
                size_--;
                return true;
            }

            current = current->next;
        }

        // Valor não encontrado
        return false;
    }

    int find(int value)
    {
        int_node *current = head;
        int index = 0;

        // Percorre a lista até encontrar o valor ou até chegar ao final
        while (current != nullptr)
        {
            if (current->value == value)
            {
                return index;
            }
            current = current->next; // Avança para o próximo node
            index++;
        }

        return -1; // Retorna -1 se o valor não for encontrado
    }

    int count(int value)
    { // Retorna quantas vezes value occorre no vetor
        int_node *current = head;
        int counter = 0;

        while (current != nullptr)
        {
            if (current->value == value)
            {
                counter++;
            }

            current = current->next;
        }
        return counter;
    }

    int sum()
    { // Retorna a soma dos elementos do vetor
        int_node *current = head;
        int sum = 0;

        while (current != nullptr)
        {
            sum += current->value;
            current = current->next;
        }

        return sum;
    }
};
#endif // __LINKED_LIST_IFRN__
