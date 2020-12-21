#include <iostream>

using namespace std;

struct Person {
    int age;
    double weight;
};

int main(){

    {
        Person person;
        person.age = 5;
        person.weight = 30;

        // These are same with those belows
        Person &ref_person = person;
        ref_person.age = 15;

        Person *ptr_person = &person;
        // -> operator's meaning
        ptr_person->age = 30;
        // (*ptr_person).age = 30;

        Person &ref_person2 = *ptr_person;
        ref_person2.age = 45;

        cout << &person << endl;
        cout << &ref_person2 << endl;
    }


    return 0;
}