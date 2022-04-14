# 상속의 기본

```
class Mother{
  ...
}

class Child : public Mother {
  ...
}
```

부모 클래스를 generalized class, 자식 클래스를 derived class라고 부르기도 한다.

부모 클래스의 private 멤버 변수, 함수는 자식 클래스에서 접근할 수 없다.

```
class Mother {
private:
  int m_i; // => Child에서는 접근 불가
  ...
}

class Child : public Mother {
private:
  double m_d;
```

=> protected를 쓰면 된다.

```
class Mother {
protected:
  int m_i; // => Child에서는 접근 불가
  ...
}

class Child : public Mother {
private:
  double m_d;
```

혹은 Mother 클래스에서 getter를 별도로 만들면 된다.
그런데 이름이 setValue 겹치면 곤란하니까 namespac를 지정함으로 수정할 수 있다.

```
void setVal(const int &i_in, const double &d_in) {
  Mother::setVal(i_in);
  m_d = d_in;
}
```

자식 클래스의 생성자를 만들어주자.

```
class Mother {
private:
  int m_i;
  ...
}

Child(const int &i_in = 0, const double &d_in = 0.0)
    : m_d(d_in), m_i(i_in) {} // Error
```

Child 클래스의 생성자에서는 죽어도 부모 클래스의 멤버 변수에 접근이 불가하다.
이는 생성자의 메커니즘과 관련이 깊은데, 생성자는 메모리 할당 시 동시에 값이 들어가는 것이지 미리 변수 생성하고 그 안에 집어넣는 것이 아니기 때문

따라서 부모 클래스의 생성자를 만들고, 자식 클래스에서는 부모 클래스의 생성자를 호출하도록 구현한다.

```
Child(const int &i_in = 0, const double &d_in = 0.0)
    : m_d(d_in), Mother(i_in) {}
```

# 상속의 기본 2

실례를 통해 상속에 대해 체험해보자.
