#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

class Object {
public:
    void hello(const string &greet_msg){
        cout << greet_msg << endl;
    }
};

void goodbye(const string &bye_msg){
    cout << bye_msg << endl;
}

int main(){

    // Modern C++, Lambda function
    {
        auto printFunc = [](const string &str_in) -> void {
            cout << str_in << endl;
        };

        printFunc("Yellow Horld");

        [](const int &i) -> void { cout << i * 111111 << endl; }(4);
    }

    // lambda function with reference
    {
        string name = "Mrs. Puff";
        [&]() -> void { cout << name << endl; } ();
        // reference for specific variable
        [&name]() -> void { cout << name << endl; } ();
        // copy
        [=]() -> void { cout << name << endl; } ();
        // for Class
        // [this]() -> void { cout << name << endl; } ();
    }

    // for_each with lambda
    {
        vector<int> vec = {1,2,3,4,5}; 

        // auto printFunc = [](const int &val){ cout << val << endl; };
        // for_each(vec.begin(), vec.end(), printFunc);
        
        // same with above but more prefered.
        for_each(vec.begin(), vec.end(), [](const int &val){ cout << val << " ";} );
        cout << endl;

        // lambda function - return 
        {
            cout << []() -> int { return 1; } () << endl;
        }
    }

    // functional and bind
    {
        auto func2 = [](const int &val) -> void{ cout << val << endl; };
        std::function<void(int)> func3 = func2;
        func3(123);

        // functoinal with two arguments
        auto two_arg_func = [&](const string &name, const int &age) -> void { 
            std::cout << "name : " << name <<
                " age : " << age << std::endl;
        };
        std::function<void(string, int)> two_arg_functor = two_arg_func;
        two_arg_func("Kim", 27);

        std::function<void()> func4 = std::bind(func3, 456);
        std::function<void()> func5 = std::bind(func2, 789);
        // std::function with std::bind
        std::function<void(int)> func6 = std::bind(func2, std::placeholders::_1);


        func4();
        func5();
        func6(100100);
    }

    // std::bind and placeholder
    {
        Object instance;

        auto hello_bind = std::bind(&Object::hello, &instance, std::placeholders::_1);
        hello_bind(string("Workout"));

        std::cout << typeid(hello_bind).name() << std::endl;
        
        auto goodbye_bind = std::bind(&goodbye, std::placeholders::_1);
        goodbye_bind(string("Workout Workout"));
    }

    return 0;
}