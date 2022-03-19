#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

int main(){

    // Basic Usage
    {
        int fibonacci[] = { 0,1,1,2,3,5,8,13,21 };

        for(int number : fibonacci)
            number = 10;
        for(int number : fibonacci)
            std::cout << number << " ";
        std::cout << std::endl;
        
        for (auto &i : fibonacci)
            i++;
        
        for ( const auto &i : fibonacci)
            cout << i << " ";
        
        cout << endl;
    }


    // Find min/max nubmer using for-each loop
    {
        int fibonacci[] = { 0,1,1,2,3,5,8,13,21 };
        
        int min_number = std::numeric_limits<int>::lowest();
        int max_number = std::numeric_limits<int>::max();

        cout << max_number << " " << min_number << endl;

        for ( const auto &num : fibonacci)
            min_number = std::max(min_number, num);
        cout << "Max Number : " << min_number << endl;

        for (auto &num : fibonacci)
            max_number = std::min(max_number, num);
        cout << "Min Number : " << max_number << endl;
    }

    // Cannot use For-each to Dynamic Allocated Array
    // Use vector then.
    // #include <vector>

    return 0;
}