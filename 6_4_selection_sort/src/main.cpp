#include <iostream>

using namespace std;

// print whole array 
void printArr(const int arr[], const int arr_size){
    for (auto i = 0; i < arr_size; i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;
}

int main(){
    int arr[] = {3,5,2,1,4};
    const int arr_size = sizeof(arr) / sizeof(int);
    cout << arr_size << endl;

    int temp, index;

    // implement selection sort
    for(int i = 0; i < arr_size; i++){
        index = i;
        
        // compare
        for(int j = i; j < arr_size; j++){
            index = ( arr[j] < arr[index]) ? j:index;
        }

        // swap
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    
        printArr(arr, arr_size);
    }

    return 0;
}