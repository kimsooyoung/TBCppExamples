#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void printValue( const vector<int> &arr, const int &num ){
    assert(num >= 0);
    assert(num < arr.size());

    cout << "arr[num] : " << arr[num] << endl;
}

int main(){

    // Basic Usage
    {
        // assert(false);

        int num = 5;
        assert(num == 5);
    }

    // Assert Example
    {
        vector<int> arr {1,2,3,4,5,6,7,8,9,10};
        
        int user_input;

        cout << "Type location : ";
        cin >> user_input; cin.ignore(32767, '\n');

        printValue(arr, user_input);
    }

    // static_assert
    {
        const int x = 5;

        // x must be identified in compile time
        static_assert(x == 5, "x shold be five");

        // Error Case
        int user_input;
        
        cout << "Type location : ";
        cin >> user_input; cin.ignore(32767, '\n');

        // user_input cannot identified during compile time
        // static_assert(user_input < 0, "user_input out of range");
    }

    return 0;
}