#include "Resource.h"
#include "AutoPtr.h"

void doSomething() { 
    // RAII : Resource Acquisition is Initialization    
    Resource *my_resource = new Resource();
    
    // my_resource must deleted in any function cases 
    if ( false ){
        delete my_resource;
        return ;
    }

    delete my_resource;
}

int main(){

    //
    {
        doSomething();
    }

    std::cout << "=========================" << std::endl;

    // AutoPtr Usage; 
    {
        AutoPtr<Resource> res = new Resource;
    }

    std::cout << "=========================" << std::endl;

    // Limitation of AutoPtr
    {
        // case1
        Resource res_origin;
        AutoPtr<Resource> res;
        
        // res = &res_origin; // Aborted (core dumped)

        // case2
        AutoPtr<Resource> res1(new Resource);
        AutoPtr<Resource> res2;
        
        // std::cout << res1.m_ptr << std::endl;
        // std::cout << res2.m_ptr << std::endl;
        
        // res2 = res1; // Aborted (core dumped)

        // std::cout << res1.m_ptr << std::endl;
        // std::cout << res2.m_ptr << std::endl;
    }

    // solution => move semantic
    {
        AutoPtrWithMS<Resource> res1(new Resource);
        AutoPtrWithMS<Resource> res2;

        std::cout << res1.m_ptr << std::endl;
        std::cout << res2.m_ptr << std::endl;
        
        res2 = res1; 

        std::cout << res1.m_ptr << std::endl;
        std::cout << res2.m_ptr << std::endl;
    }
}