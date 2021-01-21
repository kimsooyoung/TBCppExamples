

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Example {
public:
    // useful auto - vector iteration
    void ex1(){ 
        vector<int> vec = { 1, 2, 3, 4 };

        for(vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
            cout << *itr << " ";
        cout << endl;

        for (auto itr = vec.begin(); itr != vec.end(); itr++)
            cout << *itr << " ";
        cout << endl;

        for (auto elem: vec)
            cout << elem << " ";
        cout << endl;
    }

    // check how auto works
    void ex2(){
        int x = int();

        auto auto_x = x; // int

        const int &crx = x;

        auto auto_crx1 = crx; // int 

        const auto& auto_crx2 = crx;

        volatile int vx = 1024;

        auto avx = vx; // int
    }

    // int
    // template <class T>
    // void func_ex3(T t){}

    // const int &
    template <class T>
    void func_ex3( const T &t) {}

    void ex3(){
        const int &i = 123;
        func_ex3(i);
    }

    void ex4(){
        const int i = 12.34;
        auto &a_i = i; // const int&
    }

    void ex5(){
        int i = 123;
        auto &&a_i  = i; // int & 
        auto &&a_i2 = 23; // int &&
    }

    void ex6(){
        int i = 12;
        const int *p = &i;
        auto a_p = p; // const int *
    }

    // Template with auto - good example
    template <typename T, typename S>
    void func_ex7(T lhs, S rhs){
        auto prod1 = lhs * rhs;

        typedef decltype(lhs * rhs) product_type;

        product_type prod2 = lhs * rhs;

        decltype(lhs * rhs) prod3 = lhs * rhs;
    }

    template<typename T, typename S>
    auto func_ex8(T lhs, S rhs) -> decltype(lhs * rhs){
        return lhs * rhs;
    }

    void ex8(){
        cout << func_ex8(2, 3.14) << endl;
        cout << func_ex8(2, 3) << endl;
    }

    struct S{
        int m_x;

        S(){
            m_x = 42;
        }
    };

    void ex9(){
        int x;
        const int cx = 42;
        const int& crx = x;
        const S *p = new S();

        auto a = x; // int
        auto b = cx; // const int
        auto c = crx; // int
        auto d = p; // const S*
        auto e = p->m_x; // int

        typedef decltype(x)      x_type; // int
        typedef decltype(cx)     cx_type; // const int
        typedef decltype(crx)    crx_type; // const int&
        typedef decltype(p)      p_type; // const S*
        typedef decltype(p->m_x) p_mx_type; // int
    }

    const S foo(){
        return S();
    }    

    // reference return is Not recommended
    const int& foobar(){
        return 123;
    }

    void ex10(){
        std::vector<int> vec = { 42, 43 };

        auto a = foo(); // S
        typedef decltype(foo()) foo_type; // const S

        auto b = foobar(); // int
        typedef decltype(foobar()) foobar_type; // const int&

        auto itr = vec.begin(); // vector<int>::iterator
        typedef decltype(vec.begin()) itr_type; // vector<int>::iterator

        auto first_elem = vec[0]; // int
        typedef decltype(vec[0]) elem_type; // int&
    }

    void ex11(){
        int x = 0;
        int y = 0;
        const int cx = 42;
        const int cy = 43;
        double d1 = 3.14;
        double d2 = 2.72;

        typedef decltype(x * y) prod_xy_type; // int 
        auto a = x * y; // int

        typedef decltype(cx * cy) prod_cxcy_type; // int
        auto b = cx * cy; // int

        typedef decltype(d1 < d2 ? d1 : d2) cond_type; // double & (result it lvalue & is added)
        auto c = d1 < d2 ? d1: d2; // double

        typedef decltype(x < d2 ? x : d2) cond_type_mixed; // double
        auto d = x < d2 ? x : d2; // double

        // auto d = std::min(x, db1); error
    }

    template <typename T, typename S>
    auto fpmin_wrong(T t, S s) -> 
    typename std::remove_reference<decltype(t < s ? t: s)>{
        return t < s ? t: s;
    }

    void ex12(){
        int i = 42;
        double d = 45.1;
        // auto a = std::min(i, d); // error
        auto a = std::min(static_cast<double>(i), d);

        int &j = i;

        typedef decltype(fpmin_wrong(d, d)) fpmin_wrong_type1; // double&
        typedef decltype(fpmin_wrong(i, d)) fpmin_wrong_type2; // double
        typedef decltype(fpmin_wrong(j, d)) fpmin_wrong_type3; // double
    }

    void ex13(){
        vector<int> vec;
        // vec[0]; // error
        typedef decltype(vec[0]) vec_type; // it's okay
        // decltype don't actual operation
    }

    template <typename T>
    class SomeFunctor{
    public:
        typedef T result_type;

        SomeFunctor(){}

        result_type operator() () {
            return T();
        }
    };

    void ex14(){
        SomeFunctor<int> func;
        // get type from Functor class
        typedef decltype(func)::result_type nested_type; // int
    }

    void ex15(){
        auto lambda = []() { return 42; };
        decltype(lambda) lambda2(lambda); // []int ()-> int
        decltype((lambda)) lambda3(lambda); // []int ()-> int&

        cout << "Lambda Functions" << endl;
        cout << &lambda << " " << &lambda2 << endl; //  same
        cout << &lambda << " " << &lambda3 << endl; // different
    
        // 0x7ffdaad6288e 0x7ffdaad6288f
        // 0x7ffdaad6288e 0x7ffdaad6288e
        // ???
    }

    void ex16() {
        // generic lambda (return type to auto)
        auto lambda = [](auto x, auto y){
            return x + y;
        };

        cout << lambda(1.1, 2) << " " << lambda(3, 4) << " " << lambda(4.5, 2.2) << endl;
    }

};

int main(){

    Example example;

    example.ex1();
    example.ex8();
    example.ex15();
    example.ex16();

    return 0;
}