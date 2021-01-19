#include "Resource.h"
#include "AutoPtr.h"
#include "Timer.h"

AutoPtr<Resource> generateResource(){

    std::cout << "Function in" << std::endl;
    AutoPtr<Resource> res(new Resource(1000000));
    std::cout << "Function out" << std::endl;

    return res;
}

int main(){

    std::streambuf* orig_buf = std::cout.rdbuf();
    // std::cout.rdbuf(NULL);

    Timer timer;

    {
        // AutoPtr<Resource> main_res;
        // main_res = generateResource();

        AutoPtr<Resource> res(new Resource(1000000));


        // Resource resource(100);
        // AutoPtr<Resource> res1(&resource);
    }

    // std::cout.rdbuf(orig_buf);
    timer.elapsed();


    return 0;
}

