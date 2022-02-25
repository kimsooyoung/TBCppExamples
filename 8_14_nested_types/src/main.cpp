#include <iostream>

using namespace std;


class Fruit {
// Put type in class
// if FruitType only used in class 
public:
    enum class FruitType {
        APPLE,
        BANANA,
        WATER_MELON,
        STRAWBERRY,
        KIWI,
    };
    class InnerClass {}; 
    struct InnerStruct {};

private:
    FruitType m_type;

public:
    Fruit(const FruitType &type_in): m_type(type_in){}
    FruitType getType(){ return this->m_type; } 
};

int main(){
    
    {
        Fruit fruit(Fruit::FruitType::APPLE);
        if ( (int)fruit.getType() == 0)
            cout << "Apple " << endl;
    }
    return 0;
}