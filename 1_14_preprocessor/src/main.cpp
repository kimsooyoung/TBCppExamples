#include <iostream>
#include <algorithm>

#define MY_NUMBER 18
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

#define LIKE_APPLE

int main(){
#ifdef LIKE_APPLE
    std::cout << "User Likes Apple" << std::endl;
#else
    std::cout << "User hates Apple" << std::endl;
#endif

    std::cout << MAX(1 + 3, 10) << std::endl;
    std::cout << std::max(1 + 3, 10) << std::endl;

    return 0;
}