#include <iostream>
#include <string>

using namespace std; 


class Something{
private:
    static int s_val;
public:
    // static member variable cannot initialized in Constructor
    // Something(): s_val(1011) {}

    // static variable only 
    // can be accessed from static function
    static int getVal(){
        // cannot use this poineter in static function
        // this->s_val += 10;
        return s_val;
    }
    int temp(){
        return this->s_val;
    }
};

// Static member variable initialization method
class Outer{
public:
    class _init {
    public:
        _init(){
            s_val = 1234;
        }
    };
private:
    static int s_val;
    static _init s_initializer;
public:
    int temp(){
        return this->s_val;
    }
    static int getVal(){
        return s_val;
    }
};

// static value must be initialized 
// at out of class
int Something::s_val = 1024;

int Outer::s_val = 112;
Outer::_init Outer::s_initializer;

int main(){
    
    // static function example;
    {
        cout << Something::getVal() << endl;

        Something s1;
        cout << s1.getVal() << endl;

        cout << s1.temp() << endl;
    }

    // member function pointer
    {
        Something sth;

        // member function operates like this.
        int (Something::*fptr1)() = &Something::temp;
        cout << "(sth.*fptr1)() : " << (sth.*fptr1)() << endl;

        // static member function don't have to 
        // binded with class
        int (*fptr2)() = &Something::getVal;
        cout << "fptr2() : " << fptr2() << endl;
    }

    // private static member variable initialization
    {
        Outer outer;
        cout << "outer.getVal() : " << outer.getVal() << endl;
    }

    return 0;
}