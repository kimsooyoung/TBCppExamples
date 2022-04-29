12.3 override, final, 공변 반환값

다형성 사용 시 실수를 방지하기 위해 override, final, virtual 키워드를 잘 사용하는 방법에 대해 배워보자.

```
class A {
public:
    virtual void print(char a) const {
        std::cout << "A" << std::endl;
    }
};

class B : public A {
public:
    void print(int a) const  {
        std::cout << "B" << std::endl;
    }
};
```

class A에서는 매개변수 타입이 char이었는데 class B에서는 int 매개변수를 넣어주었다. 
=> 이렇게 되면 오버라이딩이 아닌, 오버로딩을 구현한 것이 됨

```
A &ref = b;
ref.print(1); 

# 실행 결과
"A"
```

이를 사전에 방지하기 위해 override 키워드를 사용한다.

```
class A {
public:
    virtual void print(char a) const {
        std::cout << "A" << std::endl;
    }
};

class B : public A {
public:
    void print(int a) override const  {
        std::cout << "B" << std::endl;
    }
};
```
=> 이제 컴파일러가 매개변수 타입이 차이난다는 것을 알아채고 빨간줄을 그어준다.

const 있고 없고나 함수 이름이 잘못되는 경우를 방지할 수 있다. 

final 키워드

```
class B : public A {
public:
    virtual void print() const override final {
        std::cout << "B" << std::endl;
    }
};
```

=> 이제 print 함수는 class B에서 마지막! B의 child class가 있다면 print는 override 할 수 없다.

covariant return type

자기 자신을 리턴하는 getThis를 구현한 뒤, Derived class pointer를 사용하도록 캐스팅해보았다.

```
class CovA {
public:
    void print() { std::cout << "CovA" << std::endl; }
    virtual CovA* getThis(){
        std::cout << "CovA* getThis" << std::endl;
        return this;
    }
};

class CovB : public CovA {
public:
    void print() { std::cout << "CovB" << std::endl; }
    virtual CovB* getThis(){
        std::cout << "CovB* getThis" << std::endl;
        return this;
    }
};

CovB b;
CovA &ref_a = b;

b.getThis()->print();
ref_a.getThis()->print();

# 실행 결과
CovB* getThis
CovB
CovB* getThis
CovA
P4CovB
P4CovA
```
=> getThis 자체는 CovB의 것을 받았는데, 실행 결과는 CovA가 나오게 되었다.

getThis가 B의 포인터를 리턴해주어도 A로 변환된 뒤 print가 실행되는 것이다.

최종 정리 

상위 클래스에서는 virtual 사용
하위 클래스에서는 virtual <함수명> override 사용 
필요 시 final 사용

12.4 가상 소멸자

Child class에서 동적 할당이 호출되는 경우

```
class Base {
public:
    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Child : public Base {
private:
    int *m_arr;
public:
    Child(const int &size_in=0){
        m_arr = new int [size_in];
    }
    ~Child(){
        std::cout << "Child Destructor" << std::endl;
        delete[] m_arr;
    }
};

Child child(3);

# 실행 결과
Child Destructor
Base Destructor
```

일반적인 경우, 자식 클래스의 소멸자 => 부모 클래스의 소멸자 순서대로 호출된다. 

다형성을 적용하고 싶은 경우 

```
Child *ptr_c = new Child(5);
Base  *ptr_b = ptr_c;
delete ptr_b;
```

child 타입을 base 타입으로 변환한 후 소멸 시에도 base 타입으로 간주하여 소멸하고자 하는 것임

이를 위해서 base 클래스의 소멸자를 virtual로 할 수 있다.
child에서도 virtual / override 키워드 붙이는 습관 잊지 말자.

```
class Base {
public:
    virtual ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Child : public Base {
    virtual ~Child() override{
        std::cout << "Child Destructor" << std::endl;
        delete[] m_arr;
    }
};
```

12.5 동적 바인딩과 정적 바인딩


static binding

이미 선언되어 있는 함수들을 상황에 맞게 실행

