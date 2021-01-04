#pragma once 

#include <initializer_list>
#include <iostream>
#include <cassert>

template <typename T, unsigned int T_SIZE>
class MyArray {
private:
    T *m_arr;
public:
    MyArray(){
        m_arr = new T [T_SIZE];
    }

    // caution, Constructor must be called for initialization 
    MyArray(const std::initializer_list<T> &list): MyArray(){
        int i = 0;

        for (auto &elem : list)
            m_arr[i++] = elem;
    }

    ~MyArray(){
        delete[] m_arr;
    }

    // Just keep Methods in Class
    // sucks even with exaplicit instantiation
    int getLength() const {
        return T_SIZE;
    }

    int& operator[] (const int &index){
        assert( index >= 0 );
        assert( index < T_SIZE );
        return m_arr[index];
    }

    friend std::ostream& operator<<(std::ostream &out, const MyArray& arr_in){
        for (auto i = 0; i < T_SIZE; i++)
            out << arr_in.m_arr[i] << " ";
        return out;
    }

};