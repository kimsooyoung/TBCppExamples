#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// For ToString example
#include <sstream>

template <typename T>
std::string ToString(T x){
    std::ostringstream osstream;
    osstream << x;
    return osstream.str();
}

template <typename T>
bool FromString(const std::string &str_in, T x ){
    std::istringstream isstream;
    return (isstream >> x) ? true: false;
}

using namespace std;

int main(){

    // std::string consturctors
    {
        string my_str1 ("my string");

        // copy from third char
        string my_str2(my_str1, 3);
        cout << my_str2 << endl;

        // copy three char from third char
        string my_str3(my_str1, 3, 3);
        cout << my_str3 << endl;

        // same for const char * type
        const char *hello_str = "Hello Hello";
        string my_str4(hello_str, 4);
        cout << my_str4 << endl;
        
        // Repeated text multiple times
        string many_a (10, 'A');
        cout << many_a << endl;         
    }

    cout << "=========================" << endl;

    // std::string with std::vector
    {
        vector<char> vec;

        for (auto &e : "Today is a good day")
            vec.push_back(e); 

        string my_str(vec.begin(), vec.end());
        string my_str2(vec.begin(), find(vec.begin(),vec.end(), ' '));

        cout << my_str << endl;
        cout << my_str2 << endl;
    }
    
    cout << "=========================" << endl;

    // useful functions
    {
        string num_to_str(to_string(1004));
        num_to_str += to_string(1248);
        cout << num_to_str << "/ typeid: " << typeid(num_to_str).name() << endl;

        int str_to_num = stoi(num_to_str);
        cout << str_to_num << "/ typeid: " << typeid(str_to_num).name() << endl;
    }

    cout << "=========================" << endl;

    // std::istringstream / std::ostringstream examples
    {
        string my_str(ToString(1004));

        cout << my_str << " type : " << typeid(my_str).name() << endl;

        double d;
        
        if(FromString(my_str, d))
            cout << "success" << endl;
        else
            cout << "fail" << endl;
    }

    return 0;
}
