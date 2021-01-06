#pragma once

#include <iostream>

class Resource {
private:
    int *m_arr = nullptr;
    int m_length;
public:
    Resource(){
        m_arr = nullptr;
        m_length = 0;
    }

    Resource(const int &len_in): m_length(len_in){
        std::cout << "Resource default constructor" << std::endl;
        m_arr = new int [len_in];
    }
    
    Resource(const Resource &res_in ): m_length(res_in.m_length){
        std::cout << "Resource copy constructor" << std::endl;
        
        m_arr = new int [m_length];

        // implement deep copy with
        for (auto i = 0; i < m_length; i++)
            m_arr[i] = res_in.m_arr[i];        
    }

    ~Resource(){
        std::cout << "Resource destructor" << std::endl;

        if(m_arr)
            delete m_arr;
    }

    Resource& operator= (const Resource &res_in){
        std::cout << "Resource copy assignment" << std::endl;

        if (this == &res_in)
            return *this;
    
        if (m_arr != nullptr)
            delete m_arr;
        
        m_length = res_in.m_length;

        // implement deep copy with
        m_arr = new int [m_length];
        
        for (auto i = 0; i < m_length; i++)
            m_arr[i] = res_in.m_arr[i];  

        return *this;
    }

    void print(){
        for (auto i = 0; i < m_length; i++){
            std::cout << m_arr[i] << " ";
        }
        std::cout << std::endl;
    }
};