```
namespace Calc {
    float add(const int &x_in, const int &y_in){
    float sub(const int &x_in, const int &y_in){
    float mul(const int &x_in, const int &y_in){
    float div(const int &x_in, const int &y_in){
}

switch (op)
{
case 0: result = Calc::add(x,y); break;
case 1: result = Calc::sub(x,y); break;
case 2: result = Calc::mul(x,y); break;
case 3: result = Calc::div(x,y); break;
default: break;
}
```

dynamic binding

어떤 함수를 직접 실행시키지 않고, functor에 저장된 주소를 보고 그 주소를 찾아가서 해당 함수를 실행

```
float (*ptr_func)(const int&, const int&) = nullptr;

switch (op)
{
case 0: ptr_func = Calc::add; break;
case 1: ptr_func = Calc::sub; break;
case 2: ptr_func = Calc::mul; break;
case 3: ptr_func = Calc::div; break;
default: break;
}
```

* static binding vs dynamic binding

static binding이 빠르기는 더 빠르다. 미리 정의되어 있는 것을 바로 쓰니까

대신, dynamic binding이 더 유연한 프로그래밍이 가능하다.

다형성의 virtual 함수는 dynamic binding에 해당된다.

12.6 가상 (함수) 표

다형성으로 함수 사용 시 표를 만들어 사용하게 된다.

*_vptr : virtual function table pointer

func1, func2가 필요해지면, 바로 호출하지 않고 일단 table을 보고 나서 해당 테이블이 가리키는 함수를 찾아 호출하게 된다.

Base 클래스의 경우 무조건 자신의 func1, func2가 되므로 테이블을 거쳐 다시 돌아오는 구조를 갖는다.

Child 클래스의 경우 조금 다른데, child 클래스 또한 자신의 table을 갖고 있으며, func1의 경우 child가 갖고 있어 문제는 없지만 func2의 경우 다시 Base class로 거슬러 올라가서 func2를 실행하게 된다.

이 table이 있어서 자식 클래스 객체를 부모 클래스 타입에 넣어도 다형성이 보장될 수 있었던 것임

따라서 virtual 함수가 하나라도 생기면 table pointer 만큼 메모리를 더 차지하기 떄문에 크기가 더 커진다.

```
cout << "sizeof(Base) : " << sizeof(Base) << endl;
cout << "sizeof(Child) : " << sizeof(Child) << endl;
cout << "sizeof(VirtualBase) : " << sizeof(VirtualBase) << endl;
cout << "sizeof(VirtualChild) : " << sizeof(VirtualChild) << endl;

# 실행 결과
sizeof(Base) : 1
sizeof(Child) : 1
sizeof(VirtualBase) : 8
sizeof(VirtualChild) : 8
```

12.7 순수 가상 함수, 추상 기본 클래스, 인터페이스 클래스

설계 측면에서 부모 클래스가 자식 클래스의 형태를 제한할 수 있도록 하는 방법을 알아보자.

순수 가상 함수 
추상 클래스 : 순수 가상 함수가 포함된 클래스
인터페이스 클래스 : 순수 가상 함수로만 이루어진 클래스 

순수 가상 함수 : body가 없고, 선언만 있다.

```
class Animal {
private:
    std::string m_name;
public:
    Animal(const std::string &name_in="Animal"): m_name(name_in) {}
    virtual void speak() const = 0;
};

Animal ani;
```

pure virtual function이 하나라도 있는 클래스는 abstract class가 되며, 이러한 경우 단독으로 사용할 수 없게 된다.

그리고 이렇게 되면, Animal의 child class는 적어도 반드시 이 speak 함수는 구현을 해야 한다.

```
class Cow : Animal {
public:
    // 이 부분을 주석하면 
    // virtual void speak() const override {
    //     std::cout << "Moo" << std::endl;
    // }
};

Cow cow("Moo"); // => 컴파일 불가
```

인터페이스 클래스

내부에 포함된 함수가 모두 pure virtual 함수인 경우
인터페이스 클래스는 이름이 I로 시작하는 관습이 있다.

인터페이스 클래스와 다형성을 사용하는 예시

