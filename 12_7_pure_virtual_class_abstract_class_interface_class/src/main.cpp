#include <iostream> 
#include <string>

class Animal {
private:
    std::string m_name;
public:
    Animal(const std::string &name_in="Animal"): m_name(name_in) {}
    virtual void speak() const = 0;
};

class Cat : Animal {
public:
    virtual void speak() const override {
        std::cout << "Meow" << std::endl;
    }
};

class Dog : Animal {
public:
    virtual void speak() const override {
        std::cout << "Woof" << std::endl;
    }
};

class Cow : Animal {
public:
    // virtual void speak() const override {
    //     std::cout << "Moo" << std::endl;
    // }
};

// Interface class starts with I
class IErrorLog {
public:
    virtual bool reportError(const char *errorMsg) = 0;

    virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog {
public:
    virtual bool reportError(const char *errorMsg) override {
        std::cout << "File Error" << std::endl;
        return true;
    }
};

class ConsoleErrorLog : public IErrorLog {
public:
    virtual bool reportError(const char *errorMsg) override {
        std::cout << "Console Error" << std::endl;
        return true;
    }
};

// Interface class Usage
// This could handle both type (FileErrorLog, ConsoleErrorLog) of Derived class
void doSth(IErrorLog &log){
    log.reportError("Error!!");
}

int main() { 

    // Animal has pure virtual function
    // is not allowed to assigned
    {
        // Animal ani;
    }

    {
        // Cow not allowed
        // pure virtual function speak must be overrided
        // Cow cow;
    }

    // Use like this
    {
        Cat cat;
        cat.speak();
    }

    // Interface class example
    {
        FileErrorLog f_err;
        ConsoleErrorLog c_err;

        doSth(f_err);
        doSth(c_err);
    }

    return 0;
}