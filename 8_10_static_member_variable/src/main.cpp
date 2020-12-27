#include <iostream>
#include <string>

using namespace std; 

// static - recap
int print(){
    static int s_id = 0;
    return s_id += 1;
}

class Something{
public:
    static int s_val;
    // static const variable
    // must be initialized in class
    static const int sc_val = 1;
    // static constexpr variable
    // must be decided in compile time
    static constexpr int sce_val = 12;
};

// static value must be initialized 
// at out of class
int Something::s_val = 0;

int main(){
    
    // static recap
    {
        cout << print() << endl;
        cout << print() << endl;
        cout << print() << endl;
    }

    // class static variable
    {
        Something s1;
        Something s2;

        s1.s_val = 2;

        // All Something classes share static variable
        cout << "s1.s_val : " << s1.s_val << endl;
        cout << "s2.s_val : " << s2.s_val << endl;

        s1.s_val = 1024;
        
        // Even static variable can called without class declaration
        cout << "Something::s_val : " << Something::s_val << endl;
    }

    return 0;
}