```
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

void doSth(IErrorLog &log){
    log.reportError("Error!!");
}

FileErrorLog f_err;
ConsoleErrorLog c_err;

doSth(f_err);
doSth(c_err);

# 실행 결과
File Error
Console Error
```


doSth에서는 IErrorLog 타입을 받도록 되어 있다. 
이 레퍼런스가 전달되면서 FileErrorLog, ConsoleErrorLog 타입의 두 클래스가 IErrorLog으로 캐스팅되지만 virtual table에 의해 다형성을 보존할 수 있는 것임

12.8 가상 기본 클래스와 다이아몬드 상속 문제

다이아몬드 상속 문제를 해결할 수 있는 가상 기본 클래스

```
class PoweredDevice {
public:
    int m_i;
    PoweredDevice(const int i_in=0): m_i(i_in) {}
};

class Scanner : public PoweredDevice {
public:
    Scanner(const int &scanner, const int &i_in): PoweredDevice(i_in){
        cout << "Scanner : " << scanner << endl;
    }
};

class Printer : public PoweredDevice {
public:
    Printer(const int &printer, const int &i_in): PoweredDevice(i_in){
        cout << "Printer : " << printer << endl;
    }
};

class Copier  : public Scanner, public Printer {
public:
    Copier(const int &scanner, const int &printer, const int &i_in): Scanner(scanner, i_in), Printer(printer, i_in){
        cout << "Copier" << endl;
    }
};

Copier copy(1,2,3);

cout << &copy.Scanner::PoweredDevice::m_i << endl;
cout << &copy.Printer::PoweredDevice::m_i << endl;
```

우선 다음과 같은 에러와 함께 컴파일이 되지 않는다.
error: ‘PoweredDevice’ is an ambiguous base of ‘Copier’

이제, Scanner와 Printer를 가상 기본 클래스로 변경해주자.

```
class Scanner : virtual public PoweredDevice {
public:
    Scanner(const int &scanner, const int &i_in): PoweredDevice(i_in){
        cout << "Scanner : " << scanner << endl;
    }
};

class Printer : virtual public PoweredDevice {
public:
    Printer(const int &printer, const int &i_in): PoweredDevice(i_in){
        cout << "Printer : " << printer << endl;
    }
};

cout << &copy.Scanner::PoweredDevice::m_i << endl;
cout << &copy.Printer::PoweredDevice::m_i << endl;

# 실행 결과
PoweredDevice
Scanner : 1
Printer : 2
Copier
0x7ffc4fbfdbf0
0x7ffc4fbfdbf0
```

두 m_i가 같은 주소를 가리키고 있다.

12.9 객체 잘림과 reference wrapper

보통 자식 클래스가 더 많은 정보를 갖게 된다.
따라서 부모 클래스로 캐스팅하면 정보가 잘리는데 이것이 객체 잘림.

이것을 방지할 수 있는 reference wrapper도 알아보자.

기본적인 Derived, Base class들을 만들어 두고 다형성을 체크해보자.

```
    Derived d;
    // Base &b = d;
    Base b = d;
```
=> 여기에서 Base &b = d가 아닌 Base b = d를 하게 되면 다형성도 깨지고 단순 대입이 되어 버린다. (객체 잘림)

=> 함수 인자로 넘길 때도 레퍼런스 안써주면 같은 문제가 발생함

=> 상황에 따라 일부러 객체 잘림을 구현할 때가 있는데 실수를 방지하기 위해 혹시나 의도했다면 꼭 주석을 달아주자. 

* 많이 하는 실수 예시

```
vector<Base> b_vec; 

b_vec.push_back(Derived());
b_vec.push_back(Base());
b_vec.push_back(Derived());

for (auto &elem : b_vec)
    elem.print();
```

=> vector<Base> b_vec로 선언해서 객체 잘림이 발생했다.

그럼 레퍼런스 vector를 쓸까? 

```
vector<Base&> b_vec; 
```
=> 이건 컴파일이 안됨, vector에는 레퍼런스를 넣을 수 없다.

포인터로 쓰면 해결

