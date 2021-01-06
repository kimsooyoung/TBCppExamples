#pragma once 

#include <iostream>
 
template <typename T> 
class AutoPtr {
public:
    T* m_ptr;
public:
    AutoPtr(T* const &ptr_in=nullptr) {
        std::cout << "AutoPtr Default Constructor with L value" << std::endl;

        m_ptr = new T;
        *m_ptr = *ptr_in;
    }

    AutoPtr(T* const &&ptr_in=nullptr): m_ptr(ptr_in) {
        std::cout << "AutoPtr Default Constructor with R value" << std::endl;
    }

    ~AutoPtr() {
        std::cout << "AutoPtr Destructor" << std::endl;
        
        if (m_ptr != nullptr)
            delete m_ptr;
    }

    AutoPtr(const AutoPtr &ptr_in) {
        std::cout << "AutoPtr Copy Constructor" << std::endl;

        m_ptr = new T;
        *m_ptr = *ptr_in.m_ptr;
    }

    AutoPtr& operator= (AutoPtr &ptr_in){
        std::cout << "AutoPtr Copy Assignment" << std::endl;

        if (this == &ptr_in)
            return *this;

        if (m_ptr != nullptr)
            delete m_ptr;
        
        m_ptr = new T;
        *m_ptr = *ptr_in.m_ptr;

        return *this;
    }

    AutoPtr(AutoPtr &&ptr_in){
        std::cout << "AutoPtr Move Constructor" << std::endl;

        m_ptr = ptr_in.m_ptr;
        ptr_in.m_ptr = nullptr; 
    }

    AutoPtr& operator= (AutoPtr &&ptr_in){
        std::cout << "AutoPtr Move Assignment" << std::endl;

        if (this == &ptr_in)
            return *this;

        if (m_ptr != nullptr)
            delete m_ptr;
        
        m_ptr = ptr_in.m_ptr;
        ptr_in.m_ptr = nullptr;

        return *this;
    }

    T& operator* () { return *m_ptr;}
    T* operator->() { return  m_ptr;}
};