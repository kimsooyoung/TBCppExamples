#pragma once

#include <iostream>

class Position2D{
private:
    int m_x;
    int m_y;

public:
    Position2D(const int &x_in = 0, const int &y_in = 0): m_x(x_in), m_y(y_in){}
    void moveTo(const int &x_in, const int &y_in){
        m_x = x_in;
        m_y = y_in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Position2D &pos_in){
        out << "( " << pos_in.m_x << " , " << pos_in.m_y << " )";
        return out;
    }
};