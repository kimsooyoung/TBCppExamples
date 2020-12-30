#include <iostream>
#include <string>
#include <vector>

class Doctor;

class Patient {
private:
    std::string m_name;
    std::vector<Doctor*> m_docs;
public:
    Patient(const std::string &name_in = ""): m_name(name_in) {}

    void addDoctor(Doctor* const doc_in){
        m_docs.push_back(doc_in);
    }

    void printDoctors();

    friend class Doctor;
};

class Doctor{
private:
    std::string m_name;
    std::vector<Patient*> m_pats;
public:
    Doctor(const std::string &name_in = ""): m_name(name_in) {}
    
    void addPatient(Patient* const pat_in){
        m_pats.push_back(pat_in);
    }

    void printPatients();

    friend class Patient;
};

void Patient::printDoctors(){
    for (auto &elem : m_docs)
        std::cout << "I Met Doctor : " << elem->m_name << std::endl;
}

void Doctor::printPatients(){
    for (auto &elem : m_pats)
        std::cout << "I Met Patient : " << elem->m_name << std::endl;
}   

int main(){
    
    Patient *p1 = new Patient("Jack Jack");
    Patient *p2 = new Patient("Dash");
    Patient *p3 = new Patient("Violet");

    Doctor *d1 = new Doctor("Doctor K");
    Doctor *d2 = new Doctor("Doctor L");
    

    {
        p1->addDoctor(d1);
        d1->addPatient(p1);

        p2->addDoctor(d2);
        d2->addPatient(p2);

        p2->addDoctor(d1);
        d1->addPatient(p2);

        p1->printDoctors();
        d1->printPatients();
    }


    delete p1;
    delete p2;
    delete p3;

    delete d1;
    delete d2;

    return 0; 
}