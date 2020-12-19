#include <iostream>

using namespace std;

int main(){
    int scores[] = {11,2,2,33,34,77,64,34,33,80};
    const int score_size = sizeof(scores)/sizeof(int);
    
    float mean = 0;
    for (auto i = 0; i < score_size; i++){
        mean += scores[i];
    }
    mean /= score_size;

    int max = 0;
    int min = 100;
    for (auto i = 0; i < score_size; i++){
        max = (max > scores[i]) ? max:scores[i];
        min = (min < scores[i]) ? min:scores[i];
    }
    
    cout << "mean : " << mean << endl;
    cout << "max : " << max << endl;
    cout << "min : " << min << endl;

    return 0;
}