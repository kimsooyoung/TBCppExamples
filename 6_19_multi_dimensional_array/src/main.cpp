#include <iostream>

using namespace std;

int main(){

    // Pointer Pointer
    {
        int *ptr = nullptr;
        int **ptrptr = nullptr;

        int val = 5;

        ptr = &val;
        ptrptr = &ptr;

        cout << ptr << " " << *ptr << " " << &ptr << endl;
        cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
        cout << *(*ptrptr) << endl;
    }

    // 2 Dimensinal Array with Pointer
    {
        int arr_matrix[][5] = {
            {1,2,3,4,5},
            {6,7,8,9,10},
            {11,12,13,14,15}
        };

        const int row = 3;
        const int col = 5;

        int *row_1 = new int [col]{1,2,3,4,5};
        int *row_2 = new int [col] {6,7,8,9,10};
        int *row_3 = new int [col] {11,12,13,14,15};

        int **ptr_matrix = new int*[row] {row_1, row_2, row_3};

        for (auto i = 0; i < row; i++)
            for (auto j = 0; j < col; j++)
                cout << i << " " << j << " " << ptr_matrix[i][j] << endl;

        // !! Delete with for loop !!
        for (auto i = 0; i < row; i++)
            delete[] ptr_matrix[i];
        
        delete[] ptr_matrix;
    }

    return 0;
}