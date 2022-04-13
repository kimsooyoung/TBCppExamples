#include <cassert>
#include <iostream>

using namespace std;

class IntList {
private:
  int m_size = 10;
  int m_arr[10] = {0};

public:
  IntList() {}
  void setItem(int index, int value) {
    assert(index >= 0);
    assert(index <= m_size);
    m_arr[index] = value;
  }
  int getItem(int index) const {
    cout << "index : " << index << endl;
    assert(index >= 0);
    assert(index <= m_size);
    return m_arr[index];
  }
  int *getList() { return m_arr; }

  int &operator[](const int &index) {
    assert(index >= 0);
    assert(index <= m_size);
    return m_arr[index];
  }

  const int &operator[](const int &index) const {
    assert(index >= 0);
    assert(index <= m_size);

    cout << "const operator [] runs" << endl;
    return m_arr[index];
  }
};

int main() {

  // Basic Usage
  {
    IntList i_list;

    i_list.setItem(0, 100);
    cout << i_list.getItem(0) << endl;

    i_list.getList()[3] = 3;
    cout << i_list.getItem(3) << endl;
  }

  // [] operator usage
  {
    IntList i_list;

    i_list.setItem(2, 222);
    cout << i_list[2] << endl;
  }

  // operator [] with const Object
  {
    const IntList i_list;

    i_list[1];
  }

  // Caution, pointer
  {
    IntList *list = new IntList;

    // list[3] = 10; // NOT OK
    (*list)[3] = 10; // OK
  }

  return 0;
}