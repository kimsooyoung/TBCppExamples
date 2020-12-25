#include <iostream>
#include <vector>

using namespace std;

void printStack(const vector<int> &stack) {
    for (auto &i : stack)
        cout << i << " ";
    cout << endl;
}

int main(){

    // resize to larger vector
    {
        std::vector<int> vec {1,2,3,4,5};

        vec.resize(10);

        
        for (auto &&i : vec)
            cout << i << " ";
        cout << endl;
        
        cout << "size : " <<  vec.size() << " capa : " << vec.capacity() << endl;
    }

    // resize to shorter vector
    {
        std::vector<int> vec {1,2,3,4,5};

        vec.resize(2);
        cout << endl << "resize to 2" << endl;

        for (auto &&i : vec)
            cout << i << " ";
        cout << endl;
        
        cout << "size : " <<  vec.size() << " capa : " << vec.capacity() << endl;
        
        // Runtime Error : 'std::out_of_range'
        // cout << "vec[4] : " << vec[4] << 
        //     " vec.at(4) : " <<  vec.at(4) << endl;

        // Let's force it out
        int *ptr_i = vec.data();

        cout << "ptr_i[4] : " << ptr_i[4] << endl;

    }

    // reserve
    {
        cout << "====  reserve ====" << endl;
        std::vector<int> vec {1,2,3,4,5};

        vec.reserve(10);
        
        for (auto &&i : vec)
            cout << i << " ";
        cout << endl;
        
        cout << "size : " <<  vec.size() << " capa : " << vec.capacity() << endl;
    }

    // Use vector like Stack
    {
        std::vector<int> stack;

        stack.reserve(10);
        
        stack.push_back(0);
        printStack(stack);
        stack.push_back(1);
        printStack(stack);
        stack.push_back(2);
        printStack(stack);
        stack.push_back(3);
        printStack(stack);

        stack.pop_back();
        printStack(stack);
        stack.pop_back();
        printStack(stack);
        stack.pop_back();
        printStack(stack);
        stack.push_back(50);
        printStack(stack);
    }

    return 0;
}