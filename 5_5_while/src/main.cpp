#include <iostream>
#include <limits>

int main(){
    
    // Basic Usage
    {
        int count = 10;
        while(count > 0){
            std::cout << "count : " << count << std::endl;
            count -= 1;
        }
    }

    // While to Goto
    {
        int count = 10;

    CountDown:
        count -= 1;

        if (count == 0)
            goto End;

        std::cout << "Count : " << count << std::endl;
        goto CountDown;
    
    End:
        std::cout << "CountDown done..." << std::endl;
    }

    // Endless while
    {
        std::string user_input;

        while(1){
            std::cout << "Type string, It'll repeated forever (or, type 'break' ) : ";
            std::cin >> user_input;
            
            if(user_input == "break")
                break;
            else
                std::cout << "Your input : " << user_input << std::endl;
        }
    }

    // DO NOT use UNSIGNED INT to while
    {
        unsigned int count = 10;
        
        while (count >= 0){
            // unsigned int will overflow and will make this endless loop
            std::cout << "Count : " << count << std::endl;
            
            count -= 1;

            if (count == std::numeric_limits<unsigned int>::max() - 10)
                break;
        }
    }

    // Nested Loop
    {
        int i = 9, j = 9;
        while( i > 0 ){
            while ( j > 0 ){
                std::cout << "( " << i << " , " << j << " )" << std::endl;
                j -= 1;
            }
            j = 9;
            i -= 1;
        }
    }

    {
        int count = 100;

        while(count > 0){

            if (count % 5 == 3)
                std::cout << count << " Mod : 3" << std::endl;
            
            --count;
        }
    }

    return 0;
}