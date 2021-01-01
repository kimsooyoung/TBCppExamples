#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string m_name;
public:
    Animal(const string &name_in="Animal"): m_name(name_in) {}
    
     virtual void speak() const {
        cout << "???" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(const string &name_in): Animal(name_in) {}
    
    void speak() const {
        cout << "Meow" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(const string &name_in): Animal(name_in) {}

    void speak() const {
        cout << "Woof" << endl;
    }
};

int main(){

    // Basic Usage of example classes
    {   
        Animal ani;
        Cat cat("Cat0");
        Dog dog("Dog0");

        ani.speak();
        cat.speak();
        dog.speak();
    }

    cout << "===================" << endl;

    // Put Child class in Mother class pointer
    {
        Cat cat("Cat0");
        Dog dog("Dog0");

        Animal *ptr_ani = &cat;
        ptr_ani->speak();

        ptr_ani = &dog;
        ptr_ani->speak();
    }

    cout << "===================" << endl;

    {
        Cat cats[] = { Cat("Cat0"), Cat("Cat1"), Cat("Cat2"),Cat("Cat3"),Cat("Cat4") };
        Dog dogs[] = { Dog("Dog0"), Dog("Dog1") };

        for (auto &cat : cats)
            cat.speak();
        
        for(auto &dog : dogs)
            dog.speak();
        
        Animal *animals[] = { &cats[0], &cats[1], &cats[2], &cats[3], &cats[4], &dogs[0], &dogs[1] };

        // Let's type virtual in front of 
        // speak() function in Animal class
        for(auto &ani : animals)
            ani->speak();
    }

    return 0;
} 