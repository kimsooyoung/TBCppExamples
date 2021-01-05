#include <iostream>
#include <exception>
#include <string>

class CustomException : public std::exception {
public:
    // noexcept Guarantees that there won't any exception in this function
    const char * what() const noexcept override {
        return "Custom Exception";
    }
};

int main(){

    // exception handling with std::exception
    {
        try{
            std::string s;
            // resize to negative number throws length error
            s.resize(-1);
        }
        catch(const std::length_error& l_e){
            std::cerr << "Length Error" << '\n';
            std::cerr << l_e.what() << '\n';
        }
        catch(const std::exception& e){
            std::cout << typeid(e).name() << std::endl;
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << "=============================" << std::endl;
    
    // Pre-declared Exception Usage
    {
        try
        {
            throw std::runtime_error("Runtime Err");
        }
        catch(const std::exception& e)
        {
            std::cerr << typeid(e).name() << '\n';
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << "=============================" << std::endl;

    // throw with CustomException
    {
        try
        {
            throw CustomException();
        }
        catch(const CustomException& e)
        {
            std::cerr << typeid(e).name() << std::endl;
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}