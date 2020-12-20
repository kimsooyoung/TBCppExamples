#include <iostream>

using namespace std;

int main(){
    
    {
        int value = 7;
        double d_value = 1234;
        
        int *ptr = &value;

        cout << uintptr_t(ptr-1) <<endl;
        cout << uintptr_t(ptr) <<endl;
        cout << uintptr_t(ptr+1) <<endl;
        cout << endl;

        double *ptr_d = &d_value;

        cout << uintptr_t(ptr_d-1) <<endl;
        cout << uintptr_t(ptr_d) <<endl;
        cout << uintptr_t(ptr_d+1) <<endl;
        cout << endl;
    }

    // Array indexing with pointer
    {
        int arr[5] = {1,2,3,4,5};

        for (auto i = 0; i < 5; i++)
            cout << *(arr + i) << " " << (uintptr_t)(arr + i) << endl;

        cout << endl;

        int *ptr_arr = arr;

        for (auto i = 0; i < 5; i++)
            cout << *(ptr_arr + i) << " " << (uintptr_t)(ptr_arr + i) << endl;
        cout << endl;
        
    }

    // Char string with pointer
    {
        char name[] = "Jack Jack";
        int size = sizeof(name) / sizeof(name[0]);
        char *ptr_c = name;

        while (1){
            if (*ptr_c == '\0')
                break;

            cout << *ptr_c << endl;
            ptr_c++;
        }
    }

    return 0;
}