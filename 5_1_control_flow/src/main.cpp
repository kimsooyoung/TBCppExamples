#include <iostream>
#include <string>

struct Person{
    double       height;
    float        weight;
    int          age;
    std::string  name;

    void print(){
        std::cout << "height : \t" << height << 
            "\nweight : \t" << weight << 
            "\nage : \t" << age << 
            "\nname : \t" << name << 
        std::endl;
    }
};

struct Employee {
    short    id;   // 2 bytes
    int      age;  // 4 bytes
    double   wage; // 8 bytes
};

// struct return function
Person getMe(){
    Person me { 2.0, 100.0, 20, "Jack Jack" };
    return me;
}

struct Family{
    Person me, mom, dad;
};

int main()
{
    {
        Person me{2.0, 100.0, 20, "Jack Jack"};
        Person me2;
        me2 = me;
        me2.print();
    }

    {
        Person me_from_func = getMe();
        
        // Person me{2.0, 100.0, 20, "Jack Jack"};
        // or
        Person me;
        me.age = 12;
        me.height = 170.1;
        me.weight = 65.0;
        me.name = "Human1";

        me.print();
    }

    {
        Employee emp1;
        std::cout << "size of Employee : " << sizeof(Employee) << std::endl;
    }

    return 0;
}
