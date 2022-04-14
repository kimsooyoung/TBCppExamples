#include <iostream>

#include <array>
#include <cassert>
#include <initializer_list>
#include <vector>

class IntArray {
private:
  int m_length = 0;
  int *m_data = nullptr;

public:
  IntArray(const int &size_in = 0) : m_length(size_in) {
    m_data = new int[m_length];
    initialize();
  }

  IntArray(const std::initializer_list<int> &list) : IntArray(list.size()) {
    int count = 0;

    for (auto &elem : list)
      m_data[count++] = elem;
  }

  ~IntArray() { delete[] m_data; }

  void initialize() {
    for (int i = 0; i < m_length; i++)
      m_data[i] = 0;
  }

  void reset() {
    if (m_data != nullptr) {
      delete[] m_data;
      m_data = nullptr;
      m_length = 0;
    }
  }

  void resize(const int &size_in) {
    int *temp = new int[m_length];

    for (int i = 0; i < m_length; i++)
      temp[i] = m_data[i];

    m_length = size_in;

    delete[] m_data;
    m_data = temp;
  }

  void insertBefore(const int &val_in, const int &ix) {
    assert(ix >= 0);
    assert(ix <= m_length);

    int *temp = new int[m_length + 1];

    int i = 0;
    for (; i < ix; i++)
      temp[i] = m_data[i];

    temp[i] = val_in;

    for (; i < m_length; i++)
      temp[i + 1] = m_data[i];

    realloc(temp);
    m_length += 1;
  }

  void remove(const int &ix) {
    assert(ix >= 0);
    assert(ix <= m_length);

    int *temp = new int[m_length - 1];

    int i = 0;
    for (; i < ix; i++)
      temp[i] = m_data[i];

    for (; i < m_length - 1; i++)
      temp[i] = m_data[i + 1];

    realloc(temp);
    m_length -= 1;
  }

  void push_back(const int &val_in) {
    int *temp = new int[m_length + 1];

    int i = 0;
    for (; i < m_length; i++)
      temp[i] = m_data[i];
    temp[i] = val_in;

    realloc(temp);
    m_length += 1;
  }

  void realloc(int *const temp) {
    delete[] m_data;
    m_data = temp;
  }

  friend std::ostream &operator<<(std::ostream &out, const IntArray &arr_in) {
    for (auto i = 0; i < arr_in.m_length; i++)
      out << arr_in.m_data[i] << " ";
    out << " / length : " << arr_in.m_length;
    return out;
  }
};

int main() {

  //  container recap
  {
    std::vector<int> int_vec;
    std::array<int, 10> int_arr;
  }

  {
    IntArray my_arr{1, 3, 5, 7, 9};

    std::cout << my_arr << std::endl;
    my_arr.insertBefore(10, 1);
    std::cout << my_arr << std::endl;

    my_arr.remove(3);
    std::cout << my_arr << std::endl;

    my_arr.push_back(13);
    std::cout << my_arr << std::endl;
  }
  return 0;
}