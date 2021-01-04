#pragma once 

#include <initializer_list>
#include <iostream>
#include <cassert>
#include <bitset>


template <typename T>
class Storage8 {
private:
    T m_arr[8];

public:
    void set(const int &index, const T &val_in){
        m_arr[index] = val_in;
    }

    T& get(const int &index){
        return m_arr[index];
    }
};

template <>
class Storage8<bool> {
private:
    unsigned char m_arr = 0;
public:

    // Let's think about how it works.
    void set(int index, bool val_in){
        
        unsigned char val = 1 << index;

        if (val_in)
            m_arr |= val;
        else
            m_arr &= ~val;
    }

    bool get(const int &index){

        unsigned char val = 1 << index;

        return (m_arr & val) != 0;
    }
};