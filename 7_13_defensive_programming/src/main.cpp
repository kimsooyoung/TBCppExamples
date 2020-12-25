#include <iostream>
#include <string>

using namespace std;

int main() {

    // semantic error
    {
        int x = 5;
        cout << "Type any number : "; 
        cin >> x; cin.ignore(32767, '\n');
        
        if(x >= 5) // => x > 5
            cout << "x is greater than 5" << endl;
    }

    // violated assumption
    {
        string my_str = "Here is fucking Hello World";
        int user_input;


        while(1){
            cout << "Input from 0 to " << my_str.size() - 1 << " : ";
            cin >> user_input; cin.ignore(32767, '\n');
            
            if(user_input >= 0 && user_input <= my_str.size() - 1){
                cout << "my_str[loc] : "<< my_str[user_input] << endl;
                break;
            }
            else
                cout << "Wrong input, try again" << endl;
        }
    }    

    return 0;
}