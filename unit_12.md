12 가상 함수들

12.1 다형성의 기본 개념

간단하게, 동물들을 표현하는 클래스들을 만들었다.

```
class Animal {
  ...
public:
  Animal(const string &name_in = "Animal") : m_name(name_in) {}
  void speak() const { cout << "???" << endl; }
};

class Cat : public Animal {
public:
  void speak() const { cout << "Meow" << endl; }
};

class Dog : public Animal {
public:
  void speak() const { cout << "Woof" << endl; }
};
```

```
Animal ani;
Cat cat("Cat0");
Dog dog("Dog0");

ani.speak();
cat.speak();
dog.speak();

# 실행 결과
???
Meow
Woof
```

이번에는 포인터를 사용해서 dog와 cat을 부모 클래스인 Animal로 캐스팅해보자.

```
Animal *ptr_ani = &cat;
ptr_ani->speak();

ptr_ani = &dog;
ptr_ani->speak();

# 실행 결과
???
???
```

자식 클래스가 마치 부모 클래스인 것처럼 동작하고 있다.

이것을 해결하기 위해서는 Animal의 speak 선언 앞에 virtual 키워드를 사용하면 된다.

```
  void speak() const { cout << "???" << endl; }

# 다시 실행시키면?
Meow
Woof
```

부모 클래스 포인터로 옮겨담아도 자식 클래스의 오버라이딩 된 함수가 동작한 것이다.

이 성질은 다음과 같이 활용 가능하다.

```
Animal *animals[] = {&cats[0], &cats[1], &cats[2], &cats[3],
                        &cats[4], &dogs[0], &dogs[1]};

// Let's type virtual in front of
// speak() function in Animal class
for (auto &ani : animals)
    ani->speak();

# 실행 결과
Meow
Meow
Meow
Meow
Meow
Woof
Woof
```

부모 클래스인 Animal 타입으로 모두 묶어버린 뒤, 한번에 반복 실행시키고 있다.

12.2 가상 함수와 다형성
