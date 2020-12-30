#pragma once

#include <vector>

#include "Teacher.h"
#include "Student.h" 

class Lecture{
private:
    std::string m_name;
    // composition
    Teacher* m_teacher;
    std::vector<Student *> m_students;

public:
    Lecture(const std::string &name_in=""): m_name(name_in) {}

    void assignTeacher(Teacher* const teacher_in){
        m_teacher = teacher_in;
    }
    void registerStudent(Student* const student_in) {
        m_students.push_back(student_in);
    }

    void study(){
        for (auto &elem : m_students)
            elem->setIntel(elem->getIntel() + 1);
    }

    friend std::ostream& operator<< (std::ostream& out, const Lecture& lec_in){
        out << lec_in.m_name << std::endl;
        out << *(lec_in.m_teacher) << std::endl;

        for (auto &elem : lec_in.m_students)
            out << *elem << std::endl;
        return out;
    }
};