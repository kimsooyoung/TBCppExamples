#include <iostream>
#include <fstream>
#include <cstring>

// return -1 if it fails
int findFirstChar (const char *string, char ch){
    for (auto i = 0; i < std::strlen(string); i++)
        if (string[i] == ch)
            return i;
        
    return -1; // no match
}

// Check Division by Zero
double devide(const int &x_in, const int &y_in, bool &success){
    if ( y_in == 0 ){
        success = false;
        return 0.0;
    }

    success = true;
    return static_cast<double>(x_in) / y_in;
}



int main() {

    // check by function output
    {
        int result = findFirstChar("Abracatabra",'c');

        if(result)
            std::cout << "Location of c : " << result << std::endl;
        else
            std::cout << "No c " << std::endl;   
    }

    std::cout << "==============================" << std::endl;

    // check by bool flag 
    {
        bool success;
        int div_result = devide(3, 0, success);

        if(success)
            std::cout << div_result << std::endl;
        else
            std::cout << "Division by Zero" << std::endl;
    }

    std::cout << "==============================" << std::endl;

    // nullptr check 
    // ifstream returns nullptr if it fails
    {
        std::ifstream input_file("temp.txt");
        if(!input_file)
            std::cerr << "Cannot open file" << std::endl;
    }

    std::cout << "==============================" << std::endl;

    {
        double x;
        std::cout << "Type any double number : ";
        std::cin >> x;

        try{
            if (x < 0.0) throw std::string("Negative input");
            
            std::cout << "You Entered " << x << std::endl;
        }
        // catch param type must match throw type
        // catch(const char * err_str) {
        //     std::cerr << err_str << '\n';
        //     // Aborted (core dumped)
        // }
        catch(const std::string err_msg){
            std::cerr << err_msg << '\n';
        }
        // There can be many different forms of catch.
        // But Again, catch param type must match throw type
        catch(const int err_num){
            std::cerr << err_num << '\n';
        }
    }

    return 0;
}