#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    // assign
    {
        string str1("I am string 1");
        cout << str1 << endl;

        str1.assign("No, you are string 2!!");
        cout << str1 << endl;

        // assign can be used with std::find
        string tmi("I was born at South Korea and My mom really loved me. "
                    "And I went to kindergarten at there I met Jimmy, "
                    "He was brilliant genious at Computer Science and He teached me...");

        string J_story;
        J_story.assign(find(tmi.begin(),tmi.end(), 'J'), tmi.end());

        cout << J_story << endl;
    }

    cout << endl;

    // append, with assign
    {
        string str1("One");
        string str2("Two");
        string str0;

        // assign return its reference
        // so can use chaining
        str0.assign("Zero").append(" ").append(str1).append(" ").append(str2); 
        
        cout << str0 << endl;
    }

    cout << endl;


    // swap
    {
        string str1("One");
        string str2("Two");

        cout << str1 << " " << str2 << endl;

        swap(str1, str2);

        cout << str1 << " " << str2 << endl;

        str1.swap(str2);

        cout << str1 << " " << str2 << endl;
    }

    cout << endl;

    // string similar to vector
    {
        string str1("one");
        string str2(" three");

        str1.push_back(' ');
        str1.push_back('t');
        str1.push_back('w');
        str1.push_back('o');
        cout << str1 << endl;

        str1 += str2;
        cout << str1 << endl;

        str1.insert(3, " point five");
        cout << str1 << endl;

    }

    return 0;
}