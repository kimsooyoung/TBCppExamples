#include <iostream>
#include <vector>
#include <cstdint>

int main()
{

    {
        typedef double distance_t;
        
        double      my_distance;
        distance_t  home2work;
        distance_t  home2school;

        std::int8_t i(97);
    }

    {
        // change types at once
        typedef float distance_t;
        
        double      my_distance;
        distance_t  home2work;
        distance_t  home2school;
    }

    {
        using namespace std;
        // typedef vector<pair<string, int> > pairlist_t;
        using pairlist_t = vector<pair<string, int> >;

        pairlist_t pairlist1;
        pairlist_t pairlist2;
    }

    return 0;
}
