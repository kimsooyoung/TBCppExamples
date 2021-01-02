#pragma once

#include <initializer_list>
#include <iostream>
#include <cassert>
#include <string>


template <typename T>
class MyArray {
private:
    int m_size;
    T *m_arr = nullptr;
public:
    MyArray(const int &size_in=0): m_size(size_in) {
        m_arr = new T [m_size];
    }

    MyArray(const std::initializer_list<T>&list): MyArray(list.size()){
        int i = 0;
        for (auto &elem : list)
            m_arr[i++] = elem;
    }
    
    ~MyArray(){
        delete[] m_arr;
    }

    void set(const int &index, const T &val);

    void reset(){
        if(m_arr){
            delete[] m_arr;
            m_arr = nullptr;
        }
        m_size = 0;
    }

    int getLength();

    T& operator[] (const int &index);
    
    friend std::ostream& operator<<(std::ostream& out, const MyArray &myarr_in){
        for (auto i = 0; i < myarr_in.m_size; i++)
            out << myarr_in.m_arr[i] << " ";
        
        return out;
    }

};

