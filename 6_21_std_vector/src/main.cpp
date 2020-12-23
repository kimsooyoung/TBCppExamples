#include <iostream>
#include <vector>

using namespace std;

int main(){

    // Initialization
    {
        vector<int> array;
        vector<int> array2 = {1,2,3,4,5};
        vector<int> array3 = {1,2,3};
        vector<int> array4 {1,2,3};

        cout << array2.size() << endl;

        for ( const auto &i : array2)
            cout << i << " ";
        cout << endl;

        cout << array2[2] << " " << array2.at(2) << endl;

        // resize
        array2.resize(10);
        cout << "=== After Resize ===" << endl;

        for (auto &num : array2)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}