#pragma once

#include "Person.h"

class Teacher : public Person {
public:
    Teacher(const std::string &name_in): Person(name_in){}
};