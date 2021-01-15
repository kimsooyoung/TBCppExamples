#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

void printStates(const std::ios& stream){
    cout << boolalpha;
    cout << "good() : " << stream.good() << endl;
    cout << "eof() : " << stream.eof() << endl;
    cout << "fail() : " << stream.fail() << endl;
    cout << "bad() : " << stream.bad() << endl;
}

void printCharacterClassification(const char &i){
    cout << boolalpha;
    cout << "isalnum : " << bool(std::isalnum(i)) << endl;
    cout << "isblank : " << bool(std::isblank(i)) << endl;
    cout << "isdigit : " << bool(std::isdigit(i)) << endl;
    cout << "islower : " << bool(std::islower(i)) << endl;
    cout << "isupper : " << bool(std::isupper(i)) << endl;
}

bool isAllDigit(const string &str){
    bool ok_flag = true;

    for (auto &elem : str)
    {
        if (!std::isdigit(elem)){
            ok_flag = false;
            break;
        }
    }

    return ok_flag;
}

bool classifyCharacters(const string &str){

    for (auto &elem : str)
    {
        cout << "isblank : " << bool(std::isblank(elem)) << endl;
        cout << "isdigit : " << bool(std::isdigit(elem)) << endl;
        cout << "isalpha : " << bool(std::isalpha(elem)) << endl;
        cout << endl;
    }
}


int main(){

    int i;
    char c;

    while (1){
        // stream status flag example
        // cin >> i;
        // printStates(cin);

        // character check example
        // cin >> c;
        // printCharacterClassification(c);
        
        //  character check example with bitmask
        // cout << boolalpha;
        // cout << std::bitset<8>(cin.rdstate()) << endl;
        // cout << std::bitset<8>(std::istream::goodbit) << endl;
        // cout << std::bitset<8>(std::istream::failbit) << endl;
        // cout << !bool((cin.rdstate() & std::istream::failbit ) != 0 ) << endl;

        // All digit check example
        // string str;
        // cin >> str;

        // cout << boolalpha;
        // cout << isAllDigit(str) << endl;


        // string str;
        // cin >> str;

        // classifyCharacters(str);

        // cin.clear();
        // cin.ignore(32767,'\n');
    }

    return 0;
}