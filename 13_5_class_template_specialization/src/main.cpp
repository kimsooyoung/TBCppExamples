#include "Storage.h"

template <typename T>
class A {
private:    
    T m_val;
public:
    A(const T &val_in): m_val(val_in) {}

    void doSomething(){
        std::cout << typeid(T).name() << std::endl;
    }

    void test(){
        std::cout << "test" << std::endl;
    }
};

template <>
class A <char> {
private:
    char m_val;
public:
    A(const char &val_in): m_val(val_in) {}

    void doSomething(){
        std::cout << "Char Specialization" << std::endl;
    }
};

int main(){

    using namespace std;

    // class template specialization example
    // gave exception to char case
    {
        A<int> i(1);
        A<double> d(1.1);
        A<char> c('c');

        i.doSomething();
        d.doSomething();
        c.doSomething();

        i.test();
        d.test();
        
        // temple specialization is differ from inheritance
        // error
        // c.test();
    }

    // from c++17 class braket <> can be omitted
    // if constructor is defined properly
    {
        // check CMakeLists.txt and C++ version
        A i(1);
        A d(1.1);
        A c('c');
    }

    // class specialization 
    // useful example, Storage8 class
    {
        Storage8<int> store;

        for (auto i = 0; i < 8; i++)
            store.set(i, i);
        
        for (auto i = 0; i < 8; i++)
            cout << store.get(i) << " ";
        cout << endl; 
        
        Storage8<bool> store_b;

        for (auto i = 0; i < 8; i++)
            store_b.set(i, true);

        store_b.set(6, false);
        store_b.set(2, false);
        
        for (auto i = 0; i < 8; i++)
            cout << store_b.get(i) << " ";
        cout << endl; 
    }

    return 0;
}