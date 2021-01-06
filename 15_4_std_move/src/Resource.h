#pragma once

#include <iostream>

template <typename T>
class Resource {
private:
    T *m_arr = nullptr;
    int m_length;
public:
    Resource(const int &length_in = 0): m_length(length_in) {
        std::cout << "Resouce Default Constructor" << std::endl;

        m_arr =  new T [m_length];
    }

    Resource(const Resource &res_in): Resource(res_in.m_length){
        std::cout << "Resource Copy Constructor" << std::endl;

        for (auto i = 0; i < m_length; i++)
            m_arr[i] = res_in.m_arr[i];
    }

    ~Resource(){
        std::cout << "Resource Destructor" << std::endl;

        if (m_arr != nullptr)
            delete m_arr;
    }

    Resource& operator= (const Resource &res_in){
        std::cout << "Resource Copy Assignment" << std::endl;

        if (&res_in == this)
            return *this;
        
        if (m_arr != nullptr)
            delete m_arr;

        m_length = res_in.m_length;
        
        m_arr = new T [m_length];
        for (auto i = 0; i < m_length; i++)
            m_arr[i] = res_in.m_arr[i];

        return *this;   
    }
    
    void print(){
        for (auto i = 0; i < m_length; i++)
            std::cout <<  m_arr[i] << " ";
        
        std::cout << std::endl;
    }

    void setAll(const int &i_in){
        for (auto i = 0; i < m_length; i++)
            m_arr[i] = i_in;
    }

    
};