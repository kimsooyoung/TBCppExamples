#include <iostream>
#include <sstream>
#include <cstring>
#include <string>


int main(int argc, char** argv){

    std::string hello("123"); 
    std::stringstream str(hello); 
    
    int x;
    
    str >> x;  
    if (!str) 
       std::cout << "The conversion failed." << std::endl;
    
    std::cout << x << std::endl;


    // https://stackoverflow.com/questions/1070497/c-convert-hex-string-to-signed-integer
    {
        std::string s = "0xfffefffe";
        int x_int = std::stoul(s, nullptr, 16);
    
        std::cout << x_int << std::endl;
    }

    {
        unsigned char data_char[4];
        data_char[0] = 0xFF; data_char[1] = 0xFC;
        data_char[2] = 0xFF; data_char[3] = 0xFE;
        
        unsigned char data_char2[2];
        data_char2[0] = 0x33; data_char2[1] = 0xA5;

        int x_int;
        int16_t x_int16;
        
        std::memcpy(&x_int, data_char, sizeof(int));
        std::memcpy(&x_int16, data_char2, sizeof(int16_t));
        
        // fefffcff
        std::cout << std::hex << x_int << '\n';
        std::cout << std::dec << x_int << '\n';

        std::cout << std::hex << x_int16 << '\n';
        std::cout << std::dec << x_int16 << '\n';

        // Fail log
        // auto hexstring = static_cast<std::string>(reinterpret_cast<const char *>(data_char));
        // std::cout << hexstring << std::endl;
        // int number = std::stoul(hexstring, nullptr, 0);
        // int number = (int)strtol(hexstring, NULL, 16);
        // const char *hexstring = "abcdef0";
        // int number = (int)strtol(hexstring, NULL, 16);
        // std::cout << number << std::endl;

    }

    {
        // Data: C3 FF FF FF 7C 42 C3 FF 
        // Data: 7F 00 00 00 5B 6E 7F 00 

        unsigned char motor_cycle_byte[4];
        unsigned char motor_encoder_byte[2];

        motor_cycle_byte[0] = 0x7F; motor_cycle_byte[1] = 0x00;
        motor_cycle_byte[2] = 0x00; motor_cycle_byte[3] = 0x00;

        motor_encoder_byte[0] = 0x5B; motor_encoder_byte[1] = 0x6E;

        unsigned char motor_cycle_byte2[4];
        unsigned char motor_encoder_byte2[2];

        motor_cycle_byte2[0] = 0xC3; motor_cycle_byte2[1] = 0xFF;
        motor_cycle_byte2[2] = 0xFF; motor_cycle_byte2[3] = 0xFF;

        motor_encoder_byte2[0] = 0x7C; motor_encoder_byte2[1] = 0x42;

        int motor_cycle, motor_cycle2;
        int16_t motor1_encoder, motor2_encoder;
        
        std::memcpy(&motor_cycle, motor_cycle_byte, sizeof(int));
        std::memcpy(&motor_cycle2, motor_cycle_byte2, sizeof(int));

        std::memcpy(&motor1_encoder, motor_encoder_byte, sizeof(int16_t));
        std::memcpy(&motor2_encoder, motor_encoder_byte2, sizeof(int16_t));

        std::cout << std::endl;
        std::cout << "motor_cycle " << std::hex << motor_cycle << '\n';
        std::cout << "motor_cycle " << std::dec << motor_cycle << '\n';
        std::cout << "motor1_encoder " << std::hex << motor1_encoder << '\n';
        std::cout << "motor1_encoder " << std::dec << motor1_encoder << '\n';
    
        std::cout << "motor_cycle2 " << std::hex << motor_cycle2 << '\n';
        std::cout << "motor_cycle2 " << std::dec << motor_cycle2 << '\n';
        std::cout << "motor2_encoder " << std::hex << motor2_encoder << '\n';
        std::cout << "motor2_encoder " << std::dec << motor2_encoder << '\n';
    }



    return 0;
}