#include <iostream>
#include <string>

using namespace std;

struct Student {
    string m_name;
    int m_id;
public:
    Student(const int &id_in, const string &name_in) : m_name(name_in), m_id(id_in) {}
    // delegating constructor
    Student(const string &name_in): Student(0, name_in) {};
    void print(){
        cout << m_id << " " << m_name << endl;
    }
}; 

// Old School Method
struct Sth{
    string m_name;
    int m_id;
public:
    void init(const int &id_in, const string &name_in) {
        m_name   = name_in;
        m_id     = id_in;
    }
    void init(const string &name_in){
        cout << "only name " << endl;
        init(0, name_in);
    }
    void init(const int &id_in){
        cout << "only id " << endl;
        init(id_in, "nothing");
    }
    void print(){
        cout << m_id << " " << m_name << endl;
    }
};

int main(){
    // delegating constructor Usage 
    {
        Student first_student(10,"Kim");
        first_student.print();

        Student second_student("James");
        second_student.print();
    }

    // old school
    {
        cout << "==== old school example ====" << endl;
        Sth sth_1;
        Sth sth_2;
        Sth sth_3;

        sth_1.init(0,"sth_1");
        sth_2.init("sth_2");
        sth_3.init(3);

        sth_1.print();
        sth_2.print();
        sth_3.print();
    }

    return 0;
}