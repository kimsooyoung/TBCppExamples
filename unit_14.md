고전적인 예외처리 방법

```
int findFirstChar(const char *string, char ch) {
  for (auto i = 0; i < std::strlen(string); i++)
    if (string[i] == ch)
      return i;

  return -1; // no match
}
```

ㄴ 문제가 있으면 -1을 반환하게 하여 예외상황을 만들어낸다.

```
double devide(const int &x_in, const int &y_in, bool &success) {
  if (y_in == 0) {
    success = false;
    return 0.0;
  }

  success = true;
  return static_cast<double>(x_in) / y_in;
}
```

0으로 나누는 예외가 발생하는 경우를 미리 방지한다.
더불어, 별도의 bool flag를 두어 성공 여부까지 반환하도록 하고 있다.

---

위 방식대로 예외처리를 해도 된다. 이것이 가장 성능이 좋음
지금부터 작업할 try-throw-catch 문법은 매우 다양한 오류가 발생할 수 있는 경우에 주로 사용된다. (게임 서버 등)

기초 문법 (try catch throw)

try : 문제가 생길 여지가 있는 부분을 감싼다.
throw : 특정 조건에 대해 예외를 던진다.
catch : throw된 에러를 받아 처리한다.

```
try {
    if (x < 0.0)
        throw std::string("Negative input");

    std::cout << "You Entered " << x << std::endl;
}
catch (const std::string err_msg) {
    std::cerr << err_msg << '\n';
}
```

주의 사항

throw 타입과 catch 타입을 정확하게 맞춰주어야 한다.

```
try {
    throw -1.0;
}
catch (int x) {
    std::cout << "Err occured with " << x << std::endl;
}
```

ㄴ 이렇게 하면 throw는 float 인데, catch는 int가 되어 런타임 에러가 발생해버린다.

```
try {
    throw "Err Message";
    throw std::string("Err Message");
}
catch (const char *err_message) {
    std::cout << "Err occured with " << err_message << std::endl;
}
catch (std::string err_message) {
    std::cout << "Err occured with " << err_message << std::endl;
}
```

ㄴ string의 경우도 마찬가지이다.

정리

- 고전적 예외처리와 try-throw-catch
- try-throw-catch 사용 시 주의사항

---

예외처리와 스택 되감기

함수가 겹겹이 쌓여있는 상황에서 예외처리가 발생한다면??

```
void last() {
    std::cout << "last" << std::endl;

    throw -1;
}

void third(){
    std::cout << "third" << std::endl;

    try{
        last();
    }
    catch(char){
        std::cerr << "third catch err" << '\n';
    }

    std::cout << "end third" << std::endl;
}

void second(){
    std::cout << "second" << std::endl;

    try{
        third();
    }
    catch(double){
        std::cerr << "second catch err" << '\n';
    }

    std::cout << "end second" << std::endl;
}

void first(){
    std::cout << "first" << std::endl;

    try{
        second();
    }
    catch(int){
        std::cout << "first catch err" << std::endl;
    }
    catch(...){
        std::cerr << "main caught ellipse exception" << std::endl;
    }

    std::cout << "end first" << std::endl;
}

int main() {
    {
        first();
    }
    return 0;
}
```

- cerr가 사용되었는데, 이는 endl나 버퍼 없이도 바로 콘솔에 출력해주는 console channel이다.

ㄴ 위 상황을 살펴보자면, main => first => second => third => last로 이어지면서 스택이 겹겹이 쌓기고, 가장 안쪽인 last에서 예외가 발생하게 된다.

실행 결과는 다음과 같다.

```
first
second
third
last
first catch err
end first
```

throw 된 수가 -1이기 때문에 catch(int)가 있는 first에서 비로소 catch가 된다.
때문에 그 전에 있던 "end third"나 "end second"는 호출되지 않으며, 오로지 "end first"만 호출되는 것임

만약 어디에도 catch(int) 가 없었다면, 런타임 에러가 발생하였을 것이다.

이를 방지하기 위해 나머지 모든 타입을 맡는 ellipsis를 사용할 수 있다.

```
  try {
    second();
  } catch (int) {
    std::cout << "first catch err" << std::endl;
  } catch (...) {
    std::cerr << "main caught ellipse exception" << std::endl;
  }
```

ellipsis 사용법 - https://buildabetterworld.tistory.com/28

exception specifier (잘 사용은 안함)

어떤 함수가 예외를 던지게 될 시, 미리 어떤 타입을 던지는지 명시한다.

