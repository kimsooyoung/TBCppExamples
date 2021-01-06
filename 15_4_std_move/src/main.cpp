#include "Resource.h"
#include "AutoPtr.h"

#include <utility>
#include <string>
#include <vector>

template <typename T>
void swap(T &x, T &y){
    
    // ordinary l value swap
    // T temp = x;
    // x = y;
    // y = temp;

    // r value swap
    T temp { std::move(x) };
    x = std::move(y);
    y = std::move(temp);
}

int main(){

    // std::move usage
    {
        AutoPtr<Resource<int>> res1(new Resource<int> (100000));

        std::cout << res1.m_ptr << std::endl;

        // std::move makes l value to r value
        AutoPtr<Resource<int>> res2 = std::move(res1);

        std::cout << res1.m_ptr << std::endl;
        std::cout << res2.m_ptr << std::endl;
    }

    std::cout << "==========================" << std::endl;

    // r value swap usage
    {
        AutoPtr<Resource<int>> ptr1(new Resource<int>(5)); 
        AutoPtr<Resource<int>> ptr2(new Resource<int>(3)); 

        ptr1->setAll(5);
        ptr2->setAll(3);

        ptr1->print();
        ptr2->print();

        swap(ptr1, ptr2);

        ptr1->print();
        ptr2->print();
        
        // // l value swap result
        // AutoPtr Copy Constructor
        // Resouce Default Constructor
        // Resource Copy Assignment
        // AutoPtr Copy Assignment
        // Resource Destructor
        // Resouce Default Constructor
        // Resource Copy Assignment
        // AutoPtr Copy Assignment
        // Resource Destructor
        // Resouce Default Constructor
        // Resource Copy Assignment
        // AutoPtr Destructor
        // Resource Destructor

        // // r value swap result
        // AutoPtr Move Constructor
        // AutoPtr Move Assignment
        // AutoPtr Move Assignment
        // AutoPtr Destructor

    }

    std::cout << "==========================" << std::endl;

    // std::vector already has r value function overloading
    // so we can use move easily
    {
        using namespace std;

        vector<string> vec;
        string str ("Hello");

        vec.push_back(str);

        cout << "str : " << str << endl;
        cout << "vec : " << vec[0] << endl;

        vec.push_back(move(str));

        cout << "str : " << str << endl;
        cout << "vec : " << vec[0] << " " << vec[1] << endl;
    }



    return 0;
}