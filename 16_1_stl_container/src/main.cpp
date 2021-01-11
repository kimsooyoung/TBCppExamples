#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>

#include "Person.h"

using namespace std;

void sequence_container(){ 

    cout << "==== vector exameple ====" << endl;
    // vector 
    {
        vector<int> vec;
        
        for (auto i = 0; i < 10; i++)
            vec.push_back(i);
        
        for (auto &elem  : vec)
            cout << elem << " ";
        
        cout << endl;
    }

    cout << "==== deque exameple ====" << endl;

    // deque
    {
        deque<int> deq;

        for (auto i = 0; i < 10; i++){
            deq.push_back(i);
            // deque allows push_front
            // time of push_front and push_back of deque is similar.
            // other than vector ...
            deq.push_front(i);
        }
        
        for (auto &elem : deq)
            cout << elem << " ";
        cout << endl;
    }
}

void associative_container(){
    

    cout << "==== set  exameple ====" << endl;

    // set
    {
        set<string> str_set;

        // set container prevent same value insert
        str_set.insert("Hello");
        str_set.insert("World");
        str_set.insert("Hello");

        for (auto &elem : str_set){
            cout << elem << endl;
        }   
    }

    cout << "==== multi set exameple ====" << endl;

    // multiset : duplication is allowed
    {
        multiset<string> str_mul_set; 


        // multiset sort elements with insertion
        str_mul_set.insert("Hello");
        str_mul_set.insert("World");
        str_mul_set.insert("Hello");

        for (auto &elem : str_mul_set)
            cout << elem << endl;
            
    }

    cout << "==== map exameple ====" << endl;

    // map
    {
        map<string, int> map;

        // map automatically sort elements during insertion
        map["c"] = 300;
        map["a"] = 100;
        map["b"] = 200;
        map["a"] = 100;

        for (auto &elem : map)
            cout << elem.first  <<  " " << elem.second << endl;
    }

    cout << "==== multi map exameple ====" << endl;

    // multimap
    {
        multimap<string, int> mul_map;

        mul_map.insert(make_pair<string, int >("a", 100));
        mul_map.insert(make_pair("c", 300));
        mul_map.insert(make_pair("b", 200));
        mul_map.insert(make_pair("c", 300));

        const string my_str = "a";
        cout << "number of " << my_str << " " << mul_map.count(my_str) << endl;

        for (auto &elem : mul_map){
            cout << elem.first << " " << elem.second << endl;
        }
    }
}

void container_adaptor(){

    cout << "==== stack exameple ====" << endl;

    // stack
    {
        stack<int> my_stack;
        my_stack.push(1);
        my_stack.emplace(2);
        my_stack.emplace(3);

        // cannot use for-loop for stack
        // for (auto &elem : stack)
        // {
        //     cout << elem <<  " ";
        // }

        cout << "top val : " <<  my_stack.top() << endl;
        my_stack.pop();
        cout << "top val : " <<  my_stack.top() << endl;        


        // stack with user-defined type
        stack<Person> person_stack;

        Person kim = Person("Kim", 24);
        Person ko  = Person("Ko", 26);

        // difference between stack.push() and stdack.emplace()
        person_stack.push(kim);
        person_stack.emplace(ko);

        cout << "  " << endl;
    }

    cout << "==== queue exameple ====" << endl;

    // queue
    {
        queue<int> q;

        for (const int i : { 3, 4, 6, 2, 5, 8, 0, 4, 9 } )
            q.push(i);
        
        // Fist in First out
        cout << "front : " << q.front() << " / " << "back : " << q.back() << endl;
        
        for (auto i = 0; i < 9; i++){
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;   
    }

    cout << "==== priority queue exameple ====" << endl;

    // priority queue
    {
        priority_queue<int> prior_q;

        for (const int i : { 3, 4, 6, 2, 5, 8, 0, 4, 9 } )
            prior_q.push(i);

        // priority queue automatically sort elements
        // But, if you wanna push user-defined type
        // you must implement operator overloadings.

        for (auto i = 0; i < 9; i++){
            cout << prior_q.top() << " ";
            prior_q.pop();
        }
        cout << endl;
    }

    cout << "==== priority queue with user-defined type ====" << endl;

    {
        priority_queue<Person> person_pq;
        person_pq.push(Person("Kim", 25));
        person_pq.push(Person("Hwang", 56));
        person_pq.push(Person("Pig", 24));
        person_pq.push(Person("Kim", 54));

        for (auto i = 0; i < 4; i++)
        {
            cout << person_pq.top() << " ";
            person_pq.pop();
        }
    }
}


int main() { 
    
    // There are three main types of containers.
    {
        sequence_container();
        associative_container();
        container_adaptor();

        // this time, 
    }


    return 0;
}