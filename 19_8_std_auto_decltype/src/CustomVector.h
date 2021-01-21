#pragma once

#include <iostream>
#include <string>
#include <utility>

using namespace std;

class CustomVector {
public:
    unsigned m_size;
    int *m_data = nullptr;

public:
    CustomVector(const unsigned &size_in, const int &data_in=0){
        cout << "Constructor" << endl;
        init(size_in, data_in);
    }

    CustomVector(const CustomVector &vec_in){
        cout << "Copy Constructor" << endl;

        init(vec_in.m_size);
        for (auto i = 0; i < m_size; i++)
            m_data[i] = vec_in.m_data[i];  
    }

    CustomVector(CustomVector &&vec_in){
        cout << "Move Constructor" << endl;

        m_size = vec_in.m_size;
        m_data = vec_in.m_data;

        vec_in.m_size = 0;
        vec_in.m_data = nullptr;
    }

    void init(const unsigned &size_in, const int &data_in=0){
        m_size = size_in;
        m_data = new int [m_size];

        for (auto i = 0; i < m_size; i++)
            m_data[i] = data_in;        
    }

    ~CustomVector(){
        if (m_data != nullptr)
            delete[] m_data;
    }
};