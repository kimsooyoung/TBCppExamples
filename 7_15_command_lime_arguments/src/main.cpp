#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    
    // Argc contains command line arguments
    {
        for (auto i = 0; i < argc; i++)
        {
            cout << argv[i] << endl;
        }
    }

    // Parse command line arguments to sting
    {
        cout << "===== string parse =====" << endl;
        for (auto i = 0; i < argc; i++)
        {
            std::string argv_str = argv[i];

            if (i == 1){
                int input_number = std::stoi(argv_str) + 1;
                cout << input_number << endl;
            }
            else
                cout << argv_str << endl;
        }
    }

    return 0;
}