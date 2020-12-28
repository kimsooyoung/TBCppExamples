#include <iostream>

using namespace std;

class Cents{
private:
    int m_val;
public:
    Cents(const int &val_in = 0): m_val(val_in) {}
    int getCents() const {
        return m_val;
    }
    void setCents(const int &val_in){
        m_val = val_in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Cents &c_in){
        out << c_in.m_val;
        return out;
    }

    // casting operator overloaded
    operator int(){
        cout << "cast here" << endl;
        return m_val;
    }
};

class Dollar {
private:
    int m_val;
public:
    Dollar(const int &val_in): m_val(val_in){}
    operator Cents(){
        return Cents(m_val * 100);
    }
};

int main(){

    {
        Cents c1;
        c1.setCents(112);
        
        // we implemented all these castings!!
        int a = (int)c1;
        int b = int(c1);
        int c = static_cast<int>(c1);

        cout << c1 << " " << a << " " << b << " " << c << endl;
    }

    {
        Dollar d(12);
        Cents c = d;
        
        cout << "Dollar => Cents Casting : " << c << endl;
    }
    return 0;
}