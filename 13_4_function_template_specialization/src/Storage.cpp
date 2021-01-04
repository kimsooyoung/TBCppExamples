#include "Storage.h"

// Header Seperation also works

template <>
void Storage<double>::print() {
    std::cout << "It's Double Type" << std::endl;
    std::cout << std::scientific << m_val << std::endl;
}

// without explicit instantiation??
// template class Storage<double>;