```
void last() throw(int) {
  std::cout << "last" << std::endl;

  throw -1;
}
```

만약 throw만 하고 아무것도 안적어주면, 예외를 발생하지 않는다고 간주
따라서 아래 경우는 에러가 발생한다.

```
void last() throw() {
  std::cout << "last" << std::endl;

  throw -1;
}

# Error
test.cpp:6:3: warning: 'last' has a non-throwing exception specification but can still throw [-Wexceptions]
```

---

예외 클래스와 상속

예외를 throw할 시, 기존 자료형이 아닌 클래스를 사용하는 방법을 알아보자.

```
class MyArray {
private:
  int m_arr[5];

public:
  int &operator[](const int &index) {
    if (index < 0 || index >= 5)
      throw -1;

    return m_arr[index];
  }
};

void doSomething() {
  MyArray my_arr;

  try {
    my_arr[100];
  }
  catch (const int &e) {
    std::cerr << "Exception : " << e << std::endl;
  }

  std::cout << "No problem in doSomething" << std::endl;
}
```

ㄴ MyArray의 []operator를 호출하면서 매우 큰 수가 들어가면 -1 예외를 throw 하도록 하고 있다.
ㄴ 클래스 내에서 예외를 던지는 것이라고 보면 된다.

그럼, 예외에 해당하는 나만의 클래스를 만들어보자.

```
class Exception {
private:
  char *err_msg = nullptr;

public:
  void report() {
    std::cerr << "Exception Report!" << std::endl;
  }
};
```

Exception이라는 클래스를 만들었으며, report라는 메소드도 만들어주었다.

예외처리 시 Exception 클래스를 사용해보자.

```
class MyArray {
private:
  int m_arr[5];

public:
  int &operator[](const int &index) {
    if (index < 0 || index >= 5)
      throw Exception();

    return m_arr[index];
  }
};

void doSomething() {
  MyArray my_arr;

  try
    my_arr[100];
  catch (Exception &e)
    e.report();

  std::cout << "No problem in doSomething" << std::endl;
}
```

상속을 사용하는 Exception 클래스

```
class Exception {
private:
  char *err_msg = nullptr;

public:
  void report() {
      std::cout << "Exception Report!" << std::endl;
  }
};

class ArrayException : public Exception {
public:
  void report(){
      std::cout << "ArrayException Report!" << std::endl;
  }
};
```

이번에는 ArrayException을 throw하고 catch 하도록 해보자.
어떤 결과가 나올까?

```
class MyArray {
private:
  int m_arr[5];

public:
  int &operator[](const int &index) {
    if (index < 0 || index >= 5)
      throw ArrayException();

    return m_arr[index];
  }
};

void doSomething() {
  MyArray my_arr;

  try
    my_arr[100];
  catch (Exception &e)
    e.report();

  std::cout << "No problem in doSomething" << std::endl;
}

# 결과
Exception Report!
```

ArrayException이 아닌 부모 클래스의 report가 호출되었다.
=> 이는 다형성으로 해결 가능!

부모 클래스인 Exception의 report 함수를 virtual로 만들어 주면 되는 것이다.

```
class Exception {
private:
  char *err_msg = nullptr;

public:
  virtual void report() { std::cout << "Exception Report!" << std::endl; }
};

class ArrayException : public Exception {
public:
  void report() override { std::cout << "ArrayException Report!" << std::endl; }
};
```

rethrow

catch 문에서 다시 throw를 하는 기법이다.

```
void doSomethingAndThrow() {
  MyArray my_arr;

  try {
    my_arr[100];
  }
  catch (Exception &e) {
    e.report();
    // throw e; => throw Exception
    throw; //  => throw ArrayException
  }

  std::cout << "No problem in doSomething" << std::endl;
}
```

대신 이때 throw e를 하게 되면 catch 부분에서 객체 잘림이 발생하게 되므로, 다형성을 유지하기 위해 단순히 throw; 만 해주게 되면 자식 클래스의 override된 함수를 그대로 사용할 수 있게 된다.

```
try {
    doSomethingAndThrow();
} catch (ArrayException &e) {
    e.report();
} catch (Exception &e) {
    e.report();
}
# 결과
ArrayException Report!
```

std::exception 소개

대부분의 예외 상황들을 모두 다룰 수 있는 범용 클래스인 std::exception class이다.

