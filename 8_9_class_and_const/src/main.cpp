#include <iostream>
#include <string>

using namespace std; 

//
class Something{
public:
    int m_val = 100;
    string m_str = "something";

    Something() {
        cout << "General Constructor Called" << endl;
    }
    Something(const Something &st){ 
        cout << &st << " " << " copy consturctor Called" << endl;
    }
    
    void setVal(const int& val_in) { m_val = val_in; }
    // Use const as much as you can.
    int  getVal() const { return m_val; }
    
    // function overroding with const expression
    string& getStr() { 
        cout << "non const getStr" << endl;
        return m_str;
    }
    const string& getStr() const { 
        cout << "const getStr" << endl;
        return m_str; 
    }
};

// Copy Constructor Example
// this function will copy Class
// void printSth(Something st){
//     cout << "&st : " << &st << endl;
//     cout << "st.m_val : " << st.m_val << endl;
// }

// in order to prevent copy, use reference 
void printSth(const Something &st) {
    cout << "Const printSth" << endl;
    cout << "&st : " << &st << endl;
    cout << "st.m_val : " << st.m_val << endl;
}

int main(){
    
    // const class
    {
        const Something something;
        // const class can only use const functions
        // something.setVal(112);
        something.getVal();
    }

    // Copy Constructor Example
    {
        Something sth;
        cout << "&sth : " << &sth << endl;
        printSth(sth);
    }

    // function overroding with const expression
    {
        Something sth;
        cout << sth.getStr() << endl;

        const Something const_sth;
        cout << const_sth.getStr() << endl;
    }

    return 0;
}