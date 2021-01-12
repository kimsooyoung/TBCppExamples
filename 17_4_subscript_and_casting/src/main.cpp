#include <iostream> 
#include <string>
#include <cstring>

using namespace std;

int main() {

    // string is similiar to vector 
    {
        string my_str("abcdefg");

        cout << my_str[1] << endl;
        my_str[3] = 'Z';
        cout << my_str[3] << endl;

        // ERROR
        // cout << my_str[100] << endl; 
    }

    // out of range err exception handling
    {
        try{
            string my_str("qwer");

            // [] operater don't have exception handling
            // cout << my_str[100] << endl;
            
            // use .at() instead
            cout << my_str.at(100) << endl;
        }
        catch(const std::exception& e){
            std::cerr << e.what() << '\n';
        }
    }

    // string to char *
    {   
        string my_str("abcdefg");

        const char* c_str = my_str.c_str();
        cout << c_str << endl;

        while (*c_str != '\0'){
            cout << *c_str << " ";
            c_str++;
        }
        cout << endl;
        
        // but c_str contains null character
        cout << int(c_str[7]) << endl;
    
        // string.data() doing same things
        const char *data_str = my_str.data();
        cout << data_str << endl;
    }

    // string.copy() 
    {
        string my_str("abcdefg");
        char buf[20];

        my_str.copy(buf, 5, 0);

        // CAUTION! add null char at the end of buffer
        buf[5] = '\0';
        
        cout << buf << endl;
    }

    return 0;
}