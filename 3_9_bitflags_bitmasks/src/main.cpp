#include <iostream>
#include <bitset>

int main()
{
    {
        bool item1_flag = false;
        bool item2_flag = false;
        bool item3_flag = false;
        bool item4_flag = false;

        // event
        item1_flag = true;

        // die! item2 loss
        item2_flag = false;
    }

    {
        const unsigned char opt0 = 1 << 0;
        const unsigned char opt1 = 1 << 1;
        const unsigned char opt2 = 1 << 2;
        const unsigned char opt3 = 1 << 3;
        // opt 4, 5, 6, 7

        std::cout << "(opt0) : " << std::bitset<8>(opt0) << std::endl;
        std::cout << "(opt1) : " << std::bitset<8>(opt1) << std::endl;
        std::cout << "(opt2) : " << std::bitset<8>(opt2) << std::endl;
        std::cout << "(opt3) : " << std::bitset<8>(opt3) << std::endl;

        unsigned char item_flag = 0;
        std::cout << "No itme" << std::bitset<8>(item_flag) << std::endl;

        // item0 on
        item_flag |= opt0;
        std::cout << "Item0 obtained " << std::bitset<8>(item_flag) << std::endl;

        // item3 on
        item_flag |= opt3;
        std::cout << "Item3 obtained " << std::bitset<8>(item_flag) << std::endl;

        // item3 lost
        item_flag &= ~opt3;    
        std::cout << "Item3 lost " << std::bitset<8>(item_flag) << std::endl;

        // has item1?
        if (item_flag & opt1) { std::cout << "Has itme1" << std::endl; }


        // obtain item 2 and 3
        item_flag |= (opt2 | opt3);

        std::cout << "(opt2 | opt3) : " << (opt2 | opt3) << std::endl;
        std::cout << "~(opt2 & opt3) : " << ~(opt2 & opt3) << std::endl;

        std::cout << "item2, item3 obtained : " << std::bitset<8>(item_flag) << std::endl;
    
        if( ( item_flag & opt2 ) && !(item_flag & opt1) ){
            item_flag ^= opt2;
            item_flag ^= opt1;
        }

        // one line expression
        // item_flag ^= (opt1 | opt2);

        std::cout << "item_flag : " << std::bitset<8>(item_flag) << std::endl;
    }

    { 
        const unsigned int red_mask = 0xFF0000;
        const unsigned int green_mask = 0x00FF00;
        const unsigned int blue_mask = 0x0000FF;

        std::cout << "red_mask : " << std::bitset<32>(red_mask) << std::endl;
        std::cout << "green_mask : " << std::bitset<32>(green_mask) << std::endl;
        std::cout << "blue_mask : " << std::bitset<32>(blue_mask) << std::endl;

        unsigned int pixel_color = 0xDAA520;
        std::cout << "pixel_color : " << std::bitset<32>(pixel_color) << std::endl;
        
        unsigned char blue = pixel_color & blue_mask;
        unsigned int green = pixel_color & green_mask;
        unsigned int red = pixel_color & red_mask;
        
        std::cout << "blue : " << std::bitset<8>(blue) << std::endl;
        std::cout << "green : " << std::bitset<8>(green >> 8) << std::endl; 
        std::cout << "red : " << std::bitset<8>(red >> 16) << std::endl; 
    }

    {
        // Quiz
        unsigned char option_viewed    = 0x01;
        unsigned char option_editted   = 0x02;
        unsigned char option_liked     = 0x04;
        unsigned char option_shared    = 0x08;
        unsigned char option_deleted   = 0x80;

        unsigned char my_article_flags = 0;

        my_article_flags |= option_viewed;

        my_article_flags |= option_liked;
        my_article_flags |= option_liked;

        my_article_flags &= ~option_deleted;
    }

    {
        // Quiz2
        unsigned char myflags = 0b01010101;

        unsigned char option1 = 0x01;
        unsigned char option2 = 0x02;
        unsigned char option3 = 0x04;
        unsigned char option4 = 0x08;
        unsigned char option5 = 0x80;

        myflags &= ~(option4 | option5);
        myflags &= ~option4  & ~option5;
    }


    return 0;
}