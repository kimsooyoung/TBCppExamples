# 덧셈 연산자 오버로딩하기

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

- 연산자 오버로딩을 구현해보자.

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

이는 +,-,\*,/ 모두 가능하지만 안되는 것들이 있다.

- 삼항연산자 (condition) ? x:y
- sizeof
- :: (범위 연산자)
- 멤버 접근, 멤버 포인터 접근 (. .\*)
- bitwise XOR ^는 우선순위가 낮아서 오버로딩을 비추천

오버로딩된 연산자의 우선순위는 유지됨 (오버로딩 + 보다 오버로딩 \*가 우선)

직관적이지 않는 상황에서는 오버로딩 웬만하면 쓰지 말자.

friend를 떼면서 멤버 함수로 바꾸고자 한다면, 함수의 형태가 바뀌어야 한다.

- 매개변수가 2개 => 1개로 축소
- 피연산자 중 하나는 this로 참조하게 된다.

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

return type으로 output stream이 있기 때문에 << 연쇄가 가능한 것이다.

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

C 언어였다면 fprintf, printf 모두 별도로 해줬어야 했음

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

# 첨자 연산자 오버로딩 하기

[] 이것이 첨자 연산자
indexing을 예외처리해주는 assert를 추천한다.
if는 퍼포먼스가 너무 떨어짐

```
#include <cassert>

int &operator[](const int &index)
{
    assert(index >= 0);
    assert(index <= m_size);

    return m_arr[index];
}
```

const를 사용하고 싶은 경우, const 오버로딩을 사용하면 된다.

```
const int &operator[](const int &index) const
{
    assert(index >= 0);
    assert(index <= m_size);

    cout << "const operator [] runs" << endl;
    return m_arr[index];
}
```

# 괄호 연산자 오버로딩과 함수 객체

괄호 연산자를 사용한다는 것은 곧 클래스를 함수처럼 사용한다는 것이다. (Functor)

```
int operator() (int i){
    m_counter += i;
    return m_counter;
}

main{
    Accumulator acc;

    cout << acc(10) << endl;
    cout << acc(20) << endl;
}
```

클래스를 마치 함수 사용하듯이 하는 것이 특징이다.

# 형변환을 오버로딩 하기

static_cast를 오버로딩하는 방법에 대해 알아보자.

```
class Cents {
  // casting operator overloaded
  operator int() {
    cout << "cast here" << endl;
    return m_val;
  }
};

void parseInt(const int &i) { cout << "Paresed Int : " << i << endl; }

int main(){
  Cents c(10);

  parseInt(c);
}
```

Cents 클래스가 int로 형변환되었다.
참고로 이는 아래 구현과 동일하다.

```
(int) cents;
int(cents);
static_cast<int>(cents);
```

좀 더 실용적인 예시 (달러를 센트로 변환)

```
class Dollar {
private:
  int m_val;

public:
  Dollar(const int &val_in) : m_val(val_in) {}
  operator Cents() { return Cents(m_val * 100); }
};

main(){
  Dollar d(12);
  Cents c = d;

  cout << "Dollar => Cents Casting : " << c << endl;
}
```

===

# 복사 생성자, 복사 초기화 반환값 최적화

자기랑 같은 타입이 들어오는 것이 복사 생성자이다.

```
Fraction(const Fraction &frac)
    : m_numerator(frac.m_numerator), m_denumerator(frac.m_denumerator) {
cout << "Copy Constructor Called" << endl;
}

Fraction frac(1, 3);
cout << frac << endl;
```

이번에는 copy initialization을 해보자.

```
Fraction copy = frac;
```

=> 동일하게 동작한다.

요점은 이렇게 사용하고 싶다면 복사 생성자가 정의되어 있어야 한다는 점

```
Fraction copy(Fraction(1, 3));
```

이때는 복사 생성자가 동작하지 않는다. => 컴파일러가 알아서 최적화함

반환값 최적화

```
Fraction doSomething() {
  Fraction temp(1, 2);
  cout << &temp << endl;
  return temp;
}

Fraction result = doSomething();
```

doSomething의 반환 시 일반적이라면 클래스가 하나 복사되고 리턴될 것이다.
하지만 컴파일 모드를 release로 바꾸면 복사가 동작하지 않는다.

=> 이것이 컴파일러의 반환값 최적화

