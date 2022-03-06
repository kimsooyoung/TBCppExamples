/* 
 * Caution
 * 
 * this example requires C++ 17 compiler
 * 
*/ 

#include <iostream>
#include <string>
#include <tuple>

using namespace std; 

tuple<string, int> getProfile(){
    return tuple<string, int>("Mrs. Puff", 45);
}

// vscode will treat this as error.
auto getModernProfile(){
    return tuple("Mrs. Puff", 45);
}


int main(){

    // old school
    {
        auto profile = getProfile();

        cout << std::get<0>(profile) << " " << std::get<1>(profile) << endl;
    }

    // modern approach
    {
        auto[name, age] = getModernProfile();

        cout << name << " " << age << endl;
    }

    return 0;
}