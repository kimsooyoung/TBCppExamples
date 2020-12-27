#include <iostream> 

using namespace std;

class Simple{
    int m_id;
public:
    Simple(const int &id_in):m_id(id_in){
        cout << "Constructor!" << endl;
    }
    ~Simple(){
        cout << "Destructor!" << endl;
    }
};

// implement new/delete in Class 
// And do everything in Class
class IntArr{
    int *m_arr;
    int m_size;
public:
    IntArr(const int &size):m_size(size){
        m_arr = new int [size];
        cout << "IntArr Constructor" << endl;
    }
    ~IntArr(){
        if(m_arr != nullptr)
            delete[] m_arr;
        cout << "IntArr Destructor" << endl;
    }
};

int main(){

    // Basic Example
    {
        Simple s1(0);
        Simple s2(1);
    }

    // Dynamic Allocation
    {
        cout << "==== Dynamic Allocation ====" << endl;
        Simple *s1 = new Simple(0);

        delete s1;
    }

    // Dynamic Array Allocation Example
    {
        cout << "==== Dynamic Array Allocation Example ====" << endl;
        IntArr int_arr(4);
    }

    return 0;
}