#include <iostream>
#include <limits>

int main(){

    using namespace std;

    {
        for (int i = 0; i < 10; ++i)
            cout << i << " ";
        cout << endl;

        for (int i = 0; i < 10; i++)
            cout << i << " ";
        cout << endl;
        
        // this same with
        int i = 0;
        for(; i < 10 ; i++)
            cout << i << " ";
        cout << endl;

        cout << "I can still use count value i : " << i << endl;
    }

    // Endless For
    {
        int count = 0;
        for(;;++count){
            if(count > 1000)
                break;
        }
    }

    // Decrease For
    {

        for(int i = 10; i > 0; i -= 2){
            cout << i << " ";
        }
        cout << endl;

        for(int i = 0, j = 0; (i + j) < 10; ++i, j += 2)
            cout << i << " , " << j << endl;
        cout << endl;
    }

    // DO NOT use UNSIGNED INT to for loop
    {
        for(unsigned int i = 10; i <= 0; --i){
            cout << i << " ";

            if(i == numeric_limits<unsigned int>::max() - 2)
                break;
        }
    }

    return 0;
}