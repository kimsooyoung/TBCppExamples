// header Separation
#include "MyArray.h"


// Main file doesn't know about template function separation 
// Resolve this by explicit instantiation
template<typename T>
int MyArray<T>::getLength() {
    return m_size;
}

template<typename T>
T& MyArray<T>::operator[] (const int &index){
    assert(index >= 0);
    assert(index < m_size);
    assert(m_arr != nullptr);
    return m_arr[index];
}

template class MyArray<int>;
template class MyArray<double>;