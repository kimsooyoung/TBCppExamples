#pragma once

#include <iostream>

template <typename T>
class AutoPtr {
private:
    T* m_ptr;
public:
    AutoPtr(T* ptr_in = nullptr): m_ptr(ptr_in) {
        std::cout << "AutoPtr default constructor" << std::endl;
    }

    ~AutoPtr(){
        std::cout << "AutoPtr desctructor" << std::endl;

        if (m_ptr != nullptr)
            delete m_ptr;
    }

    AutoPtr(const AutoPtr &ptr_in){
        std::cout << "AutoPtr copy constructor" << std::endl;

        m_ptr = new T;

        // Deep Copy
        // This line will call copy assignment operator from Resource class
        *m_ptr = *ptr_in.m_ptr;
    }

    // this const makes rvalue to lvalue
    // like this
    // const int &x = 5;
    AutoPtr& operator= (const AutoPtr &ptr_in){
        std::cout << "AutoPtr copy assignment" << std::endl;

        if (this == &ptr_in)
            return *this;
        
        if (m_ptr != nullptr)
            delete m_ptr;
        
        // Deep copy
        m_ptr = new T;
        *m_ptr = *ptr_in.m_ptr;

        return *this;
    }

    // ban copy semantic
    // AutoPtr& operator= (const AutoPtr &ptr_in);
    // AutoPtr(const AutoPtr &ptr_in);

    AutoPtr(AutoPtr &&ptr_in): m_ptr(ptr_in.m_ptr){
        std::cout << "AutoPtr move constructor" << std::endl;

        ptr_in.m_ptr = nullptr;
    }

    AutoPtr& operator= (AutoPtr &&ptr_in){
        std::cout << "AutoPtr move assignment" << std::endl;

        if(this == &ptr_in)
            return *this;
        
        if(m_ptr != nullptr)
            delete m_ptr;
        
        // Shallow Copy
        m_ptr = ptr_in.m_ptr;
        ptr_in.m_ptr = nullptr;

        return *this;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};