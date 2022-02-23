#include <iostream> 

using namespace std;

class Fraction{
    int m_numerator;
    int m_denumerator;
public:
    // Constructor
    Fraction(){
        m_numerator     = 1;
        m_denumerator   = 0;
    }
    Fraction(const int &num_in, const int &denum_in = 1){
        m_numerator     = num_in;
        m_denumerator   = denum_in;

        cout << "Fraction () Consructor " << endl;
    }
    void print(){
        cout << m_numerator << " / " << m_denumerator << endl;
    }
};

class errExmple{
    int x,y;
public:
    // Construtor Error case
    errExmple(){
        x = 1;
        y = 2;
    };
    errExmple(const int &x_in = 10, const int &y_in = 12){
        x = x_in;
        y = y_in;
    };
    void print(){
        cout << x << " " << y << endl;
    }
};

// Class in Class
class Second{
public:
    Second(){
        cout << "Class Second Constructor! " << endl;
    }
};

class First{
    Second sec;
public:
    First(){
        cout << "Class First Constructor! " << endl;
    }
};

int main(){

    {
        // Uniform initialiazatio is invalid because of 
        // m_ instances are private
        // Fraction frac{2,3};

        // Then, use Constructor
        // Caution DO NOT USE () after default Constructor
        Fraction frac;
        frac.print();

        Fraction frac_2(1,2);
        frac_2.print();

        Fraction frac_3{10, 20};
        frac_3.print();

        // 이렇게도 할 수 있지만 권장하지는 않음. 쓸데없는 생성 후 연산이기에
        Fraction frac_4 = Fraction{10, 20};
        frac_4.print();

        // Uniform initialization doesn't allows type inversion
        // Fraction invalid_frac_2 { 1.2, 2 };
        // frac_2.print();
    }

    // Error Case
    {
        // has more than one default constrctor Error
        // errExmple my_class;
        // my_class.print();
    }

    {
        First first;

        // output
        // Class Second Constructor! 
        // Class First Constructor!
    }

    return 0;
}