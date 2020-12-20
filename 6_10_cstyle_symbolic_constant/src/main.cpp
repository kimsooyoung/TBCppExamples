#include <iostream>

using namespace std;

const char * getName(){
    return "Hello Hello";
}

int main(){

    // It's Exception Case
    // `cout` allows to show literal pointer directly
    {
        const char *name = "Jack Jack";
        const char *name2 = "Jack Jack";
        const char *name3 = "Jack jack";

        cout << name << " " << (uintptr_t)(&name) << endl;
        cout << name2 << " " << (uintptr_t)(&name2) << endl;
        cout << name3 << " " << (uintptr_t)(&name3) << endl;

    }

    // const char* type function return usage
    {
        cout << getName() << endl;
        const char *name = getName();
    }

    // Error Case
    {
        char c = 'Q';

        // Compiler misunderstood &c as const char*
        cout << &c << endl;
    }

    return 0;
}