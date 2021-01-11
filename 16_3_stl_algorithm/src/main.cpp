#include <algorithm>
#include <iterator>
#include <iostream> 
#include <vector>
#include <list>

using namespace std;

int main(){

    // find min_element, reverse, sort
    {
        vector<int> vec;
        
        for (auto  i = 0; i < 10; i++){
            unsigned int sign = (i % 2 == 0 ? 1:-1);
            vec.push_back(-1 * i * sign);
        }
        
        for (auto &elem : vec)
            cout << elem << " ";
        cout << endl;
        
        
        cout << "==== std::min_element ====" << endl;

        auto itr = min_element(vec.begin(), vec.end());
        cout << *itr << endl;

        cout << "==== str::find ====" << endl;

        int elem = 3;
        itr = find(vec.begin(), vec.end(), elem);
        if (itr != vec.end())
            cout << "elem found in vector : " << elem << endl;
        else
            cout << "elem not found in vector!" << endl;

        cout << "==== str::sort ====" << endl;

        sort(vec.begin(), vec.end());
        for (auto &elem : vec)
            cout << elem << " ";
        cout << endl;

        cout << "==== str::reverse ====" << endl;

        reverse(vec.begin(), vec.end());
        for (auto &elem : vec)
            cout << elem << " ";
        cout << endl;
    }

    cout << endl << "LIST" << endl;

    // std::list already has most algorithms
    {
        list<int> int_list;

        for (auto  i = 0; i < 10; i++){
            unsigned int sign = (i % 2 == 0 ? 1:-1);
            int_list.push_back(-1 * i * sign);
        }
        
        for (auto &elem : int_list)
            cout << elem << " ";
        cout << endl;

        cout << "==== str::sort ====" << endl;
        int_list.sort();
        for (auto &elem : int_list)
            cout << elem << " ";
        cout << endl;

        cout << "==== str::reverse ====" << endl;
        int_list.reverse();
        for (auto &elem : int_list)
            cout << elem << " ";
        cout << endl;
    }

    return 0;
}
