#include <iostream>

using namespace std;

void doSomething( int student_scores[]){

    cout << "In doSomething : " << sizeof((size_t)student_scores) << endl;

    cout << "(size_t)student_scores : " << (size_t)student_scores << endl;
    cout << "(size_t)&student_scores : " << (size_t)&student_scores << endl;
    cout << "(size_t)&(student_scores[0]) : " << (size_t)&(student_scores[0]) << endl;
    
    cout << *student_scores << endl;
    cout << student_scores[0] << endl;
    cout << student_scores[1] << endl;
    cout << student_scores[2] << endl;
}

int main() {

    const int arr_size = 100;
    int student_scores[arr_size] = {1,2,3,4,5,6};

    // Set Array Size  with variable
    {
        cout << "(size_t)student_scores : " << (size_t)student_scores << endl;
        cout << "(size_t)&student_scores : " << (size_t)&student_scores << endl;
        cout << "(size_t)&(student_scores[0]) : " << (size_t)&(student_scores[0]) << endl;
        cout << "(size_t)&(student_scores[1]) : " <<(size_t)&(student_scores[1]) << endl;
        cout << "(size_t)&(student_scores[2]) : " <<(size_t)&(student_scores[2]) << endl;
        cout << "(size_t)&(student_scores[3]) : " <<(size_t)&(student_scores[3]) << endl;

        cout << sizeof(student_scores) << endl;
    }

    {
        cout << "In main : " << sizeof(student_scores) << endl;
        doSomething(student_scores);
    }

    return 0;
}

