#include <iostream>

using namespace std;

void countDown(const int &num){
    if (num == 0)
        return;
    else{
        cout << num << endl;
        countDown(num - 1);
    }
}

int sumTo(const int &num){
    if (num == 0)
        return 0;
    else if(num <= 1)
        return 1;
    else{
        const int num_minus_one =  num - 1;
        return num_minus_one + num;
    }
}

// Fibonacci example
// 0 1 1 2 3 5 8 13 15
int fibonacci(const int &num){
    if (num == 1)
        return 0;
    else if (num == 2)
        return 1;
    else
        return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {

    // count down && sumTo example call 
    {
        countDown(5);
        cout << "sumTo(5) : " << sumTo(5) << endl;
    }

    // fibonacci example
    {
        cout << fibonacci(8) << endl;
    }    

    return 0;
}