#include <iostream>
#include <fstream>
#include <tuple>

using namespace std;

class Point {
private:
    double m_x, m_y, m_z;
public:
    Point(const double& x_in= 0.0, const double& y_in= 0.0, const double& z_in= 0.0) : 
        m_x(x_in), m_y(y_in), m_z(z_in) { }
    void setPoint(const double& x_in, const double& y_in, const double& z_in){
        m_x = x_in;
        m_y = y_in;
        m_z = z_in;
    }
    std::tuple<double, double, double> getPoint() const {
        return std::make_tuple(m_x, m_y, m_z);
    }
    // opeartor << overloading requires specific format
    friend std::ostream& operator<<(std::ostream& out, const Point &p_in){
        out << "(" << p_in.m_x << "," << p_in.m_y << "," << p_in.m_z << ")";
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Point &p_in){
        in >> p_in.m_x >> p_in.m_y >> p_in.m_z;
        return in;
    }
};

int main(){

    // Basic Usage
    {
        Point p_1 ( 1.1, 2.2, 3.3 );
        Point p_2;

        cout << p_1 << endl;
        cout << "type three number for p_2 : ";
        cin >> p_2;
        cout << p_2 << endl;
    }

    // file system ofstream
    {
        ofstream of("output.txt");

        Point p_1 ( 1.1, 2.2, 3.3 );
        Point p_2 ( 4.4, 5.5, 6.6 );

        cout << p_1 << p_2 << endl;
        of   << p_1 << p_2 << endl;

        of.close();

        // output.txt
        // (1.1,2.2,3.3)(4.4,5.5,6.6)
    }

    // TODO: complete ifstream example
    {
        // ifstream if
    }

    return 0;
}