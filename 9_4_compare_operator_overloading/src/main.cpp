#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cents{
private:
    int m_val;
public:
    Cents(const int &val_in = 0): m_val(val_in){};
    void setCents(const int &val_in) { m_val = val_in; }
    int getCents() const { return m_val; }
    int& getCents() { return m_val; }
    
    friend bool operator== (const Cents &c1, const Cents &c2){
        return c1.m_val == c2.m_val;
    }

    friend bool operator!= (const Cents &c1, const Cents &c2){
        return c1.m_val != c2.m_val;
    }

    friend bool operator< (const Cents &c1, const Cents &c2){
        return c1.m_val < c2.m_val;
    }

    friend bool operator> (const Cents &c1, const Cents &c2){
        return c1.m_val > c2.m_val;
    }

    friend std::ostream& operator<< (std::ostream& out, const Cents &c_in){
        out << c_in.m_val;
        return out;
    }
};

int main(){

    // ==, != overloading Example
    {
        Cents c1(10);
        Cents c2(10);
        
        if(c1 == c2)
            cout << "c1 and c2 same" << endl;

        c1.setCents(12);

        if(c1 != c2)
            cout << "c1 and c2 differ" << endl;
    }

    // <, > overloading for vector sort
    {
        const int vec_size = 20;
        std::vector<Cents> vec(20);

        for (unsigned i = 0; i < vec_size; i++)
            vec[i].getCents() = i;
        
        std::random_shuffle(begin(vec), end(vec));

        for (auto &i : vec)
            cout << i << " ";
        cout << endl;

        std::sort(begin(vec), end(vec));

        for (auto &&i : vec)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

