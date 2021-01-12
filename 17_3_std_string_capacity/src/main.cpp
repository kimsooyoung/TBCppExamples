#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {

    // string size and capa 
    {
        string my_str("0123456789");

        cout << "size : " << my_str.size() << endl;
        cout << "capacity : " << my_str.capacity() << endl;
    }

    // difference between c-style string and std::string
    {
        // c-style string contains null chararacter 
        // while std::string doesn't have
        string my_str("");
        char c_str[] = "";

        cout << "my_str.size : " << my_str.size() << endl;
        cout << "sizeof(c_str) : " << sizeof(c_str) / sizeof(char)  << endl;

        cout << boolalpha;
        cout << "my_str.empty() : " << my_str.empty() << endl;
        cout << endl;
    }

    // capacity and reserve
    {
        string my_str("01234567");

        cout << boolalpha;
        cout << "my_str.length : " << my_str.length()   << endl;
        cout << "my_str.size : " << my_str.size()     << endl;
        cout << "my_str.capacity : " << my_str.capacity() << endl;
        cout << "my_str.max_size : " << my_str.max_size() << endl;

        cout << endl;
        
        string rsv_str("01234567");
        rsv_str.reserve(1000);

        cout << "rsv_str.length : " << rsv_str.length()   << endl;
        cout << "rsv_str.size : " << rsv_str.size()     << endl;
        cout << "rsv_str.capacity : " << rsv_str.capacity() << endl;
        cout << "rsv_str.max_size : " << rsv_str.max_size() << endl;
    }

    return 0;
}