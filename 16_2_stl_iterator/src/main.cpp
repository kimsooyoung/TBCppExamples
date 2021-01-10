#include <functional>
#include <iterator>
#include <utility>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <iostream>

using namespace std;

int main(){

    cout << "==== iterator example 1 ====" << endl;

    // iterator, basic usage 1
    {
        vector<int> vec;
        vector<int>::const_iterator itr;

        for (auto i = 0; i < 10; i++)
            vec.push_back(i);

        itr = vec.begin();

        while (itr != vec.end()){
            cout << *itr << " ";
            ++itr; // don't forget this !!!
        }
        cout << endl;
    }

    cout << "==== iterator example 2 ====" << endl;

    {
        vector<int> vec;

        for (auto i = 0; i < 10; i++)
            vec.push_back(i);

        for (auto itr = vec.begin(); itr != vec.end(); itr++){
            cout << *itr << " ";
        }
        cout << endl;   
    }

    cout << "==== iterator example 3 list ====" << endl;
    {
        list<int> int_list;

        for (auto i = 0; i < 10; i++)
            int_list.push_back(i);

        for (auto itr = int_list.begin(); itr != int_list.end(); itr++){
            cout << *itr << " ";
        }
        cout << endl;  
    }

    cout << "==== iterator example 3 list ====" << endl;
    {
        list<int> int_list;

        for (auto i = 0; i < 10; i++)
            int_list.push_back(i);

        for (auto itr = int_list.begin(); itr != int_list.end(); itr++){
            cout << *itr << " ";
        }
        cout << endl;  
    }

    cout << "==== iterator example 4 map ====" << endl;
    {
        map<int, char> ic_map;

        for (auto i = 0; i < 10; i++){
            ic_map.insert(make_pair(i, static_cast<char>(i + 65)));
            // ic_map.insert(make_pair<int, char>(i, static_cast<char>(i + 65))); // ERROR => why??
        }

        for (auto itr = ic_map.begin(); itr != ic_map.end(); itr++){
            cout << itr->first << " " << itr->second << " " << endl;
        }        
    }

    return 0;
}