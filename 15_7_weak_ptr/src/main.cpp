#include "Person.h"

int main(){

    auto lucy = std::make_shared<Person>("lucy");
    auto sam  = std::make_shared<Person>("sam");

    partnerUp(lucy, sam);

    // what happend if change name of one Person?
    sam->setName("SAMSUNG"); 
    std::cout << sam->getName() << std::endl;
    std::cout << lucy->getPartner()->getName() << std::endl;

    // creatation success, but destroy failed
    // lucy and sam's shared_ptr has cyclic structure

    // Person created
    // Person created
    // lucy is partnered with sam
    // SAMSUNG
    // SAMSUNG

    // solution => weak_ptr
    
    return 0;
}