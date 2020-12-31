#pragma once

#include "Person.h"

class Student : public Person {
private:
    int m_intel; // intelligence
public:
    Student(const std::string& name_in, const int &intel_in): Person(name_in), m_intel(intel_in){}

    void setIntel(const int &intel_in){
        m_intel = intel_in;
    }

    int getIntel() const {
        return m_intel;
    }

    void study(){
        m_intel += 1;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student &p_in){
        out << " name is : " << p_in.getName();
        out << " intel is " << p_in.m_intel;
        return out;
    }
};