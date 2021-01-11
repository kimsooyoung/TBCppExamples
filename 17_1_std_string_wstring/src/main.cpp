#include <string.h>
#include <cstddef>
#include <iostream>
#include <locale>

using namespace std;

char* texts[] = {
    u8"Ñá", //Spanish
    u8"forêt intérêt", //French
    u8"Gesäß", //German
    u8"取消波蘇日奇諾", //Chinese
    u8"日本人のビット", //Japanese
    u8"немного русский", //Russian
    u8"ένα κομμάτι της ελληνικής", // Greek
    u8"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ", // Punjabi (wtf?). xD
    u8"کمی از ایران ", // Persian (I know it, from 300 movie)
    u8"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu (telu-what?)
    u8"Но какво, по дяволите, е това?", //Bulgarian
    u8"안녕하세요?" //Korean
};

constexpr size_t ntexts = sizeof(texts) / sizeof(texts[0]);


int main(){

    // c-style string example
    {
        char *strHello = new char [7];
        strcpy(strHello, "hello");
        cout << strHello << endl;
    }

    {
        std::string string;
        std::wstring wstring;

        wchar_t wc;
        // typedef unsigned long wchar_t;
    }

    // c++ localization example
    {
        std::locale::global(std::locale(""));
        cout.imbue(std::locale());

        for ( size_t i = 0; i < ntexts; ++i )
            cout << texts[i] << endl;
    }

    return 0;
}