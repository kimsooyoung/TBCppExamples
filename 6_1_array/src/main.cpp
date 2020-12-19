#include <iostream>

using namespace std;

struct Rectangle{
    int length;
    int width;
};

int main() {
    // Array, Baisc usage
    {
        int student_score[5];

        student_score[0] = 100;
        student_score[1] = 90;
        student_score[2] = 80;
        student_score[3] = 70;
        student_score[4] = 60;
        student_score[5] = 50;
        // student_score[6] = 60;


        cout << student_score[0] << endl;
        cout << student_score[1] << endl;
        cout << student_score[2] << endl;
        cout << student_score[3] << endl;
        cout << student_score[4] << endl;
        cout << student_score[5] << endl;
        // cout << student_score[6] << endl;
    }

    // Struct Array
    {
        cout << "sizeof(Rectangle) : " << sizeof(Rectangle) << endl;

        Rectangle rect_arr[10];
        rect_arr[0].width = 7;
        rect_arr[0].length = 10;

        cout << "sizeof(rect_arr[10]) : " << sizeof(rect_arr) << endl;
    }

    // Array Initialization
    {
        int my_arr[] = {1,2,3,4,5};

        cout << my_arr[0] << endl;
        cout << my_arr[1] << endl;
        cout << my_arr[2] << endl;
        cout << my_arr[3] << endl;
        cout << my_arr[4] << endl;
        // cout << my_arr[5] << endl;

        // uniform initialization - from C++11
        int my_arr_2[] {1,2,3,4,5};
    }

    return 0;
}