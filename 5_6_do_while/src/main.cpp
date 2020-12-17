#include <iostream>

int main(){

    using namespace std;

    int selection;

    do
    {
        cout << "Select prefer operation" << endl;
        cout << "1. add" << endl;
        cout << "2. sub" << endl;
        cout << "3. mul" << endl;
        cout << "4. div" << endl;
        cin >> selection;
    } while ( selection <= 0 || selection >= 5 );

    cout << "You Selected " << selection << endl;

    return 0;
}