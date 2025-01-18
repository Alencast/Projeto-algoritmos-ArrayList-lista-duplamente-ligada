#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__
class array_list
{
private:
    int *data;
    unsigned int size_, capacity_;
    void increase_capacity()
    { // Aumentar a capacidade da lista
        capacity_ *= 2;
        int *old_data = data;
        int *new_data = new int[capacity_];

        for (int i = 0; i < size_; i++)
        {
            new_data[i] = old_data[i];
        }
        delete[] old_data;
        data = new_data;
    }

public:
    array_list()
    { // Construtor
        this->size_ = 0;
        this->capacity_ = 8;
        this->data = new int[capacity_];
    }
    ~array_list()
    { // Destrutor
        delete[] data;
    }
    unsigned int size()
    { // Retorna a quantidade de elementos armazenados
        return this->size_;
    }
    unsigned int capacity()
    { // Retorna o espaço reservado para armazenar os elementos

        return this->capacity_;
    }
    double percent_occupied()
    { // Retorna um valor entre 0.0 a 1.0 com o percentual da memória usada.
        return static_cast<double>(size_) / static_cast<double>(capacity_);
    }

    bool insert_at(unsigned int index, int value)
    { // Insere elemento no índice index
        if (index > size_ or index < 0)
        {
            return false;
        }

        if (size_ == capacity_)
        {
            increase_capacity();
        }

        for (unsigned int i = size_; i > index; i--)
        {
            data[i] = data[i - 1];
        }

        data[index] = value;

        size_++;

        return true;
    }
    bool remove_at(unsigned int index)
    { // Remove elemento do índice index
        if (index >= size_)
        {
            return false;
        }

        for (unsigned int i = index; i < size_ - 1; i++)
        {
            data[i] = data[i + 1];
        }
        data[size_ - 1] = 0;
        size_--;
        return true;
    }
    int get_at(unsigned int index)
    { // Retorna elemento no índice index, −1 se índice inválido

        if (index >= size_)
        {

            return -1;
        }

        return data[index];
    }

    void clear()
    { // Remove todos os elementos, deixando o vetor no estado inicial
        delete[] data;
        this->size_ = 0;
        this->capacity_ = 8;
        this->data = new int[8];
    }
    void push_back(int value)
    { // Adiciona um elemento no "final" do vetor
        if (size_ == capacity_)
        {
            increase_capacity();
        }

        data[size_] = value;
        size_++;
    }
    void push_front(int value)
    { // Adiciona um elemento no "inicio" do vetor
        if (size_ == capacity_)
        {

            increase_capacity();
        }
        for (int i = size_; i > 0; i--)
        {

            data[i] = data[i - 1];
        }
        size_++;
        data[0] = value;
    }
    bool pop_back()
    { // Remove um elemento do "final" do vetor

        if (size_ == 0)
        {
            return false;
        }

        size_--;
        return true;
    }

    bool pop_front()
    { // Remove um elemento do "inicio" do vetor

        if (size_ == 0)
        {
            return false;
        }
        for (int i = 0; i < size_ - 1; i++)
        {

            data[i] = data[i + 1];
        }
        data[size_ - 1] = 0;
        size_--;
        return true;
    }
    int back()
    { // Retorna o elemento do "final" do vetor

        if (size_ == 0)
        {

            return -1;
        }
        return data[size_ - 1];
    }

    int front()
    { // Retorna o elemento do "inicio" do vetor

        if (size_ == 0)
        {

            return -1;
        }

        return data[0];
    }
    bool remove(int value)
    { // Remove value do vetor caso esteja presente
        if (size_ == 0)
        {
            return false;
        }
        for (int i = 0; i < size_; i++)
        {

            if (data[i] == value)
            {

                remove_at(i);
                i--;
            }
        }
        return true;
    }
    int find(int value)
    { // Retorna o índice de value, −1 caso value não esteja presente

        if (size_ == 0)
        {

            return -1;
        }

        for (int i = 0; i < size_; i++)
        {

            if (data[i] == value)
            {

                return i;
            }
        }

        return -1;
    }
    int count(int value)
    { // Retorna quantas vezes value occorre no vetor
        if (size_ == 0)
        {
            return -1;
        }
        int count = 0;

        for (int i = 0; i < size_; i++)
        {

            if (data[i] == value)
            {
                count++;
            }
        }

        return count;
    }

    int sum()
    { // Retorna a soma dos elementos do vetor
        int sum = 0;
        if (size_ == 0)
        {
            return 0;
        }
        for (int i = 0; i < size_; i++)
        {
            sum += data[i];
        }
        return sum;
    }
};
#endif // __ARRAY_LIST_IFRN__
