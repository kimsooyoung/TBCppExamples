아래와 같은 Cents라는 클래스가 있다고 해보자.

```
class Cents{
private:
    int m_cents;
public:
...
```

Cents끼리의 덧셈을 구현하고 싶다면 이렇게 사용했었을 것이다.

```
Cents addCents(const Cents &c1, const Cents & c2){
    return Cents( c1.getCents() + c2.getCents() );
}
// or 
int& getCents() const { return m_cents; }

void addCents(const Cents &c1, const Cents & c2, Cents & output){
    output.getCents() = c1.getCents() + c2.getCents();
}
```

+ 연산자 오버로딩을 구현해보자.

```
class Cents{
private:
    int m_cents;
public:
    Cents(const int &cent_in=0): m_cents(cent_in) {}
    int getCents() const { return m_cents; }


    Cents operator + (const Cents &c1, const Cents & c2){
        return Cents( c1.getCents() + c2.getCents() );
    }
};

# 사용
cout << (Cents(1) + Cents(2)).getCents() << endl;
```

operator 함수 내에서 getCents 함수를 안쓸수는 없을까?
=> friend 사용

```
class Cents{
private:
    int m_cents;
public:
    friend Cents operator + (const Cents &c1, const Cents & c2);
...

Cents operator + (const Cents &c1, const Cents & c2){
    return Cents(c1.m_cents + c2.m_cents);
}
```

동일하게 동작한다.

이는 +,-,*,/ 모두 가능하지만 안되는 것들이 있다.

* 삼항연산자 (condition) ? x:y
* sizeof
* :: (범위 연산자)
* 멤버 접근, 멤버 포인터 접근 (. .*)
* bitwise XOR ^는 우선순위가 낮아서 오버로딩을 비추천

오버로딩된 연산자의 우선순위는 유지됨 (오버로딩 + 보다 오버로딩 *가 우선)

직관적이지 않는 상황에서는 오버로딩 웬만하면 쓰지 말자.

friend를 떼면서 멤버 함수로 바꾸고자 한다면, 함수의 형태가 바뀌어야 한다.
* 매개변수가 2개 => 1개로 축소 
* 피연산자 중 하나는 this로 참조하게 된다.

```
Cents operator + (const Cents & c){
    // return Cents( this->getCents() + c.m_cents );
    // or
    return Cents( this->m_cents + c.m_cents );
}
```

멤버 함수로만 해야 하는 연산자들
=, [], (), ->
외우지는 말고 구글링하거나 컴파일 해보면 알 수 있음.


# 입출력 연산자 오버로딩 하기

```
friend std::ostream& operator<<(std::ostream& out, const Point &p_in){
    out << "(" << p_in.m_x << "," << p_in.m_y << "," << p_in.m_z << ")";
    return out;
}

friend std::istream& operator>>(std::istream& in, Point &p_in){
    in >> p_in.m_x >> p_in.m_y >> p_in.m_z;
    return in;
}
```

입출력 연산자는 멤버 함수로 만들 수가 없다. 
첫번째 매개변수가 일반적인 매개변수가 아니라 std::ostream이어서 그렇다.

ostream의 장점, 파일 출력도 가능

파일 입출력은 이렇게 한다.
```
#include <fstream>

ofstream of("output.txt");

// cout을 of로 바꾸기만 하며 된다.
cout << p_1 << p_2 << endl;
of   << p_1 << p_2 << endl;

of.close();
```

# 단항 연산자 오버로딩 하기

-a, !a와 같은 단항 연산자를 오버로딩 하는 방법이다.

```
Cents operator-() const{
    return Cents(-m_val);
}
bool operator!() const{
    return (m_val == 0) ? true : false;
}
```

# 비교 연산자 오버로딩 하기

```
friend bool operator== (const Cents &c1, const Cents &c2){
    return c1.m_val == c2.m_val;
}

friend bool operator!= (const Cents &c1, const Cents &c2){
    return c1.m_val != c2.m_val;
}

friend bool operator< (const Cents &c1, const Cents &c2){
    return c1.m_val < c2.m_val;
}

friend bool operator> (const Cents &c1, const Cents &c2){
    return c1.m_val > c2.m_val;
}
```

# 증감 연산자 오버로딩 하기

전위, 후위에 따라 성질이 달라진다는 것에 유의한다.

```
int a = 1;
// 더해진 다음 출력됨
cout << ++a << endl;
// 출력된 다음 더해짐
cout << a++ << endl;
cout << a << endl;
```

전위형, 자기 자신을 리턴해야 함

```
Digit& operator++(){
    m_digit = (m_digit == 9) ? -1:m_digit; 
    ++m_digit;
    return *this;
}
```

후위형은 일단 현재 값을 리턴해주고 난 뒤 더해줘야 하므로 구현이 좀 다르다.

```
Digit operator++(int){
    m_digit = (m_digit == 9) ? -1:m_digit; 
    Digit temp(m_digit);
    ++m_digit;
    // 앞서 전위형을 만들었으므로 이렇게 할 수도 있다.
    ++(*this);
    
    return temp;
}
```

