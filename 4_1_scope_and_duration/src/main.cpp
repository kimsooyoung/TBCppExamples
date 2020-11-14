#include <iostream>

namespace work1 {
    int a = 1;
    void doSomething(){
        a += 3;
    }
}


namespace work2{
    int a = 1;
    void doSomething(){
        a += 5;
    }
}

// nested namespace : from C++17
// namespace space1{
//     namespace space2{
//         namespace space3{
//             int a = 1;
//             void doSomething(){
//                 a += 3;
//             }
//         }
//     }
// }

namespace space1::space2::space3{
    int a = 1;
    void doSomething(){
        a += 3;
    }
}

int main()
{

    {
        int apple = 5;

        std::cout << "apple : " << apple << std::endl;
        
        {
            apple = 1;
            std::cout << "apple : " << apple << std::endl;
        }

        std::cout << "apple : " << apple << std::endl;
    }

    {
        int apple = 5;

        std::cout << "apple : " << apple << std::endl;

        {
            int apple2 = 1;
            std::cout << "apple : " << apple << std::endl;
        }
        std::cout << "apple : " << apple << std::endl;
    }

    {
        work1::a;
        work1::doSomething();

        work2::a;
        work2::doSomething();
    }
    
    return 0;
}