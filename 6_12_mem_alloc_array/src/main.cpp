#include <iostream>

using namespace std;

int main() {

    // Dynamic Memory Allocation for Array Example
    {
        int arr_size;
        
        cout << "Enter Array Size : ";
        cin >> arr_size; cin.ignore(32767, '\n');

        int *array = new int[arr_size];
        // int *array = new int[arr_size]();
        // int *array = new int[arr_size] {1,2,3,4,5,6};
        
        array[0] = 1;
        array[1] = 2;

        for (int i = 0; i < arr_size; i++){
            cout << (uintptr_t)&array[i] << " " << array[i] << endl;
        }
    
        delete[] array;
    }

    return 0;
}