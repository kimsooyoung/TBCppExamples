#include <iostream>
#include <regex>

using namespace std; 

int main() {

    // regex re("\\d+"); // one digit
    // regex re("[[:digit:]]+"); // same with above
    // regex re("[[:digit:]]{3}"); // allow only three digits
    // regex re("[ab]"); // a or b
    // regex re("[A-Z]+"); // from A to Z
    // regex re("[A-Z]{1,5}"); // from A to Z, size from 1 to 5

    // complex example
    // regex re("([0-9]+)([-]?)([0-9]{1,4})");

    // phone number example
    // regex re("[01]{3}-\\d{3,4}-\\d{4}");

    // email example
    regex re("(\\w+)@(\\w+).([a-z]+)(.?)([a-z]*)");

    string str;

    while(1){
        getline(cin, str);

        if (std::regex_match(str, re))
            cout << "Match" << endl;
        else
            cout << "No match" << endl;

        // auto matches
        {
            auto begin = std::sregex_iterator(str.begin(), str.end(), re);
            auto end = std::sregex_iterator();
            
            // traverse str, and recommend match case
            for (auto itr = begin; itr != end; itr++)
            {
                std::smatch match = *itr;
                cout << match.str() << " ";
            }
            cout << endl;
        }
    }

    return 0;
}