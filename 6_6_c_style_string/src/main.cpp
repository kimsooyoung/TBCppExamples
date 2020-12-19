#include <iostream> 
#include <cstring>

using namespace std;

int main(){
    {
        const char string[] = "My_String";
        int string_size = sizeof(string)/sizeof(string[0]);

        for (auto i = 0; i < string_size; i++){
            cout << string[i] << endl;
        }
    }

    {
        const char source[] = "Copy This!";
        char dest[50];

        strcpy(dest, source);

        cout << "dest : " << dest << endl;
        cout << "source : " << source << endl;

    }

    {
        // Error Case
        const char source[] = "This is Error Test";
        char dest[5];

        strcpy(dest, source);

        cout << "dest : " << dest << endl;
        cout << "source : " << source << endl;
    }

    return 0;
}