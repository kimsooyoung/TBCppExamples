#include <iostream> 

template <typename T>
class A {
private:
    T m_val;
public:
    A (const T &val_in): m_val(val_in){}
    void print() {
        std::cout << m_val << std::endl;
    }
};

// pointer specialization
// Must write <T*> after class
template <typename T>
class A<T*> {
private:
    T* m_ptr;
public: 
    A (T* ptr_in): m_ptr(ptr_in){}
    void print(){
        std::cout << *m_ptr << std::endl;
    }
};

int main(){

    // Basic Usage
    A<int> i(12);
    i.print(); 

    // Pointer Specialization Usage
    int temp = 234;
    A<int*> ptr_i(&temp);
    ptr_i.print();

    return 0;
}