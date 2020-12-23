#include <iostream> 

using namespace std;

void doSomething(int x){
    cout << "x : " << x << " &x : " << &x << endl;
}

int main(){

    {
        int x = 5;

        doSomething(2);

        // those two are different
        cout << "x : " << x << " &x : " << &x << endl;
        doSomething(x); 
        // variable x => argument 5 => copied to parameter x
    }

    return 0;
}