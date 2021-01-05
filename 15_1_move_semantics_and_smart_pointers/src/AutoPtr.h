#pragma once

#include <iostream>
#include <memory>

// Similiar to auto_ptr in std
// auto_ptr is deprecated in c++11
template <typename T>
class AutoPtr {
public:
    T *m_ptr = nullptr;
public:
    AutoPtr(T *ptr_in = nullptr) : m_ptr(ptr_in){}
    
    ~AutoPtr(){
        if (m_ptr != nullptr) delete m_ptr; 
    }

    T& operator*()  const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull()   const { return m_ptr == nullptr; }
};

// AutoPtr with Move Semantic
template <typename T>
class AutoPtrWithMS : public AutoPtr<T> {
public:
    AutoPtrWithMS() : AutoPtr<T>() {}

    AutoPtrWithMS(T *ptr_in): AutoPtr<T>(ptr_in) {}

    AutoPtrWithMS(AutoPtrWithMS &ptr_in){
        AutoPtr<T>::m_ptr = ptr_in.m_ptr;
        ptr_in.m_ptr = nullptr;
    }

    AutoPtrWithMS& operator= (AutoPtrWithMS &ptr_in) {
        if (this == &ptr_in)
            return *this;
        
        delete AutoPtr<T>::m_ptr;
        AutoPtr<T>::m_ptr = ptr_in.m_ptr;
        ptr_in.m_ptr = nullptr;
        return *this;
    }
};