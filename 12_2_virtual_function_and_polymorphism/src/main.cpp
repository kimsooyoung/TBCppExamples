#include <iostream>

#include "Class.h"
#include "VirtualClass.h"

int main() {

  // Without Virual function
  {
    B b;
    C c;
    D d;

    A &ref_a = b;
    // this will print A
    ref_a.print();
  }

  std::cout << "========================" << std::endl;

  // now use virtual
  {
    VirtualB b;
    VirtualC c;
    VirtualD d;

    VirtualA ref_a = b;
    // this will print VirtualB
    ref_a.print();

    VirtualA ref_c = c;
    ref_c.print();

    VirtualB ref_b = d;
    ref_b.print();
  }

  return 0;
}