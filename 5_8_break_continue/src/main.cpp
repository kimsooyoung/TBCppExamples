#include <iostream>
#include <limits>

void breakOrReturn(){
    while (1)
    {
        char ch;
        cin >> ch;

        if(ch == 'b')
            break;

        if(ch == 'r')
            return;
    }
}


int main(){

    using namespace std;

    {
        for(int i=0; i < 10; ++i){
            if(i %2 == 0 ) continue;
            std::cout << i << std::endl;
        }
    }

    // Endless loop with do-while && continue
    {
        int count = 0;
        do{
            if(count == 5)
                continue;
            
            cout << count << endl;
            count++;

        }while(count < 10) ;
    }

    return 0;
}