#pragma once

#include <iostream>

class Calc;
class Date
{
private:
    int m_year;
    int m_month;
    int m_day;
 
public:
    Date(int year, int month, int day);
 
    void SetDate(int year, int month, int day);
 
    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay()  { return m_day; }
};

void sum(Calc& calc, const int &val);