#include <iostream>

template <typename T>
class A {
private:
    T m_val;
public:
    A (const T &val_in): m_val(val_in) {}

    // templatize Again
    // In this example TT is used like casting
    template <typename TT>
    void doSomething(){
        std::cout << typeid(T).name() << " " << typeid(TT).name() << std::endl;
        std::cout << (TT)m_val << std::endl;
    }

    template <typename TTT>
    void doSomethingParam(const TTT &val_in){
        std::cout << val_in << std::endl;
    }

    void print() {
        std::cout << m_val << std::endl;
    }
};

int main(){

    A<int> a(97);
    
    // Usage 1
    {
        // Casting 97 to char
        a.doSomething<char>();
    }

    // Usage 2
    {
        // If templatize function has typename param
        // then It is not necessary to specify the type.
        a.doSomethingParam(12.3);
    }

    return 0;
}