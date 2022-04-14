게임 내의 몬스터를 구현하고 싶다고 해보자. 

다음과 같은 속성을 갖는다.

* 이름
* 위치

```
class Monster{
private:
    std::string m_name;
    
    int pos_x;
    int pos_y;
...
```

몬스터를 특정 위치로 움직이게 해보자.

```
void moveTo(const int &x_in, const int &y_in){
    pos_x = x_in;
    pos_y = y_in;
}
```

<< 연산자를 오버로딩 시켜보자. 

```
friend std::ostream& std::operator<< (std::ostream& out, const Monster& mon_in){
    out << mon_in.m_name << " " << mon_in.pos_x << " " << mon_in.pos_y << std::endl;
    return out;
}
```

pos_x와 pos_y는 항상 묶어서 다닌다.
std::string이 char* data와 int length가 묶여다니는 것과 같이 말이다.

이들을 묶어서 새로운 클래스로 만들어주고자 한다.

```
class Position2D{
private:
    int m_x;
    int m_y;
```

생성자와 setter, << 연산자를 오버로딩 하였다. 

```
public:
    Position2D(const int &x_in = 0, const int &y_in = 0): m_x(x_in), m_y(y_in){}
    void moveTo(const int &x_in, const int &y_in){
        m_x = x_in;
        m_y = y_in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Position2D &pos_in){
        out << "( " << pos_in.m_x << " , " << pos_in.m_y << " )";
        return out;
    }
```

이제 Monster 단에서는 위치를 나타내고자 할 시 Position2D 클래스 인스턴스를 사용한다. 

현재 위치, 목표 위치, 홈 위치 등을 나타낼 수 있을 것이다.

```
class Monster{
private:
    std::string m_name;
    Position2D pos_2D;
```

팁! 오버로딩 시 위임시키기

기존 moveTo 함수와 더불어 Position2D를 받는 moveTo를 구현하고 싶었다.

```
void moveTo(const int &x_in, const int &y_in){
    pos_2D.moveTo(x_in, y_in);
}

void moveTo(const Position2D& pos_in){
    pos_2D.moveTo(pos_in);
}
```

이에 따라 Position2D에서도 다양한 입력을 받는 moveTo 함수를 구현하고 싶어짐

기존 moveTo 함수를 최대한 재사용하도록 해둔다.
이렇게 해야 로직이 변경될 시 고쳐야 할 부분이 적어진다.

```
void moveTo(const Position2D& pos_in){
    moveTo(pos_in.m_x, pos_in.m_y); // 재사용
}

void moveTo(const int &x_in, const int &y_in){
    m_x = x_in;
    m_y = y_in;
}
```

ostream 부분을 오버로딩을 해줘보자.

```
// Position2D 파트
friend std::ostream& operator<<(std::ostream& out, const Position2D &pos_in){
    out << "( " << pos_in.m_x << " , " << pos_in.m_y << " )";
    return out;
}

// Monster 파트
friend std::ostream& operator<< (std::ostream& out, const Monster &mon_in){
    out << mon_in.m_name << " " << mon_in.pos_2D;
    return out;
}
```

Position2D에서 오버로딩 해두었기 때문에 Monster에서 손쉽게 호출할 수 있게 된 것이다.

= 연산자도 오버로딩을 해줘보자.

```
// Position2D 파트
Position2D& operator= (const Position2D& m_in){
    m_x = m_in.m_x;
    m_y = m_in.m_y;

    return *this;
}

// Monster 파트
Monster& operator= (const Monster& m_in){
    m_name = m_in.m_name;
    pos_2D = m_in.pos_2D;

    return *this;
}
```

여기서 주의해야 할 점으로 복사 시 동적 생성된 무언가가 있다면 얕은 복사가 발생한다는 점에 유의한다.

```
Monster mon1("Groot", 1, 2);
mon1.moveTo(10,10);

Monster mon2("Dracula");

Monster mon3 = mon1;

std::cout << mon1 << std::endl;
std::cout << mon2 << std::endl;
std::cout << mon3 << std::endl;

# 결과
Groot ( 10 , 10 )
Dracula ( 0 , 0 )
Groot ( 10 , 10 )
```

현재 Monster와 Position2D 사이의 관계(composition)를 살펴보자.

* Monster가 사라지면 Position2D도 사라짐
* Position2D는 Monster에 대해 일절 알지 못함

조금만 복잡해져도 sub-class를 만드는 것을 추천함
결국 어떻게 설계해야 할지 많이 해봐야 함

# 집합 관계

교사와 학생이 존재하는 "수업"을 클래스로 구현하고 싶다고 해보자.
main문은 아래와 같을 것이다.

```
Teacher hong   = Teacher("Prof, Hong");
Teacher good   = Teacher("Prof, Good");

Student jj     = Student("Jack Jack", 0);
Student dash   = Student("Dash", 1);
Student violet = Student("Violet", 1);

Lecture lec1("Introduction to Computer Programming");
lec1.assignTeacher(hong);

lec1.registerStudent(jj);
lec1.registerStudent(dash);
lec1.registerStudent(violet);

Lecture lec2("Computational Thinking");
lec2.assignTeacher(good);

lec2.registerStudent(jj);
```

수업을 듣게 되면 지능 지수가 1씩 오르게 하고 싶었다.
lec1의 jj와 lec2의 jj를 동기화시키고 싶은데 지금은 둘이 별개로 움직인다.

```
Student jj     = Student("Jack Jack", 0);

lec1.registerStudent(jj);
lec2.registerStudent(jj);

// test
{  
    std::cout << lec1 << std::endl;
    std::cout << lec2 << std::endl;

    lec2.study();
    std::cout << "======== study ========" << std::endl;

    std::cout << lec1 << std::endl;
    std::cout << lec2 << std::endl;
}
```

lec1과 lec2에 같은 jj를 register 했는데 왜 이럴까?
=> registerStudent 당시 push_back하면 복사된 클래스가 vector안에 들어간다.
```
void registerStudent(const Student& student_in) {
    m_students.push_back(student_in);
}
```

이것을 어떻게 해결할 수 있을까? => 주소를 가져오도록 수정 (포인터 사용)

```
Teacher* m_teacher;
std::vector<Student *> m_students;

lec1.assignTeacher(&hong);

lec1.registerStudent(&jj);
lec1.registerStudent(&dash);
lec1.registerStudent(&violet);
```

포인터를 가져오기 때문에 lecture 자체가 소멸되어도 그 안의 teacher와 student들은 그대로 보존된다.

지금까지는 main에서 인스턴스를 생성하였기에 main이 끝나면 모든 인스턴스가 사라지는 상황이었다.

main말고 다른 곳에서도 hong, jj, dash등을 사용하기 위해서 동적 할당을 사용할 수 있다. 

```
Teacher *hong   = new Teacher("Prof, Hong");
Teacher *good   = new Teacher("Prof, Good");

Student *jj     = new Student("Jack Jack", 0);
Student *dash   = new Student("Dash", 1);
Student *violet = new Student("Violet", 1);

Lecture lec1("Introduction to Computer Programming");
lec1.assignTeacher(hong);

lec1.registerStudent(jj);
lec1.registerStudent(dash);
lec1.registerStudent(violet);
```

저자는 개인적으로 그냥 변수로 많이 쓴다고 함 
변수 이름에 포인터임을 알리기 위해서 ptr을 붙여주기도 함

# 제휴 관계

앞선 것들은 주/부 관계가 명확하게 있는 반면 그렇지 않은 제휴 관계를 살펴보자.

