#include <iostream>

class Exception {
private:
  char *err_msg = nullptr;

public:
  virtual void report() { std::cout << "Exception Report!" << std::endl; }
};

// Exception class with polymorphism
class ArrayException : public Exception {
public:
  void report() override { std::cout << "ArrayException Report!" << std::endl; }
};

class MyArray {
private:
  int m_arr[5];

public:
  int &operator[](const int &index) {
    if (index < 0 || index >= 5)
      throw ArrayException();

    return m_arr[index];
  }
};

void doSomething() {
  MyArray my_arr;

  try {
    my_arr[100];
  }
  // Polymorphism applied
  catch (Exception &e) {
    e.report();
  }

  std::cout << "No problem in doSomething" << std::endl;
}

void doSomethingAndThrow() {
  MyArray my_arr;

  try {
    my_arr[100];
  }
  // Polymorphism applied
  catch (Exception &e) {
    e.report();
    // throw e; => throw Exception
    throw; //  => throw ArrayException
  }

  std::cout << "No problem in doSomething" << std::endl;
}

int main() {

  // Exception class with polymorphism
  { doSomething(); }

  // nested exception
  {
    try {
      doSomethingAndThrow();
    } catch (ArrayException &e) {
      e.report();
    } catch (Exception &e) {
      e.report();
    }
  }

  return 0;
}