```
#include <exception>
#include <iostream>

int main() {

  try {
    std::string s;
    // resize to negative number throws length error
    s.resize(-1);
  } catch (const std::exception &e) {
    std::cout << typeid(e).name() << std::endl;
    std::cerr << e.what() << '\n';
  }

  return 0;
}

# 결과
St12length_error
basic_string
```

사용법은 catch(const std::exception &e) 이렇게 해준다.
error 메세지는 e.what() 함수를 통해 얻을 수 있다.

std::exception는 매우 많은 자식 클래스를 가진 부모 클래스이다. https://en.cppreference.com/w/cpp/error/exception

때문에 예제에서는 typeid를 사용하고 있음

throw 시에도 std::exception 계열의 메세지를 던질 수 있다.

```
try {
    throw std::runtime_error("Terrible Error!"):
} catch (const std::exception &e) {
    std::cout << typeid(e).name() << std::endl;
    std::cerr << e.what() << '\n';
}
```

std::exception을 상속받는 custom exception 클래스 사용하기

```
class CustomException : public std::exception {
public:
  // noexcept Guarantees that there won't any exception in this function
  const char *what() const noexcept override { return "Custom Exception"; }
};
```

noexcept란, C++11 이상에서 사용되는 문법으로 적어도 이 함수 안에서는 예외를 던지지 않을 것이라는 걸 명기하는 것이다.

---

함수 try

initialization list에서 발생하는 예외를 처리하는 try 함수이다.

```
class Base {
private:
  int x_;

public:
  Base(const int &x_in) : x_(x_in) {
    if (x_in <= 0)
      throw -1;
  }
};

class Child : public Base {
public:
  Child(const int &x_in) try : Base(x_in) {
  }
};
```

위와 같은 상황을 생각해보자.
Base에서 throw를 하고 있으며, 이것을 main이 아닌 Child의 생성자에서 catch하고자 한다.

이때 function try를 사용할 수 있으며, Child의 생성자 함수 전체를 try로 감싸는 구현이 들어간다.

```
class Base {
private:
  int x_;

public:
  Base(const int &x_in) : x_(x_in) {
    if (x_in <= 0)
      throw -1;
  }
};

class Child : public Base {

public:
  Child(const int &x_in) try : Base(x_in) {
    // Do sth
  } catch (...) {
    std::cerr << "Catch in Child" << std::endl;
  }
};
```

그럼, main문을 작성하고 실행시켜보자.

```
int main() {

  try {
    Child child(-1);

  } catch (const int &x) {
    std::cerr << "Catch in main" << std::endl;
  }

  return 0;
}

# 결과
Catch in Child
Catch in main
```

생성자에서 이미 catch를 했는데, 다시 main에서 catch가 이루어지고 있다. re throw를 하지 않았음에도 말이다.

이것이 생성자에서 throw를 할떄의 주요한 특징이다.

---

예외처리의 위험성과 단점

동적 할당을 사용하는 경우, throw로 넘어오면서 메모리 누수가 발생할 위험이 있다.

```
try{
    int *i_arr = new int [1000];

    // throw before delete => memory leak!!
    throw -1;

    delete[] i_arr;
}
catch(...){
    std::cerr << "Error and Memory Leak!!" << '\n';
}
```

catch문에서는 try문 안의 local variable i_arr에 접근할 방법이 없다.

해결 방법 - 스마트 포인터 사용

```
try{
    int *my_arr = new int [1000];
    // Now, unique_ptr take care of memory collection well.
    std::unique_ptr<int> up_i(my_arr);

    throw std::runtime_error("Error");
}
catch(const std::exception& e){
    std::cerr << e.what() << '\n';
}
```

unique_ptr을 사용하면 throw를 통해 스코프를 벗어나면서 자동으로 메모리가 반환된다.

소멸자에서의 throw는 금지되어있다. - 규칙같은 것임

```
class A {
public:
    ~A(){
        // warning: throw will always call terminate() [-Wterminate]
        // there's nothing to catch this -1
        throw -1;
    }
};
```

퍼포먼스 문제

for 문과 같이 비번하게 실행되는 코드 안에 예외처리를 넣으면 성능이 매우 저하된다.

언제 예외처리를 쓸까?

사용자 입력에 대한 오류의 경우 if를 쓰거나 다시 입력받는 등으로 얼마든지 회피할 수 있다. 이런 경우에는 예외처리를 안써도 됨
분산/병렬처리, 하드웨어 작업, 네트워크 작업 등 논리적으로 대체할 수 없는, 예상할 수 없는 것에 주로 예외처리를 사용한다고 한다.
