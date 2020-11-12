#include <iostream>
#include <bitset>

int main()
{
    {
        // <<, >> left/right shift
        // ~, &, |, ^
        unsigned int a = 2;
        unsigned int b = a << 1;
        
        std::cout << std::bitset<4>(a) << std::endl;
        std::cout << std::bitset<4>(b) << std::endl;

        // left shift means multiply by 2
        std::cout << "(a << 2) : " << std::bitset<8>(a << 2) << std::endl;
        std::cout << "(a << 3) : " << std::bitset<8>(a << 3) << std::endl;
        std::cout << "(a << 4) : " << std::bitset<8>(a << 4) << std::endl;
        std::cout << "(a << 5) : " << std::bitset<8>(a << 5) << std::endl;

    }

    {
        unsigned int a = 1024;

        std::cout << "(a >> 0): " << std::bitset<16>(a >> 0) << std::endl;
        std::cout << "(a >> 1): " << std::bitset<16>(a >> 1) << std::endl;
        std::cout << "(a >> 2): " << std::bitset<16>(a >> 2) << std::endl;
        std::cout << "(a >> 3): " << std::bitset<16>(a >> 3) << std::endl;
        std::cout << "(a >> 4): " << std::bitset<16>(a >> 4) << std::endl;

        std::cout <<" (~a) : " << std::bitset<16>(~a) << std::endl;

    }

    {
        unsigned int a = 0b1100;
        unsigned int b = 0b0110;

        std::cout << "(a) : " << std::bitset<16>(a) << std::endl;
        std::cout << "(~a) : " << std::bitset<16>(~a) << " " << (~a) << std::endl;
    }

    { 
        unsigned int a = 0b1100;
        unsigned int b = 0b0110;

        std::cout << "(a & b) : " << std::bitset<4>(a & b) << std::endl;
        std::cout << "(a | b) : " << std::bitset<4>(a | b) << std::endl;
        std::cout << "(a ^ b) : " << std::bitset<4>(a ^ b) << std::endl;
    }   

    {
        // Quiz
        unsigned char c = 0b0110;

        std::cout << "(c >> 2) : " << (c >> 2) << std::endl;


        std::cout << "(5 | 12) : " << (5 | 12) << std::endl;
        std::cout << "(5 & 12) : " << (5 & 12) << std::endl;
        std::cout << "(5 ^ 12) : " << (5 ^ 12) << std::endl;
    }

    return 0;
}