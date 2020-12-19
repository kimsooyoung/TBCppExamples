#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>

unsigned int PRNG() { // Pseudo Random Number Generator
    // seed number
    // try again with "static" keyword deletion
    static unsigned int seed = 5523; 
    
    seed = 825329 * seed + 2396403;
    
    return seed % 32768;
}

int getRandomNumber(int min, int max){
    static const double fraction = 1.0 / (RAND_MAX + 1.0);

    return min + static_cast<int>(rand() * fraction * (max - min + 1) );
}

int main() {

    using namespace std;

    {
        for (int count = 0; count < 100; count++)
        {
            cout << PRNG() << "\t";

            if (count % 5 == 0) cout << endl;
        }
    }

    {
        // seed
        // same seed number will make same result
        srand(5323); 

        for (int count = 0; count < 100; count++)
        {
            cout << rand() << "\t";

            if(count % 5 == 0) cout << endl;
        }
    }

    {
        srand(static_cast<unsigned int>(time(0)));

        for (int count = 0; count < 100; count++)
        {
            cout << rand() << "\t";

            if(count % 5 == 0 ) cout << endl;
        }
    }

    {
        srand(5232);

        for (int count = 0; count < 100; count++)
        {
            cout << getRandomNumber(5, 8) << "\t";

            if (count % 5 == 0 ) cout << endl;
        }
    }

    {
        srand(5232);

        // popular method
        for (int count = 0; count < 100; count++)
        {
            cout << rand() % 5 + 3 << "\t";
            
            if (count % 5 == 0) cout << endl;
        }
    }

    {
        random_device rd; 
        mt19937 mersenne(rd());
        uniform_int_distribution<> dice(1, 6);

        cout << endl << endl;
        for (int count = 0; count < 20; count++)
        {
            cout << dice(mersenne) << "\t";
        }
    }

    return 0;
}