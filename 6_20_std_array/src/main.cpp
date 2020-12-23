#include <algorithm>
#include <iostream>
#include <array>

using namespace std;

void printArrSize(const array<int, 5> &my_arr){
    cout << "Array Size : " << my_arr.size() << endl;
}

void printArrElem(const array<int ,5> &my_arr){
    for (auto &elem : my_arr)
        cout << elem << ",";
    cout << endl;
}

int main(){

    // Basic Usage
    {
        // array MUST specify its size
        // array<int> my_arr {1,2,3,4,5};
        array<int, 5> my_arr {1,2,3,4,5};

        my_arr = {1,2,3};
        // Error, longer than capacity
        // my_array = {1,2,3,4,5,6,7};

        cout << my_arr.size() << endl;
        cout << my_arr[2] << endl;
        cout << my_arr.at(2) << endl;
    }

    // Array for Fuction Param
    {
        array<int, 5> my_arr {1,2,3,4,5};

        printArrSize(my_arr);
    }

    // Element Approach - For Each
    {
        array<int, 5> my_arr {1,2,3,4,5};

        for (auto &num : my_arr)
            cout << num << endl;
        cout << endl;
    }

    // Sort
    {
        array<int, 5> my_arr {11,2,31,-1,0};

        cout << "Before Sort" << endl;
        printArrElem(my_arr);

        cout << "Ascend Sort" << endl;
        sort(my_arr.begin(), my_arr.end());
        printArrElem(my_arr);

        cout << "Descend Sort" << endl;
        sort(my_arr.rbegin(), my_arr.rend());
        printArrElem(my_arr);

    }

    return 0;
}