```
vector<Base*> b_vec; 

b_vec.push_back(&Derived());
b_vec.push_back(&Base());
b_vec.push_back(&Derived());

for (auto &elem : b_vec)
    elem->print();
```

반드시 레퍼런스로 쓰고 싶은 경우 => reference_wrapper

```
#include <functional>

vector<reference_wrapper<Base>> b_vec; 

Derived d;
Base    b;
Derived d2;

b_vec.push_back(d);
b_vec.push_back(b);
b_vec.push_back(d2);

for (auto &elem : b_vec)
    elem.get().print();
```

선언 시 reference_wrapper를 사용하고 사용 시 get()을 명기한다.

12.10 동적 형변환

자식 클래스 => 부모 클래스 => 다시 자식 클래스
(함수 인자로 넘어간 상황에서 다시 자식 클래스 타입으로 바꾸고 싶은 경우 사용될 수 있다.)

이렇게 형변환을 할 수 있을까?

```
Derived1 d_1;
Base *b = &d_1; // 이 상태에서는 Base 클래스 인스턴스만 접근 가능

auto d_to_b = dynamic_cast<Derived1*>(b); // 이제 Derived 클래스 인스턴스도 접근 가능!!
```

```
Derived1 d_1;
Base *b = &d_1;

d_1.m_d = 1111;

auto d_to_b = dynamic_cast<Derived1*>(b);

cout << d_to_b.m_d << endl; 
```
=> 1111로 바뀐다. (포인터니까)

반대의 경우도 마찬가지

```
Derived1 d_1;
Base *b = &d_1;

auto d_to_b = dynamic_cast<Derived1*>(b);
d_to_b.m_d = 1111;

cout << d_1.m_d << endl; 
```

주의해야 할 점들

현재의 상속 구조는 아래와 같다.

Base => Derived1
     => Derived2

이때, Derived1 => Base => Derived2 이렇게는 캐스팅이 안됨

```
Derived1 d_1;
Base *b = &d_1;

auto d_to_b = dynamic_cast<Derived1*>(b);
```
=> dynamic_cast는 캐스팅에 실패하면 nullptr을 반환한다.

따라서 아래와 같은 처리를 추가할 수 있을 것임

```
Derived2 d_1;
Base *b = &d_1;

auto d_to_b = dynamic_cast<Derived2*>(b);

// So handle exception like this
if (d_to_b != nullptr)
    d_to_b->print();
else
    cout << "Dynamic Cast Failed" << endl;
```

static_cast를 쓰면 어떻게 될까? 

강제로 되긴 하지만, Derived2에만 존재하는 인스턴스에 접근하는 순간 런타임 에러가 발생할 것임

이런 이유로 실제로는 dynamic_cast보다는 funcional을 더 많이 사용한다고 한다.

12.11 유도 클래스에서 출력 연산자 사용하기

출력 연산자는 오버라이딩이 불가하다.

operator<<는 std::ostream을 매개변수로 갖기 때문에 클래스 메소드가 될 수 없고 따라서 friend로서 사용하였다.

때문에 가장 상위 클래스에서만 operator<<를 구현해 두고, 실제로 하는 일들은 print라는 별도 함수에게 위임을 하자.

```
friend std::ostream& operator<<(std::ostream& out, const Base &b_in){
    return b_in.print(out);
}
```

print 함수 자체는 얼마든지 overriding이 가능하기 때문에 이것을 virtual 함수도 둘 것이다.

```
virtual std::ostream& print(std::ostream& out) const {
    out << "Base";
    return out;
}
...
class Derived : public Base {
public:
    virtual std::ostream& print(std::ostream& out) const override {
        out << "Derived";
        return out;
    }
};

Base b;
Derived d;

Base &ref_base = d;

cout << b << endl;
cout << ref_base << endl;

# 실행 결과
Base
Derived
```

operator<<자체는 Base의 것이 호출되고 <<에서 print시에 Derived 클래스의 것이 호출되는 것이다.

이러한 구현은, 단순 operator<<에만 쓰이는 것이 아니라 virtual 함수 여러개를 조합하는 방식으로 코딩 자체가 많이 된다.

