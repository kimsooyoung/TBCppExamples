#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    // showpos
    {
        cout.setf(std::ios::showpos);
        cout << 108 << endl;

        cout.unsetf(std::ios::showpos);
        cout << 109 << endl;
    }

    // hex output
    {
        // case 1
        {
            cout.unsetf(std::ios::dec);
            cout.setf(std::ios::hex);

            cout << 108 << endl;
        }

        // case 2
        {
            cout.setf(std::ios::hex, std::ios::basefield);
            cout << 108 << endl;
        }

        // case 3
        {
            cout << std::hex;
            cout << 108 << endl;

            cout << std::dec;
            cout << 108 << endl;
        }
    }

    cout << endl;

    // Uppercase in Hex
    { 
        // case 1
        {
            cout.setf(std::ios::hex, std::ios::basefield);
            cout.setf(std::ios::uppercase);
            cout << 108 << endl;
        }

        // case 2 - more comfortable 
        {
            cout << std::hex << std::uppercase;
            cout << 108 << endl;
        }
    }

    // boolalpha
    {
        cout << std::boolalpha;
        cout << true << " " << false << endl;
    }
    
    cout << endl;

    // setprecision 
    {
        // cout << std::defaultfloat;
        cout << std::setprecision(3) << 123.456 << endl;
        cout << std::setprecision(4) << 123.456 << endl;
        cout << std::setprecision(5) << 123.456 << endl;
        cout << std::setprecision(6) << 123.456 << endl;
        cout << std::setprecision(7) << 123.456 << endl;
    }

    cout << endl;

    {
        // Precision Below the decimal point
        cout << std::fixed;
        cout << std::setprecision(4) << 123.456 << endl;
        cout << std::setprecision(5) << 123.456 << endl;
        cout << std::setprecision(6) << 123.456 << endl;
        cout << std::setprecision(7) << 123.456 << endl;
    }

    cout << endl;

    {
        cout << std::scientific << std::uppercase;
        cout << std::setprecision(4) << 123.456 << endl;
        cout << std::setprecision(5) << 123.456 << endl;
        cout << std::setprecision(6) << 123.456 << endl;
        cout << std::setprecision(7) << 123.456 << endl;
    }

    cout << endl;

    {
        cout << std::showpoint;
        cout << std::setprecision(4) << 123.456 << endl;
        cout << std::setprecision(5) << 123.456 << endl;
        cout << std::setprecision(6) << 123.456 << endl;
        cout << std::setprecision(7) << 123.456 << endl;
    }

    cout << endl;

    // align numbers
    {
        cout << std::dec;
        cout << -12345 << endl;
        cout << std::setw(10) << -12345 << endl;
        cout << std::setw(10) << std::left << -12345 << endl;
        cout << std::setw(10) << std::right << -12345 << endl;
        cout << std::setw(10) << std::internal << -12345 << endl;
    }

    cout << endl;

    // fill with specific character
    {
        cout.fill('*');
        cout << std::setw(10) << -12345 << endl;
        cout << std::setw(10) << std::left << -12345 << endl;
        cout << std::setw(10) << std::right << -12345 << endl;
        cout << std::setw(10) << std::internal << -12345 << endl;
    }

    return 0;
}