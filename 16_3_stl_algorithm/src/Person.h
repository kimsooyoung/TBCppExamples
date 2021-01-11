#pragma once 

#include <string>
#include <iostream>

class Person {
private:
    std::string m_name;
    int m_age;
public:
    Person(const std::string &name_in="", const int &age_in=0): m_name(name_in), m_age(age_in) {
        std::cout << "Person Constructor Called" << std::endl;
    }

    ~Person(){
        std::cout << "Person Destructor Called" << std::endl;
    }
};