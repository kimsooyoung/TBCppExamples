#include <iostream>

using namespace std;

class Date{
    int m_month;
    int m_day;
    int m_year;
public:
    // setter
    void setDate(const int &month_input, const int &day_input, const int &year_input){
        m_month = month_input;
        m_day = day_input;
        m_year = year_input;
    }
    void setMonth(const int &month_input){
        m_month = month_input;
    }
    // getter
    // Prevent Unnecessary copy
    const int& getDay(){
        return m_day;
    }

    // copy
    void copyFrom(const Date &original){
        m_month = original.m_month;
        m_day   = original.m_day;
        m_year  = original.m_year;
    }
};

int main(){

    // getter, setter usage
    {
        Date today;
        today.setDate(12,25,2020);
        today.setMonth(10);

        cout << "today.getDay : " << today.getDay() << endl;
    }

    // copyFrom usage
    {
        Date today;
        today.setDate(1,1,2021);
        Date new_day;
        new_day.copyFrom(today);
    }
    
    return 0;
}