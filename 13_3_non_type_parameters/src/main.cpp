#include "MyArray.h"

int main(){

    using namespace std;
    
    // Instantiation with Arr size
    {
        MyArray<int, 10> m_arr {1,2};

        std::cout << m_arr << std::endl;
    }

    return 0;
}