# 변환 생성자, explicit, delete

converting constructor가 무엇인지 우선 살펴보자.

```
class Fraction {
private:
  int m_numerator;
  int m_denumerator;
  ...
public:
  Fraction(const int &num_in = 0, const int &denum_in = 1)
  ...
};

void printFrac(const Fraction &frac) { cout << frac << endl; }

void main(){
  printFrac(7);
}
```

위같이 하면, 7 => Fraction(7) => printFrac()으로 알아서 변환해주면서 동작한다.
이것이 converting constructor

이때, 생성자에 explicit을 붙이면, 7 => Fraction(7)으로의 변환을 막게 된다.
정확하게 넣어달라는 뜻

- delete 키워드

생성자 호출 시 char가 들어오는 것을 아예 막아버린다.

```
Fraction(char) = delete;
```

# 대입 연산자 오버로딩, 깊은 복사, 얕은 복사

```
MyString hello("hello");

cout << (int *)hello.m_data << endl;
cout << hello.getString() << endl;

{
    MyString copy = hello;
    cout << (int *)copy.m_data << endl;
    cout << copy.getString() << endl;
}
```

MyString copy = hello; 여기에서 일반 복사가 이루어지면서 동적 생성된 배열은 주소값만 복사하게 된다.

때문에 스코프를 벗어나면서 copy가 동적 메모리를 해제해버리고 hello는 쓰레기값을 들고 있게 되는 것

이것이 shallow copy.

이제 deep copy를 살펴보자.

```
void _init(const char *arr_in) {
if (arr_in != nullptr) {
    m_data = new char[m_length];

    for (int i = 0; i < m_length; i++)
    m_data[i] = arr_in[i];
} else
    m_data = nullptr;
}
```

주의사항

```
MyString copy = hello;

MyString copy;
copy = hello;
```

이 둘은 다르다. 윗줄은 copy constructor가 호출되며, 아래는 assignment operator가 실행되는 것이다.

따라서 혼란을 막기 위해 아래와 같이 쓰기를 추천

```
MyString copy(hello); (copy = hello랑 같다.)
```

()를 붙이면 느낌상 constructo를 호출하는 것 같기 때문이다.

deep copy 구현은 못했는데 임시방편으로 막아두고 싶은 경우, 아래와 같이 delete로 막아둘 수 있다.

```
MyString(const MyString &source) = delete;
```

# 이니셜라이져 리스트 initializer list

배열 초기화 시 아래와 같이 직접 원소들을 초기화할 수 있다.

```
int my_arr[5] = {1,2,3,4,5};
int *my_arr_ptr = new int[5]{1,2,3,4,5};
```

auto로 {1,2,3}을 받으면 뭐라고 인식할까? => std::initialize_list<int>

```
#include <initializer_list>

auto li = {1,2,3};
```

우리의 클래스도 이렇게 {}로 초기화하고 싶은 경우를 다룰 것이다.

```
IntArray(const int &size_in) : m_size(size_in) { m_arr = new int[size_in]; }

IntArray(const std::initializer_list<int> &list) : IntArray(list.size()) {
    int count = 0;
    for (auto &elem : list) {
        m_arr[count] = elem;
        count++;
    }
}
```

이때 주의점으로, initializer_list에는 []연산을 쓸 수 없기에 for 문도 사용하지 못한다는 점이 있음.

더불어, initializer_list 생성자를 작성했다면 대입 연산자 = 도 작성하는 것이 좋다.

===

# cin 더 잘 쓰기

cin을 써서 숫자 하나를 받고 싶은데 1 2 이렇게 입력하면 다음 연산에도 영향을 미치게 된다.

cin의 버퍼를 다룸으로 해결할 수 있다.
입력을 하나만 받고픈 경우 버퍼에서 하나만 받고 나머지는 clear

```
std::cin.ignore(32767, '\n');
```

원하는 기호 (+ - / % \*)만 받고 싶은 경우

```c++
if (op == '+' || op == '-' || op == '*' || op == '/')
{
    return op;
}
```

10000000000 같이 엄청나게 큰 수를 입력받는 경우 오류 처리 => cin.fail()

오류가 나면 true를 반환한다.

```
if (std::cin.fail())
{
    std::cin.clear();
    std::cin.ignore(32767, '\n');
    std::cout << "Invalid Number, Try again" << std::endl;
}
```
