#include <iostream>
#include <sstream>

using namespace std;

int main( ){
    
    // Inheritance structure
    {
        // cout (ostream <= basic_ostream <= basic_ios <= ios_base)
        // stringstream basic_stringstream basic_iostream (basic_istream/basic_ostream)
    }

    // stringstream with string
    {
        stringstream ss;
        ss << "Hello, World";
        ss.str();

        string str;
        ss >> str;

        cout << str << endl;
    }

    {
        stringstream ss;
        ss << "Hello, World";
        ss.str();

        string str;
        str = ss.str();

        cout << str << endl;
    }

    // << operator and str() function
    {
        stringstream ss;
        ss << "Hello, World";
        ss << "Yello, Morld";
        ss.str();

        string str;
        str = ss.str();

        cout << str << endl;

        ss.str("Yello, Morld");
        str = ss.str();

        cout << str << endl;
    }

    // more examples about stringstream
    {
        stringstream ss;

        ss << "1234 567 89";
        string s1;
        string s2;
        string s3;
        
        ss >> s1 >> s2 >> s3;
        cout << s1 << "|" << s2 << "|" << s3 << endl;
    }

    {
        stringstream ss;

        int i = 12345;
        double d = 6.78;

        ss << i << " " << d;

        string str1;
        string str2;

        int i2;
        double d2;

        ss >> str1 >> str2;
        cout << str1 << "|" << str2 << endl;
    }

    {
        stringstream ss;

        int i = 12345;
        double d = 6.78;

        ss << i << " " << d;

        int i2;
        double d2;

        ss >> i2 >> d2;
        cout << typeid(i2).name() << "|" << typeid(d2).name() << endl;
    }

    cout << endl;

    // how to clear ss?
    {
        stringstream ss;
        ss << "Hello, World";

        // case 1 switch to empty
        ss.str("");

        // case 2 clear
        ss.clear();

        // caution => misused clear
        ss << "Thank you!!";
        ss.clear();
        cout << ss.str() << endl;
    }

    return 0;
}