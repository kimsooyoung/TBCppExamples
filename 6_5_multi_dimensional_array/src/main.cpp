#include <iostream>

using namespace std;

// void printMat(const int mat[][], int row, int col){
//     for (auto i = 0; i < row; i++){
//         for (auto j = 0; j < col; j++){
//             cout << "[" << mat[i][j] << "," << mat[i][j] << "]" << '\t';
//         }
//         cout << endl;
//     }
// }

int main(){
    {
        const int row = 3;
        const int col = 5;

        for (auto i = 0; i < row; i++){
            for (auto j = 0; j < col; j++){
                cout << "[" << i << "," << j << "]" << '\t';
            }
            cout << endl;
        }
        
        // don't have to know row, but MUST KNOW COL SIZE
        const int arr[][col] = {
            {1,2,3,4,5},
            {6,7,8,9,10},
            {11,12,13,14,15}
        };

        for (auto i = 0; i < row; i++)
        {
            for (auto j = 0; j < col; j++)
            {
                cout << (size_t)&(arr[i][j]) << '\t';
            }
            cout << endl;
        }
    }

    // Practice
    // Matrix Multiplication
    {
        const int row = 2;
        const int col = 2;

        const int mat_1[][2] = {
            {1,2},
            {3,4}
        };
        const int mat_2[][2] = {
            {10,5},
            {5,5}
        };
        int result[][2] = {
            {0,0},
            {0,0}
        };
        
        for (auto i = 0; i < row; i++){
            for (auto j = 0; j < col; j++){
                for (auto k = 0; k < row; k++){
                    result[i][j] += mat_1[i][k] * mat_2[k][j];
                }
            }
        }

        for (auto i = 0; i < row; i++)
        {
            for (auto j = 0; j < col; j++)
            {
                cout << (result[i][j]) << '\t';
            }
            cout << endl;
        }
    }

    

    return 0;
} 