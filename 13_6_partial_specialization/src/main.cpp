#include <string.h>
#include <iostream>


template <typename T, int size>
class StaticArray_BASE
{
private:
    T m_array[size];
public:
    T* getArray() { return m_array; }

    T& operator[](int index)
    {
        return m_array[index];
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            std::cout << (*this)[i] << ' ';
        std::cout << std::endl;
    }
};

template <typename T, int size>
class StaticArray: public StaticArray_BASE<T, size>
{
};

template <int size>
class StaticArray<char, size>: public StaticArray_BASE<char, size>
{
public:
    void print()
    {
        for (int i = 0; i < size; i++)
            std::cout << (*this)[i] << ' ';
        std::cout << std::endl;
    }
};

int main(){

    using namespace std;

    {
        StaticArray<int, 4> int4;
        int4[0] = 1;
        int4[1] = 2;
        int4[2] = 3;
        int4[3] = 4;

        int4.print();

        StaticArray<char, 14> char14;
        char14[0] = 'H';
        char14[0] = 'e';
        // ...
        strcpy(char14.getArray(), "Hello, World");

        char14.print();
    }

    return 0;
}