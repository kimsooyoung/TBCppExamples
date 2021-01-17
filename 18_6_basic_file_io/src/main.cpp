#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){

    // // ascii writing
    // {
    //     ofstream ofs;
    //     ofs.open("my_file.txt");

    //     if(!ofs){
    //         cout << "File Error" << endl;
    //         exit(1);
    //     }

    //     ofs << "Hello Hello" << endl;
    //     ofs << "I am your past" << endl;;

    //     ofs.close();
    // }

    // // ascii reading
    // {
    //     ifstream ifs;
    //     ifs.open("my_file.txt");

    //     if(!ifs){
    //         cout << "File Error" << endl;
    //         exit(1);
    //     }

    //     while (ifs){
    //         string str;

    //         getline(ifs, str);
    //         cout << str << endl;
    //     }
    // }

    // binary writing
    {
        ofstream ofs("my_binary.txt");

        if (!ofs){
            cout << "File Error" << endl;
            exit(1);
        }

        string my_str = "Binary Something";
        unsigned int num_data = my_str.size();
        ofs.write((char *)&num_data, sizeof(num_data));

        for (auto &elem : my_str)
            ofs.write((char*)&elem, sizeof(elem));
        
    }

    // binary reading
    {
        ifstream ifs("my_binary.txt");

        if(!ifs){
            cout << "File Error" << endl;
            exit(1);
        }

        string my_str;
        unsigned int num_data = 0;

        ifs.read((char*)&num_data, sizeof(num_data));

        my_str.resize(num_data);
        ifs.read(&my_str[0], num_data);

        cout << my_str << endl;
    }
    
    return 0;
}