#include <iostream> 

using namespace std;

class PoweredDevice {
public:
    int m_i;
    PoweredDevice(const int i_in=0): m_i(i_in) {}
};

class Scanner : virtual public PoweredDevice {
public:
    Scanner(const int &scanner, const int &i_in): PoweredDevice(i_in){
        cout << "Scanner : " << scanner << endl;
    }
};

class Printer : virtual public PoweredDevice {
public:
    Printer(const int &printer, const int &i_in): PoweredDevice(i_in){
        cout << "Printer : " << printer << endl;
    }
};

class Copier  : public Scanner, public Printer {
public:
    Copier(const int &scanner, const int &printer, const int &i_in): Scanner(scanner, i_in), Printer(printer, i_in){
        cout << "Copier" << endl;
    }
};

int main() {

    Copier copy(1,2,3);


    // virtual public inheritance 
    // can prevent diamond inheritance problem

    // these addresse can be same, if virtual public inheritanced
    cout << &copy.Scanner::PoweredDevice::m_i << endl;
    cout << &copy.Printer::PoweredDevice::m_i << endl;

    return 0;
}