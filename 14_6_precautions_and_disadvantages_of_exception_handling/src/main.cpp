#include <iostream>
#include <memory>

// Case 2. throw in Destructor is forbidden
class A {
public:
  ~A() {
    // warning: throw will always call terminate() [-Wterminate]
    // there's nothing to catch this -1
    throw -1;
  }
};

int main() {

  // Case 1. Memory Leak
  {
    try {
      int *i_arr = new int[1000];

      // throw before delete => memory leak!!
      throw -1;

      delete[] i_arr;
    } catch (...) {
      std::cerr << "Error and Memory Leak!!" << '\n';
    }
  }

  std::cout << "========================" << std::endl;

  // Case 2. throw in Destructor is forbidden
  {
      // Aborted (core dumped)
      // A a;
  }

  // Solution => Smart Pointer!
  {
    try {
      int *my_arr = new int[1000];
      // Now, unique_ptr take care of memory collection well.
      std::unique_ptr<int> up_i(my_arr);

      throw std::runtime_error("Error");
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
  }

  return 0;
}