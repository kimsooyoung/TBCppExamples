#include <iostream> 

#include "Teacher.h"
#include "Student.h"

int main(){

    Student std("Jack Jack", 0);
    std.setName("Jack Jack 2");
    std::cout << std << std::endl;

    Teacher tch("Dr. H");
    tch.setName("Dr. K");
    std::cout << tch << std::endl;

    std.study();
    std::cout << std << std::endl;


    return 0;
}