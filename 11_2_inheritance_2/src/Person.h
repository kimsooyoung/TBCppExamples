#pragma once

#include <iostream>
#include <string>

class Person {
private:
  std::string m_name;

public:
  Person(const std::string &name_in = "No Name") : m_name(name_in) {}

  void setName(const std::string &name_in) { m_name = name_in; }

  std::string getName() const { return m_name; }

  friend std::ostream &operator<<(std::ostream &out, const Person &p_in) {
    out << " name is : " << p_in.m_name;
    return out;
  }
};