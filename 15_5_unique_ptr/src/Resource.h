#pragma once

#include <iostream>

class Resource {
private:
    int m_length;
    int *m_arr = nullptr;
public:
    Resource(const int &length_in = 0): m_length(length_in) {
        m_arr = new int [length_in];
    }

    Resource(const Resource &res_in): Resource(res_in.m_length) {
        for (auto i = 0; i < m_length; i++)
            m_arr[i] = res_in.m_arr[i];
    }

    ~Resource(){
        if (m_arr != nullptr)
            delete m_arr;
    }

    void setAll(const int &num_in){
        for (auto  i = 0; i < m_length; i++)
            m_arr[i] = num_in;
    }

    void print() const {
        for (auto i = 0; i < m_length; i++)
            std::cout << m_arr[i] << " ";
        std::cout << std::endl;
    }

    friend std::ostream& operator<< (std::ostream& out, const Resource &res_in){
        for (auto i = 0; i < res_in.m_length; i++)
            out << res_in.m_arr[i] << " ";
        return out;
    }

};