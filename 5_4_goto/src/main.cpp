#include <iostream>
#include <cmath>

int main(){

    {
        using namespace std;

        double x;

    Again:
        cout << "type any number : ";
        cin >> x;

        if (x < 0.0)
            goto Again;

        cout << "Sqrt : " << sqrt(x) << endl;
    }

    {
        // Error example
        goto skip; // skip must located before goto expression
        int x;

    skip:
        x += 3;
        return 0;
    }

    return 0;
}