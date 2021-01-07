#include "Resource.h"
#include <memory>

using std::unique_ptr;
using std::make_unique;

auto getResource(){

    return make_unique<Resource>(1000000);
}

// get unique_ptr by l value
void doSomething(unique_ptr<Resource> &res){
    res->setAll(10);
}

// what can we do in order to remove &
auto doSomething2(unique_ptr<Resource> res){
    res->setAll(10);
    
    // return with ownership 
    return std::move(res);
}

// get Resource Pointer
void doSomething3(Resource* res){
    res->setAll(10);    
}

int main(){

    // unique_ptr usage
    {
        // unique_ptr initialization

        // Case 1
        Resource *res = new Resource(1000000);
        unique_ptr<Resource> upi(res);

        // Case 2 more general
        unique_ptr<Resource> upi2(new Resource(1000000));

        // Case 3 make_unique
        auto upi3 = make_unique<Resource>(1000000);

        // Case 4 get return from function 
        auto upi4 = getResource();
    }

    // ownership movement example
    {
        auto upi1 = make_unique<Resource>(5);

        upi1->setAll(3);
        upi1->print();

        unique_ptr<Resource> upi2;

        std::cout << std::boolalpha;
        std::cout << "upi1 : " << static_cast<bool>(upi1) << std::endl;
        std::cout << "upi2 : " << static_cast<bool>(upi2) << std::endl;


        // move ownership
        upi2 = std::move(upi1);

        std::cout << std::endl << std::boolalpha;
        std::cout << "upi1 : " << static_cast<bool>(upi1) << std::endl;
        std::cout << "upi2 : " << static_cast<bool>(upi2) << std::endl;

        if (upi1 != nullptr) upi1->print();
        if (upi2 != nullptr) upi2->print();        
    }


    std::cout << "=============================" << std::endl; 

    // unique_ptr with function
    {
        auto res = make_unique<Resource>(10);

        res->setAll(1);
        res->print();

        // doSomething(res);
        // res = doSomething2(std::move(res));
        doSomething3(res.get());

        res->print();
    }

    std::cout << "=============================" << std::endl; 

    // mistake case
    {
        Resource *res = new Resource(10000);

        // mulitple ownership
        // unique_ptr<Resource> upi1(res);
        // unique_ptr<Resource> upi2(res);

        // double deletion
        // delete res;
    }

    return 0;
}