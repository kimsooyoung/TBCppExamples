#include <iostream>

class Animal{
private:
  int age;
public:
  virtual void speak(){
    std::cout << "???" << std::endl;
  }
};

class Cow : public Animal{
public:
  void speak() override {
    std::cout << "Mooo" << std::endl;
  }
};

class Cat : public Animal{
public:
  void speak() override {
    std::cout << "Meow" << std::endl;
  }
};

int main(){

  Cow cow;
  Animal& animal = cow;

  animal.speak();

  return 0;
}