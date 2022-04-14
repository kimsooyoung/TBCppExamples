#include "Lecture.h"

int main(){

    Teacher *hong   = new Teacher("Prof, Hong");
    Teacher *good   = new Teacher("Prof, Good");

    Student *jj     = new Student("Jack Jack", 0);
    Student *dash   = new Student("Dash", 1);
    Student *violet = new Student("Violet", 1);

    Lecture lec1("Introduction to Computer Programming");
    lec1.assignTeacher(hong);

    lec1.registerStudent(jj);
    lec1.registerStudent(dash);
    lec1.registerStudent(violet);

    // test
    {  
        Lecture lec2("Computational Thinking");
        lec2.assignTeacher(good);

        lec2.registerStudent(jj);
        
        std::cout << lec1 << std::endl;
        std::cout << lec2 << std::endl;

        lec2.study();
        std::cout << "======== study ========" << std::endl;

        std::cout << lec1 << std::endl;
        std::cout << lec2 << std::endl;
    }

    delete hong;
    delete good;
    delete jj;
    
    delete dash;
    delete violet;

    return 0; 
}