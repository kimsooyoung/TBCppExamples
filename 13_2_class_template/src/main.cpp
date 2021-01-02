#include "MyArray.h"

int main(){

    using namespace std;
    
    // MyArray as class template
    {
        MyArray<int> my_arr {1,2,3,4,5};

        cout << my_arr << endl;
        cout << my_arr[2] << endl;

        MyArray<double> my_arr_d {1.1, 2.2, 3.3, 4.4, 5.5};

        cout << my_arr_d << endl;
        cout << my_arr_d[2] << endl;
    }

    {
        MyArray<int> my_arr {1,2,3,4,5};

        cout << "size : " << my_arr.getLength() << endl;
        cout << my_arr[1] << endl;
    }

    return 0;
}