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

    // example1) Data: 7F 00 00 00 5B 6E 7F 00  
    {
        unsigned char motor_encoder_byte[8];

        motor_encoder_byte[0] = 0x7F; 
        motor_encoder_byte[1] = 0x00;
        motor_encoder_byte[2] = 0x00; 
        motor_encoder_byte[3] = 0x00;

        motor_encoder_byte[4] = 0x5B;
        motor_encoder_byte[5] = 0x6E;
        motor_encoder_byte[6] = 0x7F;
        motor_encoder_byte[7] = 0x00;

        // 실제로는 겹치는 부분이 있으므로 유의미한 6바이트만 사용
        unsigned char encoder_data[6];

        encoder_data[0] = motor_encoder_byte[4];
        encoder_data[1] = motor_encoder_byte[5];
        encoder_data[2] = motor_encoder_byte[6];
        encoder_data[3] = motor_encoder_byte[7];

        encoder_data[4] = motor_encoder_byte[2];
        encoder_data[5] = motor_encoder_byte[3];

        // decimal value
        unsigned int encoder_val_dec;
        
        std::memcpy(&encoder_val_dec, encoder_data, sizeof(int));

        std::cout << std::endl;
        std::cout << "[hex] encoder_val_dec " << std::hex << encoder_val_dec << '\n';
        std::cout << "[dec] encoder_val_dec " << std::dec << encoder_val_dec << '\n';
    }

    // example1) Data: C3 FF FF FF 7C 42 C3 FF 
    {
        unsigned char motor_encoder_byte[8];

        motor_encoder_byte[0] = 0xC3; 
        motor_encoder_byte[1] = 0xFF;
        motor_encoder_byte[2] = 0xFF;
        motor_encoder_byte[3] = 0xFF;

        motor_encoder_byte[4] = 0x7C;
        motor_encoder_byte[5] = 0x42;
        motor_encoder_byte[6] = 0xC3;
        motor_encoder_byte[7] = 0xFF;

        // 실제로는 겹치는 부분이 있으므로 유의미한 6바이트만 사용
        unsigned char encoder_data[6];

        encoder_data[0] = motor_encoder_byte[4];
        encoder_data[1] = motor_encoder_byte[5];
        encoder_data[2] = motor_encoder_byte[6];
        encoder_data[3] = motor_encoder_byte[7];

        encoder_data[4] = motor_encoder_byte[2];
        encoder_data[5] = motor_encoder_byte[3];

        // decimal value
        unsigned int encoder_val_dec;
        
        std::memcpy(&encoder_val_dec, encoder_data, sizeof(int));

        std::cout << std::endl;
        std::cout << "[hex] encoder_val_dec " << std::hex << encoder_val_dec << '\n';
        std::cout << "[dec] encoder_val_dec " << std::dec << encoder_val_dec << '\n';
    }

    // 0x9b 0xff 0xff 0xff 0x05 0x16 0x9b 0xff => 4288353797
    // 0x97 0xff 0xff 0xff 0xe4 0xa6 0x97 0xff => 4288128740
    // 0x92 0xff 0xff 0xff 0x3a 0x85 0x92 0xff => 4287792442
    // 0x8b 0xff 0xff 0xff 0xe6 0x80 0x8b 0xff => 4287332582
    // 1 cycle => 1,300,000
    {
        unsigned char motor_encoder_byte[8];

        motor_encoder_byte[0] = 0x8B;
        motor_encoder_byte[1] = 0xFF;
        motor_encoder_byte[2] = 0xFF;
        motor_encoder_byte[3] = 0xFF;

        motor_encoder_byte[4] = 0xE6;
        motor_encoder_byte[5] = 0x80;
        motor_encoder_byte[6] = 0x8B;
        motor_encoder_byte[7] = 0xFF;

        // 실제로는 겹치는 부분이 있으므로 유의미한 6바이트만 사용
        unsigned char encoder_data[6];

        encoder_data[0] = motor_encoder_byte[4];
        encoder_data[1] = motor_encoder_byte[5];
        encoder_data[2] = motor_encoder_byte[6];
        encoder_data[3] = motor_encoder_byte[7];

        encoder_data[4] = motor_encoder_byte[2];
        encoder_data[5] = motor_encoder_byte[3];

        // decimal value
        unsigned int encoder_val_dec;
        
        std::memcpy(&encoder_val_dec, encoder_data, sizeof(int));

        std::cout << std::endl;
        std::cout << "[hex] encoder_val_dec " << std::hex << encoder_val_dec << '\n';
        std::cout << "[dec] encoder_val_dec " << std::dec << encoder_val_dec << '\n';
    }


    return 0;
}