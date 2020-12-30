#pragma once

#include "Position2D.h"
#include <string>

class Monster{
private:
    std::string m_name;
    // Monster Contains Position2D object => composition relationship
    Position2D pos_2D;

public:
    Monster():m_name(""), pos_2D() {}
    Monster(const std::string &name_in, const int &x_in = 0, const int &y_in = 0): m_name(name_in), pos_2D(x_in, y_in) {}

    void moveTo(const int &x_in, const int &y_in){
        pos_2D.moveTo(x_in, y_in);
    }

    friend std::ostream& operator<< (std::ostream& out, const Monster &mon_in){
        out << mon_in.m_name << " " << mon_in.pos_2D;
        return out;
    }
};