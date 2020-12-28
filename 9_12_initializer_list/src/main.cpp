#include <iostream> 
#include <initializer_list>

using namespace std;

class IntArray{ 
private:
    int m_size;
    int *m_arr;
public:
    IntArray() {
        m_size = 1;
        m_arr = new int [m_size];
    }

    IntArray(const int& size_in): m_size(size_in) {
        m_arr = new int [size_in];
    }

    IntArray(const IntArray &int_arr){
        m_size = int_arr.m_size;

        if(int_arr.m_arr != nullptr){
            m_arr = new int [m_size];

            for(int i = 0; i < m_size; i++)
                m_arr[i] = int_arr.m_arr[i];
        }
        else
            m_arr = nullptr;
    }
    
    IntArray(const std::initializer_list<int> &list):IntArray(list.size()){
        int count = 0;
        for (auto &elem : list){
            m_arr[count] = elem;
            count++;
        }
    }
    
    ~IntArray(){ delete[] m_arr; }

    friend std::ostream& operator<< (std::ostream& out, const IntArray &int_arr){
        for (auto i = 0; i < int_arr.m_size; i++)
            out << int_arr.m_arr[i] << " ";
        return out;
    }
    
    IntArray& operator= (const IntArray &arr_in){

        if(this == &arr_in)
            return *this;

        delete[] m_arr;
        
        m_size = arr_in.m_size;

        if (arr_in.m_arr != nullptr){
            m_arr = new int [arr_in.m_size];

            for (auto i = 0; i < arr_in.m_size; i++)
                m_arr[i] = arr_in.m_arr[i];
        }
        else
            m_arr = nullptr;

        return *this;
    }
};

int main(){

    // initializer list - basic usage 
    {
        int my_arr[5] = {1,2,3,4,5};

        // type of li is an initializer list
        auto li = {1,2,3};
        
        IntArray int_arr = {1,2,3,4,5};
        cout << "int_arr: " <<  int_arr << endl;
    }

    // prevent shallow copy;
    {
        IntArray original = {1,2,3,4,5};
        IntArray copy = original;

        cout << "original : " << original << endl;
        cout << "copy : " << copy << endl;
    }

    return 0;
}