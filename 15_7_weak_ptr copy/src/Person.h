#pragma once
#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::shared_ptr;

// using shared_person = shared_ptr<Person>;

class Person {
private:
    string m_name;
    std::weak_ptr<Person> m_partner;
public:
    Person(const string &name_in = " "): m_name(name_in) {
        std::cout << "Person created" << std::endl;
    }

    ~Person(){
        std::cout << "Person destroyed" << std::endl;
    }

    // friend bool partnerUp(Person &person_1, Person &person_2){
    //     if (person_1.m_partner || person_2.m_partner)
    //         return false;

    //     person_1.m_partner = std::make_shared<Person>(person_2);
    //     person_2.m_partner = std::make_shared<Person>(person_1);

    //     std::cout << person_1.m_name << " is partnered with " << person_2.m_name << std::endl;

    //     return true;
    // }

    friend bool partnerUp(shared_ptr<Person> &person_1, shared_ptr<Person> &person_2){
        if (!person_1 || !person_2)
            return false;

        person_1->m_partner = person_2;
        person_2->m_partner = person_1;

        std::cout << person_1->m_name << " is partnered with " << person_2->m_name << std::endl;

        return true;
    }

    void setName(const string &name_in){
        m_name = name_in;
    }

    // weak_ptr must transform to shared_ptr when it used
    shared_ptr<Person> getPartner() const {
        return m_partner.lock();
    }

    const string& getName() const {
        return m_name;
    }
};