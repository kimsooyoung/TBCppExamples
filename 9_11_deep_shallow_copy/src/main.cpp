#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

class MyString {
private:
  int m_length = 0;

public:
  char *m_data = nullptr;

  MyString(const char *source = "") {
    assert(source);

    m_length = std::strlen(source) + 1;
    m_data = new char[m_length];

    for (auto i = 0; i < m_length; i++)
      m_data[i] = source[i];

    m_data[m_length - 1] = '\0';
  }

  MyString(const MyString &source) {
    cout << "Copy Constructor Called" << endl;

    m_length = source.m_length;

    _init(source.m_data);
  }

  MyString &operator=(const MyString &source) {
    cout << "Assignment Operator Called" << endl;

    if (this == &source)
      return *this;

    delete[] m_data;

    m_length = source.m_length;

    _init(source.m_data);

    return *this;
  }

  ~MyString() { delete[] m_data; }

  void _init(const char *arr_in) {
    if (arr_in != nullptr) {
      m_data = new char[m_length];

      for (int i = 0; i < m_length; i++)
        m_data[i] = arr_in[i];
    } else
      m_data = nullptr;
  }

  char *getString() { return m_data; }
  int getLen() { return m_length; }
};

int main() {

  // shallow copy and error case
  {
    MyString hello("hello");

    cout << (int *)hello.m_data << endl;
    cout << hello.getString() << endl;

    {
      MyString copy(hello);
      cout << (int *)copy.m_data << endl;
      cout << copy.getString() << endl;
    }

    cout << hello.getString() << endl;
    // free(): double free detected in tcache 2
    // Aborted (core dumped)

    // How to fix this? => deep copy
  }

  // Assignment Operator
  {
    MyString hello("hello");

    MyString copy = hello;
    copy = hello;
  }

  return 0;
}