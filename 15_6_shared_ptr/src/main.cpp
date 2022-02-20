#include "Resource.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;

int main(){
    
    // shared_ptr Basic usage
    {
        Resource *res = new Resource(5);
        res->setAll(1);
        res->print();

        shared_ptr<Resource> spr(res);

        spr->setAll(10);
        
        res->print();
    }

    std::cout << "===========================" << std::endl;

    // shrared_ptr counts how much it is derived 
    {
        {
            shared_ptr<Resource> spr(new Resource(5));
            spr->setAll(1);
            spr->print();

            {
                shared_ptr<Resource> spr2(spr);
                spr2->setAll(2);
                spr2->print();

                std::cout << "Going out of First Block" << std::endl;
            }

            std::getchar();

            spr->print();

            std::cout << "Going out of Second Block" << std::endl;
        }
    }

    std::cout << "===========================" << std::endl;

    // make_shared, copy assignment
    {
        // Error caes
        Resource *res = new Resource(5);
        shared_ptr<Resource> spr_err(res);

        // Error, spr_err2 doesn't know about spr_err
        // multiple deletetion occurs
        // shared_ptr<Resource> spr_err2(res);


        auto spr = make_shared<Resource>(5);
        spr->setAll(1);
        spr->print();

        {
            // copy easily with copy assignment
            // and deduction
            auto spr2 = spr;
            spr2->setAll(2);
        }

        spr->print();
    }

    return 0;
}